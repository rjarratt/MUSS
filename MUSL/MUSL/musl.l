/* musl.l: MUSL cross-compiler Lex analyzer

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

%option noyywrap

%{
#include "musl.h"
#include "musl.tab.h"

%}

NAME             [A-Z][A-Z0-9\.\/]*
INTEGER          [0-9]+

%%

ADDR                         { return T_ADDR; }
\$AD                         { return T_ADDR; }
\*END                        { return T_END; }
IMPORT                       { return T_IMPORT; }
\$IM                         { return T_IMPORT; }
INTEGER                      { return T_INTEGER; }
$IN                          { return T_INTEGER; }
IS                           { return T_IS; }
LABEL                        { return T_LABEL; }
LOGICAL                      { return T_LOGICAL; }
LITERAL                      { return T_LITERAL; }
\$LI                         { return T_LITERAL; }
\$LO                         { return T_LOGICAL; }
LSPEC                        { return T_LSPEC; }
\$LS                         { return T_LSPEC; }
MODULE                       { return T_MODULE; }
OR                           { return T_OR; }
PSPEC                        { return T_PSPEC; }
\$PS                         { return T_PSPEC; }
REAL                         { return T_REAL; }
TYPE                         { return T_TYPE; }
WITHIN                       { return T_WITHIN; }

=                            { return T_EQUALS; }
\,                           { return T_COMMA; }
\(                           { return T_L_BRACK; }
\)                           { return T_R_BRACK; }
\[                           { return T_L_PAREN; }
\]                           { return T_R_PAREN; }
\/                           { return T_SLASH; }
\;                           { }

{NAME}                       { yylval.nameval = _strdup(yytext); return T_NAME;}
{INTEGER}                    { yylval.unsignedval = atoi(yytext); return T_NUMBER;}

::.*\n                       { yylineno++; }
\n                           { yylineno++; }
. ;

%%
