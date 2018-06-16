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
#line 103 "musl.y"

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
# define YYDEBUG 1
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
     T_BEGIN = 260,
     T_DATAVEC = 261,
     T_DO = 262,
     T_ELSE = 263,
     T_MODULEEND = 264,
     T_END = 265,
     T_FI = 266,
     T_FOR = 267,
     T_IMPORT = 268,
     T_INTEGER = 269,
     T_IF = 270,
     T_IS = 271,
     T_LABEL = 272,
     T_LITERAL = 273,
     T_LOGICAL = 274,
     T_LSPEC = 275,
     T_MODULE = 276,
     T_OD = 277,
     T_OF = 278,
     T_OR = 279,
     T_PROC = 280,
     T_PSPEC = 281,
     T_REAL = 282,
     T_THEN = 283,
     T_TYPE = 284,
     T_VSTORE = 285,
     T_WHILE = 286,
     T_WITHIN = 287,
     T_SEP = 288,
     T_EQUALS = 289,
     T_NOT_EQUALS = 290,
     T_LT = 291,
     T_GT = 292,
     T_LE = 293,
     T_GE = 294,
     T_COMMA = 295,
     T_COLON = 296,
     T_CIRCUMFLEX = 297,
     T_L_BRACK = 298,
     T_R_BRACK = 299,
     T_L_PAREN = 300,
     T_R_PAREN = 301,
     T_PLUS = 302,
     T_MINUS = 303,
     T_STAR = 304,
     T_SLASH = 305,
     T_AMPERSAND = 306,
     T_EXCLAMATION = 307,
     T_XOR = 308,
     T_RSUB = 309,
     T_RDIV = 310,
     T_ADDSTORE = 311,
     T_MULSTORE = 312,
     T_DIVSTORE = 313,
     T_ANDSTORE = 314,
     T_ORSTORE = 315,
     T_XORSTORE = 316,
     T_ASSIGN = 317,
     T_RSUBSTORE = 318,
     T_RDIVSTORE = 319,
     T_LLSHIFT = 320,
     T_RLSHIFT = 321,
     T_GOTO_OR_SUBSTORE = 322,
     T_TYPE_NAME = 323,
     T_NAME = 324,
     T_CHAR_CONST = 325,
     T_MULTI_CHAR_CONST = 326,
     T_CH_STRING = 327,
     T_NUMBER = 328
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 115 "musl.y"

    char charval;
    char *stringval;
    char *nameval;
    unsigned int unsignedval;


/* Line 387 of yacc.c  */
#line 203 "musl.tab.cpp"
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
#line 231 "musl.tab.cpp"

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
#define YYLAST   691

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  176
/* YYNRULES -- Number of states.  */
#define YYNSTATES  285

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    12,    15,    17,    18,    22,    23,
      25,    27,    29,    31,    35,    38,    42,    47,    49,    51,
      55,    61,    65,    67,    68,    71,    79,    81,    91,    94,
      96,    98,   103,   105,   107,   111,   113,   115,   117,   119,
     121,   124,   129,   134,   139,   142,   146,   148,   151,   153,
     156,   158,   160,   164,   166,   168,   172,   174,   178,   182,
     185,   187,   192,   196,   198,   200,   202,   206,   210,   214,
     216,   219,   222,   224,   226,   228,   230,   232,   235,   238,
     240,   243,   246,   249,   251,   252,   256,   259,   261,   263,
     265,   267,   271,   273,   275,   277,   279,   281,   283,   285,
     287,   289,   294,   297,   302,   308,   311,   313,   315,   317,
     319,   321,   323,   325,   329,   331,   333,   335,   337,   339,
     341,   343,   345,   347,   349,   351,   353,   355,   357,   359,
     361,   363,   365,   367,   369,   371,   373,   376,   380,   385,
     387,   392,   398,   402,   404,   408,   410,   414,   418,   420,
     422,   424,   427,   431,   434,   436,   438,   440,   442,   444,
     446,   450,   452,   453,   455,   458,   462,   467,   471,   475,
     481,   487,   495,   498,   501,   506,   509
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      75,     0,    -1,    78,    76,    80,    77,   111,     9,    -1,
      21,    -1,    21,    69,    -1,    33,    -1,    -1,    78,    79,
      77,    -1,    -1,    81,    -1,    94,    -1,    95,    -1,    96,
      -1,    43,   103,    44,    -1,    82,    69,    -1,    82,    69,
      83,    -1,    82,    69,    34,    69,    -1,    20,    -1,    26,
      -1,    43,    84,    44,    -1,    43,    84,    44,    50,   104,
      -1,    84,    40,   104,    -1,   104,    -1,    -1,    18,    86,
      -1,    50,     3,    45,    87,    46,    69,    34,    -1,   102,
      -1,     6,    69,    43,   104,    44,    77,    89,    77,    10,
      -1,    89,    90,    -1,    90,    -1,    91,    -1,    91,    45,
     106,    46,    -1,    92,    -1,   106,    -1,   106,    93,    92,
      -1,    47,    -1,    48,    -1,    51,    -1,    49,    -1,    50,
      -1,    29,    69,    -1,    29,    69,    16,   100,    -1,    29,
      69,    34,   106,    -1,    32,    69,    16,   100,    -1,   102,
     103,    -1,    13,    97,    98,    -1,    18,    -1,    18,   109,
      -1,    30,    -1,    30,   109,    -1,    29,    -1,    17,    -1,
      98,    40,    99,    -1,    99,    -1,    69,    -1,    69,    45,
      46,    -1,   101,    -1,   101,    24,   100,    -1,   101,   102,
     103,    -1,   102,   103,    -1,   104,    -1,   104,    45,   106,
      46,    -1,   103,    40,    69,    -1,    69,    -1,   109,    -1,
      68,    -1,   105,   109,    46,    -1,   105,    68,    46,    -1,
     105,     3,    46,    -1,     3,    -1,     3,     3,    -1,     3,
      45,    -1,   107,    -1,   108,    -1,    71,    -1,    72,    -1,
      73,    -1,    47,    73,    -1,    48,    73,    -1,    70,    -1,
      14,   110,    -1,    27,   110,    -1,    19,   110,    -1,    73,
      -1,    -1,   111,   112,    77,    -1,   112,    77,    -1,   114,
      -1,   115,    -1,   116,    -1,   113,    -1,     5,   111,    10,
      -1,   118,    -1,    95,    -1,    81,    -1,    85,    -1,    88,
      -1,    94,    -1,    96,    -1,   119,    -1,   120,    -1,   117,
      77,   111,    10,    -1,    25,    69,    -1,    25,    69,    43,
      44,    -1,    25,    69,    43,   103,    44,    -1,    69,    41,
      -1,   121,    -1,   135,    -1,   136,    -1,   137,    -1,   138,
      -1,   122,    -1,   124,    -1,   124,   123,   122,    -1,    47,
      -1,    48,    -1,    49,    -1,    50,    -1,    51,    -1,    52,
      -1,    53,    -1,    54,    -1,    55,    -1,    56,    -1,    67,
      -1,    57,    -1,    58,    -1,    59,    -1,    60,    -1,    61,
      -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1,    66,
      -1,   133,    -1,    42,   133,    -1,   133,    23,   125,    -1,
      42,   133,    23,   125,    -1,   106,    -1,    69,    43,   132,
      44,    -1,    69,    42,    43,   132,    44,    -1,    43,   121,
      44,    -1,   133,    -1,   133,    23,   125,    -1,   127,    -1,
     127,   128,   126,    -1,    45,   126,    46,    -1,   129,    -1,
      24,    -1,     4,    -1,   121,   130,    -1,   131,   121,   130,
      -1,   131,   121,    -1,    34,    -1,    35,    -1,    36,    -1,
      37,    -1,    38,    -1,    39,    -1,   132,    40,   121,    -1,
     121,    -1,    -1,    69,    -1,    69,   134,    -1,    69,    42,
     134,    -1,    69,   134,    42,   134,    -1,    45,   121,    46,
      -1,    15,   126,   139,    -1,    31,   126,     7,   111,    22,
      -1,    12,   121,     7,   111,    22,    -1,    12,    69,    36,
     121,     7,   111,    22,    -1,    67,    69,    -1,    40,   138,
      -1,    28,   111,   140,    11,    -1,     8,   111,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   125,   125,   126,   126,   128,   128,   129,
     129,   129,   129,   131,   134,   136,   138,   140,   142,   144,
     146,   148,   148,   148,   157,   159,   160,   162,   163,   163,
     164,   164,   165,   166,   166,   167,   167,   167,   167,   167,
     170,   172,   174,   176,   178,   180,   182,   184,   186,   188,
     190,   192,   194,   194,   196,   198,   200,   200,   201,   201,
     203,   203,   205,   205,   209,   211,   217,   219,   221,   223,
     225,   226,   228,   228,   228,   228,   229,   229,   229,   230,
     233,   235,   237,   239,   239,   241,   241,   243,   243,   243,
     243,   244,   246,   246,   246,   246,   246,   246,   246,   248,
     248,   250,   251,   251,   251,   253,   255,   255,   255,   255,
     257,   259,   260,   260,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   264,   266,   268,   270,   272,
     274,   276,   278,   279,   279,   281,   281,   282,   282,   283,
     283,   285,   286,   286,   287,   287,   287,   287,   287,   287,
     289,   289,   289,   292,   292,   292,   292,   293,   295,   296,
     297,   297,   298,   300,   300,   301,   301
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ADDR", "T_AND", "T_BEGIN",
  "T_DATAVEC", "T_DO", "T_ELSE", "T_MODULEEND", "T_END", "T_FI", "T_FOR",
  "T_IMPORT", "T_INTEGER", "T_IF", "T_IS", "T_LABEL", "T_LITERAL",
  "T_LOGICAL", "T_LSPEC", "T_MODULE", "T_OD", "T_OF", "T_OR", "T_PROC",
  "T_PSPEC", "T_REAL", "T_THEN", "T_TYPE", "T_VSTORE", "T_WHILE",
  "T_WITHIN", "T_SEP", "T_EQUALS", "T_NOT_EQUALS", "T_LT", "T_GT", "T_LE",
  "T_GE", "T_COMMA", "T_COLON", "T_CIRCUMFLEX", "T_L_BRACK", "T_R_BRACK",
  "T_L_PAREN", "T_R_PAREN", "T_PLUS", "T_MINUS", "T_STAR", "T_SLASH",
  "T_AMPERSAND", "T_EXCLAMATION", "T_XOR", "T_RSUB", "T_RDIV",
  "T_ADDSTORE", "T_MULSTORE", "T_DIVSTORE", "T_ANDSTORE", "T_ORSTORE",
  "T_XORSTORE", "T_ASSIGN", "T_RSUBSTORE", "T_RDIVSTORE", "T_LLSHIFT",
  "T_RLSHIFT", "T_GOTO_OR_SUBSTORE", "T_TYPE_NAME", "T_NAME",
  "T_CHAR_CONST", "T_MULTI_CHAR_CONST", "T_CH_STRING", "T_NUMBER",
  "$accept", "module", "start_module", "separator", "imports", "import",
  "exports", "proc_dec", "proc_dec_spec", "pspec", "t_list", "lit_dec",
  "pointer_lit", "any_type", "data_vec", "literals", "literal_item",
  "literal", "const_expr", "const_op", "type_dec", "var_dec", "import_dec",
  "kind", "imp_list", "imp_list_item", "structure", "fields", "type",
  "name_list", "scalar_type", "vector_pointer", "const", "dec_integer",
  "char_const", "numeric_type", "size", "statements", "statement", "block",
  "declarative_statement", "imperative_statement", "proc_defn",
  "proc_heading", "label_dec", "comp_st", "control_st", "computation",
  "opr_opd_seq", "operator", "operand", "context", "condition", "test",
  "logop", "comparison", "compare_list", "comparator", "p_list",
  "variable", "subscript", "if_st", "while_st", "for_st", "go_st",
  "action", "else_cl", YY_NULL
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
     325,   326,   327,   328
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    77,    77,    78,    78,    79,
      79,    79,    79,    80,    81,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    85,    86,    87,    88,    89,    89,
      90,    90,    91,    92,    92,    93,    93,    93,    93,    93,
      94,    94,    94,    94,    95,    96,    97,    97,    97,    97,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   104,   104,   104,   104,
     104,   105,   106,   106,   106,   106,   107,   107,   107,   108,
     109,   109,   109,   110,   110,   111,   111,   112,   112,   112,
     112,   113,   114,   114,   114,   114,   114,   114,   114,   115,
     115,   116,   117,   117,   117,   118,   119,   119,   119,   119,
     120,   121,   122,   122,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   124,   124,   124,   124,   124,
     124,   124,   124,   125,   125,   126,   126,   127,   127,   128,
     128,   129,   130,   130,   131,   131,   131,   131,   131,   131,
     132,   132,   132,   133,   133,   133,   133,   134,   135,   136,
     137,   137,   138,   139,   139,   140,   140
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     2,     1,     0,     3,     0,     1,
       1,     1,     1,     3,     2,     3,     4,     1,     1,     3,
       5,     3,     1,     0,     2,     7,     1,     9,     2,     1,
       1,     4,     1,     1,     3,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     2,     3,     1,     2,     1,     2,
       1,     1,     3,     1,     1,     3,     1,     3,     3,     2,
       1,     4,     3,     1,     1,     1,     3,     3,     3,     1,
       2,     2,     1,     1,     1,     1,     1,     2,     2,     1,
       2,     2,     2,     1,     0,     3,     2,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     2,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     1,
       4,     5,     3,     1,     3,     1,     3,     3,     1,     1,
       1,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     0,     1,     2,     3,     4,     3,     3,     5,
       5,     7,     2,     2,     4,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,    69,     0,    84,    84,    17,     3,
      18,    84,     0,     0,    65,     0,     6,     9,     0,    10,
      11,    12,     0,    60,     0,    64,    70,    71,    51,    46,
      50,    48,     0,    83,    80,    82,     4,    81,    40,     0,
       0,     6,     5,     7,    14,    63,    44,     0,     0,     0,
       0,    47,    49,    54,    45,    53,     0,     0,     0,     0,
       0,     0,    23,    15,     0,     0,     0,    79,    74,    75,
      76,     0,    72,    73,    68,    67,    66,     0,     0,    41,
      56,     0,    42,    43,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   163,    94,    95,    96,    97,
      93,    98,   139,     0,     6,    90,    87,    88,    89,     6,
      92,    99,   100,   106,   111,   112,   135,   107,   108,   109,
     110,    16,     0,    22,    62,    77,    78,    61,    55,    52,
       0,     0,    59,     0,     0,   163,     0,     0,   163,     0,
       0,   145,   148,     0,    24,   102,     0,   163,   136,     0,
     172,   105,     0,   162,     0,   164,     2,     6,    86,     0,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     124,     0,     0,     0,    19,    57,    58,    91,     0,     0,
       0,     0,   154,   155,   156,   157,   158,   159,   151,     0,
       0,     0,   168,   150,   149,     0,     0,     0,     0,     0,
       0,   142,   162,   165,   161,     0,     0,     0,    85,     0,
     113,   137,   143,    21,     0,     0,     0,     0,   147,   153,
     176,   173,   146,     0,   103,     0,     0,   138,     0,     0,
     140,   167,   166,   101,     0,    20,     6,     0,   170,   152,
       0,     0,     0,    26,   104,   169,   141,   160,   144,     0,
       0,   175,   174,     0,     6,    29,    30,    32,    33,   171,
       0,     0,    28,     0,    35,    36,    38,    39,    37,     0,
      25,    27,     0,    34,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    15,    43,     2,    16,    41,    96,    18,    63,
     122,    97,   144,   252,    98,   264,   265,   266,   267,   279,
      99,   100,   101,    32,    54,    55,    79,    80,    22,    46,
      23,    24,   102,    72,    73,    25,    34,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   181,
     115,   221,   140,   141,   205,   142,   198,   199,   215,   116,
     155,   117,   118,   119,   120,   202,   251
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -193
static const yytype_int16 yypact[] =
{
    -193,    46,   131,  -193,     8,   119,   -26,   -26,  -193,   -53,
    -193,   -26,    24,    26,  -193,    29,    67,  -193,    32,  -193,
    -193,  -193,    41,    40,    72,  -193,  -193,  -193,  -193,    16,
    -193,    16,    47,  -193,  -193,  -193,  -193,  -193,     3,   112,
      41,    67,  -193,  -193,    23,  -193,    90,    42,    97,   109,
     115,  -193,  -193,   117,   129,  -193,   161,    42,   161,    52,
     597,   103,   161,  -193,   118,   121,   142,  -193,  -193,  -193,
    -193,   158,  -193,  -193,  -193,  -193,  -193,   175,    47,  -193,
       9,    41,  -193,  -193,  -193,   597,   153,   304,   251,   173,
     156,   251,   159,   375,   162,    77,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,    36,    67,  -193,  -193,  -193,  -193,    67,
    -193,  -193,  -193,  -193,  -193,   624,   204,  -193,  -193,  -193,
    -193,  -193,    58,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
     161,    41,    90,   171,   187,   111,   226,   251,   150,   328,
      -8,    10,  -193,   231,  -193,   192,   229,    28,   214,   202,
    -193,  -193,    15,   375,   375,   207,  -193,    67,  -193,   597,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,   375,   159,   161,   200,  -193,    90,  -193,   161,   375,
     597,   205,  -193,  -193,  -193,  -193,  -193,  -193,  -193,   375,
     597,   186,  -193,  -193,  -193,   251,   213,   -29,   597,   219,
     159,  -193,   375,  -193,  -193,    98,   220,   219,  -193,   242,
    -193,  -193,   236,  -193,   161,   221,   263,   313,  -193,   328,
     384,  -193,  -193,   161,  -193,   138,   455,  -193,   176,   375,
    -193,  -193,  -193,  -193,   159,  -193,    67,   597,  -193,  -193,
     597,   261,   233,  -193,  -193,  -193,  -193,  -193,  -193,    42,
     526,   597,  -193,   206,   230,  -193,   235,  -193,   160,  -193,
     247,   266,  -193,    42,  -193,  -193,  -193,  -193,  -193,    42,
    -193,  -193,   237,  -193,  -193
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -193,  -193,  -193,   -40,  -193,  -193,  -193,   280,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,    22,  -193,    12,  -193,
     285,   286,   290,  -193,  -193,   217,   -49,  -193,   -54,   -37,
     -57,  -193,   -47,  -193,  -193,     0,   194,   -79,   -95,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,   -66,   116,  -193,
    -193,  -192,   -78,  -193,  -193,  -193,    75,  -193,    93,   -85,
    -135,  -193,  -193,  -193,   105,  -193,  -193
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
      71,    60,    81,    59,    81,   123,   133,   148,   157,    83,
      82,    26,     4,   146,   203,   234,    36,   213,   237,    56,
     200,   136,   139,     6,    50,   139,   131,   149,     7,    51,
       6,    52,   201,   130,   204,     7,    11,    57,   157,     4,
      45,    85,    86,    11,   132,   156,     3,    33,    87,     5,
       6,    88,   258,    27,    89,     7,     8,    61,   212,   191,
     154,    90,    10,    11,   158,    12,    62,    91,    13,   159,
     209,   139,    40,   154,   213,    48,    81,    14,    92,    93,
     219,   185,   242,    65,    66,    47,     6,   214,   216,    65,
      66,     7,    64,    38,   186,    39,    84,   222,   183,    11,
      42,    44,   184,    94,    14,    95,    67,    68,    69,    70,
      45,   227,    67,    68,    69,    70,    53,   218,   151,   152,
     153,   230,   154,   226,   157,   222,   223,   232,    58,   236,
      64,   225,   157,   229,     4,   157,    28,    29,   239,   139,
      49,   157,   240,    74,     5,     6,   214,   189,    30,    31,
       7,     8,     9,   152,   153,    75,   154,    10,    11,   222,
      12,    76,    77,    13,     4,   157,   157,   245,   260,    78,
     235,   261,   121,   257,     4,     6,    85,    86,    64,   253,
       7,   187,   254,    87,     5,     6,    88,   124,    11,    89,
       7,     8,   152,   153,   125,   154,    90,    10,    11,    14,
      12,    35,    91,    13,   127,    37,   259,   274,   275,   276,
     277,   278,   268,    92,    93,   126,   239,   268,    65,    66,
     256,   128,   134,   143,   271,   145,   282,   182,   147,    14,
     188,   150,   268,   190,   206,   207,   208,   210,    94,    14,
      95,    67,    68,    69,    70,     4,   211,    85,    86,   217,
     224,   228,   243,    94,    87,     5,     6,    88,   233,   244,
      89,     7,     8,    42,   154,   246,   241,    90,    10,    11,
     247,    12,   262,    91,    13,   270,   281,    65,    66,   263,
     273,   280,    17,   284,    92,    93,   272,    19,    20,    65,
      66,   283,    21,    92,    93,   129,   137,   220,    65,    66,
      67,    68,    69,    70,   249,   238,   231,     0,     0,    94,
      14,    95,    67,    68,    69,    70,     4,     0,    85,    86,
     138,    67,    68,    69,    70,    87,     5,     6,    88,     0,
       0,    89,     7,     8,     0,   248,     0,     0,    90,    10,
      11,     0,    12,     0,    91,    13,    92,    93,     0,     0,
       0,    65,    66,     0,     0,    92,    93,     0,     0,     0,
      65,    66,   192,   193,   194,   195,   196,   197,     0,     0,
       0,     0,     0,   135,    67,    68,    69,    70,     0,     0,
      94,    14,    95,    67,    68,    69,    70,     4,     0,    85,
      86,     0,   250,     0,     0,     0,    87,     5,     6,    88,
       0,     0,    89,     7,     8,     0,     0,     0,     0,    90,
      10,    11,     0,    12,     0,    91,    13,    92,    93,     0,
       0,     0,    65,    66,     0,     0,    92,    93,     0,     0,
       0,    65,    66,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,    67,    68,    69,    70,     0,
       0,    94,    14,    95,    67,    68,    69,    70,     4,     0,
      85,    86,     0,     0,     0,     0,     0,    87,     5,     6,
      88,     0,     0,    89,     7,     8,     0,   255,     0,     0,
      90,    10,    11,     0,    12,     0,    91,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    92,    93,     0,
       0,     0,    65,    66,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    14,    95,    67,    68,    69,    70,     4,
       0,    85,    86,     0,     0,     0,     0,     0,    87,     5,
       6,    88,     0,     0,    89,     7,     8,     0,   269,     0,
       0,    90,    10,    11,     0,    12,     0,    91,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
       0,     0,     0,    65,    66,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    94,    14,    95,    67,    68,    69,    70,
       4,     0,    85,    86,     0,     0,     0,     0,     0,    87,
       5,     6,    88,     0,     0,    89,     7,     8,     0,     0,
       0,     0,    90,    10,    11,     0,    12,     0,    91,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    92,
      93,     0,     0,     0,    65,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    94,    14,    95,    67,    68,    69,
      70,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-193)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      47,    41,    56,    40,    58,    62,    85,    92,   103,    58,
      57,     3,     3,    91,     4,    44,    69,   152,   210,    16,
      28,    87,    88,    14,    24,    91,    80,    93,    19,    29,
      14,    31,    40,    24,    24,    19,    27,    34,   133,     3,
      69,     5,     6,    27,    81,     9,     0,    73,    12,    13,
      14,    15,   244,    45,    18,    19,    20,    34,    43,   137,
      45,    25,    26,    27,   104,    29,    43,    31,    32,   109,
      42,   137,    43,    45,   209,     3,   130,    68,    42,    43,
     159,   130,   217,    47,    48,    45,    14,   153,   154,    47,
      48,    19,    40,    69,   131,    69,    44,   182,    40,    27,
      33,    69,    44,    67,    68,    69,    70,    71,    72,    73,
      69,   190,    70,    71,    72,    73,    69,   157,    41,    42,
      43,   200,    45,   189,   219,   210,   183,   205,    16,   208,
      40,   188,   227,   199,     3,   230,    17,    18,    40,   205,
      68,   236,    44,    46,    13,    14,   212,    36,    29,    30,
      19,    20,    21,    42,    43,    46,    45,    26,    27,   244,
      29,    46,    45,    32,     3,   260,   261,   224,   247,    40,
     207,   250,    69,   239,     3,    14,     5,     6,    40,   233,
      19,    10,    44,    12,    13,    14,    15,    69,    27,    18,
      19,    20,    42,    43,    73,    45,    25,    26,    27,    68,
      29,     7,    31,    32,    46,    11,   246,    47,    48,    49,
      50,    51,   259,    42,    43,    73,    40,   264,    47,    48,
      44,    46,    69,    50,   264,    69,   273,    23,    69,    68,
      43,    69,   279,     7,     3,    43,     7,    23,    67,    68,
      69,    70,    71,    72,    73,     3,    44,     5,     6,    42,
      50,    46,    10,    67,    12,    13,    14,    15,    45,    23,
      18,    19,    20,    33,    45,    44,    46,    25,    26,    27,
       7,    29,    11,    31,    32,    69,    10,    47,    48,    46,
      45,    34,     2,    46,    42,    43,   264,     2,     2,    47,
      48,   279,     2,    42,    43,    78,    45,   181,    47,    48,
      70,    71,    72,    73,   229,   212,   201,    -1,    -1,    67,
      68,    69,    70,    71,    72,    73,     3,    -1,     5,     6,
      69,    70,    71,    72,    73,    12,    13,    14,    15,    -1,
      -1,    18,    19,    20,    -1,    22,    -1,    -1,    25,    26,
      27,    -1,    29,    -1,    31,    32,    42,    43,    -1,    -1,
      -1,    47,    48,    -1,    -1,    42,    43,    -1,    -1,    -1,
      47,    48,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,    -1,
      67,    68,    69,    70,    71,    72,    73,     3,    -1,     5,
       6,    -1,     8,    -1,    -1,    -1,    12,    13,    14,    15,
      -1,    -1,    18,    19,    20,    -1,    -1,    -1,    -1,    25,
      26,    27,    -1,    29,    -1,    31,    32,    42,    43,    -1,
      -1,    -1,    47,    48,    -1,    -1,    42,    43,    -1,    -1,
      -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    71,    72,    73,    -1,
      -1,    67,    68,    69,    70,    71,    72,    73,     3,    -1,
       5,     6,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    -1,    -1,    18,    19,    20,    -1,    22,    -1,    -1,
      25,    26,    27,    -1,    29,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,
      -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    73,     3,
      -1,     5,     6,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    -1,    -1,    18,    19,    20,    -1,    22,    -1,
      -1,    25,    26,    27,    -1,    29,    -1,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    67,    68,    69,    70,    71,    72,    73,
       3,    -1,     5,     6,    -1,    -1,    -1,    -1,    -1,    12,
      13,    14,    15,    -1,    -1,    18,    19,    20,    -1,    -1,
      -1,    -1,    25,    26,    27,    -1,    29,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    75,    78,     0,     3,    13,    14,    19,    20,    21,
      26,    27,    29,    32,    68,    76,    79,    81,    82,    94,
      95,    96,   102,   104,   105,   109,     3,    45,    17,    18,
      29,    30,    97,    73,   110,   110,    69,   110,    69,    69,
      43,    80,    33,    77,    69,    69,   103,    45,     3,    68,
     109,   109,   109,    69,    98,    99,    16,    34,    16,   103,
      77,    34,    43,    83,    40,    47,    48,    70,    71,    72,
      73,   106,   107,   108,    46,    46,    46,    45,    40,   100,
     101,   102,   106,   100,    44,     5,     6,    12,    15,    18,
      25,    31,    42,    43,    67,    69,    81,    85,    88,    94,
      95,    96,   106,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   124,   133,   135,   136,   137,
     138,    69,    84,   104,    69,    73,    73,    46,    46,    99,
      24,   102,   103,   111,    69,    69,   121,    45,    69,   121,
     126,   127,   129,    50,    86,    69,   126,    69,   133,   121,
      69,    41,    42,    43,    45,   134,     9,   112,    77,    77,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,   123,    23,    40,    44,   100,   103,    10,    43,    36,
       7,   126,    34,    35,    36,    37,    38,    39,   130,   131,
      28,    40,   139,     4,    24,   128,     3,    43,     7,    42,
      23,    44,    43,   134,   121,   132,   121,    42,    77,   111,
     122,   125,   133,   104,    50,   104,   121,   111,    46,   121,
     111,   138,   126,    45,    44,   103,   111,   125,   132,    40,
      44,    46,   134,    10,    23,   104,    44,     7,    22,   130,
       8,   140,    87,   102,    44,    22,    44,   121,   125,    77,
     111,   111,    11,    46,    89,    90,    91,    92,   106,    22,
      69,    77,    90,    45,    47,    48,    49,    50,    51,    93,
      34,    10,   106,    92,    46
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
        case 40:
/* Line 1792 of yacc.c  */
#line 170 "musl.y"
    { new_type((yyvsp[(2) - (2)].nameval)); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 172 "musl.y"
    { new_type((yyvsp[(2) - (4)].nameval)); }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 174 "musl.y"
    { new_type((yyvsp[(2) - (4)].nameval)); }
    break;


/* Line 1792 of yacc.c  */
#line 1814 "musl.tab.cpp"
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
#line 302 "musl.y"


