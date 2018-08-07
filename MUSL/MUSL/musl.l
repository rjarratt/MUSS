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

NAME             [A-Z][A-Z0-9\.]*
INTEGER          [0-9]+

%%

ADDR                         { return T_ADDR; }
AND                          { return T_AND; }
\$AD                         { return T_ADDR; }
BEGIN                        { return T_BEGIN; }
DATAVEC                      { return T_DATAVEC; }
DO                           { return T_DO; }
ELSE                         { return T_ELSE; }
\*END                        { return T_MODULEEND; }
END                          { return T_END; }
FI                           { return T_FI; }
FOR                          { return T_FOR; }
IF                           { return T_IF; }
IMPORT                       { return T_IMPORT; }
\$IM                         { return T_IMPORT; }
INTEGER                      { return T_INTEGER; }
INTEGER8                     { return T_INTEGER8; }
INTEGER16                    { return T_INTEGER16; }
INTEGER32                    { return T_INTEGER32; }
INTEGER64                    { return T_INTEGER64; }
$IN                          { return T_INTEGER; }
$IN8                         { return T_INTEGER8; }
$IN16                        { return T_INTEGER16; }
$IN32                        { return T_INTEGER32; }
$IN64                        { return T_INTEGER64; }
IS                           { return T_IS; }
LABEL                        { return T_LABEL; }
LOGICAL                      { return T_LOGICAL; }
LOGICAL8                     { return T_LOGICAL8; }
LOGICAL16                    { return T_LOGICAL16; }
LOGICAL32                    { return T_LOGICAL32; }
LOGICAL64                    { return T_LOGICAL64; }
$LO                          { return T_LOGICAL; }
$LO8                         { return T_LOGICAL8; }
$LO16                        { return T_LOGICAL16; }
$LO32                        { return T_LOGICAL32; }
$LO64                        { return T_LOGICAL64; }
LITERAL                      { return T_LITERAL; }
\$LI                         { return T_LITERAL; }
LSPEC                        { return T_LSPEC; }
\$LS                         { return T_LSPEC; }
MODULE                       { return T_MODULE; }
OD                           { return T_OD; }
OF                           { return T_OF; }
OR                           { return T_OR; }
PROC                         { return T_PROC; }
PSPEC                        { return T_PSPEC; }
\$PS                         { return T_PSPEC; }
REAL                         { return T_REAL; }
REAL32                       { return T_REAL32; }
REAL64                       { return T_REAL64; }
REAL128                      { return T_REAL128; }
$RE                          { return T_REAL; }
$RE32                        { return T_REAL32; }
$RE64                        { return T_REAL64; }
$RE128                       { return T_REAL128; }
THEN                         { return T_THEN; }
TYPE                         { return T_TYPE; }
WHILE                        { return T_WHILE; }
WITHIN                       { return T_WITHIN; }

;                            { return T_SEP; }
=                            { return T_EQUALS; }
\/=                          { return T_NOT_EQUALS; }
\<                           { return T_LT; }
\>                           { return T_GT; }
\=<                          { return T_LE; }
\>=                          { return T_GE; }
\,                           { return T_COMMA; }
\:                           { return T_COLON; }
\^                           { return T_CIRCUMFLEX; }
\(                           { return T_L_BRACK; }
\)                           { return T_R_BRACK; }
\[                           { return T_L_PAREN; }
\]                           { return T_R_PAREN; }
\+                           { return T_PLUS; }
\-                           { return T_MINUS; }
\*                           { return T_STAR; }
\/                           { return T_SLASH; }
\&                           { return T_AMPERSAND; }
\!                           { return T_EXCLAMATION; }
\-\=                         { return T_XOR; }
\-\:                         { return T_RSUB; }
\/\:                         { return T_RDIV; }
\+\>                         { return T_ADDSTORE; }
\*\>                         { return T_MULSTORE; }
\/\>                         { return T_DIVSTORE; }
\&\>                         { return T_ANDSTORE; }
\!\>                         { return T_ORSTORE; }
\-\=\>                       { return T_XORSTORE; }
\=\>                         { return T_ASSIGN; }
\-\:->                       { return T_RSUBSTORE; }
\/\:\>                       { return T_RDIVSTORE; }
\<\<\-                       { return T_LLSHIFT; }
\-\>\>                       { return T_RLSHIFT; }
\-\>                         { return T_GOTO_OR_SUBSTORE; }
\;                           { }

\".*\"                       { yylval.stringval = _strdup(yytext); return T_MULTI_CHAR_CONST; }
\%\".*\"                     { yylval.stringval = _strdup(&yytext[1]); return T_CH_STRING; }
\'\$L                        { yylval.charval = '\n'; return T_CHAR_CONST; }
\'\$P                        { yylval.charval = '\f'; return T_CHAR_CONST; }
\'\$N                        { yylval.charval = '\0'; return T_CHAR_CONST; }
\'\$\"                       { yylval.charval = '\"'; return T_CHAR_CONST; }
\'\$\$                       { yylval.charval = '$'; return T_CHAR_CONST; }
\'.                          { yylval.charval = yytext[1]; return T_CHAR_CONST; }
{NAME}                       { yylval.nameval = _strdup(yytext); return is_type(yytext) ? T_TYPE_NAME : T_NAME; }
{INTEGER}                    { yylval.unsignedval = atoi(yytext); return T_NUMBER;}

::.*\n                       { yylineno++; }
^\*.*\n                      { yylineno++; /* filter out directives for now */}
\n                           { yylineno++; }
. ;

%%
