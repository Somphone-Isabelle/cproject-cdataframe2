#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#define REALLOC_SIZE 256
#define TITLE_MAX_LENGTH 50

COLUMN *create_column(char* title){
    COLUMN* column = (COLUMN*)malloc(sizeof(COLUMN));
    if (column == NULL){
        printf("ERROR");
        exit(1);
    }
    int title_len = 0;
    while (title[title_len] != '\0' && title_len <TITLE_MAX_LENGTH -1){
        title_len++;
    }
    column->title = (char*)malloc((title_len + 1)*sizeof(char));
    if(column->title == NULL){
        printf("ERROR");
        exit(1);
    }
    for (int i = 0; i<title_len;i++){
        column->title[i] = title[i];
    } 
    column->title[title_len]='\0';
    column->value = NULL;
    column->phy_size = 0;
    column->log_size = 0;

    return column;
}

int insert_value(COLUMN* col, int value){
    if (col->log_size >= col->phy_size){
        int* new_val = (int*)realloc(col->value,(col->phy_size + REALLOC_SIZE)*sizeof(int));
        if (new_val == NULL){
            printf("ERROR");
            return 0;
        }
        col->value = new_val;
        col->phy_size += REALLOC_SIZE;
    }
    col->value[col->log_size] = value;
    col->log_size++;
    return 1;
}

void delete_column(COLUMN **col);
void print_col(COLUMN* col);

