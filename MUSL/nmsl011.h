#pragma once
#include <stdio.h>
#define CONSTKZ 500
extern FILE *MSTR;
extern FILE *MUTLSTR;
extern int CONSTK[CONSTKZ];
extern int CONPTR;
extern FILE *RESFILE;
extern void RESTART(void);
extern void CEXIT(void);
extern int IX, DIRYZ;
extern void MUSL(char *file, char *PROG, int CMPMODE, int DIR);
