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
        return NULL;
    }

    column->title = strdup(title);
    column->size = 0;
    column->max_size = 0;
    column->column_type = type;
    column->data = NULL;
    column->index = NULL;

    return column;
}

int insert_value(COLUMN *col, void *value){
    if (col->size >= col->max_size){
        COL_TYPE **new_data = (COL_TYPE **)realloc(col->data, (col->max_size + REALLOC_SIZE) * sizeof(COL_TYPE *));
        if (new_data == NULL){
            return 0;
        }
        col->data = new_data;
        col->max_size += REALLOC_SIZE;
    }
    
    col->data[col->size] = (COL_TYPE *)malloc(sizeof(COL_TYPE));

    if (value == NULL){

        col->data[col->size] = NULL;
    }
    else {
    switch (col->column_type){
        case UINT:
            *((unsigned int *)(col->data[col->size])) = *((unsigned int *)value);
            break;
        case INT:
            *((signed int *)(col->data[col->size])) = *((signed int *)value);
            break;
        case CHAR:
            *((char *)(col->data[col->size])) = *((char *)value);
            break;
        case FLOAT:
            *((float *)(col->data[col->size])) = *((float *)value);
            break;
        case DOUBLE:
            *((double *)(col->data[col->size])) = *((double *)value);
            break;
        case STRING:{
            char *str_value = (char *)value;
            col->data[col->size]->string_value = (char *)malloc(strlen(str_value) + 1);
            if (col->data[col->size]->string_value == NULL) {
                free(col->data[col->size]);
                return 0;
            }
            strcpy(col->data[col->size]->string_value, str_value);
            break;
        }
        case STRUCTURE:
            break;
        default:
            return 0;
    }}
    col->size++;
    return 1;
}

void del_column(COLUMN **col){
    if (*col != NULL){
        free((*col)->title);
        for (unsigned int i = 0; i < (*col)->size; ++i){
            if ((*col)->column_type == STRING){
                free((*col)->data[i]->string_value);
            }
            free((*col)->data[i]);
        }
        free((*col)->data);
        free((*col)->index);
        free(*col);
        *col = NULL;
    }
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size){
    if (col->data[i] == NULL){
        snprintf(str, size, "%s", "NULL");
    }
    else{
        switch(col->column_type){
            case UINT:
                snprintf(str, size, "%u", *((unsigned int *)col->data[i]));
                break;
            case INT:
                snprintf(str, size, "%d", *((int *)col->data[i]));
                break;
            case CHAR:
                snprintf(str, size, "%c", *((char *)col->data[i]));
                break;
            case FLOAT:
                snprintf(str, size, "%f", *((float *)col->data[i]));
                break;
            case DOUBLE:
                snprintf(str, size, "%lf", *((double *)col->data[i]));
                break;
            case STRING:
                snprintf(str, size, "%s", (char *)col->data[i]);
                break;
            case STRUCTURE:
                break;
            default:
                snprintf(str, size, "ERROR");
                break;
    }
}
}

void print_col(COLUMN *col){
    printf("Column '%s' :\n", col->title);
    for (unsigned int i = 0; i < col->size; ++i){
        char value_str[256];
        convert_value(col, i, value_str, sizeof(value_str));
        printf("[%u] %s\n", i, value_str);
    }
}

//ANALYSIS FUNCTIONS

int count_occ(COLUMN *col, void *x){
    int count = 0;
    if (x == NULL){
        for (int i = 0; i < col->size; i++){
            if (col->data[i] == NULL) {
                count++;
            }
        }
    } else {
        switch (col->column_type){
            case UINT:
                for (int i = 0; i < col->size; i++){
                    if (*((unsigned int *)(col->data[i])) == *((unsigned int *)x)){
                        count++;
                    }
                }
                break;
            case INT:
                for (int i = 0; i < col->size; i++){
                    if (*((int *)(col->data[i])) == *((int *)x)){
                        count++;
                    }
                }
                break;
            case CHAR:
                for (int i = 0; i < col->size; i++) {
                    if (*((char *)(col->data[i])) == *((char *)x)){
                        count++;
                    }
                }
                break;
            case FLOAT:
                for (int i = 0; i < col->size; i++){
                    if (*((float *)(col->data[i])) == *((float *)x)){
                        count++;
                    }
                }
                break;
            case DOUBLE:
                for (int i = 0; i < col->size; i++){
                    if (*((double *)(col->data[i])) == *((double *)x)){
                        count++;
                    }
                }
                break;
            case STRING:
                for (int i = 0; i < col->size; i++){
                    if (strcmp((char *)(col->data[i]), (char *)x) == 0){
                        count++;
                    }
                }
                break;
            case STRUCTURE:
                break;
            default:
                break;
        }
    }
    return count;
}

void *pos_val(COLUMN* col, unsigned long long int x){
    if (x >= col->size){
        return NULL;
    }
    return col->data[x];
}

int great_val(COLUMN* col, void* x) {
    int count = 0;
    for (int i = 0; i < col->size; i++) {
        switch (col->column_type) {
            case UINT:
                if (*((unsigned int*)col->data[i]) > *((unsigned int*)x)) {
                    count++;
                }
                break;
            case INT:
                if (*((int*)col->data[i]) > *((int*)x)) {
                    count++;
                }
                break;
            case CHAR:
                if (*((char*)col->data[i]) > *((char*)x)) {
                    count++;
                }
                break;
            case FLOAT:
                if (*((float*)col->data[i]) > *((float*)x)) {
                    count++;
                }
                break;
            case DOUBLE:
                if (*((double*)col->data[i]) > *((double*)x)) {
                    count++;
                }
                break;
            case STRING:
                if (col->data[i] != NULL && strcmp((char*)col->data[i], (char*)x) > 0) {
                    count++;
                }
                break;
            case STRUCTURE:
                // TO WORK AGAIN
                break;
            default:
                // TO WORK AGAIN
                break;
        }
    }
    return count;
}

int less_val(COLUMN* col, void* x){
    int count = 0;
    for (int i = 0; i < col->size; i++) {
        switch (col->column_type) {
            case UINT:
                if (*((unsigned int*)col->data[i]) < *((unsigned int*)x)) {
                    count++;
                }
                break;
            case INT:
                if (*((int*)col->data[i]) < *((int*)x)) {
                    count++;
                }
                break;
            case CHAR:
                if (*((char*)col->data[i]) < *((char*)x)) {
                    count++;
                }
                break;
            case FLOAT:
                if (*((float*)col->data[i]) < *((float*)x)) {
                    count++;
                }
                break;
            case DOUBLE:
                if (*((double*)col->data[i]) < *((double*)x)) {
                    count++;
                }
                break;
            case STRING:
                if (col->data[i] != NULL && strcmp((char*)col->data[i], (char*)x) < 0) {
                    count++;
                }
                break;
            case STRUCTURE:
                // TO WORK AGAIN
                break;
            default:
                // TO WORK AGAIN
                break;
        }
    }
    return count;
}

int equal_val(COLUMN* col, void* x){
int count = 0;
    for (int i = 0; i < col->size; i++) {
        switch (col->column_type) {
            case UINT:
                if (*((unsigned int*)col->data[i]) == *((unsigned int*)x)) {
                    count++;
                }
                break;
            case INT:
                if (*((int*)col->data[i]) == *((int*)x)) {
                    count++;
                }
                break;
            case CHAR:
                if (*((char*)col->data[i]) == *((char*)x)) {
                    count++;
                }
                break;
            case FLOAT:
                if (*((float*)col->data[i]) == *((float*)x)) {
                    count++;
                }
                break;
            case DOUBLE:
                if (*((double*)col->data[i]) == *((double*)x)) {
                    count++;
                }
                break;
            case STRING:
                if (col->data[i] != NULL && strcmp((char*)col->data[i], (char*)x) == 0) {
                    count++;
                }
                break;
            case STRUCTURE:
                // TO WORK AGAIN
                break;
            default:
                // TO WORK AGAIN
                break;
        }
    }
    return count;
}
