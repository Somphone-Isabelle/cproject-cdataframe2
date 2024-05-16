#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cdataframe.h"
#include "column.h"
#include "list.h"
#include "tools.h"

void cdf_log(char *str) {
    puts(str);
}

Command* create_commande() {
    Command* cmd = (Command*)malloc(sizeof(Command));    
    strcpy(cmd->name, "");
    cmd->size = 0;
    return cmd;
}

void add_param(Command* cmd, char* p) {
    printf("arg : %s\n", p);
    char *str = malloc(BUFFER_SIZE);
    stpcpy(str, p);
    cmd->params[cmd->size] = str;
    cmd->size++;
}

void free_cmd(Command* cmd) {
    free(cmd);
}

void print_header(char *title) {
    printf("\033[2J\033[1;1H"); // clean screen
    printf("%s\n", title); // title
    printf("help to list command\n");
    printf("________________________________________________________________________________\n");
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
    } else if (strcmp(cmd->name, "cdf_display") == 0) {
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
    } else if (strcmp(cmd->name, "csv_export") == 0) {
        cmd_csv_export(cmd);
    } else if (strcmp(cmd->name, "help") == 0) {
        cmd_help(cmd);
    } else {
        print_header("Command not found");
    }
    return 0;
}

void read_from_stdin(Command* cmd) {
    char texte[1000];
    printf("\n>");
    fgets(texte, sizeof(texte), stdin);
    texte[strcspn(texte, "\n")] = '\0';
    if (strlen(texte) == 0) {
        return;
    }
    printf("> cmd : %s\n", texte);
    char* token = strtok(texte, " ");
    strcpy(cmd->name, token);
    while (token != NULL) {
        token = (char *)strtok(NULL, " ");
        if (token != NULL) {
            add_param(cmd, token);
        }
    }
}

int isInt(char* str) {
    int len = strlen(str);
    // empty = not
    if (len == 0) {
        return 0;
    }
    // check 
    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0; 
        }
    }
    return 1; 
}

int isFloat(char* str) {
    // todo
    return 1; 
}

int isDouble(char* str) {
    // todo
    return 1; 
}

int isChar(char* str) {
    int len = strlen(str);
    // empty = not
    if (len != 1) {
        return 0;
    }
    return 1; 
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

int cmd_test(Command* cmd) {
    cdf_log("cmd_test()");
    print_header("test : run default test");
    
    run_cdf_test();
    return 0;
}

int cmd_help(Command* cmd) {
    cdf_log("cmd_help()");
    printf("\033[2J\033[1;1H");
    printf("HELP\n");
    printf("\n");
    printf("List of commands\n");
    printf("- test : run test\n");
    printf("- cdf_new  : usage >col_new type_colonne titre_colonne\n");
    printf("- col_add  : usage >col_add value1 value2 value3...\n");
    printf("- col_show : usage >col_show\n");
    printf("- col_del  : usage >col_del nom_colonne\n");
    printf("- col_sort : ...\n");
    printf("- import   : usage >import fichier_donnees.csv");
    printf("...\n");

    printf("- exit : \n");
    printf("- clear : \n");
    printf("- test : \n");
    printf("- help : \n");
    printf("- cdf_new : \n");
    printf("- cdf_display : \n"); 
    printf("- cdf_delete : \n");
    printf("- col_new : \n");
    printf("- col_delete : \n");
    printf("- col_insert : \n");
    printf("- col_title : \n");
    printf("- col_edit : \n");
    printf("- col_test : \n");
    printf("- col_sort : \n");
    printf("- csv_import : \n");
    printf("- csv_export : \n");

    printf("________________________________________________________________________________\n");
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

    display_cdf(CDF);

    return 0;
}

int cmd_cdf_delete(Command* cmd) {
    cdf_log("cmd_cdf_delete()");
    print_header("cmd_cdf_delete");
    printf("TODO\n");
    return 0;
}

int cmd_row_new(Command* cmd) {
    cdf_log("cmd_row_new()");
    print_header("cmd_row_new");
    printf("TODO\n");
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
    printf("TODO\n");
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
    printf("TODO\n");
    return 0;
}

int cmd_col_insert(Command* cmd) {
    cdf_log("cmd_col_insert()");
    print_header("cmd_col_insert");
    printf("TODO\n");
    return 0;
}

int cmd_col_title(Command* cmd) {
    cdf_log("cmd_col_title()");
    print_header("cmd_col_title");
    printf("TODO\n");
    return 0;
}

int cmd_col_edit(Command* cmd) {
    cdf_log("cmd_col_edit()");
    print_header("cmd_col_edit");
    printf("TODO\n");
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

void cmd_run() {
    print_header("Enter a command :");
    while (1) {
        Command* cmd = create_commande();
        read_from_stdin(cmd);
        read_exec_command(cmd);
        free_cmd(cmd);
    }
}
