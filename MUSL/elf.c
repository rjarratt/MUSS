#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elf.h"

#define MAX_SYMBOLS 1024
#define MAX_STRING_DATA 10240
#define MAX_SECTIONS 32

typedef struct elf32_section
{
    Elf32_Shdr section_header;
    Elf32_Half section_index;
    void *data;
    void *(*encode_data_entry)(void *);
    void *(*decode_data_entry)(void *);
} Elf32_Section;

typedef struct elf32_context
{
    Elf32_Ehdr elf_header;
    Elf32_Section *symbol_table_section;
    Elf32_Section *section_header_string_table_section;
    Elf32_Section *string_table_section;
    Elf32_Section section_table[MAX_SECTIONS];
} Elf32_Context;

static Elf32_Section *add_section(Elf32_Context *ctx, Elf32_Shdr *header);
static int is_empty_section(Elf32_Section *section);
static void create_empty_section(Elf32_Context *ctx);
static void create_symbol_table(Elf32_Context *ctx);
static void create_section_header_string_table(Elf32_Context *ctx);
static void create_string_table(Elf32_Context *ctx);

static int add_string(Elf32_Section *section, char *string);

static Elf32_Ehdr *encode_ehdr(Elf32_Ehdr *header);
static Elf32_Shdr *encode_shdr(Elf32_Shdr *header);
static Elf32_Sym *encode_sym(Elf32_Sym *sym);
static Elf32_Half encode_half(Elf32_Half half);
static Elf32_Word encode_word(Elf32_Word word);
static Elf32_Off encode_off(Elf32_Off off);
static Elf32_Addr encode_addr(Elf32_Addr addr);

static Elf32_Half decode_half(Elf32_Off off);
static Elf32_Off decode_off(Elf32_Off off);


void *elf_new_file(Elf32_Half e_type, Elf32_Half e_machine, Elf32_Addr e_entry, Elf32_Word e_flags)
{
    Elf32_Context *ctx = (Elf32_Context *)malloc(sizeof(Elf32_Context));
    memset(ctx, 0, sizeof(Elf32_Context));
    ctx->elf_header.e_ident[EI_MAG0] = ELFMAG0;
    ctx->elf_header.e_ident[EI_MAG1] = ELFMAG1;
    ctx->elf_header.e_ident[EI_MAG2] = ELFMAG2;
    ctx->elf_header.e_ident[EI_MAG3] = ELFMAG3;
    ctx->elf_header.e_ident[EI_CLASS] = ELFCLASS32;
    ctx->elf_header.e_ident[EI_DATA] = ELFDATA2MSB; /* big endian */
    ctx->elf_header.e_ident[EI_VERSION] = EV_CURRENT;

    ctx->elf_header.e_type = e_type;
    ctx->elf_header.e_machine = 0;
    ctx->elf_header.e_version = EV_CURRENT;
    ctx->elf_header.e_entry = e_entry;
    ctx->elf_header.e_flags = e_flags;
    ctx->elf_header.e_ehsize = sizeof(ctx->elf_header);

    ctx->elf_header.e_shentsize = sizeof(Elf32_Shdr);

    create_empty_section(ctx);
    create_section_header_string_table(ctx);
    create_string_table(ctx);
    create_symbol_table(ctx);

    return ctx;
}

int elf_add_code_section(void *context, Elf32_Word word_size, Elf32_Addr address, char *data)
{
    Elf32_Context *ctx = context;
    Elf32_Shdr header;
    Elf32_Section *section;
    memset(&header, 0, sizeof(Elf32_Shdr));
    header.sh_name = add_string(ctx->section_header_string_table_section, ".text");
    header.sh_type = SHT_PROGBITS;
    header.sh_flags = SHF_ALLOC | SHF_EXECINSTR;
    header.sh_addr = address;
    header.sh_entsize = word_size;
    section = add_section(ctx, &header);
    section->data = data;
    return section->section_index;
}

int elf_add_data_section(void *context, Elf32_Word word_size, Elf32_Addr address)
{
    Elf32_Context *ctx = context;
    Elf32_Shdr header;
    Elf32_Section *section;
    memset(&header, 0, sizeof(Elf32_Shdr));
    header.sh_name = add_string(ctx->section_header_string_table_section, ".data");
    header.sh_type = SHT_PROGBITS;
    header.sh_flags = SHF_ALLOC | SHF_WRITE;
    header.sh_addr = address;
    header.sh_entsize = word_size;
    section = add_section(ctx, &header);
    section->data = calloc(1, 100);
    section->section_header.sh_size = 100;
    return section->section_index;
}

int elf_add_bss_section(void *context, Elf32_Word word_size, Elf32_Addr address)
{
    Elf32_Context *ctx = context;
    Elf32_Shdr header;
    Elf32_Section *section;
    memset(&header, 0, sizeof(Elf32_Shdr));
    header.sh_name = add_string(ctx->section_header_string_table_section, ".bss");
    header.sh_type = SHT_NOBITS;
    header.sh_flags = SHF_ALLOC | SHF_WRITE;
    header.sh_addr = address;
    header.sh_entsize = word_size;
    section = add_section(ctx, &header);
    return section->section_index;
}

void elf_add_global_symbol(void *context, char *name, Elf32_Addr value, Elf32_Word size, int type, Elf32_Half section_index)
{
    Elf32_Context *ctx = context;
    int num_symbols = ctx->symbol_table_section->section_header.sh_size / sizeof(Elf32_Sym);
    if (num_symbols >= MAX_SYMBOLS)
    {
        perror("Too many symbols");
        exit(1);
    }

    Elf32_Sym *sym = (Elf32_Sym *)ctx->symbol_table_section->data + num_symbols;
    sym->st_name = add_string(ctx->string_table_section, name);
    sym->st_value = value;
    sym->st_size = size;
    sym->st_info = ELF32_ST_INFO(STB_GLOBAL, type);
    sym->st_other = 0;
    sym->st_shndx = section_index;
    ctx->symbol_table_section->section_header.sh_size += sizeof(Elf32_Sym);
}

void elf_add_binary_data_to_section(void *context, Elf32_Half section_index, char *data, int length)
{
    Elf32_Context *ctx = context;
    Elf32_Section *section = &ctx->section_table[section_index];
    if (section->section_header.sh_type != SHT_NOBITS)
    {
        memcpy((char *)section->data + section->section_header.sh_size, data, length);
    }
    section->section_header.sh_size += length;
}

void elf_write_file(void *context, char *file_name)
{
    Elf32_Off section_offset;
    int num_sections;
    Elf32_Context *ctx = context;
    int section_index;
    FILE *f = fopen(file_name, "wb");

    num_sections = ctx->elf_header.e_shnum;
    ctx->elf_header.e_shoff = sizeof(ctx->elf_header);
    ctx->elf_header.e_shnum = ctx->elf_header.e_shnum;

    fwrite(encode_ehdr(&ctx->elf_header), sizeof(ctx->elf_header), 1, f);

    /* write section table */
    section_offset = sizeof(Elf32_Ehdr) + (num_sections * sizeof(Elf32_Shdr));
    for (section_index = 0; section_index < num_sections; section_index++)
    {
        Elf32_Section *section = &ctx->section_table[section_index];
        if (!is_empty_section(section))
        {
            section->section_header.sh_offset = section_offset;
        }

        section_offset += section->section_header.sh_size;
        section->section_header.sh_size = section->section_header.sh_size;
        fwrite(encode_shdr(&section->section_header), sizeof(Elf32_Shdr), 1, f);
    }

    /* write sections */
    for (section_index = 0; section_index < num_sections; section_index++)
    {
        Elf32_Section *section = &ctx->section_table[section_index];
        int section_size = section->section_header.sh_size;
        int entry_size = section->section_header.sh_entsize;
        if (section->section_header.sh_type != SHT_NOBITS)
        {
            if (section->encode_data_entry == NULL)
            {
                fwrite(section->data, 1, section_size, f);
            }
            else
            {
                int i;
                int n = section_size / entry_size;
                for (i = 0; i < n; i++)
                {
                    void *buffer = section->encode_data_entry((char *)(section->data) + (i * entry_size));
                    fwrite(buffer, entry_size, 1, f);
                }
            }
        }
    }

    fclose(f);
}

static Elf32_Section *add_section(Elf32_Context *ctx, Elf32_Shdr *header)
{
    ctx->elf_header.e_shnum++;
    if (ctx->elf_header.e_shnum >= MAX_SECTIONS)
    {
        perror("Too many sections");
        exit(1);
    }

    Elf32_Section *new_section = &ctx->section_table[ctx->elf_header.e_shnum - 1];
    memcpy(&new_section->section_header, header, sizeof(Elf32_Shdr));
    new_section->data = NULL;
    new_section->section_index = ctx->elf_header.e_shnum - 1;
    new_section->encode_data_entry = NULL;
    new_section->decode_data_entry = NULL;

    return new_section;
}

static int is_empty_section(Elf32_Section *section)
{
    return section->section_header.sh_type == SHT_NULL;
}

static void create_empty_section(Elf32_Context *ctx)
{
    Elf32_Shdr header;
    memset(&header, 0, sizeof(Elf32_Shdr));
    header.sh_name = 0;
    header.sh_type = SHT_NULL;
    header.sh_link = SHN_UNDEF;
    add_section(ctx, &header);
}

static void create_symbol_table(Elf32_Context *ctx)
{
    Elf32_Shdr header;
    memset(&header, 0, sizeof(Elf32_Shdr));
    header.sh_name = add_string(ctx->section_header_string_table_section, ".symtab");
    header.sh_type = SHT_SYMTAB;
    header.sh_flags = 0;
    header.sh_addr = 0;
    header.sh_link = ctx->string_table_section->section_index;
    header.sh_entsize = sizeof(Elf32_Sym);
    ctx->symbol_table_section = add_section(ctx, &header);
    ctx->symbol_table_section->data = calloc(MAX_SYMBOLS, sizeof(Elf32_Sym));
    ctx->symbol_table_section->encode_data_entry = encode_sym;

    Elf32_Sym *empty_sym = ctx->symbol_table_section->data;
    empty_sym->st_shndx = encode_half(SHN_UNDEF);
    ctx->symbol_table_section->section_header.sh_size = sizeof(Elf32_Sym);
}

static void create_section_header_string_table(Elf32_Context *ctx)
{
    Elf32_Shdr header;
    memset(&header, 0, sizeof(Elf32_Shdr));
    header.sh_name = 1;
    header.sh_type = SHT_STRTAB;
    header.sh_flags = 0;
    header.sh_addr = 0;
    header.sh_entsize = 0;
    ctx->section_header_string_table_section = add_section(ctx, &header);
    ctx->section_header_string_table_section->data = calloc(1, MAX_STRING_DATA);
    ctx->section_header_string_table_section->section_header.sh_size = 1;
    ctx->elf_header.e_shstrndx = ctx->section_header_string_table_section->section_index;

    add_string(ctx->section_header_string_table_section, ".shstrtab");
}

static void create_string_table(Elf32_Context *ctx)
{
    Elf32_Shdr header;
    memset(&header, 0, sizeof(Elf32_Shdr));
    header.sh_name = add_string(ctx->section_header_string_table_section, ".strtab");
    header.sh_type = SHT_STRTAB;
    header.sh_flags = 0;
    header.sh_addr = 0;
    header.sh_entsize = 0;
    ctx->string_table_section = add_section(ctx, &header);
    ctx->string_table_section->data = calloc(1, MAX_STRING_DATA);
    ctx->string_table_section->section_header.sh_size = 1;
}

static int add_string(Elf32_Section *section, char *string)
{
    int result = section->section_header.sh_size;
    int len = strlen(string) + 1;
    char *ptr = section->data;

    if ((section->section_header.sh_size + len) > MAX_STRING_DATA)
    {
        perror("Too much string data");
        exit(1);
    }

    strcpy(&ptr[result], string);
    section->section_header.sh_size += len;

    return result;
}

static Elf32_Ehdr *encode_ehdr(Elf32_Ehdr *header)
{
    static Elf32_Ehdr result;

    memcpy(&result.e_ident, &header->e_ident, EI_NIDENT);
    result.e_type = encode_half(header->e_type);
    result.e_machine = encode_half(header->e_machine);
    result.e_version = encode_word(header->e_version);
    result.e_entry = encode_addr(header->e_entry);
    result.e_phoff = encode_off(header->e_phoff);
    result.e_shoff = encode_off(header->e_shoff);
    result.e_flags = encode_word(header->e_flags);
    result.e_ehsize = encode_half(header->e_ehsize);
    result.e_phentsize = encode_half(header->e_phentsize);
    result.e_phnum = encode_half(header->e_phnum);
    result.e_shentsize = encode_half(header->e_shentsize);
    result.e_shnum = encode_half(header->e_shnum);
    result.e_shstrndx = encode_half(header->e_shstrndx);

    return &result;
}

static Elf32_Shdr *encode_shdr(Elf32_Shdr *header)
{
    static Elf32_Shdr result;

    result.sh_name = encode_word(header->sh_name);
    result.sh_type = encode_word(header->sh_type);
    result.sh_flags = encode_word(header->sh_flags);
    result.sh_addr = encode_addr(header->sh_addr);
    result.sh_offset = encode_off(header->sh_offset);
    result.sh_size = encode_word(header->sh_size);
    result.sh_link = encode_word(header->sh_link);
    result.sh_info = encode_word(header->sh_info);
    result.sh_addralign = encode_word(header->sh_addralign);
    result.sh_entsize = encode_word(header->sh_entsize);


    return &result;
}

static Elf32_Sym *encode_sym(Elf32_Sym *sym)
{
    static Elf32_Sym result;

    result.st_name = encode_word(sym->st_name);
    result.st_value = encode_addr(sym->st_value);
    result.st_size = encode_word(sym->st_size);
    result.st_info = sym->st_info;
    result.st_other = sym->st_other;
    result.st_shndx = encode_half(sym->st_shndx);

    return &result;
}

static Elf32_Half encode_half(Elf32_Half half)
{
    Elf32_Half result;
    unsigned char *ptr = (char *)(&result);
    *ptr++ = (half >> 8) & 0xFF;
    *ptr++ = (half & 0xFF);
    return result;
}

static Elf32_Word encode_word(Elf32_Word word)
{
    Elf32_Word result;
    unsigned char *ptr = (char *)(&result);
    *ptr++ = (word >> 24) & 0xFF;
    *ptr++ = (word >> 16) & 0xFF;
    *ptr++ = (word >> 8) & 0xFF;
    *ptr++ = (word & 0xFF);
    return result;
}

static Elf32_Off encode_off(Elf32_Off off)
{
    Elf32_Off result;
    unsigned char *ptr = (char *)(&result);
    *ptr++ = (off >> 24) & 0xFF;
    *ptr++ = (off >> 16) & 0xFF;
    *ptr++ = (off >> 8) & 0xFF;
    *ptr++ = (off & 0xFF);
    return result;
}

static Elf32_Addr encode_addr(Elf32_Addr addr)
{
    Elf32_Addr result;
    unsigned char *ptr = (char *)(&result);
    *ptr++ = (addr >> 24) & 0xFF;
    *ptr++ = (addr >> 16) & 0xFF;
    *ptr++ = (addr >> 8) & 0xFF;
    *ptr++ = (addr & 0xFF);
    return result;
}

static Elf32_Half decode_half(Elf32_Half off)
{
    Elf32_Half result = 0;
    unsigned char *ptr = (char *)(&off);
    result = result << 8 | (*ptr++);
    result = result << 8 | (*ptr++);
    return result;

}

static Elf32_Off decode_off(Elf32_Off off)
{
    Elf32_Off result = 0;
    unsigned char *ptr = (char *)(&off);
    result = result << 8 | (*ptr++);
    result = result << 8 | (*ptr++);
    result = result << 8 | (*ptr++);
    result = result << 8 | (*ptr++);
    return result;
}

