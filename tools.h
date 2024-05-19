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
void read_from_stdin(Command* cmd);

void cdf_log(char *str);

/* LIST COMMAND */

ENUM_TYPE string_to_enumtype(char *_str);

#endif 