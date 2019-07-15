#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elf.h"

#define MAX_SYMBOLS 1024
#define MAX_STRING_DATA 10240

typedef struct elf32_section
{
    Elf32_Shdr section_header;
    Elf32_Half section_index;
    struct elf32_section *next_section;
    void *data;
} Elf32_Section;

typedef struct elf32_context
{
    Elf32_Ehdr elf_header;
    Elf32_Section *symbol_table_section;
    Elf32_Section *section_header_string_table_section;
    Elf32_Section *string_table_section;
    Elf32_Section *section_list_head;
    Elf32_Section *section_list_tail;
} Elf32_Context;

static Elf32_Section *add_section(Elf32_Context *ctx, Elf32_Shdr *header);
static int is_empty_section(Elf32_Section *section);
static void create_empty_section(Elf32_Context *ctx);
static void create_symbol_table(Elf32_Context *ctx);
static void create_section_header_string_table(Elf32_Context *ctx);
static void create_string_table(Elf32_Context *ctx);

static int add_string(Elf32_Section *section, char *string);

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

    ctx->elf_header.e_type = encode_half(e_type);
    ctx->elf_header.e_machine = encode_half(0);
    ctx->elf_header.e_version = encode_word(EV_CURRENT);
    ctx->elf_header.e_entry = encode_addr(e_entry);
    ctx->elf_header.e_flags = encode_word(e_flags);
    ctx->elf_header.e_ehsize = encode_half(sizeof(ctx->elf_header));

    ctx->elf_header.e_shentsize = encode_half(sizeof(Elf32_Shdr));

    create_empty_section(ctx);
    create_section_header_string_table(ctx);
    create_string_table(ctx);
    create_symbol_table(ctx);

    return ctx;
}

int elf_add_code_section(void *context, Elf32_Word word_size, Elf32_Addr address)
{
    Elf32_Context *ctx = context;
    Elf32_Shdr header;
    Elf32_Section *section;
    memset(&header, 0, sizeof(Elf32_Shdr));
    header.sh_name = encode_word(add_string(ctx->section_header_string_table_section, ".text"));
    header.sh_type = encode_word(SHT_PROGBITS);
    header.sh_flags = encode_word(SHF_ALLOC | SHF_EXECINSTR);
    header.sh_addr = encode_addr(address);
    header.sh_entsize = encode_word(word_size);
    section = add_section(ctx, &header);
    section->data = calloc(1, 100);
    section->section_header.sh_size = 100;
    return section->section_index;
}

int elf_add_data_section(void *context, Elf32_Word word_size, Elf32_Addr address)
{
    Elf32_Context *ctx = context;
    Elf32_Shdr header;
    Elf32_Section *section;
    memset(&header, 0, sizeof(Elf32_Shdr));
    header.sh_name = encode_word(add_string(ctx->section_header_string_table_section, ".data"));
    header.sh_type = encode_word(SHT_PROGBITS);
    header.sh_flags = encode_word(SHF_ALLOC | SHF_WRITE);
    header.sh_addr = encode_addr(address);
    header.sh_entsize = encode_word(word_size);
    section = add_section(ctx, &header);
    section->data = calloc(1, 100);
    section->section_header.sh_size = 100;
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
    sym->st_name = encode_word(add_string(ctx->string_table_section, name));
    sym->st_value = encode_addr(value);
    sym->st_size = encode_word(size);
    sym->st_info = ELF32_ST_INFO(STB_GLOBAL, type);
    sym->st_other = 0;
    sym->st_shndx = encode_half(section_index);
    ctx->symbol_table_section->section_header.sh_size += sizeof(Elf32_Sym);
}

void elf_write_file(void *context, char *file_name)
{
    Elf32_Off section_offset;
    int num_sections;
    Elf32_Context *ctx = context;
    FILE *f = fopen(file_name, "wb");

    num_sections = ctx->elf_header.e_shnum;
    ctx->elf_header.e_shoff = encode_off(sizeof(ctx->elf_header));
    ctx->elf_header.e_shnum = encode_half(ctx->elf_header.e_shnum);

    fwrite(&ctx->elf_header, sizeof(ctx->elf_header), 1, f);

    /* write section table */
    Elf32_Section *section = ctx->section_list_head;
    section_offset = sizeof(Elf32_Ehdr) + (num_sections * sizeof(Elf32_Shdr));
    while (section != NULL)
    {
        if (!is_empty_section(section))
        {
            section->section_header.sh_offset = encode_off(section_offset);
        }

        section_offset += section->section_header.sh_size;
        section->section_header.sh_size = encode_word(section->section_header.sh_size);
        fwrite(&section->section_header, sizeof(Elf32_Shdr), 1, f);
        section = section->next_section;
    }

    /* write sections */
    section = ctx->section_list_head;
    while (section != NULL)
    {
        int section_size = decode_off(section->section_header.sh_size);
        fwrite(section->data, 1, section_size, f);
        section = section->next_section;
    }

    fclose(f);
}

static Elf32_Section *add_section(Elf32_Context *ctx, Elf32_Shdr *header)
{
    ctx->elf_header.e_shnum++;
    Elf32_Section *new_section = (Elf32_Section *)malloc(sizeof(Elf32_Section));
    memcpy(&new_section->section_header, header, sizeof(Elf32_Shdr));
    new_section->data = NULL;
    new_section->next_section = NULL;
    new_section->section_index = ctx->elf_header.e_shnum - 1;

    if (ctx->section_list_head == NULL)
    {
        ctx->section_list_head = new_section;
    }
    else
    {
        ctx->section_list_tail->next_section = new_section;
    }

    ctx->section_list_tail = new_section;

    return new_section;
}

static int is_empty_section(Elf32_Section *section)
{
    return section->section_header.sh_type == encode_word(SHT_NULL);
}

static void create_empty_section(Elf32_Context *ctx)
{
    Elf32_Shdr header;
    memset(&header, 0, sizeof(Elf32_Shdr));
    header.sh_name = encode_word(0);
    header.sh_type = encode_word(SHT_NULL);
    header.sh_link = encode_word(SHN_UNDEF);
    add_section(ctx, &header);
}

static void create_symbol_table(Elf32_Context *ctx)
{
    Elf32_Shdr header;
    memset(&header, 0, sizeof(Elf32_Shdr));
    header.sh_name = encode_word(add_string(ctx->section_header_string_table_section, ".symtab"));
    header.sh_type = encode_word(SHT_SYMTAB);
    header.sh_flags = encode_word(0);
    header.sh_addr = encode_addr(0);
    header.sh_link = encode_word(ctx->string_table_section->section_index);
    header.sh_entsize = encode_word(sizeof(Elf32_Sym));
    ctx->symbol_table_section = add_section(ctx, &header);
    ctx->symbol_table_section->data = calloc(MAX_SYMBOLS, sizeof(Elf32_Sym));

    Elf32_Sym *empty_sym = ctx->symbol_table_section->data;
    empty_sym->st_shndx = encode_half(SHN_UNDEF);
    ctx->symbol_table_section->section_header.sh_size = sizeof(Elf32_Sym);
}

static void create_section_header_string_table(Elf32_Context *ctx)
{
    Elf32_Shdr header;
    memset(&header, 0, sizeof(Elf32_Shdr));
    header.sh_name = encode_word(1);
    header.sh_type = encode_word(SHT_STRTAB);
    header.sh_flags = encode_word(0);
    header.sh_addr = encode_addr(0);
    header.sh_entsize = encode_word(0);
    ctx->section_header_string_table_section = add_section(ctx, &header);
    ctx->section_header_string_table_section->data = calloc(1, MAX_STRING_DATA);
    ctx->section_header_string_table_section->section_header.sh_size = 1;
    ctx->elf_header.e_shstrndx = encode_half(ctx->section_header_string_table_section->section_index);

    add_string(ctx->section_header_string_table_section, ".shstrtab");
}

static void create_string_table(Elf32_Context *ctx)
{
    Elf32_Shdr header;
    memset(&header, 0, sizeof(Elf32_Shdr));
    header.sh_name = encode_word(add_string(ctx->section_header_string_table_section, ".strtab"));
    header.sh_type = encode_word(SHT_STRTAB);
    header.sh_flags = encode_word(0);
    header.sh_addr = encode_addr(0);
    header.sh_entsize = encode_word(0);
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

