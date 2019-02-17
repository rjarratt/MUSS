#include <stdio.h>
#include "support.h"
static FILE *CurrentInputStream;
static FILE *CurrentOutputStream;
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
    return fopen(FileName, "r");
}

FILE *CURRENTOUTPUT(void)
{
    return CurrentOutputStream;
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
    char result;
    fscanf(CurrentInputStream, "%c", &result);
    return result;
}

void OUTCH(int ch)
{
    LastCh = ch;
    fprintf(CurrentOutputStream, "%c", ch);
}
int NEXTCH(void)
{
    char result;
    fscanf(CurrentInputStream, "%c", &result);
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
