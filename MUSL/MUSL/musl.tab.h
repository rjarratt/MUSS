/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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
/* Line 2058 of yacc.c  */
#line 135 "musl.y"

    char charval;
    char *stringval;
    char *nameval;
    unsigned int unsignedval;


/* Line 2058 of yacc.c  */
#line 156 "musl.tab.h"
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
