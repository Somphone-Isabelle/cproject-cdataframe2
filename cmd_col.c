//Cdataframe project led by Isabelle and Ambre - Commands for the columns of the cdataframe - source file
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "cdataframe.h"
#include "column.h"
#include "list.h"
#include "tools.h"
#include "cmd.h"
#include "cmd_cdf.h"
#include "cmd_col.h"
#include "cmd_row.h"
 
 //Command to initialize a new column
int cmd_col_add(Command* cmd) {
    cdf_log("cmd_col_add()");
    print_header("cmd_col_add");

    if (cmd->size != 2) {
        return cmd_error("Error incorrect parameter !");
    }

    if (CDF != NULL && CDF->tail != NULL) {
        char *title = cmd->params[1];
        char *param = cmd->params[0];
        
        ENUM_TYPE type = string_to_enumtype(param);
        if (type == NULLVAL) {
            return cmd_error("Error incorrect parameter !");
        }
        COLUMN *col = create_column(type, title);
        for (int i = 0; i < cdf_line_size(CDF); i++) {
            insert_value2(col, " ");
        }
        if (col != NULL) {
            lnode *node = lst_create_lnode(col);
            if (node != NULL) {
                if (CDF->head == NULL) {
                    lst_insert_head(CDF, node);
                }
                lst_insert_tail(CDF, node);
            }
        }        
    } else {
        return cmd_error("Please init CDF"); 
    }
    return 0;
}

//Command to delete a column
int cmd_col_delete(Command* cmd) {
    cdf_log("cmd_col_delete()");
    print_header("cmd_col_delete");

    if (cmd != NULL && cmd->size == 1) {
        delete_column(CDF, cmd->params[0]);
    } else {
        return cmd_error("Error bad params. Usage : col_delete COL_NAME");
    }
    return 0;
}

int cmd_col_delete_by_int(Command* cmd) {
    cdf_log("cmd_col_delete()");
    print_header("cmd_col_delete");

    if (cmd != NULL && cmd->size == 1) {
        if (isInt(cmd->params[0])) {
            delete_column2(CDF, atoi(cmd->params[0]));
        } else {
            return cmd_error("Error not int");
        }
    } else {
        return cmd_error("Error bad params. Usage : col_delete COL_NAME");
    }
    return 0;
}

//Command to display columns
int cmd_col_display(Command* cmd) {
    cdf_log("cmd_col_display()");
    print_header("cmd_col_display");
    char *usage = "cmd_col_display numero_colonne";

    if (cmd != NULL && cmd->size == 1) {
        if (isInt(cmd->params[0])) {
            int i = atoi(cmd->params[0]);
            if (i == 1) {
                lnode *node = (lnode *)get_first_node(CDF);
                if (node != NULL) {
                    COLUMN *col = (COLUMN *)node->data;
                    print_col(col);
                }
            } else {
                int pos = 1;
                lnode *node = (lnode *)get_first_node(CDF);
                while (node != NULL) {
                    COLUMN *col = (COLUMN *)node->data;
                    if (i == pos) {
                        print_col(col);
                        return 0;
                    }        
                    node = (lnode *)get_next_node(CDF, node);
                    pos++;
                }
            }
        } else {
            return cmd_error("Bad number param");
        }
    } else {
        return cmd_error("Bad param");
    }
    return 0;
}

//Command to define a title for a specific column
int cmd_col_title(Command* cmd) {
    cdf_log("cmd_col_title()");
    print_header("cmd_col_title");
    char *usage = "col_title col_pos title";

    if (cmd != NULL && cmd->size == 2) {
        int x;
        sscanf(cmd->params[0], "%d", &x);
        cdf_col_title(CDF, x, cmd->params[1]);
    } else {
        printf("ERROR : %s", usage);
    }
    return 0;
}

//Command to edit a column
int cmd_col_edit(Command* cmd) {
    cdf_log("cmd_col_edit()");
    print_header("cmd_col_edit");
    char *usage = "col_edit colomn_id colomn_place value";
    cmd_error("Error edit colomn.\n usage : col_edit colomn_id colomn_place value");

    return 0;
}

//Command to sort the columns of the cdataframe
int cmd_col_sort(Command* cmd) {
    cdf_log("cmd_col_sort()");
    print_header("cmd_col_sort");
    printf("TODO\n");
    return 0;
}

//Command to list the columns
int cmd_col_list(Command* cmd) {
    cdf_log("cmd_col_list()");
    print_header("cmd_col_list");
 
    printf("TODO\n");
    return 0;
}