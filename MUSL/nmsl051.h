#pragma once
#include "support.h"
#include "nmsl021.h"

#define KPSPEC 1
#define KPROC 3
#define KFIELD 5
#define KSPACE 8

extern int LASTMN;
extern int CURLEV;
extern int CURRES;
extern int CURPROC;
extern int CURBLK;
extern int GLEV;
extern int PROCLEV;

extern int TLIST[TLISTZ];
extern int PARAMS[PARAMSZ];

extern void MODHEAD(void);
extern void DECLPROC(int);
extern uint16 ADDLSPEC(uint16);
extern void PROCHEAD(void);
extern void BEGINST(void);
extern void ENDST(void);
extern void INITS5(void);
extern void DECLTYPE(uint32);
extern void DECLVAR(void);
extern void DECLFIELD(void);
extern void DECLSPACE(void);
extern void DECLLIT(void);
extern void DECLLAB(void);
extern void DECLDVEC(void);
extern void DECLIMP(void);
extern void DECLVSTORE(void);
extern void ENDCHECKS(void);
extern int32 EVALLIT(int, int);
extern int32 EVALCONST(void);
extern int COMPTYPE(void);
