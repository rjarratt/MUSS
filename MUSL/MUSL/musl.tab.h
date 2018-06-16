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
/* Line 2058 of yacc.c  */
#line 115 "musl.y"

    char charval;
    char *stringval;
    char *nameval;
    unsigned int unsignedval;


/* Line 2058 of yacc.c  */
#line 138 "musl.tab.h"
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
