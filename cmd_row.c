//Cdataframe project led by Isabelle and Ambre - Commands for the rows of the cdataframe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "cdataframe.h"
#include "column.h"
#include "list.h"
#include "tools.h"
#include "cmd.h"
#include "cmd_cdf.h"
#include "cmd_col.h"
#include "cmd_row.h"

//Command to insert a row
int cmd_row_insert(Command* cmd) {
    cdf_log("cmd_row_new()");
    print_header("cmd_row_new");

    if (CDF != NULL) {
        lnode *node = (lnode *)get_first_node(CDF);
        int i = 0;
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            insert_value(col, cmd->params[i++]);
            node = (lnode *)get_next_node(CDF, node);
        }
    }

    return 0;
}

//Command to delete a row
int cmd_row_delete(Command* cmd) {
    cdf_log("cmd_row_delete()");
    print_header("cmd_row_delete");
    printf("TODO\n");
    return 0;
}

//Command to display a row
int cmd_row_display(Command* cmd) {
    cdf_log("cmd_row_display()");
    print_header("cmd_row_display");
    printf("TODO\n");
    return 0;
}

