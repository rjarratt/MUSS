/* flocoder.y: Flocoder cross-compiler Yacc syntax analyzer

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

%token <lineval> T_LINE
%token T_OTHERDATA
%token T_X
%token T_BOX
%token T_TITLE
%token T_ROW
%token T_COL
%token T_FLOW
%token T_END
%token T_PERIOD
%token T_HYPHEN
%token T_HASH
%token <nameval> T_NAME
%token <nameval> T_LABEL
%token <unsignedval> T_INTEGER

%{
#include <stdio.h>
#include <string.h>
#include "flip.h"

extern int yylex();
extern char *yytext;
extern int yylineno;

%}

%union
{
    char *nameval;
    char *lineval;
    int unsignedval;
}

%type <lineval> simple_line
%type <nameval> cross_ref_line

%%

file: documentation chart_list | chart_list;

documentation: x_directive documentation_lines;

documentation_lines: documentation_lines simple_line | simple_line;

chart_list: chart_list chart | chart;

chart: title_directive column_directive_list row_directive_list flow_directive_list row_directive_list box_list end_directive;

column_directive_list: column_directive_list column_directive | column_directive;

row_directive_list: row_directive_list row_directive | ;

flow_directive_list: flow_directive_list flow_directive | ;

box_list: box_list box | box;

box: box_directive box_lines;

box_lines: box_lines box_line | ;

simple_line: T_LINE { $$ = $1; }
cross_ref_line: T_HASH T_NAME { $$ = $2; }
box_line:
  simple_line { process_line($1); }
| cross_ref_line { process_cross_ref($1); }

x_directive: T_X T_OTHERDATA

title_directive: 
  T_TITLE T_NAME T_OTHERDATA { start_chart($2); }
| T_TITLE T_NAME { start_chart($2); }

column_directive: T_COL { start_column_sequence(); }column_box_refs

row_directive: T_ROW T_OTHERDATA

flow_directive: T_FLOW { start_flow_sequence(); } flow_box_refs { end_flow_sequence(); }

box_directive: T_BOX T_INTEGER T_PERIOD T_INTEGER {start_box($2, $4); }

end_directive: T_END { end_box(); }

column_box_refs: column_box_ref | column_box_refs T_HYPHEN column_box_ref
column_box_ref: T_INTEGER T_LABEL { process_column_box_ref($1, $2); }

flow_box_refs: flow_box_ref | flow_box_refs T_HYPHEN flow_box_ref
flow_box_ref: T_INTEGER T_LABEL { process_flow_box_ref($1); }
flow_box_ref: T_INTEGER { process_flow_box_ref($1); }
%%

