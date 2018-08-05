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

#define MAX_BOX 64

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
    int box_no;
    int label_number;
    int lab_count;
    int is_branch_destination;
    int generated;
    int inflow;
    int next_col_box_number;
    int next_pflow_box_number;
    int next_sflow_box_number; /* for the THEN part of a Test box */
    TABLE lines;
} BOX;

typedef struct
{
    BOX *box;
    int jump_info;
} CODE_LIST_ENTRY;

typedef struct
{
    int start_box_number;
    int finish_box_number;
    BOX boxes[MAX_BOX + 1]; /* box numbers are 1-based */
    CODE_LIST_ENTRY code_list[MAX_BOX];
    int code_list_count = 0;

} CHART_TABLE_ENTRY;

static int enable_lex_trace = 0;
static int enable_yacc_trace = 0;
static char *label_format;
static char *goto_format;
static char *conditional_goto_format;
static char conditional_goto[80];
static int conditional_already_substituted;

static int in_selected_box = 0;
static CHART_TABLE_ENTRY *current_chart_table_entry;
static char *current_chart_name;
static TABLE *current_line_table;

static TABLE chart_table;

static int last_box_number = -1;
static int last_label_number = -1;
static int flow_contains_test_box = 0;

static int check_box_number(int number);
static BOX *get_box(CHART_TABLE_ENTRY *chart_table_entry, int number);
static BOX *get_next_box(CHART_TABLE_ENTRY *chart_table_entry, BOX *box);
static BOX *get_next_true_branch_box(CHART_TABLE_ENTRY *chart_table_entry, BOX *box);
static int get_box_number(CHART_TABLE_ENTRY *chart_table_entry, BOX *box);
static void print_chart_structure(CHART_TABLE_ENTRY *chart_table_entry);
static void output_box_line(char *name, void *value);
static void output_box(CHART_TABLE_ENTRY *chart_table_entry, BOX *box);
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
    for (int i = 0; i < MAX_BOX; i++)
    {
        current_chart_table_entry->boxes[i].box_no = i;
    }
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
        if (line[0] == '#')
        {
            entry->line_type = CrossReference;
            entry->line = &line[1];
        }
        else
        {
            entry->line_type = NormalLine;
            entry->line = line;
        }
        add_table_entry(current_line_table, "", entry);
    }
}

void start_column_sequence(void)
{
    last_box_number = -1;
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
        if (last_box_number > 0)
        {
            current_chart_table_entry->boxes[last_box_number].next_col_box_number = box_number;
        }

        current_chart_table_entry->boxes[box_number].type = box_type;
    }
}

void start_flow_sequence(void)
{
    last_box_number = -1;
    flow_contains_test_box = 0;
}

void process_flow_box_ref(int box_number)
{
    if (check_box_number(box_number))
    {
        if (last_box_number > 0)
        {
            BOX *prev_box = get_box(current_chart_table_entry, last_box_number);
            /* Box 7 */
            if (prev_box->next_pflow_box_number != box_number)
            {
                if (prev_box->next_pflow_box_number == 0)
                {
                    prev_box->next_pflow_box_number = box_number;
                }
                else
                {
                    flow_contains_test_box = 1;
                    if (prev_box->type == Test)
                    {
                        if (prev_box->next_col_box_number == box_number)
                        {
                            /* Box 10 */
                            prev_box->next_sflow_box_number = prev_box->next_pflow_box_number;
                            get_box(current_chart_table_entry, prev_box->next_sflow_box_number)->inflow--;
                        }
                        else
                        {
                            /* Box 14 */
                            prev_box->next_sflow_box_number = box_number;
                            goto Box12;
                        }
                    }
                    else
                    {
                        yyerror("too many flows");
                    }

                    /* Box 11 */
                    prev_box->next_pflow_box_number = box_number;
                    get_box(current_chart_table_entry, box_number)->inflow++;
                }
            }
        }

    Box12:
        /* Box 12 */
        last_box_number = box_number;
    }
}

void end_flow_sequence(void)
{
    if (flow_contains_test_box)
    {
        get_box(current_chart_table_entry, last_box_number)->is_branch_destination = 1;
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
    if (box->next_pflow_box_number != 0)
    {
        next = get_box(chart_table_entry, box->next_pflow_box_number);
    }

    return next;
}

static BOX *get_next_true_branch_box(CHART_TABLE_ENTRY *chart_table_entry, BOX *box)
{
    BOX *next = NULL;
    if (box->next_pflow_box_number != 0)
    {
        next = get_box(chart_table_entry, box->next_sflow_box_number);
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
        result = (int)(box - chart_table_entry->boxes);
    }

    return result;
}

static void output_box(CHART_TABLE_ENTRY *chart_table_entry, BOX * box)
{
    //fprintf(output, "\n::::::::::::::::::BOX %d\n", get_box_number(chart_table_entry, box));

    strcpy(conditional_goto, "");
    if (box->type == Test)
    {
        sprintf(conditional_goto, conditional_goto_format, get_box(chart_table_entry, box->next_sflow_box_number)->label_number);
    }
    conditional_already_substituted = 0;

    process_table_entries(&box->lines, output_box_line);
    if (box->type == Test && !conditional_already_substituted)
    {
        fprintf(output, " %s", conditional_goto);
    }
}

static void print_chart_structure(CHART_TABLE_ENTRY *chart_table_entry)
{
    int i;
    char *types[] = { "Unknwn", "Annotn", "Circle", "Finish", "Null", "Rect", "Start", "Test" };
    for ( i = 0; i < MAX_BOX; i++)
    {
        BOX *box = get_box(chart_table_entry, i + 1);
        if (box->type != Unknown)
        {
            printf("%2d %6s Pri: %2d Sec: %2d Inflow: %2d\n", i + 1, types[box->type], box->next_pflow_box_number, box->next_sflow_box_number, box->inflow);
        }
    }
}

static void plant_box(CHART_TABLE_ENTRY *chart_table_entry, BOX *box, BOX **finish_box)
{
    BOX *secondary_box;
    /* Box 13 */
    box->inflow = 1;

    /* Box 14 */
    if (box->type != Null && box->type != Annotation)
    {
        /* Box 2 */
        if (box->generated) goto Box10;

        /* Box 3 */
        box->generated = 1;

        /* Box 4 */
        if (box->type == Finish) goto Box5;

        /* Box 6 */
        chart_table_entry->code_list[chart_table_entry->code_list_count].box = box;
        chart_table_entry->code_list[chart_table_entry->code_list_count].jump_info = 0;
        chart_table_entry->code_list_count++;

        /* Box 7 */
        secondary_box = get_box(chart_table_entry, box->next_sflow_box_number);
        if (secondary_box != NULL)
        {
            /* Box 8 */

            while (secondary_box->type == Unknown || secondary_box->type == Null || secondary_box->type == Annotation)
            {
                secondary_box = get_box(chart_table_entry, secondary_box->next_pflow_box_number);
            }

            chart_table_entry->code_list[chart_table_entry->code_list_count].box = secondary_box;
            chart_table_entry->code_list[chart_table_entry->code_list_count].jump_info = 2;
            chart_table_entry->code_list_count++;
            secondary_box->lab_count++;

            //WHILE T OF BOXTAB[SJ] < 3 DO
            //    PFLOW.LINK OF BOXTAB[SJ] = > SJ;
            //OD
            //    SJ = > BNO OF CODELIST[CLPTR];
            //2 = > JMP.INFO OF CODELIST[CLPTR];
            //1 + > CLPTR;
            //1 + > LAB.COUNT OF BOXTAB[SJ];


        }

        goto Box12;

    Box5:
        /* Box 5 */
        *finish_box = box;

    Box10:
        /* Box 10 */
        box->next_pflow_box_number = 0;
        box->lab_count++;

        /* Box 11 */
        chart_table_entry->code_list[chart_table_entry->code_list_count].box = box;
        chart_table_entry->code_list[chart_table_entry->code_list_count].jump_info = 1;
        chart_table_entry->code_list_count++;

    Box12:;
    }
}

static void order_boxes(char *name, void *value)
{
    CHART_TABLE_ENTRY *chart_table_entry = (CHART_TABLE_ENTRY *)value;
    BOX *finish_box = NULL;
    int k = 1;
    BOX *current_box = get_box(chart_table_entry, chart_table_entry->start_box_number);

    chart_table_entry->code_list_count = 0;

Box4:
    
    plant_box(chart_table_entry, current_box, &finish_box);

    /* Box 5 */
    current_box = get_box(chart_table_entry, current_box->next_pflow_box_number);
    if (current_box != NULL) goto Box4;

Box17:
    /* Box 17 */
    current_box = get_box(chart_table_entry, k);

    /* Box 6 */
    if (current_box->type != Unknown && current_box->inflow == 0) goto Box4;

Box7:
    /* Box 7 */
    current_box = get_box(chart_table_entry, current_box->next_pflow_box_number);
    if (current_box == NULL) goto Box16;

    /* Box 8 */
    if (get_box_number(chart_table_entry, current_box) > k) goto Box7;

    /* Box 9 */
    if (current_box->type == Null || current_box->type == Annotation || current_box->type == Unknown || current_box->generated) goto Box7;
    goto Box4;

Box16:
    k++;

    /* Box 11 */
    if (k < MAX_BOX) goto Box17;

    /* Box 12 */
    if (finish_box != NULL)
    {
        chart_table_entry->code_list[chart_table_entry->code_list_count].box = finish_box;
        chart_table_entry->code_list[chart_table_entry->code_list_count].jump_info = 0;
        chart_table_entry->code_list_count++;
    }
}

static void generate_chart_text(char *name, void *value)
{
    CHART_TABLE_ENTRY *chart_table_entry = (CHART_TABLE_ENTRY *)value;
    int clptr;
    BOX *next_box;
    int next_jump_info;
    int jmpsw;

    /* Box 2 */
    order_boxes(name, value);

    /* Box 3 */
    clptr = 0;

Box4:
    /* Box 4 */

    next_box = chart_table_entry->code_list[clptr].box;
    next_jump_info = chart_table_entry->code_list[clptr].jump_info;
    clptr++;

    /* Box 6 */
    if (next_jump_info >= 1) goto Box11;

    /* Box 5 */
    if (clptr > chart_table_entry->code_list_count) goto Box16;

    /* Box 7 */

    /* Box 8 */
    if (next_box->lab_count != 0)
    {
        /* Box 9 */
        fprintf(output, "\n");
        fprintf(output, label_format, next_box->label_number);
        //BNO OF NEXT.EL = >LABLIST[1 + >LABPTR];
        //COPYSTR(LABL, TDIND, BNO OF NEXT.EL);
        //NEWLINES(1);
    }

    /* Box 22 */
    jmpsw = chart_table_entry->code_list[clptr].jump_info > 1;

    /* Box 10 */
    output_box(chart_table_entry, next_box);
    //IF TEXTPTR OF BOXTAB[BNO OF NEXT.EL] = > I /= 0 THEN
    //    CLPTR = >T1;
    //WHILE BTB[I] /= EOBWC DO
    //    IF BTB[I] = '@ AND JMPSW = 1 AND BTB[I+1]='>
    //    AND BTB[I + 2] = '> THEN
    //    BNO OF CODELIST[CLPTR] = > BNO OF NEXT.EL;
    //CLPTR + 1 = > T1;
    //COPYSTR(RELJUMP, TDIND, BNO OF NEXT.EL);
    //4 + >I;
    //ELSE
    //    OUTCH(BTB[I]);
    //1 + > I;
    //FI
    //    OD
    //    T1 = > CLPTR;
    //FI
    goto Box4;

Box11:
    /* Box 11 */
    if (next_jump_info == 1) goto Box13;

    /* Box 12 */
    fprintf(output, conditional_goto_format, next_box->label_number);
    //SET.O.POS(O.POS() - 1);
    //COPYSTR(RELJUMP, TDIND, BNO OF NEXT.EL);
    //NEWLINES(1);
    goto Box4;

Box13:
    /* Box 13 */
    if (next_box != chart_table_entry->code_list[clptr].box) goto Box15;

    /* Box 14 */
    chart_table_entry->code_list[clptr].box->lab_count--;
    goto Box4;

Box15:
    /* Box 15 */
    fprintf(output, "\n");
    fprintf(output, goto_format, next_box->label_number);
    // COPYSTR(JUMP,TDIND,BNO OF NEXTEL);
    goto Box4;

Box16:
    /* Box 16 */
    ;
    //64 = > LABLIST[1 + >LABPTR];
    //OUTCH(EOCWC);
    //SELECT.OUTPUT(OLD.OUT);


}

static void output_box_line(char *name, void *value)
{
    char *conditional_substitution = NULL;

    LINE_TABLE_ENTRY *entry = (LINE_TABLE_ENTRY *)value;
    if (entry->line_type == CrossReference)
    {
        CHART_TABLE_ENTRY *chart_entry = (CHART_TABLE_ENTRY *)find_table_entry(&chart_table, entry->line);
        if (chart_entry == NULL)
        {
            fprintf(stderr, "Chart cross reference not found: %s\n", entry->line);
        }

//        fprintf(output, "\n***************XREF %s", entry->line);
        generate_chart_text(entry->line, chart_entry);
    }
    else
    {
        if (!conditional_already_substituted)
        {
            conditional_substitution = strstr(entry->line, "@>>");
        }

        if (conditional_substitution != NULL)
        {
            *conditional_substitution = '\0';
            fprintf(output, "\n%s", entry->line);
            fprintf(output, " %s", conditional_goto);
            conditional_already_substituted = 1;
        }
        else
        {
            fprintf(output, "\n%s", entry->line);
        }
    }
}

static void output_code(void)
{
    generate_chart_text(chart_table.head->name, chart_table.head->value);
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
