/* flip.cpp: Form Linear Program

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

typedef enum
{
    Unknown,
    Annotation,
    Circle,
    Finish,
    Null,
    Rectangle,
    Start,
    Test
} BOX_TYPE;

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
    BOX_TYPE type;
    int label_number;
    int is_branch_destination;
    int generated;
    int next_box_number;
    int true_branch_box_number; /* for the THEN part of a Test box */
    TABLE lines;
} BOX;

typedef struct
{
    int start_box_number;
    int finish_box_number;
    BOX boxes[MAX_BOX + 1]; /* box numbers are 1-based */
} CHART_TABLE_ENTRY;

static int enable_lex_trace = 0;
static int enable_yacc_trace = 0;
static char *label_format;
static char *goto_format;
static char *conditional_goto_format;
static char conditional_goto[80];
char *conditional_substitution;

static int in_selected_box = 0;
static CHART_TABLE_ENTRY *current_chart_table_entry;
static char *current_chart_name;
static TABLE *current_line_table;

static TABLE chart_table;

static int last_flow_box_number = -1;
static int last_label_number = -1;
static int flow_contains_test_box = 0;

static int check_box_number(int number);
static BOX *get_box(CHART_TABLE_ENTRY *chart_table_entry, int number);
static BOX *get_next_box(CHART_TABLE_ENTRY *chart_table_entry, BOX *box);
static BOX *get_next_true_branch_box(CHART_TABLE_ENTRY *chart_table_entry, BOX *box);
static int get_box_number(CHART_TABLE_ENTRY *chart_table_entry, BOX *box);
static int box_is_reachable(CHART_TABLE_ENTRY *chart_table_entry, BOX *from, BOX *to);
static void output_chart(char *name, void *value);
static void output_box_line(char *name, void *value);
static void output_box(CHART_TABLE_ENTRY *chart_table_entry, BOX *box);
static void output_box_sequence(CHART_TABLE_ENTRY *chart_table_entry, BOX *start_box, int is_root);
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
        if (check_box_number(number))
        {
            BOX *box = get_box(current_chart_table_entry, number);
            current_line_table = &box->lines;
            box->label_number = ++last_label_number;
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

void process_column_box_ref(int box_number, char *box_type_name)
{
    BOX_TYPE box_type = Unknown;

    if (strcmp(box_type_name, "A") == 0)
    {
        box_type = Annotation;
    }
    else if (strcmp(box_type_name, "C") == 0)
    {
        box_type = Circle;
    }
    else if (strcmp(box_type_name, "F") == 0)
    {
        box_type = Finish;
        current_chart_table_entry->finish_box_number = box_number;
    }
    else if (strcmp(box_type_name, "N") == 0)
    {
        box_type = Null;
    }
    else if (strcmp(box_type_name, "R") == 0)
    {
        box_type = Rectangle;
    }
    else if (strcmp(box_type_name, "S") == 0)
    {
        box_type = Start;
        current_chart_table_entry->start_box_number = box_number;
    }
    else if (strcmp(box_type_name, "T") == 0)
    {
        box_type = Test;
    }
    else
    {
        yyerror("Unknown box type %s\n", box_type);
    }

    yacc_trace("col %d %s(%d)\n", box_number, box_type_name, box_type);
    if (check_box_number(box_number))
    {
        current_chart_table_entry->boxes[box_number].type = box_type;
    }
}

void start_flow_sequence(void)
{
    last_flow_box_number = -1;
    flow_contains_test_box = 0;
}

void process_flow_box_ref(int box_number)
{
    if (check_box_number(box_number))
    {
        if (last_flow_box_number > 0)
        {
            BOX *box = get_box(current_chart_table_entry, last_flow_box_number);
            if (box->type == Test)
            {
                if (box->next_box_number <= 0)
                {
                    box->next_box_number = box_number;
                    flow_contains_test_box = 1;
                }
                else
                {
                    box->true_branch_box_number = box_number;
                    get_box(current_chart_table_entry, box_number)->is_branch_destination = 1;
                }
            }
            else
            {
                box->next_box_number = box_number;
                if (last_flow_box_number > 0 && box_number != last_flow_box_number + 1)
                {
                    get_box(current_chart_table_entry, box_number)->is_branch_destination = 1;
                }
            }
        }

        last_flow_box_number = box_number;
    }
}

void end_flow_sequence(void)
{
    if (flow_contains_test_box)
    {
        get_box(current_chart_table_entry, last_flow_box_number)->is_branch_destination = 1;
    }
}

static int check_box_number(int number)
{
    int result = number < MAX_BOX;
    if (!result)
    {
        yyerror("Box number %d greater than maximum allowed (%d) on chart %s\n", number, MAX_BOX, current_chart_name);
    }

    return result;
}

static BOX *get_box(CHART_TABLE_ENTRY *chart_table_entry, int number)
{
    BOX *result = NULL;
    if (number > 0)
    {
        result = &chart_table_entry->boxes[number];
    }

    return result;
}

static BOX *get_next_box(CHART_TABLE_ENTRY *chart_table_entry, BOX *box)
{
    BOX *next = NULL;
    if (box->next_box_number != 0)
    {
        next = get_box(chart_table_entry, box->next_box_number);
    }

    return next;
}

static BOX *get_next_true_branch_box(CHART_TABLE_ENTRY *chart_table_entry, BOX *box)
{
    BOX *next = NULL;
    if (box->next_box_number != 0)
    {
        next = get_box(chart_table_entry, box->true_branch_box_number);
    }

    return next;
}

static int get_box_number(CHART_TABLE_ENTRY *chart_table_entry, BOX *box)
{
    int result;
    if (box == NULL)
    {
        result = 0;
    }
    else
    {
        result = box - chart_table_entry->boxes;
    }

    return result;
}

static int box_is_reachable(CHART_TABLE_ENTRY *chart_table_entry, BOX *from, BOX *to)
{
    int reachable = 0;
    BOX *next = from;
    printf("Can reach %d from %d:", get_box_number(chart_table_entry, to), get_box_number(chart_table_entry, from));
    while (next != NULL && !reachable)
    {
        if (next == to)
        {
            reachable = 1;
        }
        else
        {
            next = get_next_box(chart_table_entry, next);
        }
    }

    if (reachable)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return reachable;
}

static void output_box(CHART_TABLE_ENTRY *chart_table_entry, BOX * box)
{
    if (box->is_branch_destination)
    {
        fprintf(output, label_format, box->label_number);
    }

    fprintf(output, "\n::::::::::::::::::BOX %d\n", get_box_number(chart_table_entry, box));
    printf("Outputting box %d, is test=%d\n", get_box_number(chart_table_entry, box), box->type == Test);
    strcpy(conditional_goto, "");
    if (box->type == Test)
    {
        sprintf(conditional_goto, conditional_goto_format, get_box(chart_table_entry, box->true_branch_box_number)->label_number);
    }
    conditional_substitution = NULL;

    process_table_entries(&box->lines, output_box_line);
    if (box->type == Test && conditional_substitution == NULL)
    {
        fprintf(output, " %s", conditional_goto);
    }

    if (box->type != Finish)
    {
        fprintf(output, "\n");
    }

    box->generated = 1;
}

/* stop if box is reachable from root box*/
static void output_box_sequence(CHART_TABLE_ENTRY *chart_table_entry, BOX *start_box, int is_root)
{
    /*
    Output linear sequence except for last box
    If there were any T boxes insert a goto for the last box (make sure flow ref adds label for it)
    Second pass to process other T branches, for each branch invoke this method recursively
    */
    BOX *box = start_box;
    BOX *last_box = start_box;
    int contains_test_box = 0;
    printf("Starting sequnce\n");
    while (box != NULL && box->type != Finish && !box->generated)
    {
        contains_test_box = contains_test_box || box->type == Test;
        output_box(chart_table_entry, box);
        last_box = box;
        box = get_next_box(chart_table_entry, box);
    }

    /* If the sequence contains Test boxes do a second pass to output the branched side of the test boxes */
    if (contains_test_box)
    {
        fprintf(output, goto_format, last_box->label_number); // goto the last box as we are now about to output the other side of a branch
        box = start_box;
        while (box != NULL && box->type != Finish)
        {
            printf("Checking true branch box %d, is test=%d\n", get_box_number(chart_table_entry, box), box->type == Test);
            if (box->type == Test)
            {
                output_box_sequence(chart_table_entry, get_next_true_branch_box(chart_table_entry, box), 0);
            }

            box = get_next_box(chart_table_entry, box);
        }
    }

    if (last_box->type == Finish || last_box->generated)
    {
        fprintf(output, goto_format, last_box->label_number);
    }
    printf("End sequnce\n");
}

static void output_chart(char *name, void *value)
{
    int i;
    CHART_TABLE_ENTRY *chart_table_entry = (CHART_TABLE_ENTRY *)value;
    printf("Generating chart %s\n", name);
    fprintf(output, "\n:::::::::::::::::: CHART %s\n", name);
    BOX *start_box = get_box(chart_table_entry, chart_table_entry->start_box_number);
    BOX *finish_box = get_box(chart_table_entry, chart_table_entry->finish_box_number);

    //output_box(chart_table_entry, start_box);
    //for ( i = 0; i < MAX_BOX; i++)
    //{
    //    BOX *box = get_box(chart_table_entry, i + 1);
    //    if (!box->generated && box->type != Null && box->type != Finish && box->type != Unknown)
    //    {
    //        output_box(chart_table_entry, box);
    //    }
    //}
    //output_box(chart_table_entry, finish_box);

    output_box_sequence(chart_table_entry, start_box, 1);
    output_box(chart_table_entry, finish_box);
}

static void output_box_line(char *name, void *value)
{
    LINE_TABLE_ENTRY *entry = (LINE_TABLE_ENTRY *)value;
    if (entry->line_type == CrossReference)
    {
        CHART_TABLE_ENTRY *chart_entry = (CHART_TABLE_ENTRY *)find_table_entry(&chart_table, entry->line);
        output_chart(entry->line, chart_entry);
        //fprintf(output, "\nXREF %s", entry->line);
    }
    else
    {
        conditional_substitution = strstr(entry->line, "@>>");
        if (conditional_substitution != NULL)
        {
            *conditional_substitution = '\0';
            fprintf(output, "\n%s", entry->line);
            fprintf(output, " %s", conditional_goto);
        }
        else
        {
            fprintf(output, "\n%s", entry->line);
        }
    }
}

static void output_code(void)
{
    output_chart(chart_table.head->name, chart_table.head->value);
    //process_table_entries(&chart_table, output_chart);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "usage: flip [infile] [outfile]\n");
    }
    else
    {
        label_format = "LB%05d:\n";
        goto_format = "-> LB%05d;\n";
        conditional_goto_format = ",-> LB%05d;";
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
