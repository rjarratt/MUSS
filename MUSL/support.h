#include <stdio.h>
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