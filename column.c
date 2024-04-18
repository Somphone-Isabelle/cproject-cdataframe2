#include "column.h"

typedef struct {
    char *title;
    int *data;
} COLUMN;
/**
* Create a column
* @param1 : Column title
* @return : Pointer to created column
*/

COLUMN *create_column(char *title) 
{
    COLUMN *newcol = (COLUMN*) malloc(sizeof(COLUMN));
    newcol->title = (char *)malloc(strlen(title) + 1);
}





/*int insert_value(COLUMN* col, int value);
je vais faire les 2 dernieres et toi les 2 premieres
void delete_column(COLUMN **col);
void print_col(COLUMN* col);*/

