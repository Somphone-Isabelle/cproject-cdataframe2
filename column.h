//Cdataframe project led by Isabelle and Ambre - functions for the columns - header file
#ifndef COLUMN_H
#define COLUMN_H
#define REALLOC_SIZE 256

enum enum_type{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE ;

struct column {
    char *title;
    unsigned int size; 
    unsigned int max_size;
    ENUM_TYPE column_type;
    COL_TYPE **data;
    unsigned long long int *index;
};
typedef struct column COLUMN;

//BASICS FUNCTIONS

COLUMN *create_column(ENUM_TYPE type, char* title);
int insert_value(COLUMN* col, void *value);
int insert_value2(COLUMN* col, char *value);
void del_column(COLUMN **col);
void convert_value(COLUMN *col, unsigned int i, char *str, int size);
void print_col(COLUMN* col);


//ANALYSIS FUNCTIONS
int count_occ(COLUMN* col, void* x);
void* pos_val(COLUMN* col, unsigned long long x);
int great_val(COLUMN* col, void* x);
int less_val(COLUMN* col, void* x);
int equal_val(COLUMN* col, void* x);

int run_column_test();
int remove_value(COLUMN *col, int pos);


#endif 