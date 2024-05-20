#ifndef CDATAFRAME_H
#define CDATAFRAME_H

#include "column.h"
#include "list.h"

typedef list CDATAFRAME;

//BASICS
CDATAFRAME *create_expty_cdataframe();
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size); //done
void delete_cdataframe(CDATAFRAME *cdf);
void delete_column(CDATAFRAME *cdf, char *col_name);
void delete_column2(CDATAFRAME *cdf, int pos);
int get_cdataframe_cols_size(CDATAFRAME *cdf);
CDATAFRAME* load_from_csv(char *file_name, ENUM_TYPE *dftype, int size);

void run_cdf_test();

void display_cdf(CDATAFRAME* cdf);

int get_nbcols(CDATAFRAME *cdf);

void cdf_print_line(CDATAFRAME *_cdf, int _line);
void cdf_col_title(CDATAFRAME *_cdf, unsigned int _pos, char *_title);
int cdf_line_size(CDATAFRAME *_cdf);
void display_cdf_titles(CDATAFRAME *cdf);
void csv_to_cdataframe(CDATAFRAME *cdf, char *filename);
int cdf_eq_test(CDATAFRAME *_cdf, float _val);
void row_add(CDATAFRAME *cdf, char **data);
void row_delete(CDATAFRAME *_cdf, int _line);
int col_add(CDATAFRAME *_cdf, char *_type, char *_title);
int edit(CDATAFRAME *_cdf, void *_data, int _ncol, int _nline);
int cdf_search(CDATAFRAME *_cdf, void *_data);
int cdf_eq(CDATAFRAME *_cdf, void *_data);
int cdf_gt(CDATAFRAME *_cdf, void *_data);
int cdf_lt(CDATAFRAME *_cdf, void *_data);

#endif 