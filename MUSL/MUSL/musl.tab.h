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
     T_DATAVEC = 259,
     T_DO = 260,
     T_MODULEEND = 261,
     T_END = 262,
     T_FOR = 263,
     T_IMPORT = 264,
     T_INTEGER = 265,
     T_IS = 266,
     T_LABEL = 267,
     T_LITERAL = 268,
     T_LOGICAL = 269,
     T_LSPEC = 270,
     T_MODULE = 271,
     T_OD = 272,
     T_OR = 273,
     T_PROC = 274,
     T_PSPEC = 275,
     T_REAL = 276,
     T_TYPE = 277,
     T_VSTORE = 278,
     T_WITHIN = 279,
     T_EQUALS = 280,
     T_LT = 281,
     T_COMMA = 282,
     T_COLON = 283,
     T_CIRCUMFLEX = 284,
     T_L_BRACK = 285,
     T_R_BRACK = 286,
     T_L_PAREN = 287,
     T_R_PAREN = 288,
     T_PLUS = 289,
     T_MINUS = 290,
     T_STAR = 291,
     token = 292,
     T_SLASH = 293,
     T_AMPERSAND = 294,
     T_EXCLAMATION = 295,
     T_XOR = 296,
     T_RSUB = 297,
     T_RDIV = 298,
     T_ADDSTORE = 299,
     T_MULSTORE = 300,
     T_DIVSTORE = 301,
     T_ANDSTORE = 302,
     T_ORSTORE = 303,
     T_XORSTORE = 304,
     T_ASSIGN = 305,
     T_RSUBSTORE = 306,
     T_RDIVSTORE = 307,
     T_LLSHIFT = 308,
     T_RLSHIFT = 309,
     T_GOTO = 310,
     T_NAME = 311,
     T_CHAR_CONST = 312,
     T_NUMBER = 313
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 97 "musl.y"

    char charval;
    char *nameval;
    unsigned int unsignedval;


/* Line 2058 of yacc.c  */
#line 122 "musl.tab.h"
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
