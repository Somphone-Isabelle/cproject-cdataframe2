#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cdataframe.h"
#include "column.h"
#include "list.h"
#include "tools.h"

int cmd_test(Command* cmd) {
    cdf_log("cmd_test()");
    print_header("test : run default test");
    
    run_cdf_test();
    return 0;
}

int cmd_cdf_new(Command* cmd) {
    cdf_log("cmd_cdf_new()");
//    print_header("cmd_cdf_new");
    char *usage = "cdf_new INT CHAR STRING DOUBLE INT";
    ENUM_TYPE *cdftype = malloc(cmd->size * sizeof(ENUM_TYPE));
    for (int i = 0; i < cmd->size; i++) {
        char *param = cmd->params[i];
        printf("exec cdf_new with %s\n", param);
        if (strcmp(param, "INT") == 0) {
            cdftype[i] = INT;
        } else if (strcmp(param, "UINT") == 0) {
            cdftype[i] = UINT;
        } else if (strcmp(param, "DOUBLE") == 0) {
            cdftype[i] = DOUBLE;
        } else if (strcmp(param, "FLOAT") == 0) {
            cdftype[i] = FLOAT;
        } else if (strcmp(param, "CHAR") == 0) {
            cdftype[i] = CHAR;
        } else if (strcmp(param, "STRING") == 0) {
            cdftype[i] = STRING;
        } else {
            cmd_error("Error parametre incorrect !");
        }
    }
    CDF = create_cdataframe(cdftype, cmd->size);
    return 0;
}

int cmd_cdf_display(Command* cmd) {
    cdf_log("cmd_cdf_display()");
    print_header("cmd_cdf_display");

    cdf_print_line(CDF, 0);
//    display_cdf(CDF);

    return 0;
}

int cmd_cdf_delete(Command* cmd) {
    cdf_log("cmd_cdf_delete()");
    print_header("cmd_cdf_delete");

//    lst_delete_list
//    delete_cdataframe(*CDF);

    return 0;
}

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

int cmd_row_delete(Command* cmd) {
    cdf_log("cmd_row_delete()");
    print_header("cmd_row_delete");
    printf("TODO\n");
    return 0;
}

int cmd_row_display(Command* cmd) {
    cdf_log("cmd_row_display()");
    print_header("cmd_row_display");
    printf("TODO\n");
    return 0;
}

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

int cmd_col_delete(Command* cmd) {
    cdf_log("cmd_col_delete()");
    print_header("cmd_col_delete");
    printf("TODO\n");
    return 0;
}

int cmd_col_display(Command* cmd) {
    cdf_log("cmd_col_display()");
    print_header("cmd_col_display");
    char *usage = "cmd_col_display numero_colonne";

    printf("TODO\n");
    return 0;
}

int cmd_col_insert(Command* cmd) {
    cdf_log("cmd_col_insert()");
    print_header("cmd_col_insert");

    if (cmd != NULL && cmd->size == 2) {

    }
    return 0;
}

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

int cmd_col_edit(Command* cmd) {
    cdf_log("cmd_col_edit()");
    print_header("cmd_col_edit");
    char *usage = "col_edit colomn_id colomn_place value";
    cmd_error("Error edit colomn.\n usage : col_edit colomn_id colomn_place value");

    return 0;
}
int cmd_col_test(Command* cmd) {
    cdf_log("cmd_col_test()");
    print_header("cmd_col_test");
    printf("TODO\n");
    return 0;
}
int cmd_col_sort(Command* cmd) {
    cdf_log("cmd_col_sort()");
    print_header("cmd_col_sort");
    printf("TODO\n");
    return 0;
}
int cmd_col_list(Command* cmd) {
    cdf_log("cmd_col_list()");
    print_header("cmd_col_list");
 
        printf("TODO\n");
    return 0;
}
int cmd_csv_import(Command* cmd) {
    cdf_log("cmd_csv_import()");
    print_header("cmd_csv_import");
    printf("TODO\n");
    return 0;
}
int cmd_csv_export(Command* cmd) {
    cdf_log("cmd_csv_export()");
    print_header("cmd_csv_export");
    printf("TODO\n");
    return 0;
}
int cmd_search(Command* cmd) {
    cdf_log("cmd_search()");
    print_header("cmd_search");
    printf("TODO\n");
    return 0;
}