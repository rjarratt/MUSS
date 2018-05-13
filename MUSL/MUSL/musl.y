/* musl.y: MUSL cross-compiler Yacc syntax analyzer

Copyright (c) 2018, Robert Jarratt

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
ROBERT JARRATT BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of Robert Jarratt shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from Robert Jarratt.
*/

%token T_ADDR
%token T_END
%token T_IMPORT
%token T_INTEGER
%token T_IS
%token T_LABEL
%token T_LITERAL
%token T_LOGICAL
%token T_LSPEC
%token T_MODULE
%token T_OR
%token T_PSPEC
%token T_REAL
%token T_TYPE
%token T_VSTORE
%token T_WITHIN

%token T_EQUALS
%token T_COMMA
%token T_L_BRACK
%token T_R_BRACK
%token T_L_PAREN
%token T_R_PAREN
%token T_SLASH

%token <nameval> T_NAME
%token <unsignedval> T_NUMBER

%{
#include <stdio.h>
#include <string.h>
#include "musl.h"

extern int yylex();
extern char *yytext;
extern int yylineno;

%}

%union
{
    char *nameval;
    unsigned int unsignedval;
}

%%

module: imports start_module T_END;
start_module: T_MODULE | T_MODULE T_NAME;

imports: imports import | ;
import: proc_dec | type_dec | var_dec | import_dec

proc_dec:
    proc_dec_spec T_NAME
    |
    proc_dec_spec T_NAME pspec
    |
    proc_dec_spec T_NAME T_EQUALS T_NAME;
proc_dec_spec:
    T_LSPEC
    |
    T_PSPEC;
pspec:
    T_L_BRACK t_list T_R_BRACK
    |
    T_L_BRACK t_list T_R_BRACK T_SLASH scalar_type;

t_list: t_list T_COMMA scalar_type | scalar_type | ;

type_dec:
    T_TYPE T_NAME
    |
    T_TYPE T_NAME T_IS structure
    |
    T_TYPE T_NAME const
    |
    T_WITHIN T_NAME T_IS structure;

var_dec: type name_list;

import_dec: T_IMPORT kind imp_list;
kind:
    T_LITERAL
    |
    T_LITERAL numeric_type
    |
    T_VSTORE
    |
    T_VSTORE numeric_type
    |
    T_TYPE
    |
    T_LABEL;

imp_list: imp_list T_COMMA imp_list_item | imp_list_item;
imp_list_item:
    T_NAME
    |
    T_NAME T_L_PAREN T_R_PAREN

structure: fields | fields T_OR structure;
fields: fields type name_list |  type name_list;

type: scalar_type | scalar_type T_L_PAREN const T_R_PAREN;

name_list: name_list T_COMMA T_NAME | T_NAME;

scalar_type:
    numeric_type
    |
    T_NAME
    |
    T_ADDR numeric_type
    |
/*    T_ADDR T_NAME    This part of the rule is excluded as it creates an ambiguity in variable declarations of type ADDR. I think it is meant that T_NAME is the name of a TYPE
    |*/ 
    T_ADDR T_L_PAREN numeric_type T_R_PAREN
    |
    T_ADDR T_L_PAREN T_NAME T_R_PAREN
    |
    T_ADDR T_L_PAREN T_ADDR T_R_PAREN
    |
    T_ADDR
    |
    T_ADDR T_ADDR;

const: T_NUMBER; /* see 9.3.5 for the rest */

numeric_type:
    T_INTEGER size
    |
    T_REAL size
    |
    T_LOGICAL size;

size: T_NUMBER |;


%%

