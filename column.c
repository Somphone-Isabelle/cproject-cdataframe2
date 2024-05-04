#include "column.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define REALLOC_SIZE 256
#define TITLE_MAX_LENGTH 50

//BASICS FUNCTIONS

COLUMN *create_column(ENUM_TYPE type, char *title){
    COLUMN *column = (COLUMN *)malloc(sizeof(COLUMN));
    if (column == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    column->title = title;
    column->size = 0;
    column->max_size = 0;
    column->column_type = type;
    column->data = NULL;
    column->index = NULL;

    return column;
}

int insert_value(COLUMN *col, void *value) {
    if (!col || col->size >= col->max_size) {
        return 0; // Invalid column or insufficient memory
    }

    // Allocate memory for the new data element
    col->data[col->size] = (COL_TYPE *)malloc(sizeof(COL_TYPE));
    if (!col->data[col->size]) {
        return 0; // Memory allocation failed
    }

    // Copy the value based on the column type
    switch (col->column_type) {
        case UINT:
            col->data[col->size]->uint_value = *((unsigned int *)value);
            break;
        case INT:
            col->data[col->size]->int_value = *((signed int *)value);
            break;
        case CHAR:
            col->data[col->size]->char_value = *((char *)value);
            break;
        case FLOAT:
            col->data[col->size]->float_value = *((float *)value);
            break;
        case DOUBLE:
            col->data[col->size]->double_value = *((double *)value);
            break;
        case STRING:
            col->data[col->size]->string_value = strdup((char *)value);
            if (!col->data[col->size]->string_value) {
                free(col->data[col->size]);
                return 0; // Memory allocation failed
            }
            break;
        case STRUCTURE:
            // Handle structure insertion
            break;
        default:
            return 0; // Invalid column type
    }

    col->size++;
    return 1; // Successful insertion
}


void delete_column(COLUMN **col) {
    if (!col || !*col) {
        return; // Nothing to delete
    }

    // Free memory for title
    free((*col)->title);

    // Free memory for data elements
    for (int i = 0; i < (*col)->size; i++) {
        switch ((*col)->column_type) {
            case STRING:
                free((*col)->data[i]->string_value);
                break;
            case STRUCTURE:
                // Free memory for structure data
                break;
            default:
                // No additional memory to free
                break;
        }
        free((*col)->data[i]);
    }

    // Free memory for data array and index
    free((*col)->data);
    free((*col)->index);

    // Free memory for column structure
    free(*col);
    *col = NULL;
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size) {
    if (!col || !str || i >= col->size) {
        snprintf(str, size, "ERROR");
        return;
    }

    switch (col->column_type) {
        case INT:
            snprintf(str, size, "%d", col->data[i]->int_value);
            break;
        case UINT:
            snprintf(str, size, "%u", col->data[i]->uint_value);
            break;
        case CHAR:
            snprintf(str, size, "%c", col->data[i]->char_value);
            break;
        case FLOAT:
            snprintf(str, size, "%f", col->data[i]->float_value);
            break;
        case DOUBLE:
            snprintf(str, size, "%lf", col->data[i]->double_value);
            break;
        case STRING:
            snprintf(str, size, "%s", col->data[i]->string_value);
            break;
        case STRUCTURE:
            snprintf(str, size, "Structure to design");
            break;
        default:
            snprintf(str, size, "ERROR");
            break;
    }
}


void print_col(COLUMN *col) {
    if (!col) {
        printf("Column is NULL\n");
        return;
    }

    printf("Content of column '%s' :\n", col->title);
    for (unsigned int i = 0; i < col->size; ++i) {
        char value_str[256];
        convert_value(col, i, value_str, sizeof(value_str));
        printf("[%u] %s\n", i, value_str);
    }
}

/*

//ANALYSIS FUNCTIONS

int count_occ(COLUMN* col, int x){
    int count = 0;
    for (int i = 0; i<col->log_size;i++){
        if (col->value[i] == x){
            count++;
        }
    }
    return count;
}


int pos_val(COLUMN* col, int pos){
    /*if(pos < 0 || pos >= col->log_size){
        printf("ERROR");
        return 99;
    }*/
   
/*
int great_val(COLUMN* col, int x){
    int count = 0;
    for(int i = 0; i < col->log_size;i++){
        if(col->value[i] > x){
            count++;
        }
    }
    return count;
}
int less_val(COLUMN* col, int x){
    int count = 0;
    for(int i = 0; i < col->log_size;i++){
        if(col->value[i] < x){
            count++;
        }
    }
    return count;
}
int equal_val(COLUMN* col, int x){
    int count = 0;
    for(int i = 0; i < col->log_size;i++){
        if(col->value[i] == x){
            count++;
        }
    }
    return count;
}*/
