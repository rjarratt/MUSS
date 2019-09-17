#pragma once

#define MAXKEYWORD 45
#define KEYWORD 44
#define SDLIST 87

#define TADPROC 0x24

#define TINT0 0x40
#define TLO8 0x80
#define TLO0 0x80
#define TLO1 0x20
#define STRINGTYPE 0x83
#define TINT16 0x44
#define TINT32 0x4C
#define TINT64 0x5C
#define TLO32 0x8C
#define TRE0 0x00
#define TLAB 0x30
#define TDELIM 0
#define TNAME 1
#define TSTRING 2
#define TCONST 3

#define IEOS 0
#define IBYTE 29
#define IMINCOMP 46
#define ILOAD 51
#define ISTORE 61
#define ICOMP 71

typedef struct { unsigned char TAG, ST; unsigned short IND; } ITYPE;

extern uint16 TINT;
extern uint16 TVST;
extern uint16 TLO;
extern uint16 TRE;
extern uint16 TBYADDR;
extern ITYPE LBUFF[LBUFFZ];
extern int IPTR;
extern int SPTR;
extern unsigned char CLIST[CLISTZ];
extern unsigned short DLIST[];
extern unsigned char SBUFF[2000];

extern const ITYPE UMINUS;
extern const ITYPE EOS;
extern const ITYPE LSHIFT;
extern const ITYPE ASTERISK;
extern const ITYPE EOL;
extern const ITYPE DIMPORT;

/* the following are defined centrally here even though in the original code they are conditionally defined in NMSL021 and NMSL031 */
extern const ITYPE DIF;
extern const ITYPE DTHEN;
extern const ITYPE DELSE;
extern const ITYPE DDO;
extern const ITYPE DVSTORE;
extern const ITYPE DTY;
extern const ITYPE DEND;
extern const ITYPE DDATAVEC;
extern const ITYPE DADDR;
extern const ITYPE DLA;
extern const ITYPE DFROM;
extern const ITYPE DOF;
extern const ITYPE DIS;
extern const ITYPE DAND;
extern const ITYPE DOR;
extern const ITYPE LTHAN;
extern const ITYPE EQUALS;
extern const ITYPE GTHAN;
extern const ITYPE PLUS;
extern const ITYPE MINUS;
extern const ITYPE SLASH;
extern const ITYPE GOTO;
extern const ITYPE DAMPAND;
extern const ITYPE DBANG;
extern const ITYPE DEREF;
extern const ITYPE HASH;
extern const ITYPE REF;
extern const ITYPE COMMA;
extern const ITYPE LSB;
extern const ITYPE RSB;
extern const ITYPE LB;
extern const ITYPE RB;
extern const ITYPE BSLASH;
extern const ITYPE XCOLON;
extern const ITYPE COLON;

extern void ITEMISE(int);
extern void INITS3(void);
