#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "support.h"
#include "mu5_mutl.h"
static FILE *CurrentInputStream = NULL;
static FILE *CurrentOutputStream = NULL;
static int LastCh;

void SELECTINPUT(FILE *f)
{
    CurrentInputStream = f;
}

void SELECTOUTPUT(FILE *f)
{
    CurrentOutputStream = f;
    //CurrentOutputStream = stderr;
}

FILE *DEFINEINPUT(int StreamNumber, char *FileName, int Mode)
{
    FILE *result = fopen(FileName, "r");
    if (result == NULL)
    {
        perror("Input file could not be opened");
        exit(0);
    }

    return result;
}

FILE *CURRENTOUTPUT(void)
{
    FILE *result = CurrentOutputStream;
    if (CurrentOutputStream == NULL)
    {
        result = stderr;
    }

    return result;
}

FILE *CURRENTINPUT(void)
{
    return CurrentInputStream;
}

void ENDINPUT(FILE *f, int mode)
{
    fclose(f);
}

void OVERLAY(int n)
{
    // Don't know what this does.
}

int INCH(void)
{
    int result = fgetc(CurrentInputStream);
    return result;
}

void OUTCH(int ch)
{
    LastCh = ch;
    fputc(ch, CurrentOutputStream);
}

int NEXTCH(void)
{
    char result = INCH();
    INBACKSPACE(1);
    return result;
}

void NEWLINES(int n)
{
    if (LastCh != '\n')
    {
        n = n + 1;
    }

    for (size_t i = 0; i < n; i++)
    {
        fprintf(CurrentOutputStream, "\n");
    }
}

void OUTHEX(int number, int digits)
{
    fprintf(CurrentOutputStream, "%0*X", digits, number);
}

void SPACES(int n)
{
    for (int i = 0; i < n; i++)
    {
        fprintf(CurrentOutputStream, " ");
    }
}

void PPCCMD(void)
{
}

void INBACKSPACE(int n)
{
    fseek(CurrentInputStream, -n, SEEK_CUR);
}

void OUTLINENO(int n)
{
}

char *FINDN(VECTOR *name, int kind)
{
    printf("FINDN not implemented\n");
    exit(0);
    // see lib022
    return NULL;
}

VECTOR *PART(char *vec, int buffer, int last)
{
    static VECTOR result;
    result.buffer = &vec[buffer];
    result.length = last - buffer + 1;
    return &result;
}

void CAPTION(char *msg)
{
    printf("%s\n", msg);
}

int FINDP(char *name, int buffer, int last)
{
    return 0;
}

int BOPD;
int AOPD;

void OUTI(int32 number, int field)
{
    printf("%*d", field, number);
}

void OUTBINB(int n)
{
    //printf("%02X", n & 0xFF);
}

char *format_basic_type(uint16 bt)
{
    static char buf[80];
    char *modes[] = { "Real", "Signed Int", "Unsigned Int", "Decimal" };
    char *relates_to[] = { "", " pointer to", "", " bounded pointer to" };
    sprintf(buf, "(%04X)%s%s%s%s Mode=%s bytes=%d",
        bt,
        (BT_NOTDEF(bt)) ? " NotDef" : "",
        (BT_IS_EXPORT(bt)) ? " Export" : "",
        (BT_IS_IMPORT(bt)) ? " Import" : "",
        relates_to[BT_PTR_TO(bt)],
        modes[BT_MODE(bt)],
        BT_SIZE(bt));
    return buf;
}


int DumpAR(uint16 AR[], int ap, int level)
{
    static char *opkind[] = { "Named item", "Literal", "Negated Literal", "Proc call", "Lib proc call", "Sub expression", "Conditional", "Built in func", "String", "Proc call by var" };
    int i;
    uint16 kind = AR[ap];
    int is_operator;
    printf("%0.*sStart of Analysis Record\n", level*2, " ");
    printf("%0.*sKind -", level * 2, " ");
    if ((kind & 0x100) != 0)
    {
        printf(" Comparison");
    }
    if ((kind & 0x80) != 0)
    {
        printf(" SingleOperand");
    }
    if ((kind & 0x40) != 0)
    {
        printf(" DestroysD");
    }
    if ((kind & 0x20) != 0)
    {
        printf(" DestroysA");
    }
    if ((kind & 0x10) != 10)
    {
        printf(" DestroysB");
    }
    printf("\n");
    printf("%0.*sType %s\n", level * 2, " ", format_basic_type(AR[ap + 1]));

    i = ap + 1;
    is_operator = 1;
    while (AR[++i] != 0)
    {
        uint16 word = AR[i];
        if (is_operator && (word & 0x8000) != 0)
        {
            printf("%0.*sOperator: Switch type to %s\n", level * 2, " ", format_basic_type(word & 0x7F));
            is_operator = 1;
        }
        else if (is_operator)
        {
            if (word == 0x7F)
            {
                printf("%0.*sOperator: Deref\n", level * 2, " ");
            }
            else if (word == 0x7E)
            {
                printf("%0.*sOperator: Subscript. D reg type %s\n", level * 2, " ", format_basic_type(AR[++i]));
                i = DumpAR(AR, i, level + 1);
            }
            else
            {
                printf("%0.*sOperator: %d\n", level * 2, " ", word);
            }
            is_operator = 0;
        }
        else
        {
            switch (word & 0xF)
            {
                case 0:
                    printf("%0.*sOperand: Named item", level * 2, " ");
                    if (word & 0x80)
                    {
                        printf(", Ref to var reqd");
                    }
                    if (word & 0x40)
                    {
                        printf(", Uses D");
                    }
                    if (word & 0x20)
                    {
                        printf(", Uses A");
                    }
                    if (word & 0x10)
                    {
                        printf(", Uses B");
                    }
                    printf(". MUTL name %d\n", AR[++i]);
                    break;
                case 1:
                    printf("%0.*sOperand: Literal %s, position in CLIST=%d\n", level * 2, " ", format_basic_type(word >> 4), AR[++i]);
                    break;
                case 2:
                    printf("%0.*sOperand: Negated iteral %s, position in CLIST=%d\n", level * 2, " ", format_basic_type(word >> 4), AR[++i]);
                    break;
                default:
                    printf("%0.*sOperand: %s (%d)\n", level * 2, " ", opkind[word & 0xF], word);
                    break;
            }
            is_operator = 1;
        }
    }
    printf("%0.*sEnd of Analysis Record\n", level * 2, " ");
    return i;
}
extern void MUSL(char *file, char *PROG, int CMPMODE, int DIR);
int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("nmsl infile outfile [-i import] [-l logginglevel]");
    }
    else
    {
        int arg = 3;
        while (arg < argc)
        {
            if (strcmp(argv[arg], "-l") == 0)
            {
                arg++;
                if (arg < argc)
                {
                    set_logging(atoi(argv[arg++]));
                }
                else
                {
                    printf("Missing logging level");
                    exit(0);
                }
            }
            else
            {
                arg++;
            }
        }

        arg = 3;
        while (arg < argc)
        {
            if (strcmp(argv[arg], "-i") == 0)
            {
                arg++;
                if (arg < argc)
                {
                    import_module(argv[arg++]);
                }
                else
                {
                    printf("Missing module file name");
                    exit(0);
                }
            }
            else
            {
                arg++;
            }
        }

        MUSL(argv[1], argv[2], 0x200 /* 32 bit */, 0);
    }
}