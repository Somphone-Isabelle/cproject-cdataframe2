//Cdataframe project led by Isabelle and Ambre - functions for the columns - source file

#include "column.h"
#include "tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REALLOC_SIZE 256
#define TITLE_MAX_LENGTH 50

//BASICS FUNCTIONS

//Creating a new column
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

//Inserting a new value in a column
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
            col->data[col->size]->string_value = value;
            break;
        }
        case STRUCTURE:
            break;
        default:
            return 0;
    
    }}
    
    long  long unsigned int *index = malloc(sizeof(int) + 1);
    for (int i = 0; i < col->size; i++) {
        index[i] = col->index[i];
    }
    index[col->size] = col->size;
    col->index = index;

    printf("index : %i\n", col->index[col->size]);
    col->size++;
    return 1;
}

//Deleting a column: first removing the title then data from the column
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

//Converting the value in function of the type of the column
void convert_value(COLUMN *col, unsigned int i, char *str, int size){
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
                snprintf(str, size, "%s", (char *)(col->data[i]->string_value));
                break;
            case STRUCTURE:
                break;
            default:
                snprintf(str, size, "ERROR");
                break;
        }
    }
}

//Displaying a chosen column and its content
void print_col(COLUMN *col){
    printf("Column '%s' :\n", col->title);
    for (unsigned int i = 0; i < col->size; ++i){
        char value_str[256];
        convert_value(col, i, value_str, sizeof(value_str));
        printf("[%u] %s\n", i, value_str);
    }
}

//ANALYSIS FUNCTIONS

//This function takes as argument a given type of data 'x', and will count the occurrences of any data of this type in the column
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

//This function returns the position of a given value in the column
void *pos_val(COLUMN* col, unsigned long long int x){
    if (x >= col->size){
        return NULL;
    }
    return col->data[x];
}

//This function gives the value contained in the column that is greater than the given one 'x' in function of its type
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
                break;
        }
    }
    return count;
}

//This function gives the value contained in the column that is less than the given one 'x' in function of its type
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

//This function gives the value contained in the column that is equal to the given one 'x' in function of its type
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
                break;
        }
    }
    return count;
}

//Function to test the functions for the columns with different types of input data
int run_column_test() {
    printf("\nTEST STRING");
    COLUMN *colString = create_column(STRING, "String");
    char *s1 = "Toto est 1";
    char *s2 = "Titi est 2";
    char *s3 = "Tutu est 3";
    printf(" : %s, %s, %s\n", s1, s2, s3);
    insert_value(colString, s1);
    insert_value(colString, s2);
    insert_value(colString, s3);
    print_col(colString);

    printf("\nTEST INT");
    COLUMN *colInt = create_column(INT, "INT");
    int i1 = 999, i2 = -12345, i3 = 42;
    printf(" : %i, %i, %i\n", i1, i2, i3);
    insert_value(colInt, &i1);
    insert_value(colInt, &i2);
    insert_value(colInt, &i3);
    print_col(colInt);

    printf("\nTEST UNIT");
    COLUMN *colUInt = create_column(UINT, "UINT");
    unsigned int u1 = 42, u2 = 0, u3 = 123456789;
    printf(" : %u, %u, %u\n", u1, u2, u3);
    insert_value(colUInt, &u1);
    insert_value(colUInt, &u2);
    insert_value(colUInt, &u3);
    print_col(colUInt);

    printf("\nTEST CHAR");
    COLUMN *colChar = create_column(CHAR, "CHAR");
    char c1 = 'a', c2 = 'b', c3 = 'z';
    printf(" : %c, %c, %c\n", c1, c2, c3);
    insert_value(colChar, &c1);
    insert_value(colChar, &c2);
    insert_value(colChar, &c3);
    print_col(colChar);

    printf("\nTEST DOUBLE");
    COLUMN *colDouble = create_column(DOUBLE, "DOUBLE");
    double d1 = 1.23, d2 = 0.9999, d3 = 0.0;
    printf(" : %f, %f, %f\n", d1, d2, d3);
    insert_value(colDouble, &d1);
    insert_value(colDouble, &d2);
    insert_value(colDouble, &d3);
    print_col(colDouble);

    printf("\nTEST FLOAT");
    COLUMN *colFloat = create_column(FLOAT, "FLOAT");
    double f1 = 1.23, f2 = 0.99, f3 = 0.0;
    printf(" : %f, %f, %f\n", f1, f2, f3);
    insert_value(colFloat, &f1);
    insert_value(colFloat, &f2);
    insert_value(colFloat, &f3);
    print_col(colFloat);
}


//Inserting a new value in a column
int insert_value2(COLUMN *col, char *value){
    cdf_log("log : int insert_value2()");

    if (col->size >= col->max_size){
        COL_TYPE **new_data = (COL_TYPE **)realloc(col->data, (col->max_size + REALLOC_SIZE) * sizeof(COL_TYPE *));
        if (new_data == NULL){
            return 0;
        }
        col->data = new_data;
        col->max_size += REALLOC_SIZE;
    }
    col->data[col->size] = (COL_TYPE *)malloc(sizeof(COL_TYPE));
            
    long  long unsigned int *index = malloc(sizeof(int) * BUFFER_SIZE);
    for (int i = 0; i < col->size; i++) {
        index[i] = col->index[i];
    }
    index[col->size] = col->size;
    col->index = index;
    
    if (value == NULL){
        col->data[col->size] = NULL;
    } else {
    switch (col->column_type){
        //convert the data from the columns 
        case UINT:
            col->data[col->size]->uint_value = atoi(value);
            break;
        case INT:
            col->data[col->size]->int_value = atoi(value);
            break;
        case CHAR:
            *((char *)(col->data[col->size])) = *((char *)value);
            break;
        case FLOAT:
            col->data[col->size]->float_value = atof(value);
            break;
        case DOUBLE:
            col->data[col->size]->double_value = atof(value);
            break;
        case STRING:{
            col->data[col->size]->string_value = value;
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

//remove a value in a column
int remove_value(COLUMN *col, int pos){
    cdf_log("log : remove_value");

    if (pos > 0) {
        pos--;
    } else {
        printf("Error bad argument cannot remove");
    }
    if (col != NULL && col->size > 0) {
        for (int i = 0; i < col->size; i++) {
            if (col->index[i] >= pos) {
                col->data[i] = col->data[i + 1];
                col->index[i] = i;
            } 
        }
    }
    col->size--;
    return 0;
}



