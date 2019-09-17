#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "support.h"
#include "mu5_mutl_link.h"
#include "mu5_mutl.h"
#include "elf.h"

/* TODO global ref check on every call, but check for literals when they are vectors planted in code rather than literals */
/* Information on code organisation

Global Variables
================
A module can have a number of global variables. These have to be accessed using the XNB register. It would be possible
to record every global variable access and have the linker embed the XNB address of each global variable before
each global variable access. However, XNB is 64-bit aligned, so every global variable would need to be 64-bit aligned.
The alternative is to have XNB be loaded with the base of each global variable segment and then use a Name offset
to get the variable. However, it is possible for a module to use directives to put globals in different areas, so it
would be necessary to track the areas and have different base addresses loaded by the linker for different global variables.

The approach taken is to have XNB loaded with the base address of the area on each global variable access as it is more
space efficient.

*/

/* ELF Notes

To make things simple all addresses are stored in the ELF as byte addresses. They can then be adjusted when loading.
This applies particularly to functions. Names are .....

V-Store pre and post procedures are handled as follows. The symbol entries for the functions are with a symbol name
that is the name of the V-Store variable with a suffix.

*/

#define PROGRAM_MODULE 1
#define LIBRARY_MODULE 2
#define FIRST_NAME 2
#define MAX_IMPORTS 256
#define NO_MODULE (-1)
#define MAX_NAMES 4031
#define MAX_NAME_LEN 32
#define MAX_LITERAL_LEN 256
#define MAX_FORWARD_LOCATIONS 64
#define MAX_BLOCK_DEPTH 16
#define MAX_NESTED_CALLS 16
#define MAX_PROC_PARAMS 16
#define MAX_TYPE_FIELDS 64
#define MAX_LOOP_DEPTH 16
#define MAX_AREAS 256
#define MAX_SEGMENTS 32
#define MAX_SEGMENT_SIZE 65535
#define MAX_HEADER_SIZE_BYTES 65535
#define MAX_RELOCATION_ENTRIES 1024

#define CR_ORG 0
#define CR_B 1
#define CR_STS1 2
#define CR_STS2 3
#define CR_XS 4
#define CR_AU 5
#define CR_ADC 6
#define CR_FLOAT 7

#define F_LOAD_B 0
#define F_LOAD_DEC_B 1
#define F_STACK_LOAD_B 2
#define F_STORE_B 3
#define F_ADD_B 4
#define F_SUB_B 5
#define F_MUL_B 6
#define F_XOR_B 8
#define F_OR_B 9
#define F_SHIFT_L_B 10
#define F_AND_B 11
#define F_RSUB_B 12
#define F_COMP_B 13
#define F_CINC_B 14

#define F_LOAD_X 0
#define F_STACK_LOAD_X 2
#define F_STORE_X 3
#define F_ADD_X 4
#define F_SUB_X 5
#define F_MUL_X 6
#define F_DIV_X 7
#define F_XOR_X 8
#define F_OR_X 9
#define F_SHIFT_L_X 10
#define F_AND_X 11
#define F_RSUB_X 12
#define F_COMP_X 13
#define F_CONV_X 14
#define F_RDIV_X 15

#define F_LOAD_AOD 0
#define F_STACK_LOAD_AOD 2
#define F_STORE_AOD 3
#define F_ADD_A 4
#define F_SUB_A 5
#define F_MUL_A 6
#define F_DIV_A 7
#define F_XOR_A 8
#define F_OR_A 9
#define F_SHIFT_L_A 10
#define F_AND_A 11
#define F_RSUB_A 12
#define F_COMP_A 13

#define F_LOAD_AEX 1
#define F_STACK_LOAD_AEX 2
#define F_STORE_AEX 3
#define F_COMP_AOD 12

#define F_LOAD_XDO 0
#define F_LOAD_XD 1
#define F_STACK 2
#define F_STORE_XD 3
#define F_LOAD_XDB 4
#define F_XCHK 5
#define F_SMOD 6
#define F_XMOD 7
#define F_SLGC 8
#define F_SMVB 9
#define F_SMVF 11
#define F_TALU 12
#define F_SCMP 14
#define F_SUB1 15

#define F_LOAD_DO 0
#define F_LOAD_D 1
#define F_STACK_LOAD_D 2
#define F_STORE_D 3
#define F_LOAD_DB 4
#define F_MDR 5
#define F_MOD 6
#define F_RMOD 7
#define F_BLGC 8
#define F_BMVB 9
#define F_BMVE 10
#define F_BSCN 13
#define F_BCMP 14
#define F_SUB2 15

#define F_LOAD_32 0
#define F_LOAD_64 1
#define F_STACK_LOAD 2
#define F_STORE 3
#define F_XOR 8
#define F_OR 9
#define F_SHIFT_CIRC 10
#define F_AND 11

#define F_RELJUMP 0
#define F_EXIT 1
#define F_ABSJUMP 4
#define F_RETURN 5
#define F_XC0 8
#define F_XC1 9
#define F_XC2 10
#define F_XC3 11
#define F_XC4 12
#define F_XC5 13
#define F_XC6 14
#define F_STACKLINK 15
#define F_MS_LOAD 16
#define F_DL_LOAD 17
#define F_SPM 18
#define F_SETLINK 19
#define F_XNB_LOAD 20
#define F_SN_LOAD 21
#define F_XNB_PLUS 22
#define F_XNB_STORE 23
#define F_SF_LOAD 24
#define F_SF_PLUS 25
#define F_SF_LOAD_NB_PLUS 26
#define F_SF_STORE 27
#define F_NB_LOAD 28
#define F_NB_LOAD_SF_PLUS 29
#define F_NB_PLUS 30
#define F_NB_STORE 31
#define F_BRANCH_EQ 32
#define F_BRANCH_NE 33
#define F_BRANCH_GE 34
#define F_BRANCH_LT 35
#define F_BRANCH_LE 36
#define F_BRANCH_GT 37
#define F_BRANCH_OVF 38
#define F_BRANCH_BN 39
#define F_BN_EQ 40
#define F_BN_NE 41
#define F_BN_GE 42
#define F_BN_LT 43
#define F_BN_LE 44
#define F_BN_GT 45
#define F_BN_OVF 46
#define F_BN_BN 47
#define F_BN_0 48
#define F_BN_BN_AND_X 49
#define F_BN_NOT_BN_AND_X 50
#define F_BN_X 51
#define F_BN_BN_AND_NOT_X 52
#define F_BN_COPY_BN 53
#define F_BNBN_NEQV_X 54
#define F_BN_BN_OR_X 55
#define F_BN_NOT_BN_AND_NOT_X 56
#define F_BN_BN_EQV_X 57
#define F_BN_NOT_BN 58
#define F_BN_NOT_BN_OR_X 59
#define F_BN_NOT_X 60
#define F_BN_BN_OR_NOT_X 61
#define F_BN_NOT_BN_OR_NOT_X 62
#define F_BN_1 63

#define K_LITERAL 0
#define K_IR 1
#define K_V32 2
#define K_V64 3
#define K_SB 4
#define K_SB_5 5
#define K_S0 6
#define K_PRIVILEGED 7

#define KP_LITERAL 0
#define KP_LITERAL_1 1

#define NP_16_BIT_SIGNED_LITERAL 0
#define NP_32_BIT_SIGNED_LITERAL 1
#define NP_64_BIT_LITERAL 2
#define NP_64_BIT_LITERAL_3 3
#define NP_16_BIT_UNSIGNED_LITERAL 4
#define NP_32_BIT_UNSIGNED_LITERAL 5
#define NP_64_BIT_LITERAL_6 6
#define NP_64_BIT_LITERAL_7 7

#define NP_SF 0
#define NP_0 1
#define NP_NB 2
#define NP_XNB 3
#define NP_STACK 4
#define NP_DR 5
#define NP_NB_REF 6
#define NP_XNB_REF 7

#define DESCRIPTOR_8_BIT 3
#define DESCRIPTOR_16_BIT 4
#define DESCRIPTOR_32_BIT 5
#define DESCRIPTOR_64_BIT 6

#define MUTL_NATURE_NAME_ALREADY_DEFINED(N) ((N & 0x2000) == 0x2000)
#define MUTL_NATURE_NAME(N) (N & 0xFFF)

#define BT_BOUNDED_PTR_TO_VECTOR 3

#define BT_MODE_REAL 0
#define BT_MODE_SIGNED_INTEGER 1
#define BT_MODE_UNSIGNED_INTEGER 2
#define BT_MODE_DECIMAL 3

#define TINT32 0x4C

#define OPERAND_LITERAL 0
#define OPERAND_REG_A 0x3000
#define OPERAND_POP 0x1003
#define OPERAND_D_REF 0x1004
#define NO_OPERAND_FOLLOWS_FLAG 0x80
#define OPERAND_FOLLOWS(kn) ((kn & NO_OPERAND_FOLLOWS_FLAG) == 0)
#define IS_MUTL_VAR(n) (n>= 2 && n < 0x1000)
#define IS_SUBROUTINE(NAT) ((NAT & 0x2) == 0x2)

#define UNKNOWN_ADDRESS 0x7FFF

typedef enum { OP_NULL, OP_REGULAR, OP_MODE } OPERANDTYPE;
typedef struct { void(*op)(uint16); OPERANDTYPE op_type; } MUTLOP;

typedef enum { SYM_VARIABLE, SYM_LITERAL, SYM_LABEL, SYM_PROC, SYM_TYPE } SYMBOLTYPE;

typedef struct
{
    uint16 data_type;
    uint16 dimension;
    uint16 position; /* for regular variables this is offset in 32-bit words from NB, including LINK if appropriate, vstore it is the v-line number */
    int is_parameter;
    int is_vstore;
    uint16 v_read_proc;
    void *v_read_proc_sym; /* for imports only */
    uint16 v_write_proc;
    void *v_write_proc_sym; /* for imports only */
} VARSYMBOL;

typedef struct
{
    uint16 data_type;
    uint16 dimension;
    uint16 length;
    uint32 address;
    VECTOR value;
    uint8 valuebuf[MAX_LITERAL_LEN];
} LITSYMBOL;

typedef struct /* some fields in common with PROC so must remain in synch */
{
    int address_defined;
    uint32 address;
    int num_forward_refs;
    uint32 forward_ref_locations[MAX_FORWARD_LOCATIONS];
    uint16 segment_number;
    uint16 global_location; /* location where XNB value is to be stored on linking */
} LABELSYMBOL;

typedef struct /* some fields in common with LABEL so must remain in synch */
{
    int address_defined;
    uint32 address;
    int num_forward_refs;
    uint32 forward_ref_locations[MAX_FORWARD_LOCATIONS];
    uint16 segment_number;
    uint32 global_location; /* location where XNB value is to be stored on linking */
    VARSYMBOL parameters[MAX_PROC_PARAMS];
    uint16 param_count;
    int nature;
} PROCSYMBOL;

typedef struct
{
    VARSYMBOL fields[MAX_TYPE_FIELDS];
    int field_count;
} TYPESYMBOL;

typedef struct
{
    SYMBOLTYPE symbol_type;
    char name[MAX_NAME_LEN];
    int block_level;
    int module_number; /* the number of the import module in the module table, if the symbol is imported, -1 if not imported. */
    void *elf_symbol;
    union
    {
        VARSYMBOL var;
        LITSYMBOL lit;
        LABELSYMBOL label;
        PROCSYMBOL proc;
        TYPESYMBOL type;
    } data;
} MUTLSYMBOL;

typedef struct
{
    uint16 last_mutl_var; /* The number of the last MUTL variable for the previous block in the hierarchy */
    uint16 local_names_space; /* The number of 32-bit words required for local names in the current block, including LINK (if any) and parameters */
    uint32 stack_offset_address; /* the location to update the SF offset when the size of the block's variables is known */
    int has_stack_frame;
    MUTLSYMBOL *proc_def_var;
} BLOCK;

typedef struct
{
    uint32 address_of_condition;
    uint32 address_of_end_of_loop_jump;
    int mode;
    uint16 control_variable;
} LOOP;

typedef struct
{
    uint16 segment_index;
} AREA;

typedef struct
{
    int in_use;
    unsigned short int elf_section_index;
    uint16 segment_address;
    uint16 words[MAX_SEGMENT_SIZE];
    uint32 first_word; /* first word in the segment where the current module starts during import/link of modules */
    uint32 next_word;
    uint16 kind;
    uint32 size;
    uint32 run_time_address;
} SEGMENT;

/* type to record global references for relocation */
typedef struct
{
    uint16 referenced_segment_number; /* the segment number for which the base address is to be filled in by the linker */
    uint32 referencing_address; /* the address where the address of the referenced segment must be placed */
} GLOBALREF;

typedef struct
{
    uint16 proc_n;
    int proc_call_stack_link_offset_address;
} NESTEDPROCCALL;

static int logging;
static char out_file_name[_MAX_PATH + 1];
static int is_library;
static uint32 start_address;
static int current_line;
static uint16 amode = 0;
static MUTLSYMBOL mutl_var[MAX_NAMES + 1];
static MUTLSYMBOL mutl_import_var[MAX_IMPORTS];
static uint8 current_literal_buf[MAX_LITERAL_LEN];
static VECTOR current_literal;
static uint16 current_literal_basic_type; /* gives length */
static PROCSYMBOL *current_proc_spec;
static MUTLSYMBOL *current_proc_def;
static MUTLSYMBOL *current_type_def;
static int current_assign_variable;
static uint16 current_assign_variable_area;
static int current_nested_call_depth = 0;
static NESTEDPROCCALL nested_call[MAX_NESTED_CALLS];
static BLOCK block_stack[MAX_BLOCK_DEPTH];
static BLOCK import_block;
static int block_level = -1;
static uint32 module_global_address_location;
static LOOP loop_stack[MAX_LOOP_DEPTH];
static int loop_level = -1;
static AREA areas[MAX_AREAS];
static uint8 current_code_area = 1;
static uint8 current_data_area = 0;
static SEGMENT segments[MAX_SEGMENTS];
static int imported_module_count;
static int relocation_count;
static uint32 stack_front_load_byte_address;
static void *elf_module_context;
static void *elf_literal_placeholder_symbol;

uint8 k_v(void);
void op_org_abs_jump_generic_symbol(void *sym, uint8 F);
void op_org_stack_link(uint16);
void op_org_enter(uint16);

void set_logging(int l)
{
    logging = l;
}

void log(int source, char *format, ...)
{
    va_list va;

    va_start(va, format);

    if (logging & source)
    {
        vprintf(format, va);
    }

    va_end(va);
}

void fatal(char *format, ...)
{
    va_list va;

    va_start(va, format);

    vprintf(format, va);

    va_end(va);

    exit(1);
}

static void vecstrcpy(char *dst, VECTOR *src, int dst_size)
{
    int len = src->length;
    if (len > dst_size - 1)
    {
        len = dst_size - 1;
    }

    strncpy(dst, src->buffer, len);
    dst[len] = '\0';
}

static void vecmemcpy(VECTOR *dst, VECTOR *src, uint16 dst_size)
{
    uint16 len = src->length;
    if (len > dst_size)
    {
        len = dst_size;
    }

    memcpy(dst->buffer, src->buffer, len);
    dst->length = len;
}

static int type_is_vector(uint16 T)
{
    int result = BT_PTR_TO(T) == BT_BOUNDED_PTR_TO_VECTOR;
    return result;
}

static char *format_operand(uint16 n)
{
    static char buf[80];
    int pos;
    int len;
    int i;
    if (n == OPERAND_LITERAL)
    {
        pos = sprintf(buf, "const 0x");
        len = BT_SIZE(current_literal_basic_type);
        for (i = 0; i < current_literal.length; i++)
        {
            sprintf(&buf[pos + 2*i], "%02X", current_literal.buffer[i]);
        }
    }
    else if (n == OPERAND_REG_A)
    {
        strcpy(buf, "reg A");
    }
    else if (n == OPERAND_POP)
    {
        strcpy(buf, "pop stack");
    }
    else if (n == OPERAND_D_REF)
    {
        strcpy(buf, "D[]");
    }
    else if (n < 0x1000)
    {
        sprintf(buf, "var %d", n);
    }
    else
    {
        fatal("Unsupported operand type 0x%X\n", n);
    }

    return buf;
}

static void write_16_bit_word_to_buffer(uint8 *buffer, uint16* buffer_size, uint16 value)
{
    buffer[(*buffer_size)++] = (value >> 8) & 0xFF;
    buffer[(*buffer_size)++] = value & 0xFF;
}

static void write_32_bit_word_to_buffer(uint8 *buffer, uint16* buffer_size, uint32 value)
{
    write_16_bit_word_to_buffer(buffer, buffer_size, value >> 16);
    write_16_bit_word_to_buffer(buffer, buffer_size, value & 0xFFFF);
}

static void write_string_to_buffer(uint8 *buffer, uint16* buffer_size, char *value)
{
    uint8 len = strlen(value) & 0xFF;
    buffer[(*buffer_size)++] = len;
    memcpy(&buffer[*buffer_size], value, len);
    (*buffer_size) += len;
}

static void write_vector_to_buffer(uint8 *buffer, uint16* buffer_size, VECTOR *value)
{
    uint8 len = value->length & 0xFF;
    buffer[(*buffer_size)++] = len;
    memcpy(&buffer[*buffer_size], value->buffer, len);
    (*buffer_size) += len;
}

uint16 get_segment_number_from_full_address(uint32 address)
{
    uint16 result = address >> 16;
    return result;
}

SEGMENT *get_segment_for_area(uint16 area_number)
{
    AREA *area;
    SEGMENT *segment;
    area = &areas[area_number];
    if (area->segment_index >= MAX_SEGMENTS)
    {
        fatal("Invalid segment index %d for area %d\n", area->segment_index, area_number);
    }

    segment = &segments[area->segment_index];
    return segment;
}

SEGMENT *get_segment_by_segment_number(uint16 segment_number)
{
    SEGMENT *segment = NULL;
    int i;

    for (i = 0; i < MAX_SEGMENTS; i++)
    {
        segment = &segments[i];
        if (segment->in_use && segment->segment_address == segment_number)
        {
            break;
        }
    }

    return segment;
}

SEGMENT *get_segment_by_full_address(uint32 address)
{
    SEGMENT *segment = get_segment_by_segment_number(get_segment_number_from_full_address(address));
    return segment;
}

static uint16 encode_16_bit_word(uint16 word)
{
    return ((word >> 8) & 0xFF) | ((word & 0xFF) << 8);
}

static void plant_16_bit_word(uint16 area_number, uint16 word)
{
    SEGMENT *segment = get_segment_for_area(area_number);
    if (segment->next_word > segment->size)
    {
        fatal("Segment %d is full\n", segment->segment_address);
    }

    uint16 encoded_word = encode_16_bit_word(word);
    elf_add_binary_data_to_section(elf_module_context, segment->elf_section_index, (char *)&encoded_word, 2);
    segment->next_word++;
}

static void plant_32_bit_word(uint16 area_number, uint32 word)
{
    plant_16_bit_word(area_number, (word >> 16) & 0xFFFF);
    plant_16_bit_word(area_number, word & 0xFFFF);
}

static void plant_16_bit_word_update(uint16 area_number, uint16 address, uint16 word)
{
    SEGMENT *segment = get_segment_for_area(area_number);
    segment->words[address] = encode_16_bit_word(word);
}

static void plant_16_bit_word_update_by_address(uint32 address, uint16 word)
{
    SEGMENT *segment = get_segment_by_full_address(address);
    uint16 offset = address & 0xFFFF;
    segment->words[offset] = encode_16_bit_word(word);
}

static void plant_32_bit_word_update_by_address(uint32 address, uint32 word)
{
    SEGMENT *segment = get_segment_by_full_address(address);
    uint16 offset = address & 0xFFFF;
    segment->words[offset] = encode_16_bit_word(word >> 16);
    segment->words[offset + 1] = encode_16_bit_word(word & 0xFFFF);
}

static void plant_16_bit_code_word(uint16 word)
{
    plant_16_bit_word(current_code_area, word);
}

static void plant_32_bit_code_word(uint32 word)
{
    plant_16_bit_code_word((word >> 16) & 0xFFFF);
    plant_16_bit_code_word(word & 0xFFFF);
}

static void plant_64_bit_code_word(t_uint64 word)
{
    plant_16_bit_code_word((word >> 48) & 0xFFFF);
    plant_16_bit_code_word((word >> 32) & 0xFFFF);
    plant_16_bit_code_word((word >> 16) & 0xFFFF);
    plant_16_bit_code_word(word & 0xFFFF);
}

static void plant_16_bit_code_word_update(unsigned int address, unsigned int word, char *reason)
{
    plant_16_bit_word_update(current_code_area, address, word);
    log(LOG_PLANT, "Fixing code address %08X to contain %04X for %s\n", address, word, reason);
}

static void plant_16_bit_data_word(uint16 word)
{
    plant_16_bit_word(current_data_area, word);
}

static void plant_vector(uint16 data_type, VECTOR *v)
{
    uint8 buffer[MAX_LITERAL_LEN];
    int i;
    uint16 words;
    uint16 data_type_len = BT_SIZE(data_type);
    uint16 len = v->length;
    uint8 fill = 0;

    if (BT_MODE(data_type) == BT_MODE_SIGNED_INTEGER && ((current_literal.buffer[0] & 0x80) == 0x80))
    {
        fill = 0xFF;
    }

    if (data_type_len > v->length)
    {
        len = data_type_len;
    }
    words = (len + 1) / 2;
    memset(buffer, fill, sizeof(buffer));
    if (BT_SIZE(data_type) > 1)
    {
        memcpy(&buffer[(words * 2) - v->length], v->buffer, v->length);
    }
    else
    {
        memcpy(buffer, v->buffer, v->length);
    }

    for (i = 0; i < words; i++)
    {
        uint16 word = (buffer[i * 2] << 8) | buffer[i * 2 + 1];
        plant_16_bit_data_word(word);
    }
    block_stack[0].local_names_space += (words +1)/2; /* names space is in 32-bit word increments */ /* TODO: is there a problem here with vectors of 16-bit integers? */
}

static uint16 next_instruction_segment_number(void)
{
    uint16 result;
    SEGMENT *segment = get_segment_for_area(current_code_area);
    result = segment->segment_address;
    return result;
}

static uint16 next_code_segment_number(void)
{
    uint16 result;
    SEGMENT *segment = get_segment_for_area(current_data_area);
    result = segment->segment_address;
    return result;
}

static uint32 next_instruction_full_byte_address(void)
{
    uint32 result;
    SEGMENT *segment = get_segment_for_area(current_code_area);
    result = segment->segment_address << 16 | (segment->next_word * 2);
    return result;
}

static int next_instruction_segment_address(void)
{
    SEGMENT *segment = get_segment_for_area(current_code_area);
    return segment->next_word;
}

static int next_instruction_segment_byte_address(void)
{
    return next_instruction_segment_address() * 2;
}

static uint32 global_data_start_address(void)
{
    uint32 result;
    SEGMENT *segment = get_segment_for_area(current_data_area);
    result = segment->segment_address << 16 | (segment->first_word & 0xFFFF);
    return result;
}

static int next_data_address(void)
{
    SEGMENT *segment = get_segment_for_area(current_data_area);
    return segment->next_word;
}

static uint32 compute_descriptor_origin(uint16 data_area_word_address)
{
    uint32 result;
    SEGMENT *segment = get_segment_for_area(current_data_area);
    result = segment->segment_address << 16 | ((data_area_word_address << 1) & 0xFFFF);
    return result;
}

static t_uint64 get_current_literal(void)
{
    int len;
    len = current_literal.length;
    t_uint64 literal = 0;
    int i;
    for (i = 0; i < len; i++)
    {
        literal = literal << 8 | current_literal.buffer[i];
    }

    return literal;
}

static t_uint64 build_type_0_descriptor(uint8 size_bytes, uint16 length, uint32 address)
{
    t_uint64 descriptor;
    t_uint64 type;
    if (size_bytes == 1)
    {
        type = DESCRIPTOR_8_BIT;
    }
    else if (size_bytes == 2)
    {
        type = DESCRIPTOR_16_BIT;
    }
    else if (size_bytes == 4)
    {
        type = DESCRIPTOR_32_BIT;
    }
    else
    {
        type = DESCRIPTOR_64_BIT;
    }

    descriptor = (type & 0x7) << 59;
    descriptor |= (t_uint64)(length & 0xFFFFFF) << 32;
    descriptor |= address;
    return descriptor;
}
static uint8 get_operand(uint16 n)
{
    uint8 kp = 0;
    uint8 np = 0;
    uint8 modifier = 0;

    if (n == OPERAND_LITERAL)
    {
        kp = KP_LITERAL;
        switch (BT_MODE(current_literal_basic_type))
        {
            case BT_MODE_UNSIGNED_INTEGER:
            {
                int len = BT_SIZE(current_literal_basic_type);
                if (len <= 2)
                {
                    np = NP_16_BIT_UNSIGNED_LITERAL;
                }
                else if (len <= 4)
                {
                    np = NP_32_BIT_UNSIGNED_LITERAL;
                }
                else
                {
                    np = NP_64_BIT_LITERAL;
                }
                break;
            }
            case BT_MODE_SIGNED_INTEGER:
            {
                int len = BT_SIZE(current_literal_basic_type);
                if (len <= 2)
                {
                    np = NP_16_BIT_SIGNED_LITERAL;
                }
                else if (len <= 4)
                {
                    np = NP_32_BIT_SIGNED_LITERAL;
                }
                else
                {
                    np = NP_64_BIT_LITERAL;
                }
                break;
            }
            default:
            {
                fatal("Cannot yet generate literal of %s\n", format_basic_type(current_literal_basic_type));
                break;
            }
        }
    }
    else if (n == OPERAND_POP)
    {
        kp = k_v();
        np = NP_STACK;
        modifier = NO_OPERAND_FOLLOWS_FLAG;
    }
    else if (n == OPERAND_D_REF)
    {
        kp = K_SB;
        np = NP_DR;
        modifier = NO_OPERAND_FOLLOWS_FLAG;
    }
    else if (IS_MUTL_VAR(n))
    {
        MUTLSYMBOL *var = &mutl_var[n];
        if (var->symbol_type == SYM_VARIABLE)
        {
            if (!var->data.var.is_vstore)
            {
                if (var->data.var.is_parameter || var->data.var.dimension > 0 || BT_IS_BOUNDED(var->data.var.data_type))
                {
                    kp = K_V64;
                }
                else
                {
                    kp = k_v();
                }
                if (var->block_level <= 0)
                {
                    np = NP_XNB;
                }
                else if (var->block_level == block_level)
                {
                    np = NP_NB;
                }
                else
                {
                    fatal("Non-local non-global variable access not supported yet.");
                }
            }
            else
            {
                kp = K_PRIVILEGED;
                np = NP_0;
            }
        }
        else if (var->symbol_type == SYM_LITERAL)
        {
            kp = KP_LITERAL;
            np = NP_64_BIT_LITERAL; /* will plant descriptor in the literal */
        }
        else
        {
            fatal("Can't get operand for this symbol type\n");
        }
    }
    else
    {
        fatal("Unsupported operand type 0x%X\n", n);
    }

    return modifier | kp << 3 | (np & 0x7);
}

static void plant_operand(uint16 n)
{
    if (n == OPERAND_LITERAL)
    {
        switch (BT_MODE(current_literal_basic_type))
        {
            case BT_MODE_UNSIGNED_INTEGER:
            case BT_MODE_SIGNED_INTEGER:
            {
                int len = BT_SIZE(current_literal_basic_type);
                t_uint64 literal = get_current_literal();

                if (len <= 2)
                {
                    plant_16_bit_code_word(literal & 0xFFFF);
                }
                else if (len <= 4)
                {
                    plant_32_bit_code_word(literal & 0xFFFFFFFF);
                }
                else
                {
                    plant_64_bit_code_word(literal);
                }
                break;
            }
            default:
            {
                fatal("Cannot yet generate literal of %s\n", format_basic_type(current_literal_basic_type));
                break;
            }
        }
    }
    else if (n >= 2 && n < 0x1000)
    {
        MUTLSYMBOL *mutlsym = &mutl_var[n];
        if (mutlsym->symbol_type == SYM_VARIABLE)
        {
            if (mutlsym->data.var.position == (uint16)-1)
            {
                SEGMENT *code_seg = get_segment_for_area(current_code_area);
                if (mutlsym->data.var.is_vstore)
                {
                    elf_add_relocation_entry(elf_module_context, code_seg->elf_section_index, next_instruction_segment_byte_address(), mutlsym->elf_symbol, MU5_REL_TYPE_16_BIT_VALUE, 0);
                }
                else
                {
                    elf_add_relocation_entry(elf_module_context, code_seg->elf_section_index, next_instruction_segment_byte_address(), mutlsym->elf_symbol, MU5_REL_TYPE_VAR_OFFSET, 0);
                }
            }
            plant_16_bit_code_word(mutlsym->data.var.position);
        }
        else if (mutl_var[n].symbol_type == SYM_LITERAL)
        {
            void *elf_sym;
            SEGMENT *data_seg = get_segment_for_area(current_data_area);
            SEGMENT *code_seg = get_segment_for_area(current_code_area);
            LITSYMBOL *lit = &mutl_var[n].data.lit;
            t_uint64 descriptor;

            if (elf_literal_placeholder_symbol == NULL && mutlsym->elf_symbol == NULL)
            {
                elf_literal_placeholder_symbol = elf_add_symbol(elf_module_context, MU5_LIT_SYM_NAME, 0, 0, STB_LOCAL, STT_NOTYPE, data_seg->elf_section_index);
            }

            elf_sym = (mutlsym->elf_symbol != NULL) ? mutlsym->elf_symbol : elf_literal_placeholder_symbol;

            if (BT_IS_IMPORT(lit->data_type))
            {
                plant_64_bit_code_word(0);
                elf_add_relocation_entry(elf_module_context, code_seg->elf_section_index, (code_seg->next_word - 2) * 2, elf_sym, MU5_REL_TYPE_32_BIT_VALUE, 0);
            }
            else
            {
                descriptor = build_type_0_descriptor(BT_SIZE(lit->data_type), lit->dimension, lit->address);
                plant_64_bit_code_word(descriptor);

                elf_add_relocation_entry(elf_module_context, code_seg->elf_section_index, (code_seg->next_word - 2) * 2, elf_sym, MU5_REL_TYPE_DESC_LIT, lit->address & 0xFFFF);
            }
        }
        else
        {
            fatal("Can't plant operand for this symbol type\n");
        }
    }
    else
    {
        fatal("Unsupported operand type 0x%X\n", n);
    }
}

static void plant_order_extended(uint8 cr, uint8 f, uint8 kp, uint8 np)
{
    uint16 plant_order;

    plant_order = (cr & 0x7) << 13;
    plant_order |= (f & 0xF) << 9;
    plant_order |= 0x7 << 6;
    plant_order |= (kp & 0x7) << 3;
    plant_order |= np & 0x7;
    plant_16_bit_code_word(plant_order);
}

static void plant_order_extended_operand(uint8 cr, uint8 f, uint16 n)
{
    uint16 order;
    uint8 operand = get_operand(n);

    order = (cr & 0x7) << 13;
    order |= (f & 0xF) << 9;
    order |= 0x7 << 6;
    order |= operand & 0x3F;
    plant_16_bit_code_word(order);
    if (OPERAND_FOLLOWS(operand))
    {
        plant_operand(n);
    }
}

static void plant_order(uint8 cr, uint8 f, uint8 k, uint8 n)
{
    uint16 order;

    order = (cr & 0x7) << 13;
    order |= (f & 0xF) << 9;
    order |= (k & 0x7) << 6;
    order |= n & 0x3F;
    plant_16_bit_code_word(order);
}

static void plant_org_order_extended(uint8 f, uint8 kp, uint8 np)
{
    uint16 plant_order;

    plant_order = (f & 0x3F) << 7;
    plant_order |= 0x1 << 6;
    plant_order |= (kp & 0x7) << 3;
    plant_order |= np & 0x7;
    plant_16_bit_code_word(plant_order);
}

static void plant_org_order(uint8 f, uint8 k, uint8 n)
{
    uint16 order;

    order = (f & 0x3F) << 7;
    order |= (k & 0x1) << 6;
    order |= n & 0x3F;
    plant_16_bit_code_word(order);
}

uint8 cr(void)
{
    uint8 result = 0;
    if (type_is_vector(amode))
    {
        result = CR_STS2;
    }
    else
    {
        switch (BT_MODE(amode))
        {
            case BT_MODE_SIGNED_INTEGER:
            {
                if (BT_SIZE(amode) <= 4)
                {
                    result = CR_XS;
                }
                else
                {
                    result = CR_AU;
                }

                break;
            }
            case BT_MODE_UNSIGNED_INTEGER:
            {
                result = CR_AU;
                break;
            }
            default:
            {
                fatal("Cannot handle Real and Decimal\n");
            }
        }
    }
    return result;
}

uint8 cr_for_load(void)
{
    uint8 result = 0;
    if (type_is_vector(amode))
    {
        result = CR_STS2;
    }
    else
    {
        switch (BT_MODE(amode))
        {
            case BT_MODE_SIGNED_INTEGER:
            {
                if (BT_SIZE(amode) <= 4)
                {
                    result = CR_XS;
                }
                else
                {
                    result = CR_FLOAT;
                }
                break;
            }
            case BT_MODE_UNSIGNED_INTEGER:
            {
                result = CR_FLOAT;
                break;
            }
            default:
            {
                fatal("Cannot handle Real and Decimal\n");
            }
        }
    }
    return result;
}

uint8 k_v()
{
    uint8 result = 0;
    uint8 size = BT_SIZE(amode);
    if (type_is_vector(amode))
    {
        result = K_V64;
    }
    else if (size <= 4)
    {
        result = K_V32;
    }
    else
    {
        result = K_V64;
    }
    return result;
}

static void plant_stack_a(void)
{
    log(LOG_PLANT, "%04X Stack A\n", next_instruction_segment_address());
    plant_org_order(F_SF_PLUS, K_LITERAL, 2);
    plant_order_extended(cr_for_load(), F_STORE, K_V64, NP_SF);
    plant_16_bit_code_word(0);
}

static void plant_pop_a(void)
{
    log(LOG_PLANT, "%04X Pop A\n", next_instruction_segment_address());
    if (BT_SIZE(amode) <= 4)
    {
        plant_order_extended(cr_for_load(), F_LOAD_32, K_V32, NP_STACK);
    }
    else
    {
        plant_order_extended(cr_for_load(), F_LOAD_64, K_V32, NP_STACK);
    }
}

static void plant_stack_x(void)
{
    plant_org_order(F_SF_PLUS, K_LITERAL, 2);
    plant_order_extended(CR_XS, F_STORE, K_V64, NP_SF);
    plant_16_bit_code_word(0);
}

static void plant_stack_d(void)
{
    log(LOG_PLANT, "%04X Stack D\n", next_instruction_segment_address());
    plant_org_order(F_SF_PLUS, K_LITERAL, 2);
    plant_order_extended(CR_STS2, F_STORE, K_V64, NP_SF);
    plant_16_bit_code_word(0);
}

static void plant_pop_x(void)
{
    plant_order_extended(CR_XS, F_LOAD_32, K_V32, NP_STACK);
}

static void plant_pop(void)
{
    plant_org_order(F_SF_PLUS, K_LITERAL, (uint8)-2);
}

BLOCK *get_current_block(void)
{
    BLOCK *result;
    if (block_level < 0)
    {
        result = &import_block;
    }
    else
    {
        result = &block_stack[block_level];
    }

    return result;
}

void start_block_level(uint16 param_stack_size, int has_stack_frame)
{
    BLOCK *block;
    int16 nb_adjust;

    block_level++;
    if (block_level >= MAX_BLOCK_DEPTH)
    {
        fatal("Max block nesting level exceeded\n");
    }

    block = get_current_block();
    if (block_level <= 0)
    {
        block->last_mutl_var = FIRST_NAME - 1;
        block->local_names_space = 0;
        nb_adjust = 0;
    }
    else
    {
        BLOCK *prev_block = &block_stack[block_level - 1];

        block->last_mutl_var = prev_block->last_mutl_var;
        block->local_names_space = 2; /* for the LINK */
        block->proc_def_var = current_proc_def;
        block->has_stack_frame = has_stack_frame;
        nb_adjust = -param_stack_size; /* NB must be positioned at the LINK */
    }

    if (block_level > 0)
    {
        plant_org_order_extended(F_NB_LOAD_SF_PLUS, KP_LITERAL, NP_16_BIT_SIGNED_LITERAL);
        plant_16_bit_code_word(nb_adjust);
        if (has_stack_frame)
        {
            log(LOG_PLANT, "%04X Plant NB=SF+%d\n", next_instruction_segment_address(), nb_adjust);
            plant_org_order_extended(F_SF_LOAD_NB_PLUS, KP_LITERAL, NP_16_BIT_SIGNED_LITERAL);
            block->stack_offset_address = next_instruction_segment_address();
            plant_16_bit_code_word(0); /* plant a placeholder to be filled with the size of the local variables */
        }
    }


    log(LOG_STRUCTURE, "Start block, level=%d, last mutl name=%d\n", block_level, block->last_mutl_var);
}

int block_var_is_not_aligned(uint16 T)
{
    BLOCK *block = get_current_block();
    int result = 0;
    if (BT_SIZE(T) > 4 && (block->local_names_space % 2 != 0))
    { 
        result = 1;
    }

    return result;
}

uint16 add_block_var(uint16 T, int is_parameter)
{
    BLOCK *block = get_current_block();
    if (is_parameter || BT_SIZE(T) > 4)
    {
        if (block_var_is_not_aligned(T))
        {
            block->local_names_space++;
        }
    }

    block->last_mutl_var++;
    return block->last_mutl_var;
}

uint16 add_other_block_item(void)
{
    BLOCK *block = get_current_block();
    block->last_mutl_var++;
    return block->last_mutl_var;
}

uint16 get_block_name_offset_for_last_var(uint16 T, int is_parameter)
{
    BLOCK *block = get_current_block();
    uint16 result;
    if (is_parameter || BT_SIZE(T) > 4 || type_is_vector(T))
    {
        result = block->local_names_space / 2;
    }
    else
    {
        result = block->local_names_space;
    }
    return result;
}

void end_block_level(void)
{
    if (block_level >= 0)
    {
        BLOCK *block = get_current_block();

        if (block_level > 0 && block->has_stack_frame)
        {
            plant_16_bit_code_word_update(block->stack_offset_address, block->local_names_space, "SF adjustment to make room for local variables");
        }

        current_proc_def = block->proc_def_var;
    }
    else
    {
        fatal("Too many block ends, stack underflow\n");
    }

    log(LOG_STRUCTURE, "End block, level=%d\n", block_level);
    block_level--;
}

uint16 param_stack_size(uint16 N)
{
    uint16 result;
    result = mutl_var[N].data.proc.param_count * 2;
    return result;
}

int param_instruction_size(uint16 N)
{
    int result;
    result = mutl_var[N].data.proc.param_count * 2;
    return result;
}

void register_forward_label_ref(uint16 N)
{
    MUTLSYMBOL *sym = &mutl_var[N];
    LABELSYMBOL *label = &sym->data.label;
    if (sym->symbol_type == SYM_PROC)
    {
        SEGMENT *segment = get_segment_for_area(current_code_area);
        elf_add_relocation_entry(elf_module_context, segment->elf_section_index, next_instruction_segment_byte_address(), sym->elf_symbol, MU5_REL_TYPE_FUNC, 0);
    }
    else if (label->num_forward_refs >= MAX_FORWARD_LOCATIONS)
    {
        fatal("Forward ref list for %s is full\n", mutl_var[N].name);
    }
    else
    {
        label->forward_ref_locations[label->num_forward_refs++] = next_instruction_segment_address();
        //printf("Forward ref for %s at 0x%08X\n", mutl_var[N].name, next_instruction_address());
    }
}

void fixup_forward_label_refs(uint16 N)
{
    LABELSYMBOL *label = &mutl_var[N].data.label;
    int i;
    for (i = 0; i < label->num_forward_refs; i++)
    {
        plant_16_bit_code_word_update(label->forward_ref_locations[i], label->address - label->forward_ref_locations[i] + 1, "forward label reference");
    }
}

void check_v_store_read_proc(uint16 N)
{
    if (N >= 2 && N < 0x1000)
    {
        MUTLSYMBOL *mutl_sym = &mutl_var[N];
        if (mutl_sym->symbol_type == SYM_VARIABLE)
        {
            VARSYMBOL *var = &mutl_sym->data.var;
            if (var->v_read_proc != 0)
            {
                log(LOG_PLANT, "%04X V STORE read proc call required\n", next_instruction_segment_address());
                op_org_stack_link(var->v_read_proc);
                op_org_enter(0);
            }
            else if (var->v_read_proc_sym != 0)
            {
                int proc_call_stack_link_offset_address;
                log(LOG_PLANT, "%04X V STORE external read proc call required\n", next_instruction_segment_address());
                log(LOG_PLANT, "%04X ORG STACK LINK to read proc\n", next_instruction_segment_address());
                plant_org_order_extended(F_STACKLINK, KP_LITERAL, NP_16_BIT_UNSIGNED_LITERAL);

                proc_call_stack_link_offset_address = next_instruction_segment_address();
                plant_16_bit_code_word(0); /* placeholder fixed up when we plant the ENTER */
                log(LOG_PLANT, "%04X ORG JUMP ABS JUMP with relocation\n", next_instruction_segment_address());
                op_org_abs_jump_generic_symbol(var->v_read_proc_sym, F_ABSJUMP);
                plant_16_bit_code_word_update(proc_call_stack_link_offset_address, next_instruction_segment_address() - proc_call_stack_link_offset_address + 1, "return address");
            }
        }
    }
}

void check_v_store_write_proc(uint16 N)
{
    if (N >= 2 && N < 0x1000)
    {
        MUTLSYMBOL *mutl_sym = &mutl_var[N];
        if (mutl_sym->symbol_type == SYM_VARIABLE)
        {
            VARSYMBOL *var = &mutl_sym->data.var;
            if (var->v_write_proc != 0)
            {
                log(LOG_PLANT, "%04X V STORE write proc call required\n", next_instruction_segment_address());
                op_org_stack_link(var->v_write_proc);
                op_org_enter(0);
            }
            else if (var->v_write_proc_sym != 0)
            {
                int proc_call_stack_link_offset_address;
                log(LOG_PLANT, "%04X V STORE external write proc call required\n", next_instruction_segment_address());
                log(LOG_PLANT, "%04X ORG STACK LINK to write proc\n", next_instruction_segment_address());
                plant_org_order_extended(F_STACKLINK, KP_LITERAL, NP_16_BIT_UNSIGNED_LITERAL);

                proc_call_stack_link_offset_address = next_instruction_segment_address();
                plant_16_bit_code_word(0); /* placeholder fixed up when we plant the ENTER */
                log(LOG_PLANT, "%04X ORG JUMP ABS JUMP with relocation\n", next_instruction_segment_address());
                op_org_abs_jump_generic_symbol(var->v_write_proc_sym, F_ABSJUMP);
                plant_16_bit_code_word_update(proc_call_stack_link_offset_address, next_instruction_segment_address() - proc_call_stack_link_offset_address + 1, "return address");
            }
        }
    }
}

int is_global_ref(uint16 N)
{
    int result = 0;
    MUTLSYMBOL *mutl_sym;
    if (IS_MUTL_VAR(N))
    {
        mutl_sym = &mutl_var[N];
        result = mutl_sym->block_level == 0 && (mutl_sym->symbol_type == SYM_VARIABLE) && !mutl_sym->data.var.is_vstore;
    }
    return result;
}

void check_global_ref(uint16 N)
{
    if (is_global_ref(N))
    {
        MUTLSYMBOL *mutl_sym = &mutl_var[N];
        plant_org_order_extended(F_XNB_LOAD, KP_LITERAL, NP_32_BIT_UNSIGNED_LITERAL);

        SEGMENT *segment = get_segment_for_area(current_code_area);
        elf_add_relocation_entry(elf_module_context, segment->elf_section_index, next_instruction_segment_byte_address(), mutl_sym->elf_symbol, MU5_REL_TYPE_VAR_BASE, 0);
        plant_32_bit_code_word(0);
    }
}

void op_b_load(uint16 N)
{
    log(LOG_PLANT, "%04X B load %s\n", next_instruction_segment_address(), format_operand(N));
    plant_order_extended_operand(CR_B, F_LOAD_B, N);
}

void op_d_load(uint16 N)
{
    log(LOG_PLANT, "%04X D load %s\n", next_instruction_segment_address(), format_operand(N));
    plant_order_extended_operand(CR_STS2, F_LOAD_D, N); /* can generate a 64-bit signed load on MU5 which is not valid */
}

void op_d_load_ref(uint16 N)
{
    log(LOG_PLANT, "%04X D load REF %s\n", next_instruction_segment_address(), format_operand(N));
    if (N <= 0 || N >= MAX_NAMES)
    {
        fatal("Cannot load descriptor ref to operand\n");
    }

    plant_order_extended_operand(CR_STS2, F_LOAD_D, N);
}

void op_d_select_element(uint16 N)
{
    log(LOG_PLANT, "%04X D select element (NO-OP) %s\n", next_instruction_segment_address(), format_operand(N));
}

void op_a_store(uint16 N)
{
    log(LOG_PLANT, "%04X A store to %s\n", next_instruction_segment_address(), mutl_var[N].name);
    plant_order_extended_operand(cr_for_load(), F_STORE, N);
    check_v_store_write_proc(N);
}

void op_a_load(uint16 N)
{
    log(LOG_PLANT, "%04X A load %s\n", next_instruction_segment_address(), format_operand(N));
    check_v_store_read_proc(N);
    if (BT_SIZE(amode) <= 4)
    {
        plant_order_extended_operand(cr_for_load(), F_LOAD_32, N);
    }
    else
    {
        plant_order_extended_operand(cr_for_load(), F_LOAD_64, N);
    }
}

void op_a_load_neg_or_ref(uint16 N)
{
    VARSYMBOL *var = &mutl_var[N].data.var;
    if (var->dimension == 0 && N != OPERAND_D_REF)
    {
        log(LOG_PLANT, "%04X A load negative %s\n", next_instruction_segment_address(), format_operand(N));
        check_v_store_read_proc(N);
        op_a_load(N);
        plant_order(cr(), F_RSUB_A, K_IR, 34); /* 34 is the Z internal register */
    }
    else
    {
        if (N == OPERAND_D_REF)
        {
            log(LOG_PLANT, "%04X A load REF %s (NO-OP)\n", next_instruction_segment_address(), format_operand(N));
        }
        else
        {
            log(LOG_PLANT, "%04X A load REF %s\n", next_instruction_segment_address(), format_operand(N));
            plant_order_extended_operand(cr(), F_LOAD_64, N);
        }
    }
}

void op_a_xor(uint16 N)
{
    log(LOG_PLANT, "%04X A XOR 0x%X\n", next_instruction_segment_address(), N);
    check_v_store_read_proc(N);
    plant_order_extended_operand(cr(), F_XOR_A, N);
}

void op_a_and(uint16 N)
{
    log(LOG_PLANT, "%04X A AND %s\n", next_instruction_segment_address(), format_operand(N));
    check_v_store_read_proc(N);
    plant_order_extended_operand(cr(), F_AND_A, N);
}

void op_a_or(uint16 N)
{
    log(LOG_PLANT, "%04X A OR %s\n", next_instruction_segment_address(), format_operand(N));
    check_v_store_read_proc(N);
    plant_order_extended_operand(cr(), F_OR_A, N);
}

void op_a_left_shift(uint16 N)
{
    log(LOG_PLANT, "%04X A LSH %s\n", next_instruction_segment_address(), format_operand(N));
    check_v_store_read_proc(N);
    plant_order_extended_operand(cr(), F_SHIFT_L_A, N);
}

void op_a_add(uint16 N)
{
    log(LOG_PLANT, "%04X A ADD %s\n", next_instruction_segment_address(), format_operand(N));
    check_v_store_read_proc(N);
    plant_order_extended_operand(cr(), F_ADD_A, N);
}

void op_a_sub(uint16 N)
{
    log(LOG_PLANT, "%04X A SUB %s\n", next_instruction_segment_address(), format_operand(N));
    check_v_store_read_proc(N);
    plant_order_extended_operand(cr(), F_SUB_A, N);
}

void op_a_reverse_sub(uint16 N)
{
    log(LOG_PLANT, "%04X A RSUB %s\n", next_instruction_segment_address(), format_operand(N));
    check_v_store_read_proc(N);
    plant_order_extended_operand(cr(), F_RSUB_A, N);
}

void op_a_mul(uint16 N)
{
    log(LOG_PLANT, "%04X A MUL %s\n", next_instruction_segment_address(), format_operand(N));
    check_v_store_read_proc(N);
    plant_order_extended_operand(cr(), F_MUL_A, N);
}

void op_a_div(uint16 N)
{
    log(LOG_PLANT, "%04X A DIV %s\n", next_instruction_segment_address(), format_operand(N));
    check_v_store_read_proc(N);
    plant_order_extended_operand(cr(), F_DIV_A, N);
}

void op_a_compare(uint16 N)
{
    log(LOG_PLANT, "%04X A COMP %s\n", next_instruction_segment_address(), format_operand(N));
    check_v_store_read_proc(N);
    plant_order_extended_operand(cr(), F_COMP_A, N);
}

void op_a_add_store(uint16 N)
{
    log(LOG_PLANT, "%04X A ADD STORE %s\n", next_instruction_segment_address(), format_operand(N));
    op_a_add(N);
    op_a_store(N);
}

void op_a_sub_store(uint16 N)
{
    log(LOG_PLANT, "%04X A SUB STORE %s\n", next_instruction_segment_address(), format_operand(N));
    op_a_sub(N);
    op_a_store(N);
}

void op_a_reverse_sub_store(uint16 N)
{
    log(LOG_PLANT, "%04X A RSUB STORE %s\n", next_instruction_segment_address(), format_operand(N));
    op_a_reverse_sub(N);
    op_a_store(N);
}

void op_a_xor_store(uint16 N)
{
    log(LOG_PLANT, "%04X A XOR STORE %s\n", next_instruction_segment_address(), format_operand(N));
    op_a_xor(N);
    op_a_store(N);
}

void op_a_and_store(uint16 N)
{
    log(LOG_PLANT, "%04X A AND STORE %s\n", next_instruction_segment_address(), format_operand(N));
    op_a_and(N);
    op_a_store(N);
}

void op_a_or_store(uint16 N)
{
    log(LOG_PLANT, "%04X A OR STORE %s\n", next_instruction_segment_address(), format_operand(N));
    op_a_or(N);
    op_a_store(N);
}

uint32 op_org_jump_generic_rel_address(uint8 F, int16 relative)
{
    uint32 address_location;
    if (relative >= -32 && relative < 32)
    {
        plant_org_order(F, K_LITERAL, (uint8)relative & 0x3F);
        address_location = UNKNOWN_ADDRESS;
    }
    else
    {
        plant_org_order_extended(F, KP_LITERAL, NP_16_BIT_SIGNED_LITERAL);
        address_location = next_instruction_segment_address();
        plant_16_bit_code_word(relative);
    }

    return address_location;
}

uint32 op_org_jump_generic_abs_address(uint8 F, uint32 address)
{
    uint32 address_location;
    plant_org_order_extended(F, KP_LITERAL, NP_32_BIT_SIGNED_LITERAL);
    address_location = next_instruction_segment_address();
    plant_32_bit_code_word(address);

    return address_location;
}

/* this function relies on labels and procs having the same initial structure. */
void op_org_rel_jump_generic(uint16 N, uint8 F, char *type)
{
    if (mutl_var[N].data.label.address_defined)
    {
        int16 relative = (uint16)(mutl_var[N].data.label.address - next_instruction_segment_address());
        log(LOG_PLANT, "%04X ORG JUMP %s %s relative %d\n", next_instruction_segment_address(), type, mutl_var[N].name, relative);
        op_org_jump_generic_rel_address(F, relative);
    }
    else
    {
        log(LOG_PLANT, "%04X ORG JUMP %s to %s forward ref\n", next_instruction_segment_address(), type, mutl_var[N].name);
        plant_org_order_extended(F, KP_LITERAL, NP_16_BIT_SIGNED_LITERAL);
        register_forward_label_ref(N);
        plant_16_bit_code_word(0); /* place holder */
    }
}

void op_org_abs_jump_generic_symbol(void *sym, uint8 F)
{
    SEGMENT *segment = get_segment_for_area(current_code_area);
    plant_org_order_extended(F, KP_LITERAL, NP_32_BIT_SIGNED_LITERAL);
    elf_add_relocation_entry(elf_module_context, segment->elf_section_index, next_instruction_segment_byte_address(), sym, MU5_REL_TYPE_FUNC, 0);
    plant_32_bit_code_word(0); /* place holder */
}

/* this function relies on labels and procs having the same initial structure. */
void op_org_abs_jump_generic(uint16 N, uint8 F, char *type)
{
    MUTLSYMBOL *sym = &mutl_var[N];
    log(LOG_PLANT, "%04X ORG JUMP %s to %s with relocation\n", next_instruction_segment_address(), type, mutl_var[N].name);
    op_org_abs_jump_generic_symbol(sym->elf_symbol, F);
}

void op_org_stack_link(uint16 N)
{
    if (current_nested_call_depth >= MAX_NESTED_CALLS)
    {
        fatal("Calls nested too deeply");
    }

    nested_call[current_nested_call_depth].proc_n = N;
    log(LOG_PLANT, "%04X ORG STACK LINK to %s\n", next_instruction_segment_address(), mutl_var[N].name);
    plant_org_order_extended(F_STACKLINK, KP_LITERAL, NP_16_BIT_UNSIGNED_LITERAL);

    nested_call[current_nested_call_depth].proc_call_stack_link_offset_address = next_instruction_segment_address();
    plant_16_bit_code_word(0); /* placeholder fixed up when we plant the ENTER */
    current_nested_call_depth++;
}

void op_org_stack_parameter(uint16 N)
{
    if (N != OPERAND_REG_A)
    {
        fatal("Can't stack parameter 0x%04x\n", N);
    }

    log(LOG_PLANT, "%04X STACK parameter\n", next_instruction_segment_address());
    plant_stack_a();
}

void op_org_enter(uint16 N)
{
    int proc_call_stack_link_offset_address;

    if (N != 0)
    {
        fatal("Can't enter 0x%04x\n", N);
    }

    current_nested_call_depth--;
    op_org_abs_jump_generic(nested_call[current_nested_call_depth].proc_n, F_ABSJUMP, "ABS JUMP");
    /* update the offset for the STACKLINK */

    proc_call_stack_link_offset_address = nested_call[current_nested_call_depth].proc_call_stack_link_offset_address;
    plant_16_bit_code_word_update(proc_call_stack_link_offset_address, next_instruction_segment_address() - proc_call_stack_link_offset_address + 1, "return address");
}

void op_org_return(uint16 N)
{
    log(LOG_STRUCTURE, "RETURN operand %s\n", format_operand(N));
    plant_org_order_extended(F_RETURN, k_v(), NP_STACK);
}

void op_org_aconv(uint16 N)
{
    int kind = (N >> 14) & 1;
    uint16 from_amode = amode;
    uint16 to_amode = N;
    log(LOG_PLANT, "Aconv kind=%d from %s", kind, format_basic_type(from_amode));
    log(LOG_PLANT, " to %s\n", format_basic_type(to_amode));
    if (type_is_vector(from_amode) && (BT_MODE(to_amode) == BT_MODE_SIGNED_INTEGER || BT_MODE(to_amode) == BT_MODE_UNSIGNED_INTEGER))
    {
        amode = to_amode;
        log(LOG_PLANT, "Aconv get vector bound\n");
        log(LOG_PLANT, "  ");
        plant_stack_d();
        log(LOG_PLANT, "  %04X Load top 32 bits\n", next_instruction_segment_address());
        plant_order_extended(cr(), F_LOAD_32, K_V32, NP_SF);
        plant_16_bit_code_word(0);
        log(LOG_PLANT, "  %04X Mask the bound\n", next_instruction_segment_address());
        plant_order_extended(cr(), F_AND, KP_LITERAL, NP_32_BIT_UNSIGNED_LITERAL);
        plant_32_bit_code_word(0x00FFFFFF);
        plant_pop();
    }
    else if ((BT_MODE(from_amode) == BT_MODE(to_amode)))
    {
        /* do nothing */
    }
    else if ((BT_MODE(from_amode) == BT_MODE_UNSIGNED_INTEGER) && (BT_MODE(to_amode) == BT_MODE_SIGNED_INTEGER)
             ||
             (BT_MODE(from_amode) == BT_MODE_SIGNED_INTEGER && BT_MODE(to_amode) == BT_MODE_UNSIGNED_INTEGER))
    {
        plant_stack_a();
        amode = to_amode;
        plant_pop_a();
    }
    else
    {
        fatal("Conversion not implemented\n");
    }

    amode = to_amode;
}

void op_org_set_amode(uint16 N)
{
    amode = N;
    log(LOG_PLANT, "Amode set to %s\n", format_basic_type(N));
}

void op_org_stack(uint16 N)
{
    if (N != OPERAND_REG_A)
    {
        fatal("Can't stack register 0x%04x\n", N);
    }

    log(LOG_PLANT, "%04X STACK register\n", next_instruction_segment_address());
    plant_stack_a();
}

void op_org_jump_equal(uint16 N)
{
    op_org_rel_jump_generic(N, F_BRANCH_EQ, "EQ");
}

void op_org_jump_not_equal(uint16 N)
{
    op_org_rel_jump_generic(N, F_BRANCH_NE, "NE");
}

void op_org_jump_greater_than_or_equal(uint16 N)
{
    op_org_rel_jump_generic(N, F_BRANCH_GE, "GE");
}

void op_org_jump_less_than(uint16 N)
{
    op_org_rel_jump_generic(N, F_BRANCH_LT, "LT");
}

void op_org_jump_less_than_or_equal(uint16 N)
{
    op_org_rel_jump_generic(N, F_BRANCH_LE, "LE");
}

void op_org_jump_greater_than(uint16 N)
{
    op_org_rel_jump_generic(N, F_BRANCH_GT, "GT");
}

void op_org_jump_seg(uint16 N)
{
    if (mutl_var[N].data.label.address_defined)
    {
        int16 relative = (uint16)(mutl_var[N].data.label.address - next_instruction_segment_address());
        log(LOG_PLANT, "%04X ORG JUMP SEG to %s relative %d\n", next_instruction_segment_address(), mutl_var[N].name, relative);
        if (relative >= -32 && relative < 32)
        {
            plant_org_order(F_RELJUMP, K_LITERAL, relative & 0x3F);
        }
        else
        {
            plant_org_order_extended(F_RELJUMP, KP_LITERAL, NP_16_BIT_SIGNED_LITERAL);
            plant_16_bit_code_word(relative);
        }
    }
    else
    {
        log(LOG_PLANT, "%04X ORG JUMP SEG to %s forward ref\n", next_instruction_segment_address(), mutl_var[N].name);
        plant_org_order_extended(F_RELJUMP, KP_LITERAL, NP_16_BIT_SIGNED_LITERAL);
        register_forward_label_ref(N);
        plant_16_bit_code_word(0); /* place holder */
    }
}

static MUTLOP mutl_ops[32][4] =
{
    { { NULL, OP_NULL },         { op_a_store, OP_REGULAR },            { op_org_stack_link, OP_REGULAR },                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_load_neg_or_ref, OP_REGULAR },  { op_org_stack_parameter, OP_REGULAR },           { op_d_load_ref, OP_REGULAR } },
    { { op_b_load, OP_REGULAR }, { op_a_load, OP_REGULAR },             { op_org_enter, OP_REGULAR },                     { op_d_load, OP_REGULAR } },
    { { NULL, OP_NULL },         { op_a_xor, OP_REGULAR },              { op_org_return, OP_REGULAR },                    { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_and, OP_REGULAR },              { NULL, OP_NULL },                                { op_d_select_element, OP_REGULAR } },
    { { NULL, OP_NULL },         { op_a_or, OP_REGULAR },               { op_org_aconv, OP_MODE},                         { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_left_shift, OP_REGULAR },       { op_org_set_amode, OP_MODE},                     { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { NULL, OP_NULL },                     { op_org_stack, OP_REGULAR },                     { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_add, OP_REGULAR },              { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_sub, OP_REGULAR },              { op_org_jump_equal, OP_REGULAR },                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_reverse_sub, OP_REGULAR },      { op_org_jump_not_equal, OP_REGULAR },            { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_mul, OP_REGULAR },              { op_org_jump_greater_than_or_equal, OP_REGULAR },{ NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_div, OP_REGULAR },              { op_org_jump_less_than, OP_REGULAR },            { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { NULL, OP_NULL },                     { op_org_jump_less_than_or_equal, OP_REGULAR },   { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { NULL, OP_NULL },                     { op_org_jump_greater_than, OP_REGULAR },         { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_compare, OP_REGULAR },          { op_org_jump_seg, OP_REGULAR },                  { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { NULL, OP_NULL },                     { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { NULL, OP_NULL },                     { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { NULL, OP_NULL },                     { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_xor_store, OP_REGULAR },        { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_and_store, OP_REGULAR },        { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_or_store, OP_REGULAR },         { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { NULL, OP_NULL },                     { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { NULL, OP_NULL },                     { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_add_store, OP_REGULAR },        { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_sub_store, OP_REGULAR },        { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { op_a_reverse_sub_store, OP_REGULAR },{ NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { NULL, OP_NULL },                     { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { NULL, OP_NULL },                     { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { NULL, OP_NULL },                     { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { NULL, OP_NULL },                     { NULL, OP_NULL },                                { NULL, OP_NULL } },
    { { NULL, OP_NULL },         { NULL, OP_NULL },                     { NULL, OP_NULL },                                { NULL, OP_NULL } }
};

void set_literal_value(t_uint64 val, uint16 size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        current_literal.buffer[i] = (val >> 8 * (size - i - 1)) & 0xFF;
    }
    current_literal.length = size;
}

void TLSEG(int32 N, int32 S, int32 RTA, int32 CTA, uint16 NL)
{
    SEGMENT *seg = &segments[N];
    uint16 actual_rta = (RTA == -1) ? 0 : get_segment_number_from_full_address(RTA);

    if (seg == get_segment_by_full_address(start_address))
    {
        /* update start address*/
        start_address = actual_rta << 16 | (start_address & 0xFFFF);
        stack_front_load_byte_address = actual_rta << 16 | (stack_front_load_byte_address & 0xFFFF);
        elf_set_entry(elf_module_context, start_address);
    }

    seg->in_use = 1;
    seg->segment_address = actual_rta;
    seg->size = S;
    seg->kind = NL;
    seg->run_time_address = RTA;
    if (seg->elf_section_index!= 0)
    {
        elf_update_section_address(elf_module_context, seg->elf_section_index, seg->run_time_address);
    }

    log(LOG_MEMORY, "TL.SEG MUTL segment %d, segment address %d, size %d run-time address 0x%08X\n", N, seg->segment_address, seg->size, seg->run_time_address);
}

void TLLOAD(uint16 SN, int AN)
{
    log(LOG_MEMORY, "TL.LOAD segment %d area %d\n", SN, AN);
    areas[AN].segment_index = SN;/* TODO: the code here is naive, it should not have a 1:1 mapping from area to segment, we should scan segment table for a free entry */
}

void TLCODEAREA(int AN)
{
    SEGMENT *segment;

    log(LOG_MEMORY, "TL.CODE.AREA area %d\n", AN);
    current_code_area = (uint8)AN;
    segment = get_segment_for_area(current_code_area);
    if (segment->elf_section_index == 0)
    {
        segment->elf_section_index = elf_add_code_section(elf_module_context, 2, segment->run_time_address, (char *)segment->words);
    }
    else
    {
        elf_update_section_address(elf_module_context, segment->elf_section_index, segment->run_time_address);
    }
}

void TLDATAAREA(int AN)
{
    SEGMENT *segment;

    log(LOG_MEMORY, "TL.DATA.AREA area %d\n", AN);
    current_data_area = (uint8)AN;
    segment = get_segment_for_area(current_data_area);
    if (segment->elf_section_index == 0)
    {
        segment->elf_section_index = elf_add_data_section(elf_module_context, 4, segment->run_time_address, (char *)segment->words);
    }
    else
    {
        elf_update_section_address(elf_module_context, segment->elf_section_index, segment->run_time_address);
    }
}

void TL(int M, char *FN, int DZ)
{
    int i;

    strcpy(out_file_name, FN);

    is_library = (M & 0x4) == 0x4;
    if (is_library)
    {
        printf("Compiling a library\n");
        elf_module_context = elf_new_file(ET_REL, 0, 0);
    }
    else
    {
        elf_module_context = elf_new_file(ET_EXEC, 0, 0);
        start_address = next_instruction_full_byte_address();
        elf_set_entry(elf_module_context, start_address);
        printf("Compiling a program\n");
    }

    for (i = 0; i < MAX_SEGMENTS; i++)
    {
        segments[i].in_use = 0;
    }

    TLSEG(0, MAX_SEGMENT_SIZE, -1, -1, 6);

    current_literal.buffer = (char *)current_literal_buf;
}

void TLEND(void)
{
    if (!is_library)
    {
        //SEGMENT *stack_segment = get_segment_for_area(0);
        //plant_16_bit_word_update_by_address(stack_front_load_byte_address / 2, stack_segment->segment_address/4);
    }

    elf_write_file(elf_module_context, out_file_name);
}

void TLMODULE(void)
{
    TLLOAD(0, 1);
    TLCODEAREA(1);
    TLDATAAREA(0);
    
    if (!is_library)
    {
        SEGMENT *stack_segment = get_segment_for_area(0);
        log(LOG_PLANT, "%04X Load SN=0x%04x\n", next_instruction_segment_address(), stack_segment->segment_address);
        plant_org_order_extended(F_SN_LOAD, KP_LITERAL, NP_16_BIT_UNSIGNED_LITERAL);
        plant_16_bit_code_word(stack_segment->segment_address);
        plant_org_order_extended(F_SF_LOAD, KP_LITERAL, NP_16_BIT_UNSIGNED_LITERAL);
        stack_front_load_byte_address = next_instruction_full_byte_address();
        plant_16_bit_code_word(0);
    }

    start_block_level(0, 0);
}

void TLENDMODULE(int ST)
{
    end_block_level();
}

uint16 compute_variable_size(uint16 T, int D)
{
    uint16 result;
    if (D == 0)
    {
        if (BT_SIZE(T) > 4)
        {
            result = 2;
        }
        else
        {
            result = 1;
        }
    }
    else if (D > 0)
    {
        result = ((BT_SIZE(T) * (uint16)D) + 1) / 4;
    }
    else if (D != -1 && D != -2048 && D != 4096)
    {
        LITSYMBOL *lit = &mutl_var[-D].data.lit;
        int i;
        result = 0;
        for (i = 0; i < lit->value.length; i++)
        {
            result = (result << 8) | (lit->value.buffer[i] & 0xFF);
        }
    }
    else
    {
        fatal("Don't yet support computing variable size when dimension is negative\n");
        result = 0;
    }

    return result;
}

uint16 compute_variable_space(uint16 size_words, int is_parameter)
{
    uint16 result;
    if (is_parameter)
    {
        result = 2;
    }
    else
    {
        result = size_words;
    }
    return result;
}

MUTLSYMBOL *get_next_mutl_var(uint16 n)
{
    MUTLSYMBOL *result;
    if (block_level < 0)
    {
        result = &mutl_import_var[n];
    }
    else
    {
        result = &mutl_var[n];
    }

    return result;
}

void make_read_proc_name(char *name, MUTLSYMBOL *var)
{
    sprintf(name, "%s(READ)", var->name);
}

void make_write_proc_name(char *name, MUTLSYMBOL *var)
{
    sprintf(name, "%s(WRITE)", var->name);
}

void import_vstore(MUTLSYMBOL *var)
{
    /* search all import modules for read or write procs */
    char proc_name[MAX_NAME_LEN];
    Elf32_Sym *external_v_sym;
    Elf32_Sym *external_v_read_sym;
    Elf32_Sym *external_v_write_sym;

    external_v_sym = get_symbol(var->name);
    if (external_v_sym == NULL)
    {
        fatal("Please import the module that exports the imported VSTORE");
    }
    else if (external_v_sym->st_shndx != SHN_ABS)
    {
        var->data.var.position = (uint16)external_v_sym->st_value;
        var->data.var.is_vstore = 0;
    }

    make_read_proc_name(proc_name, var);
    external_v_read_sym = get_symbol(proc_name);
    if (external_v_read_sym != NULL)
    {
        var->data.var.v_read_proc_sym = elf_add_symbol(elf_module_context, proc_name, 0, 4, STB_GLOBAL, STT_FUNC, SHN_UNDEF);
    }

    make_write_proc_name(proc_name, var);
    external_v_write_sym = get_symbol(proc_name);
    if (external_v_write_sym != NULL)
    {
        var->data.var.v_write_proc_sym = elf_add_symbol(elf_module_context, proc_name, 0, 4, STB_GLOBAL, STT_FUNC, SHN_UNDEF);
    }

    /* get variable position to decide if it is a variable or a direct VSTORE address */
}

void declare_variable(VECTOR *name, uint16 T, int D, int is_parameter, int is_vstore, uint16 v_position, uint16 v_read_proc, uint16 v_write_proc, int module)
{
    SEGMENT *segment = get_segment_for_area(current_data_area);
    MUTLSYMBOL *var;
    uint16 var_n;
    uint16 size_words;

    size_words = compute_variable_size(T, D);

    if (!is_vstore)
    {
        var_n = add_block_var(T, is_parameter);
    }
    else
    {
        var_n = add_other_block_item();
    }
    var = get_next_mutl_var(var_n);

    var->symbol_type = SYM_VARIABLE;
    vecstrcpy(var->name, name, sizeof(var->name));
    var->block_level = block_level;
    var->module_number = module;
    var->data.var.data_type = T;
    var->data.var.dimension = (uint16)D;
    var->data.var.is_parameter = is_parameter;

    if (BT_IS_IMPORT(T))
    {
        BLOCK *block;
        block = get_current_block();
        var->data.var.is_vstore = is_vstore;
        var->data.var.position = (uint16)-1;
        if (is_vstore)
        {
            import_vstore(var);
        }
        log(LOG_SYMBOLS, "Declare var %s %s level=%d, dim=%d, words=%d, offset=%d in slot %d\n", var->name, format_basic_type(T), block_level, D, size_words, var->data.var.position, var_n);
    }
    else if (!is_vstore)
    {
        BLOCK *block = get_current_block();
        var->data.var.is_vstore = 0;
        var->data.var.position = get_block_name_offset_for_last_var(T, is_parameter);
        block->local_names_space += compute_variable_space(size_words, is_parameter);
        if (block_level == 0)
        {
            /* reserve space in data area by writing data words */
            int i;
            for (i = 0; i < 2 * size_words; i++)
            {
                plant_16_bit_data_word(0);
            }
        }
        log(LOG_SYMBOLS, "Declare var %s %s level=%d, dim=%d, words=%d, offset=%d in slot %d\n", var->name, format_basic_type(T), block_level, D, size_words, var->data.var.position, var_n);
    }
    else if (v_position == 0)
    {
        var->data.var.is_vstore = 1;
        var->data.var.position = (uint16)get_current_literal();
        log(LOG_SYMBOLS, "Declare vstore %s %s level=%d, dim=%d, position=0x%X in slot %d\n", var->name, format_basic_type(T), block_level, D, var->data.var.position, var_n);
    }
    else
    {
        var->data.var.is_vstore = 0;
        var->data.var.v_read_proc = v_read_proc;
        var->data.var.v_write_proc = v_write_proc;
        var->data.var.position = mutl_var[v_position].data.var.position;

        if (v_read_proc != 0 && v_position != 0)
        {
            MUTLSYMBOL *mutl_sym = &mutl_var[v_read_proc];
            make_read_proc_name(mutl_sym->name, var);
            elf_update_symbol_name(elf_module_context, mutl_sym->elf_symbol, mutl_sym->name);
        }

        if (v_write_proc != 0)
        {
            MUTLSYMBOL *mutl_sym = &mutl_var[v_write_proc];
            make_write_proc_name(mutl_sym->name, var);
            elf_update_symbol_name(elf_module_context, mutl_sym->elf_symbol, mutl_sym->name);
        }
        log(LOG_SYMBOLS, "Declare vstore (backed by var) %s %s level=%d, dim=%d, position=0x%X in slot %d\n", var->name, format_basic_type(T), block_level, D, var->data.var.position, var_n);
    }

    if (BT_IS_EXPORT(T))
    {
        Elf32_Half section = (var->data.var.is_vstore) ? SHN_ABS : segment->elf_section_index;
        var->elf_symbol = elf_add_symbol(elf_module_context, var->name, var->data.var.position, BT_SIZE(var->data.var.data_type), STB_GLOBAL, STT_OBJECT, section);
    }
    else if (BT_IS_IMPORT(T))
    {
        var->elf_symbol = elf_add_symbol(elf_module_context, var->name, var->data.var.position, BT_SIZE(var->data.var.data_type), STB_GLOBAL, STT_OBJECT, SHN_UNDEF);
    }
    else if (block_level == 0 && !is_vstore && !is_parameter)
    {
        var->elf_symbol = elf_add_symbol(elf_module_context, var->name, var->data.var.position, BT_SIZE(var->data.var.data_type), STB_LOCAL, STT_OBJECT, segment->elf_section_index);
    }
}

void declare_literal(VECTOR *name, VECTOR *literal, uint16 T, int D, int module)
{
    SEGMENT *segment = get_segment_for_area(current_data_area);
    MUTLSYMBOL *var;
    LITSYMBOL *lit;
    uint16 var_n;

    var_n = add_other_block_item();
    var = get_next_mutl_var(var_n);
    lit = &var->data.lit;

    vecstrcpy(var->name, name, sizeof(var->name));
    var->symbol_type = SYM_LITERAL;
    var->block_level = block_level;
    var->module_number = module;
    lit->data_type = T;
    lit->dimension = (D == -1) ? literal->length : (uint16)D;
    lit->address = compute_descriptor_origin((uint16)next_data_address());
    lit->value.buffer = (char *)&lit->valuebuf;

    if (!BT_IS_IMPORT(T))
    {
        vecmemcpy(&lit->value, literal, sizeof(lit->valuebuf));
    }

    if (BT_IS_EXPORT(T))
    {
        if (lit->value.length > 4)
        {
            fatal("can't export literal greater than 4 bytes");
        }

        Elf32_Addr value = 0;
        for (int i = 0; i < lit->value.length; i++)
        {
            value = (value << 8) | lit->value.buffer[i];
        }
        var->elf_symbol = elf_add_symbol(elf_module_context, var->name, value, 0, STB_GLOBAL, STT_OBJECT, SHN_ABS);
    }
    else if (BT_IS_IMPORT(T))
    {
        var->elf_symbol = elf_add_symbol(elf_module_context, var->name, 0, 0, STB_GLOBAL, STT_OBJECT, SHN_UNDEF);
    }
    else if (block_level == 0 && (literal->length > 4 || (literal->length == 0 && D == -1)))
    {
        var->elf_symbol = elf_add_symbol(elf_module_context, var->name, var->data.lit.address, 0, STB_LOCAL, STT_OBJECT, segment->elf_section_index);
    }
    log(LOG_SYMBOLS, "Declare literal %s %s level=%d, dim=%d, address=0x%08X in slot %d\n", var->name, format_basic_type(var->data.lit.data_type), block_level, var->data.lit.dimension, var->data.lit.address, var_n);
}

void declare_proc(VECTOR *name, uint32 address, int NAT, int module)
{
    static int generated_name = 0;
    SEGMENT *segment = get_segment_for_area(current_code_area);
    MUTLSYMBOL *sym = get_next_mutl_var(add_other_block_item());
    current_proc_spec = &sym->data.proc;
    sym->symbol_type = SYM_PROC;
    sym->data.proc.nature = NAT;
    if (address != 0)
    {
        sym->data.proc.address_defined = 1;
        sym->data.proc.address = address;
    }

    if (name == NULL)
    {
        sprintf(sym->name, "(GEN%04X)", generated_name++);
    }
    else
    {
        vecstrcpy(sym->name, name, sizeof(sym->name));
    }

    if (sym->data.proc.address_defined)
    {
        log(LOG_SYMBOLS, "Declare proc %s, nature=0x%04X address=0x%08X in slot %d\n", sym->name, NAT, sym->data.proc.address, get_current_block()->last_mutl_var);
    }
    else
    {
        log(LOG_SYMBOLS, "Declare proc %s, nature=0x%04X in slot %d\n", sym->name, NAT, get_current_block()->last_mutl_var);
    }

    if (BT_IS_EXPORT(NAT))
    {
        sym->elf_symbol = elf_add_symbol(elf_module_context, sym->name, 0, 4, STB_GLOBAL, STT_FUNC, segment->elf_section_index);
    }
    else if (BT_IS_IMPORT(NAT))
    {
        sym->elf_symbol = elf_add_symbol(elf_module_context, sym->name, 0, 4, STB_GLOBAL, STT_FUNC, SHN_UNDEF);
    }
    else
    {
        sym->elf_symbol = elf_add_symbol(elf_module_context, sym->name, 0, 4, STB_LOCAL, STT_FUNC, segment->elf_section_index);
    }
}

void TLTYPE(VECTOR *N, int NAT)
{
    uint16 sym_n;
    if (MUTL_NATURE_NAME_ALREADY_DEFINED(NAT))
    {
        sym_n = MUTL_NATURE_NAME(NAT);
    }
    else
    {
        sym_n = add_other_block_item();
    }

    current_type_def = get_next_mutl_var(sym_n);
    vecstrcpy(current_type_def->name, N, sizeof(current_type_def->name));
    current_type_def->symbol_type = SYM_TYPE;
    current_type_def->block_level = block_level;
    current_type_def->module_number = NO_MODULE;

    log(LOG_SYMBOLS, "Start aggregate type %0.*s nature=%X level=%d in slot %d\n", N->length, N->buffer, NAT, block_level, sym_n);
}

void TLTYPECOMP(uint16 T, int D, VECTOR *NM)
{
    log(LOG_SYMBOLS, "Adding %0.*s of type %s and dimension %d to %s\n", NM->length, NM->buffer, format_basic_type(T), D, current_type_def->name);
    if (BT_NOTDEF(T))
    {
        fatal("Don't yet support forward def\n"); /* have to add a MUTL name for it */
    }

    TYPESYMBOL *type = &current_type_def->data.type;
    VARSYMBOL *field = &type->fields[type->field_count++];
    field->data_type = T;
    field->dimension = (uint16)D;
}

void TLENDTYPE(int STAT)
{
    log(LOG_SYMBOLS, "End of aggregate type definition for %s\n", current_type_def->name);
    current_type_def = NULL;
    if (STAT == 1)
    {
        fatal("Don't support alternative type specification\n");
    }
}

void TLSDECL(VECTOR *SN, uint16 T, int D)
{
    VECTOR name;
    if (SN != NULL)
    {
        memcpy(&name, SN, sizeof(VECTOR));
    }

    if (D == -1)
    {
        if (SN == NULL)
        {
            name.buffer = "(anonymous_literal)";
            name.length = (uint16)strlen(name.buffer);
        }
        declare_literal(&name, &current_literal, T, D, NO_MODULE);
    }
    else
    {
        if (SN == NULL)
        {
            name.buffer = "(anonymous_variable)";
            name.length = (uint16)strlen(name.buffer);
        }
        declare_variable(&name, T, D, 0, 0, 0, 0, 0, NO_MODULE);
    }
}

void TLVDECL(VECTOR *SN, uint32 SA, uint16 RS, uint16 WS, uint16 T, int D)
{
    declare_variable(SN, T, D, 0, 1, (uint16)SA, RS, WS, NO_MODULE);
}

void TLASS(int VL, uint16 AN)
{
    LITSYMBOL *lit;
    current_assign_variable = VL;
    lit = &mutl_var[current_assign_variable].data.lit;
    lit->dimension = 0;
    lit->length = 0;

    if (AN == -1)
    {
        current_assign_variable_area = current_code_area;
    }
    else if (AN == -2)
    {
        current_assign_variable_area = current_data_area;
    }
    else
    {
        current_assign_variable_area = AN;
    }
    log(LOG_LITERALS, "TL.ASS to variable %d in area %d\n", current_assign_variable, current_assign_variable_area);
}

void TLASSVALUE(uint16 N, int R)
{
    int i;
    uint16 size;
    LITSYMBOL *lit;
    if (N != 0)
    {
        MUTLSYMBOL *mutl_sym = &mutl_var[N];
        if (mutl_sym->symbol_type == SYM_PROC)
        {
            log(LOG_LITERALS, "TL.ASS.VALUE to proc %s, repeat is %d\n", mutl_sym->name, R);
            SEGMENT *segment = get_segment_for_area(current_assign_variable_area);
            for (i = 0; i < R; i++)
            {
                elf_add_relocation_entry(elf_module_context, segment->elf_section_index, next_instruction_segment_byte_address(), mutl_sym->elf_symbol, MU5_REL_TYPE_FUNC, 0);
                plant_32_bit_word(current_assign_variable_area, 0); /* place holder */
                
            }
        }
        else
        {
            fatal("TL.ASS.VALUE for non-zero NAME not supported (except for procedures)\n");
        }
    }
    else
    {
        lit = &mutl_var[current_assign_variable].data.lit;
        size = BT_SIZE(lit->data_type);

        log(LOG_LITERALS, "TL.ASS.VALUE current literal to variable %d, repeat is %d\n", current_assign_variable, R);
        for (i = 0; i < R; i++)
        {
            lit->length += current_literal.length;
            lit->dimension += (current_literal.length + size - 1) / size; /* round up to integral number of size units */
            plant_vector(lit->data_type, &current_literal);
        }
    }
}

void TLASSEND(void)
{
    log(LOG_LITERALS, "TL.ASS.END\n");
    if (IS_MUTL_VAR(current_assign_variable))
    {
        MUTLSYMBOL *sym = &mutl_var[current_assign_variable];
        LITSYMBOL *lit = &sym->data.lit;
        if (sym->elf_symbol != NULL)
        {
            elf_update_symbol_size(sym->elf_symbol, lit->dimension);
        }
    }
    current_assign_variable = -1;
    memset(current_literal_buf, 0, sizeof(current_literal_buf));
    current_literal.length = 0;
}

void TLPROCSPEC(VECTOR *NAM, int NAT)
{
    declare_proc(NAM, 0, NAT, NO_MODULE);
}

void TLPROCPARAM(uint16 T, int D)
{
    log(LOG_SYMBOLS, "Declare proc param %s, dim=%d\n", format_basic_type(T), D);
    if (current_proc_spec->param_count < MAX_PROC_PARAMS)
    {
        current_proc_spec->parameters[current_proc_spec->param_count].data_type = T;
        current_proc_spec->parameters[current_proc_spec->param_count].dimension = (uint16)D;
        current_proc_spec->param_count++;
    }
    else
    {
        fatal("Too many parameters for procedure\n");
    }
}

void TLPROCRESULT(uint16 R, int D)
{
    if (R != 0)
    {
        log(LOG_SYMBOLS, "Declare proc result %s, dim=%d\n", format_basic_type(R), (uint16)D);
    }
    /* TODO. Process this. */
}

void TLPROC(uint16 P)
{
    int i;
    current_proc_def = &mutl_var[P];
    PROCSYMBOL *proc_def_var = &current_proc_def->data.proc;
    log(LOG_STRUCTURE, "Define proc %s at 0x%04X\n", current_proc_def->name, next_instruction_segment_byte_address());
    proc_def_var->address_defined = 1;
    proc_def_var->address = next_instruction_full_byte_address();
    elf_update_symbol_value(current_proc_def->elf_symbol, next_instruction_segment_byte_address());

    fixup_forward_label_refs(P);
    start_block_level(param_stack_size(P), !IS_SUBROUTINE(proc_def_var->nature));
    for (i = 0; i < proc_def_var->param_count; i++)
    {
        VECTOR temp;
        temp.buffer = "(param)";
        temp.length = (uint16)strlen(temp.buffer);
        declare_variable(&temp, proc_def_var->parameters[i].data_type, proc_def_var->parameters[i].dimension, 1, 0, 0, 0, 0, NO_MODULE);
    }
}

void TLPROCKIND(int K)
{
    fatal("TLPROCKIND");
    log(LOG_STRUCTURE, "Define proc kind 0x%04X\n", K);
}

void TLENDPROC(void)
{
    log(LOG_STRUCTURE, "End proc\n");
    end_block_level();
}

void TLBLOCK(void)
{
    fatal("TLBLOCK");
}

void TLENDBLOCK(void)
{
    fatal("TLENDBLOCK");
    log(LOG_STRUCTURE, "End block\n");
}
void TLENTRY(uint16 N)
{
    fatal("TLENTRY");
    log(LOG_STRUCTURE, "Enter proc %s\n", mutl_var[N].name);
}
void TLLABELSPEC(VECTOR *N, int U)
{
    char temp[80];
    uint16 sym_n;

    sym_n = add_other_block_item();
    MUTLSYMBOL *sym = get_next_mutl_var(sym_n);
    sym->symbol_type = SYM_LABEL;
    if (U > 1)
    {
        sprintf(temp, "INTERNAL%04d", sym_n);
        strncpy(sym->name, temp, MAX_NAME_LEN - 1);
        log(LOG_SYMBOLS, "Declare internal label %s\n", temp);
    }
    else
    {
        vecstrcpy(sym->name, N, sizeof(sym->name));
        log(LOG_SYMBOLS, "Declare label %s\n", sym->name);
    }

    sym->data.label.address_defined = 0;
    sym->data.label.num_forward_refs = 0;
}

void TLLABEL(uint16 L)
{
    log(LOG_SYMBOLS, "Define label %s at 0x%04X\n", mutl_var[L].name, next_instruction_segment_address());
    mutl_var[L].data.label.address_defined = 1;
    mutl_var[L].data.label.address = next_instruction_segment_address();
    fixup_forward_label_refs(L);
}

void TLCLIT16(uint16 BT, int16 VAL)
{
    set_literal_value(VAL, sizeof(int16));
    log(LOG_LITERALS, "Current 16-bit literal 0x%llx\n", get_current_literal());
    current_literal_basic_type = BT;
}

void TLCLIT32(uint16 BT, int32 VAL)
{
    set_literal_value(VAL, sizeof(int32));
    log(LOG_LITERALS, "Current 32-bit literal 0x%llx\n", get_current_literal());
    current_literal_basic_type = BT;
}

void TLCLIT64(uint16 BT, t_uint64 VAL)
{
    set_literal_value(VAL, sizeof(t_uint64));
    log(LOG_LITERALS, "Current 64-bit literal 0x%llx\n", get_current_literal());
    current_literal_basic_type = BT;
}

void TLCNULL(int PT)
{
    fatal("TL.C.NULL not supported\n");
}

void TLCLITS(uint16 BT, VECTOR *VAL)
{
    int i;

    vecmemcpy(&current_literal, VAL, MAX_LITERAL_LEN);

    current_literal_basic_type = BT;
    log(LOG_LITERALS, "Current vector literal is");
    for (i = 0; i < VAL->length; i++)
    {
        log(LOG_LITERALS, " %02X", current_literal.buffer[i]);
    }
    log(LOG_LITERALS, "\n");
}

void TLCLIT128(uint16 BT, double VAL)
{
    fatal("TL.C.LIT128 not supported\n");
}

void TLLIT(VECTOR *SN, int K)
{
    uint16 T = current_literal_basic_type;
    T |= (K & BT_IMPORT); /* add in import flag if this is an import */
    if ((K & 0x3FFF) == 0)
    {
        T |= (K & BT_EXPORT);
    }
    declare_literal(SN, &current_literal, T, 0, NO_MODULE);
}

void TLPL(int F, uint16 N)
{
    int data_type = F >> 5;
    int opcode = F & 0x1F;
    void(*op)(uint16) = NULL;
    op = mutl_ops[opcode][data_type].op;
    if (op != NULL)
    {
        if (mutl_ops[opcode][data_type].op_type == OP_REGULAR)
        {
            check_global_ref(N);
        }
        op((uint16)N);
    }
    else
    {
        fatal("Plant type=%d op=0x%X n=0x%X\n", data_type, opcode, N);
    }
}

void TLINSERT(int BIN)
{
    if ((BIN & 0xFFFF0000) != 0)
    {
        fatal("Cannot insert numbers larger than 16 bits");
    }

    plant_16_bit_code_word(BIN & 0xFFFF);
}

void TLLINE(int LN)
{
    /* TODO: Line numbers are not accurate. Blank lines don't get counted, nor do line breaks in the middle of a statement */
    current_line = LN;
}

void TLPRINT(int M)
{
    // TODO: Implement as per manual
}

LOOP *start_loop(int mode, uint16 control_variable)
{
    LOOP *loop;
    loop_level++;
    if (loop_level >= MAX_LOOP_DEPTH)
    {
        fatal("Exceed loop nesting depth\n");
    }

    loop = &loop_stack[loop_level];
    loop->address_of_condition = next_instruction_segment_address();
    loop->mode = mode;
    loop->control_variable = control_variable;

    return loop;
}

void end_loop(void)
{
    loop_level--;
}

void TLCYCLE(uint16 limit)
{
    LOOP *loop;
    log(LOG_PLANT, "TL.CYCLE\n");
    uint16 saved_amode = amode;
    amode = TINT32;
    op_a_load(limit);
    op_org_stack(OPERAND_REG_A);
    loop = start_loop(1, OPERAND_POP);
    TLCLIT32(TINT32, 0);
    op_a_compare(OPERAND_LITERAL);
    loop->address_of_end_of_loop_jump = op_org_jump_generic_rel_address(F_BRANCH_LE, UNKNOWN_ADDRESS);
    amode = saved_amode;
}

void TLCVCYCLE(uint16 cv, uint16 init, int mode)
{
    uint16 saved_amode = amode;
    amode = mutl_var[cv].data.var.data_type;
    log(LOG_PLANT, "TL.CV.CYCLE, mode=%d\n", mode);
    op_a_load(init);
    op_a_store(cv);
    start_loop(mode, cv);
    amode = saved_amode;
}

void TLCVLIMIT(uint16 limit)
{
    /* This code assumes the FOR loop is always of the form "FOR N < 10". In other words the operator is always LESS THAN only.
       The compiler does not seem to tell MUTL if the operator is any different. */
    uint16 saved_amode = amode;
    amode = TINT32;
    LOOP *loop = &loop_stack[loop_level];
    log(LOG_PLANT, "TL.CV.LIMIT %s\n", format_operand(limit));

    if (limit != OPERAND_REG_A)
    {
        op_a_load(limit);
    }

    op_a_compare(loop->control_variable);
    if ((loop->mode & 1) == 0)
    {
        loop->address_of_end_of_loop_jump = op_org_jump_generic_rel_address(F_BRANCH_LE, UNKNOWN_ADDRESS);
    }
    else
    {
        loop->address_of_end_of_loop_jump = op_org_jump_generic_rel_address(F_BRANCH_GT, UNKNOWN_ADDRESS);
    }

    amode = saved_amode;
}

void TLREPEAT(void)
{
    uint16 relative;
    LOOP *loop = &loop_stack[loop_level];
    uint16 saved_amode = amode;
    amode = mutl_var[loop->control_variable].data.var.data_type;
    log(LOG_PLANT, "TL.CV.REPEAT\n");
    op_a_load(loop->control_variable);
    if ((loop->mode & 1) == 0)
    {
        plant_order(cr(), F_ADD_A, K_LITERAL, 1);
    }
    else
    {
        plant_order(cr(), F_SUB_A, K_LITERAL, 1);
    }

    if (loop->control_variable == OPERAND_POP)
    {
        op_org_stack(OPERAND_REG_A);
    }
    else
    {
        op_a_store(loop->control_variable);
    }
    relative = (uint16)(loop->address_of_condition - next_instruction_segment_address());
    op_org_jump_generic_rel_address(F_RELJUMP, relative);

    relative = (uint16)(next_instruction_segment_address() - loop->address_of_end_of_loop_jump + 1);
    plant_16_bit_code_word_update(loop->address_of_end_of_loop_jump, relative, "end of loop address");
    end_loop();
    if (loop->control_variable == OPERAND_POP)
    {
        op_a_load(OPERAND_POP); /* remove control variable from the stack */
    }

    amode = saved_amode;
}


char *extract_filename(char *path)
{
    char * ptr;
    ptr = strrchr(path, '\\');
    if (ptr != NULL)
    {
        ptr++;
    }
    if (ptr == NULL)
    {
        ptr = strrchr(path, '/');
        if (ptr != NULL)
        {
            ptr++;
        }
    }

    if (ptr == NULL)
    {
        ptr = path;
    }

    return ptr;
}

uint16 read_16_bit_word(FILE *f)
{
    uint16 result = (uint8)fgetc(f) << 8 | (uint8)fgetc(f);
    return result;
}

uint32 read_32_bit_word(FILE *f)
{
    uint32 result = (uint32)fgetc(f) << 24 | (uint32)fgetc(f) << 16 | (uint32)fgetc(f) << 8 | (uint32)fgetc(f);
    return result;
}

void read_name(FILE *f, char *buffer, int max_len)
{
    uint8 len = fgetc(f) & 0xFF;
    if (len > max_len)
    {
        fatal("Name too long to read");
    }

    fread(buffer, 1, len, f);
}

void read_vector(FILE *f, VECTOR *v)
{
    v->length = fgetc(f) & 0xFF;
    fread(v->buffer, 1, v->length, f);
}

void update_segment_starts(void)
{
    int i;
    for (i = 0; i < MAX_SEGMENTS; i++)
    {
        if (segments[i].in_use)
        {
            segments[i].first_word = segments[i].next_word;
        }
    }
}

void import_symbol(char *name, Elf32_Addr value, Elf32_Word size, int type, unsigned char st_other)
{
    VECTOR vname;
    vname.buffer = name;
    vname.length = (uint16)strlen(name);
    if (type == STT_FUNC)
    {
        declare_proc(&vname, value, 0, imported_module_count - 1);
    }
}
