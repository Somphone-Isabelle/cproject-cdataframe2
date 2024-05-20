//Cdataframe project led by Isabelle and Ambre - functions for the tools - header file

#ifndef TOOLS_H
#define TOOLS_H
#define BUFFER_SIZE 255
#define MAX_PARAMS 100

struct command {
    char name[BUFFER_SIZE];
    int size;
    char* params[MAX_PARAMS];
};

typedef struct command Command;
int isInt(char* str);
void print_header(char *title);

Command* create_commande();
void add_param(Command* cmd, char* p);
void read_from_stdin(Command* cmd);

void cdf_log(char *str);

/* LIST COMMAND */

ENUM_TYPE string_to_enumtype(char *_str);

#endif 