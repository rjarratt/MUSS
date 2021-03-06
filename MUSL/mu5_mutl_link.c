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
    Elf32_Half elf_input_section_index;
    Elf32_Half elf_output_section_index;
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

typedef struct
{
    char *lookup_name;
    Elf32_Sym *found_symbol;
} SYMBOL_SCAN;

extern void fatal(char *format, ...);

static Elf32_Addr entry_point;
static int num_modules;
static LINKER_MODULE elf_modules[MAX_IMPORT_MODULES];
static int num_segments;
static LINKER_SEGMENT *segment_table;
static LINKER_SYMBOL_TABLE global_symbol_table = { 0, STB_GLOBAL, NULL };
static LINKER_SYMBOL_TABLE local_symbol_table = { 0, STB_LOCAL, NULL };

static LINKER_SEGMENT *get_linker_segment_for_section(void *context, int section_index);
static void check_segment_for_start_address(LINKER_SEGMENT *segment);
static void count_symbol(void *elf_context, void *symbol, void *context, char *name, Elf32_Addr value, Elf32_Word size, int binding, int type, unsigned char st_other, Elf32_Half section_index);
static void add_symbol(void *elf_context, void *symbol, void *context, char *name, Elf32_Addr value, Elf32_Word size, int binding, int type, unsigned char st_other, Elf32_Half section_index);
static void scan_for_symbol(void *elf_context, void *symbol, void *context, char *name, Elf32_Addr value, Elf32_Word size, int binding, int type, unsigned char st_other, Elf32_Half section_index);
static void compute_total_symbols(LINKER_SYMBOL_TABLE *symbol_table);
static int compare_symbol_name(const void *sym1, const void *sym2);
static int compare_segment_by_section_address(const void *seg1, const void *seg2);
static void build_global_symbol_table(void);
static void build_local_symbol_table(void *elf_context);
static LINKER_SYMBOL *get_linker_symbol(void *elf_module_context, int symbol_index, LINKER_SYMBOL_TABLE *symbol_table);
static void check_for_symbols_with_multiple_definitions(LINKER_SYMBOL_TABLE *symbol_table);
static void process_segments(Elf32_Word flag, void *callback_context, void(*process_segment)(LINKER_MODULE *module, Elf32_Half section_index, void *callback_context));
static void count_segments(void);
static void count_segment(LINKER_MODULE *module, Elf32_Half section_index, void *callback_context);
static void define_segments(void);
static void define_segment(LINKER_MODULE *module, Elf32_Half section_index, void *callback_context);
static void resolve_symbols(void);
static void resolve_symbol_in_segment(LINKER_SEGMENT *linker_segment);
static void write_32_bit_resolution(LINKER_SEGMENT *linker_segment, char *name, Elf32_Rela *rela_entry, Elf32_Addr new_addr);
static void write_16_bit_resolution(LINKER_SEGMENT *linker_segment, char *name, Elf32_Rela *rela_entry, Elf32_Half new_addr);
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
        exit(1);
    }

    LINKER_MODULE *module = &elf_modules[num_modules++];
    strncpy(module->module_name, filename, sizeof(module->module_name));
    module->elf_module_context = elf_read_file(f, 0);
    fclose(f);
}

void link_modules(char *filename)
{
    void *out_elf_context = elf_new_file(ET_EXEC, 0, 0);
    define_segments();
    elf_set_entry(out_elf_context, entry_point);
    build_global_symbol_table();
    resolve_symbols();
    add_segments_to_output(out_elf_context);
    elf_write_file(out_elf_context, filename);
}

Elf32_Sym *get_symbol(char *name)
{
    int i;
    SYMBOL_SCAN scan;
    scan.lookup_name = name;
    scan.found_symbol = NULL;
    for (i = 0; i < num_modules; i++)
    {
        elf_process_defined_symbols(elf_modules[i].elf_module_context, &scan, scan_for_symbol);
    }

    return scan.found_symbol;
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

static void check_segment_for_start_address(LINKER_SEGMENT *segment)
{
    Elf32_Ehdr elf_header;
    elf_get_elf_header(segment->module->elf_module_context, &elf_header);
    if (elf_header.e_type == ET_EXEC)
    {
        if (elf_header.e_entry >= segment->section_header.sh_addr && elf_header.e_entry < (segment->section_header.sh_addr + segment->section_header.sh_size))
        {
            entry_point = segment->segment_relocated_start_address + (elf_header.e_entry - segment->section_header.sh_addr);
        }
    }
}

static void count_symbol(void *elf_context, void *symbol, void *context, char *name, Elf32_Addr value, Elf32_Word size, int binding, int type, unsigned char st_other, Elf32_Half section_index)
{
    LINKER_SYMBOL_TABLE *symbol_table = context;
    if (binding == symbol_table->binding_filter)
    {
        symbol_table->num_symbols++;
    }
}

static void add_symbol(void *elf_context, void *symbol, void *context, char *name, Elf32_Addr value, Elf32_Word size, int binding, int type, unsigned char st_other, Elf32_Half section_index)
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

static void scan_for_symbol(void *elf_context, void *symbol, void *context, char *name, Elf32_Addr value, Elf32_Word size, int binding, int type, unsigned char st_other, Elf32_Half section_index)
{
    SYMBOL_SCAN *scan = context;
    if (strcmp(name, scan->lookup_name) == 0)
    {
        scan->found_symbol = symbol;
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
    LINKER_SYMBOL *ls1 = (LINKER_SYMBOL *)sym1;
    LINKER_SYMBOL *ls2 = (LINKER_SYMBOL *)sym2;

    return strcmp(ls1->name, ls2->name);
}

static int compare_segment_by_section_address(const void *seg1, const void *seg2)
{
    LINKER_SEGMENT *ls1 = (LINKER_SEGMENT *)seg1;
    LINKER_SEGMENT *ls2 = (LINKER_SEGMENT *)seg2;

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
        exit(1);
    }
}

static void process_segments(Elf32_Word flag, void *callback_context, void(*process_segment)(LINKER_MODULE *module, Elf32_Half section_index, void *callback_context))
{
    int module_index;
    Elf32_Half section_index;
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

static void count_segment(LINKER_MODULE *module, Elf32_Half section_index, void *callback_context)
{
    num_segments++;
}

static void define_segments(void)
{
    Elf32_Half segment_index = 0;
    count_segments();
    segment_table = calloc(num_segments, sizeof(LINKER_SEGMENT));
    process_segments(SHT_PROGBITS, &segment_index, define_segment);
    qsort(segment_table, num_segments, sizeof(LINKER_SEGMENT), compare_segment_by_section_address);
    compute_segment_start_addresses();
}

static void define_segment(LINKER_MODULE *module, Elf32_Half section_index, void *callback_context)
{
    Elf32_Half *segment_index = callback_context;
    Elf32_Half relocation_section;
    LINKER_SEGMENT *segment = &segment_table[(*segment_index)++];
    segment->module = module;
    segment->elf_input_section_index = section_index;
    elf_get_section_header(module->elf_module_context, &segment->section_header, &segment->data, section_index);
    relocation_section = elf_get_relocation_section(module->elf_module_context, section_index);
    if (relocation_section != SHN_UNDEF)
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

            if (linker_symbol == NULL)
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
                write_32_bit_resolution(linker_segment, name, rela_entry, new_addr);
            }
            else if (linker_symbol->type == STT_OBJECT && rel_type == MU5_REL_TYPE_VAR_BASE)
            {
                new_addr = linker_symbol->segment->segment_relocated_start_address / 4;
                write_32_bit_resolution(linker_segment, name, rela_entry, new_addr);
            }
            else if (linker_symbol->type == STT_OBJECT && rel_type == MU5_REL_TYPE_VAR_OFFSET)
            {
                write_16_bit_resolution(linker_segment, name, rela_entry, linker_symbol->value & 0xFFFF);
            }
            else if (linker_symbol->type == STT_OBJECT && rel_type == MU5_REL_TYPE_16_BIT_VALUE)
            {
                write_16_bit_resolution(linker_segment, name, rela_entry, linker_symbol->value & 0xFFFF);
            }
            else if (linker_symbol->type == STT_OBJECT && rel_type == MU5_REL_TYPE_32_BIT_VALUE)
            {
                write_32_bit_resolution(linker_segment, name, rela_entry, linker_symbol->value & 0xFFFFFFFF);
            }
            else if (rel_type == MU5_REL_TYPE_DESC_LIT)
            {
                new_addr = linker_symbol->segment->segment_relocated_start_address + rela_entry->r_addend;
                write_32_bit_resolution(linker_segment, name, rela_entry, new_addr);
            }
            else
            {
                perror("Unrecognised link type");
                exit(1);
            }
        }
    }
}

static void write_32_bit_resolution(LINKER_SEGMENT *linker_segment, char *name, Elf32_Rela *rela_entry, Elf32_Addr new_addr)
{
    printf("Resolved %s reference at offset %08X to %08X\n", name, rela_entry->r_offset, new_addr);
    char *ptr = &linker_segment->data[rela_entry->r_offset];
    *ptr++ = (new_addr >> 24) & 0xFF;
    *ptr++ = (new_addr >> 16) & 0xFF;
    *ptr++ = (new_addr >> 8) & 0xFF;
    *ptr++ = (new_addr & 0xFF);
}

static void write_16_bit_resolution(LINKER_SEGMENT *linker_segment, char *name, Elf32_Rela *rela_entry, Elf32_Half new_addr)
{
    printf("Resolved %s reference at offset %08X to %04X\n", name, rela_entry->r_offset, new_addr);
    char *ptr = &linker_segment->data[rela_entry->r_offset];
    *ptr++ = (new_addr >> 8) & 0xFF;
    *ptr++ = (new_addr & 0xFF);
}

static void compute_segment_start_addresses(void)
{
    int i;
    Elf32_Addr last_addr = (Elf32_Addr)~0;
    LINKER_SEGMENT *current_seg = NULL;
    LINKER_SEGMENT *previous_seg = NULL;
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

        check_segment_for_start_address(current_seg);

        printf("Module %s, section %s, segment start address = %08X\n", current_seg->module->module_name, elf_get_section_name(current_seg->module->elf_module_context, current_seg->section_header.sh_name), current_seg->segment_relocated_start_address);

        previous_seg = current_seg;
    }
}

static void add_segments_to_output(void *out_elf_context)
{
    int i;
    char name[_MAX_PATH];
    LINKER_SEGMENT *current_seg;
    for (i = 0; i < num_segments; i++)
    {
        current_seg = &segment_table[i];
        if (current_seg->section_header.sh_flags & SHF_EXECINSTR)
        {
            sprintf(name, "%s.text", current_seg->module->module_name);
            current_seg->elf_output_section_index = elf_add_code_section(out_elf_context, name, current_seg->section_header.sh_entsize, current_seg->segment_relocated_start_address, current_seg->data);
        }
        else
        {
            sprintf(name, "%s.data", current_seg->module->module_name);
            current_seg->elf_output_section_index = elf_add_data_section(out_elf_context, name, current_seg->section_header.sh_entsize, current_seg->segment_relocated_start_address, current_seg->data);
        }

        elf_update_section_size(out_elf_context, current_seg->elf_output_section_index, current_seg->section_header.sh_size);
    }
}