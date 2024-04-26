<<<<<<< HEAD
#define REALOC_SIZE 256
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
=======
#ifndef COLUMN_H
#define COLUMN_H
#define REALLOC_SIZE 256
>>>>>>> f1d4cfb6fa3ab2c3647ab07f5bf7e0d96f29d6a8


typedef struct{
    char* title;
    int* value;
    int phy_size;
    int log_size;
}COLUMN;

//BASICS FUNCTIONS

COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);

//ANALYSIS FUNCTIONS
int count_occ(COLUMN* col, int x);
int pos_val(COLUMN* col, int pos);
int great_val(COLUMN* col, int x);
int less_val(COLUMN* col, int x);
int equal_val(COLUMN* col, int x);

#endif 