#include <stdio.h>
#include "support.h"
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
    fprintf(CurrentOutputStream, "%*X", digits, number);
}

void SPACES(int n)
{
    for (size_t i = 0; i < n; i++)
    {
        fprintf(CurrentOutputStream, " ");
    }
}

void PPCCMD(void)
{
    printf("PPCCMD\n");
}

void INBACKSPACE(int n)
{
    fseek(CurrentInputStream, -n, SEEK_CUR);
}

void TLLINE(int line)
{
    printf("TLLINE %d\n", line);
}

void OUTLINENO(int n)
{
    printf("OUTLINENO %d", n);
}

char *FINDN(char *name, int kind)
{
    // see lib022
    return NULL;
}

char *PART(char *vec, int first, int last)
{
    return NULL;
}

void TLPRINT(int mode)
{
    printf("TLPRINT %d\n", mode);
}

void CAPTION(char *msg)
{
    printf("%s\n", msg);
}

int FINDP(char *name, int first, int last)
{
    return 0;
}

void TLCYCLE(int limit)
{

}

void TLCVCYCLE(int cv, int init, int mode)
{

}

void TLCVLIMIT(int limit, int test)
{

}

void TLREPEAT(void)
{

}

int BOPD;
int AOPD;

void OUTI(int32 number, int field)
{

}

void OUTBINB(int n)
{
}

extern void MUSL(char *file, char *PROG, int CMPMODE, int DIR);
int main(int argc, char *argv[])
{
    MUSL(argv[1], argv[2], 0, 0);
}