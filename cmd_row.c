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
int cmd_row_add(Command* cmd) {
    cdf_log("cmd_row_new()");
    print_header("cmd_row_new");

    if (CDF != NULL && CDF->tail != NULL) {
        lnode *node = (lnode *)get_first_node(CDF);
        int i = 0;
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            insert_value2(col, cmd->params[i++]);
            node = (lnode *)get_next_node(CDF, node);
        }
    }
    return 0;
}

//Command to delete a row
int cmd_row_delete(Command* cmd) {
    cdf_log("cmd_row_delete()");
    print_header("cmd_row_delete");

    if (cmd != NULL && cmd->size == 1) {
        if (CDF != NULL && CDF->tail != NULL) {
            if (isInt(cmd->params[0])) {
                row_delete(CDF, atoi(cmd->params[0]));
            }
        } else {
            return cmd_error("CDF not init");
        }
    } else {
        return cmd_error("Bad param, usage : row_delete pos");
    }
    return 0;
}

//Command to display a row
int cmd_row_display(Command* cmd) {
    cdf_log("cmd_row_display()");
    print_header("cmd_row_display");

    if (cmd != NULL && cmd->size == 1) {
        if (CDF != NULL && CDF->tail != NULL) {
            if (isInt(cmd->params[0])) {
                cdf_print_line(CDF, atoi(cmd->params[0]));
            } else {
                return cmd_error("Error not int param");
            }
        } else {
            return cmd_error("CDF not init");
        }
    } else {
        return cmd_error("Bad param, usage : row_delete pos");
    }
    return 0;
}

