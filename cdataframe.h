#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include "column.h"
#include "list.h"

typedef struct{
    COLUMN** columns;
    int nbrows;
    list *rows;
}CDATAFRAME;

//BASICS
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);
void delete_cdataframe(CDATAFRAME **cdf);

//FILLING
CDATAFRAME *create_empty_cdf();
CDATAFRAME *user_imput_df(CDATAFRAME *cdf);
CDATAFRAME *hardfill_df(CDATAFRAME *cdf, void **data, int rows, int cols);

//DISPLAYING FUNCTIONS
void display_cdf(CDATAFRAME* cdf);
void disp_part_row(CDATAFRAME* dataf, int lim);
void disp_part_col(CDATAFRAME* dataf, int lim);


//OPERATIONS FUNCTIONS
void add_row(CDATAFRAME *cdf, void **new_row, int nbcols);
void del_row(CDATAFRAME *cdf, int i); //i = row index
void add_col(CDATAFRAME *dataf, COLUMN* column);
void delete_column(CDATAFRAME *cdf, char *col_name);
void rename_column_in_cdataframe(CDATAFRAME *cdf, char *old_name, char *new_name);
int search_val(CDATAFRAME *cdf, char *old_name, char *new_name);
void *replace_val(CDATAFRAME *cdf, int row_index, int col_index, void *new_value);
void display_column_names(CDATAFRAME *cdf);

//ANALYSIS FUNCTIONS

int get_nbrows(CDATAFRAME* dataf);
int get_nbrows(CDATAFRAME *cdf);
int disp_cell_equal(CDATAFRAME* cdf, void *x);
int disp_cell_great(CDATAFRAME* cdf, void *x);
int disp_cell_lower(CDATAFRAME* cdf, void *x);

#endif 