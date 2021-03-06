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
%token T_ALTERNATIVE
%token T_AND
%token T_BEGIN
%token T_DATAVEC
%token T_DO
%token T_ELSE
%token T_MODULEEND
%token T_END
%token T_FI
%token T_FOR
%token T_FROM
%token T_IMPORT
%token T_INTEGER
%token T_INTEGER8
%token T_INTEGER16
%token T_INTEGER32
%token T_INTEGER64
%token T_IF
%token T_IS
%token T_LABEL
%token T_LITERAL
%token T_LOGICAL
%token T_LOGICAL8
%token T_LOGICAL16
%token T_LOGICAL32
%token T_LOGICAL64
%token T_LSPEC
%token T_MODULE
%token T_OD
%token T_OF
%token T_OR
%token T_PROC
%token T_PSPEC
%token T_REAL
%token T_REAL32
%token T_REAL64
%token T_REAL128
%token T_SWITCH
%token T_THEN
%token T_TYPE
%token T_VSTORE
%token T_WHILE
%token T_WITHIN

%token T_SEP
%token T_EQUALS
%token T_NOT_EQUALS
%token T_LT
%token T_GT
%token T_LE
%token T_GE
%token T_PERIOD
%token T_COMMA
%token T_COLON
%token T_CIRCUMFLEX
%token T_L_BRACK
%token T_R_BRACK
%token T_L_PAREN
%token T_R_PAREN
%token T_PLUS
%token T_MINUS
%token T_STAR
%token T_SLASH
%token T_FSLASH
%token T_AMPERSAND
%token T_EXCLAMATION
%token T_XOR
%token T_RSUB
%token T_RDIV
%token T_ADDSTORE
%token T_MULSTORE
%token T_DIVSTORE
%token T_ANDSTORE
%token T_ORSTORE
%token T_XORSTORE
%token T_ASSIGN
%token T_RSUBSTORE
%token T_RDIVSTORE
%token T_LLSHIFT
%token T_RLSHIFT
%token T_GOTO_OR_SUBSTORE

%token <nameval> T_TYPE_NAME
%token <nameval> T_PSPEC_NAME
%token <nameval> T_NAME
%token <charval> T_CHAR_CONST
%token <stringval> T_MULTI_CHAR_CONST
%token <stringval> T_CH_STRING
%token <unsignedval> T_NUMBER
%token <unsignedval> T_HEXNUMBER

%right T_ADDR T_L_PAREN

%type <nameval> proc_name

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
    char charval;
    char *stringval;
    char *nameval;
    unsigned int unsignedval;
}

%%

module: imports start_module exports separator statements T_MODULEEND;
start_module: T_MODULE | T_MODULE T_NAME;
separator: T_SEP | ;

imports: imports import separator | ;
import: proc_dec | type_dec | var_dec | import_dec; 

exports: T_L_BRACK name_list T_R_BRACK /*| ; removed optionality as it creates a shift/reduce conflict with computation statements */

proc_dec:
    proc_dec_spec T_NAME { new_pspec($2); }
    |
    proc_dec_spec T_NAME pspec { new_pspec($2); }
    |
    proc_dec_spec T_NAME T_EQUALS T_PSPEC_NAME { new_pspec($2); };
proc_dec_spec:
    T_LSPEC
    |
    T_PSPEC;
pspec:
    T_L_BRACK t_list T_R_BRACK
    |
    T_L_BRACK t_list T_R_BRACK T_SLASH scalar_type;

t_list: t_list T_COMMA scalar_type | scalar_type | ;

lit_dec:
    T_LITERAL integer_lits
    |
/*    T_LITERAL real_lits
    |
    T_LITERAL aggregate_lits
    |*/
    T_LITERAL pointer_lit;

pointer_lit: T_SLASH T_ADDR T_L_PAREN any_type T_R_PAREN T_NAME T_EQUALS;
any_type: type; /* any_type is not defined in the manual */

integer_lits: T_SLASH integer_type integer_list | integer_list;
integer_type: integer | logical;
integer_list: integer_list T_COMMA integer_list_item | integer_list_item;
integer_list_item: T_NAME T_EQUALS value;
value: const | const const_op value;

data_vec: T_DATAVEC T_NAME T_L_BRACK scalar_type T_R_BRACK separator literals separator T_END;
literals: literals literal_item | literal_item;
literal_item: literal | literal T_L_PAREN const T_R_PAREN;
literal: const_expr /*| aggregate_const*/;
const_expr: const | const const_op const_expr;
const_op: T_PLUS | T_MINUS | T_AMPERSAND | T_STAR | T_SLASH;

type_dec:
    T_TYPE T_NAME { new_type($2); }
    |
    T_TYPE T_NAME T_IS structure { new_type($2); }
    |
    T_TYPE T_NAME T_EQUALS const { new_type($2); }
    |
    T_WITHIN T_NAME T_IS structure;

var_dec: type name_list;

import_dec: T_IMPORT kind imp_list;
kind:
    T_LITERAL
    |
    T_LITERAL numeric_type
    |
    T_LITERAL T_ADDR /* not documented in manual */
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

name_list: name_list T_COMMA T_NAME { new_var($3); } | T_NAME { new_var($1); };
existing_name_list:
    existing_name_list T_COMMA T_NAME
    |
    existing_name_list T_COMMA T_PSPEC_NAME
    |
    T_NAME
    |
    T_PSPEC_NAME;

/* shift-reduce conflict because of vector declaration in the definition of <type> above, with conflict on left square bracket */
scalar_type:
    numeric_type
    |
    T_TYPE_NAME
    |
    /*T_ADDR numeric_type  This part of the rule excluded because of a shift-reduce conflict
    |*/
    T_ADDR T_PSPEC_NAME
    | 
    vector_pointer numeric_type T_R_PAREN
    |
    vector_pointer T_TYPE_NAME T_R_PAREN
    |
    vector_pointer T_ADDR T_R_PAREN
    |
    T_ADDR
    |
    T_ADDR T_ADDR;
vector_pointer: T_ADDR T_L_PAREN;

const: dec_integer | real_const | char_const | T_MULTI_CHAR_CONST | T_CH_STRING | T_NAME; /* see 9.3.5 for the rest. T_NAME not documented, also real_const documented but not shown as part of <const> */
dec_integer: T_NUMBER | T_PLUS T_NUMBER | T_MINUS T_NUMBER | T_HEXNUMBER | T_HEXNUMBER T_L_BRACK T_NUMBER T_R_BRACK;
char_const: T_CHAR_CONST;
real_const: dec_integer T_PERIOD T_NUMBER /* exponent syntax not covered*/

logical: T_LOGICAL | T_LOGICAL8  | T_LOGICAL16  | T_LOGICAL32 | T_LOGICAL64;
integer: T_INTEGER | T_INTEGER8 | T_INTEGER16 | T_INTEGER32 | T_INTEGER64;
real: T_REAL | T_REAL32 | T_REAL64 | T_REAL128;

numeric_type:
    integer
    |
    real
    |
    logical;

statements: statements statement separator | statement separator | ;

statement: declarative_statement | imperative_statement | proc_defn | block;
block: T_BEGIN separator statements T_END;

declarative_statement: label_dec | var_dec | proc_dec | lit_dec | data_vec | type_dec | import_dec;

imperative_statement: comp_st | control_st;

proc_name: T_NAME | T_PSPEC_NAME;
proc_defn: proc_heading separator statements T_END { pop_symbol(); };
proc_heading:
    T_PROC proc_name { new_pspec($2); push_symbol(); }
    |
    T_PROC proc_name T_L_BRACK T_R_BRACK { new_pspec($2); push_symbol(); }
    |
    T_PROC proc_name T_L_BRACK existing_name_list T_R_BRACK { new_pspec($2); push_symbol(); } 

label_dec: T_NAME T_COLON;

comp_st: computation | if_st | while_st| for_st;

control_st: go_st | switch_st | alt_st;

computation: opr_opd_seq;
opr_opd_seq: operand | operand operator opr_opd_seq;

operator: T_PLUS | T_MINUS | T_STAR | T_SLASH | T_AMPERSAND | T_EXCLAMATION | T_XOR | T_RSUB | T_RDIV | T_ADDSTORE | T_GOTO_OR_SUBSTORE | T_MULSTORE | T_DIVSTORE | T_ANDSTORE | T_ORSTORE | T_XORSTORE | T_ASSIGN | T_RSUBSTORE | T_RDIVSTORE | T_LLSHIFT | T_RLSHIFT;
operand: /* simplified */
    variable
    |
    T_CIRCUMFLEX variable
    |
    variable T_OF context
    |
    T_CIRCUMFLEX variable T_OF context
    |
    const
    |
    proc_name T_L_BRACK p_list T_R_BRACK
    |
    T_NAME T_CIRCUMFLEX T_L_BRACK p_list T_R_BRACK
    |
    T_L_BRACK computation T_R_BRACK
context: variable | variable T_OF context;

condition: test | test logop condition;
test: T_L_PAREN condition T_R_PAREN | comparison
logop: T_OR | T_AND;

comparison: computation compare_list;
compare_list: comparator computation compare_list | comparator computation;
comparator: T_EQUALS | T_NOT_EQUALS | T_LT | T_GT | T_LE | T_GE;

p_list: p_list T_COMMA computation | computation | ;

/* subscripts and variables as defined in the documenation create an ambiguous grammar, so I have re-factored the grammar slightly here */
variable: T_NAME | T_PSPEC_NAME | T_NAME subscript | T_NAME T_CIRCUMFLEX subscript | T_NAME subscript T_CIRCUMFLEX subscript;
subscript: T_L_PAREN computation T_R_PAREN ;

if_st: T_IF condition action
while_st: T_WHILE condition T_DO statements T_OD
for_st: T_FOR computation T_DO statements T_OD | T_FOR T_NAME T_LT computation T_DO statements T_OD 
go_st: T_GOTO_OR_SUBSTORE T_NAME;
switch_st: T_SWITCH computation T_FSLASH nlist;
alt_st: T_ALTERNATIVE computation T_FROM statements T_END;
nlist: nlist T_COMMA T_NAME | T_NAME;

action: T_COMMA go_st | T_THEN statements else_cl T_FI;
else_cl: T_ELSE statements | ;
%%

