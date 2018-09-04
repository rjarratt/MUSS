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
#line 121 "musl.y"

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
     T_SWITCH = 294,
     T_THEN = 295,
     T_TYPE = 296,
     T_VSTORE = 297,
     T_WHILE = 298,
     T_WITHIN = 299,
     T_SEP = 300,
     T_EQUALS = 301,
     T_NOT_EQUALS = 302,
     T_LT = 303,
     T_GT = 304,
     T_LE = 305,
     T_GE = 306,
     T_PERIOD = 307,
     T_COMMA = 308,
     T_COLON = 309,
     T_CIRCUMFLEX = 310,
     T_L_BRACK = 311,
     T_R_BRACK = 312,
     T_L_PAREN = 313,
     T_R_PAREN = 314,
     T_PLUS = 315,
     T_MINUS = 316,
     T_STAR = 317,
     T_SLASH = 318,
     T_FSLASH = 319,
     T_AMPERSAND = 320,
     T_EXCLAMATION = 321,
     T_XOR = 322,
     T_RSUB = 323,
     T_RDIV = 324,
     T_ADDSTORE = 325,
     T_MULSTORE = 326,
     T_DIVSTORE = 327,
     T_ANDSTORE = 328,
     T_ORSTORE = 329,
     T_XORSTORE = 330,
     T_ASSIGN = 331,
     T_RSUBSTORE = 332,
     T_RDIVSTORE = 333,
     T_LLSHIFT = 334,
     T_RLSHIFT = 335,
     T_GOTO_OR_SUBSTORE = 336,
     T_TYPE_NAME = 337,
     T_PSPEC_NAME = 338,
     T_NAME = 339,
     T_CHAR_CONST = 340,
     T_MULTI_CHAR_CONST = 341,
     T_CH_STRING = 342,
     T_NUMBER = 343,
     T_HEXNUMBER = 344
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 133 "musl.y"

    char charval;
    char *stringval;
    char *nameval;
    unsigned int unsignedval;


/* Line 387 of yacc.c  */
#line 219 "musl.tab.cpp"
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
#line 247 "musl.tab.cpp"

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
#define YYLAST   1041

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  212
/* YYNRULES -- Number of states.  */
#define YYNSTATES  333

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   344

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
      85,    86,    87,    88,    89
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
     214,   216,   221,   225,   227,   229,   231,   234,   238,   242,
     246,   248,   251,   254,   256,   258,   260,   262,   264,   266,
     268,   271,   274,   276,   281,   283,   287,   289,   291,   293,
     295,   297,   299,   301,   303,   305,   307,   309,   311,   313,
     315,   317,   319,   321,   325,   328,   329,   331,   333,   335,
     337,   342,   344,   346,   348,   350,   352,   354,   356,   358,
     360,   362,   364,   369,   372,   377,   383,   386,   388,   390,
     392,   394,   396,   398,   400,   402,   406,   408,   410,   412,
     414,   416,   418,   420,   422,   424,   426,   428,   430,   432,
     434,   436,   438,   440,   442,   444,   446,   448,   450,   453,
     457,   462,   464,   469,   475,   479,   481,   485,   487,   491,
     495,   497,   499,   501,   504,   508,   511,   513,   515,   517,
     519,   521,   523,   527,   529,   530,   532,   534,   537,   541,
     546,   550,   554,   560,   566,   574,   577,   582,   586,   588,
     591,   596,   599
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      91,     0,    -1,    94,    92,    96,    93,   135,     9,    -1,
      29,    -1,    29,    84,    -1,    45,    -1,    -1,    94,    95,
      93,    -1,    -1,    97,    -1,   115,    -1,   116,    -1,   117,
      -1,    56,   124,    57,    -1,    98,    84,    -1,    98,    84,
      99,    -1,    98,    84,    46,    83,    -1,    28,    -1,    34,
      -1,    56,   100,    57,    -1,    56,   100,    57,    63,   125,
      -1,   100,    53,   125,    -1,   125,    -1,    -1,    22,   104,
      -1,    22,   102,    -1,    63,     3,    58,   103,    59,    84,
      46,    -1,   123,    -1,    63,   105,   106,    -1,   106,    -1,
     132,    -1,   131,    -1,   106,    53,   107,    -1,   107,    -1,
      84,    46,   108,    -1,   127,    -1,   127,   114,   108,    -1,
       6,    84,    56,   125,    57,    93,   110,    93,    10,    -1,
     110,   111,    -1,   111,    -1,   112,    -1,   112,    58,   127,
      59,    -1,   113,    -1,   127,    -1,   127,   114,   113,    -1,
      60,    -1,    61,    -1,    65,    -1,    62,    -1,    63,    -1,
      41,    84,    -1,    41,    84,    20,   121,    -1,    41,    84,
      46,   127,    -1,    44,    84,    20,   121,    -1,   123,   124,
      -1,    13,   118,   119,    -1,    22,    -1,    22,   134,    -1,
      42,    -1,    42,   134,    -1,    41,    -1,    21,    -1,   119,
      53,   120,    -1,   120,    -1,    84,    -1,    84,    58,    59,
      -1,   122,    -1,   122,    32,   121,    -1,   122,   123,   124,
      -1,   123,   124,    -1,   125,    -1,   125,    58,   127,    59,
      -1,   124,    53,    84,    -1,    84,    -1,   134,    -1,    82,
      -1,     3,    83,    -1,   126,   134,    59,    -1,   126,    82,
      59,    -1,   126,     3,    59,    -1,     3,    -1,     3,     3,
      -1,     3,    58,    -1,   128,    -1,   130,    -1,   129,    -1,
      86,    -1,    87,    -1,    84,    -1,    88,    -1,    60,    88,
      -1,    61,    88,    -1,    89,    -1,    89,    56,    88,    57,
      -1,    85,    -1,   128,    52,    88,    -1,    23,    -1,    24,
      -1,    25,    -1,    26,    -1,    27,    -1,    14,    -1,    15,
      -1,    16,    -1,    17,    -1,    18,    -1,    35,    -1,    36,
      -1,    37,    -1,    38,    -1,   132,    -1,   133,    -1,   131,
      -1,   135,   136,    93,    -1,   136,    93,    -1,    -1,   138,
      -1,   139,    -1,   141,    -1,   137,    -1,     5,    93,   135,
      10,    -1,   143,    -1,   116,    -1,    97,    -1,   101,    -1,
     109,    -1,   115,    -1,   117,    -1,   144,    -1,   145,    -1,
      84,    -1,    83,    -1,   142,    93,   135,    10,    -1,    33,
     140,    -1,    33,   140,    56,    57,    -1,    33,   140,    56,
     124,    57,    -1,    84,    54,    -1,   146,    -1,   160,    -1,
     161,    -1,   162,    -1,   163,    -1,   164,    -1,   147,    -1,
     149,    -1,   149,   148,   147,    -1,    60,    -1,    61,    -1,
      62,    -1,    63,    -1,    65,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    81,    -1,    71,    -1,
      72,    -1,    73,    -1,    74,    -1,    75,    -1,    76,    -1,
      77,    -1,    78,    -1,    79,    -1,    80,    -1,   158,    -1,
      55,   158,    -1,   158,    31,   150,    -1,    55,   158,    31,
     150,    -1,   127,    -1,   140,    56,   157,    57,    -1,    84,
      55,    56,   157,    57,    -1,    56,   146,    57,    -1,   158,
      -1,   158,    31,   150,    -1,   152,    -1,   152,   153,   151,
      -1,    58,   151,    59,    -1,   154,    -1,    32,    -1,     4,
      -1,   146,   155,    -1,   156,   146,   155,    -1,   156,   146,
      -1,    46,    -1,    47,    -1,    48,    -1,    49,    -1,    50,
      -1,    51,    -1,   157,    53,   146,    -1,   146,    -1,    -1,
      84,    -1,    83,    -1,    84,   159,    -1,    84,    55,   159,
      -1,    84,   159,    55,   159,    -1,    58,   146,    59,    -1,
      19,   151,   166,    -1,    43,   151,     7,   135,    30,    -1,
      12,   146,     7,   135,    30,    -1,    12,    84,    48,   146,
       7,   135,    30,    -1,    81,    84,    -1,    39,   146,    64,
     165,    -1,   165,    53,    84,    -1,    84,    -1,    53,   163,
      -1,    40,   135,   167,    11,    -1,     8,   135,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   142,   142,   143,   143,   144,   144,   146,   146,   147,
     147,   147,   147,   149,   152,   154,   156,   158,   160,   162,
     164,   166,   166,   166,   169,   175,   177,   178,   180,   180,
     181,   181,   182,   182,   183,   184,   184,   186,   187,   187,
     188,   188,   189,   190,   190,   191,   191,   191,   191,   191,
     194,   196,   198,   200,   202,   204,   206,   208,   210,   212,
     214,   216,   218,   218,   220,   222,   224,   224,   225,   225,
     227,   227,   229,   229,   233,   235,   239,   241,   243,   245,
     247,   249,   250,   252,   252,   252,   252,   252,   252,   253,
     253,   253,   253,   253,   254,   255,   257,   257,   257,   257,
     257,   258,   258,   258,   258,   258,   259,   259,   259,   259,
     262,   264,   266,   268,   268,   268,   270,   270,   270,   270,
     271,   273,   273,   273,   273,   273,   273,   273,   275,   275,
     277,   277,   278,   279,   279,   279,   281,   283,   283,   283,
     283,   285,   285,   287,   288,   288,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   292,   294,   296,
     298,   300,   302,   304,   306,   307,   307,   309,   309,   310,
     310,   311,   311,   313,   314,   314,   315,   315,   315,   315,
     315,   315,   317,   317,   317,   320,   320,   320,   320,   320,
     321,   323,   324,   325,   325,   326,   327,   328,   328,   330,
     330,   331,   331
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
  "T_REAL32", "T_REAL64", "T_REAL128", "T_SWITCH", "T_THEN", "T_TYPE",
  "T_VSTORE", "T_WHILE", "T_WITHIN", "T_SEP", "T_EQUALS", "T_NOT_EQUALS",
  "T_LT", "T_GT", "T_LE", "T_GE", "T_PERIOD", "T_COMMA", "T_COLON",
  "T_CIRCUMFLEX", "T_L_BRACK", "T_R_BRACK", "T_L_PAREN", "T_R_PAREN",
  "T_PLUS", "T_MINUS", "T_STAR", "T_SLASH", "T_FSLASH", "T_AMPERSAND",
  "T_EXCLAMATION", "T_XOR", "T_RSUB", "T_RDIV", "T_ADDSTORE", "T_MULSTORE",
  "T_DIVSTORE", "T_ANDSTORE", "T_ORSTORE", "T_XORSTORE", "T_ASSIGN",
  "T_RSUBSTORE", "T_RDIVSTORE", "T_LLSHIFT", "T_RLSHIFT",
  "T_GOTO_OR_SUBSTORE", "T_TYPE_NAME", "T_PSPEC_NAME", "T_NAME",
  "T_CHAR_CONST", "T_MULTI_CHAR_CONST", "T_CH_STRING", "T_NUMBER",
  "T_HEXNUMBER", "$accept", "module", "start_module", "separator",
  "imports", "import", "exports", "proc_dec", "proc_dec_spec", "pspec",
  "t_list", "lit_dec", "pointer_lit", "any_type", "integer_lits",
  "integer_type", "integer_list", "integer_list_item", "value", "data_vec",
  "literals", "literal_item", "literal", "const_expr", "const_op",
  "type_dec", "var_dec", "import_dec", "kind", "imp_list", "imp_list_item",
  "structure", "fields", "type", "name_list", "scalar_type",
  "vector_pointer", "const", "dec_integer", "char_const", "real_const",
  "logical", "integer", "real", "numeric_type", "statements", "statement",
  "block", "declarative_statement", "imperative_statement", "proc_name",
  "proc_defn", "proc_heading", "label_dec", "comp_st", "control_st",
  "computation", "opr_opd_seq", "operator", "operand", "context",
  "condition", "test", "logop", "comparison", "compare_list", "comparator",
  "p_list", "variable", "subscript", "if_st", "while_st", "for_st",
  "go_st", "switch_st", "nlist", "action", "else_cl", YY_NULL
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    95,    95,    96,    97,    97,    97,    98,    98,    99,
      99,   100,   100,   100,   101,   101,   102,   103,   104,   104,
     105,   105,   106,   106,   107,   108,   108,   109,   110,   110,
     111,   111,   112,   113,   113,   114,   114,   114,   114,   114,
     115,   115,   115,   115,   116,   117,   118,   118,   118,   118,
     118,   118,   119,   119,   120,   120,   121,   121,   122,   122,
     123,   123,   124,   124,   125,   125,   125,   125,   125,   125,
     125,   125,   126,   127,   127,   127,   127,   127,   127,   128,
     128,   128,   128,   128,   129,   130,   131,   131,   131,   131,
     131,   132,   132,   132,   132,   132,   133,   133,   133,   133,
     134,   134,   134,   135,   135,   135,   136,   136,   136,   136,
     137,   138,   138,   138,   138,   138,   138,   138,   139,   139,
     140,   140,   141,   142,   142,   142,   143,   144,   144,   144,
     144,   145,   145,   146,   147,   147,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   149,   149,   149,
     149,   149,   149,   149,   149,   150,   150,   151,   151,   152,
     152,   153,   153,   154,   155,   155,   156,   156,   156,   156,
     156,   156,   157,   157,   157,   158,   158,   158,   158,   158,
     159,   160,   161,   162,   162,   163,   164,   165,   165,   166,
     166,   167,   167
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
       1,     4,     3,     1,     1,     1,     2,     3,     3,     3,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     0,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     2,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       4,     1,     4,     5,     3,     1,     3,     1,     3,     3,
       1,     1,     1,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     0,     1,     1,     2,     3,     4,
       3,     3,     5,     5,     7,     2,     4,     3,     1,     2,
       4,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,    80,     0,   101,   102,   103,   104,
     105,    96,    97,    98,    99,   100,    17,     3,    18,   106,
     107,   108,   109,     0,     0,    75,     0,     6,     9,     0,
      10,    11,    12,     0,    70,     0,   112,   110,   111,    74,
      81,    82,    76,    61,    56,    60,    58,     0,     4,    50,
       0,     0,     6,     5,     7,    14,    73,    54,     0,     0,
       0,     0,    57,    59,    64,    55,    63,     0,     0,     0,
       0,   115,     0,    23,    15,     0,     0,     0,    88,    94,
      86,    87,    89,    92,     0,    83,    85,    84,    79,    78,
      77,     0,     0,    51,    66,     0,    52,    53,    13,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     196,    88,   123,   124,   125,   126,   122,   127,   171,     0,
       6,   119,   116,   117,     0,   118,     6,   121,   128,   129,
     137,   143,   144,   167,   138,   139,   140,   141,   142,    16,
       0,    22,    72,    90,    91,     0,    71,     0,    65,    62,
       0,     0,    69,   115,     0,    88,     0,     0,    88,     0,
       0,   177,   180,     0,     0,    25,    24,    29,    33,   131,
     130,   133,     0,     0,   196,   195,   168,     0,   205,   136,
       0,     0,   197,     2,     6,   114,   194,   115,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   156,     0,
       0,     0,    19,     0,    95,    67,    68,     0,     0,     0,
     115,     0,   186,   187,   188,   189,   190,   191,   183,     0,
     115,     0,   201,   182,   181,     0,     0,     0,    31,    30,
       0,     0,     0,     0,   115,     0,     0,   174,   194,   198,
       0,     0,   113,   193,     0,     0,   145,   169,   175,    21,
       0,    93,   120,     0,     0,     0,   179,   185,   212,   209,
     178,     0,    28,    34,    35,    32,   134,     0,   208,   206,
       0,   170,     0,   200,   199,     0,   172,   132,     0,    20,
       6,   115,   203,   184,   115,     0,     0,    27,    45,    46,
      48,    49,    47,     0,   135,     0,   202,   173,   192,   176,
       0,     0,   211,   210,     0,    36,   207,     6,    39,    40,
      42,    43,   204,     0,     0,    38,     0,     0,    26,    37,
       0,    44,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,    54,     2,    27,    52,   112,    29,    74,
     140,   113,   165,   296,   166,   237,   167,   168,   273,   114,
     317,   318,   319,   320,   303,   115,   116,   117,    47,    65,
      66,    93,    94,    33,    57,    34,    35,   118,    85,    86,
      87,    36,    37,    38,    39,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   209,   132,
     257,   160,   161,   235,   162,   228,   229,   254,   133,   182,
     134,   135,   136,   137,   138,   279,   232,   295
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -231
static const yytype_int16 yypact[] =
{
    -231,    82,    18,  -231,    15,    39,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,   -64,  -231,  -231,
    -231,  -231,  -231,    52,    56,  -231,   -17,   -19,  -231,    62,
    -231,  -231,  -231,    67,    95,   943,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,   151,  -231,   151,    75,  -231,    20,
     140,    67,   -19,  -231,  -231,    11,  -231,   108,    30,   103,
     104,   111,  -231,  -231,   113,   119,  -231,   959,    30,   959,
     -30,   867,    90,   959,  -231,    96,    91,    93,  -231,  -231,
    -231,  -231,  -231,   127,   125,   133,  -231,  -231,  -231,  -231,
    -231,   134,    75,  -231,   196,    67,  -231,  -231,  -231,   -19,
     110,   335,   248,     9,    -7,   422,   248,    73,   422,   114,
     152,    55,  -231,  -231,  -231,  -231,  -231,  -231,  -231,   258,
     -19,  -231,  -231,  -231,   153,  -231,   -19,  -231,  -231,  -231,
    -231,  -231,   938,   176,  -231,  -231,  -231,  -231,  -231,  -231,
      17,  -231,  -231,  -231,  -231,   128,  -231,   129,  -231,  -231,
     959,    67,   108,   867,   159,    89,   211,   248,    47,   154,
     -15,    33,  -231,   567,   178,  -231,  -231,   172,  -231,  -231,
    -231,   170,   163,   222,  -231,    13,   199,   179,  -231,  -231,
      41,   422,   180,  -231,   -19,  -231,   422,   867,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,   422,
      73,   959,   174,   181,  -231,  -231,   108,   345,   959,   422,
     867,   182,  -231,  -231,  -231,  -231,  -231,  -231,  -231,   422,
     867,   161,  -231,  -231,  -231,   248,   185,   156,  -231,  -231,
      30,   156,   -35,   160,   867,   188,    73,  -231,   422,  -231,
     189,   188,  -231,  -231,    26,   432,  -231,  -231,   216,  -231,
     959,  -231,  -231,   192,   243,   519,  -231,   154,   606,  -231,
    -231,   959,   172,  -231,    61,  -231,  -231,    54,  -231,   198,
     693,  -231,    81,  -231,  -231,   422,  -231,  -231,    73,  -231,
     -19,   867,  -231,  -231,   867,   242,   195,  -231,  -231,  -231,
    -231,  -231,  -231,    30,  -231,   171,  -231,  -231,  -231,  -231,
      30,   780,   867,  -231,   173,  -231,  -231,    43,  -231,   200,
    -231,    61,  -231,   210,   250,  -231,    30,    30,  -231,  -231,
     203,  -231,  -231
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,  -231,   -51,  -231,  -231,  -231,   263,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,    42,    46,   -14,  -231,
    -231,   -29,  -231,   -37,   -23,   298,   303,   305,  -231,  -231,
     218,   -54,  -231,   -65,   -45,   -68,  -231,   -58,  -231,  -231,
    -231,   148,   149,  -231,   -16,  -136,  -116,  -231,  -231,  -231,
     212,  -231,  -231,  -231,  -231,  -231,   -94,   106,  -231,  -231,
    -230,   -93,  -231,  -231,  -231,    50,  -231,    72,   -98,  -156,
    -231,  -231,  -231,    92,  -231,  -231,  -231,  -231
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -196
static const yytype_int16 yytable[] =
{
      84,    71,    95,   184,    95,   141,    70,   156,   159,   176,
      96,   172,   159,   173,   177,    97,   281,   217,    40,    61,
      48,     4,   276,    75,   249,   230,    53,    98,    62,   151,
      63,     5,     6,     7,     8,     9,    10,   233,   231,    51,
      67,    11,    12,    13,    14,    15,    16,    17,   153,    56,
     152,   255,    18,    19,    20,    21,    22,    72,   309,    23,
      43,    44,    24,   159,   221,   234,    68,    73,   245,   185,
     211,   181,   163,    41,   212,   187,   169,   170,  -195,   285,
      45,    46,     3,   286,   265,    95,  -195,   250,    53,   249,
      76,    77,   253,   164,   268,   284,   215,   248,    42,   181,
      25,   184,   180,    76,    77,   181,   216,    75,   280,   179,
     180,   304,   258,   181,    78,    79,    80,    81,    82,    83,
    -195,   298,   299,   300,   301,   264,   302,    78,    79,    80,
      81,    82,    83,   252,   285,   267,    49,   219,   307,   184,
      50,   159,   270,   259,   180,  -130,    55,   181,   258,   184,
     263,    56,   184,    58,   253,   311,   174,   175,   312,    64,
      69,    75,    88,    89,   184,     6,     7,     8,     9,    10,
      90,    91,    92,   139,    11,    12,    13,    14,    15,   143,
     142,   144,   274,   145,   146,   147,    19,    20,    21,    22,
     258,   308,   289,   148,   154,   184,   184,   277,   178,     4,
     222,   223,   224,   225,   226,   227,   297,   210,  -131,   186,
       6,     7,     8,     9,    10,   218,   213,   214,   220,    11,
      12,    13,    14,    15,   240,   241,   242,   243,   150,   244,
     246,    19,    20,    21,    22,   251,   247,   260,   261,   310,
     164,   266,   109,   271,   278,   274,   181,   288,   283,   290,
     291,   305,   321,   313,   314,   316,   328,   323,   326,   321,
     329,     4,   332,    99,   100,    28,   324,   183,   330,   321,
     101,     5,     6,     7,     8,     9,    10,   102,    25,   272,
     103,    11,    12,    13,    14,    15,    16,   275,   325,   315,
     331,   104,    18,    19,    20,    21,    22,   105,   327,    23,
      30,   106,    24,   107,   108,    31,   157,    32,    76,    77,
     149,   238,   239,   107,   108,   256,   171,   293,    76,    77,
     282,     0,     0,   269,     0,     0,     0,     0,     0,     0,
       0,   110,   158,    79,    80,    81,    82,    83,     0,   109,
      25,   110,   111,    79,    80,    81,    82,    83,     4,     0,
      99,   100,     0,     0,     0,   262,     0,   101,     5,     6,
       7,     8,     9,    10,   102,     0,     0,   103,    11,    12,
      13,    14,    15,    16,     0,     0,     0,     0,   104,    18,
      19,    20,    21,    22,   105,     0,    23,     0,   106,    24,
     107,   108,     0,     0,     0,    76,    77,     0,     0,     0,
     107,   108,     0,     0,     0,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   155,
      79,    80,    81,    82,    83,     0,   109,    25,   110,   111,
      79,    80,    81,    82,    83,     4,     0,    99,   100,     0,
       0,     0,   287,     0,   101,     5,     6,     7,     8,     9,
      10,   102,     0,     0,   103,    11,    12,    13,    14,    15,
      16,     0,     0,     0,     0,   104,    18,    19,    20,    21,
      22,   105,     0,    23,     0,   106,    24,   107,   108,     0,
       0,     0,    76,    77,     0,     0,     0,   107,   108,     0,
       0,     0,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   158,    79,    80,    81,
      82,    83,     0,   109,    25,   110,   111,    79,    80,    81,
      82,    83,     4,     0,    99,   100,     0,     0,     0,     0,
       0,   101,     5,     6,     7,     8,     9,    10,   102,     0,
       0,   103,    11,    12,    13,    14,    15,    16,     0,   292,
       0,     0,   104,    18,    19,    20,    21,    22,   105,     0,
      23,     0,   106,    24,     0,     0,     0,     0,     0,     0,
     236,     0,     0,     0,   107,   108,     0,     0,     0,    76,
      77,     6,     7,     8,     9,    10,     0,     0,     0,     0,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
     109,    25,   110,   111,    79,    80,    81,    82,    83,     4,
       0,    99,   100,     0,   294,     0,     0,     0,   101,     5,
       6,     7,     8,     9,    10,   102,     0,     0,   103,    11,
      12,    13,    14,    15,    16,     0,     0,     0,     0,   104,
      18,    19,    20,    21,    22,   105,     0,    23,     0,   106,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   107,   108,     0,     0,     0,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,    25,   110,
     111,    79,    80,    81,    82,    83,     4,     0,    99,   100,
       0,     0,     0,     0,     0,   101,     5,     6,     7,     8,
       9,    10,   102,     0,     0,   103,    11,    12,    13,    14,
      15,    16,     0,   306,     0,     0,   104,    18,    19,    20,
      21,    22,   105,     0,    23,     0,   106,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   107,   108,
       0,     0,     0,    76,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,    25,   110,   111,    79,    80,
      81,    82,    83,     4,     0,    99,   100,     0,     0,     0,
       0,     0,   101,     5,     6,     7,     8,     9,    10,   102,
       0,     0,   103,    11,    12,    13,    14,    15,    16,     0,
     322,     0,     0,   104,    18,    19,    20,    21,    22,   105,
       0,    23,     0,   106,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   108,     0,     0,     0,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,    25,   110,   111,    79,    80,    81,    82,    83,
       4,     0,    99,   100,     0,     0,     0,     0,     0,   101,
       5,     6,     7,     8,     9,    10,   102,     0,     0,   103,
      11,    12,    13,    14,    15,    16,     0,     0,     0,     0,
     104,    18,    19,    20,    21,    22,   105,     0,    23,     0,
     106,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   107,   108,     0,     0,     0,    76,    77,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,     0,   109,    25,
     110,   111,    79,    80,    81,    82,    83,     6,     7,     8,
       9,    10,     4,     0,     0,     0,    11,    12,    13,    14,
      15,     0,     0,     6,     7,     8,     9,    10,    19,    20,
      21,    22,    11,    12,    13,    14,    15,     0,     0,     0,
       0,     0,     0,     0,    19,    20,    21,    22,   188,   189,
     190,   191,     0,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,     0,     0,     0,     0,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-231)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      58,    52,    67,   119,    69,    73,    51,   101,   102,   107,
      68,   105,   106,   106,   108,    69,   246,   153,     3,    35,
      84,     3,    57,    53,   180,    40,    45,    57,    44,    94,
      46,    13,    14,    15,    16,    17,    18,     4,    53,    56,
      20,    23,    24,    25,    26,    27,    28,    29,    99,    84,
      95,   187,    34,    35,    36,    37,    38,    46,   288,    41,
      21,    22,    44,   157,   157,    32,    46,    56,    55,   120,
      53,    58,    63,    58,    57,   126,    83,    84,    31,    53,
      41,    42,     0,    57,   220,   150,    31,   181,    45,   245,
      60,    61,   186,    84,   230,   251,   150,    56,    83,    58,
      82,   217,    55,    60,    61,    58,   151,    53,   244,    54,
      55,    57,   210,    58,    84,    85,    86,    87,    88,    89,
      31,    60,    61,    62,    63,   219,    65,    84,    85,    86,
      87,    88,    89,   184,    53,   229,    84,    48,    57,   255,
      84,   235,   235,   211,    55,    56,    84,    58,   246,   265,
     218,    84,   268,    58,   248,   291,    83,    84,   294,    84,
      20,    53,    59,    59,   280,    14,    15,    16,    17,    18,
      59,    58,    53,    83,    23,    24,    25,    26,    27,    88,
      84,    88,   240,    56,    59,    52,    35,    36,    37,    38,
     288,   285,   260,    59,    84,   311,   312,   242,    84,     3,
      46,    47,    48,    49,    50,    51,   271,    31,    56,    56,
      14,    15,    16,    17,    18,    56,    88,    88,     7,    23,
      24,    25,    26,    27,    46,    53,    56,    64,    32,     7,
      31,    35,    36,    37,    38,    55,    57,    63,    57,   290,
      84,    59,    81,    58,    84,   303,    58,    31,    59,    57,
       7,    53,   310,    11,    59,    84,    46,    84,    58,   317,
      10,     3,    59,     5,     6,     2,   317,     9,   326,   327,
      12,    13,    14,    15,    16,    17,    18,    19,    82,   237,
      22,    23,    24,    25,    26,    27,    28,   241,   317,   303,
     327,    33,    34,    35,    36,    37,    38,    39,   321,    41,
       2,    43,    44,    55,    56,     2,    58,     2,    60,    61,
      92,   163,   163,    55,    56,   209,   104,   267,    60,    61,
     248,    -1,    -1,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    88,    89,    -1,    81,
      82,    83,    84,    85,    86,    87,    88,    89,     3,    -1,
       5,     6,    -1,    -1,    -1,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    -1,    43,    44,
      55,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      55,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    84,
      85,    86,    87,    88,    89,    -1,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     3,    -1,     5,     6,    -1,
      -1,    -1,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    -1,    -1,    22,    23,    24,    25,    26,    27,
      28,    -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    -1,    43,    44,    55,    56,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    55,    56,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    83,    84,    85,    86,    87,
      88,    89,    -1,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     3,    -1,     5,     6,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,    60,
      61,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     3,
      -1,     5,     6,    -1,     8,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    -1,    -1,    22,    23,
      24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    -1,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    55,    56,    -1,    -1,    -1,    60,    61,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     3,    -1,     5,     6,
      -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    -1,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,
      -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     3,    -1,     5,     6,    -1,    -1,    -1,
      -1,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      -1,    -1,    22,    23,    24,    25,    26,    27,    28,    -1,
      30,    -1,    -1,    33,    34,    35,    36,    37,    38,    39,
      -1,    41,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       3,    -1,     5,     6,    -1,    -1,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    55,    56,    -1,    -1,    -1,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    14,    15,    16,
      17,    18,     3,    -1,    -1,    -1,    23,    24,    25,    26,
      27,    -1,    -1,    14,    15,    16,    17,    18,    35,    36,
      37,    38,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    60,    61,
      62,    63,    -1,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    91,    94,     0,     3,    13,    14,    15,    16,    17,
      18,    23,    24,    25,    26,    27,    28,    29,    34,    35,
      36,    37,    38,    41,    44,    82,    92,    95,    97,    98,
     115,   116,   117,   123,   125,   126,   131,   132,   133,   134,
       3,    58,    83,    21,    22,    41,    42,   118,    84,    84,
      84,    56,    96,    45,    93,    84,    84,   124,    58,     3,
      82,   134,   134,   134,    84,   119,   120,    20,    46,    20,
     124,    93,    46,    56,    99,    53,    60,    61,    84,    85,
      86,    87,    88,    89,   127,   128,   129,   130,    59,    59,
      59,    58,    53,   121,   122,   123,   127,   121,    57,     5,
       6,    12,    19,    22,    33,    39,    43,    55,    56,    81,
      83,    84,    97,   101,   109,   115,   116,   117,   127,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   149,   158,   160,   161,   162,   163,   164,    83,
     100,   125,    84,    88,    88,    56,    59,    52,    59,   120,
      32,   123,   124,    93,    84,    84,   146,    58,    84,   146,
     151,   152,   154,    63,    84,   102,   104,   106,   107,    83,
      84,   140,   146,   151,    83,    84,   158,   146,    84,    54,
      55,    58,   159,     9,   136,    93,    56,    93,    60,    61,
      62,    63,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,   148,
      31,    53,    57,    88,    88,   121,   124,   135,    56,    48,
       7,   151,    46,    47,    48,    49,    50,    51,   155,   156,
      40,    53,   166,     4,    32,   153,     3,   105,   131,   132,
      46,    53,    56,    64,     7,    55,    31,    57,    56,   159,
     146,    55,    93,   146,   157,   135,   147,   150,   158,   125,
      63,    57,    10,   125,   146,   135,    59,   146,   135,   163,
     151,    58,   106,   108,   127,   107,    57,   124,    84,   165,
     135,   150,   157,    59,   159,    53,    57,    10,    31,   125,
      57,     7,    30,   155,     8,   167,   103,   123,    60,    61,
      62,    63,    65,   114,    57,    53,    30,    57,   146,   150,
      93,   135,   135,    11,    59,   108,    84,   110,   111,   112,
     113,   127,    30,    84,    93,   111,    58,   114,    46,    10,
     127,   113,    59
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
        case 14:
/* Line 1792 of yacc.c  */
#line 152 "musl.y"
    { new_pspec((yyvsp[(2) - (2)].nameval)); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 154 "musl.y"
    { new_pspec((yyvsp[(2) - (3)].nameval)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 156 "musl.y"
    { new_pspec((yyvsp[(2) - (4)].nameval)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 194 "musl.y"
    { new_type((yyvsp[(2) - (2)].nameval)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 196 "musl.y"
    { new_type((yyvsp[(2) - (4)].nameval)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 198 "musl.y"
    { new_type((yyvsp[(2) - (4)].nameval)); }
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 279 "musl.y"
    { new_pspec((yyvsp[(2) - (2)].nameval)); }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 279 "musl.y"
    { new_pspec((yyvsp[(2) - (4)].nameval)); }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 279 "musl.y"
    { new_pspec((yyvsp[(2) - (5)].nameval)); }
    break;


/* Line 1792 of yacc.c  */
#line 1986 "musl.tab.cpp"
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
#line 332 "musl.y"


