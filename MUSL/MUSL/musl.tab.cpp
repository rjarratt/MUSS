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
#line 118 "musl.y"

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
     T_COMMA = 307,
     T_COLON = 308,
     T_CIRCUMFLEX = 309,
     T_L_BRACK = 310,
     T_R_BRACK = 311,
     T_L_PAREN = 312,
     T_R_PAREN = 313,
     T_PLUS = 314,
     T_MINUS = 315,
     T_STAR = 316,
     T_SLASH = 317,
     T_FSLASH = 318,
     T_AMPERSAND = 319,
     T_EXCLAMATION = 320,
     T_XOR = 321,
     T_RSUB = 322,
     T_RDIV = 323,
     T_ADDSTORE = 324,
     T_MULSTORE = 325,
     T_DIVSTORE = 326,
     T_ANDSTORE = 327,
     T_ORSTORE = 328,
     T_XORSTORE = 329,
     T_ASSIGN = 330,
     T_RSUBSTORE = 331,
     T_RDIVSTORE = 332,
     T_LLSHIFT = 333,
     T_RLSHIFT = 334,
     T_GOTO_OR_SUBSTORE = 335,
     T_TYPE_NAME = 336,
     T_PSPEC_NAME = 337,
     T_NAME = 338,
     T_CHAR_CONST = 339,
     T_MULTI_CHAR_CONST = 340,
     T_CH_STRING = 341,
     T_NUMBER = 342,
     T_HEXNUMBER = 343
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 130 "musl.y"

    char charval;
    char *stringval;
    char *nameval;
    unsigned int unsignedval;


/* Line 387 of yacc.c  */
#line 218 "musl.tab.cpp"
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
#line 246 "musl.tab.cpp"

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
#define YYLAST   1069

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  77
/* YYNRULES -- Number of rules.  */
#define YYNRULES  209
/* YYNRULES -- Number of states.  */
#define YYNSTATES  328

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   343

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
      85,    86,    87,    88
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
     269,   272,   274,   279,   281,   283,   285,   287,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   307,   309,   311,
     313,   315,   319,   322,   323,   325,   327,   329,   331,   336,
     338,   340,   342,   344,   346,   348,   350,   352,   354,   356,
     358,   363,   366,   371,   377,   380,   382,   384,   386,   388,
     390,   392,   394,   396,   400,   402,   404,   406,   408,   410,
     412,   414,   416,   418,   420,   422,   424,   426,   428,   430,
     432,   434,   436,   438,   440,   442,   444,   447,   451,   456,
     458,   463,   469,   473,   475,   479,   481,   485,   489,   491,
     493,   495,   498,   502,   505,   507,   509,   511,   513,   515,
     517,   521,   523,   524,   526,   529,   533,   538,   542,   546,
     552,   558,   566,   569,   574,   578,   580,   583,   588,   591
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      90,     0,    -1,    93,    91,    95,    92,   133,     9,    -1,
      29,    -1,    29,    83,    -1,    45,    -1,    -1,    93,    94,
      92,    -1,    -1,    96,    -1,   114,    -1,   115,    -1,   116,
      -1,    55,   123,    56,    -1,    97,    83,    -1,    97,    83,
      98,    -1,    97,    83,    46,    83,    -1,    28,    -1,    34,
      -1,    55,    99,    56,    -1,    55,    99,    56,    62,   124,
      -1,    99,    52,   124,    -1,   124,    -1,    -1,    22,   103,
      -1,    22,   101,    -1,    62,     3,    57,   102,    58,    83,
      46,    -1,   122,    -1,    62,   104,   105,    -1,   105,    -1,
     130,    -1,   129,    -1,   105,    52,   106,    -1,   106,    -1,
      83,    46,   107,    -1,   126,    -1,   126,   113,   107,    -1,
       6,    83,    55,   124,    56,    92,   109,    92,    10,    -1,
     109,   110,    -1,   110,    -1,   111,    -1,   111,    57,   126,
      58,    -1,   112,    -1,   126,    -1,   126,   113,   112,    -1,
      59,    -1,    60,    -1,    64,    -1,    61,    -1,    62,    -1,
      41,    83,    -1,    41,    83,    20,   120,    -1,    41,    83,
      46,   126,    -1,    44,    83,    20,   120,    -1,   122,   123,
      -1,    13,   117,   118,    -1,    22,    -1,    22,   132,    -1,
      42,    -1,    42,   132,    -1,    41,    -1,    21,    -1,   118,
      52,   119,    -1,   119,    -1,    83,    -1,    83,    57,    58,
      -1,   121,    -1,   121,    32,   120,    -1,   121,   122,   123,
      -1,   122,   123,    -1,   124,    -1,   124,    57,   126,    58,
      -1,   123,    52,    83,    -1,    83,    -1,   132,    -1,    81,
      -1,     3,    82,    -1,   125,   132,    58,    -1,   125,    81,
      58,    -1,   125,     3,    58,    -1,     3,    -1,     3,     3,
      -1,     3,    57,    -1,   127,    -1,   128,    -1,    85,    -1,
      86,    -1,    83,    -1,    87,    -1,    59,    87,    -1,    60,
      87,    -1,    88,    -1,    88,    55,    87,    56,    -1,    84,
      -1,    23,    -1,    24,    -1,    25,    -1,    26,    -1,    27,
      -1,    14,    -1,    15,    -1,    16,    -1,    17,    -1,    18,
      -1,    35,    -1,    36,    -1,    37,    -1,    38,    -1,   130,
      -1,   131,    -1,   129,    -1,   133,   134,    92,    -1,   134,
      92,    -1,    -1,   136,    -1,   137,    -1,   139,    -1,   135,
      -1,     5,    92,   133,    10,    -1,   141,    -1,   115,    -1,
      96,    -1,   100,    -1,   108,    -1,   114,    -1,   116,    -1,
     142,    -1,   143,    -1,    83,    -1,    82,    -1,   140,    92,
     133,    10,    -1,    33,   138,    -1,    33,   138,    55,    56,
      -1,    33,   138,    55,   123,    56,    -1,    83,    53,    -1,
     144,    -1,   158,    -1,   159,    -1,   160,    -1,   161,    -1,
     162,    -1,   145,    -1,   147,    -1,   147,   146,   145,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,    64,    -1,
      65,    -1,    66,    -1,    67,    -1,    68,    -1,    69,    -1,
      80,    -1,    70,    -1,    71,    -1,    72,    -1,    73,    -1,
      74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,
      79,    -1,   156,    -1,    54,   156,    -1,   156,    31,   148,
      -1,    54,   156,    31,   148,    -1,   126,    -1,   138,    55,
     155,    56,    -1,    83,    54,    55,   155,    56,    -1,    55,
     144,    56,    -1,   156,    -1,   156,    31,   148,    -1,   150,
      -1,   150,   151,   149,    -1,    57,   149,    58,    -1,   152,
      -1,    32,    -1,     4,    -1,   144,   153,    -1,   154,   144,
     153,    -1,   154,   144,    -1,    46,    -1,    47,    -1,    48,
      -1,    49,    -1,    50,    -1,    51,    -1,   155,    52,   144,
      -1,   144,    -1,    -1,    83,    -1,    83,   157,    -1,    83,
      54,   157,    -1,    83,   157,    54,   157,    -1,    57,   144,
      58,    -1,    19,   149,   164,    -1,    43,   149,     7,   133,
      30,    -1,    12,   144,     7,   133,    30,    -1,    12,    83,
      48,   144,     7,   133,    30,    -1,    80,    83,    -1,    39,
     144,    63,   163,    -1,   163,    52,    83,    -1,    83,    -1,
      52,   161,    -1,    40,   133,   165,    11,    -1,     8,   133,
      -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   139,   139,   140,   140,   141,   141,   143,   143,   144,
     144,   144,   144,   146,   149,   151,   153,   155,   157,   159,
     161,   163,   163,   163,   166,   172,   174,   175,   177,   177,
     178,   178,   179,   179,   180,   181,   181,   183,   184,   184,
     185,   185,   186,   187,   187,   188,   188,   188,   188,   188,
     191,   193,   195,   197,   199,   201,   203,   205,   207,   209,
     211,   213,   215,   215,   217,   219,   221,   221,   222,   222,
     224,   224,   226,   226,   230,   232,   236,   238,   240,   242,
     244,   246,   247,   249,   249,   249,   249,   249,   250,   250,
     250,   250,   250,   251,   253,   253,   253,   253,   253,   254,
     254,   254,   254,   254,   255,   255,   255,   255,   258,   260,
     262,   264,   264,   264,   266,   266,   266,   266,   267,   269,
     269,   269,   269,   269,   269,   269,   271,   271,   273,   273,
     274,   275,   275,   275,   277,   279,   279,   279,   279,   281,
     281,   283,   284,   284,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   288,   290,   292,   294,   296,
     298,   300,   302,   303,   303,   305,   305,   306,   306,   307,
     307,   309,   310,   310,   311,   311,   311,   311,   311,   311,
     313,   313,   313,   316,   316,   316,   316,   317,   319,   320,
     321,   321,   322,   323,   324,   324,   326,   326,   327,   327
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
  "T_LT", "T_GT", "T_LE", "T_GE", "T_COMMA", "T_COLON", "T_CIRCUMFLEX",
  "T_L_BRACK", "T_R_BRACK", "T_L_PAREN", "T_R_PAREN", "T_PLUS", "T_MINUS",
  "T_STAR", "T_SLASH", "T_FSLASH", "T_AMPERSAND", "T_EXCLAMATION", "T_XOR",
  "T_RSUB", "T_RDIV", "T_ADDSTORE", "T_MULSTORE", "T_DIVSTORE",
  "T_ANDSTORE", "T_ORSTORE", "T_XORSTORE", "T_ASSIGN", "T_RSUBSTORE",
  "T_RDIVSTORE", "T_LLSHIFT", "T_RLSHIFT", "T_GOTO_OR_SUBSTORE",
  "T_TYPE_NAME", "T_PSPEC_NAME", "T_NAME", "T_CHAR_CONST",
  "T_MULTI_CHAR_CONST", "T_CH_STRING", "T_NUMBER", "T_HEXNUMBER",
  "$accept", "module", "start_module", "separator", "imports", "import",
  "exports", "proc_dec", "proc_dec_spec", "pspec", "t_list", "lit_dec",
  "pointer_lit", "any_type", "integer_lits", "integer_type",
  "integer_list", "integer_list_item", "value", "data_vec", "literals",
  "literal_item", "literal", "const_expr", "const_op", "type_dec",
  "var_dec", "import_dec", "kind", "imp_list", "imp_list_item",
  "structure", "fields", "type", "name_list", "scalar_type",
  "vector_pointer", "const", "dec_integer", "char_const", "logical",
  "integer", "real", "numeric_type", "statements", "statement", "block",
  "declarative_statement", "imperative_statement", "proc_name",
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
     335,   336,   337,   338,   339,   340,   341,   342,   343
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    94,    94,    95,    96,    96,    96,    97,    97,    98,
      98,    99,    99,    99,   100,   100,   101,   102,   103,   103,
     104,   104,   105,   105,   106,   107,   107,   108,   109,   109,
     110,   110,   111,   112,   112,   113,   113,   113,   113,   113,
     114,   114,   114,   114,   115,   116,   117,   117,   117,   117,
     117,   117,   118,   118,   119,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   124,   124,   124,   124,
     124,   124,   125,   126,   126,   126,   126,   126,   127,   127,
     127,   127,   127,   128,   129,   129,   129,   129,   129,   130,
     130,   130,   130,   130,   131,   131,   131,   131,   132,   132,
     132,   133,   133,   133,   134,   134,   134,   134,   135,   136,
     136,   136,   136,   136,   136,   136,   137,   137,   138,   138,
     139,   140,   140,   140,   141,   142,   142,   142,   142,   143,
     143,   144,   145,   145,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   147,   147,   147,   147,   147,
     147,   147,   147,   148,   148,   149,   149,   150,   150,   151,
     151,   152,   153,   153,   154,   154,   154,   154,   154,   154,
     155,   155,   155,   156,   156,   156,   156,   157,   158,   159,
     160,   160,   161,   162,   163,   163,   164,   164,   165,   165
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
       1,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     0,     1,     1,     1,     1,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     2,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     1,
       4,     5,     3,     1,     3,     1,     3,     3,     1,     1,
       1,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     0,     1,     2,     3,     4,     3,     3,     5,
       5,     7,     2,     4,     3,     1,     2,     4,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,    80,     0,    99,   100,   101,   102,
     103,    94,    95,    96,    97,    98,    17,     3,    18,   104,
     105,   106,   107,     0,     0,    75,     0,     6,     9,     0,
      10,    11,    12,     0,    70,     0,   110,   108,   109,    74,
      81,    82,    76,    61,    56,    60,    58,     0,     4,    50,
       0,     0,     6,     5,     7,    14,    73,    54,     0,     0,
       0,     0,    57,    59,    64,    55,    63,     0,     0,     0,
       0,   113,     0,    23,    15,     0,     0,     0,    87,    93,
      85,    86,    88,    91,     0,    83,    84,    79,    78,    77,
       0,     0,    51,    66,     0,    52,    53,    13,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
      87,   121,   122,   123,   124,   120,   125,   169,     0,     6,
     117,   114,   115,     0,   116,     6,   119,   126,   127,   135,
     141,   142,   165,   136,   137,   138,   139,   140,    16,     0,
      22,    72,    89,    90,     0,    71,    65,    62,     0,     0,
      69,   113,     0,    87,     0,     0,    87,     0,     0,   175,
     178,     0,     0,    25,    24,    29,    33,   128,   131,     0,
       0,   193,   166,     0,   202,   134,     0,     0,   194,     2,
       6,   112,   192,   113,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   154,     0,     0,     0,    19,     0,
      67,    68,     0,     0,     0,   113,     0,   184,   185,   186,
     187,   188,   189,   181,     0,   113,     0,   198,   180,   179,
       0,     0,     0,    31,    30,     0,     0,     0,     0,   113,
       0,     0,   172,   192,   195,     0,     0,   111,   191,     0,
       0,   143,   167,   173,    21,     0,    92,   118,     0,     0,
       0,   177,   183,   209,   206,   176,     0,    28,    34,    35,
      32,   132,     0,   205,   203,     0,   168,     0,   197,   196,
       0,   170,   130,     0,    20,     6,   113,   200,   182,   113,
       0,     0,    27,    45,    46,    48,    49,    47,     0,   133,
       0,   199,   171,   190,   174,     0,     0,   208,   207,     0,
      36,   204,     6,    39,    40,    42,    43,   201,     0,     0,
      38,     0,     0,    26,    37,     0,    44,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,    54,     2,    27,    52,   111,    29,    74,
     139,   112,   163,   291,   164,   232,   165,   166,   268,   113,
     312,   313,   314,   315,   298,   114,   115,   116,    47,    65,
      66,    92,    93,    33,    57,    34,    35,   117,    85,    86,
      36,    37,    38,    39,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   205,   131,   252,
     158,   159,   230,   160,   223,   224,   249,   132,   178,   133,
     134,   135,   136,   137,   274,   227,   290
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -226
static const yytype_int16 yypact[] =
{
    -226,    27,   138,  -226,     6,    43,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,   -29,  -226,  -226,
    -226,  -226,  -226,   -26,    -1,  -226,   -23,    44,  -226,     4,
    -226,  -226,  -226,     7,     9,   955,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  1002,  -226,  1002,    12,  -226,    10,
      78,     7,    44,  -226,  -226,   -22,  -226,    47,   121,    49,
      57,    58,  -226,  -226,    67,    73,  -226,   971,   121,   971,
     -18,   855,    48,   971,  -226,    50,    39,    45,  -226,  -226,
    -226,  -226,  -226,    79,    81,  -226,  -226,  -226,  -226,  -226,
      84,    12,  -226,   930,     7,  -226,  -226,  -226,    44,    53,
     244,   143,   -31,   -43,   330,   143,    54,   330,    66,  -226,
     -11,  -226,  -226,  -226,  -226,  -226,  -226,  -226,   253,    44,
    -226,  -226,  -226,   103,  -226,    44,  -226,  -226,  -226,  -226,
    -226,   989,   128,  -226,  -226,  -226,  -226,  -226,  -226,   -15,
    -226,  -226,  -226,  -226,    82,  -226,  -226,  -226,   971,     7,
      47,   855,   113,     5,   163,   143,    -6,    63,   -17,    13,
    -226,   472,   125,  -226,  -226,   126,  -226,  -226,   129,   120,
     179,   -28,   156,   133,  -226,  -226,    23,   330,   136,  -226,
      44,  -226,   330,   855,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,   330,    54,   971,   134,   139,
    -226,    47,   339,   971,   330,   855,   141,  -226,  -226,  -226,
    -226,  -226,  -226,  -226,   330,   855,   130,  -226,  -226,  -226,
     143,   154,   131,  -226,  -226,   121,   131,   -34,   132,   855,
     155,    54,  -226,   330,  -226,   158,   155,  -226,  -226,    15,
     425,  -226,  -226,   182,  -226,   971,  -226,  -226,   161,   211,
     511,  -226,    63,   597,  -226,  -226,   971,   126,  -226,    42,
    -226,  -226,    21,  -226,   168,   683,  -226,    71,  -226,  -226,
     330,  -226,  -226,    54,  -226,    44,   855,  -226,  -226,   855,
     210,   164,  -226,  -226,  -226,  -226,  -226,  -226,   121,  -226,
     140,  -226,  -226,  -226,  -226,   121,   769,   855,  -226,   149,
    -226,  -226,    34,  -226,   167,  -226,    42,  -226,   187,   225,
    -226,   121,   121,  -226,  -226,   178,  -226,  -226
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -226,  -226,  -226,   -51,  -226,  -226,  -226,   235,  -226,  -226,
    -226,  -226,  -226,  -226,  -226,  -226,    11,     2,   -59,  -226,
    -226,   -71,  -226,   -80,   -72,   243,   246,   247,  -226,  -226,
     159,   -56,  -226,   -65,   -44,   -67,  -226,   -58,  -226,  -226,
      85,    90,  -226,    26,  -139,  -115,  -226,  -226,  -226,   150,
    -226,  -226,  -226,  -226,  -226,   -86,    52,  -226,  -226,  -225,
    -100,  -226,  -226,  -226,   -10,  -226,    17,   -98,  -165,  -226,
    -226,  -226,    29,  -226,  -226,  -226,  -226
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -194
static const yytype_int16 yytable[] =
{
      84,    71,    94,   180,    94,   170,   140,    70,   172,    40,
      95,   244,   212,    96,   154,   157,   276,   228,   169,   157,
    -193,   173,   271,   225,    72,  -193,   240,     3,   149,   177,
      67,   161,    51,    73,    75,   226,  -193,   207,    97,   109,
     167,   208,   175,   176,   250,   229,   177,   151,   176,    56,
     150,   177,   162,   214,    48,   216,    68,    49,   304,   176,
    -128,    61,   177,    41,    43,    44,    58,   280,   181,   157,
      62,   281,    63,    75,   183,   244,   260,   299,   243,    53,
     177,   279,    50,    94,    45,    46,   263,    55,    42,    53,
      56,   245,   210,    76,    77,    64,   248,   180,    69,    75,
     275,   293,   294,   295,   296,   211,   297,    87,   253,   217,
     218,   219,   220,   221,   222,    88,    89,    78,    79,    80,
      81,    82,    83,   280,    90,    91,   142,   302,   259,   247,
     265,   138,   143,   141,   144,   180,   152,   171,   262,   145,
     254,     4,   146,   253,   157,   180,   258,   306,   180,   174,
     307,     5,     6,     7,     8,     9,    10,   248,   182,   206,
     180,    11,    12,    13,    14,    15,    16,    17,   213,   209,
     215,   235,    18,    19,    20,    21,    22,   269,   236,    23,
      76,    77,    24,   238,   237,   253,   239,   241,   284,   242,
     246,   180,   180,   272,   303,   256,   255,   106,   107,   261,
     155,   292,    76,    77,    78,    79,    80,    81,    82,    83,
     108,   266,   177,   283,   162,   273,   278,   285,   286,    25,
     300,   308,   309,   311,   321,   109,   156,    79,    80,    81,
      82,    83,   318,   323,   305,   324,   327,    28,   270,   310,
     269,   320,   326,   267,   322,    30,   233,   316,    31,    32,
     147,   234,   288,   168,   316,   264,     4,   251,    98,    99,
     277,   319,   179,   325,   316,   100,     5,     6,     7,     8,
       9,    10,   101,     0,     0,   102,    11,    12,    13,    14,
      15,    16,     0,     0,     0,     0,   103,    18,    19,    20,
      21,    22,   104,     0,    23,     0,   105,    24,   106,   107,
       0,     0,     0,    76,    77,     0,     0,   106,   107,     0,
       0,     0,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   153,    79,    80,
      81,    82,    83,   108,    25,   109,   110,    79,    80,    81,
      82,    83,     4,     0,    98,    99,     0,     0,     0,   257,
       0,   100,     5,     6,     7,     8,     9,    10,   101,     0,
       0,   102,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,   103,    18,    19,    20,    21,    22,   104,     0,
      23,     0,   105,    24,   106,   107,     0,     0,     0,    76,
      77,     0,     0,   106,   107,     0,     0,     0,    76,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   109,   156,    79,    80,    81,    82,    83,   108,
      25,   109,   110,    79,    80,    81,    82,    83,     4,     0,
      98,    99,     0,     0,     0,   282,     0,   100,     5,     6,
       7,     8,     9,    10,   101,     0,     0,   102,    11,    12,
      13,    14,    15,    16,     0,     0,     0,     0,   103,    18,
      19,    20,    21,    22,   104,     0,    23,     0,   105,    24,
       0,     0,     0,     0,     0,   231,     0,     0,     0,   106,
     107,     0,     0,     0,    76,    77,     6,     7,     8,     9,
      10,     0,     0,     0,     0,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,   108,    25,   109,   110,    79,
      80,    81,    82,    83,     4,     0,    98,    99,     0,     0,
       0,     0,     0,   100,     5,     6,     7,     8,     9,    10,
     101,     0,     0,   102,    11,    12,    13,    14,    15,    16,
       0,   287,     0,     0,   103,    18,    19,    20,    21,    22,
     104,     0,    23,     0,   105,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   106,   107,     0,     0,     0,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   108,    25,   109,   110,    79,    80,    81,    82,    83,
       4,     0,    98,    99,     0,   289,     0,     0,     0,   100,
       5,     6,     7,     8,     9,    10,   101,     0,     0,   102,
      11,    12,    13,    14,    15,    16,     0,     0,     0,     0,
     103,    18,    19,    20,    21,    22,   104,     0,    23,     0,
     105,    24,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106,   107,     0,     0,     0,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   108,    25,   109,
     110,    79,    80,    81,    82,    83,     4,     0,    98,    99,
       0,     0,     0,     0,     0,   100,     5,     6,     7,     8,
       9,    10,   101,     0,     0,   102,    11,    12,    13,    14,
      15,    16,     0,   301,     0,     0,   103,    18,    19,    20,
      21,    22,   104,     0,    23,     0,   105,    24,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   107,     0,
       0,     0,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   108,    25,   109,   110,    79,    80,    81,
      82,    83,     4,     0,    98,    99,     0,     0,     0,     0,
       0,   100,     5,     6,     7,     8,     9,    10,   101,     0,
       0,   102,    11,    12,    13,    14,    15,    16,     0,   317,
       0,     0,   103,    18,    19,    20,    21,    22,   104,     0,
      23,     0,   105,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   106,   107,     0,     0,     0,    76,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
      25,   109,   110,    79,    80,    81,    82,    83,     4,     0,
      98,    99,     0,     0,     0,     0,     0,   100,     5,     6,
       7,     8,     9,    10,   101,     0,     0,   102,    11,    12,
      13,    14,    15,    16,     0,     0,     0,     0,   103,    18,
      19,    20,    21,    22,   104,     0,    23,     0,   105,    24,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
     107,     0,     0,     0,    76,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     0,   108,    25,   109,   110,    79,
      80,    81,    82,    83,     6,     7,     8,     9,    10,     0,
       0,     0,     0,    11,    12,    13,    14,    15,    59,     0,
       0,     0,   148,     0,     0,    19,    20,    21,    22,     6,
       7,     8,     9,    10,     4,     0,     0,     0,    11,    12,
      13,    14,    15,     0,     0,     6,     7,     8,     9,    10,
      19,    20,    21,    22,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,     0,     0,    19,    20,    21,    22,
       0,    25,     0,     0,     0,     0,     6,     7,     8,     9,
      10,     0,     0,     0,     0,    11,    12,    13,    14,    15,
       0,     0,     0,     0,     0,     0,    60,    19,    20,    21,
      22,     0,     0,     0,     0,     0,     0,     0,   184,   185,
     186,   187,    25,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-226)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      58,    52,    67,   118,    69,   105,    73,    51,   106,     3,
      68,   176,   151,    69,   100,   101,   241,     4,   104,   105,
      31,   107,    56,    40,    46,    31,    54,     0,    93,    57,
      20,    62,    55,    55,    52,    52,    31,    52,    56,    82,
      83,    56,    53,    54,   183,    32,    57,    98,    54,    83,
      94,    57,    83,    48,    83,   155,    46,    83,   283,    54,
      55,    35,    57,    57,    21,    22,    57,    52,   119,   155,
      44,    56,    46,    52,   125,   240,   215,    56,    55,    45,
      57,   246,    83,   148,    41,    42,   225,    83,    82,    45,
      83,   177,   148,    59,    60,    83,   182,   212,    20,    52,
     239,    59,    60,    61,    62,   149,    64,    58,   206,    46,
      47,    48,    49,    50,    51,    58,    58,    83,    84,    85,
      86,    87,    88,    52,    57,    52,    87,    56,   214,   180,
     230,    83,    87,    83,    55,   250,    83,    83,   224,    58,
     207,     3,    58,   241,   230,   260,   213,   286,   263,    83,
     289,    13,    14,    15,    16,    17,    18,   243,    55,    31,
     275,    23,    24,    25,    26,    27,    28,    29,    55,    87,
       7,    46,    34,    35,    36,    37,    38,   235,    52,    41,
      59,    60,    44,    63,    55,   283,     7,    31,   255,    56,
      54,   306,   307,   237,   280,    56,    62,    54,    55,    58,
      57,   266,    59,    60,    83,    84,    85,    86,    87,    88,
      80,    57,    57,    31,    83,    83,    58,    56,     7,    81,
      52,    11,    58,    83,    57,    82,    83,    84,    85,    86,
      87,    88,    83,    46,   285,    10,    58,     2,   236,   298,
     298,   312,   322,   232,   316,     2,   161,   305,     2,     2,
      91,   161,   262,   103,   312,   226,     3,   205,     5,     6,
     243,   312,     9,   321,   322,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    -1,    43,    44,    54,    55,
      -1,    -1,    -1,    59,    60,    -1,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    85,
      86,    87,    88,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     3,    -1,     5,     6,    -1,    -1,    -1,    10,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    -1,    43,    44,    54,    55,    -1,    -1,    -1,    59,
      60,    -1,    -1,    54,    55,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    87,    88,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     3,    -1,
       5,     6,    -1,    -1,    -1,    10,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    -1,    43,    44,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    54,
      55,    -1,    -1,    -1,    59,    60,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     3,    -1,     5,     6,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    30,    -1,    -1,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    -1,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       3,    -1,     5,     6,    -1,     8,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    55,    -1,    -1,    -1,    59,    60,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      83,    84,    85,    86,    87,    88,     3,    -1,     5,     6,
      -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28,    -1,    30,    -1,    -1,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    -1,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      -1,    -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     3,    -1,     5,     6,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    30,
      -1,    -1,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    59,    60,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    80,
      81,    82,    83,    84,    85,    86,    87,    88,     3,    -1,
       5,     6,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    -1,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    -1,    -1,    -1,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,    -1,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    23,    24,    25,    26,    27,     3,    -1,
      -1,    -1,    32,    -1,    -1,    35,    36,    37,    38,    14,
      15,    16,    17,    18,     3,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    -1,    -1,    14,    15,    16,    17,    18,
      35,    36,    37,    38,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      -1,    81,    -1,    -1,    -1,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    81,    35,    36,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    81,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    90,    93,     0,     3,    13,    14,    15,    16,    17,
      18,    23,    24,    25,    26,    27,    28,    29,    34,    35,
      36,    37,    38,    41,    44,    81,    91,    94,    96,    97,
     114,   115,   116,   122,   124,   125,   129,   130,   131,   132,
       3,    57,    82,    21,    22,    41,    42,   117,    83,    83,
      83,    55,    95,    45,    92,    83,    83,   123,    57,     3,
      81,   132,   132,   132,    83,   118,   119,    20,    46,    20,
     123,    92,    46,    55,    98,    52,    59,    60,    83,    84,
      85,    86,    87,    88,   126,   127,   128,    58,    58,    58,
      57,    52,   120,   121,   122,   126,   120,    56,     5,     6,
      12,    19,    22,    33,    39,    43,    54,    55,    80,    82,
      83,    96,   100,   108,   114,   115,   116,   126,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   147,   156,   158,   159,   160,   161,   162,    83,    99,
     124,    83,    87,    87,    55,    58,    58,   119,    32,   122,
     123,    92,    83,    83,   144,    57,    83,   144,   149,   150,
     152,    62,    83,   101,   103,   105,   106,    83,   138,   144,
     149,    83,   156,   144,    83,    53,    54,    57,   157,     9,
     134,    92,    55,    92,    59,    60,    61,    62,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,   146,    31,    52,    56,    87,
     120,   123,   133,    55,    48,     7,   149,    46,    47,    48,
      49,    50,    51,   153,   154,    40,    52,   164,     4,    32,
     151,     3,   104,   129,   130,    46,    52,    55,    63,     7,
      54,    31,    56,    55,   157,   144,    54,    92,   144,   155,
     133,   145,   148,   156,   124,    62,    56,    10,   124,   144,
     133,    58,   144,   133,   161,   149,    57,   105,   107,   126,
     106,    56,   123,    83,   163,   133,   148,   155,    58,   157,
      52,    56,    10,    31,   124,    56,     7,    30,   153,     8,
     165,   102,   122,    59,    60,    61,    62,    64,   113,    56,
      52,    30,    56,   144,   148,    92,   133,   133,    11,    58,
     107,    83,   109,   110,   111,   112,   126,    30,    83,    92,
     110,    57,   113,    46,    10,   126,   112,    58
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
#line 149 "musl.y"
    { new_pspec((yyvsp[(2) - (2)].nameval)); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 151 "musl.y"
    { new_pspec((yyvsp[(2) - (3)].nameval)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 191 "musl.y"
    { new_type((yyvsp[(2) - (2)].nameval)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 193 "musl.y"
    { new_type((yyvsp[(2) - (4)].nameval)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 195 "musl.y"
    { new_type((yyvsp[(2) - (4)].nameval)); }
    break;


/* Line 1792 of yacc.c  */
#line 1958 "musl.tab.cpp"
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
#line 328 "musl.y"


