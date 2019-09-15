#pragma once
#include "support.h"
#define LBUFFZ 125
#define CLISTZ 1250
#define PLISTZ 320
#define PARAMSZ 270
#define TLISTZ 250
#define NLISTZ 340
#define CHLISTZ 4100
#define KLAB 14
#define KLABREF 15
#define KVAR 4
#define KDUMMY 0
#define KGLAB 13
#define KIMPLAB 16
#define KTREF 9
#define KTYPE 6
#define NIL NULL

typedef struct { unsigned short MUTLN, MUSLN, HASH; } NLISTENT;
typedef struct { unsigned short INTID, PREVN, K, T; int32 DETAIL; } PLISTENT;

extern NLISTENT NLIST[NLISTZ];
extern PLISTENT PLIST[PLISTZ];
extern unsigned char CHLIST[CHLISTZ];
extern unsigned char XNAME[64];
