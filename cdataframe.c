#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdataframe.h"
#include "list.h"

#define TITLE_MAX_LENGTH 50

//FILLING FUNCTIONS
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size) {
    CDATAFRAME *cdf = (CDATAFRAME *)malloc(sizeof(CDATAFRAME));
    if (cdf == NULL) {
        return NULL;
    }

    cdf->columns = (COLUMN **)malloc(size * sizeof(COLUMN *));
    if (cdf->columns == NULL) {
        free(cdf);
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        cdf->columns[i] = create_column(cdftype[i], "Column");
        if (cdf->columns[i] == NULL) {
            // Rollback on failure
            for (int j = 0; j < i; j++) {
                del_column(&(cdf->columns[j]));
            }
            free(cdf->columns);
            free(cdf);
            return NULL;
        }
    }

    cdf->nbrows = 0;
    cdf->rows = lst_create_list();
    if (cdf->rows == NULL) {
        for (int i = 0; i < size; i++) {
            del_column(&(cdf->columns[i]));
        }
        free(cdf->columns);
        free(cdf);
        return NULL;
    }

    return cdf;
}

void delete_cdataframe(CDATAFRAME **cdf) {
    if (*cdf != NULL) {
        for (int i = 0; i < get_nbcols(*cdf); i++) {
            del_column(&((*cdf)->columns[i]));
        }
        free((*cdf)->columns);
        lst_delete_list((*cdf)->rows);
        free(*cdf);
        *cdf = NULL;
    }
}

 
/*
void user_imput(CDATAFRAME* dataf){
    for(int i = 0; i<dataf->nbcols;i++){
        printf("Enter values for %s column: \n", dataf->columns[i]->title);
        for(int j = 0; j<dataf->nbrows; j++){
            int val;
            printf("Enter value for row %d: ", j+1);
            scanf("%d", &val);
            insert_value(dataf->columns[i], val); //call function from column.c
        }
        dataf->nbrows++;
    }
}
void hardfill_df(CDATAFRAME* dataf){
    for(int i = 0; i<dataf->nbrows; i++){
        for(int j=0; j<dataf->nbcols; j++){
            int val = rand()%50; //choose 50 for a test
            insert_value(dataf->columns[j], val);
        }
    }
}
*/

//DISPLAYING FUNCTIONS
void display_cdf(CDATAFRAME *cdf) {
    if (cdf == NULL) {
        printf("Dataframe is NULL.\n");
        return;
    }

    printf("Column Names:\n");
    for (int i = 0; i < get_nbcols(cdf); i++) {
        printf("%s\t", cdf->columns[i]->title);
    }
    printf("\n");

    // Display rows
    printf("Number of Rows: %d\n", cdf->nbrows);
    for (lnode *cur_row = get_first_node(cdf->rows); cur_row != NULL; cur_row = get_next_node(cdf->rows, cur_row)) {
        for (int i = 0; i < get_nbcols(cdf); i++) {
            char value_str[256];
            convert_value(cdf->columns[i], (unsigned int)cur_row->data, value_str, sizeof(value_str));
            printf("%s\t", value_str);
        }
        printf("\n");
    }
}

/*
void disp_part_row(CDATAFRAME* dataf, int start, int end){
    printf("Select rows from %d to %d: \n", start,end);
     for (int i = start; i <= end; i++) {
        for (int j = 0; j < dataf->nbcols; j++) {
            printf("%d\t", dataf->columns[j]->value[i]);
        }
        printf("\n");
    }
}

void disp_part_col(CDATAFRAME* dataf, int start, int end){
    printf("Select rows from %d to %d: \n", start,end);
     for (int i = start; i <= end; i++) {
        for (int j = 0; j < dataf->nbrows; j++) {
            printf("%d\t", dataf->columns[j]->value[i]);
        }
        printf("\n");
     }
}
*/

//OPERATIONS FUNCTIONS

/*
void add_row(CDATAFRAME* dataf, int* vals){
    for (int i = 0; i<dataf->nbcols;i++){
        insert_value(dataf->columns[i],vals[i]);
    }
}
void del_row(CDATAFRAME* dataf, int i){
    for(int j = 0; j<dataf->nbcols; j++){
        for (int k=i; k<dataf->columns[j]->log_size-1;k++){
            dataf->columns[j]->value[k] = dataf->columns[j]->value[k+1];
        }
        dataf->columns[j]->log_size--;
    }
}

void add_col(CDATAFRAME* dataf, COLUMN* column){
    dataf->columns[dataf->nbcols++] = column;
}
*/
/*

void delete_column_cdf(CDATAFRAME *cdf, char *col_name){
  lnode *current = get_first_node(cdf->columns);
  while (current != NULL){
    COLUMN *col = (COLUMN*)(current->data);
    if (strcmp(col->name, col_name)==){
        lst_create_lnode(cdf->columns, current);
        del_column(&col);
        return;
    }
    current = get_next_node(cdf->columns, current);
  }
}
*/
/*
void rename_col(CDATAFRAME* dataf, int j, char* new_title){
    free(dataf->columns[j]->title);
    int len_title = 0;
    while (new_title[len_title] != '\0' && len_title < TITLE_MAX_LENGTH - 1) {
        len_title++;
    }
    dataf->columns[j]->title = (char*)malloc((len_title + 1) * sizeof(char));
    for(int i =0; len_title; i++){
        dataf->columns[j]->title[i] = new_title[i];
    }
    dataf->columns[j]->title[len_title]= '\0';
}

int search_val(CDATAFRAME* dataf, int val){
    int count = 0;
    for (int i=0; i<dataf->nbcols; i++){
        count += count_occ(dataf->columns[i], val);
    }
    return count;
}

int get_cell(CDATAFRAME* dataf, int i, int j){
    return dataf->columns[j]->value[i];
}

void replace_val(CDATAFRAME* dataf,int i, int j, int new_val){
    dataf->columns[j]->value[i]= new_val;
}
void disp_col_names(CDATAFRAME* dataf){
    printf("Names of the columns:\n");
    for (int i =0; i<dataf->nbcols; i++){
        printf("[%d] %s\n", i, dataf->columns[i]->title);
    }
}

*/
/*
//ANALYSIS FUNCTIONS
int display_nbrows(CDATAFRAME* dataf); */

int get_nbcols(CDATAFRAME *cdf){
    if (cdf == NULL || cdf->columns == NULL) {
        return 0;
    }

    int count = 0;
    COLUMN **columns = cdf->columns;
    while (*columns != NULL) {
        count++;
        columns++;
    }

    return count;
}

/*
int disp_cell_equal(CDATAFRAME* dataf, int x);
int disp_cell_great(CDATAFRAME* dataf, int x);
int disp_cell_lower(CDATAFRAME* dataf,  int x);  */