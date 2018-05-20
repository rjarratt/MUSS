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
     T_SLASH = 303,
     T_AMPERSAND = 304,
     T_EXCLAMATION = 305,
     T_XOR = 306,
     T_RSUB = 307,
     T_RDIV = 308,
     T_ADDSTORE = 309,
     T_MULSTORE = 310,
     T_DIVSTORE = 311,
     T_ANDSTORE = 312,
     T_ORSTORE = 313,
     T_XORSTORE = 314,
     T_ASSIGN = 315,
     T_RSUBSTORE = 316,
     T_RDIVSTORE = 317,
     T_LLSHIFT = 318,
     T_RLSHIFT = 319,
     T_GOTO = 320,
     T_NAME = 321,
     T_CHAR_CONST = 322,
     T_MULTI_CHAR_CONST = 323,
     T_CH_STRING = 324,
     T_NUMBER = 325
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
#line 200 "musl.tab.cpp"
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
#line 228 "musl.tab.cpp"

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
#define YYLAST   606

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  172
/* YYNRULES -- Number of states.  */
#define YYNSTATES  273

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

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
      65,    66,    67,    68,    69,    70
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
     180,   185,   189,   191,   193,   195,   200,   205,   210,   212,
     214,   216,   218,   220,   222,   225,   228,   230,   233,   236,
     239,   241,   242,   245,   247,   249,   251,   253,   255,   257,
     259,   261,   263,   265,   267,   269,   271,   275,   278,   283,
     289,   292,   294,   296,   298,   300,   302,   304,   306,   310,
     312,   314,   316,   318,   320,   322,   324,   326,   328,   330,
     332,   334,   336,   338,   340,   342,   344,   346,   348,   350,
     352,   355,   359,   364,   366,   371,   377,   381,   383,   385,
     389,   391,   395,   399,   401,   403,   405,   408,   412,   415,
     417,   419,   421,   423,   425,   427,   431,   433,   434,   439,
     441,   444,   448,   453,   457,   461,   467,   473,   481,   484,
     487,   492,   495
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      72,     0,    -1,    74,    73,    76,   106,     8,    -1,    20,
      -1,    20,    66,    -1,    74,    75,    -1,    -1,    77,    -1,
      90,    -1,    91,    -1,    92,    -1,    41,    99,    42,    -1,
      -1,    78,    66,    -1,    78,    66,    79,    -1,    78,    66,
      32,    66,    -1,    19,    -1,    25,    -1,    41,    80,    42,
      -1,    41,    80,    42,    48,   100,    -1,    80,    38,   100,
      -1,   100,    -1,    -1,    17,    82,    -1,    48,     3,    43,
      83,    44,    66,    32,    -1,    98,    -1,     5,    66,    41,
     100,    42,    85,     9,    -1,    85,    86,    -1,    86,    -1,
      87,    -1,    87,    43,   101,    44,    -1,    88,    -1,   101,
      -1,   101,    89,    88,    -1,    45,    -1,    46,    -1,    49,
      -1,    47,    -1,    48,    -1,    28,    66,    -1,    28,    66,
      15,    96,    -1,    28,    66,   101,    -1,    31,    66,    15,
      96,    -1,    98,    99,    -1,    12,    93,    94,    -1,    17,
      -1,    17,   104,    -1,    29,    -1,    29,   104,    -1,    28,
      -1,    16,    -1,    94,    38,    95,    -1,    95,    -1,    66,
      -1,    66,    43,    44,    -1,    97,    -1,    97,    23,    96,
      -1,    97,    98,    99,    -1,    98,    99,    -1,   100,    -1,
     100,    43,   101,    44,    -1,    99,    38,    66,    -1,    66,
      -1,   104,    -1,    66,    -1,     3,    43,   104,    44,    -1,
       3,    43,    66,    44,    -1,     3,    43,     3,    44,    -1,
       3,    -1,   102,    -1,   103,    -1,    68,    -1,    69,    -1,
      70,    -1,    45,    70,    -1,    46,    70,    -1,    67,    -1,
      13,   105,    -1,    26,   105,    -1,    18,   105,    -1,    70,
      -1,    -1,   106,   107,    -1,   107,    -1,   108,    -1,   109,
      -1,   110,    -1,   112,    -1,    91,    -1,    77,    -1,    81,
      -1,    84,    -1,    90,    -1,    92,    -1,   113,    -1,   114,
      -1,   111,   106,     9,    -1,    24,    66,    -1,    24,    66,
      41,    42,    -1,    24,    66,    41,    99,    42,    -1,    66,
      39,    -1,   115,    -1,   130,    -1,   131,    -1,   132,    -1,
     133,    -1,   116,    -1,   118,    -1,   118,   117,   116,    -1,
      45,    -1,    46,    -1,    47,    -1,    48,    -1,    49,    -1,
      50,    -1,    51,    -1,    52,    -1,    53,    -1,    54,    -1,
      55,    -1,    56,    -1,    57,    -1,    58,    -1,    59,    -1,
      60,    -1,    61,    -1,    62,    -1,    63,    -1,    64,    -1,
     128,    -1,    40,   128,    -1,   128,    22,   119,    -1,    40,
     128,    22,   119,    -1,   101,    -1,    66,    41,   126,    42,
      -1,    66,    40,    41,   126,    42,    -1,    41,   115,    42,
      -1,   127,    -1,   128,    -1,   128,    22,   119,    -1,   121,
      -1,   121,   122,   120,    -1,    43,   120,    44,    -1,   123,
      -1,    23,    -1,     4,    -1,   115,   124,    -1,   125,   115,
     124,    -1,   125,   115,    -1,    32,    -1,    33,    -1,    34,
      -1,    35,    -1,    36,    -1,    37,    -1,   126,    38,   115,
      -1,   115,    -1,    -1,    66,    41,    99,    42,    -1,    66,
      -1,    66,   129,    -1,    66,    40,   129,    -1,    66,   129,
      40,   129,    -1,    43,   115,    44,    -1,    14,   120,   134,
      -1,    30,   120,     6,   106,    21,    -1,    11,   115,     6,
     106,    21,    -1,    11,    66,    34,   115,     6,   106,    21,
      -1,    65,    66,    -1,    38,   133,    -1,    27,   106,   135,
      10,    -1,     7,   106,    -1,    -1
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
     197,   199,   199,   203,   205,   211,   213,   215,   217,   221,
     221,   221,   221,   222,   222,   222,   223,   226,   228,   230,
     232,   232,   234,   234,   236,   236,   236,   238,   238,   238,
     238,   238,   238,   238,   240,   240,   242,   243,   243,   243,
     245,   247,   247,   247,   247,   249,   251,   252,   252,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   256,
     258,   260,   262,   264,   266,   268,   270,   272,   273,   273,
     275,   275,   276,   276,   277,   277,   279,   280,   280,   281,
     281,   281,   281,   281,   281,   283,   283,   283,   284,   287,
     287,   287,   287,   288,   290,   291,   292,   292,   293,   295,
     295,   296,   296
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
  "T_R_PAREN", "T_PLUS", "T_MINUS", "T_STAR", "T_SLASH", "T_AMPERSAND",
  "T_EXCLAMATION", "T_XOR", "T_RSUB", "T_RDIV", "T_ADDSTORE", "T_MULSTORE",
  "T_DIVSTORE", "T_ANDSTORE", "T_ORSTORE", "T_XORSTORE", "T_ASSIGN",
  "T_RSUBSTORE", "T_RDIVSTORE", "T_LLSHIFT", "T_RLSHIFT", "T_GOTO",
  "T_NAME", "T_CHAR_CONST", "T_MULTI_CHAR_CONST", "T_CH_STRING",
  "T_NUMBER", "$accept", "module", "start_module", "imports", "import",
  "exports", "proc_dec", "proc_dec_spec", "pspec", "t_list", "lit_dec",
  "pointer_lit", "any_type", "data_vec", "literals", "literal_item",
  "literal", "const_expr", "const_op", "type_dec", "var_dec", "import_dec",
  "kind", "imp_list", "imp_list_item", "structure", "fields", "type",
  "name_list", "scalar_type", "const", "dec_integer", "char_const",
  "numeric_type", "size", "statements", "statement",
  "declarative_statement", "imperative_statement", "proc_defn",
  "proc_heading", "label_dec", "comp_st", "control_st", "computation",
  "opr_opd_seq", "operator", "operand", "context", "condition", "test",
  "logop", "comparison", "compare_list", "comparator", "p_list",
  "built_in_function", "variable", "subscript", "if_st", "while_st",
  "for_st", "go_st", "action", "else_cl", YY_NULL
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
     325
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    75,    75,    75,
      75,    76,    76,    77,    77,    77,    78,    78,    79,    79,
      80,    80,    80,    81,    82,    83,    84,    85,    85,    86,
      86,    87,    88,    88,    89,    89,    89,    89,    89,    90,
      90,    90,    90,    91,    92,    93,    93,    93,    93,    93,
      93,    94,    94,    95,    95,    96,    96,    97,    97,    98,
      98,    99,    99,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   102,   102,   102,   103,   104,   104,   104,
     105,   105,   106,   106,   107,   107,   107,   108,   108,   108,
     108,   108,   108,   108,   109,   109,   110,   111,   111,   111,
     112,   113,   113,   113,   113,   114,   115,   116,   116,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   118,
     118,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     120,   120,   121,   121,   122,   122,   123,   124,   124,   125,
     125,   125,   125,   125,   125,   126,   126,   126,   127,   128,
     128,   128,   128,   129,   130,   131,   132,   132,   133,   134,
     134,   135,   135
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
       4,     3,     1,     1,     1,     4,     4,     4,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     2,     2,     2,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     4,     1,     4,     5,     3,     1,     1,     3,
       1,     3,     3,     1,     1,     1,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     4,     1,
       2,     3,     4,     3,     3,     5,     5,     7,     2,     2,
       4,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     1,    68,     0,    81,    81,    16,     3,
      17,    81,     0,     0,    64,    12,     5,     7,     0,     8,
       9,    10,     0,    59,    63,     0,    50,    45,    49,    47,
       0,    80,    77,    79,     4,    78,    39,     0,     0,     0,
      13,    62,    43,     0,     0,     0,     0,    46,    48,    53,
      44,    52,     0,     0,     0,    76,    71,    72,    73,    41,
      69,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   159,    89,    90,    91,    92,    88,    93,
     133,     0,    83,    84,    85,    86,     0,    87,    94,    95,
     101,   106,   107,   137,   129,   102,   103,   104,   105,     0,
      22,    14,     0,     0,    67,    66,    65,     0,     0,    40,
      55,     0,    74,    75,    42,    11,     0,   159,     0,     0,
     159,     0,     0,   140,   143,     0,    23,    97,     0,   159,
     130,     0,   168,   100,     0,   157,     0,   160,     2,    82,
       0,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,     0,     0,    15,     0,    21,    61,    60,    54,    51,
       0,     0,    58,     0,     0,     0,     0,   149,   150,   151,
     152,   153,   154,   146,     0,     0,     0,   164,   145,   144,
       0,     0,     0,     0,     0,     0,   136,   157,   161,   159,
       0,   156,     0,     0,     0,    96,   108,   131,   138,     0,
      18,    56,    57,     0,     0,     0,   142,   148,   172,   169,
     141,     0,    98,     0,     0,   132,     0,   158,     0,   134,
     163,   162,     0,    20,     0,     0,     0,   166,   147,     0,
       0,     0,    25,    99,   165,   135,   155,   139,    19,     0,
      28,    29,    31,    32,     0,   171,   170,     0,    26,    27,
       0,    34,    35,    37,    38,    36,     0,   167,     0,     0,
      33,    24,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    15,     2,    16,    39,    74,    18,   101,   164,
      75,   126,   241,    76,   249,   250,   251,   252,   266,    77,
      78,    79,    30,    50,    51,   109,   110,    22,    42,    23,
      80,    60,    61,    24,    32,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,   161,    92,   207,   122,
     123,   190,   124,   183,   184,   202,    93,    94,   137,    95,
      96,    97,    98,   187,   240
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -178
static const yytype_int16 yypact[] =
{
    -178,    17,   207,  -178,     2,    54,   -13,   -13,  -178,    -1,
    -178,   -13,     0,     1,  -178,    31,  -178,  -178,    14,  -178,
    -178,  -178,    33,    63,  -178,    12,  -178,    26,  -178,    26,
      52,  -178,  -178,  -178,  -178,  -178,   183,    94,    33,   516,
      18,  -178,    96,    79,   107,   114,   117,  -178,  -178,    85,
     102,  -178,   139,    73,    93,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,   139,    35,   112,   304,   236,   134,   125,   236,
     126,   320,   130,   -20,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,    23,  -178,  -178,  -178,  -178,   516,  -178,  -178,  -178,
    -178,  -178,   542,  -178,   175,  -178,  -178,  -178,  -178,   137,
     139,  -178,   142,   165,  -178,  -178,  -178,   167,    52,  -178,
      84,    33,  -178,  -178,  -178,  -178,   171,    71,   208,   236,
     143,   259,    -5,    20,  -178,   212,  -178,   177,   217,    61,
     209,   192,  -178,  -178,   -14,   372,   320,   196,  -178,  -178,
     176,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,
    -178,   320,   126,  -178,    43,  -178,  -178,  -178,  -178,  -178,
     139,    33,    96,   139,   320,   516,   193,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,   320,   516,   174,  -178,  -178,  -178,
     236,   197,   -10,   516,   205,   126,  -178,   320,  -178,   128,
      58,  -178,    88,   210,   205,  -178,  -178,  -178,   237,   139,
     216,  -178,    96,   218,   260,   244,  -178,   259,   312,  -178,
    -178,   139,  -178,    99,   380,  -178,   135,  -178,   320,  -178,
    -178,  -178,   126,  -178,   139,    79,   516,  -178,  -178,   516,
     257,   227,  -178,  -178,  -178,  -178,  -178,  -178,  -178,    86,
    -178,   235,  -178,   252,   448,   516,  -178,   214,  -178,  -178,
      79,  -178,  -178,  -178,  -178,  -178,    79,  -178,   251,   242,
    -178,  -178,  -178
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,  -178,  -178,  -178,  -178,   285,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,  -178,    39,  -178,    41,  -178,   306,
     314,   316,  -178,  -178,   213,   -48,  -178,   -49,   -32,   -89,
     -36,  -178,  -178,    90,   169,   -77,   -80,  -178,  -178,  -178,
    -178,  -178,  -178,  -178,   -61,   159,  -178,  -178,  -177,   -57,
    -178,  -178,  -178,   105,  -178,   131,  -178,   -68,  -118,  -178,
    -178,  -178,   141,  -178,  -178
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -65
static const yytype_int16 yytable[] =
{
      59,   139,   130,   111,   118,   121,    63,   103,   121,   140,
     131,   165,   128,   111,   114,    44,   198,     3,   225,   133,
     134,   135,   185,   136,   188,     6,     4,   197,    64,   136,
       7,   138,   222,   186,    65,     5,     6,    66,    11,     6,
      67,     7,     8,   189,     7,    25,   -64,    68,    10,    11,
      99,    12,    11,    69,    13,   247,    41,    31,   121,   100,
     139,   171,   176,    70,    71,    34,    36,    37,    53,    54,
      26,    27,    38,   102,   201,   203,   198,   115,    45,   172,
      40,   209,    28,    29,   213,   210,   231,     4,    72,    73,
      55,    56,    57,    58,   208,   258,   102,     6,   215,    41,
     227,   194,     7,   200,   136,   174,    43,   170,   218,    62,
      11,   134,   135,   214,   136,    46,   224,    47,    49,    48,
     233,   111,   211,   217,    53,    54,   228,   208,   107,   121,
     229,    53,    54,   220,   102,   139,   201,   102,   139,   212,
     108,   243,     4,   112,   139,   248,    55,    56,    57,    58,
      14,   104,     6,    55,    56,    57,    58,     7,   105,   254,
     223,   106,   255,   113,   208,    11,   -62,   246,   134,   135,
     -62,   136,   242,   228,   139,   139,    33,   245,   116,     4,
      35,    64,   125,   134,   135,   205,   136,    65,     5,     6,
      66,   127,   129,    67,     7,     8,   132,   162,    52,   253,
      68,    10,    11,   163,    12,    14,    69,    13,   166,   167,
       4,   168,   173,   253,   175,   191,    70,    71,   192,     5,
       6,    53,    54,   193,   269,     7,     8,     9,    53,    54,
     253,   195,    10,    11,   196,    12,   204,   216,    13,    72,
     221,    72,    73,    55,    56,    57,    58,     4,   136,    64,
      55,    56,    57,    58,   230,    65,     5,     6,    66,   232,
     235,    67,     7,     8,   234,   237,   236,   256,    68,    10,
      11,   257,    12,    14,    69,    13,    70,    71,   260,   119,
     268,    53,    54,   271,    70,    71,   272,    17,   259,    53,
      54,   177,   178,   179,   180,   181,   182,   261,   262,   263,
     264,   265,   120,    55,    56,    57,    58,   270,    19,    72,
      73,    55,    56,    57,    58,     4,    20,    64,    21,   239,
     206,   169,   238,    65,     5,     6,    66,   219,   226,    67,
       7,     8,     0,     0,     0,     0,    68,    10,    11,     0,
      12,     0,    69,    13,    70,    71,     0,     0,     0,    53,
      54,     0,    70,    71,     0,     0,     0,    53,    54,     0,
      70,    71,     0,     0,     0,    53,    54,     0,     0,     0,
     117,    55,    56,    57,    58,     0,     0,    72,    73,    55,
      56,    57,    58,     4,     0,    64,   120,    55,    56,    57,
      58,    65,     5,     6,    66,     0,     0,    67,     7,     8,
       0,   244,     0,     0,    68,    10,    11,     0,    12,     0,
      69,    13,    70,    71,     0,     0,     0,    53,    54,     0,
      70,    71,     0,     0,     0,    53,    54,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,    55,
      56,    57,    58,     0,     0,    72,    73,    55,    56,    57,
      58,     4,     0,    64,     0,     0,     0,     0,     0,    65,
       5,     6,    66,     0,     0,    67,     7,     8,     0,   267,
       0,     0,    68,    10,    11,     0,    12,     0,    69,    13,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    71,
       0,     0,     0,    53,    54,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    73,    55,    56,    57,    58,     4,
       0,    64,     0,     0,     0,     0,     0,    65,     5,     6,
      66,     0,     0,    67,     7,     8,     0,     0,     0,     0,
      68,    10,    11,     0,    12,     0,    69,    13,     0,     0,
       0,     0,     0,     0,     0,     0,    70,    71,     0,     0,
       0,    53,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    73,    55,    56,    57,    58,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-178)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      36,    81,    70,    52,    65,    66,    38,    43,    69,    86,
      71,   100,    69,    62,    62,     3,   134,     0,   195,    39,
      40,    41,    27,    43,     4,    13,     3,    41,     5,    43,
      18,     8,    42,    38,    11,    12,    13,    14,    26,    13,
      17,    18,    19,    23,    18,    43,    66,    24,    25,    26,
      32,    28,    26,    30,    31,   232,    66,    70,   119,    41,
     140,   110,   119,    40,    41,    66,    66,    66,    45,    46,
      16,    17,    41,    38,   135,   136,   194,    42,    66,   111,
      66,    38,    28,    29,   173,    42,   204,     3,    65,    66,
      67,    68,    69,    70,   162,     9,    38,    13,   175,    66,
      42,    40,    18,   135,    43,    34,    43,    23,   185,    15,
      26,    40,    41,   174,    43,    25,   193,    27,    66,    29,
     209,   170,   170,   184,    45,    46,    38,   195,    43,   190,
      42,    45,    46,   190,    38,   215,   197,    38,   218,   171,
      38,    42,     3,    70,   224,   234,    67,    68,    69,    70,
      66,    44,    13,    67,    68,    69,    70,    18,    44,   236,
     192,    44,   239,    70,   232,    26,    38,   228,    40,    41,
      42,    43,   221,    38,   254,   255,     7,    42,    66,     3,
      11,     5,    48,    40,    41,     9,    43,    11,    12,    13,
      14,    66,    66,    17,    18,    19,    66,    22,    15,   235,
      24,    25,    26,    66,    28,    66,    30,    31,    66,    44,
       3,    44,    41,   249,     6,     3,    40,    41,    41,    12,
      13,    45,    46,     6,   260,    18,    19,    20,    45,    46,
     266,    22,    25,    26,    42,    28,    40,    44,    31,    65,
      43,    65,    66,    67,    68,    69,    70,     3,    43,     5,
      67,    68,    69,    70,    44,    11,    12,    13,    14,    22,
      42,    17,    18,    19,    48,    21,     6,    10,    24,    25,
      26,    44,    28,    66,    30,    31,    40,    41,    43,    43,
      66,    45,    46,    32,    40,    41,    44,     2,   249,    45,
      46,    32,    33,    34,    35,    36,    37,    45,    46,    47,
      48,    49,    66,    67,    68,    69,    70,   266,     2,    65,
      66,    67,    68,    69,    70,     3,     2,     5,     2,     7,
     161,   108,   217,    11,    12,    13,    14,   186,   197,    17,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,
      28,    -1,    30,    31,    40,    41,    -1,    -1,    -1,    45,
      46,    -1,    40,    41,    -1,    -1,    -1,    45,    46,    -1,
      40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    -1,    -1,    65,    66,    67,
      68,    69,    70,     3,    -1,     5,    66,    67,    68,    69,
      70,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
      -1,    21,    -1,    -1,    24,    25,    26,    -1,    28,    -1,
      30,    31,    40,    41,    -1,    -1,    -1,    45,    46,    -1,
      40,    41,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    70,    -1,    -1,    65,    66,    67,    68,    69,
      70,     3,    -1,     5,    -1,    -1,    -1,    -1,    -1,    11,
      12,    13,    14,    -1,    -1,    17,    18,    19,    -1,    21,
      -1,    -1,    24,    25,    26,    -1,    28,    -1,    30,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    67,    68,    69,    70,     3,
      -1,     5,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,
      14,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,    -1,
      24,    25,    26,    -1,    28,    -1,    30,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    72,    74,     0,     3,    12,    13,    18,    19,    20,
      25,    26,    28,    31,    66,    73,    75,    77,    78,    90,
      91,    92,    98,   100,   104,    43,    16,    17,    28,    29,
      93,    70,   105,   105,    66,   105,    66,    66,    41,    76,
      66,    66,    99,    43,     3,    66,   104,   104,   104,    66,
      94,    95,    15,    45,    46,    67,    68,    69,    70,   101,
     102,   103,    15,    99,     5,    11,    14,    17,    24,    30,
      40,    41,    65,    66,    77,    81,    84,    90,    91,    92,
     101,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   118,   127,   128,   130,   131,   132,   133,    32,
      41,    79,    38,   101,    44,    44,    44,    43,    38,    96,
      97,    98,    70,    70,    96,    42,    66,    66,   115,    43,
      66,   115,   120,   121,   123,    48,    82,    66,   120,    66,
     128,   115,    66,    39,    40,    41,    43,   129,     8,   107,
     106,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,   117,    22,    66,    80,   100,    66,    44,    44,    95,
      23,    98,    99,    41,    34,     6,   120,    32,    33,    34,
      35,    36,    37,   124,   125,    27,    38,   134,     4,    23,
     122,     3,    41,     6,    40,    22,    42,    41,   129,    66,
      99,   115,   126,   115,    40,     9,   116,   119,   128,    38,
      42,    96,    99,   100,   115,   106,    44,   115,   106,   133,
     120,    43,    42,    99,   106,   119,   126,    42,    38,    42,
      44,   129,    22,   100,    48,    42,     6,    21,   124,     7,
     135,    83,    98,    42,    21,    42,   115,   119,   100,    85,
      86,    87,    88,   101,   106,   106,    10,    44,     9,    86,
      43,    45,    46,    47,    48,    49,    89,    21,    66,   101,
      88,    32,    44
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
#line 1770 "musl.tab.cpp"
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
#line 297 "musl.y"


