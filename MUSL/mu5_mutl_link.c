#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mu5_mutl_link.h"
#include "elf.h"

#define MAX_IMPORT_MODULES 64

typedef struct
{
    void *elf_module_context;
    char module_name[80];
} LINKER_MODULE;

typedef struct
{
    LINKER_MODULE *module;
    Elf32_Shdr section_header;
    int elf_input_section_index;
    int elf_output_section_index;
    Elf32_Shdr relocation_section_header;
    char *data;
    char *rela_data;
    Elf32_Addr segment_relocated_start_address;
} LINKER_SEGMENT;

typedef struct
{
    char *name;
    int type;
    Elf32_Addr value;
    LINKER_SEGMENT *segment;
} LINKER_SYMBOL;

typedef struct
{
    int num_symbols;
    int binding_filter;
    LINKER_SYMBOL *symbols;
} LINKER_SYMBOL_TABLE;

static Elf32_Addr entry_point;
static int num_modules;
static LINKER_MODULE elf_modules[MAX_IMPORT_MODULES];
static int num_segments;
static LINKER_SEGMENT *segment_table;
static LINKER_SYMBOL_TABLE global_symbol_table = { 0, STB_GLOBAL, NULL };
static LINKER_SYMBOL_TABLE local_symbol_table = { 0, STB_LOCAL, NULL };

static LINKER_SEGMENT *get_linker_segment_for_section(void *context, int section_index);
static void check_module_for_start_address(void *elf_module);
static void count_symbol(void *elf_context, void *context, char *name, Elf32_Addr value, Elf32_Word size, int binding, int type, unsigned char st_other, Elf32_Half section_index);
static void add_symbol(void *elf_context, void *context, char *name, Elf32_Addr value, Elf32_Word size, int binding, int type, unsigned char st_other, Elf32_Half section_index);
static void compute_total_symbols(LINKER_SYMBOL_TABLE *symbol_table);
static int compare_symbol_name(const void *sym1, const void *sym2);
static int compare_segment_by_section_address(const void *seg1, const void *seg2);
static void build_global_symbol_table(void);
static void build_local_symbol_table(void *elf_context);
static LINKER_SYMBOL *get_linker_symbol(void *elf_module_context, int symbol_index, LINKER_SYMBOL_TABLE *symbol_table);
static void check_for_symbols_with_multiple_definitions(LINKER_SYMBOL_TABLE *symbol_table);
static void process_segments(Elf32_Word flag, void *callback_context, void(*process_segment)(LINKER_MODULE *module, int section_index, void *callback_context));
static void count_segments(void);
static void count_segment(LINKER_MODULE *module, int section_index, void *callback_context);
static void define_segments(void);
static void define_segment(LINKER_MODULE *module, int section_index, void *callback_context);
static void resolve_symbols(void);
static void resolve_symbol_in_segment(LINKER_SEGMENT *linker_segment);
static void compute_segment_start_addresses(void);
static void add_segments_to_output(void *out_elf_context);

void import_module(char * filename)
{
    FILE * f;

    if (num_modules >= MAX_IMPORT_MODULES)
    {
        fatal("Too many import modules\n");
    }

    f = fopen(filename, "rb");
    if (f == NULL)
    {
        perror("Could not open import file");
        exit(0);
    }

    LINKER_MODULE *module = &elf_modules[num_modules++];
    strncpy(module->module_name, filename, sizeof(module->module_name));
    module->elf_module_context = elf_read_file(f, 0);
    check_module_for_start_address(elf_modules[num_modules - 1].elf_module_context);
    fclose(f);
}

void link_modules(char *filename)
{
    void *out_elf_context = elf_new_file(ET_EXEC, 0, 0);
    elf_set_entry(out_elf_context, entry_point);
    define_segments();
    build_global_symbol_table();
    resolve_symbols();
    add_segments_to_output(out_elf_context);
    elf_write_file(out_elf_context, filename);
}

static LINKER_SEGMENT *get_linker_segment_for_section(void *context, int section_index)
{
    int i;
    LINKER_SEGMENT *result = NULL;
    LINKER_SEGMENT *current_seg;
    for (i = 0; i < num_segments; i++)
    {
        current_seg = &segment_table[i];
        if (current_seg->module->elf_module_context == context && current_seg->elf_input_section_index == section_index)
        {
            result = current_seg;
            break;
        }
    }

    return result;
}

static void check_module_for_start_address(void *elf_module)
{
    Elf32_Ehdr elf_header;
    elf_get_elf_header(elf_module, &elf_header);
    if (elf_header.e_type == ET_EXEC)
    {
        entry_point = elf_header.e_entry;
    }
}

static void count_symbol(void *elf_context, void *context, char *name, Elf32_Addr value, Elf32_Word size, int binding, int type, unsigned char st_other, Elf32_Half section_index)
{
    LINKER_SYMBOL_TABLE *symbol_table = context;
    if (binding == symbol_table->binding_filter)
    {
        symbol_table->num_symbols++;
    }
}

static void add_symbol(void *elf_context, void *context, char *name, Elf32_Addr value, Elf32_Word size, int binding, int type, unsigned char st_other, Elf32_Half section_index)
{
    LINKER_SYMBOL_TABLE *symbol_table = context;
    LINKER_SYMBOL *link_sym;
    LINKER_SEGMENT *link_seg;
    if (binding == symbol_table->binding_filter)
    {
        link_sym = &symbol_table->symbols[symbol_table->num_symbols++];
        link_seg = get_linker_segment_for_section(elf_context, section_index);
        link_sym->name = name;
        link_sym->type = type;
        if (type == STT_FUNC)
        {
            link_sym->value = link_seg->segment_relocated_start_address + value;
        }
        else
        {
            link_sym->value = value;
        }
        link_sym->segment = link_seg;
    }
}

static void  compute_total_symbols(LINKER_SYMBOL_TABLE *symbol_table)
{
    int i;
    for (i = 0; i < num_modules; i++)
    {
        elf_process_defined_symbols(elf_modules[i].elf_module_context, symbol_table, count_symbol);
    }
}

static int compare_symbol_name(const void *sym1, const void *sym2)
{
    LINKER_SYMBOL *ls1 = sym1;
    LINKER_SYMBOL *ls2 = sym2;

    return strcmp(ls1->name, ls2->name);
}

static int compare_segment_by_section_address(const void *seg1, const void *seg2)
{
    LINKER_SEGMENT *ls1 = seg1;
    LINKER_SEGMENT *ls2 = seg2;

    return ls1->section_header.sh_addr - ls2->section_header.sh_addr;
}

static void build_global_symbol_table(void)
{
    int i;
    
    compute_total_symbols(&global_symbol_table);

    global_symbol_table.symbols = (LINKER_SYMBOL *)(malloc(global_symbol_table.num_symbols * sizeof(LINKER_SYMBOL)));
    global_symbol_table.num_symbols = 0; /* reset count because add_symbol uses it to index into the table while adding the symbols */
    for (i = 0; i < num_modules; i++)
    {
        elf_process_defined_symbols(elf_modules[i].elf_module_context, &global_symbol_table, add_symbol);
    }

    qsort(global_symbol_table.symbols, global_symbol_table.num_symbols, sizeof(LINKER_SYMBOL), compare_symbol_name);

    check_for_symbols_with_multiple_definitions(&global_symbol_table);
}

static void build_local_symbol_table(void *elf_context)
{
    int i;

    if (local_symbol_table.symbols != NULL)
    {
        free(local_symbol_table.symbols);
    }

    local_symbol_table.num_symbols = 0;
    compute_total_symbols(&local_symbol_table);

    local_symbol_table.symbols = (LINKER_SYMBOL *)(malloc(local_symbol_table.num_symbols * sizeof(LINKER_SYMBOL)));
    local_symbol_table.num_symbols = 0; /* reset count because add_symbol uses it to index into the table while adding the symbols */
    elf_process_defined_symbols(elf_context, &local_symbol_table, add_symbol);

    qsort(local_symbol_table.symbols, local_symbol_table.num_symbols, sizeof(LINKER_SYMBOL), compare_symbol_name);
}

static LINKER_SYMBOL *get_linker_symbol(void *elf_module_context, int symbol_index, LINKER_SYMBOL_TABLE *symbol_table)
{
    Elf32_Sym symbol;
    LINKER_SYMBOL lookup;
    LINKER_SYMBOL *result;
    char *name;

    elf_get_symbol(elf_module_context, &symbol, symbol_index);
    lookup.name = elf_get_string(elf_module_context, symbol.st_name);
    result = bsearch(&lookup, symbol_table->symbols, symbol_table->num_symbols, sizeof(LINKER_SYMBOL), compare_symbol_name);
    return result;
}

static void check_for_symbols_with_multiple_definitions(LINKER_SYMBOL_TABLE *symbol_table)
{
    int i;
    char *last_name = "";
    int error = 0;
    for (i = 0; i < symbol_table->num_symbols; i++)
    {
        LINKER_SYMBOL *sym = &symbol_table->symbols[i];
        if (strcmp(last_name, sym->name) == 0)
        {
            error = 1;
            perror(last_name);
            perror(" has multiple definitions");
        }

        last_name = sym->name;
    }

    if (error)
    {
        exit(0);
    }
}

static void process_segments(Elf32_Word flag, void *callback_context, void(*process_segment)(LINKER_MODULE *module, int section_index, void *callback_context))
{
    int module_index;
    int section_index;
    for (module_index = 0; module_index < num_modules; module_index++)
    {
        Elf32_Ehdr module_elf_header;
        LINKER_MODULE *module = &elf_modules[module_index];
        elf_get_elf_header(module->elf_module_context, &module_elf_header);
        for (section_index = 0; section_index < module_elf_header.e_shnum; section_index++)
        {
            Elf32_Shdr section_header;
            elf_get_section_header(module->elf_module_context, &section_header, NULL, section_index);
            if (section_header.sh_type == flag)
            {
                process_segment(module, section_index, callback_context);
            }
        }
    }
}

static void count_segments(void)
{
    num_segments = 0;
    process_segments(SHT_PROGBITS, NULL, count_segment);
}

static void count_segment(LINKER_MODULE *module, int section_index, void *callback_context)
{
    num_segments++;
}

static void define_segments(void)
{
    int segment_index = 0;
    count_segments();
    segment_table = calloc(num_segments, sizeof(LINKER_SEGMENT));
    process_segments(SHT_PROGBITS, &segment_index, define_segment);
    qsort(segment_table, num_segments, sizeof(LINKER_SEGMENT), compare_segment_by_section_address);
    compute_segment_start_addresses();
}

static void define_segment(LINKER_MODULE *module, int section_index, void *callback_context)
{
    int *segment_index = callback_context;
    int relocation_section;
    LINKER_SEGMENT *segment = &segment_table[(*segment_index)++];
    segment->module = module;
    segment->elf_input_section_index = section_index;
    elf_get_section_header(module->elf_module_context, &segment->section_header, &segment->data, section_index);
    relocation_section = elf_get_relocation_section(module->elf_module_context, section_index);
    if (relocation_section >= 0)
    {
        elf_get_section_header(module->elf_module_context, &segment->relocation_section_header, &segment->rela_data, relocation_section);
    }
}

static void resolve_symbols(void)
{
    int i;
    LINKER_SEGMENT *current_seg;
    for (i = 0; i < num_segments; i++)
    {
        current_seg = &segment_table[i];
        resolve_symbol_in_segment(current_seg);
    }
}

static void resolve_symbol_in_segment(LINKER_SEGMENT *linker_segment)
{
    int i;
    int num_relas;
    if (linker_segment->relocation_section_header.sh_size > 0)
    {
        printf("Resolving symbols in module %s, section %s for segment at %08X\n", linker_segment->module->module_name, elf_get_section_name(linker_segment->module->elf_module_context, linker_segment->section_header.sh_name), linker_segment->segment_relocated_start_address);
        build_local_symbol_table(linker_segment->module->elf_module_context);
        num_relas = linker_segment->relocation_section_header.sh_size / linker_segment->relocation_section_header.sh_entsize;
        for (i = 0; i < num_relas; i++)
        {
            Elf32_Rela *rela_entry = &((Elf32_Rela *)linker_segment->rela_data)[i];
            LINKER_SYMBOL *linker_symbol;
            char *name;
            int symbol_index = ELF32_R_SYM(rela_entry->r_info);
            int rel_type = ELF32_R_TYPE(rela_entry->r_info);
            linker_symbol = get_linker_symbol(linker_segment->module->elf_module_context, symbol_index, &local_symbol_table);
            if (linker_symbol == NULL)
            {
                linker_symbol = get_linker_symbol(linker_segment->module->elf_module_context, symbol_index, &global_symbol_table);
            }

            if (name = linker_symbol->name == NULL)
            {
                Elf32_Sym symbol;
                elf_get_symbol(linker_segment->module->elf_module_context, &symbol, symbol_index);
                printf("Symbol %s is not defined", elf_get_string(linker_segment->module->elf_module_context, symbol.st_name));
                exit(1);
            }

            Elf32_Addr new_addr;
            name = linker_symbol->name;
            
            if (linker_symbol->type == STT_FUNC && rel_type == MU5_REL_TYPE_FUNC)
            {
                new_addr = linker_symbol->value / 2 + rela_entry->r_addend;
            }
            else if (linker_symbol->type == STT_OBJECT && rel_type == MU5_REL_TYPE_VAR)
            {
                new_addr = linker_symbol->segment->segment_relocated_start_address;
            }
            else if (rel_type == MU5_REL_TYPE_DESC_LIT)
            {
                new_addr = linker_symbol->segment->segment_relocated_start_address + rela_entry->r_addend;
            }
            else
            {
                perror("Unrecognised link type");
                exit(0);
            }

            printf("Resolved %s reference at offset %08X to %08X\n", name, rela_entry->r_offset, new_addr);
            char *ptr = &linker_segment->data[rela_entry->r_offset];
            *ptr++ = (new_addr >> 24) & 0xFF;
            *ptr++ = (new_addr >> 16) & 0xFF;
            *ptr++ = (new_addr >> 8) & 0xFF;
            *ptr++ = (new_addr & 0xFF);
        }
    }
}

static void compute_segment_start_addresses(void)
{
    int i;
    Elf32_Addr last_addr;
    LINKER_SEGMENT *current_seg;
    LINKER_SEGMENT *previous_seg;
    for (i = 0; i < num_segments; i++)
    {
        current_seg = &segment_table[i];
        if (i == 0 || last_addr != current_seg->section_header.sh_addr)
        {
            last_addr = current_seg->section_header.sh_addr;
            current_seg->segment_relocated_start_address = current_seg->section_header.sh_addr;
        }
        else
        {
            current_seg->segment_relocated_start_address = previous_seg->segment_relocated_start_address + previous_seg->section_header.sh_size;
        }

        printf("Module %s, section %s, segment start address = %08X\n", current_seg->module->module_name, elf_get_section_name(current_seg->module->elf_module_context, current_seg->section_header.sh_name), current_seg->segment_relocated_start_address);

        previous_seg = current_seg;
    }
}

static void add_segments_to_output(void *out_elf_context)
{
    int i;
    LINKER_SEGMENT *current_seg;
    for (i = 0; i < num_segments; i++)
    {
        current_seg = &segment_table[i];
        if (current_seg->section_header.sh_flags & SHF_EXECINSTR)
        {
            current_seg->elf_output_section_index = elf_add_code_section(out_elf_context, current_seg->section_header.sh_entsize, current_seg->segment_relocated_start_address, current_seg->data);
        }
        else
        {
            current_seg->elf_output_section_index = elf_add_data_section(out_elf_context, current_seg->section_header.sh_entsize, current_seg->segment_relocated_start_address, current_seg->data);
        }

        elf_update_section_size(out_elf_context, current_seg->elf_output_section_index, current_seg->section_header.sh_size);
    }

}