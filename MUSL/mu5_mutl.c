#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "support.h"

#define LOG_PLANT 0x1
#define LOG_SYMBOLS 0x2
#define LOG_STRUCTURE 0x4
#define LOG_LITERALS 0x8
#define LOG_MEMORY 0x10

#define FIRST_NAME 2
#define MAX_NAMES 4031
#define MAX_NAME_LEN 32
#define MAX_LITERAL_LEN 256
#define MAX_FORWARD_LOCATIONS 64
#define MAX_BLOCK_DEPTH 16
#define MAX_PROC_PARAMS 16
#define MAX_LOOP_DEPTH 16
#define MAX_AREAS 256

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

#define BT_SIZE(n) (((n >> 2) & 0xF) +1 )
#define BT_MODE(n) ((n >> 6) & 0x3)

#define BT_MODE_REAL 0
#define BT_MODE_SIGNED_INTEGER 1
#define BT_MODE_UNSIGNED_INTEGER 2
#define BT_MODE_DECIMAL 3

#define TINT32 0x4C

#define OPERAND_LITERAL 0
#define OPERAND_REG_A 0x3000
#define OPERAND_POP 0x1003
#define NO_OPERAND_FOLLOWS_FLAG 0x80
#define OPERAND_FOLLOWS(kn) ((kn & NO_OPERAND_FOLLOWS_FLAG) == 0)

#define UNKNOWN_ADDRESS 0x7FFF

typedef struct { void(*op)(int); } MUTLOP;

typedef enum { SYM_VARIABLE, SYM_LABEL, SYM_PROC } SYMBOLTYPE;

typedef struct
{
    int data_type;
    int dimension;
    int position; /* for regular variables this is offset in 32-bit words from NB, including LINK if appropriate, vstore it is the v-line number */
    int is_vstore;
} VARSYMBOL;

typedef struct /* some fields in common with PROC so must remain in synch */
{
    int address_defined;
    uint32 address;
    int num_forward_refs;
    uint32 forward_ref_locations[MAX_FORWARD_LOCATIONS];
} LABELSYMBOL;

typedef struct /* some fields in common with LABEL so must remain in synch */
{
    int address_defined;
    uint32 address;
    int num_forward_refs;
    uint32 forward_ref_locations[MAX_FORWARD_LOCATIONS];
    VARSYMBOL parameters[MAX_PROC_PARAMS];
    int param_count;
} PROCSYMBOL;

typedef struct
{
    SYMBOLTYPE symbol_type;
    char name[MAX_NAME_LEN];
    int block_level;
    union
    {
        VARSYMBOL var;
        LABELSYMBOL label;
        PROCSYMBOL proc;
    } data;
} MUTLSYMBOL;

typedef struct
{
    int last_mutl_var; /* The number of the last MUTL variable for the previous block in the hierarchy */
    int local_names_space; /* The number of 32-bit words required for local names in the current block, including LINK (if any) and parameters */
    uint32 stack_offset_address; /* the location to update the SF offset when the size of the block's variables is known */
    MUTLSYMBOL *proc_def_var;
} BLOCK;

typedef struct
{
    uint32 address_of_condition;
    uint32 address_of_end_of_loop_jump;
    int mode;
    int control_variable;
} LOOP;

typedef struct
{
    uint16 segment;
    uint16 size;
} AREA;

static int logging = LOG_PLANT | LOG_SYMBOLS | LOG_STRUCTURE | LOG_MEMORY | LOG_LITERALS;
static FILE *out_file;
static int amode = 0;
static MUTLSYMBOL mutl_var[MAX_NAMES + 1];
static uint8 current_literal[MAX_LITERAL_LEN];
static int current_literal_basic_type; /* gives length */
static int next_instruction_address = 0;
static PROCSYMBOL *current_proc_spec;
static MUTLSYMBOL *current_proc_def;
static int current_proc_call_n;
static int current_proc_call_stack_link_offset_address;
static BLOCK block_stack[MAX_BLOCK_DEPTH];
static int block_level = -1;
static LOOP loop_stack[MAX_LOOP_DEPTH];
static int loop_level = -1;
static AREA areas[MAX_AREAS];
static uint8 current_code_area = 1;
static uint8 current_data_area = 0;
static uint16 module_header_word_count = 0;

uint8 k_v(void);

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

    exit(0);

    va_end(va);
}

static void vecstrcpy(char *dst, VECTOR *src, int dst_size)
{
    int len = src->length;
    if (len > dst_size - 1)
    {
        len = dst_size - 1;
    }

    strncpy(dst, src->first, len);
    dst[len] = '\0';
}

static char *format_basic_type(int bt)
{
    static char buf[80];
    char *modes[] = { "Real", "Signed Int", "Unsigned Int", "Decimal" };
    sprintf(buf, "Mode=%s bytes=%d", modes[BT_MODE(bt)], BT_SIZE(bt));
    return buf;
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
        for (i = 0; i < len; i++)
        {
            sprintf(&buf[pos + 2*i], "%02X", current_literal[i]);
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

static void write_16_bit_word(uint16 word)
{
    uint8 byte;
    byte = (word >> 8) & 0xFF;
    fwrite(&byte, 1, 1, out_file);
    byte = word & 0xFF;
    fwrite(&byte, 1, 1, out_file);
}

static void write_16_bit_header_word(uint16 word)
{
    write_16_bit_word(word);
    module_header_word_count++;
}

static void write_16_bit_code_word(uint16 word)
{
    write_16_bit_word(word);
    next_instruction_address++;
    if (areas[current_code_area].size >= 65535)
    {
        fatal("Code segment is full\n");
    }

    areas[current_code_area].size++;
}

static void update_16_bit_word(uint32 address, uint16 word)
{
    unsigned char byte;
    fpos_t cur_pos;
    fgetpos(out_file, &cur_pos);
    fseek(out_file, address * 2, SEEK_SET);
    byte = (word >> 8) & 0xFF;
    fwrite(&byte, 1, 1, out_file);
    byte = word & 0xFF;
    fwrite(&byte, 1, 1, out_file);
    fsetpos(out_file, &cur_pos);
}

static void update_16_bit_code_word(unsigned int address, unsigned int word, char *reason)
{
    update_16_bit_word(address + module_header_word_count, word, reason);
    log(LOG_PLANT, "Fixing code address %08X to contain %04X for %s\n", address, word, reason);
}

static void update_16_bit_header_word(unsigned int address, unsigned int word, char *reason)
{
    update_16_bit_word(address, word, reason);
    log(LOG_PLANT, "Fixing header address %08X to contain %04X for %s\n", address, word, reason);
}

static t_uint64 get_current_literal()
{
    int len = BT_SIZE(current_literal_basic_type);
    t_uint64 literal = 0;
    int i;
    for (i = 0; i < len; i++)
    {
        literal = literal << 8 | current_literal[i];
    }

    return literal;
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
    else if (n < 0x1000)
    {
        if (!mutl_var[n].data.var.is_vstore)
        {
            kp = k_v();
            if (mutl_var[n].block_level <= 0)
            {
                np = NP_XNB;
            }
            else
            {
                np = NP_NB;
            }
        }
        else
        {
            kp = K_PRIVILEGED;
            np = NP_0;
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
                    write_16_bit_code_word(literal & 0xFFFF);
                }
                else if (len <= 4)
                {
                    write_16_bit_code_word((literal >> 16) & 0xFFFF);
                    write_16_bit_code_word(literal & 0xFFFF);
                }
                else
                {
                    write_16_bit_code_word((literal >> 48) & 0xFFFF);
                    write_16_bit_code_word((literal >> 32) & 0xFFFF);
                    write_16_bit_code_word((literal >> 16) & 0xFFFF);
                    write_16_bit_code_word(literal & 0xFFFF);
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
    else if (n < 0x1000)
    {
        MUTLSYMBOL *var = &mutl_var[n];
        if (BT_SIZE(var->data.var.data_type) <= 4 || var->data.var.is_vstore)
        {
            write_16_bit_code_word(var->data.var.position);
        }
        else
        {
            write_16_bit_code_word(var->data.var.position / 2);
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
    write_16_bit_code_word(plant_order);
}

static void plant_order_extended_operand(uint8 cr, uint8 f, uint16 n)
{
    uint16 order;
    uint8 operand = get_operand(n);

    order = (cr & 0x7) << 13;
    order |= (f & 0xF) << 9;
    order |= 0x7 << 6;
    order |= operand & 0x3F;
    write_16_bit_code_word(order);
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
    write_16_bit_code_word(order);
}

static void plant_org_order_extended(uint8 f, uint8 kp, uint8 np)
{
    uint16 plant_order;

    plant_order = (f & 0x3F) << 7;
    plant_order |= 0x1 << 6;
    plant_order |= (kp & 0x7) << 3;
    plant_order |= np & 0x7;
    write_16_bit_code_word(plant_order);
}

static void plant_org_order(uint8 f, uint8 k, uint8 n)
{
    uint16 order;

    order = (f & 0x3F) << 7;
    order |= (k & 0x1) << 6;
    order |= n & 0x3F;
    write_16_bit_code_word(order);
}

uint8 cr(void)
{
    uint8 result = 0;
    switch (BT_MODE(amode))
    {
        case BT_MODE_SIGNED_INTEGER:
        {
            result = CR_XS;
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
    return result;
}

uint8 k_v()
{
    uint8 result = 0;
    uint8 size = BT_SIZE(amode);
    if (size <= 4)
    {
        result = K_V32;
    }
    else
    {
        result = K_V64;
    }
    return result;
}

void start_block_level(int param_stack_size)
{
    BLOCK *block;
    int nb_adjust;

    block_level++;
    if (block_level >= MAX_BLOCK_DEPTH)
    {
        fatal("Max block nesting level exceeded\n");
    }

    block = &block_stack[block_level];
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
        nb_adjust = -param_stack_size; /* NB must be positioned at the LINK */
    }

    /* don't make the jump variable length because then we can't calculate the offset to pass to STACKLINK without more complication */
    plant_org_order_extended(F_NB_LOAD_SF_PLUS, KP_LITERAL, NP_16_BIT_SIGNED_LITERAL);
    write_16_bit_code_word(nb_adjust);
    log(LOG_PLANT, "%04X Plant NB=SF+%d\n", next_instruction_address, nb_adjust);
    plant_org_order_extended(F_SF_LOAD_NB_PLUS, KP_LITERAL, NP_16_BIT_SIGNED_LITERAL);
    block->stack_offset_address = next_instruction_address;
    write_16_bit_code_word(0); /* plant a placeholder to be filled with the size of the local variables */

    log(LOG_STRUCTURE, "Start block, level=%d, last mutl name=%d\n", block_level, block->last_mutl_var);
}

int block_var_is_not_aligned(T)
{
    BLOCK *block = &block_stack[block_level];
    int result = 0;
    if (BT_SIZE(T) > 4 && (block->local_names_space % 2 != 0))
    { 
        result = 1;
    }

    return result;
}

int add_block_var(uint8 T, int is_parameter)
{
    BLOCK *block = &block_stack[block_level];
    if (is_parameter || BT_SIZE(T) > 4)
    {
        if (block_var_is_not_aligned(T))
        {
            block->local_names_space++;
        }
        block->local_names_space += 2;
    }
    else
    {
        block->local_names_space++;
    }

    block->last_mutl_var++;
    return block->last_mutl_var;
}

int add_other_block_item(void)
{
    BLOCK *block = &block_stack[block_level];
    block->last_mutl_var++;
    return block->last_mutl_var;
}

uint16 get_block_name_offset_for_last_var(uint8 T, int is_parameter)
{
    BLOCK *block = &block_stack[block_level];
    uint16 result;

    if (BT_SIZE(T) > 4)
    {
        result = block->local_names_space / 2;
    }
    else if (is_parameter)
    {
        result = block->local_names_space - 1;
    }
    else
    {
        result = block->local_names_space - 1;
    }

    return result;
}

void end_block_level(void)
{
    if (block_level >= 0)
    {
        BLOCK *block = &block_stack[block_level];

        update_16_bit_code_word(block->stack_offset_address, block->local_names_space, "SF adjustment to make room for local variables");

        current_proc_def = block->proc_def_var;
    }
    else
    {
        fatal("Too many block ends, stack underflow\n");
    }

    log(LOG_STRUCTURE, "End block, level=%d\n", block_level);
    block_level--;
}

int param_stack_size(int N)
{
    int result;
    result = mutl_var[N].data.proc.param_count * 2;
    return result;
}

int param_instruction_size(int N)
{
    int result;
    result = mutl_var[N].data.proc.param_count * 2;
    return result;
}

void register_forward_label_ref(int N)
{
    LABELSYMBOL *label = &mutl_var[N].data.label;
    if (label->num_forward_refs >= MAX_FORWARD_LOCATIONS)
    {
        fatal("Forward ref list for %s is full\n", mutl_var[N].name);
    }
    else
    {
        label->forward_ref_locations[label->num_forward_refs++] = next_instruction_address;
        //printf("Forward ref for %s at 0x%08X\n", mutl_var[N].name, next_instruction_address);
    }
}

void fixup_forward_label_refs(int N)
{
    LABELSYMBOL *label = &mutl_var[N].data.label;
    int i;
    for (i = 0; i < label->num_forward_refs; i++)
    {
        update_16_bit_code_word(label->forward_ref_locations[i], label->address - label->forward_ref_locations[i] + 1, "forward label reference");
    }
}

void op_a_store(int N)
{
    log(LOG_PLANT, "%04X A store to %s\n", next_instruction_address, mutl_var[N].name);
    plant_order_extended_operand(cr(), F_STORE, N);
}

void op_a_load(int N)
{
    log(LOG_PLANT, "%04X A load %s\n", next_instruction_address, format_operand(N));
    if (BT_SIZE(amode) <= 4)
    {
        plant_order_extended_operand(cr(), F_LOAD_32, N);
    }
    else
    {
        plant_order_extended_operand(cr(), F_LOAD_64, N); /* can generate a 64-bit signed load on MU5 which is not valid */
    }
}

void op_a_load_neg_or_ref(int N)
{
    VARSYMBOL *var = &mutl_var[N];
    if (var->dimension == 0)
    {
        log(LOG_PLANT, "%04X A load negative %s\n", next_instruction_address, format_operand(N));
        op_a_load(N);
        plant_order(cr(), F_RSUB_A, K_IR, 34); /* 34 is the Z internal register */
    }
    else
    {
        log(LOG_PLANT, "%04X A load REF %s\n", next_instruction_address, format_operand(N));
    }
}

void op_a_xor(int N)
{
    log(LOG_PLANT, "%04X A XOR 0x%X\n", next_instruction_address, N);
    plant_order_extended_operand(cr(), F_XOR_A, N);
}

void op_a_and(int N)
{
    log(LOG_PLANT, "%04X A AND %s\n", next_instruction_address, format_operand(N));
    plant_order_extended_operand(cr(), F_AND_A, N);
}

void op_a_or(int N)
{
    log(LOG_PLANT, "%04X A OR %s\n", next_instruction_address, format_operand(N));
    plant_order_extended_operand(cr(), F_OR_A, N);
}

void op_a_left_shift(int N)
{
    log(LOG_PLANT, "%04X A LSH %s\n", next_instruction_address, format_operand(N));
    plant_order_extended_operand(cr(), F_SHIFT_L_A, N);
}

void op_a_add(int N)
{
    log(LOG_PLANT, "%04X A ADD %s\n", next_instruction_address, format_operand(N));
    plant_order_extended_operand(cr(), F_ADD_A, N);
}

void op_a_sub(int N)
{
    log(LOG_PLANT, "%04X A SUB %s\n", next_instruction_address, format_operand(N));
    plant_order_extended_operand(cr(), F_SUB_A, N);
}

void op_a_mul(int N)
{
    log(LOG_PLANT, "%04X A MUL %s\n", next_instruction_address, format_operand(N));
    plant_order_extended_operand(cr(), F_MUL_A, N);
}

void op_a_div(int N)
{
    log(LOG_PLANT, "%04X A DIV %s\n", next_instruction_address, format_operand(N));
    plant_order_extended_operand(cr(), F_DIV_A, N);
}

void op_a_compare(int N)
{
    log(LOG_PLANT, "%04X A COMP %s\n", next_instruction_address, format_operand(N));
    plant_order_extended_operand(cr(), F_COMP_A, N);
}

void op_a_add_store(int N)
{
    log(LOG_PLANT, "%04X A ADD STORE %s\n", next_instruction_address, format_operand(N));
    op_a_add(N);
    op_a_store(N);
}

void op_a_sub_store(int N)
{
    log(LOG_PLANT, "%04X A SUB STORE %s\n", next_instruction_address, format_operand(N));
    op_a_sub(N);
    op_a_store(N);
}

uint32 op_org_jump_generic_address(int F, int16 relative)
{
    uint32 address_location;
    if (relative >= -32 && relative < 32)
    {
        plant_org_order(F, K_LITERAL, relative & 0x3F);
        address_location = UNKNOWN_ADDRESS;
    }
    else
    {
        plant_org_order_extended(F, KP_LITERAL, NP_16_BIT_SIGNED_LITERAL);
        address_location = next_instruction_address;
        write_16_bit_code_word(relative);
    }

    return address_location;
}

void op_org_jump_generic(int N, int F, char *type)
{
    if (mutl_var[N].data.label.address_defined)
    {
        int16 relative = next_instruction_address - mutl_var[N].data.label.address;
        log(LOG_PLANT, "%04X ORG JUMP %s %s relative %d\n", next_instruction_address, type, mutl_var[N].name, relative);
        op_org_jump_generic_address(F, relative);
    }
    else
    {
        log(LOG_PLANT, "%04X ORG JUMP %s to %s forward ref\n", next_instruction_address, type, mutl_var[N].name);
        plant_org_order_extended(F, KP_LITERAL, NP_16_BIT_SIGNED_LITERAL);
        register_forward_label_ref(N);
        write_16_bit_code_word(0); /* place holder */
    }
}

void op_org_stack_link(int N)
{
    current_proc_call_n = N;
    log(LOG_PLANT, "%04X ORG STACK LINK to %s\n", next_instruction_address, mutl_var[N].name);
    plant_org_order_extended(F_STACKLINK, KP_LITERAL, NP_16_BIT_UNSIGNED_LITERAL);
    current_proc_call_stack_link_offset_address = next_instruction_address;
    write_16_bit_code_word(0); /* placeholder fixed up when we plant the ENTER */
}

void op_org_stack_parameter(int N)
{
    if (N != OPERAND_REG_A)
    {
        fatal("Can't stack parameter 0x%04x\n", N);
    }

    log(LOG_PLANT, "%04X STACK parameter\n", next_instruction_address);
    //plant_order(CR_STS1, F_STACK, K_IR, 48);
    plant_org_order(F_SF_PLUS, K_LITERAL, 2);
    plant_order_extended(cr(), F_STORE, K_V64, NP_SF);
    write_16_bit_code_word(0);
}

void op_org_enter(int N)
{
    if (N != 0)
    {
        fatal("Can't enter 0x%04x\n", N);
    }

    op_org_jump_generic(current_proc_call_n, F_RELJUMP, "REL JUMP"); // TODO: should make this absolute, needs generic function to support it.
    /* update the offset for the STACKLINK */
    update_16_bit_code_word(current_proc_call_stack_link_offset_address, next_instruction_address - current_proc_call_stack_link_offset_address + 1, "return address");
}

void op_org_return(int N)
{
    log(LOG_STRUCTURE, "RETURN operand %s\n", format_operand(N));
    plant_org_order_extended(F_RETURN, k_v(), NP_STACK);
}

void op_org_aconv(int N)
{
    printf("Aconv %s\n", format_basic_type(N));
}

void op_org_set_amode(int N)
{
    amode = N;
    log(LOG_PLANT, "Amode set to %s\n", format_basic_type(N));
}

void op_org_stack(int N)
{
    if (N != OPERAND_REG_A)
    {
        fatal("Can't stack register 0x%04x\n", N);
    }

    log(LOG_PLANT, "%04X STACK register\n", next_instruction_address);
    plant_org_order(F_SF_PLUS, K_LITERAL, 2);
    plant_order_extended(cr(), F_STORE, K_V64, NP_SF);
    write_16_bit_code_word(0);
}

void op_org_jump_equal(int N)
{
    op_org_jump_generic(N, F_BRANCH_EQ, "EQ");
}

void op_org_jump_not_equal(int N)
{
    op_org_jump_generic(N, F_BRANCH_NE, "NE");
}

void op_org_jump_greater_than_or_equal(int N)
{
    op_org_jump_generic(N, F_BRANCH_GE, "GE");
}

void op_org_jump_less_than(int N)
{
    op_org_jump_generic(N, F_BRANCH_LT, "LT");
}

void op_org_jump_less_than_or_equal(int N)
{
    op_org_jump_generic(N, F_BRANCH_LE, "LE");
}

void op_org_jump_greater_than(int N)
{
    op_org_jump_generic(N, F_BRANCH_GT, "GT");
}

void op_org_jump_seg(int N)
{
    if (mutl_var[N].data.label.address_defined)
    {
        int16 relative = mutl_var[N].data.label.address - next_instruction_address;
        log(LOG_PLANT, "%04X ORG JUMP SEG to %s relative %d\n", next_instruction_address, mutl_var[N].name, relative);
        if (relative >= -32 && relative < 32)
        {
            plant_org_order(F_RELJUMP, K_LITERAL, relative & 0x3F);
        }
        else
        {
            plant_org_order_extended(F_RELJUMP, KP_LITERAL, NP_16_BIT_SIGNED_LITERAL);
            write_16_bit_code_word(relative);
        }
    }
    else
    {
        log(LOG_PLANT, "%04X ORG JUMP SEG to %s forward ref\n", next_instruction_address, mutl_var[N].name);
        plant_org_order_extended(F_RELJUMP, KP_LITERAL, NP_16_BIT_SIGNED_LITERAL);
        register_forward_label_ref(N);
        write_16_bit_code_word(0); /* place holder */
    }
}

static MUTLOP mutl_ops[32][4] =
{
    { NULL, op_a_store, op_org_stack_link, NULL },
    { NULL, op_a_load_neg_or_ref, op_org_stack_parameter, NULL },
    { NULL, op_a_load, op_org_enter, NULL },
    { NULL, op_a_xor, op_org_return, NULL },
    { NULL, op_a_and, NULL, NULL },
    { NULL, op_a_or, op_org_aconv, NULL },
    { NULL, op_a_left_shift, op_org_set_amode, NULL },
    { NULL, NULL, op_org_stack, NULL },
    { NULL, op_a_add, NULL, NULL },
    { NULL, op_a_sub, op_org_jump_equal, NULL },
    { NULL, NULL, op_org_jump_not_equal, NULL },
    { NULL, op_a_mul, op_org_jump_greater_than_or_equal, NULL },
    { NULL, op_a_div, op_org_jump_less_than, NULL },
    { NULL, NULL, op_org_jump_less_than_or_equal, NULL },
    { NULL, NULL, op_org_jump_greater_than, NULL },
    { NULL, op_a_compare, op_org_jump_seg, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, op_a_add_store, NULL, NULL },
    { NULL, op_a_sub_store, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL }
};

void set_literal_value(t_uint64 val, int size)
{
    t_uint64 temp = val;
    int i;
    for (i = 0; i < size; i++)
    {
        current_literal[i] = (val >> (size - i - 1)) & 0xF;
    }
}

void TLLOAD(int SN, int AN)
{
    log(LOG_MEMORY, "TL.LOAD segment %d area %d\n", SN, AN);
    areas[AN].segment = SN;
}

void TLCODEAREA(int AN)
{
    /* TODO: currently assumes the whole compile unit is one module and one segment for the code */
    log(LOG_MEMORY, "TL.CODE.AREA area %d\n", AN);
    current_code_area = AN;

    update_16_bit_header_word(0, areas[AN].segment, "code segment updated");
}

void TLDATAAREA(int AN)
{
    log(LOG_MEMORY, "TL.DATA.AREA area %d\n", AN);
    current_data_area = AN;
    plant_org_order_extended(F_SN_LOAD, KP_LITERAL, NP_16_BIT_UNSIGNED_LITERAL);
    write_16_bit_code_word(areas[current_data_area].segment);
    log(LOG_PLANT, "%04X Load SN=0x%04x\n", next_instruction_address, areas[current_data_area].segment);
}

void TL(int M, char *FN, int DZ)
{
    out_file = fopen(FN, "wb");
}

void TLEND(void)
{
    fclose(out_file);
}

void TLMODULE(void)
{
    /* Write module header. This format is specific to the MU5 emulator */
    write_16_bit_header_word(areas[0].segment);
    write_16_bit_header_word(0); /* place holder for segment length */

    start_block_level(0);
}

void TLENDMODULE(int ST)
{
    end_block_level();
    update_16_bit_header_word(1, areas[current_code_area].size, "module length");
}

void declare_variable(VECTOR *name, uint8 T, int D, int is_parameter, int is_vstore)
{
    MUTLSYMBOL *var;
    int nb_offset;
    int var_n;

    if (!is_vstore)
    {
        var_n = add_block_var(T, is_parameter);
    }
    else
    {
        var_n = add_other_block_item();
    }
    var = &mutl_var[var_n];

    var->symbol_type = SYM_VARIABLE;
    vecstrcpy(var->name, name, sizeof(var->name));
    var->symbol_type = SYM_VARIABLE;
    var->block_level = block_level;
    var->data.var.data_type = T;
    var->data.var.dimension = D;
    var->data.var.is_vstore = is_vstore;

    if (!is_vstore)
    {
        var->data.var.position = get_block_name_offset_for_last_var(T, is_parameter);
        log(LOG_SYMBOLS, "Declare var %s %s level=%d, dim=%d, offset=%d in slot %d\n", var->name, format_basic_type(T), block_level, D, var->data.var.position, var_n);
    }
    else
    {
        var->data.var.position = get_current_literal();
        log(LOG_SYMBOLS, "Declare vstore %s %s level=%d, dim=%d, position=0x%X in slot %d\n", var->name, format_basic_type(T), block_level, D, var->data.var.position, var_n);
    }
}

void TLSDECL(VECTOR *SN, int T, int D)
{
    VECTOR name;
    if (SN != NULL)
    {
        memcpy(&name, SN, sizeof(VECTOR));
    }
    else
    {
        name.first = "(internal)";
        name.length = strlen(name.first);
    }

    declare_variable(&name, T, D, 0, 0);
}

void TLVDECL(VECTOR *SN, uint32 SA, int RS, int WS, int T, int D)
{
    if (SA != 0)
    {
        fatal("Expected TL.V.DECL to be called with a literal for the position\n");
    }

    declare_variable(SN, T, D, 0, 1);
}

void TLPROCSPEC(VECTOR *NAM, int NAT)
{
    MUTLSYMBOL *sym = &mutl_var[add_other_block_item()];
    current_proc_spec = &sym->data.proc;
    sym->symbol_type = SYM_PROC;
    vecstrcpy(sym->name, NAM, sizeof(sym->name));
    log(LOG_SYMBOLS, "Declare proc %s, nature=0x%04X\n", sym->name, NAT);
}

void TLPROCPARAM(int T, int D)
{
    log(LOG_SYMBOLS, "Declare proc param %s, dim=%d\n", format_basic_type(T), D);
    if (current_proc_spec->param_count < MAX_PROC_PARAMS)
    {
        current_proc_spec->parameters[current_proc_spec->param_count].data_type = T;
        current_proc_spec->parameters[current_proc_spec->param_count].dimension = D;
        current_proc_spec->param_count++;
    }
    else
    {
        fatal("Too many parameters for procedure\n");
    }
}

void TLPROCRESULT(int R, int D)
{
    if (R != 0)
    {
        log(LOG_SYMBOLS, "Declare proc result %s, dim=%d\n", format_basic_type(R), D);
    }
    /* TODO. Process this. */
}

void TLPROC(int P)
{
    int i;
    current_proc_def = &mutl_var[P];
    PROCSYMBOL *proc_def_var = &current_proc_def->data.proc;
    log(LOG_STRUCTURE, "Define proc %s at 0x%04X\n", current_proc_def->name, next_instruction_address);
    proc_def_var->address_defined = 1;
    proc_def_var->address = next_instruction_address;

    fixup_forward_label_refs(P);
    start_block_level(param_stack_size(P));
    for (i = 0; i < proc_def_var->param_count; i++)
    {
        declare_variable("(param)", proc_def_var->parameters[i].data_type, proc_def_var->parameters[i].dimension, 1, 0);
    }
}

void TLPROCKIND(int K)
{
    log(LOG_STRUCTURE, "Define proc kind 0x%04X\n", K);
}

void TLENDPROC(void)
{
    log(LOG_STRUCTURE, "End proc\n");
    end_block_level();
}

void TLBLOCK(void)
{
    log(LOG_STRUCTURE, "Start block\n");
}

void TLENDBLOCK(void)
{
    log(LOG_STRUCTURE, "End block\n");
}
void TLENTRY(int N)
{
    log(LOG_STRUCTURE, "Enter proc %s\n", mutl_var[N].name);
}
void TLLABELSPEC(VECTOR *N, int U)
{
    char temp[80];
    int sym_n;

    sym_n = add_other_block_item();
    MUTLSYMBOL *sym = &mutl_var[sym_n];
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

void TLLABEL(int L)
{
    log(LOG_SYMBOLS, "Define label %s at 0x%04X\n", mutl_var[L].name, next_instruction_address);
    mutl_var[L].data.label.address_defined = 1;
    mutl_var[L].data.label.address = next_instruction_address;
    fixup_forward_label_refs(L);
}

void TLCLIT16(int BT, int16 VAL)
{
    set_literal_value(VAL, sizeof(int16));
    current_literal_basic_type = BT;
}

void TLCLIT32(int BT, int32 VAL)
{
    set_literal_value(VAL, sizeof(int32));
    current_literal_basic_type = BT;
}

void TLCLIT64(int BT, t_uint64 VAL)
{
    set_literal_value(VAL, sizeof(t_uint64));
    current_literal_basic_type = BT;
}

void TLCNULL(int PT)
{
    fatal("TL.C.NULL not supported\n");
}

void TLCLITS(int BT, VECTOR *VAL)
{
    int len = BT_SIZE(BT);
    int i;

    memcpy(current_literal, VAL->first, VAL->length);

    current_literal_basic_type = BT;
    log(LOG_LITERALS, "Current literal is");
    for (i = 0; i < VAL->length; i++)
    {
        log(LOG_LITERALS, " %02X", current_literal[i]);
    }
    log(LOG_LITERALS, "\n");
}

void TLCLIT128(int BT, double VAL)
{
    fatal("TL.C.LIT128 not supported\n");
}

void TLLIT(VECTOR *SN, int K)
{
    fatal("TL.LIT not supported\n");
}

void TLPL(int F, int N)
{
    int data_type = F >> 5;
    int opcode = F & 0x1F;
    void(*op)(int) = NULL;
    op = mutl_ops[opcode][data_type].op;
    if (op != NULL)
    {
        op(N);
    }
    else
    {
        printf("Plant type=%d op=0x%X n=0x%X\n", data_type, opcode, N);
    }
}

LOOP *start_loop(int mode, int control_variable)
{
    LOOP *loop;
    loop_level++;
    if (loop_level >= MAX_LOOP_DEPTH)
    {
        fatal("Exceed loop nesting depth\n");
    }

    loop = &loop_stack[loop_level];
    loop->address_of_condition = next_instruction_address;
    loop->mode = mode;
    loop->control_variable = control_variable;

    return loop;
}

void end_loop(void)
{
    loop_level--;
}

void TLCYCLE(int limit)
{
    LOOP *loop;
    log(LOG_PLANT, "TL.CYCLE\n");
    op_org_set_amode(TINT32);
    op_a_load(limit);
    op_org_stack(OPERAND_REG_A);
    loop = start_loop(1, OPERAND_POP);
    TLCLIT32(TINT32, 0);
    op_a_compare(OPERAND_LITERAL);
    loop->address_of_end_of_loop_jump = op_org_jump_generic_address(F_BRANCH_LE, UNKNOWN_ADDRESS);
}

void TLCVCYCLE(int cv, int init, int mode)
{
    log(LOG_PLANT, "TL.CV.CYCLE, mode=%d\n", mode);
    op_a_load(init);
    op_a_store(cv);
    start_loop(mode, cv);
}

void TLCVLIMIT(int limit)
{
    /* This code assumes the FOR loop is always of the form "FOR N < 10". In other words the operator is always LESS THAN only.
       The compiler does not seem to tell MUTL if the operator is any different. */
    LOOP *loop = &loop_stack[loop_level];
    log(LOG_PLANT, "TL.CV.LIMIT %s\n", format_operand(limit));

    if (limit != OPERAND_REG_A)
    {
        op_a_load(limit);
    }

    op_a_compare(loop->control_variable);
    if ((loop->mode & 1) == 0)
    {
        loop->address_of_end_of_loop_jump = op_org_jump_generic_address(F_BRANCH_LE, UNKNOWN_ADDRESS);
    }
    else
    {
        loop->address_of_end_of_loop_jump = op_org_jump_generic_address(F_BRANCH_GT, UNKNOWN_ADDRESS);
    }
}

void TLREPEAT(void)
{
    int relative;
    LOOP *loop = &loop_stack[loop_level];
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
    relative = loop->address_of_condition - next_instruction_address;
    op_org_jump_generic_address(F_RELJUMP, relative);

    relative = next_instruction_address - loop->address_of_end_of_loop_jump + 1;
    update_16_bit_code_word(loop->address_of_end_of_loop_jump, relative, "end of loop address");
    end_loop();
    if (loop->control_variable == OPERAND_POP)
    {
        op_a_load(OPERAND_POP); /* remove control variable from the stack */
    }
}


