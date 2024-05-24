//Cdataframe project led by Isabelle and Ambre - Commands functions for the cdataframe - source file
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

CDATAFRAME   *CDF;

//Command to run a test 
int cmd_test(Command* cmd) {
    cdf_log("cmd_test()");
    print_header("test : run default test");
    
    run_cdf_test();
    return 0;
}

//command to import data from a csv format
int cmd_csv_import(Command* cmd) {
    cdf_log("cmd_csv_import()");
    print_header("cmd_csv_import");

    if (cmd != NULL && cmd->size == 1) {
        csv_to_cdataframe(CDF, cmd->params[0]);
    } else {
        return cmd_error("Error bad params. Usage : csv_import COL_NAME");
    }
    return 0;
}

//Command to export data into a csv format
int cmd_csv_export(Command* cmd) {
    cdf_log("cmd_csv_export()");
    print_header("cmd_csv_export");

    if (cmd != NULL && cmd->size == 1) {
        csv_from_cdataframe(CDF, cmd->params[0]);
    } else {
        return cmd_error("Error bad params. Usage : csv_import COL_NAME");
    }
    return 0;
}

//Command to search a certain value 
int cmd_search(Command* cmd) {
    cdf_log("cmd_search()");
    print_header("cmd_search");
    printf("TODO\n");
    return 0;
}

void free_cmd(Command* cmd) {
    free(cmd);
}

int read_exec_command(Command* cmd) {
    if (strlen(cmd->name) == 0) {
        print_header("");
        return 0;
    }
    if (strcmp(cmd->name, "exit") == 0) {
        cmd_exit(cmd);
    } else if (strcmp(cmd->name, "clear") == 0) {
        cmd_clear(cmd);
    } else if (strcmp(cmd->name, "test") == 0) {
        cmd_test(cmd);
    } else if (strcmp(cmd->name, "cdf_new") == 0 || strcmp(cmd->name, "new") == 0) {
        cmd_cdf_new(cmd);
    } else if (strcmp(cmd->name, "cdf_init") == 0 || strcmp(cmd->name, "init") == 0) {
        cmd_cdf_init(cmd);
    } else if (strcmp(cmd->name, "cdf_display") == 0 || strcmp(cmd->name, "display") == 0) {
        cmd_cdf_display(cmd);
    } else if (strcmp(cmd->name, "cdf_cols") == 0) {
        cmd_cdf_colums(cmd);
    } else if (strcmp(cmd->name, "cdf_lines") == 0) {
        cmd_cdf_lines(cmd);
    } else if (strcmp(cmd->name, "cdf_edit") == 0) {
        cmd_cdf_edit(cmd);
    } else if (strcmp(cmd->name, "cdf_search") == 0) {
        cmd_cdf_search(cmd);
    } else if (strcmp(cmd->name, "cdf_eq") == 0) {
        cmd_cdf_eq(cmd);
    } else if (strcmp(cmd->name, "cdf_gt") == 0) {
        cmd_cdf_gt(cmd);
    } else if (strcmp(cmd->name, "cdf_lt") == 0) {
        cmd_cdf_lt(cmd);
    } else if (strcmp(cmd->name, "col_new") == 0 || strcmp(cmd->name, "col_add") == 0) {
        cmd_col_add(cmd);
    } else if (strcmp(cmd->name, "col_delete") == 0) {
        cmd_col_delete_by_int(cmd);
    } else if (strcmp(cmd->name, "col_delete_by_title") == 0) {
        cmd_col_delete(cmd);
    } else if (strcmp(cmd->name, "col_display") == 0) {
        cmd_col_display(cmd);
    } else if (strcmp(cmd->name, "col_title") == 0) {
        cmd_col_title(cmd);
    } else if (strcmp(cmd->name, "col_sort") == 0) {
        cmd_col_sort(cmd);
    } else if (strcmp(cmd->name, "row_new") == 0 || strcmp(cmd->name, "row_add") == 0) {
        cmd_row_add(cmd);
    } else if (strcmp(cmd->name, "row_delete") == 0) {
        cmd_row_delete(cmd);
    } else if (strcmp(cmd->name, "row_display") == 0) {
        cmd_row_display(cmd);
    } else if (strcmp(cmd->name, "csv_import") == 0) {
        cmd_csv_import(cmd);
    } else if (strcmp(cmd->name, "csv_export") == 0) {
        cmd_csv_export(cmd);
    } else if (strcmp(cmd->name, "help") == 0) {
        cmd_help(cmd);
    } else {
        print_header("Command not found");
    }
    return 0;
}

int cmd_exit(Command* cmd) {
    cdf_log("cmd_exit()");
    print_header("exit");
    exit(0);
}

int cmd_error(char *msg) {
    cdf_log("error");
    print_header(msg);
    return 0;
}

int cmd_clear(Command* cmd) {
    cdf_log("cmd_clear()");
    print_header("clear");
    printf("\033[2J\033[1;1H"); // clean screen
    return 0;
}

//Display of the list of all the commands to exploit the cdataframe
int cmd_help(Command* cmd) {
    cdf_log("cmd_help()");
    printf("\033[2J\033[1;1H");
    printf("HELP\n");
    printf("\n");
    printf("*********************************************************************************\n");
    printf("\t\t\t\tLIST OF COMMANDS\n");
    printf("*********************************************************************************\n");
    printf("General commands\n");
    printf("\t- clear : To clear the screen > type 'clear' \n");
    printf("\t- test : To load a random test > type 'test' \n");
    printf("\t- csv_import : import data from csv > type 'csv_import file.csv'\n");
    printf("\t- csv_export : export date to csv > type 'csv_export file.csv'\n");
    printf("\t- help : \n");
    printf("\t- exit : exit\n");
    printf("Cdataframe's commands\n");
//    printf("\t- cdf_new : to create a cdataframe: type 'cdf_new TYPE TYPE ...'\n");
    printf("\t- cdf_init : to create a cdataframe: type 'cdf_init TYPE TYPE ...'\n");
    printf("\t- cdf_display : display cdataframe\n"); 
    printf("\t- cdf_search : cdf_search data\n"); 
    printf("\t- cdf_lines : display rows size\n"); 
    printf("\t- cdf_cols : display cols\n"); 
    printf("\t- cdf_edit : edit > type 'cdf_edit data posx posy' \n"); 
    printf("\t- cdf_search : search > type 'cdf_search data' \n"); 
    printf("\t- cdf_eq : nb eq to data > type 'cdf_eq data'\n"); 
    printf("\t- cdf_gt : nb great then data > type 'cdf_gt data'\n"); 
    printf("\t- cdf_lt : nb less then data > type 'cdf_lt data'\n"); 
    printf("Column's commands\n");
    printf("\t- col_add : to add a column > type 'col_add TYPE title'\n");
    printf("\t- col_display : to display one collomn at POS > type 'col_display POS'\n");
    printf("\t- col_delete : to delete column > type 'col_delete POS'\n");
    printf("\t- col_delete_by_title : to delete column > type 'col_delete_by_title'\n");
    printf("\t- col_title : to replace a title > type 'col_title POS new_title'\n");
    printf("\t- cdf_edit : to replace a data > type 'cdf_edit data posx posy\n");
    printf("\t- col_sort : to sort a column > type 'col_sort colnb asc/desc\n");
    printf("Row's commands\n");
    printf("\t- row_display : to display a row > type 'row_display pos'\n"); 
    printf("\t- row_add : to add a row > type 'row_new val1 val2 ...'\n");
    printf("\t- row_delete : to delete a row > type 'row_delete pos'\n");   
    printf("________________________________________________________________________________\n");
}

//Command to run the code
void cmd_run() {
    printf("\n");
    print_header("Enter a command :");
    while (1) {
        Command* cmd = create_commande();
        read_from_stdin(cmd);
        read_exec_command(cmd);
        free_cmd(cmd);
    }
}
