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

%token T_START_DIRECTIVE
%token <lineval> T_LINE
%token T_OTHERDATA
%token T_X
%token T_BOX
%token T_TITLE
%token T_ROW
%token T_COL
%token T_FLOW
%token T_END
%token T_NL
%token T_PERIOD
%token T_HASH
%token <nameval> T_NAME
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

%%

file: statement | file statement
statement:
  T_START_DIRECTIVE directive T_NL
| T_LINE T_NL { process_line($1); }
| T_HASH T_NAME T_NL { process_cross_ref($2); }
| T_NL

directive:
  T_X T_OTHERDATA
| T_TITLE T_NAME T_OTHERDATA { start_chart($2); }
| T_BOX T_INTEGER T_PERIOD T_INTEGER {start_box($2, $4); }
| T_ROW T_OTHERDATA { end_box(); }
| T_COL T_OTHERDATA { end_box(); }
| T_FLOW T_OTHERDATA { end_box(); }
| T_END { end_box(); }

%%

