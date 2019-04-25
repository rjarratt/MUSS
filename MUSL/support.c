#include <stdio.h>
#include <memory.h>
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

VECTOR *PART(char *vec, int first, int last)
{
    static VECTOR result;
    result.first = &vec[first];
    result.length = last - first + 1;
    return &result;
}

void CAPTION(char *msg)
{
    printf("%s\n", msg);
}

int FINDP(char *name, int first, int last)
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

extern void MUSL(char *file, char *PROG, int CMPMODE, int DIR);
int main(int argc, char *argv[])
{
    MUSL(argv[1], argv[2], 0x200 /* 32 bit */, 0);
}