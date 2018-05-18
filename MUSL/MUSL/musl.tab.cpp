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
#line 94 "musl.y"

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
     T_OR = 277,
     T_PROC = 278,
     T_PSPEC = 279,
     T_REAL = 280,
     T_THEN = 281,
     T_TYPE = 282,
     T_VSTORE = 283,
     T_WITHIN = 284,
     T_EQUALS = 285,
     T_NOT_EQUALS = 286,
     T_LT = 287,
     T_GT = 288,
     T_LE = 289,
     T_GE = 290,
     T_COMMA = 291,
     T_COLON = 292,
     T_CIRCUMFLEX = 293,
     T_L_BRACK = 294,
     T_R_BRACK = 295,
     T_L_PAREN = 296,
     T_R_PAREN = 297,
     T_PLUS = 298,
     T_MINUS = 299,
     T_STAR = 300,
     token = 301,
     T_SLASH = 302,
     T_AMPERSAND = 303,
     T_EXCLAMATION = 304,
     T_XOR = 305,
     T_RSUB = 306,
     T_RDIV = 307,
     T_ADDSTORE = 308,
     T_MULSTORE = 309,
     T_DIVSTORE = 310,
     T_ANDSTORE = 311,
     T_ORSTORE = 312,
     T_XORSTORE = 313,
     T_ASSIGN = 314,
     T_RSUBSTORE = 315,
     T_RDIVSTORE = 316,
     T_LLSHIFT = 317,
     T_RLSHIFT = 318,
     T_GOTO = 319,
     T_NAME = 320,
     T_CHAR_CONST = 321,
     T_NUMBER = 322
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 106 "musl.y"

    char charval;
    char *nameval;
    unsigned int unsignedval;


/* Line 387 of yacc.c  */
#line 196 "musl.tab.cpp"
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
#line 224 "musl.tab.cpp"

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
#define YYLAST   488

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  166
/* YYNRULES -- Number of states.  */
#define YYNSTATES  260

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   322

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
      65,    66,    67
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
     215,   218,   220,   222,   224,   227,   230,   232,   235,   238,
     241,   243,   244,   247,   249,   251,   253,   255,   257,   259,
     261,   263,   265,   267,   269,   271,   273,   277,   280,   285,
     291,   294,   296,   298,   300,   302,   304,   306,   310,   312,
     314,   316,   318,   320,   322,   324,   326,   328,   330,   332,
     334,   336,   338,   340,   342,   344,   346,   348,   350,   352,
     355,   357,   362,   368,   372,   374,   376,   380,   384,   386,
     388,   390,   393,   397,   400,   402,   404,   406,   408,   410,
     412,   416,   418,   419,   424,   426,   429,   433,   438,   442,
     446,   452,   460,   463,   466,   471,   474
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      69,     0,    -1,    71,    70,    73,   103,     8,    -1,    20,
      -1,    20,    65,    -1,    71,    72,    -1,    -1,    74,    -1,
      87,    -1,    88,    -1,    89,    -1,    39,    96,    40,    -1,
      -1,    75,    65,    -1,    75,    65,    76,    -1,    75,    65,
      30,    65,    -1,    19,    -1,    24,    -1,    39,    77,    40,
      -1,    39,    77,    40,    47,    97,    -1,    77,    36,    97,
      -1,    97,    -1,    -1,    17,    79,    -1,    47,     3,    41,
      80,    42,    65,    30,    -1,    95,    -1,     5,    65,    39,
      97,    40,    82,     9,    -1,    82,    83,    -1,    83,    -1,
      84,    -1,    84,    41,    98,    42,    -1,    85,    -1,    98,
      -1,    98,    86,    85,    -1,    43,    -1,    44,    -1,    48,
      -1,    45,    -1,    47,    -1,    27,    65,    -1,    27,    65,
      15,    93,    -1,    27,    65,    98,    -1,    29,    65,    15,
      93,    -1,    95,    96,    -1,    12,    90,    91,    -1,    17,
      -1,    17,   101,    -1,    28,    -1,    28,   101,    -1,    27,
      -1,    16,    -1,    91,    36,    92,    -1,    92,    -1,    65,
      -1,    65,    41,    42,    -1,    94,    -1,    94,    22,    93,
      -1,    94,    95,    96,    -1,    95,    96,    -1,    97,    -1,
      97,    41,    98,    42,    -1,    96,    36,    65,    -1,    65,
      -1,   101,    -1,    65,    -1,     3,   101,    -1,     3,    41,
     101,    42,    -1,     3,    41,    65,    42,    -1,     3,    41,
       3,    42,    -1,     3,    -1,     3,     3,    -1,    99,    -1,
     100,    -1,    67,    -1,    43,    67,    -1,    44,    67,    -1,
      66,    -1,    13,   102,    -1,    25,   102,    -1,    18,   102,
      -1,    67,    -1,    -1,   103,   104,    -1,   104,    -1,   105,
      -1,   106,    -1,   107,    -1,   109,    -1,    88,    -1,    74,
      -1,    78,    -1,    81,    -1,    87,    -1,    89,    -1,   110,
      -1,   111,    -1,   108,   103,     9,    -1,    23,    65,    -1,
      23,    65,    39,    40,    -1,    23,    65,    39,    96,    40,
      -1,    65,    37,    -1,   112,    -1,   126,    -1,   127,    -1,
     128,    -1,   113,    -1,   115,    -1,   115,   114,   113,    -1,
      43,    -1,    44,    -1,    45,    -1,    47,    -1,    48,    -1,
      49,    -1,    50,    -1,    51,    -1,    52,    -1,    53,    -1,
      54,    -1,    55,    -1,    56,    -1,    57,    -1,    58,    -1,
      59,    -1,    60,    -1,    61,    -1,    62,    -1,    63,    -1,
     124,    -1,    38,   124,    -1,    98,    -1,    65,    39,   122,
      40,    -1,    65,    38,    39,   122,    40,    -1,    39,   112,
      40,    -1,   123,    -1,   117,    -1,   117,   118,   116,    -1,
      41,   116,    42,    -1,   119,    -1,    22,    -1,     4,    -1,
     112,   120,    -1,   121,   112,   120,    -1,   121,   112,    -1,
      30,    -1,    31,    -1,    32,    -1,    33,    -1,    34,    -1,
      35,    -1,   122,    36,   112,    -1,   112,    -1,    -1,    65,
      39,    96,    40,    -1,    65,    -1,    65,   125,    -1,    65,
      38,   125,    -1,    65,   125,    38,   125,    -1,    41,   112,
      42,    -1,    14,   116,   129,    -1,    11,   112,     6,   103,
      21,    -1,    11,    65,    32,   112,     6,   103,    21,    -1,
      64,    65,    -1,    36,   128,    -1,    26,   103,   130,    10,
      -1,     7,   103,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   115,   115,   117,   117,   118,   118,   118,
     118,   120,   120,   123,   125,   127,   129,   131,   133,   135,
     137,   137,   137,   146,   148,   149,   151,   152,   152,   153,
     153,   154,   155,   155,   156,   156,   156,   156,   156,   159,
     161,   163,   165,   167,   169,   171,   173,   175,   177,   179,
     181,   183,   183,   185,   187,   189,   189,   190,   190,   192,
     192,   194,   194,   197,   199,   201,   205,   207,   209,   211,
     213,   215,   215,   216,   216,   216,   217,   220,   222,   224,
     226,   226,   228,   228,   230,   230,   230,   232,   232,   232,
     232,   232,   232,   232,   234,   234,   236,   237,   237,   237,
     239,   241,   241,   241,   243,   245,   246,   246,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   250,   252,
     254,   256,   258,   260,   262,   264,   264,   265,   265,   266,
     266,   268,   269,   269,   270,   270,   270,   270,   270,   270,
     272,   272,   272,   273,   276,   276,   276,   276,   277,   279,
     280,   280,   281,   283,   283,   284,   284
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
  "T_LSPEC", "T_MODULE", "T_OD", "T_OR", "T_PROC", "T_PSPEC", "T_REAL",
  "T_THEN", "T_TYPE", "T_VSTORE", "T_WITHIN", "T_EQUALS", "T_NOT_EQUALS",
  "T_LT", "T_GT", "T_LE", "T_GE", "T_COMMA", "T_COLON", "T_CIRCUMFLEX",
  "T_L_BRACK", "T_R_BRACK", "T_L_PAREN", "T_R_PAREN", "T_PLUS", "T_MINUS",
  "T_STAR", "token", "T_SLASH", "T_AMPERSAND", "T_EXCLAMATION", "T_XOR",
  "T_RSUB", "T_RDIV", "T_ADDSTORE", "T_MULSTORE", "T_DIVSTORE",
  "T_ANDSTORE", "T_ORSTORE", "T_XORSTORE", "T_ASSIGN", "T_RSUBSTORE",
  "T_RDIVSTORE", "T_LLSHIFT", "T_RLSHIFT", "T_GOTO", "T_NAME",
  "T_CHAR_CONST", "T_NUMBER", "$accept", "module", "start_module",
  "imports", "import", "exports", "proc_dec", "proc_dec_spec", "pspec",
  "t_list", "lit_dec", "pointer_lit", "any_type", "data_vec", "literals",
  "literal_item", "literal", "const_expr", "const_op", "type_dec",
  "var_dec", "import_dec", "kind", "imp_list", "imp_list_item",
  "structure", "fields", "type", "name_list", "scalar_type", "const",
  "dec_integer", "char_const", "numeric_type", "size", "statements",
  "statement", "declarative_statement", "imperative_statement",
  "proc_defn", "proc_heading", "label_dec", "comp_st", "control_st",
  "computation", "opr_opd_seq", "operator", "operand", "condition", "test",
  "logop", "comparison", "compare_list", "comparator", "p_list",
  "built_in_function", "variable", "subscript", "if_st", "for_st", "go_st",
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
     315,   316,   317,   318,   319,   320,   321,   322
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    68,    69,    70,    70,    71,    71,    72,    72,    72,
      72,    73,    73,    74,    74,    74,    75,    75,    76,    76,
      77,    77,    77,    78,    79,    80,    81,    82,    82,    83,
      83,    84,    85,    85,    86,    86,    86,    86,    86,    87,
      87,    87,    87,    88,    89,    90,    90,    90,    90,    90,
      90,    91,    91,    92,    92,    93,    93,    94,    94,    95,
      95,    96,    96,    97,    97,    97,    97,    97,    97,    97,
      97,    98,    98,    99,    99,    99,   100,   101,   101,   101,
     102,   102,   103,   103,   104,   104,   104,   105,   105,   105,
     105,   105,   105,   105,   106,   106,   107,   108,   108,   108,
     109,   110,   110,   110,   111,   112,   113,   113,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   115,   115,
     115,   115,   115,   115,   115,   116,   116,   117,   117,   118,
     118,   119,   120,   120,   121,   121,   121,   121,   121,   121,
     122,   122,   122,   123,   124,   124,   124,   124,   125,   126,
     127,   127,   128,   129,   129,   130,   130
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
       2,     1,     1,     1,     2,     2,     1,     2,     2,     2,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     4,     5,     3,     1,     1,     3,     3,     1,     1,
       1,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     1,     0,     4,     1,     2,     3,     4,     3,     3,
       5,     7,     2,     2,     4,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     1,    69,     0,    81,    81,    16,     3,
      17,    81,     0,     0,    64,    12,     5,     7,     0,     8,
       9,    10,     0,    59,    63,    70,     0,    65,    50,    45,
      49,    47,     0,    80,    77,    79,     4,    78,    39,     0,
       0,     0,    13,    62,    43,     0,     0,     0,     0,    46,
      48,    53,    44,    52,     0,     0,     0,    76,    73,    41,
      71,    72,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   154,    89,    90,    91,    92,    88,    93,   130,
       0,    83,    84,    85,    86,     0,    87,    94,    95,   101,
     105,   106,   134,   128,   102,   103,   104,     0,    22,    14,
       0,     0,    68,    67,    66,     0,     0,    40,    55,     0,
      74,    75,    42,    11,     0,   154,     0,     0,   154,     0,
       0,   135,   138,     0,    23,    97,   154,   129,     0,   162,
     100,     0,   152,     0,   155,     2,    82,     0,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     0,    15,
       0,    21,    61,    60,    54,    51,     0,     0,    58,     0,
       0,     0,     0,   144,   145,   146,   147,   148,   149,   141,
       0,     0,     0,   159,   140,   139,     0,     0,     0,     0,
     133,   152,   156,   154,     0,   151,     0,     0,     0,    96,
     107,     0,    18,    56,    57,     0,     0,     0,   137,   143,
     166,   163,   136,     0,    98,     0,     0,   153,     0,   131,
     158,   157,    20,     0,     0,     0,   160,   142,     0,     0,
       0,    25,    99,   132,   150,    19,     0,    28,    29,    31,
      32,     0,   165,   164,     0,    26,    27,     0,    34,    35,
      37,    38,    36,     0,   161,     0,     0,    33,    24,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    15,     2,    16,    41,    73,    18,    99,   160,
      74,   124,   230,    75,   236,   237,   238,   239,   253,    76,
      77,    78,    32,    52,    53,   107,   108,    22,    44,    23,
      79,    60,    61,    24,    34,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   158,    91,   120,   121,
     186,   122,   179,   180,   196,    92,    93,   134,    94,    95,
      96,   183,   229
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -118
static const yytype_int16 yypact[] =
{
    -118,    20,   192,  -118,   130,   235,   -45,   -45,  -118,   -29,
    -118,   -45,   -23,   -22,  -118,   -12,  -118,  -118,     8,  -118,
    -118,  -118,    28,    59,  -118,  -118,    12,  -118,  -118,   132,
    -118,   132,    51,  -118,  -118,  -118,  -118,  -118,    69,   107,
      28,   400,   -11,  -118,   102,    24,    98,   104,   109,  -118,
    -118,   119,   128,  -118,    76,   103,   105,  -118,  -118,  -118,
    -118,  -118,    76,   -19,   114,    60,   229,   133,   120,   125,
     278,   129,    82,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
      21,  -118,  -118,  -118,  -118,   400,  -118,  -118,  -118,  -118,
    -118,   425,  -118,  -118,  -118,  -118,  -118,   135,    76,  -118,
     136,   142,  -118,  -118,  -118,   150,    51,  -118,    44,    28,
    -118,  -118,  -118,  -118,   167,   127,   168,   229,   158,   244,
     -13,    27,  -118,   210,  -118,   175,    13,  -118,   178,  -118,
    -118,    22,   335,   278,   182,  -118,  -118,   164,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,  -118,   278,  -118,
      42,  -118,  -118,  -118,  -118,  -118,    76,    28,   102,    76,
     278,   400,   180,  -118,  -118,  -118,  -118,  -118,  -118,  -118,
     278,   400,   159,  -118,  -118,  -118,   229,   184,   -24,   186,
    -118,   278,  -118,   295,    56,  -118,    66,   194,   186,  -118,
    -118,    76,   190,  -118,   102,   201,   237,   221,  -118,   244,
     286,  -118,  -118,    76,  -118,    71,    94,  -118,   278,  -118,
    -118,  -118,  -118,    76,    24,   400,  -118,  -118,   400,   239,
     205,  -118,  -118,  -118,  -118,  -118,     9,  -118,   212,  -118,
     294,   343,   400,  -118,   189,  -118,  -118,    24,  -118,  -118,
    -118,  -118,  -118,    24,  -118,   225,   214,  -118,  -118,  -118
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,  -118,  -118,  -118,  -118,   256,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,    25,  -118,    16,  -118,   264,
     269,   279,  -118,  -118,   174,   -56,  -118,   -52,   -35,   -86,
     -38,  -118,  -118,   113,   147,   -76,   -79,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,   -62,   124,  -118,  -118,  -106,  -118,
    -118,  -118,    74,  -118,    93,  -118,   223,  -117,  -118,  -118,
     108,  -118,  -118
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -65
static const yytype_int16 yytable[] =
{
      59,   136,   109,   116,   119,    63,   112,   101,   128,   137,
     109,   172,   161,   181,   192,    46,   214,   100,   245,    97,
       3,   113,    33,   182,     4,     6,    64,    40,    98,   135,
       7,   184,    65,     5,     6,    66,    36,    11,    67,     7,
       8,    43,    38,    39,    68,    10,    11,     4,    12,   185,
      13,   189,    55,    56,   133,   119,   167,     6,   136,    69,
      70,   191,     7,   133,    55,    56,   166,    55,    56,    11,
     195,   197,   192,    42,   168,    57,    58,    47,   201,     4,
     212,   221,   202,   205,    54,    71,    72,    57,    58,     6,
      57,    58,   100,    43,     7,   207,   217,   194,    69,    70,
      45,    11,   218,    55,    56,   210,   219,   100,   206,    14,
     203,   232,    55,    56,   109,   222,    51,    27,   209,   130,
     131,   132,    62,   133,   119,   115,    57,    58,   136,   195,
     218,   136,   204,    25,   233,    57,    58,   235,   100,    48,
     102,    14,    49,     6,    50,     6,   103,   -64,     7,   241,
       7,   104,   242,   215,    35,    11,   234,    11,    37,   170,
     105,   231,   136,   136,   106,   131,   132,     4,   133,    64,
     110,    26,   111,   199,   171,    65,     5,     6,    66,   114,
     123,    67,     7,     8,   163,   125,   240,    68,    10,    11,
     126,    12,   164,    13,   129,     4,   131,   132,   240,   133,
     159,   162,    69,    70,     5,     6,   169,    55,    56,   256,
       7,     8,     9,   187,   188,   240,    10,    11,   190,    12,
     198,    13,   208,    71,     4,   213,    64,   133,    71,    72,
      57,    58,    65,     5,     6,    66,   220,   223,    67,     7,
       8,   224,   226,   225,    68,    10,    11,   244,    12,   243,
      13,    28,    29,   247,   255,   258,   259,    14,    17,    69,
      70,   246,    30,    31,    55,    56,    19,    69,    70,   257,
     117,    20,    55,    56,   173,   174,   175,   176,   177,   178,
     165,    21,   200,   227,   216,    71,    72,    57,    58,     4,
     211,    64,   127,   228,   118,    57,    58,    65,     5,     6,
      66,     0,     0,    67,     7,     8,     0,     0,     0,    68,
      10,    11,     0,    12,     0,    13,    69,    70,     0,     0,
       0,    55,    56,     0,    69,    70,     0,     0,     0,    55,
      56,   -62,     0,   131,   132,   -62,   133,   248,   249,   250,
       0,   251,   252,   118,    57,    58,     4,     0,    64,     0,
      71,    72,    57,    58,    65,     5,     6,    66,     0,     0,
      67,     7,     8,     0,   254,     0,    68,    10,    11,     0,
      12,     0,    13,    69,    70,     0,     0,     0,    55,    56,
       0,    69,    70,     0,     0,     0,    55,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     193,    57,    58,     4,     0,    64,     0,    71,    72,    57,
      58,    65,     5,     6,    66,     0,     0,    67,     7,     8,
       0,     0,     0,    68,    10,    11,     0,    12,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,    69,    70,
       0,     0,     0,    55,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    71,    72,    57,    58,   138,   139,
     140,     0,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-118)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      38,    80,    54,    65,    66,    40,    62,    45,    70,    85,
      62,   117,    98,    26,   131,     3,    40,    36,     9,    30,
       0,    40,    67,    36,     3,    13,     5,    39,    39,     8,
      18,     4,    11,    12,    13,    14,    65,    25,    17,    18,
      19,    65,    65,    65,    23,    24,    25,     3,    27,    22,
      29,    38,    43,    44,    41,   117,   108,    13,   137,    38,
      39,    39,    18,    41,    43,    44,    22,    43,    44,    25,
     132,   133,   189,    65,   109,    66,    67,    65,    36,     3,
     186,   198,    40,   169,    15,    64,    65,    66,    67,    13,
      66,    67,    36,    65,    18,   171,    40,   132,    38,    39,
      41,    25,    36,    43,    44,   181,    40,    36,   170,    65,
     166,    40,    43,    44,   166,   201,    65,     4,   180,    37,
      38,    39,    15,    41,   186,    65,    66,    67,   207,   191,
      36,   210,   167,     3,    40,    66,    67,   223,    36,    26,
      42,    65,    29,    13,    31,    13,    42,    65,    18,   225,
      18,    42,   228,   188,     7,    25,   218,    25,    11,    32,
      41,   213,   241,   242,    36,    38,    39,     3,    41,     5,
      67,    41,    67,     9,     6,    11,    12,    13,    14,    65,
      47,    17,    18,    19,    42,    65,   224,    23,    24,    25,
      65,    27,    42,    29,    65,     3,    38,    39,   236,    41,
      65,    65,    38,    39,    12,    13,    39,    43,    44,   247,
      18,    19,    20,     3,    39,   253,    24,    25,    40,    27,
      38,    29,    42,    64,     3,    41,     5,    41,    64,    65,
      66,    67,    11,    12,    13,    14,    42,    47,    17,    18,
      19,    40,    21,     6,    23,    24,    25,    42,    27,    10,
      29,    16,    17,    41,    65,    30,    42,    65,     2,    38,
      39,   236,    27,    28,    43,    44,     2,    38,    39,   253,
      41,     2,    43,    44,    30,    31,    32,    33,    34,    35,
     106,     2,   158,   209,   191,    64,    65,    66,    67,     3,
     182,     5,    69,     7,    65,    66,    67,    11,    12,    13,
      14,    -1,    -1,    17,    18,    19,    -1,    -1,    -1,    23,
      24,    25,    -1,    27,    -1,    29,    38,    39,    -1,    -1,
      -1,    43,    44,    -1,    38,    39,    -1,    -1,    -1,    43,
      44,    36,    -1,    38,    39,    40,    41,    43,    44,    45,
      -1,    47,    48,    65,    66,    67,     3,    -1,     5,    -1,
      64,    65,    66,    67,    11,    12,    13,    14,    -1,    -1,
      17,    18,    19,    -1,    21,    -1,    23,    24,    25,    -1,
      27,    -1,    29,    38,    39,    -1,    -1,    -1,    43,    44,
      -1,    38,    39,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,     3,    -1,     5,    -1,    64,    65,    66,
      67,    11,    12,    13,    14,    -1,    -1,    17,    18,    19,
      -1,    -1,    -1,    23,    24,    25,    -1,    27,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    43,    44,
      45,    -1,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    69,    71,     0,     3,    12,    13,    18,    19,    20,
      24,    25,    27,    29,    65,    70,    72,    74,    75,    87,
      88,    89,    95,    97,   101,     3,    41,   101,    16,    17,
      27,    28,    90,    67,   102,   102,    65,   102,    65,    65,
      39,    73,    65,    65,    96,    41,     3,    65,   101,   101,
     101,    65,    91,    92,    15,    43,    44,    66,    67,    98,
      99,   100,    15,    96,     5,    11,    14,    17,    23,    38,
      39,    64,    65,    74,    78,    81,    87,    88,    89,    98,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   115,   123,   124,   126,   127,   128,    30,    39,    76,
      36,    98,    42,    42,    42,    41,    36,    93,    94,    95,
      67,    67,    93,    40,    65,    65,   112,    41,    65,   112,
     116,   117,   119,    47,    79,    65,    65,   124,   112,    65,
      37,    38,    39,    41,   125,     8,   104,   103,    43,    44,
      45,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,   114,    65,
      77,    97,    65,    42,    42,    92,    22,    95,    96,    39,
      32,     6,   116,    30,    31,    32,    33,    34,    35,   120,
     121,    26,    36,   129,     4,    22,   118,     3,    39,    38,
      40,    39,   125,    65,    96,   112,   122,   112,    38,     9,
     113,    36,    40,    93,    96,    97,   112,   103,    42,   112,
     103,   128,   116,    41,    40,    96,   122,    40,    36,    40,
      42,   125,    97,    47,    40,     6,    21,   120,     7,   130,
      80,    95,    40,    40,   112,    97,    82,    83,    84,    85,
      98,   103,   103,    10,    42,     9,    83,    41,    43,    44,
      45,    47,    48,    86,    21,    65,    98,    85,    30,    42
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
#line 1728 "musl.tab.cpp"
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
#line 285 "musl.y"


