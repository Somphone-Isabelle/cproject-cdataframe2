#ifndef TOOLS_H
#define TOOLS_H

#define BUFFER_SIZE 255
#define MAX_PARAMS 100

static CDATAFRAME   *CDF;
static unsigned int INDEX = 0; // TODO controle de la taille de colone < index

struct command {
    char name[BUFFER_SIZE];
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
void print_header(char *title);

Command* create_commande();
void add_param(Command* cmd, char* p);
void free_cmd(Command* cmd);
int read_exec_command(Command* cmd);
void read_from_stdin(Command* cmd);

int cmd_test();
void cmd_run();
void cdf_log(char *str);

int cmd_error(char *msg);

/* LIST COMMAND */
int cmd_exit(Command* cmd);
int cmd_clear(Command* cmd);
int cmd_test(Command* cmd);
int cmd_help(Command* cmd);
int cmd_cdf_new(Command* cmd);
int cmd_cdf_display(Command* cmd); 
int cmd_cdf_delete(Command* cmd);
int cmd_col_new(Command* cmd);
int cmd_col_delete(Command* cmd);
int cmd_col_insert(Command* cmd);
int cmd_col_title(Command* cmd);
int cmd_col_edit(Command* cmd);
int cmd_col_list(Command* cmd);
int cmd_col_test(Command* cmd);
int cmd_col_sort(Command* cmd);
int cmd_csv_import(Command* cmd);
int cmd_csv_export(Command* cmd);
int cmd_row_insert(Command* cmd);
int cmd_row_delete(Command* cmd);
int cmd_row_display(Command* cmd);

ENUM_TYPE string_to_enumtype(char *_str);

#endif 