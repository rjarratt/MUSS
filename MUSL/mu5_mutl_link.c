#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elf.h"

#define MAX_IMPORT_MODULES 64

typedef struct
{
    char *name;
    Elf32_Addr value;
} LINKER_SYMBOL;

static void *elf_modules[MAX_IMPORT_MODULES];
static int num_modules;
static LINKER_SYMBOL *symbol_table;
static int total_symbol_count;
static int loaded_symbol_count;

static void count_symbol(char *name, Elf32_Addr value, Elf32_Word size, int type, unsigned char st_other, Elf32_Half section_index);
static void add_symbol(char *name, Elf32_Addr value, Elf32_Word size, int type, unsigned char st_other, Elf32_Half section_index);
static void compute_total_symbols(void);
static int compare_symbol_name(const void *sym1, const void *sym2);
static void build_symbol_table(void);
static void check_for_symbols_with_multiple_definitions(void);

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
    elf_modules[num_modules++] = elf_read_file(f, 0);
    fclose(f);
}

void link_modules(char *filename)
{
    build_symbol_table();
}

static void count_symbol(char *name, Elf32_Addr value, Elf32_Word size, int type, unsigned char st_other, Elf32_Half section_index)
{
    total_symbol_count++;
}

static void add_symbol(char *name, Elf32_Addr value, Elf32_Word size, int type, unsigned char st_other, Elf32_Half section_index)
{
    LINKER_SYMBOL *link_sym = &symbol_table[loaded_symbol_count++];
    link_sym->name = name;
    link_sym->value = value;
}

static void  compute_total_symbols()
{
    int i;
    for (i = 0; i < num_modules; i++)
    {
        elf_process_defined_symbols(elf_modules[i], count_symbol);
    }
}

static int compare_symbol_name(const void *sym1, const void *sym2)
{
    LINKER_SYMBOL *ls1 = sym1;
    LINKER_SYMBOL *ls2 = sym2;

    return strcmp(ls1->name, ls2->name);
}

static void build_symbol_table(void)
{
    int i;
    
    compute_total_symbols();

    symbol_table = (LINKER_SYMBOL *)(malloc(total_symbol_count * sizeof(LINKER_SYMBOL)));
    for (i = 0; i < num_modules; i++)
    {
        elf_process_defined_symbols(elf_modules[i], add_symbol);
    }

    qsort(symbol_table, total_symbol_count, sizeof(LINKER_SYMBOL), compare_symbol_name);

    check_for_symbols_with_multiple_definitions();
}

static void check_for_symbols_with_multiple_definitions(void)
{
    int i;
    char *last_name = "";
    int error = 0;
    for (i = 0; i < total_symbol_count; i++)
    {
        LINKER_SYMBOL *sym = &symbol_table[i];
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
