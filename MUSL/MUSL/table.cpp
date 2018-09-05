/* table.cpp: Simple table structure

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

This module contains a very naive table mechanism. It is not efficient and
does not scale well. It also assumes that the names and values to be stored
have already been allocated.

*/

#include <stdlib.h>
#include <string.h>
#include "table.h"

TABLE *new_child_table(TABLE *parent)
{
    TABLE *child = (TABLE *)malloc(sizeof(TABLE));
    child->parent = parent;
    child->head = NULL;
    child->tail = NULL;
    return child;
}

TABLE *pop_child_table(TABLE *table)
{
    return table->parent;
}

void add_table_entry(TABLE *table, char *name, void *value)
{
    TABLE_ENTRY *entry = (TABLE_ENTRY *)malloc(sizeof(TABLE_ENTRY));
    entry->next = NULL;
    entry->name = name;
    entry->value = value;

    if (table->head == NULL)
    {
        table->head = entry;
        table->tail = entry;
    }
    else
    {
        table->tail->next = entry;
        table->tail = entry;
    }
}

void *find_table_entry(TABLE *table, char *name)
{
    void *result = NULL;
    TABLE_ENTRY *entry = table->head;
    while (entry != NULL)
    {
        if (strcmp(name, entry->name) == 0)
        {
            result = entry->value;
            break;
        }
        entry = entry->next;
    }

    if (result == NULL && table->parent != NULL)
    {
        result = find_table_entry(table->parent, name);
    }

    return result;
}

void process_table_entries(TABLE *table, void(*process)(char *name, void *value))
{
    TABLE_ENTRY *entry = table->head;
    while (entry != NULL)
    {
        process(entry->name, entry->value);
        entry = entry->next;
    }
}
