/* flocoder.l: Flocoder cross-compiler Lex analyzer

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
#include "flip.h"
#include "flocoder.tab.h"

%}

%x DIRECTIVE_TITLE
%x DIRECTIVE_CROSS_REF
%s DIRECTIVE_BOX
%s DIRECTIVE_BOX_REFS
%x DIRECTIVE_IGNORE

START_DIRECTIVE  ^\f?@
NAME             [A-Z][A-Z0-9\.\/]*
LABEL            [A-Z][^\-\n]*
INTEGER          [0-9]+

%%

{START_DIRECTIVE}X                       { BEGIN DIRECTIVE_IGNORE; lex_trace("x"); return T_X; }
{START_DIRECTIVE}TITLE                   { BEGIN DIRECTIVE_TITLE; lex_trace("title"); return T_TITLE; }
{START_DIRECTIVE}BOX                     { BEGIN DIRECTIVE_BOX; lex_trace("box"); return T_BOX; }
{START_DIRECTIVE}ROW                     { BEGIN DIRECTIVE_IGNORE; lex_trace("row"); return T_ROW; }
{START_DIRECTIVE}COL                     { BEGIN DIRECTIVE_BOX_REFS; lex_trace("col"); return T_COL; }
{START_DIRECTIVE}FLOW                    { BEGIN DIRECTIVE_BOX_REFS; lex_trace("flow"); return T_FLOW; }
{START_DIRECTIVE}END                     { BEGIN INITIAL; lex_trace("end\n"); return T_END; }
{START_DIRECTIVE}[^ \t\n]*               { yyerror("Unexpected directive \'%s\'\n", yytext); }
<DIRECTIVE_TITLE>{NAME}                  { BEGIN DIRECTIVE_IGNORE; yylval.nameval = _strdup(yytext); lex_trace(" name \"%s\"", yytext); return T_NAME;}
<DIRECTIVE_TITLE>[ ]*                    { ; }
<DIRECTIVE_CROSS_REF>{NAME}              { BEGIN INITIAL; yylval.nameval = _strdup(yytext); lex_trace(" name \"%s\"", yytext); return T_NAME;}
<DIRECTIVE_BOX>{INTEGER}                 { yylval.unsignedval = atoi(yytext); lex_trace(" %s(%d)", yytext, yylval.unsignedval); return T_INTEGER;}
<DIRECTIVE_BOX>[ ]*                      { ; }
<DIRECTIVE_BOX>\.                        { lex_trace(" ."); return T_PERIOD;}
<DIRECTIVE_BOX_REFS>[ ]                  { ; }
<DIRECTIVE_BOX_REFS>{INTEGER}            { yylval.unsignedval = atoi(yytext); lex_trace(" %s", yytext); return T_INTEGER;}
<DIRECTIVE_BOX_REFS>\-                   { lex_trace(" ."); return T_HYPHEN;}
<DIRECTIVE_BOX_REFS>{LABEL}              { yylval.nameval = _strdup(yytext); lex_trace(" label %s", yytext); return T_LABEL;}
<DIRECTIVE_IGNORE>[^\n]*                 { BEGIN INITIAL; lex_trace(" value %s\n", yytext); return T_OTHERDATA;}
^[^@\f\n\#][^\n]*                        { BEGIN INITIAL; yylval.lineval = _strdup(yytext); lex_trace("%d: %s\n", yylineno, yytext); return T_LINE;}
^\#                                      { BEGIN DIRECTIVE_CROSS_REF; return T_HASH;}
^\n                                      { BEGIN INITIAL; yylineno++; }
\n                                       { BEGIN INITIAL; yylineno++; }
\f                                       { BEGIN INITIAL; }

%%
