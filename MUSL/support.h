#pragma once
#include <stdio.h>

typedef unsigned char      uint8;
typedef short              int16;
typedef unsigned short     uint16;
typedef int                int32;
typedef unsigned int       uint32;
typedef long long          t_int64;
typedef unsigned int       uint32;
typedef unsigned long long t_uint64;

typedef struct
{
    char *buffer;
    uint16 length;
} VECTOR;

void SELECTINPUT(FILE *f);
void SELECTOUTPUT(FILE *f);
FILE *DEFINEINPUT(int StreamNumber, char *FileName, int Mode); /* CH3UM */
FILE *CURRENTOUTPUT(void);
FILE *CURRENTINPUT(void);
void ENDINPUT(FILE *, int);

void OVERLAY(int);

int INCH(void);
void OUTCH(int ch);
int NEXTCH(void);
void NEWLINES(int);
void OUTHEX(int, int);
void SPACES(int);

void PPCCMD(void);

void INBACKSPACE(int);
void TLLINE(int);
void OUTLINENO(int);

unsigned int FINDN(VECTOR *, int);
VECTOR *PART(unsigned char *, int, int);
void TLPRINT(int);
void CAPTION(char *);
uint16 FINDP(unsigned int, int, int);
void TLCYCLE(uint16);
void TLCVCYCLE(uint16, uint16, int);
void TLCVLIMIT(uint16);
void TLREPEAT(void);

extern int BOPD;
extern int AOPD;
typedef int                int32;

void OUTI(int32, int);
void OUTBINB(int);
char *format_basic_type(uint16 bt);
int DumpAR(uint16 AR[], int ap, int level);
