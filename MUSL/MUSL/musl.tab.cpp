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
#line 115 "musl.y"

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
     T_INTEGER8 = 270,
     T_INTEGER16 = 271,
     T_INTEGER32 = 272,
     T_INTEGER64 = 273,
     T_IF = 274,
     T_IS = 275,
     T_LABEL = 276,
     T_LITERAL = 277,
     T_LOGICAL = 278,
     T_LOGICAL8 = 279,
     T_LOGICAL16 = 280,
     T_LOGICAL32 = 281,
     T_LOGICAL64 = 282,
     T_LSPEC = 283,
     T_MODULE = 284,
     T_OD = 285,
     T_OF = 286,
     T_OR = 287,
     T_PROC = 288,
     T_PSPEC = 289,
     T_REAL = 290,
     T_REAL32 = 291,
     T_REAL64 = 292,
     T_REAL128 = 293,
     T_THEN = 294,
     T_TYPE = 295,
     T_VSTORE = 296,
     T_WHILE = 297,
     T_WITHIN = 298,
     T_SEP = 299,
     T_EQUALS = 300,
     T_NOT_EQUALS = 301,
     T_LT = 302,
     T_GT = 303,
     T_LE = 304,
     T_GE = 305,
     T_COMMA = 306,
     T_COLON = 307,
     T_CIRCUMFLEX = 308,
     T_L_BRACK = 309,
     T_R_BRACK = 310,
     T_L_PAREN = 311,
     T_R_PAREN = 312,
     T_PLUS = 313,
     T_MINUS = 314,
     T_STAR = 315,
     T_SLASH = 316,
     T_AMPERSAND = 317,
     T_EXCLAMATION = 318,
     T_XOR = 319,
     T_RSUB = 320,
     T_RDIV = 321,
     T_ADDSTORE = 322,
     T_MULSTORE = 323,
     T_DIVSTORE = 324,
     T_ANDSTORE = 325,
     T_ORSTORE = 326,
     T_XORSTORE = 327,
     T_ASSIGN = 328,
     T_RSUBSTORE = 329,
     T_RDIVSTORE = 330,
     T_LLSHIFT = 331,
     T_RLSHIFT = 332,
     T_GOTO_OR_SUBSTORE = 333,
     T_TYPE_NAME = 334,
     T_NAME = 335,
     T_CHAR_CONST = 336,
     T_MULTI_CHAR_CONST = 337,
     T_CH_STRING = 338,
     T_NUMBER = 339,
     T_HEXNUMBER = 340
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 127 "musl.y"

    char charval;
    char *stringval;
    char *nameval;
    unsigned int unsignedval;


/* Line 387 of yacc.c  */
#line 215 "musl.tab.cpp"
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
#line 243 "musl.tab.cpp"

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
#define YYLAST   1003

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  201
/* YYNRULES -- Number of states.  */
#define YYNSTATES  313

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    12,    15,    17,    18,    22,    23,
      25,    27,    29,    31,    35,    38,    42,    47,    49,    51,
      55,    61,    65,    67,    68,    71,    74,    82,    84,    88,
      90,    92,    94,    98,   100,   104,   106,   110,   120,   123,
     125,   127,   132,   134,   136,   140,   142,   144,   146,   148,
     150,   153,   158,   163,   168,   171,   175,   177,   180,   182,
     185,   187,   189,   193,   195,   197,   201,   203,   207,   211,
     214,   216,   221,   225,   227,   229,   231,   235,   239,   243,
     245,   248,   251,   253,   255,   257,   259,   261,   263,   266,
     269,   271,   273,   275,   277,   279,   281,   283,   285,   287,
     289,   291,   293,   295,   297,   299,   301,   303,   305,   307,
     311,   314,   315,   317,   319,   321,   323,   328,   330,   332,
     334,   336,   338,   340,   342,   344,   346,   351,   354,   359,
     365,   368,   370,   372,   374,   376,   378,   380,   382,   386,
     388,   390,   392,   394,   396,   398,   400,   402,   404,   406,
     408,   410,   412,   414,   416,   418,   420,   422,   424,   426,
     428,   430,   433,   437,   442,   444,   449,   455,   459,   461,
     465,   467,   471,   475,   477,   479,   481,   484,   488,   491,
     493,   495,   497,   499,   501,   503,   507,   509,   510,   512,
     515,   519,   524,   528,   532,   538,   544,   552,   555,   558,
     563,   566
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      87,     0,    -1,    90,    88,    92,    89,   130,     9,    -1,
      29,    -1,    29,    80,    -1,    44,    -1,    -1,    90,    91,
      89,    -1,    -1,    93,    -1,   111,    -1,   112,    -1,   113,
      -1,    54,   120,    55,    -1,    94,    80,    -1,    94,    80,
      95,    -1,    94,    80,    45,    80,    -1,    28,    -1,    34,
      -1,    54,    96,    55,    -1,    54,    96,    55,    61,   121,
      -1,    96,    51,   121,    -1,   121,    -1,    -1,    22,   100,
      -1,    22,    98,    -1,    61,     3,    56,    99,    57,    80,
      45,    -1,   119,    -1,    61,   101,   102,    -1,   102,    -1,
     127,    -1,   126,    -1,   102,    51,   103,    -1,   103,    -1,
      80,    45,   104,    -1,   123,    -1,   123,   110,   104,    -1,
       6,    80,    54,   121,    55,    89,   106,    89,    10,    -1,
     106,   107,    -1,   107,    -1,   108,    -1,   108,    56,   123,
      57,    -1,   109,    -1,   123,    -1,   123,   110,   109,    -1,
      58,    -1,    59,    -1,    62,    -1,    60,    -1,    61,    -1,
      40,    80,    -1,    40,    80,    20,   117,    -1,    40,    80,
      45,   123,    -1,    43,    80,    20,   117,    -1,   119,   120,
      -1,    13,   114,   115,    -1,    22,    -1,    22,   129,    -1,
      41,    -1,    41,   129,    -1,    40,    -1,    21,    -1,   115,
      51,   116,    -1,   116,    -1,    80,    -1,    80,    56,    57,
      -1,   118,    -1,   118,    32,   117,    -1,   118,   119,   120,
      -1,   119,   120,    -1,   121,    -1,   121,    56,   123,    57,
      -1,   120,    51,    80,    -1,    80,    -1,   129,    -1,    79,
      -1,   122,   129,    57,    -1,   122,    79,    57,    -1,   122,
       3,    57,    -1,     3,    -1,     3,     3,    -1,     3,    56,
      -1,   124,    -1,   125,    -1,    82,    -1,    83,    -1,    80,
      -1,    84,    -1,    58,    84,    -1,    59,    84,    -1,    85,
      -1,    81,    -1,    23,    -1,    24,    -1,    25,    -1,    26,
      -1,    27,    -1,    14,    -1,    15,    -1,    16,    -1,    17,
      -1,    18,    -1,    35,    -1,    36,    -1,    37,    -1,    38,
      -1,   127,    -1,   128,    -1,   126,    -1,   130,   131,    89,
      -1,   131,    89,    -1,    -1,   133,    -1,   134,    -1,   135,
      -1,   132,    -1,     5,    89,   130,    10,    -1,   137,    -1,
     112,    -1,    93,    -1,    97,    -1,   105,    -1,   111,    -1,
     113,    -1,   138,    -1,   139,    -1,   136,    89,   130,    10,
      -1,    33,    80,    -1,    33,    80,    54,    55,    -1,    33,
      80,    54,   120,    55,    -1,    80,    52,    -1,   140,    -1,
     154,    -1,   155,    -1,   156,    -1,   157,    -1,   141,    -1,
     143,    -1,   143,   142,   141,    -1,    58,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
      65,    -1,    66,    -1,    67,    -1,    78,    -1,    68,    -1,
      69,    -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,
      74,    -1,    75,    -1,    76,    -1,    77,    -1,   152,    -1,
      53,   152,    -1,   152,    31,   144,    -1,    53,   152,    31,
     144,    -1,   123,    -1,    80,    54,   151,    55,    -1,    80,
      53,    54,   151,    55,    -1,    54,   140,    55,    -1,   152,
      -1,   152,    31,   144,    -1,   146,    -1,   146,   147,   145,
      -1,    56,   145,    57,    -1,   148,    -1,    32,    -1,     4,
      -1,   140,   149,    -1,   150,   140,   149,    -1,   150,   140,
      -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,    49,
      -1,    50,    -1,   151,    51,   140,    -1,   140,    -1,    -1,
      80,    -1,    80,   153,    -1,    80,    53,   153,    -1,    80,
     153,    53,   153,    -1,    56,   140,    57,    -1,    19,   145,
     158,    -1,    42,   145,     7,   130,    30,    -1,    12,   140,
       7,   130,    30,    -1,    12,    80,    47,   140,     7,   130,
      30,    -1,    78,    80,    -1,    51,   157,    -1,    39,   130,
     159,    11,    -1,     8,   130,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   136,   136,   137,   137,   138,   138,   140,   140,   141,
     141,   141,   141,   143,   146,   148,   150,   152,   154,   156,
     158,   160,   160,   160,   163,   169,   171,   172,   174,   174,
     175,   175,   176,   176,   177,   178,   178,   180,   181,   181,
     182,   182,   183,   184,   184,   185,   185,   185,   185,   185,
     188,   190,   192,   194,   196,   198,   200,   202,   204,   206,
     208,   210,   212,   212,   214,   216,   218,   218,   219,   219,
     221,   221,   223,   223,   227,   229,   235,   237,   239,   241,
     243,   244,   246,   246,   246,   246,   246,   247,   247,   247,
     247,   248,   250,   250,   250,   250,   250,   251,   251,   251,
     251,   251,   252,   252,   252,   252,   255,   257,   259,   261,
     261,   261,   263,   263,   263,   263,   264,   266,   266,   266,
     266,   266,   266,   266,   268,   268,   270,   271,   271,   271,
     273,   275,   275,   275,   275,   277,   279,   280,   280,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     284,   286,   288,   290,   292,   294,   296,   298,   299,   299,
     301,   301,   302,   302,   303,   303,   305,   306,   306,   307,
     307,   307,   307,   307,   307,   309,   309,   309,   312,   312,
     312,   312,   313,   315,   316,   317,   317,   318,   320,   320,
     321,   321
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ADDR", "T_AND", "T_BEGIN",
  "T_DATAVEC", "T_DO", "T_ELSE", "T_MODULEEND", "T_END", "T_FI", "T_FOR",
  "T_IMPORT", "T_INTEGER", "T_INTEGER8", "T_INTEGER16", "T_INTEGER32",
  "T_INTEGER64", "T_IF", "T_IS", "T_LABEL", "T_LITERAL", "T_LOGICAL",
  "T_LOGICAL8", "T_LOGICAL16", "T_LOGICAL32", "T_LOGICAL64", "T_LSPEC",
  "T_MODULE", "T_OD", "T_OF", "T_OR", "T_PROC", "T_PSPEC", "T_REAL",
  "T_REAL32", "T_REAL64", "T_REAL128", "T_THEN", "T_TYPE", "T_VSTORE",
  "T_WHILE", "T_WITHIN", "T_SEP", "T_EQUALS", "T_NOT_EQUALS", "T_LT",
  "T_GT", "T_LE", "T_GE", "T_COMMA", "T_COLON", "T_CIRCUMFLEX",
  "T_L_BRACK", "T_R_BRACK", "T_L_PAREN", "T_R_PAREN", "T_PLUS", "T_MINUS",
  "T_STAR", "T_SLASH", "T_AMPERSAND", "T_EXCLAMATION", "T_XOR", "T_RSUB",
  "T_RDIV", "T_ADDSTORE", "T_MULSTORE", "T_DIVSTORE", "T_ANDSTORE",
  "T_ORSTORE", "T_XORSTORE", "T_ASSIGN", "T_RSUBSTORE", "T_RDIVSTORE",
  "T_LLSHIFT", "T_RLSHIFT", "T_GOTO_OR_SUBSTORE", "T_TYPE_NAME", "T_NAME",
  "T_CHAR_CONST", "T_MULTI_CHAR_CONST", "T_CH_STRING", "T_NUMBER",
  "T_HEXNUMBER", "$accept", "module", "start_module", "separator",
  "imports", "import", "exports", "proc_dec", "proc_dec_spec", "pspec",
  "t_list", "lit_dec", "pointer_lit", "any_type", "integer_lits",
  "integer_type", "integer_list", "integer_list_item", "value", "data_vec",
  "literals", "literal_item", "literal", "const_expr", "const_op",
  "type_dec", "var_dec", "import_dec", "kind", "imp_list", "imp_list_item",
  "structure", "fields", "type", "name_list", "scalar_type",
  "vector_pointer", "const", "dec_integer", "char_const", "logical",
  "integer", "real", "numeric_type", "statements", "statement", "block",
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
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    88,    89,    89,    90,    90,    91,
      91,    91,    91,    92,    93,    93,    93,    94,    94,    95,
      95,    96,    96,    96,    97,    97,    98,    99,   100,   100,
     101,   101,   102,   102,   103,   104,   104,   105,   106,   106,
     107,   107,   108,   109,   109,   110,   110,   110,   110,   110,
     111,   111,   111,   111,   112,   113,   114,   114,   114,   114,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   121,   121,   121,   121,
     121,   122,   123,   123,   123,   123,   123,   124,   124,   124,
     124,   125,   126,   126,   126,   126,   126,   127,   127,   127,
     127,   127,   128,   128,   128,   128,   129,   129,   129,   130,
     130,   130,   131,   131,   131,   131,   132,   133,   133,   133,
     133,   133,   133,   133,   134,   134,   135,   136,   136,   136,
     137,   138,   138,   138,   138,   139,   140,   141,   141,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   142,
     143,   143,   143,   143,   143,   143,   143,   143,   144,   144,
     145,   145,   146,   146,   147,   147,   148,   149,   149,   150,
     150,   150,   150,   150,   150,   151,   151,   151,   152,   152,
     152,   152,   153,   154,   155,   156,   156,   157,   158,   158,
     159,   159
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     2,     1,     0,     3,     0,     1,
       1,     1,     1,     3,     2,     3,     4,     1,     1,     3,
       5,     3,     1,     0,     2,     2,     7,     1,     3,     1,
       1,     1,     3,     1,     3,     1,     3,     9,     2,     1,
       1,     4,     1,     1,     3,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     2,     3,     1,     2,     1,     2,
       1,     1,     3,     1,     1,     3,     1,     3,     3,     2,
       1,     4,     3,     1,     1,     1,     3,     3,     3,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     0,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     2,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     4,     1,     4,     5,     3,     1,     3,
       1,     3,     3,     1,     1,     1,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     1,     2,
       3,     4,     3,     3,     5,     5,     7,     2,     2,     4,
       2,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,    79,     0,    97,    98,    99,   100,
     101,    92,    93,    94,    95,    96,    17,     3,    18,   102,
     103,   104,   105,     0,     0,    75,     0,     6,     9,     0,
      10,    11,    12,     0,    70,     0,   108,   106,   107,    74,
      80,    81,    61,    56,    60,    58,     0,     4,    50,     0,
       0,     6,     5,     7,    14,    73,    54,     0,     0,     0,
       0,    57,    59,    64,    55,    63,     0,     0,     0,     0,
     111,     0,    23,    15,     0,     0,     0,    86,    91,    84,
      85,    87,    90,     0,    82,    83,    78,    77,    76,     0,
       0,    51,    66,     0,    52,    53,    13,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,   119,   120,
     121,   122,   118,   123,   164,     0,     6,   115,   112,   113,
     114,     6,   117,   124,   125,   131,   136,   137,   160,   132,
     133,   134,   135,    16,     0,    22,    72,    88,    89,    71,
      65,    62,     0,     0,    69,   111,     0,    86,     0,     0,
      86,     0,     0,   170,   173,     0,     0,    25,    24,    29,
      33,   127,     0,   188,   161,     0,   197,   130,     0,   187,
       0,   189,     2,     6,   110,   111,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   149,     0,     0,     0,
      19,    67,    68,     0,     0,     0,   111,     0,   179,   180,
     181,   182,   183,   184,   176,     0,   111,     0,   193,   175,
     174,     0,     0,     0,    31,    30,     0,     0,     0,   111,
       0,     0,   167,   187,   190,   186,     0,     0,     0,   109,
       0,   138,   162,   168,    21,     0,   116,     0,     0,     0,
     172,   178,   201,   198,   171,     0,    28,    34,    35,    32,
     128,     0,     0,   163,     0,     0,   165,   192,   191,   126,
       0,    20,     6,   111,   195,   177,   111,     0,     0,    27,
      45,    46,    48,    49,    47,     0,   129,   194,   166,   185,
     169,     0,     0,   200,   199,     0,    36,     6,    39,    40,
      42,    43,   196,     0,     0,    38,     0,     0,    26,    37,
       0,    44,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,    53,     2,    27,    51,   108,    29,    73,
     134,   109,   157,   278,   158,   223,   159,   160,   257,   110,
     297,   298,   299,   300,   285,   111,   112,   113,    46,    64,
      65,    91,    92,    33,    56,    34,    35,   114,    84,    85,
      36,    37,    38,    39,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   197,   127,   242,   152,
     153,   221,   154,   214,   215,   236,   128,   171,   129,   130,
     131,   132,   218,   277
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -219
static const yytype_int16 yypact[] =
{
    -219,    16,   837,  -219,     9,    34,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,   -48,  -219,  -219,
    -219,  -219,  -219,   -16,    -7,  -219,    25,    19,  -219,     7,
    -219,  -219,  -219,    33,   -26,   894,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,   140,  -219,   140,    35,  -219,     4,    94,
      33,    19,  -219,  -219,    -1,  -219,    67,   171,    70,    72,
      73,  -219,  -219,    75,    81,  -219,   924,   171,   924,   -24,
     764,    56,   924,  -219,    71,    65,    68,  -219,  -219,  -219,
    -219,  -219,  -219,   102,  -219,  -219,  -219,  -219,  -219,   103,
      35,  -219,   867,    33,  -219,  -219,  -219,    19,    82,    27,
      63,   -43,    88,    63,    90,   257,    91,   -14,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,   183,    19,  -219,  -219,  -219,
    -219,    19,  -219,  -219,  -219,  -219,  -219,   916,   130,  -219,
    -219,  -219,  -219,  -219,   -22,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,   924,    33,    67,   764,   118,    46,   167,    63,
      14,   281,   -17,    11,  -219,   395,   137,  -219,  -219,   133,
    -219,   136,   180,    41,   162,   139,  -219,  -219,    49,   257,
     257,   150,  -219,    19,  -219,   764,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,  -219,   257,    90,   924,
     143,  -219,    67,   266,   924,   257,   764,   155,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,   257,   764,   135,  -219,  -219,
    -219,    63,   158,   144,  -219,  -219,   171,   144,   -29,   764,
     159,    90,  -219,   257,  -219,  -219,    -5,   170,   159,  -219,
     349,  -219,  -219,   200,  -219,   924,  -219,   177,   226,   432,
    -219,   281,   515,  -219,  -219,   924,   133,  -219,   274,  -219,
    -219,    37,   598,  -219,    69,   257,  -219,  -219,  -219,  -219,
      90,  -219,    19,   764,  -219,  -219,   764,   224,   181,  -219,
    -219,  -219,  -219,  -219,  -219,   171,  -219,  -219,  -219,  -219,
    -219,   171,   681,   764,  -219,   163,  -219,   -23,  -219,   188,
    -219,   274,  -219,   194,   235,  -219,   171,   171,  -219,  -219,
     189,  -219,  -219
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -219,  -219,  -219,   -50,  -219,  -219,  -219,   246,  -219,  -219,
    -219,  -219,  -219,  -219,  -219,  -219,    36,    30,   -27,  -219,
    -219,   -37,  -219,   -34,   -31,   272,   273,   275,  -219,  -219,
     196,   -59,  -219,   -64,   -45,   -66,  -219,   -57,  -219,  -219,
     132,   141,  -219,    61,  -134,  -112,  -219,  -219,  -219,  -219,
    -219,  -219,  -219,  -219,   -80,    98,  -219,  -219,  -218,   -95,
    -219,  -219,  -219,    47,  -219,    64,   -97,  -154,  -219,  -219,
    -219,    95,  -219,  -219
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -189
static const yytype_int16 yytable[] =
{
      83,    70,    93,   173,    93,    69,   135,   164,   162,    95,
      94,   203,    40,   263,   234,   219,     3,  -188,   155,   148,
     151,    52,   216,   151,    66,   165,   260,    74,   143,   199,
      57,    96,    47,   200,   217,    75,    76,   156,   167,   168,
     169,   240,   170,   220,    71,  -188,   265,   145,   144,    67,
     266,    55,   290,    72,   207,    42,    43,    77,    78,    79,
      80,    81,    82,    52,    48,    41,   174,   168,   169,   151,
     170,   175,   249,    49,    44,    45,   234,  -188,    93,    50,
     104,   105,   252,   201,   268,    75,    76,    54,    74,   235,
     237,   173,   286,   205,   230,   262,    60,   170,   202,   168,
     169,   243,   170,   233,    61,   170,    62,   147,    78,    79,
      80,    81,    82,    55,    68,    63,   104,   105,    74,   149,
     265,    75,    76,   239,   288,   248,   254,    86,   173,    87,
      88,    89,    90,   244,   243,   251,   133,   173,   247,   292,
     173,   151,   293,   150,    78,    79,    80,    81,    82,   137,
     173,   136,   138,   235,     6,     7,     8,     9,    10,   139,
     140,   198,   146,    11,    12,    13,    14,    15,   161,   258,
     163,   166,   204,   243,   206,    19,    20,    21,    22,   271,
     173,   173,   226,   261,   227,   289,     4,   229,    97,    98,
     228,   279,   172,   231,   232,    99,     5,     6,     7,     8,
       9,    10,   100,   238,   245,   101,    11,    12,    13,    14,
      15,    16,   250,   106,   255,   170,   102,    18,    19,    20,
      21,    22,   291,    23,   156,   103,    24,   267,   258,    75,
      76,   270,   272,   273,   301,   294,   104,   105,   295,   308,
     301,    75,    76,   303,   306,   309,   312,   304,    28,   310,
     301,    77,    78,    79,    80,    81,    82,   259,   296,   256,
     305,   106,    25,   107,    78,    79,    80,    81,    82,     4,
     307,    97,    98,   311,    30,    31,   246,    32,    99,     5,
       6,     7,     8,     9,    10,   100,   141,   224,   101,    11,
      12,    13,    14,    15,    16,   241,   225,   264,   275,   102,
      18,    19,    20,    21,    22,     0,    23,     0,   103,    24,
     104,   105,   253,     0,     0,    75,    76,     0,     0,   104,
     105,     0,     0,     0,    75,    76,   208,   209,   210,   211,
     212,   213,   280,   281,   282,   283,   284,   150,    78,    79,
      80,    81,    82,     0,   106,    25,   107,    78,    79,    80,
      81,    82,     4,     0,    97,    98,     0,     0,     0,   269,
       0,    99,     5,     6,     7,     8,     9,    10,   100,     0,
       0,   101,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,   102,    18,    19,    20,    21,    22,     0,    23,
       0,   103,    24,     0,     0,     0,     0,     0,   222,     0,
       0,     0,   104,   105,     0,     0,     0,    75,    76,     6,
       7,     8,     9,    10,     0,     0,     0,     0,    11,    12,
      13,    14,    15,     0,     0,     0,     0,   106,    25,   107,
      78,    79,    80,    81,    82,     4,     0,    97,    98,     0,
       0,     0,     0,     0,    99,     5,     6,     7,     8,     9,
      10,   100,     0,     0,   101,    11,    12,    13,    14,    15,
      16,     0,   274,     0,     0,   102,    18,    19,    20,    21,
      22,     0,    23,     0,   103,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   104,   105,     0,     0,     0,
      75,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,    25,   107,    78,    79,    80,    81,    82,     4,     0,
      97,    98,     0,   276,     0,     0,     0,    99,     5,     6,
       7,     8,     9,    10,   100,     0,     0,   101,    11,    12,
      13,    14,    15,    16,     0,     0,     0,     0,   102,    18,
      19,    20,    21,    22,     0,    23,     0,   103,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
       0,     0,     0,    75,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,    25,   107,    78,    79,    80,    81,
      82,     4,     0,    97,    98,     0,     0,     0,     0,     0,
      99,     5,     6,     7,     8,     9,    10,   100,     0,     0,
     101,    11,    12,    13,    14,    15,    16,     0,   287,     0,
       0,   102,    18,    19,    20,    21,    22,     0,    23,     0,
     103,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   104,   105,     0,     0,     0,    75,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,    25,   107,    78,
      79,    80,    81,    82,     4,     0,    97,    98,     0,     0,
       0,     0,     0,    99,     5,     6,     7,     8,     9,    10,
     100,     0,     0,   101,    11,    12,    13,    14,    15,    16,
       0,   302,     0,     0,   102,    18,    19,    20,    21,    22,
       0,    23,     0,   103,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,   105,     0,     0,     0,    75,
      76,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
      25,   107,    78,    79,    80,    81,    82,     4,     0,    97,
      98,     0,     0,     0,     0,     0,    99,     5,     6,     7,
       8,     9,    10,   100,     0,     0,   101,    11,    12,    13,
      14,    15,    16,     0,     0,     0,     0,   102,    18,    19,
      20,    21,    22,     0,    23,     0,   103,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   104,   105,     0,
       0,     0,    75,    76,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     0,   106,    25,   107,    78,    79,    80,    81,    82,
       5,     6,     7,     8,     9,    10,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,     0,     0,     0,
       4,    18,    19,    20,    21,    22,     0,    23,     0,     0,
      24,     6,     7,     8,     9,    10,     0,     0,     0,     0,
      11,    12,    13,    14,    15,     0,     0,    58,     0,   142,
       0,     0,    19,    20,    21,    22,     0,     0,     6,     7,
       8,     9,    10,     0,     0,     0,    25,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     4,     0,    19,
      20,    21,    22,     0,     0,     0,     0,     0,     6,     7,
       8,     9,    10,     0,     0,     0,    25,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,    19,
      20,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    59,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,     0,     0,     0,     0,     0,
       0,     0,     0,    25
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-219)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      57,    51,    66,   115,    68,    50,    72,   104,   103,    68,
      67,   145,     3,   231,   168,     4,     0,    31,    61,    99,
     100,    44,    39,   103,    20,   105,    55,    51,    92,    51,
      56,    55,    80,    55,    51,    58,    59,    80,    52,    53,
      54,   175,    56,    32,    45,    31,    51,    97,    93,    45,
      55,    80,   270,    54,   149,    21,    22,    80,    81,    82,
      83,    84,    85,    44,    80,    56,   116,    53,    54,   149,
      56,   121,   206,    80,    40,    41,   230,    31,   142,    54,
      53,    54,   216,   142,   238,    58,    59,    80,    51,   169,
     170,   203,    55,    47,    53,   229,    35,    56,   143,    53,
      54,   198,    56,    54,    43,    56,    45,    80,    81,    82,
      83,    84,    85,    80,    20,    80,    53,    54,    51,    56,
      51,    58,    59,   173,    55,   205,   221,    57,   240,    57,
      57,    56,    51,   199,   231,   215,    80,   249,   204,   273,
     252,   221,   276,    80,    81,    82,    83,    84,    85,    84,
     262,    80,    84,   233,    14,    15,    16,    17,    18,    57,
      57,    31,    80,    23,    24,    25,    26,    27,    80,   226,
      80,    80,    54,   270,     7,    35,    36,    37,    38,   245,
     292,   293,    45,   228,    51,   265,     3,     7,     5,     6,
      54,   255,     9,    31,    55,    12,    13,    14,    15,    16,
      17,    18,    19,    53,    61,    22,    23,    24,    25,    26,
      27,    28,    57,    78,    56,    56,    33,    34,    35,    36,
      37,    38,   272,    40,    80,    42,    43,    57,   285,    58,
      59,    31,    55,     7,   291,    11,    53,    54,    57,    45,
     297,    58,    59,    80,    56,    10,    57,   297,     2,   306,
     307,    80,    81,    82,    83,    84,    85,   227,   285,   223,
     297,    78,    79,    80,    81,    82,    83,    84,    85,     3,
     301,     5,     6,   307,     2,     2,    10,     2,    12,    13,
      14,    15,    16,    17,    18,    19,    90,   155,    22,    23,
      24,    25,    26,    27,    28,   197,   155,   233,   251,    33,
      34,    35,    36,    37,    38,    -1,    40,    -1,    42,    43,
      53,    54,   217,    -1,    -1,    58,    59,    -1,    -1,    53,
      54,    -1,    -1,    -1,    58,    59,    45,    46,    47,    48,
      49,    50,    58,    59,    60,    61,    62,    80,    81,    82,
      83,    84,    85,    -1,    78,    79,    80,    81,    82,    83,
      84,    85,     3,    -1,     5,     6,    -1,    -1,    -1,    10,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    -1,    40,
      -1,    42,    43,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    53,    54,    -1,    -1,    -1,    58,    59,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    78,    79,    80,
      81,    82,    83,    84,    85,     3,    -1,     5,     6,    -1,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    33,    34,    35,    36,    37,
      38,    -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    -1,
      58,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,     3,    -1,
       5,     6,    -1,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    -1,    40,    -1,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      -1,    -1,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    84,
      85,     3,    -1,     5,     6,    -1,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    -1,    -1,
      22,    23,    24,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    33,    34,    35,    36,    37,    38,    -1,    40,    -1,
      42,    43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    -1,    -1,    -1,    58,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    79,    80,    81,
      82,    83,    84,    85,     3,    -1,     5,     6,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    33,    34,    35,    36,    37,    38,
      -1,    40,    -1,    42,    43,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    -1,    -1,    -1,    58,
      59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,
      79,    80,    81,    82,    83,    84,    85,     3,    -1,     5,
       6,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    38,    -1,    40,    -1,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    -1,
      -1,    -1,    58,    59,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
       3,    34,    35,    36,    37,    38,    -1,    40,    -1,    -1,
      43,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    -1,    -1,     3,    -1,    32,
      -1,    -1,    35,    36,    37,    38,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    79,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,     3,    -1,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    14,    15,
      16,    17,    18,    -1,    -1,    -1,    79,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    87,    90,     0,     3,    13,    14,    15,    16,    17,
      18,    23,    24,    25,    26,    27,    28,    29,    34,    35,
      36,    37,    38,    40,    43,    79,    88,    91,    93,    94,
     111,   112,   113,   119,   121,   122,   126,   127,   128,   129,
       3,    56,    21,    22,    40,    41,   114,    80,    80,    80,
      54,    92,    44,    89,    80,    80,   120,    56,     3,    79,
     129,   129,   129,    80,   115,   116,    20,    45,    20,   120,
      89,    45,    54,    95,    51,    58,    59,    80,    81,    82,
      83,    84,    85,   123,   124,   125,    57,    57,    57,    56,
      51,   117,   118,   119,   123,   117,    55,     5,     6,    12,
      19,    22,    33,    42,    53,    54,    78,    80,    93,    97,
     105,   111,   112,   113,   123,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   143,   152,   154,
     155,   156,   157,    80,    96,   121,    80,    84,    84,    57,
      57,   116,    32,   119,   120,    89,    80,    80,   140,    56,
      80,   140,   145,   146,   148,    61,    80,    98,   100,   102,
     103,    80,   145,    80,   152,   140,    80,    52,    53,    54,
      56,   153,     9,   131,    89,    89,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,   142,    31,    51,
      55,   117,   120,   130,    54,    47,     7,   145,    45,    46,
      47,    48,    49,    50,   149,   150,    39,    51,   158,     4,
      32,   147,     3,   101,   126,   127,    45,    51,    54,     7,
      53,    31,    55,    54,   153,   140,   151,   140,    53,    89,
     130,   141,   144,   152,   121,    61,    10,   121,   140,   130,
      57,   140,   130,   157,   145,    56,   102,   104,   123,   103,
      55,   120,   130,   144,   151,    51,    55,    57,   153,    10,
      31,   121,    55,     7,    30,   149,     8,   159,    99,   119,
      58,    59,    60,    61,    62,   110,    55,    30,    55,   140,
     144,    89,   130,   130,    11,    57,   104,   106,   107,   108,
     109,   123,    30,    80,    89,   107,    56,   110,    45,    10,
     123,   109,    57
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
        case 50:
/* Line 1792 of yacc.c  */
#line 188 "musl.y"
    { new_type((yyvsp[(2) - (2)].nameval)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 190 "musl.y"
    { new_type((yyvsp[(2) - (4)].nameval)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 192 "musl.y"
    { new_type((yyvsp[(2) - (4)].nameval)); }
    break;


/* Line 1792 of yacc.c  */
#line 1924 "musl.tab.cpp"
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
#line 322 "musl.y"


