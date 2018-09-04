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
#line 123 "musl.y"

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
     T_ALTERNATIVE = 259,
     T_AND = 260,
     T_BEGIN = 261,
     T_DATAVEC = 262,
     T_DO = 263,
     T_ELSE = 264,
     T_MODULEEND = 265,
     T_END = 266,
     T_FI = 267,
     T_FOR = 268,
     T_FROM = 269,
     T_IMPORT = 270,
     T_INTEGER = 271,
     T_INTEGER8 = 272,
     T_INTEGER16 = 273,
     T_INTEGER32 = 274,
     T_INTEGER64 = 275,
     T_IF = 276,
     T_IS = 277,
     T_LABEL = 278,
     T_LITERAL = 279,
     T_LOGICAL = 280,
     T_LOGICAL8 = 281,
     T_LOGICAL16 = 282,
     T_LOGICAL32 = 283,
     T_LOGICAL64 = 284,
     T_LSPEC = 285,
     T_MODULE = 286,
     T_OD = 287,
     T_OF = 288,
     T_OR = 289,
     T_PROC = 290,
     T_PSPEC = 291,
     T_REAL = 292,
     T_REAL32 = 293,
     T_REAL64 = 294,
     T_REAL128 = 295,
     T_SWITCH = 296,
     T_THEN = 297,
     T_TYPE = 298,
     T_VSTORE = 299,
     T_WHILE = 300,
     T_WITHIN = 301,
     T_SEP = 302,
     T_EQUALS = 303,
     T_NOT_EQUALS = 304,
     T_LT = 305,
     T_GT = 306,
     T_LE = 307,
     T_GE = 308,
     T_PERIOD = 309,
     T_COMMA = 310,
     T_COLON = 311,
     T_CIRCUMFLEX = 312,
     T_L_BRACK = 313,
     T_R_BRACK = 314,
     T_L_PAREN = 315,
     T_R_PAREN = 316,
     T_PLUS = 317,
     T_MINUS = 318,
     T_STAR = 319,
     T_SLASH = 320,
     T_FSLASH = 321,
     T_AMPERSAND = 322,
     T_EXCLAMATION = 323,
     T_XOR = 324,
     T_RSUB = 325,
     T_RDIV = 326,
     T_ADDSTORE = 327,
     T_MULSTORE = 328,
     T_DIVSTORE = 329,
     T_ANDSTORE = 330,
     T_ORSTORE = 331,
     T_XORSTORE = 332,
     T_ASSIGN = 333,
     T_RSUBSTORE = 334,
     T_RDIVSTORE = 335,
     T_LLSHIFT = 336,
     T_RLSHIFT = 337,
     T_GOTO_OR_SUBSTORE = 338,
     T_TYPE_NAME = 339,
     T_PSPEC_NAME = 340,
     T_NAME = 341,
     T_CHAR_CONST = 342,
     T_MULTI_CHAR_CONST = 343,
     T_CH_STRING = 344,
     T_NUMBER = 345,
     T_HEXNUMBER = 346
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 135 "musl.y"

    char charval;
    char *stringval;
    char *nameval;
    unsigned int unsignedval;


/* Line 387 of yacc.c  */
#line 221 "musl.tab.cpp"
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
#line 249 "musl.tab.cpp"

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
#define YYLAST   1130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  79
/* YYNRULES -- Number of rules.  */
#define YYNRULES  215
/* YYNRULES -- Number of states.  */
#define YYNSTATES  340

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   346

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
      85,    86,    87,    88,    89,    90,    91
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
     150,   153,   158,   163,   168,   171,   175,   177,   180,   183,
     185,   188,   190,   192,   196,   198,   200,   204,   206,   210,
     214,   217,   219,   224,   228,   230,   232,   234,   237,   241,
     245,   249,   251,   254,   257,   259,   261,   263,   265,   267,
     269,   271,   274,   277,   279,   284,   286,   290,   292,   294,
     296,   298,   300,   302,   304,   306,   308,   310,   312,   314,
     316,   318,   320,   322,   324,   328,   331,   332,   334,   336,
     338,   340,   345,   347,   349,   351,   353,   355,   357,   359,
     361,   363,   365,   367,   372,   375,   380,   386,   389,   391,
     393,   395,   397,   399,   401,   403,   405,   407,   411,   413,
     415,   417,   419,   421,   423,   425,   427,   429,   431,   433,
     435,   437,   439,   441,   443,   445,   447,   449,   451,   453,
     455,   458,   462,   467,   469,   474,   480,   484,   486,   490,
     492,   496,   500,   502,   504,   506,   509,   513,   516,   518,
     520,   522,   524,   526,   528,   532,   534,   535,   537,   539,
     542,   546,   551,   555,   559,   565,   571,   579,   582,   587,
     593,   597,   599,   602,   607,   610
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      93,     0,    -1,    96,    94,    98,    95,   137,    10,    -1,
      31,    -1,    31,    86,    -1,    47,    -1,    -1,    96,    97,
      95,    -1,    -1,    99,    -1,   117,    -1,   118,    -1,   119,
      -1,    58,   126,    59,    -1,   100,    86,    -1,   100,    86,
     101,    -1,   100,    86,    48,    85,    -1,    30,    -1,    36,
      -1,    58,   102,    59,    -1,    58,   102,    59,    65,   127,
      -1,   102,    55,   127,    -1,   127,    -1,    -1,    24,   106,
      -1,    24,   104,    -1,    65,     3,    60,   105,    61,    86,
      48,    -1,   125,    -1,    65,   107,   108,    -1,   108,    -1,
     134,    -1,   133,    -1,   108,    55,   109,    -1,   109,    -1,
      86,    48,   110,    -1,   129,    -1,   129,   116,   110,    -1,
       7,    86,    58,   127,    59,    95,   112,    95,    11,    -1,
     112,   113,    -1,   113,    -1,   114,    -1,   114,    60,   129,
      61,    -1,   115,    -1,   129,    -1,   129,   116,   115,    -1,
      62,    -1,    63,    -1,    67,    -1,    64,    -1,    65,    -1,
      43,    86,    -1,    43,    86,    22,   123,    -1,    43,    86,
      48,   129,    -1,    46,    86,    22,   123,    -1,   125,   126,
      -1,    15,   120,   121,    -1,    24,    -1,    24,   136,    -1,
      24,     3,    -1,    44,    -1,    44,   136,    -1,    43,    -1,
      23,    -1,   121,    55,   122,    -1,   122,    -1,    86,    -1,
      86,    60,    61,    -1,   124,    -1,   124,    34,   123,    -1,
     124,   125,   126,    -1,   125,   126,    -1,   127,    -1,   127,
      60,   129,    61,    -1,   126,    55,    86,    -1,    86,    -1,
     136,    -1,    84,    -1,     3,    85,    -1,   128,   136,    61,
      -1,   128,    84,    61,    -1,   128,     3,    61,    -1,     3,
      -1,     3,     3,    -1,     3,    60,    -1,   130,    -1,   132,
      -1,   131,    -1,    88,    -1,    89,    -1,    86,    -1,    90,
      -1,    62,    90,    -1,    63,    90,    -1,    91,    -1,    91,
      58,    90,    59,    -1,    87,    -1,   130,    54,    90,    -1,
      25,    -1,    26,    -1,    27,    -1,    28,    -1,    29,    -1,
      16,    -1,    17,    -1,    18,    -1,    19,    -1,    20,    -1,
      37,    -1,    38,    -1,    39,    -1,    40,    -1,   134,    -1,
     135,    -1,   133,    -1,   137,   138,    95,    -1,   138,    95,
      -1,    -1,   140,    -1,   141,    -1,   143,    -1,   139,    -1,
       6,    95,   137,    11,    -1,   145,    -1,   118,    -1,    99,
      -1,   103,    -1,   111,    -1,   117,    -1,   119,    -1,   146,
      -1,   147,    -1,    86,    -1,    85,    -1,   144,    95,   137,
      11,    -1,    35,   142,    -1,    35,   142,    58,    59,    -1,
      35,   142,    58,   126,    59,    -1,    86,    56,    -1,   148,
      -1,   162,    -1,   163,    -1,   164,    -1,   165,    -1,   166,
      -1,   167,    -1,   149,    -1,   151,    -1,   151,   150,   149,
      -1,    62,    -1,    63,    -1,    64,    -1,    65,    -1,    67,
      -1,    68,    -1,    69,    -1,    70,    -1,    71,    -1,    72,
      -1,    83,    -1,    73,    -1,    74,    -1,    75,    -1,    76,
      -1,    77,    -1,    78,    -1,    79,    -1,    80,    -1,    81,
      -1,    82,    -1,   160,    -1,    57,   160,    -1,   160,    33,
     152,    -1,    57,   160,    33,   152,    -1,   129,    -1,   142,
      58,   159,    59,    -1,    86,    57,    58,   159,    59,    -1,
      58,   148,    59,    -1,   160,    -1,   160,    33,   152,    -1,
     154,    -1,   154,   155,   153,    -1,    60,   153,    61,    -1,
     156,    -1,    34,    -1,     5,    -1,   148,   157,    -1,   158,
     148,   157,    -1,   158,   148,    -1,    48,    -1,    49,    -1,
      50,    -1,    51,    -1,    52,    -1,    53,    -1,   159,    55,
     148,    -1,   148,    -1,    -1,    86,    -1,    85,    -1,    86,
     161,    -1,    86,    57,   161,    -1,    86,   161,    57,   161,
      -1,    60,   148,    61,    -1,    21,   153,   169,    -1,    45,
     153,     8,   137,    32,    -1,    13,   148,     8,   137,    32,
      -1,    13,    86,    50,   148,     8,   137,    32,    -1,    83,
      86,    -1,    41,   148,    66,   168,    -1,     4,   148,    14,
     137,    11,    -1,   168,    55,    86,    -1,    86,    -1,    55,
     165,    -1,    42,   137,   170,    12,    -1,     9,   137,    -1,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   144,   144,   145,   145,   146,   146,   148,   148,   149,
     149,   149,   149,   151,   154,   156,   158,   160,   162,   164,
     166,   168,   168,   168,   171,   177,   179,   180,   182,   182,
     183,   183,   184,   184,   185,   186,   186,   188,   189,   189,
     190,   190,   191,   192,   192,   193,   193,   193,   193,   193,
     196,   198,   200,   202,   204,   206,   208,   210,   212,   214,
     216,   218,   220,   222,   222,   224,   226,   228,   228,   229,
     229,   231,   231,   233,   233,   237,   239,   243,   245,   247,
     249,   251,   253,   254,   256,   256,   256,   256,   256,   256,
     257,   257,   257,   257,   257,   258,   259,   261,   261,   261,
     261,   261,   262,   262,   262,   262,   262,   263,   263,   263,
     263,   266,   268,   270,   272,   272,   272,   274,   274,   274,
     274,   275,   277,   277,   277,   277,   277,   277,   277,   279,
     279,   281,   281,   282,   283,   283,   283,   285,   287,   287,
     287,   287,   289,   289,   289,   291,   292,   292,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   296,
     298,   300,   302,   304,   306,   308,   310,   311,   311,   313,
     313,   314,   314,   315,   315,   317,   318,   318,   319,   319,
     319,   319,   319,   319,   321,   321,   321,   324,   324,   324,
     324,   324,   325,   327,   328,   329,   329,   330,   331,   332,
     333,   333,   335,   335,   336,   336
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ADDR", "T_ALTERNATIVE", "T_AND",
  "T_BEGIN", "T_DATAVEC", "T_DO", "T_ELSE", "T_MODULEEND", "T_END", "T_FI",
  "T_FOR", "T_FROM", "T_IMPORT", "T_INTEGER", "T_INTEGER8", "T_INTEGER16",
  "T_INTEGER32", "T_INTEGER64", "T_IF", "T_IS", "T_LABEL", "T_LITERAL",
  "T_LOGICAL", "T_LOGICAL8", "T_LOGICAL16", "T_LOGICAL32", "T_LOGICAL64",
  "T_LSPEC", "T_MODULE", "T_OD", "T_OF", "T_OR", "T_PROC", "T_PSPEC",
  "T_REAL", "T_REAL32", "T_REAL64", "T_REAL128", "T_SWITCH", "T_THEN",
  "T_TYPE", "T_VSTORE", "T_WHILE", "T_WITHIN", "T_SEP", "T_EQUALS",
  "T_NOT_EQUALS", "T_LT", "T_GT", "T_LE", "T_GE", "T_PERIOD", "T_COMMA",
  "T_COLON", "T_CIRCUMFLEX", "T_L_BRACK", "T_R_BRACK", "T_L_PAREN",
  "T_R_PAREN", "T_PLUS", "T_MINUS", "T_STAR", "T_SLASH", "T_FSLASH",
  "T_AMPERSAND", "T_EXCLAMATION", "T_XOR", "T_RSUB", "T_RDIV",
  "T_ADDSTORE", "T_MULSTORE", "T_DIVSTORE", "T_ANDSTORE", "T_ORSTORE",
  "T_XORSTORE", "T_ASSIGN", "T_RSUBSTORE", "T_RDIVSTORE", "T_LLSHIFT",
  "T_RLSHIFT", "T_GOTO_OR_SUBSTORE", "T_TYPE_NAME", "T_PSPEC_NAME",
  "T_NAME", "T_CHAR_CONST", "T_MULTI_CHAR_CONST", "T_CH_STRING",
  "T_NUMBER", "T_HEXNUMBER", "$accept", "module", "start_module",
  "separator", "imports", "import", "exports", "proc_dec", "proc_dec_spec",
  "pspec", "t_list", "lit_dec", "pointer_lit", "any_type", "integer_lits",
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
  "go_st", "switch_st", "alt_st", "nlist", "action", "else_cl", YY_NULL
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
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    94,    94,    95,    95,    96,    96,    97,
      97,    97,    97,    98,    99,    99,    99,   100,   100,   101,
     101,   102,   102,   102,   103,   103,   104,   105,   106,   106,
     107,   107,   108,   108,   109,   110,   110,   111,   112,   112,
     113,   113,   114,   115,   115,   116,   116,   116,   116,   116,
     117,   117,   117,   117,   118,   119,   120,   120,   120,   120,
     120,   120,   120,   121,   121,   122,   122,   123,   123,   124,
     124,   125,   125,   126,   126,   127,   127,   127,   127,   127,
     127,   127,   127,   128,   129,   129,   129,   129,   129,   129,
     130,   130,   130,   130,   130,   131,   132,   133,   133,   133,
     133,   133,   134,   134,   134,   134,   134,   135,   135,   135,
     135,   136,   136,   136,   137,   137,   137,   138,   138,   138,
     138,   139,   140,   140,   140,   140,   140,   140,   140,   141,
     141,   142,   142,   143,   144,   144,   144,   145,   146,   146,
     146,   146,   147,   147,   147,   148,   149,   149,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   151,
     151,   151,   151,   151,   151,   151,   151,   152,   152,   153,
     153,   154,   154,   155,   155,   156,   157,   157,   158,   158,
     158,   158,   158,   158,   159,   159,   159,   160,   160,   160,
     160,   160,   161,   162,   163,   164,   164,   165,   166,   167,
     168,   168,   169,   169,   170,   170
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     1,     2,     1,     0,     3,     0,     1,
       1,     1,     1,     3,     2,     3,     4,     1,     1,     3,
       5,     3,     1,     0,     2,     2,     7,     1,     3,     1,
       1,     1,     3,     1,     3,     1,     3,     9,     2,     1,
       1,     4,     1,     1,     3,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     2,     3,     1,     2,     2,     1,
       2,     1,     1,     3,     1,     1,     3,     1,     3,     3,
       2,     1,     4,     3,     1,     1,     1,     2,     3,     3,
       3,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     4,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     0,     1,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     2,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     4,     1,     4,     5,     3,     1,     3,     1,
       3,     3,     1,     1,     1,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     1,     1,     2,
       3,     4,     3,     3,     5,     5,     7,     2,     4,     5,
       3,     1,     2,     4,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,    81,     0,   102,   103,   104,   105,
     106,    97,    98,    99,   100,   101,    17,     3,    18,   107,
     108,   109,   110,     0,     0,    76,     0,     6,     9,     0,
      10,    11,    12,     0,    71,     0,   113,   111,   112,    75,
      82,    83,    77,    62,    56,    61,    59,     0,     4,    50,
       0,     0,     6,     5,     7,    14,    74,    54,     0,     0,
       0,     0,    58,    57,    60,    65,    55,    64,     0,     0,
       0,     0,   116,     0,    23,    15,     0,     0,     0,    89,
      95,    87,    88,    90,    93,     0,    84,    86,    85,    80,
      79,    78,     0,     0,    51,    67,     0,    52,    53,    13,
       0,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   198,    89,   124,   125,   126,   127,   123,   128,
     173,     0,     6,   120,   117,   118,     0,   119,     6,   122,
     129,   130,   138,   145,   146,   169,   139,   140,   141,   142,
     143,   144,    16,     0,    22,    73,    91,    92,     0,    72,
       0,    66,    63,     0,     0,    70,    89,     0,   116,     0,
      89,     0,     0,     0,     0,   179,   182,     0,     0,    25,
      24,    29,    33,   132,   131,   134,     0,     0,   198,   197,
     170,     0,   207,   137,     0,     0,   199,     2,     6,   115,
     196,   116,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   158,     0,     0,     0,    19,     0,    96,    68,
      69,   116,     0,     0,     0,   116,     0,   188,   189,   190,
     191,   192,   193,   185,     0,   116,     0,   203,   184,   183,
       0,     0,     0,    31,    30,     0,     0,     0,     0,   116,
       0,     0,   176,   196,   200,     0,     0,   114,   195,     0,
       0,   147,   171,   177,    21,     0,    94,     0,   121,     0,
       0,     0,   181,   187,   215,   212,   180,     0,    28,    34,
      35,    32,   135,     0,   211,   208,     0,   172,     0,   202,
     201,     0,   174,   133,     0,    20,   209,     6,   116,   205,
     186,   116,     0,     0,    27,    45,    46,    48,    49,    47,
       0,   136,     0,   204,   175,   194,   178,     0,     0,   214,
     213,     0,    36,   210,     6,    39,    40,    42,    43,   206,
       0,     0,    38,     0,     0,    26,    37,     0,    44,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,    54,     2,    27,    52,   114,    29,    75,
     143,   115,   169,   303,   170,   242,   171,   172,   279,   116,
     324,   325,   326,   327,   310,   117,   118,   119,    47,    66,
      67,    94,    95,    33,    57,    34,    35,   120,    86,    87,
      88,    36,    37,    38,    39,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   213,   134,
     262,   164,   165,   240,   166,   233,   234,   259,   135,   186,
     136,   137,   138,   139,   140,   141,   285,   237,   302
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -231
static const yytype_int16 yypact[] =
{
    -231,    25,    17,  -231,    15,    82,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,   -56,  -231,  -231,
    -231,  -231,  -231,    -6,     0,  -231,    45,    61,  -231,    31,
    -231,  -231,  -231,    38,    67,   154,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  1052,  -231,  1068,    44,  -231,    54,
     113,    38,    61,  -231,  -231,    14,  -231,    83,   174,    85,
      93,   106,  -231,  -231,  -231,   109,    86,  -231,   203,   174,
     203,   -31,   976,    58,   203,  -231,    91,    96,    98,  -231,
    -231,  -231,  -231,  -231,   139,   137,   145,  -231,  -231,  -231,
    -231,  -231,   142,    44,  -231,    94,    38,  -231,  -231,  -231,
     127,    61,   118,   432,   343,   -27,    80,   127,   343,    90,
     127,   121,   150,    36,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,   264,    61,  -231,  -231,  -231,   151,  -231,    61,  -231,
    -231,  -231,  -231,  -231,  1047,   177,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,   -28,  -231,  -231,  -231,  -231,   134,  -231,
     135,  -231,  -231,   203,    38,    83,    28,   212,   976,   169,
       8,   225,   343,   205,   -16,    18,  -231,   579,   186,  -231,
    -231,   180,  -231,  -231,  -231,   181,   178,   237,  -231,    34,
     214,   189,  -231,  -231,    21,   127,   192,  -231,    61,  -231,
     127,   976,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,  -231,
    -231,  -231,  -231,   127,    90,   203,   185,   210,  -231,  -231,
      83,   976,   353,   203,   127,   976,   190,  -231,  -231,  -231,
    -231,  -231,  -231,  -231,   127,   976,   195,  -231,  -231,  -231,
     343,   226,   209,  -231,  -231,   174,   209,   -37,   211,   976,
     238,    90,  -231,   127,  -231,   245,   238,  -231,  -231,    23,
     442,  -231,  -231,   239,  -231,   203,  -231,   531,  -231,   254,
     300,   620,  -231,   205,   709,  -231,  -231,   203,   180,  -231,
      97,  -231,  -231,    81,  -231,   259,   798,  -231,    89,  -231,
    -231,   127,  -231,  -231,    90,  -231,  -231,    61,   976,  -231,
    -231,   976,   303,   255,  -231,  -231,  -231,  -231,  -231,  -231,
     174,  -231,   231,  -231,  -231,  -231,  -231,   174,   887,   976,
    -231,   232,  -231,  -231,   249,  -231,   260,  -231,    97,  -231,
     271,   312,  -231,   174,   174,  -231,  -231,   263,  -231,  -231
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -231,  -231,  -231,   -51,  -231,  -231,  -231,   323,  -231,  -231,
    -231,  -231,  -231,  -231,  -231,  -231,    87,    84,    22,  -231,
    -231,     4,  -231,    -3,     5,   332,   339,   340,  -231,  -231,
     250,   -54,  -231,   -66,   -45,   -60,  -231,   -58,  -231,  -231,
    -231,   179,   191,  -231,    72,  -151,  -118,  -231,  -231,  -231,
     256,  -231,  -231,  -231,  -231,  -231,   -95,   131,  -231,  -231,
    -230,   -89,  -231,  -231,  -231,    88,  -231,    92,   -99,  -167,
    -231,  -231,  -231,   129,  -231,  -231,  -231,  -231,  -231
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -198
static const yytype_int16 yytable[] =
{
      85,    72,    96,   188,    96,   157,    71,   222,   161,   163,
     180,    97,   176,   163,   144,   181,    98,   254,    40,   177,
       4,   287,   282,   238,    76,     3,   235,   215,    99,   154,
      48,   216,     5,     6,     7,     8,     9,    10,   167,   236,
     260,  -197,    11,    12,    13,    14,    15,    16,    17,    56,
     158,   155,   239,    18,    19,    20,    21,    22,   224,   168,
      23,  -197,    73,    24,   316,   184,  -131,   163,   185,  -197,
     267,   189,    74,   226,   271,    41,    68,   191,   291,   253,
      49,   185,   292,   254,   274,   184,    50,    96,   185,   290,
     255,   250,   183,   184,   185,   258,   185,     4,   286,   219,
      42,    25,    69,    51,   188,    43,    44,    61,    53,   220,
       6,     7,     8,     9,    10,   263,    63,    55,    64,    11,
      12,    13,    14,    15,    56,    45,    46,    58,   153,   270,
      65,    19,    20,    21,    22,    70,    76,   257,    76,   273,
     311,    93,   188,   142,   291,   163,    89,   318,   314,   188,
     319,   276,   263,   188,    90,   264,   188,    59,   258,   305,
     306,   307,   308,   269,   309,   173,   174,    91,   188,    92,
       6,     7,     8,     9,    10,   178,   179,   145,    25,    11,
      12,    13,    14,    15,   109,   110,   146,   280,   147,    77,
      78,    19,    20,    21,    22,   263,   315,   148,   149,   150,
     188,   188,   283,   151,   159,   295,     4,   182,  -132,   190,
     214,   304,   112,   156,    80,    81,    82,    83,    84,     6,
       7,     8,     9,    10,   217,   218,   221,   223,    11,    12,
      13,    14,    15,   225,   245,   246,    77,    78,    60,   247,
      19,    20,    21,    22,   248,   249,   317,   251,   252,   256,
     265,   272,   280,   227,   228,   229,   230,   231,   232,   328,
      79,    80,    81,    82,    83,    84,   328,     4,   100,   266,
     101,   102,   294,   331,   187,   337,   328,   103,   111,     5,
       6,     7,     8,     9,    10,   104,   277,    25,   105,    11,
      12,    13,    14,    15,    16,   168,    53,   284,   185,   106,
      18,    19,    20,    21,    22,   107,   289,    23,   298,   108,
      24,    77,    78,   297,   312,   320,   321,   323,   330,   335,
     333,   109,   110,   336,   339,    28,    77,    78,   332,   278,
     281,   338,   322,   334,    30,    79,    80,    81,    82,    83,
      84,    31,    32,   152,   261,   288,   243,   111,    25,   112,
     113,    80,    81,    82,    83,    84,     4,   100,   244,   101,
     102,   300,   175,     0,   268,   275,   103,     0,     5,     6,
       7,     8,     9,    10,   104,     0,     0,   105,    11,    12,
      13,    14,    15,    16,     0,     0,     0,     0,   106,    18,
      19,    20,    21,    22,   107,     0,    23,     0,   108,    24,
     109,   110,     0,   162,     0,    77,    78,     0,     0,     0,
     109,   110,     0,     0,     0,    77,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   112,   156,
      80,    81,    82,    83,    84,     0,   111,    25,   112,   113,
      80,    81,    82,    83,    84,     4,   100,     0,   101,   102,
       0,     0,     0,   293,     0,   103,     0,     5,     6,     7,
       8,     9,    10,   104,     0,     0,   105,    11,    12,    13,
      14,    15,    16,     0,     0,     0,     0,   106,    18,    19,
      20,    21,    22,   107,     0,    23,     0,   108,    24,   109,
     110,     0,     0,     0,    77,    78,     0,     0,     0,   109,
     110,     0,     0,     0,    77,    78,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   112,   160,    80,
      81,    82,    83,    84,     0,   111,    25,   112,   113,    80,
      81,    82,    83,    84,     4,   100,     0,   101,   102,     0,
       0,     0,   296,     0,   103,     0,     5,     6,     7,     8,
       9,    10,   104,     0,     0,   105,    11,    12,    13,    14,
      15,    16,     0,     0,     0,     0,   106,    18,    19,    20,
      21,    22,   107,     0,    23,     0,   108,    24,     0,     0,
       0,     0,   241,     0,     0,     0,     0,     0,   109,   110,
       0,     0,     0,    77,    78,     6,     7,     8,     9,    10,
       0,     0,     0,     0,    11,    12,    13,    14,    15,     0,
       0,     0,     0,     0,   111,    25,   112,   113,    80,    81,
      82,    83,    84,     4,   100,     0,   101,   102,     0,     0,
       0,     0,     0,   103,     0,     5,     6,     7,     8,     9,
      10,   104,     0,     0,   105,    11,    12,    13,    14,    15,
      16,     0,   299,     0,     0,   106,    18,    19,    20,    21,
      22,   107,     0,    23,     0,   108,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,   110,     0,
       0,     0,    77,    78,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   111,    25,   112,   113,    80,    81,    82,
      83,    84,     4,   100,     0,   101,   102,     0,   301,     0,
       0,     0,   103,     0,     5,     6,     7,     8,     9,    10,
     104,     0,     0,   105,    11,    12,    13,    14,    15,    16,
       0,     0,     0,     0,   106,    18,    19,    20,    21,    22,
     107,     0,    23,     0,   108,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,   110,     0,     0,
       0,    77,    78,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   111,    25,   112,   113,    80,    81,    82,    83,
      84,     4,   100,     0,   101,   102,     0,     0,     0,     0,
       0,   103,     0,     5,     6,     7,     8,     9,    10,   104,
       0,     0,   105,    11,    12,    13,    14,    15,    16,     0,
     313,     0,     0,   106,    18,    19,    20,    21,    22,   107,
       0,    23,     0,   108,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   109,   110,     0,     0,     0,
      77,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   111,    25,   112,   113,    80,    81,    82,    83,    84,
       4,   100,     0,   101,   102,     0,     0,     0,     0,     0,
     103,     0,     5,     6,     7,     8,     9,    10,   104,     0,
       0,   105,    11,    12,    13,    14,    15,    16,     0,   329,
       0,     0,   106,    18,    19,    20,    21,    22,   107,     0,
      23,     0,   108,    24,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   109,   110,     0,     0,     0,    77,
      78,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,    25,   112,   113,    80,    81,    82,    83,    84,     4,
     100,     0,   101,   102,     0,     0,     0,     0,     0,   103,
       0,     5,     6,     7,     8,     9,    10,   104,     0,     0,
     105,    11,    12,    13,    14,    15,    16,     0,     0,     0,
       0,   106,    18,    19,    20,    21,    22,   107,     0,    23,
       0,   108,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   110,     0,     0,     0,    77,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    62,     0,     0,     0,   111,
      25,   112,   113,    80,    81,    82,    83,    84,     6,     7,
       8,     9,    10,     0,     0,     0,     0,    11,    12,    13,
      14,    15,     0,     0,     6,     7,     8,     9,    10,    19,
      20,    21,    22,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,    19,    20,    21,    22,   192,
     193,   194,   195,     0,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-231)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      58,    52,    68,   121,    70,   100,    51,   158,   103,   104,
     109,    69,   107,   108,    74,   110,    70,   184,     3,   108,
       3,   251,    59,     5,    55,     0,    42,    55,    59,    95,
      86,    59,    15,    16,    17,    18,    19,    20,    65,    55,
     191,    33,    25,    26,    27,    28,    29,    30,    31,    86,
     101,    96,    34,    36,    37,    38,    39,    40,    50,    86,
      43,    33,    48,    46,   294,    57,    58,   162,    60,    33,
     221,   122,    58,   162,   225,    60,    22,   128,    55,    58,
      86,    60,    59,   250,   235,    57,    86,   153,    60,   256,
     185,    57,    56,    57,    60,   190,    60,     3,   249,   153,
      85,    84,    48,    58,   222,    23,    24,    35,    47,   154,
      16,    17,    18,    19,    20,   214,    44,    86,    46,    25,
      26,    27,    28,    29,    86,    43,    44,    60,    34,   224,
      86,    37,    38,    39,    40,    22,    55,   188,    55,   234,
      59,    55,   260,    85,    55,   240,    61,   298,    59,   267,
     301,   240,   251,   271,    61,   215,   274,     3,   253,    62,
      63,    64,    65,   223,    67,    85,    86,    61,   286,    60,
      16,    17,    18,    19,    20,    85,    86,    86,    84,    25,
      26,    27,    28,    29,    57,    58,    90,   245,    90,    62,
      63,    37,    38,    39,    40,   294,   291,    58,    61,    54,
     318,   319,   247,    61,    86,   265,     3,    86,    58,    58,
      33,   277,    85,    86,    87,    88,    89,    90,    91,    16,
      17,    18,    19,    20,    90,    90,    14,    58,    25,    26,
      27,    28,    29,     8,    48,    55,    62,    63,    84,    58,
      37,    38,    39,    40,    66,     8,   297,    33,    59,    57,
      65,    61,   310,    48,    49,    50,    51,    52,    53,   317,
      86,    87,    88,    89,    90,    91,   324,     3,     4,    59,
       6,     7,    33,   324,    10,   333,   334,    13,    83,    15,
      16,    17,    18,    19,    20,    21,    60,    84,    24,    25,
      26,    27,    28,    29,    30,    86,    47,    86,    60,    35,
      36,    37,    38,    39,    40,    41,    61,    43,     8,    45,
      46,    62,    63,    59,    55,    12,    61,    86,    86,    48,
      60,    57,    58,    11,    61,     2,    62,    63,   324,   242,
     246,   334,   310,   328,     2,    86,    87,    88,    89,    90,
      91,     2,     2,    93,   213,   253,   167,    83,    84,    85,
      86,    87,    88,    89,    90,    91,     3,     4,   167,     6,
       7,   273,   106,    -1,    11,   236,    13,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    -1,    45,    46,
      57,    58,    -1,    60,    -1,    62,    63,    -1,    -1,    -1,
      57,    58,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      87,    88,    89,    90,    91,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    91,     3,     4,    -1,     6,     7,
      -1,    -1,    -1,    11,    -1,    13,    -1,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    -1,    45,    46,    57,
      58,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    57,
      58,    -1,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    87,
      88,    89,    90,    91,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,    91,     3,     4,    -1,     6,     7,    -1,
      -1,    -1,    11,    -1,    13,    -1,    15,    16,    17,    18,
      19,    20,    21,    -1,    -1,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,
      -1,    -1,     3,    -1,    -1,    -1,    -1,    -1,    57,    58,
      -1,    -1,    -1,    62,    63,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    83,    84,    85,    86,    87,    88,
      89,    90,    91,     3,     4,    -1,     6,     7,    -1,    -1,
      -1,    -1,    -1,    13,    -1,    15,    16,    17,    18,    19,
      20,    21,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    -1,
      -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      90,    91,     3,     4,    -1,     6,     7,    -1,     9,    -1,
      -1,    -1,    13,    -1,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    -1,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    83,    84,    85,    86,    87,    88,    89,    90,
      91,     3,     4,    -1,     6,     7,    -1,    -1,    -1,    -1,
      -1,    13,    -1,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    -1,    -1,    35,    36,    37,    38,    39,    40,    41,
      -1,    43,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    -1,    -1,    -1,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,    91,
       3,     4,    -1,     6,     7,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    -1,    32,
      -1,    -1,    35,    36,    37,    38,    39,    40,    41,    -1,
      43,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    -1,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      83,    84,    85,    86,    87,    88,    89,    90,    91,     3,
       4,    -1,     6,     7,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    -1,    43,
      -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    -1,    -1,    -1,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,    -1,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    -1,    -1,    16,    17,    18,    19,    20,    37,
      38,    39,    40,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    38,    39,    40,    62,
      63,    64,    65,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    93,    96,     0,     3,    15,    16,    17,    18,    19,
      20,    25,    26,    27,    28,    29,    30,    31,    36,    37,
      38,    39,    40,    43,    46,    84,    94,    97,    99,   100,
     117,   118,   119,   125,   127,   128,   133,   134,   135,   136,
       3,    60,    85,    23,    24,    43,    44,   120,    86,    86,
      86,    58,    98,    47,    95,    86,    86,   126,    60,     3,
      84,   136,     3,   136,   136,    86,   121,   122,    22,    48,
      22,   126,    95,    48,    58,   101,    55,    62,    63,    86,
      87,    88,    89,    90,    91,   129,   130,   131,   132,    61,
      61,    61,    60,    55,   123,   124,   125,   129,   123,    59,
       4,     6,     7,    13,    21,    24,    35,    41,    45,    57,
      58,    83,    85,    86,    99,   103,   111,   117,   118,   119,
     129,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   151,   160,   162,   163,   164,   165,
     166,   167,    85,   102,   127,    86,    90,    90,    58,    61,
      54,    61,   122,    34,   125,   126,    86,   148,    95,    86,
      86,   148,    60,   148,   153,   154,   156,    65,    86,   104,
     106,   108,   109,    85,    86,   142,   148,   153,    85,    86,
     160,   148,    86,    56,    57,    60,   161,    10,   138,    95,
      58,    95,    62,    63,    64,    65,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,   150,    33,    55,    59,    90,    90,   123,
     126,    14,   137,    58,    50,     8,   153,    48,    49,    50,
      51,    52,    53,   157,   158,    42,    55,   169,     5,    34,
     155,     3,   107,   133,   134,    48,    55,    58,    66,     8,
      57,    33,    59,    58,   161,   148,    57,    95,   148,   159,
     137,   149,   152,   160,   127,    65,    59,   137,    11,   127,
     148,   137,    61,   148,   137,   165,   153,    60,   108,   110,
     129,   109,    59,   126,    86,   168,   137,   152,   159,    61,
     161,    55,    59,    11,    33,   127,    11,    59,     8,    32,
     157,     9,   170,   105,   125,    62,    63,    64,    65,    67,
     116,    59,    55,    32,    59,   148,   152,    95,   137,   137,
      12,    61,   110,    86,   112,   113,   114,   115,   129,    32,
      86,    95,   113,    60,   116,    48,    11,   129,   115,    61
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
#line 154 "musl.y"
    { new_pspec((yyvsp[(2) - (2)].nameval)); }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 156 "musl.y"
    { new_pspec((yyvsp[(2) - (3)].nameval)); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 158 "musl.y"
    { new_pspec((yyvsp[(2) - (4)].nameval)); }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 196 "musl.y"
    { new_type((yyvsp[(2) - (2)].nameval)); }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 198 "musl.y"
    { new_type((yyvsp[(2) - (4)].nameval)); }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 200 "musl.y"
    { new_type((yyvsp[(2) - (4)].nameval)); }
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 283 "musl.y"
    { new_pspec((yyvsp[(2) - (2)].nameval)); }
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 283 "musl.y"
    { new_pspec((yyvsp[(2) - (4)].nameval)); }
    break;

  case 136:
/* Line 1792 of yacc.c  */
#line 283 "musl.y"
    { new_pspec((yyvsp[(2) - (5)].nameval)); }
    break;


/* Line 1792 of yacc.c  */
#line 2009 "musl.tab.cpp"
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
#line 337 "musl.y"


