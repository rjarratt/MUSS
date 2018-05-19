/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 98 "musl.y"

#include <stdio.h>
#include <string.h>
#include "musl.h"

extern int yylex();
extern char *yytext;
extern int yylineno;


/* Line 371 of yacc.c  */
#line 79 "musl.tab.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "musl.tab.h".  */
#ifndef YY_YY_MUSL_TAB_H_INCLUDED
# define YY_YY_MUSL_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_ADDR = 258,
     T_AND = 259,
     T_DATAVEC = 260,
     T_DO = 261,
     T_ELSE = 262,
     T_MODULEEND = 263,
     T_END = 264,
     T_FI = 265,
     T_FOR = 266,
     T_IMPORT = 267,
     T_INTEGER = 268,
     T_IF = 269,
     T_IS = 270,
     T_LABEL = 271,
     T_LITERAL = 272,
     T_LOGICAL = 273,
     T_LSPEC = 274,
     T_MODULE = 275,
     T_OD = 276,
     T_OF = 277,
     T_OR = 278,
     T_PROC = 279,
     T_PSPEC = 280,
     T_REAL = 281,
     T_THEN = 282,
     T_TYPE = 283,
     T_VSTORE = 284,
     T_WHILE = 285,
     T_WITHIN = 286,
     T_EQUALS = 287,
     T_NOT_EQUALS = 288,
     T_LT = 289,
     T_GT = 290,
     T_LE = 291,
     T_GE = 292,
     T_COMMA = 293,
     T_COLON = 294,
     T_CIRCUMFLEX = 295,
     T_L_BRACK = 296,
     T_R_BRACK = 297,
     T_L_PAREN = 298,
     T_R_PAREN = 299,
     T_PLUS = 300,
     T_MINUS = 301,
     T_STAR = 302,
     token = 303,
     T_SLASH = 304,
     T_AMPERSAND = 305,
     T_EXCLAMATION = 306,
     T_XOR = 307,
     T_RSUB = 308,
     T_RDIV = 309,
     T_ADDSTORE = 310,
     T_MULSTORE = 311,
     T_DIVSTORE = 312,
     T_ANDSTORE = 313,
     T_ORSTORE = 314,
     T_XORSTORE = 315,
     T_ASSIGN = 316,
     T_RSUBSTORE = 317,
     T_RDIVSTORE = 318,
     T_LLSHIFT = 319,
     T_RLSHIFT = 320,
     T_GOTO = 321,
     T_NAME = 322,
     T_CHAR_CONST = 323,
     T_MULTI_CHAR_CONST = 324,
     T_CH_STRING = 325,
     T_NUMBER = 326
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 110 "musl.y"

    char charval;
    char *stringval;
    char *nameval;
    unsigned int unsignedval;


/* Line 387 of yacc.c  */
#line 201 "musl.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_MUSL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 229 "musl.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   671

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  174
/* YYNRULES -- Number of states.  */
#define YYNSTATES  275

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    11,    14,    17,    18,    20,    22,
      24,    26,    30,    31,    34,    38,    43,    45,    47,    51,
      57,    61,    63,    64,    67,    75,    77,    85,    88,    90,
      92,    97,    99,   101,   105,   107,   109,   111,   113,   115,
     118,   123,   127,   132,   135,   139,   141,   144,   146,   149,
     151,   153,   157,   159,   161,   165,   167,   171,   175,   178,
     180,   185,   189,   191,   193,   195,   198,   203,   208,   213,
     215,   218,   220,   222,   224,   226,   228,   231,   234,   236,
     239,   242,   245,   247,   248,   251,   253,   255,   257,   259,
     261,   263,   265,   267,   269,   271,   273,   275,   277,   281,
     284,   289,   295,   298,   300,   302,   304,   306,   308,   310,
     312,   316,   318,   320,   322,   324,   326,   328,   330,   332,
     334,   336,   338,   340,   342,   344,   346,   348,   350,   352,
     354,   356,   358,   361,   365,   370,   372,   377,   383,   387,
     389,   391,   395,   397,   401,   405,   407,   409,   411,   414,
     418,   421,   423,   425,   427,   429,   431,   433,   437,   439,
     440,   445,   447,   450,   454,   459,   463,   467,   473,   479,
     487,   490,   493,   498,   501
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      73,     0,    -1,    75,    74,    77,   107,     8,    -1,    20,
      -1,    20,    67,    -1,    75,    76,    -1,    -1,    78,    -1,
      91,    -1,    92,    -1,    93,    -1,    41,   100,    42,    -1,
      -1,    79,    67,    -1,    79,    67,    80,    -1,    79,    67,
      32,    67,    -1,    19,    -1,    25,    -1,    41,    81,    42,
      -1,    41,    81,    42,    49,   101,    -1,    81,    38,   101,
      -1,   101,    -1,    -1,    17,    83,    -1,    49,     3,    43,
      84,    44,    67,    32,    -1,    99,    -1,     5,    67,    41,
     101,    42,    86,     9,    -1,    86,    87,    -1,    87,    -1,
      88,    -1,    88,    43,   102,    44,    -1,    89,    -1,   102,
      -1,   102,    90,    89,    -1,    45,    -1,    46,    -1,    50,
      -1,    47,    -1,    49,    -1,    28,    67,    -1,    28,    67,
      15,    97,    -1,    28,    67,   102,    -1,    31,    67,    15,
      97,    -1,    99,   100,    -1,    12,    94,    95,    -1,    17,
      -1,    17,   105,    -1,    29,    -1,    29,   105,    -1,    28,
      -1,    16,    -1,    95,    38,    96,    -1,    96,    -1,    67,
      -1,    67,    43,    44,    -1,    98,    -1,    98,    23,    97,
      -1,    98,    99,   100,    -1,    99,   100,    -1,   101,    -1,
     101,    43,   102,    44,    -1,   100,    38,    67,    -1,    67,
      -1,   105,    -1,    67,    -1,     3,   105,    -1,     3,    43,
     105,    44,    -1,     3,    43,    67,    44,    -1,     3,    43,
       3,    44,    -1,     3,    -1,     3,     3,    -1,   103,    -1,
     104,    -1,    69,    -1,    70,    -1,    71,    -1,    45,    71,
      -1,    46,    71,    -1,    68,    -1,    13,   106,    -1,    26,
     106,    -1,    18,   106,    -1,    71,    -1,    -1,   107,   108,
      -1,   108,    -1,   109,    -1,   110,    -1,   111,    -1,   113,
      -1,    92,    -1,    78,    -1,    82,    -1,    85,    -1,    91,
      -1,    93,    -1,   114,    -1,   115,    -1,   112,   107,     9,
      -1,    24,    67,    -1,    24,    67,    41,    42,    -1,    24,
      67,    41,   100,    42,    -1,    67,    39,    -1,   116,    -1,
     131,    -1,   132,    -1,   133,    -1,   134,    -1,   117,    -1,
     119,    -1,   119,   118,   117,    -1,    45,    -1,    46,    -1,
      47,    -1,    49,    -1,    50,    -1,    51,    -1,    52,    -1,
      53,    -1,    54,    -1,    55,    -1,    56,    -1,    57,    -1,
      58,    -1,    59,    -1,    60,    -1,    61,    -1,    62,    -1,
      63,    -1,    64,    -1,    65,    -1,   129,    -1,    40,   129,
      -1,   129,    22,   120,    -1,    40,   129,    22,   120,    -1,
     102,    -1,    67,    41,   127,    42,    -1,    67,    40,    41,
     127,    42,    -1,    41,   116,    42,    -1,   128,    -1,   129,
      -1,   129,    22,   120,    -1,   122,    -1,   122,   123,   121,
      -1,    43,   121,    44,    -1,   124,    -1,    23,    -1,     4,
      -1,   116,   125,    -1,   126,   116,   125,    -1,   126,   116,
      -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,    36,
      -1,    37,    -1,   127,    38,   116,    -1,   116,    -1,    -1,
      67,    41,   100,    42,    -1,    67,    -1,    67,   130,    -1,
      67,    40,   130,    -1,    67,   130,    40,   130,    -1,    43,
     116,    44,    -1,    14,   121,   135,    -1,    30,   121,     6,
     107,    21,    -1,    11,   116,     6,   107,    21,    -1,    11,
      67,    34,   116,     6,   107,    21,    -1,    66,    67,    -1,
      38,   134,    -1,    27,   107,   136,    10,    -1,     7,   107,
      -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   120,   120,   122,   122,   123,   123,   123,
     123,   125,   125,   128,   130,   132,   134,   136,   138,   140,
     142,   142,   142,   151,   153,   154,   156,   157,   157,   158,
     158,   159,   160,   160,   161,   161,   161,   161,   161,   164,
     166,   168,   170,   172,   174,   176,   178,   180,   182,   184,
     186,   188,   188,   190,   192,   194,   194,   195,   195,   197,
     197,   199,   199,   202,   204,   206,   210,   212,   214,   216,
     218,   220,   220,   220,   220,   221,   221,   221,   222,   225,
     227,   229,   231,   231,   233,   233,   235,   235,   235,   237,
     237,   237,   237,   237,   237,   237,   239,   239,   241,   242,
     242,   242,   244,   246,   246,   246,   246,   248,   250,   251,
     251,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   255,   257,   259,   261,   263,   265,   267,   269,   271,
     272,   272,   274,   274,   275,   275,   276,   276,   278,   279,
     279,   280,   280,   280,   280,   280,   280,   282,   282,   282,
     283,   286,   286,   286,   286,   287,   289,   290,   291,   291,
     292,   294,   294,   295,   295
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ADDR", "T_AND", "T_DATAVEC", "T_DO",
  "T_ELSE", "T_MODULEEND", "T_END", "T_FI", "T_FOR", "T_IMPORT",
  "T_INTEGER", "T_IF", "T_IS", "T_LABEL", "T_LITERAL", "T_LOGICAL",
  "T_LSPEC", "T_MODULE", "T_OD", "T_OF", "T_OR", "T_PROC", "T_PSPEC",
  "T_REAL", "T_THEN", "T_TYPE", "T_VSTORE", "T_WHILE", "T_WITHIN",
  "T_EQUALS", "T_NOT_EQUALS", "T_LT", "T_GT", "T_LE", "T_GE", "T_COMMA",
  "T_COLON", "T_CIRCUMFLEX", "T_L_BRACK", "T_R_BRACK", "T_L_PAREN",
  "T_R_PAREN", "T_PLUS", "T_MINUS", "T_STAR", "token", "T_SLASH",
  "T_AMPERSAND", "T_EXCLAMATION", "T_XOR", "T_RSUB", "T_RDIV",
  "T_ADDSTORE", "T_MULSTORE", "T_DIVSTORE", "T_ANDSTORE", "T_ORSTORE",
  "T_XORSTORE", "T_ASSIGN", "T_RSUBSTORE", "T_RDIVSTORE", "T_LLSHIFT",
  "T_RLSHIFT", "T_GOTO", "T_NAME", "T_CHAR_CONST", "T_MULTI_CHAR_CONST",
  "T_CH_STRING", "T_NUMBER", "$accept", "module", "start_module",
  "imports", "import", "exports", "proc_dec", "proc_dec_spec", "pspec",
  "t_list", "lit_dec", "pointer_lit", "any_type", "data_vec", "literals",
  "literal_item", "literal", "const_expr", "const_op", "type_dec",
  "var_dec", "import_dec", "kind", "imp_list", "imp_list_item",
  "structure", "fields", "type", "name_list", "scalar_type", "const",
  "dec_integer", "char_const", "numeric_type", "size", "statements",
  "statement", "declarative_statement", "imperative_statement",
  "proc_defn", "proc_heading", "label_dec", "comp_st", "control_st",
  "computation", "opr_opd_seq", "operator", "operand", "context",
  "condition", "test", "logop", "comparison", "compare_list", "comparator",
  "p_list", "built_in_function", "variable", "subscript", "if_st",
  "while_st", "for_st", "go_st", "action", "else_cl", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    74,    75,    75,    76,    76,    76,
      76,    77,    77,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    81,    82,    83,    84,    85,    86,    86,    87,
      87,    88,    89,    89,    90,    90,    90,    90,    90,    91,
      91,    91,    91,    92,    93,    94,    94,    94,    94,    94,
      94,    95,    95,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   101,   101,   101,   101,
     101,   102,   102,   102,   102,   103,   103,   103,   104,   105,
     105,   105,   106,   106,   107,   107,   108,   108,   108,   109,
     109,   109,   109,   109,   109,   109,   110,   110,   111,   112,
     112,   112,   113,   114,   114,   114,   114,   115,   116,   117,
     117,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   125,
     125,   126,   126,   126,   126,   126,   126,   127,   127,   127,
     128,   129,   129,   129,   129,   130,   131,   132,   133,   133,
     134,   135,   135,   136,   136
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     1,     2,     2,     0,     1,     1,     1,
       1,     3,     0,     2,     3,     4,     1,     1,     3,     5,
       3,     1,     0,     2,     7,     1,     7,     2,     1,     1,
       4,     1,     1,     3,     1,     1,     1,     1,     1,     2,
       4,     3,     4,     2,     3,     1,     2,     1,     2,     1,
       1,     3,     1,     1,     3,     1,     3,     3,     2,     1,
       4,     3,     1,     1,     1,     2,     4,     4,     4,     1,
       2,     1,     1,     1,     1,     1,     2,     2,     1,     2,
       2,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     2,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     3,     4,     1,     4,     5,     3,     1,
       1,     3,     1,     3,     3,     1,     1,     1,     2,     3,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     0,
       4,     1,     2,     3,     4,     3,     3,     5,     5,     7,
       2,     2,     4,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     1,    69,     0,    83,    83,    16,     3,
      17,    83,     0,     0,    64,    12,     5,     7,     0,     8,
       9,    10,     0,    59,    63,    70,     0,    65,    50,    45,
      49,    47,     0,    82,    79,    81,     4,    80,    39,     0,
       0,     0,    13,    62,    43,     0,     0,     0,     0,    46,
      48,    53,    44,    52,     0,     0,     0,    78,    73,    74,
      75,    41,    71,    72,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   161,    91,    92,    93,    94,
      90,    95,   135,     0,    85,    86,    87,    88,     0,    89,
      96,    97,   103,   108,   109,   139,   131,   104,   105,   106,
     107,     0,    22,    14,     0,     0,    68,    67,    66,     0,
       0,    40,    55,     0,    76,    77,    42,    11,     0,   161,
       0,     0,   161,     0,     0,   142,   145,     0,    23,    99,
       0,   161,   132,     0,   170,   102,     0,   159,     0,   162,
       2,    84,     0,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,     0,     0,    15,     0,    21,    61,    60,
      54,    51,     0,     0,    58,     0,     0,     0,     0,   151,
     152,   153,   154,   155,   156,   148,     0,     0,     0,   166,
     147,   146,     0,     0,     0,     0,     0,     0,   138,   159,
     163,   161,     0,   158,     0,     0,     0,    98,   110,   133,
     140,     0,    18,    56,    57,     0,     0,     0,   144,   150,
     174,   171,   143,     0,   100,     0,     0,   134,     0,   160,
       0,   136,   165,   164,     0,    20,     0,     0,     0,   168,
     149,     0,     0,     0,    25,   101,   167,   137,   157,   141,
      19,     0,    28,    29,    31,    32,     0,   173,   172,     0,
      26,    27,     0,    34,    35,    37,    38,    36,     0,   169,
       0,     0,    33,    24,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    15,     2,    16,    41,    76,    18,   103,   166,
      77,   128,   243,    78,   251,   252,   253,   254,   268,    79,
      80,    81,    32,    52,    53,   111,   112,    22,    44,    23,
      82,    62,    63,    24,    34,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,   163,    94,   209,   124,
     125,   192,   126,   185,   186,   204,    95,    96,   139,    97,
      98,    99,   100,   189,   242
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -183
static const yytype_int16 yypact[] =
{
    -183,    23,    14,  -183,    54,   169,   -53,   -53,  -183,   -32,
    -183,   -53,   -14,    -4,  -183,    37,  -183,  -183,    16,  -183,
    -183,  -183,    26,    53,  -183,  -183,    25,  -183,  -183,    93,
    -183,    93,    43,  -183,  -183,  -183,  -183,  -183,    80,    84,
      26,   579,    41,  -183,    77,    85,    73,    88,   103,  -183,
    -183,    81,    99,  -183,    51,    87,    92,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,    51,   104,   113,   226,   -21,   117,
     114,   -21,   120,   242,   134,    61,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,   165,  -183,  -183,  -183,  -183,   579,  -183,
    -183,  -183,  -183,  -183,   606,  -183,   130,  -183,  -183,  -183,
    -183,   135,    51,  -183,   142,   176,  -183,  -183,  -183,   177,
      43,  -183,    18,    26,  -183,  -183,  -183,  -183,   153,   100,
     216,   -21,   201,   182,    32,    33,  -183,   168,  -183,   188,
     232,    28,   218,   207,  -183,  -183,    64,   295,   242,   210,
    -183,  -183,   234,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,   242,   120,  -183,   119,  -183,  -183,  -183,
    -183,  -183,    51,    26,    77,    51,   242,   579,   211,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,   242,   579,   190,  -183,
    -183,  -183,   -21,   214,   -12,   579,   220,   120,  -183,   242,
    -183,   185,   127,  -183,   150,   217,   220,  -183,  -183,  -183,
     246,    51,   205,  -183,    77,   227,   264,   303,  -183,   182,
     372,  -183,  -183,    51,  -183,   162,   441,  -183,   170,  -183,
     242,  -183,  -183,  -183,   120,  -183,    51,    85,   579,  -183,
    -183,   579,   263,   233,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,    20,  -183,   235,  -183,   305,   510,   579,  -183,   209,
    -183,  -183,    85,  -183,  -183,  -183,  -183,  -183,    85,  -183,
     249,   240,  -183,  -183,  -183
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,  -183,  -183,  -183,   283,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,    35,  -183,    21,  -183,   288,
     289,   290,  -183,  -183,   189,   -50,  -183,   -51,   -34,   -91,
     -38,  -183,  -183,    83,   196,   -79,   -82,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,   -63,   144,  -183,  -183,  -182,   -59,
    -183,  -183,  -183,    79,  -183,   124,  -183,   -70,  -120,  -183,
    -183,  -183,   131,  -183,  -183
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -65
static const yytype_int16 yytable[] =
{
      61,   141,   132,   113,   120,   123,    65,   105,   123,   142,
     133,   167,   130,   113,   116,   227,   200,     4,    33,    72,
      73,     4,   121,     3,    55,    56,     5,     6,    46,   260,
     224,     6,     7,     8,     9,    36,     7,   190,     6,    10,
      11,   172,    12,     7,    11,    13,   122,    57,    58,    59,
      60,    11,   249,    38,     4,    43,   191,    25,   123,   187,
     141,   173,   178,    39,     6,    55,    56,     6,   196,     7,
     188,   138,     7,   101,   203,   205,   200,    11,    40,   174,
      11,    14,   102,    42,   215,    14,   233,    27,    57,    58,
      59,    60,    47,    43,   210,    54,    45,    26,   217,    64,
     135,   136,   137,   202,   138,   199,     6,   138,   220,    48,
      51,     7,    49,   216,    50,   104,   226,   106,    14,    11,
     235,   113,   213,   219,   109,    55,    56,   210,   -64,   123,
      55,    56,   107,   222,   176,   141,   203,   110,   141,   214,
     136,   137,   104,   138,   141,   250,   117,   108,    57,    58,
      59,    60,   164,    57,    58,    59,    60,   211,   114,   256,
     225,   212,   257,   115,   210,   104,   127,   248,     4,   229,
      66,   193,   244,   140,   141,   141,    67,     5,     6,    68,
     118,   129,    69,     7,     8,    28,    29,   131,   230,    70,
      10,    11,   231,    12,   175,    71,    13,    30,    31,   255,
     104,   134,   165,    35,   245,    72,    73,    37,   230,   168,
      55,    56,   247,   255,   179,   180,   181,   182,   183,   184,
     169,   170,   177,   -62,   271,   136,   137,   -62,   138,   194,
     255,    74,    75,    57,    58,    59,    60,     4,   195,    66,
     197,   136,   137,   207,   138,    67,     5,     6,    68,   198,
     206,    69,     7,     8,   236,   218,    74,   223,    70,    10,
      11,   232,    12,   138,    71,    13,    72,    73,   234,   237,
     238,    55,    56,   258,    72,    73,   270,   259,   262,    55,
      56,   273,    72,    73,   274,    17,   261,    55,    56,   272,
      19,    20,    21,   119,    57,    58,    59,    60,   240,   171,
      74,    75,    57,    58,    59,    60,     4,   208,    66,   122,
      57,    58,    59,    60,    67,     5,     6,    68,     0,   221,
      69,     7,     8,   228,   239,     0,     0,    70,    10,    11,
       0,    12,     0,    71,    13,    72,    73,     0,     0,     0,
      55,    56,     0,    72,    73,     0,     0,     0,    55,    56,
     263,   264,   265,     0,   266,   267,     0,     0,     0,     0,
       0,     0,   201,    57,    58,    59,    60,     0,     0,    74,
      75,    57,    58,    59,    60,     4,     0,    66,     0,   241,
       0,     0,     0,    67,     5,     6,    68,     0,     0,    69,
       7,     8,     0,     0,     0,     0,    70,    10,    11,     0,
      12,     0,    71,    13,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,     0,     0,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    75,
      57,    58,    59,    60,     4,     0,    66,     0,     0,     0,
       0,     0,    67,     5,     6,    68,     0,     0,    69,     7,
       8,     0,   246,     0,     0,    70,    10,    11,     0,    12,
       0,    71,    13,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    73,     0,     0,     0,    55,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    57,
      58,    59,    60,     4,     0,    66,     0,     0,     0,     0,
       0,    67,     5,     6,    68,     0,     0,    69,     7,     8,
       0,   269,     0,     0,    70,    10,    11,     0,    12,     0,
      71,    13,     0,     0,     0,     0,     0,     0,     0,     0,
      72,    73,     0,     0,     0,    55,    56,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    57,    58,
      59,    60,     4,     0,    66,     0,     0,     0,     0,     0,
      67,     5,     6,    68,     0,     0,    69,     7,     8,     0,
       0,     0,     0,    70,    10,    11,     0,    12,     0,    71,
      13,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,     0,     0,     0,    55,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    74,    75,    57,    58,    59,
      60,   143,   144,   145,     0,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-183)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      38,    83,    72,    54,    67,    68,    40,    45,    71,    88,
      73,   102,    71,    64,    64,   197,   136,     3,    71,    40,
      41,     3,    43,     0,    45,    46,    12,    13,     3,     9,
      42,    13,    18,    19,    20,    67,    18,     4,    13,    25,
      26,    23,    28,    18,    26,    31,    67,    68,    69,    70,
      71,    26,   234,    67,     3,    67,    23,     3,   121,    27,
     142,   112,   121,    67,    13,    45,    46,    13,    40,    18,
      38,    43,    18,    32,   137,   138,   196,    26,    41,   113,
      26,    67,    41,    67,   175,    67,   206,     4,    68,    69,
      70,    71,    67,    67,   164,    15,    43,    43,   177,    15,
      39,    40,    41,   137,    43,    41,    13,    43,   187,    26,
      67,    18,    29,   176,    31,    38,   195,    44,    67,    26,
     211,   172,   172,   186,    43,    45,    46,   197,    67,   192,
      45,    46,    44,   192,    34,   217,   199,    38,   220,   173,
      40,    41,    38,    43,   226,   236,    42,    44,    68,    69,
      70,    71,    22,    68,    69,    70,    71,    38,    71,   238,
     194,    42,   241,    71,   234,    38,    49,   230,     3,    42,
       5,     3,   223,     8,   256,   257,    11,    12,    13,    14,
      67,    67,    17,    18,    19,    16,    17,    67,    38,    24,
      25,    26,    42,    28,    41,    30,    31,    28,    29,   237,
      38,    67,    67,     7,    42,    40,    41,    11,    38,    67,
      45,    46,    42,   251,    32,    33,    34,    35,    36,    37,
      44,    44,     6,    38,   262,    40,    41,    42,    43,    41,
     268,    66,    67,    68,    69,    70,    71,     3,     6,     5,
      22,    40,    41,     9,    43,    11,    12,    13,    14,    42,
      40,    17,    18,    19,    49,    44,    66,    43,    24,    25,
      26,    44,    28,    43,    30,    31,    40,    41,    22,    42,
       6,    45,    46,    10,    40,    41,    67,    44,    43,    45,
      46,    32,    40,    41,    44,     2,   251,    45,    46,   268,
       2,     2,     2,    67,    68,    69,    70,    71,   219,   110,
      66,    67,    68,    69,    70,    71,     3,   163,     5,    67,
      68,    69,    70,    71,    11,    12,    13,    14,    -1,   188,
      17,    18,    19,   199,    21,    -1,    -1,    24,    25,    26,
      -1,    28,    -1,    30,    31,    40,    41,    -1,    -1,    -1,
      45,    46,    -1,    40,    41,    -1,    -1,    -1,    45,    46,
      45,    46,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    -1,    -1,    66,
      67,    68,    69,    70,    71,     3,    -1,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,    13,    14,    -1,    -1,    17,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,
      28,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    41,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    71,     3,    -1,     5,    -1,    -1,    -1,
      -1,    -1,    11,    12,    13,    14,    -1,    -1,    17,    18,
      19,    -1,    21,    -1,    -1,    24,    25,    26,    -1,    28,
      -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,     3,    -1,     5,    -1,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
      -1,    21,    -1,    -1,    24,    25,    26,    -1,    28,    -1,
      30,    31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,     3,    -1,     5,    -1,    -1,    -1,    -1,    -1,
      11,    12,    13,    14,    -1,    -1,    17,    18,    19,    -1,
      -1,    -1,    -1,    24,    25,    26,    -1,    28,    -1,    30,
      31,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    45,    46,    47,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    73,    75,     0,     3,    12,    13,    18,    19,    20,
      25,    26,    28,    31,    67,    74,    76,    78,    79,    91,
      92,    93,    99,   101,   105,     3,    43,   105,    16,    17,
      28,    29,    94,    71,   106,   106,    67,   106,    67,    67,
      41,    77,    67,    67,   100,    43,     3,    67,   105,   105,
     105,    67,    95,    96,    15,    45,    46,    68,    69,    70,
      71,   102,   103,   104,    15,   100,     5,    11,    14,    17,
      24,    30,    40,    41,    66,    67,    78,    82,    85,    91,
      92,    93,   102,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   119,   128,   129,   131,   132,   133,
     134,    32,    41,    80,    38,   102,    44,    44,    44,    43,
      38,    97,    98,    99,    71,    71,    97,    42,    67,    67,
     116,    43,    67,   116,   121,   122,   124,    49,    83,    67,
     121,    67,   129,   116,    67,    39,    40,    41,    43,   130,
       8,   108,   107,    45,    46,    47,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   118,    22,    67,    81,   101,    67,    44,
      44,    96,    23,    99,   100,    41,    34,     6,   121,    32,
      33,    34,    35,    36,    37,   125,   126,    27,    38,   135,
       4,    23,   123,     3,    41,     6,    40,    22,    42,    41,
     130,    67,   100,   116,   127,   116,    40,     9,   117,   120,
     129,    38,    42,    97,   100,   101,   116,   107,    44,   116,
     107,   134,   121,    43,    42,   100,   107,   120,   127,    42,
      38,    42,    44,   130,    22,   101,    49,    42,     6,    21,
     125,     7,   136,    84,    99,    42,    21,    42,   116,   120,
     101,    86,    87,    88,    89,   102,   107,   107,    10,    44,
       9,    87,    43,    45,    46,    47,    49,    50,    90,    21,
      67,   102,    89,    32,    44
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
/* Line 1792 of yacc.c  */
#line 1786 "musl.tab.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 296 "musl.y"


