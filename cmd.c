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

int cmd_test(Command* cmd) {
    cdf_log("cmd_test()");
    print_header("test : run default test");
    
    run_cdf_test();
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
    } else if (strcmp(cmd->name, "cdf_new") == 0) {
        cmd_cdf_new(cmd);
    } else if (strcmp(cmd->name, "cdf_display") == 0 || strcmp(cmd->name, "display") == 0) {
        cmd_cdf_display(cmd);
    } else if (strcmp(cmd->name, "cdf_delete") == 0) {
        cmd_cdf_delete(cmd);
    } else if (strcmp(cmd->name, "col_new") == 0) {
        cmd_col_new(cmd);
    } else if (strcmp(cmd->name, "col_delete") == 0) {
        cmd_col_delete(cmd);
    } else if (strcmp(cmd->name, "col_insert") == 0) {
        cmd_col_insert(cmd);
    } else if (strcmp(cmd->name, "col_title") == 0) {
        cmd_col_title(cmd);
    } else if (strcmp(cmd->name, "col_edit") == 0) {
        cmd_col_edit(cmd);
    } else if (strcmp(cmd->name, "col_test") == 0) {
        cmd_col_test(cmd);
    } else if (strcmp(cmd->name, "col_sort") == 0) {
        cmd_col_sort(cmd);
    } else if (strcmp(cmd->name, "csv_import") == 0) {
        cmd_csv_import(cmd);
    } else if (strcmp(cmd->name, "row_insert") == 0) {
        cmd_row_insert(cmd);
    } else if (strcmp(cmd->name, "row_delete") == 0) {
        cmd_row_delete(cmd);
    } else if (strcmp(cmd->name, "row_display") == 0) {
        cmd_row_display(cmd);
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
    cdf_log("cmd_clear()");
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
    return 0;
}

int cmd_help(Command* cmd) {
    cdf_log("cmd_help()");
    printf("\033[2J\033[1;1H");
    printf("HELP\n");
    printf("\n");
    printf("List of commands\n");
    printf("- clear : clear screen\n");
    printf("- test : load test data\n");
    printf("- cdf_new : usage : >cdf_new INT CHAR STRING DOUBLE INT\n");
    printf("- cdf_display : display cdataframe\n"); 
    printf("- cdf_delete : delete\n");
    printf("- col_new : add new column, usage >col_new TYPE title\n");
    printf("- col_delete : delete colomn at POS, usage >col_delete POS\n");
    printf("- col_insert : insert new column at POS, usage >col_insert POS TYPE tile\n");
    printf("- col_title : replace title, usage >col_tile POS new_title\n");
    printf("- col_edit : replace data at column et line\n");
    printf("- col_sort : \n");
    printf("- csv_import : \n");
    printf("- csv_export : \n");
    printf("- help : \n");
    printf("- exit : exit\n");
    
    printf("________________________________________________________________________________\n");
}

void cmd_run() {
    print_header("Enter a command :");
    while (1) {
        Command* cmd = create_commande();
        read_from_stdin(cmd);
        read_exec_command(cmd);
        free_cmd(cmd);
    }
}
