#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cdataframe.h"
#include "column.h"
#include "list.h"
#include "tools.h"

void cdf_log(char *str) {
    int LOG_MODE = 0;
    if (LOG_MODE == 1) {
        puts(str);
    }
}

Command* create_commande() {
    Command* cmd = (Command*)malloc(sizeof(Command));    
    strcpy(cmd->name, "");
    cmd->size = 0;
    return cmd;
}

//Add a parameter
void add_param(Command* cmd, char* p) {
//    printf("arg : %s\n", p);
    char *str = malloc(BUFFER_SIZE);
    stpcpy(str, p);
    cmd->params[cmd->size] = str;
    cmd->size++;
}

void print_header(char *title) {
//    printf("\033[2J\033[1;1H"); // clean screen
    printf("________________________________________________________________________________\n");
    printf("\n");
    printf("%s [help to list command]\n", title); // title
    printf("________________________________________________________________________________\n");
}

void read_from_stdin(Command* cmd) {
    char texte[1000];
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

ENUM_TYPE string_to_enumtype(char *_str) {
    cdf_log("string_to_enumtype()");

    ENUM_TYPE type;
    if (strcmp(_str, "INT") == 0) {
        type = INT;
    } else if (strcmp(_str, "UINT") == 0) {
        type = UINT;
    } else if (strcmp(_str, "DOUBLE") == 0) {
        type = DOUBLE;
    } else if (strcmp(_str, "FLOAT") == 0) {
        type = FLOAT;
    } else if (strcmp(_str, "CHAR") == 0) {
        type = CHAR;
    } else if (strcmp(_str, "STRING") == 0) {
        type = STRING;
    } else {
        type = NULLVAL;
    }
    return type;
}

