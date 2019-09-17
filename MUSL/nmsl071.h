#pragma once

#define AOPD 0x3000
#define DIND 0x1004
#define BREQD ((uint16)-1)

uint16 AR[256];
extern int AP;
extern int FPTR;
extern int STPTR;
extern int REGSIU;

uint16 PREPROCESSCOMP(uint16);
void PREPROCESSCOND(void);
uint16 COMPILECOMP(int16, uint16);
void COMPILECOND(int, int, int);
void COMPILEAND(int, int, int);
void COMPILETEST(int, int, int);
void PRINTAR(void);
