//Cdataframe project led by Isabelle and Ambre - Commands for the columns of the cdataframe
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
int cmd_col_new(Command* cmd) {
    cdf_log("cmd_col_new()");
    print_header("cmd_col_new");

    if (cmd->size != 2) {
        return cmd_error("Error parametre incorrect !");
    }
    char *title = cmd->params[1];
    char *param = cmd->params[0];
    ENUM_TYPE type = string_to_enumtype(param);
    if (type == NULLVAL) {
        return cmd_error("Error parametre incorrect !");
    }
    COLUMN *col = create_column(type, title);
    for (int i = 0; i < cdf_line_size(CDF); i++) {
        insert_value(col, NULL);
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
    return 0;
}

//Command to delete a column
int cmd_col_delete(Command* cmd) {
    cdf_log("cmd_col_delete()");
    print_header("cmd_col_delete");
    printf("TODO\n");
    return 0;
}

//Command to display columns
int cmd_col_display(Command* cmd) {
    cdf_log("cmd_col_display()");
    print_header("cmd_col_display");
    char *usage = "cmd_col_display numero_colonne";

    printf("TODO\n");
    return 0;
}

//Command to insert a column in the cdataframe
int cmd_col_insert(Command* cmd) {
    cdf_log("cmd_col_insert()");
    print_header("cmd_col_insert");

    if (cmd != NULL && cmd->size == 2) {

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

//Command to test the columns
int cmd_col_test(Command* cmd) {
    cdf_log("cmd_col_test()");
    print_header("cmd_col_test");
    printf("TODO\n");
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