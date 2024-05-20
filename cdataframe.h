#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"
#include "list.h"

typedef list CDATAFRAME;

//BASICS
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size); //done
void delete_cdataframe(CDATAFRAME *cdf);
void delete_column(CDATAFRAME *cdf, char *col_name);
int get_cdataframe_cols_size(CDATAFRAME *cdf);
CDATAFRAME* load_from_csv(char *file_name, ENUM_TYPE *dftype, int size);

void run_cdf_test();

void display_cdf(CDATAFRAME* cdf);

int get_nbcols(CDATAFRAME *cdf);

void cdf_print_line(CDATAFRAME *_cdf, int _line);
void cdf_col_title(CDATAFRAME *_cdf, unsigned int _pos, char *_title);
int cdf_line_size(CDATAFRAME *_cdf);
void display_cdf_titles(CDATAFRAME *cdf);

#endif 