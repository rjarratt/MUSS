/* musl.cpp: Manchester University System Implementation Language

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

FLIP is Form LInear Program and takes a Flocoder file and outputs a linear
program. This program is used to bootstrap the process of generating Flip
from the original MUSL code.

*/

// TODO:Check task 3, do includes

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "table.h"
#include "musl.h"

FILE *output;

extern FILE *output;
extern FILE *yyin;
extern char *yytext;
extern int yylineno;
extern int yylex(void);
extern int yyparse(void);
extern int yydebug;

typedef enum
{
    SymbolVariable,
    SymbolPSpec
} SYMBOL_TYPE;

typedef struct
{
    SYMBOL_TYPE symbol_type;
} SYMBOL;

TABLE type_table;
TABLE root_symbol_table;
TABLE *current_symbol_table = &root_symbol_table;

static int enable_lex_trace = 0;
static int enable_yacc_trace = 0;
static char *label_format;
static char *goto_format;

void yyerror(const char *msg, ...)
{
    va_list ap;
    va_start(ap, msg);
    fprintf(stderr, "%d: ", yylineno);
    vfprintf(stderr, msg, ap);
    fprintf(stderr, " at '%s'\n", yytext);
    va_end(ap);
    exit(0);
}

void lex_trace(const char *msg, ...)
{
    va_list ap;
    va_start(ap, msg);
    if (enable_lex_trace)
    {
        vprintf(msg, ap);
    }
    va_end(ap);
}

void yacc_trace(const char *msg, ...)
{
    va_list ap;
    va_start(ap, msg);
    if (enable_yacc_trace)
    {
        vprintf(msg, ap);
    }
    va_end(ap);
}

void remove_periods(char *name)
{
    char *ptr = name;
    char *next = name;
    int done = 0;
    do
    {
        done = *next == '\0';
        if (*next == '.')
        {
            next++;
        }
        else
        {
            *ptr++ = *next++;
        }
    } while (!done);
}

void new_type(char *name)
{
    //printf("new_type %s\n", name);
    add_table_entry(&type_table, name, name);
}

int is_type(char *name)
{
    void *entry = find_table_entry(&type_table, name);
    //printf("is_type %s=%d\n", name, entry != NULL);
    return entry != NULL;
}

void new_var(char *name)
{
    //printf("new_var %s\n", name);
    SYMBOL *symbol = (SYMBOL *)malloc(sizeof(SYMBOL));
    symbol->symbol_type = SymbolVariable;
    add_table_entry(current_symbol_table, name, symbol);
}

void new_pspec(char *name)
{
    //printf("new_pspec %s\n", name);
    SYMBOL *symbol = (SYMBOL *)malloc(sizeof(SYMBOL));
    symbol->symbol_type = SymbolPSpec;
    add_table_entry(current_symbol_table, name, symbol);
}

int is_pspec(char *name)
{
    SYMBOL *entry = (SYMBOL *)find_table_entry(current_symbol_table, name);
    //printf("is_pspec %s=%d\n", name, entry != NULL);
    return entry != NULL && entry->symbol_type == SymbolPSpec;
}

void push_symbol(void)
{
    printf("Symbol push\n");
    current_symbol_table = new_child_table(current_symbol_table);
}

void pop_symbol(void)
{
    printf("Symbol pop\n");
    current_symbol_table = pop_child_table(current_symbol_table);
}

void add_builtin_functions()
{
    new_pspec("MAKE");
    new_pspec("PART");
    new_pspec("SIZE");
    new_pspec("POSN");
    new_pspec("BYTE");
    new_pspec("LLST");
    new_pspec("LPST");
    new_pspec("LENT");
}

int main(int argc, char *argv[])
{
    yydebug = 0;
    if (argc != 3)
    {
        fprintf(stderr, "usage: musl [infile] [outfile]\n");
    }
    else
    {
        yyin = fopen(argv[1], "r");
        if (yyin == NULL)
        {
            fprintf(stderr, "cannot open %s\n", argv[1]);
        }

        output = fopen(argv[2], "w");
        if (output == NULL)
        {
            fprintf(stderr, "cannot open %s\n", argv[2]);
        }

        if (yyin != NULL && output != NULL)
        {
            yylineno = 1;
            add_builtin_functions();
            do
            {
                yyparse();
            } while (!feof(yyin));

            fclose(output);
        }
    }
}
