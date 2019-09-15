#pragma once

#define AOPD 0x3000
#define DIND 0x1004
#define BREQD -1

uint16 AR[256];
int AP;
int FPTR;
int STPTR;

int PREPROCESSCOMP(int);
void PREPROCESSCOND(void);
int COMPILECOMP(int, int);
void COMPILECOND(int, int, int);
void COMPILEAND(int, int, int);
void COMPILETEST(int, int, int);
void PRINTAR(void);
