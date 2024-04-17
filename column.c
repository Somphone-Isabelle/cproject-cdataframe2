#include "column.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define REALLOC_SIZE 256

COLUMN *create_column(char* title){
    COLUMN* column = (COLUMN*)malloc(sizeof(COLUMN)); 
    column->title=(char*)malloc(strlen(title)+1);
    strcpy(column->title, title);
    column->value = NULL; //initialization of the attributes
    column->phy_size = 0;
    column->log_size = 0;
    return column; //returnt pointer
}

int insert_value(COLUMN* col, int value){
    int* new_val = (int*)realloc(col->value,(col->phy_size + REALLOC_SIZE));
    col->value = new_val;
    col->phy_size += REALLOC_SIZE;
    col->value[col->log_size] = value;
    col->log_size++;
    return 0;

}
void delete_column(COLUMN **col);
void print_col(COLUMN* col);

