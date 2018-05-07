/* flip.cpp: Form Linear Program

Copyright (c) 2016-2018, Robert Jarratt

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

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include "flip.h"
#include "table.h"

#define MAX_BOX 50

FILE *output;

extern FILE *output;
extern FILE *yyin;
extern char *yytext;
extern int yylineno;
extern int yylex(void);
extern int yyparse(void);

typedef enum
{
    NormalLine,
    CrossReference
} LINE_TYPE;

typedef struct
{
    LINE_TYPE line_type;
    char *line;
} LINE_TABLE_ENTRY;

typedef struct
{
    TABLE line_table;
} BOX_TABLE_ENTRY;

typedef struct
{
    int used;
    TABLE lines;
} BOX;

typedef struct
{
    BOX boxes[MAX_BOX];
} CHART_TABLE_ENTRY;

static int enable_lex_trace = 0;
static int enable_yacc_trace = 1;

static int in_selected_box = 0;
static CHART_TABLE_ENTRY *current_chart_table_entry;
static char *current_chart_name;
static TABLE *current_line_table;

static TABLE chart_table;

static void output_chart(char *name, void *value);
static void output_box(char *name, void *value);
static void output_code(void);

void yyerror(const char *msg, ...)
{
    va_list ap;
    va_start(ap, msg);
    fprintf(stderr, "%d: ", yylineno);
    vfprintf(stderr, msg, ap);
    fprintf(stderr, " at '%s'\n", yytext);
    va_end(ap);
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

void start_chart(char *title)
{
    yacc_trace("New chart %s\n", title);

    current_chart_table_entry = (CHART_TABLE_ENTRY *)calloc(1, sizeof(CHART_TABLE_ENTRY));
    current_chart_name = title;
    add_table_entry(&chart_table, title, current_chart_table_entry);
}

void start_box(int number, int level)
{
    yacc_trace("New box %d.%d\n", number, level);
    in_selected_box = level == 1;
    if (in_selected_box)
    {
        if (number >= MAX_BOX)
        {
            yyerror("Too many boxes in chart %s\n", current_chart_name);
        }
        else
        {
            current_chart_table_entry->boxes[number].used = 1;
            current_line_table = &current_chart_table_entry->boxes[number].lines;
        }
    }
}

void end_box(void)
{
    yacc_trace("End box\n");
    in_selected_box = 0;
}

void process_line(char *line)
{
    LINE_TABLE_ENTRY *entry;
    if (in_selected_box)
    {
        entry = (LINE_TABLE_ENTRY *)malloc(sizeof(LINE_TABLE_ENTRY));
        entry->line_type = NormalLine;
        entry->line = line;
        add_table_entry(current_line_table, "", entry);
    }
}

void process_cross_ref(char *title)
{
    LINE_TABLE_ENTRY *entry;
    if (in_selected_box)
    {
        entry = (LINE_TABLE_ENTRY *)malloc(sizeof(LINE_TABLE_ENTRY));
        entry->line_type = CrossReference;
        entry->line = title;
        add_table_entry(current_line_table, "", entry);
    }
}

static void output_chart(char *name, void *value)
{
    int i;
    CHART_TABLE_ENTRY *chart_table_entry = (CHART_TABLE_ENTRY *)value;
    fprintf(output, ":::::::::::::::::: CHART %s\n", name);
    for (i = 0; i < MAX_BOX; i++)
    {
        BOX *box = &chart_table_entry->boxes[i];
        if (box->used)
        {
            fprintf(output, ":::::::::::::::::: BOX %d\n", i);
            process_table_entries(&box->lines, output_box);
        }
    }
}
static void output_box(char *name, void *value)
{
    LINE_TABLE_ENTRY *entry = (LINE_TABLE_ENTRY *)value;
    if (entry->line_type == CrossReference)
    {
        fprintf(output, "XREF %s\n", entry->line);
    }
    else
    {
        fprintf(output, "%s\n", entry->line);
    }
}

static void output_code(void)
{
    process_table_entries(&chart_table, output_chart);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "usage: flip [infile] [outfile]\n");
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
            do
            {
                yyparse();
            }
            while (!feof(yyin));

            output_code();

            fclose(output);
        }
    }
}
