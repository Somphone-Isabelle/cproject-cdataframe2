#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"
#include "column.h"

//FILLING FUNCTIONS
CDATAFRAME* create_cdf(int nbcols, char** title){
    CDATAFRAME* dataf = (CDATAFRAME*)malloc(sizeof(CDATAFRAME));
   /* if (dataf == NULL){
        printf("ERROR\n");
        exit(1);
    }*/ 
    dataf->columns=(COLUMN**)malloc(nbcols * sizeof(COLUMN*));
    dataf-> nbrows = 0;
    dataf-> nbcols = nbcols;
    for (int i = 0; i<nbcols;i++){
        dataf->columns[i]= create_column(title[i]);
    }
    return dataf;
}
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

//DISPLAYING FUNCTIONS
void display_df(CDATAFRAME* dataf){
    for (int i = 0; i<dataf->nbcols;i++){
        printf("%s\t", dataf->columns[i]->title);
    }
    printf("\n");
    for (int i = 0; i<dataf->nbrows;i++){
        for (int j = 0; j<dataf->nbcols; j++){
            printf("%d\t", dataf->columns[j]->value[i]);
        }
        printf("\n");
    }
}
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

/*
//OPERATIONS FUNCTIONS
void add_row(CDATAFRAME* dataf, int* vals);
void del_row(CDATAFRAME* dataf, int i); //i = index
void add_col(CDATAFRAME* dataf, COLUMN* column);
void del_col(CDATAFRAME* dataf, int i);
void rename_col(CDATAFRAME* dataf, int j, char* new_title);
int search_val(CDATAFRAME* dataf, int val);
int get_cell(CDATAFRAME* dataf, int i, int j);
void replace_val(CDATAFRAME* dataf,int i, int j)
void disp_col_names(CDATAFRAME* dataf);

//ANALYSIS FUNCTIONS
int display_nbrows(CDATAFRAME* dataf);
int display_nbcols(CDATAFRAME* dataf);
int disp_cell_equal(CDATAFRAME* dataf, int x);
int disp_cell_great(CDATAFRAME* dataf, int x);
int disp_cell_lower(CDATAFRAME* dataf,  int x);   */