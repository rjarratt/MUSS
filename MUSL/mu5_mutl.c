#include <stdio.h>
#include <string.h>
#include "support.h"

#define FIRST_NAME 2
#define MAX_NAMES 4031
#define MAX_NAME_LEN 32
#define MAX_LITERAL_LEN 256

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

typedef struct { void(*op)(int); } MUTLOP;

typedef struct { char name[MAX_NAME_LEN]; int type; int dimension; int offset;  } MUTLVAR;

static FILE *out_file;
static int amode = 0;
static MUTLVAR mutl_var[MAX_NAMES + 1];
static int last_mutl_var = FIRST_NAME - 1;
static int last_mutl_var_offset = -1;
static uint8 current_literal[MAX_LITERAL_LEN];
static int current_literal_basic_type; /* gives length */

static void print_basic_type(int bt)
{
    char *modes[] = { "Real", "Signed Int", "Unsigned Int", "Decimal" };
    printf("Mode=%s bytes=%d", modes[BT_MODE(bt)], BT_SIZE(bt));
}

static void write_16_bit_word(unsigned int word)
{
    unsigned char byte;
    byte = (word >> 8) & 0xFF;
    fwrite(&byte, 1, 1, out_file);
    byte = word & 0xFF;
    fwrite(&byte, 1, 1, out_file);
}

static uint8 get_operand(uint8 n)
{
    uint8 kp = 0;
    uint8 np = 0;

    if (n == 0)
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
            default:
            {
                printf("Cannot yet generate literal of ");
                print_basic_type(current_literal_basic_type);
                printf("\n");
                exit(1);
                break;
            }
        }
    }
    else
    {
        kp = K_V32;
        np = NP_XNB;
    }

    return kp << 3 | np;
}

static void plant_operand(uint8 n)
{
    if (n == 0)
    {
        switch (BT_MODE(current_literal_basic_type))
        {
            case BT_MODE_UNSIGNED_INTEGER:
            {
                int len = BT_SIZE(current_literal_basic_type);
                t_uint64 literal = 0;
                int i;
                for (i = 0; i < len; i++)
                {
                    literal = literal << 8 | current_literal[i];
                }

                if (len <= 2)
                {
                    write_16_bit_word(literal & 0xFFFF);
                }
                else if (len <= 4)
                {
                    write_16_bit_word((literal >> 16) & 0xFFFF);
                    write_16_bit_word(literal & 0xFFFF);
                }
                else
                {
                    write_16_bit_word((literal >> 48) & 0xFFFF);
                    write_16_bit_word((literal >> 32) & 0xFFFF);
                    write_16_bit_word((literal >> 16) & 0xFFFF);
                    write_16_bit_word(literal & 0xFFFF);
                }
                break;
            }
            default:
            {
                printf("Cannot yet generate literal of ");
                print_basic_type(current_literal_basic_type);
                printf("\n");
                exit(1);
                break;
            }
        }
    }
    else
    {
        MUTLVAR var = mutl_var[n];
        write_16_bit_word(var.offset);
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
    write_16_bit_word(plant_order);
}

static void plant_order_extended_operand(uint8 cr, uint8 f, uint8 n)
{
    uint16 order;
    uint8 operand = get_operand(n);

    order = (cr & 0x7) << 13;
    order |= (f & 0xF) << 9;
    order |= 0x7 << 6;
    order |= operand & 0x3F;
    write_16_bit_word(order);
    plant_operand(n);
}

static void plant_order(uint8 cr, uint8 f, uint8 k, uint8 n)
{
    uint16 order;

    order = (cr & 0x7) << 13;
    order |= (f & 0xF) << 9;
    order |= (k & 0x7) << 6;
    order |= n & 0x3F;
    write_16_bit_word(order);
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
            printf("Cannot handle Real and Decimal\n");
            exit(1);
        }
    }
    return result;
}

void op_a_store(int N)
{
    plant_order_extended_operand(cr(), F_STORE, N);
    //printf("A store to %s\n", mutl_var[N].name);
}

void op_a_load(int N)
{
    if (BT_SIZE(amode) <= 4)
    {
        plant_order_extended_operand(cr(), F_LOAD_32, N);
    }
    else
    {
        plant_order_extended_operand(cr(), F_LOAD_64, N); /* can generate a 64-bit signed load on MU5 which is not valid */
    }
    //printf("A load 0x%X\n", N);
}

void op_a_add(int N)
{
    plant_order_extended_operand(cr(), F_ADD_A, N);
}

void op_a_sub(int N)
{
    plant_order_extended_operand(cr(), F_SUB_A, N);
}

void op_a_mul(int N)
{
    plant_order_extended_operand(cr(), F_MUL_A, N);
}

void op_a_div(int N)
{
    plant_order_extended_operand(cr(), F_DIV_A, N);
}

void op_a_add_store(int N)
{
    op_a_add(N);
    op_a_store(N);
}

void op_org_aconv(int N)
{
    printf("Aconv "); print_basic_type(N); printf("\n");
}

void op_org_set_amode(int N)
{
    amode = N;
    //printf("Amode set to "); print_basic_type(N); printf("\n");
}

static MUTLOP mutl_ops[32][4] =
{
    { NULL, op_a_store, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, op_a_load, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, op_org_aconv, NULL },
    { NULL, NULL, op_org_set_amode, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, op_a_add, NULL, NULL },
    { NULL, op_a_sub, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, op_a_mul, NULL, NULL },
    { NULL, op_a_div, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, op_a_add_store, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL },
    { NULL, NULL, NULL, NULL }
};

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
}

void TLENDMODULE(int ST)
{
}

void TLSDECL(char *SN, int T, int D)
{
    printf("Declare var %s ", SN); print_basic_type(T); printf(" dim=%d\n", D);
    last_mutl_var++;
    strncpy(mutl_var[last_mutl_var].name, SN, MAX_NAME_LEN - 1);
    mutl_var[last_mutl_var].type = T;
    mutl_var[last_mutl_var].dimension = D;
    mutl_var[last_mutl_var].offset = ++last_mutl_var_offset;
}

void TLPROCSPEC(char *NAM, int NAT)
{
    printf("Declare proc %s\n", NAM);
    last_mutl_var++;
}

void TLCLITS(int BT, char *VAL)
{
    int len = BT_SIZE(BT);
    int i;
    memcpy(current_literal, VAL, len);
    current_literal_basic_type = BT;
    printf("Current literal is");
    for (i = 0; i < len; i++)
    {
        printf(" %02X", current_literal[i]);
    }
    printf("\n");
}

void TLPL(int F, int N)
{
    int type = F >> 5;
    int opcode = F & 0x1F;
    void(*op)(int) = NULL;
    op = mutl_ops[opcode][type].op;
    if (op != NULL)
    {
        op(N);
    }
    else
    {
        printf("Plant type=%d op=0x%X n=0x%X\n", type, opcode, N);
    }
}

