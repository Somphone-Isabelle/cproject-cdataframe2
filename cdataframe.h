#ifdef CDATAFRAME_H
#define CDATAFRA%E_H
#include "column.h"

typedef struct{
    COLUMN** columns;
    int nbrows;
    int nbcols;
}CDATAFRAME;

//FILLING FUNCTIONS
CDATAFRAME* create_cdf(int nbcols);
void user_imput(CDATAFRAME* dataf);
void hardfill_df(CDATAFRAME* dataf);

//DISPLAYING FUNCTIONS
void display_df(CDATAFRAME* dataf);
void disp_part_row(CDATAFRAME* dataf, int start, int end);
void disp_part_col(CDATAFRAME* dataf, int start, int end);

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
int disp_cell_lower(CDATAFRAME* dataf, int x);

#enfif 