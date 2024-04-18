#define REALOC_SIZE 256
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char* title;
    int* value;
    int phy_size;
    int log_size;
}COLUMN;

COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);


