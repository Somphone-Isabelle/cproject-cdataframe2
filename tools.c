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
    cmd->params[cmd->size++] = p;
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
        print_header("exit");
        exit(0);
    } else if (strcmp(cmd->name, "clear") == 0) {
        print_header("clear");
    } else if (strcmp(cmd->name, "test") == 0) {
        print_header("test : run default test");
        cmd_test();
    } else if (strcmp(cmd->name, "cdf_new") == 0) {
        print_header("cdf_new");
    } else if (strcmp(cmd->name, "cdf_col_del") == 0) {
        print_header("cdf_col_del");

        delete_column(cdf, "col2");

    } else if (strcmp(cmd->name, "cdf_col_nb") == 0) {
        print_header("delete_cdataframe");
    } else if (strcmp(cmd->name, "help") == 0) {
        printf("\033[2J\033[1;1H");
        printf("Application HELP\n");
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
        printf("________________________________________________________________________________\n");
    } else {
        print_header("Command not found");
    }
    return 0;
}

void read_from_stdin(Command* cmd) {
    char texte[255];
    printf("\n>");
    fgets(texte, sizeof(texte), stdin);
    texte[strcspn(texte, "\n")] = '\0';
    if (strlen(texte) == 0) {
        return;
    }

    char* token = strtok(texte, " ");
    strcpy(cmd->name, token);
    while (token != NULL) {
        token = (char *)strtok(NULL, " ");
        if (token != NULL) {
            int test = (int)isInt(token);
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

int cmd_test() {
//    run_column_test();
    run_cdf_test();
/*
    ENUM_TYPE cdftype[] = {INT, CHAR, INT};
    CDATAFRAME *cdf = create_cdataframe(cdftype, 3);

    // Display the entire dataframe
    printf("Displaying the entire CDataframe:\n");
    display_cdf(cdf);

    // Delete the dataframe to free memory
    delete_cdataframe(&cdf);
*/
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
