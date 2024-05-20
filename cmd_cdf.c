//Cdataframe project led by Isabelle and Ambre - Commands for the cdataframe - source file
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

//Command to initialize a new cdataframe
int cmd_cdf_new(Command* cmd) {
    cdf_log("cmd_cdf_new()");
    print_header("New cdf");

    CDF = create_expty_cdataframe();    
}

int cmd_cdf_init(Command* cmd) {
    cdf_log("cmd_cdf_int()");
    print_header("Init cdf");

    if (cmd != NULL && cmd->size > 0) {
            ENUM_TYPE *cdftype = malloc(cmd->size * sizeof(ENUM_TYPE));
            for (int i = 0; i < cmd->size; i++) {
                char *param = cmd->params[i];
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
    }
    else {
        char *usage = "cdf_new INT CHAR STRING DOUBLE INT";
        printf("ERROR : %s", usage);
    }
    return 0;
}

//Command to display the cdataframe
int cmd_cdf_display(Command* cmd) {
    cdf_log("cmd_cdf_display()");
    print_header("cmd_cdf_display");

    /* Display all lines */
    cdf_print_line(CDF, 0);
    return 0;
}

//Command to delete the cdataframe
int cmd_cdf_delete(Command* cmd) {
    cdf_log("cmd_cdf_delete()");
    print_header("cmd_cdf_delete");
    delete_cdataframe(CDF);
    return 0;
}

int cmd_cdf_colums(Command* cmd) {
    cdf_log("cmd_cdf_colums()");
    print_header("cmd_cdf_colums");

    display_cdf_titles(CDF);
    return 0;
}

int cmd_cdf_lines(Command* cmd) {
    cdf_log("cmd_cdf_lines()");
    print_header("cmd_cdf_lines");
    
    if (cmd != NULL) {
        printf("lines : %d", cdf_line_size(CDF));
    }    
    return 0;
}

int cmd_cdf_edit(Command* cmd) {
    cdf_log("cdf_edit()");
    print_header("cdf_edit");

    if (cmd != NULL && cmd->size == 3) {
        if (isInt(cmd->params[1]) && isInt(cmd->params[2])) {
            edit(CDF, cmd->params[0], atoi(cmd->params[1]), atoi(cmd->params[2]));
        } else cmd_error("Bad params, usage cdf_edt data posx posy");
    } else {
        return cmd_error("Bad params, usage cdf_edt data posx posy");
    }
    return 0;
}

int cmd_cdf_search(Command* cmd) {
    cdf_log("cdf_search()");
    print_header("cdf_search");

    if (cmd != NULL && cmd->size == 1) {
        cdf_search(CDF, cmd->params[0]);
    } else {
        return cmd_error("Bad params, usage cdf_edt data posx posy");
    }
    return 0;
}

int cmd_cdf_eq(Command* cmd) {
    cdf_log("cdf_eq()");
    print_header("cdf_eq");

    if (cmd != NULL && cmd->size == 1) {
        cdf_eq(CDF, cmd->params[0]);
    } else {
        return cmd_error("Bad params, usage cdf_edt data posx posy");
    }
    return 0;
}

int cmd_cdf_gt(Command* cmd) {
    cdf_log("cdf_gt()");
    print_header("cdf_gt");

    if (cmd != NULL && cmd->size == 1) {
        cdf_gt(CDF, cmd->params[0]);
    } else {
        return cmd_error("Bad params, usage cdf_edt data posx posy");
    }
    return 0;
}

int cmd_cdf_lt(Command* cmd) {
    cdf_log("cdf_lt()");
    print_header("cdf_lt");

    if (cmd != NULL && cmd->size == 1) {
        cdf_lt(CDF, cmd->params[0]);
    } else {
        return cmd_error("Bad params, usage cdf_edt data posx posy");
    }
    return 0;
}




