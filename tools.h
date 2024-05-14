#ifndef TOOLS_H
#define TOOLS_H

#define BUFFER_SIZE 255
#define FCT_SIZE 30
#define MAX_PARAMS 10

struct command {
    char name[FCT_SIZE];
    int size;
    char* params[MAX_PARAMS];
};

typedef struct command Command;
int isNull(char* str);
int isInt(char* str);
int isUInt(char* str);
int isDouble(char* str);
int isFloat(char* str);
int isChar(char* str);
int isString(char* str);
int isStruct(char* str);

Command* create_commande();
void add_param(Command* cmd, char* p);
void free_cmd(Command* cmd);
int read_exec_command(Command* cmd);
void read_from_stdin(Command* cmd);

int cmd_test();
void cmd_run();

#endif 