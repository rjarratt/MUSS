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
/* Line 2058 of yacc.c  */
#line 106 "musl.y"

    char charval;
    char *nameval;
    unsigned int unsignedval;


/* Line 2058 of yacc.c  */
#line 131 "musl.tab.h"
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
