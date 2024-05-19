//Cdataframe project led by Isabelle and Ambre - File for the cdataframe functions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdataframe.h"
#include "list.h"
#include "tools.h"

#define TITLE_MAX_LENGTH 50

//Creating the cdataframe in function of the type of data and the size we want
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size) {
    CDATAFRAME *cdf = (CDATAFRAME *)lst_create_list();
    for (int i = 0; i < size; i++) {
        printf("NODE : %i", cdftype[i]);
    
        COLUMN *col = create_column(cdftype[i], "Nouveau");
        lnode *node = lst_create_lnode(col);
        
        if (cdf->head == NULL) {
            lst_insert_head(cdf, node);
        }
        lst_insert_tail(cdf, node);
    }
    return cdf;
}

//Delete the cdatafrme
void delete_cdataframe(CDATAFRAME **cdf) {
    free(cdf);
}

//Delete a coulumn in the cdataframe
void delete_column(CDATAFRAME *cdf, char *col_name) {
    cdf_log("delete_column");
    if (cdf != NULL) {        
        lnode *node = (lnode *)get_first_node(cdf);
        node = (lnode *)get_first_node(cdf);
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            if (strcmp(col_name, col->title) == 0) {
                lst_delete_lnode(cdf, node);
                cdf_log("lst_delete_lnode");
                return;
            }
            node = (lnode *)get_next_node(cdf, node);
        }
    }
}

//Display the cdataframe
void display_cdf(CDATAFRAME *cdf) {
    cdf_log("display_cdf");

    if (cdf != NULL) {        
        lnode *node = (lnode *)get_first_node(cdf);
        node = (lnode *)get_first_node(cdf);
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            print_col(col);
            node = (lnode *)get_next_node(cdf, node);
        }
    }
}

//Display the titles of cdataframe's columns
char **display_cdf_titles(CDATAFRAME *cdf) {
    cdf_log("display_cdf");
    char **titles;
    if (cdf != NULL) {        
        lnode *node = (lnode *)get_first_node(cdf);
        node = (lnode *)get_first_node(cdf);
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            print_col(col);
            node = (lnode *)get_next_node(cdf, node);
        }
    }
}

//Returning the size of the cdataframe's columns
int get_cdataframe_cols_size(CDATAFRAME *cdf) {
    cdf_log("get_cdataframe_cols_size()");
    int count = 0;

    if (cdf != NULL) {        
        lnode *node = (lnode *)get_first_node(cdf);
        node = (lnode *)get_first_node(cdf);
        while (node != NULL) {
            node = (lnode *)get_next_node(cdf, node);
            count++;
        }
    }
    return count;
}

//Function to test all commands and other functions linked to the cdtaframe
void    run_cdf_test() {
    cdf_log("run_cdf_test()");

    ENUM_TYPE cdftype [] = {INT,CHAR,INT};
    // CDATAFRAME *cdf = create_cdataframe(cdftype, 3);
    CDF = create_cdataframe(cdftype, 3);
    
    int i = 1;
    printf("\n\nINSERT DATA\n\n");
    lnode *node = (lnode *)get_first_node(CDF);
    while (node != NULL) {
        COLUMN *col = (COLUMN *)node->data;
        if (i == 1) {
            int v11 = 11, v12 = -12, v13 = 13;
            printf("INSERT col[%i] load : %i, %i, %i \n", i, v11, v12, v13);
            col->title = "col1";
            insert_value(col, &v11);
            insert_value(col, &v12);
            insert_value(col, &v13);
        } else if (i == 2) {
            char v21 = 'a', v22 = 'b', v23 = 'z';
            printf("INSERT col[%i] load : %c, %c, %c \n", i, v21, v22, v23);
            col->title = "col2";
            insert_value(col, &v21);
            insert_value(col, &v22);
            insert_value(col, &v23);
        } else if (i == 3) {
            int v31 = 3333333, v32 = -987654321, v33 = 0;
            printf("INSERT col[%i] load : %i, %i, %i \n", i, v31, v32, v33);
            col->title = "col3";
            insert_value(col, &v31);
            insert_value(col, &v32);
            insert_value(col, &v33);
        }
        node = (lnode *)get_next_node(CDF, node);
        i++;
    }

/*
    printf("\n\nDISPLAY\n");
    display_cdf(cdf);

    printf("\n\nDELETE col2\n");
    delete_column(cdf, "col2");
    
    printf("\n\nDISPLAY\n");    
    display_cdf(cdf);
    cdf_print_line(2);

*/
    cdf_print_line(CDF, 0);
    printf("\n");

    cdf_print_line(CDF, 3);
    printf("\n");

    cdf_col_title(CDF, 2, "XXX");
    printf("\n");

    cdf_print_line(CDF, 1);
    printf("\n");

    cdf_print_line(CDF, 2);
    printf("\n");

    cdf_print_line(CDF, 4);
    printf("\n");

    //    display_cdf(CDF);
}

//Taking the content of a 'csv' file to store its data in the cdataframe
void csv_to_cdataframe(CDATAFRAME *cdf, char *filename) {
    cdf_log("csv_to_cdataframe");

    FILE *fptr;
    // Open a file in read mode
    fptr = fopen("data.csv", "r");
    // Store the content of the file
    char myString[100];
    while(fgets(myString, 100, fptr)) {
        printf("%s", myString);
    }
    // Close the file
    fclose(fptr); 
}

//Define a title for a specific column in the cdataframe
void cdf_col_title(CDATAFRAME *_cdf, unsigned int _pos, char *_title) {
    if (_cdf != NULL) {
        int pos = _pos - 1;
        int i = 0;
        lnode *node = (lnode *)get_first_node(_cdf);
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            if (i == pos) {
                col->title = _title;
                return;
            }        
            node = (lnode *)get_next_node(_cdf, node);
            i++;
        }
    }
}

//Display one or several lines of the cdataframe
void cdf_print_line(CDATAFRAME *_cdf, int _line) {
    cdf_log("cdf_print_line()");

    if (_cdf != NULL) {

        lnode *node = (lnode *)get_first_node(_cdf);
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            printf("|\t%s\t", col->title);
            node = (lnode *)get_next_node(_cdf, node);
        }
        printf("|\n");

        if (_line != 0){
            int pos = _line - 1;
            int col_pos = 0;
            printf("|");
            lnode *node = (lnode *)get_first_node(_cdf);
            while (node != NULL) {
                COLUMN *col = (COLUMN *)node->data;
                if (col != NULL) {
                    if (col->index[pos] == pos) {
                        char str[BUFFER_SIZE];
                        convert_value(col, pos, str, BUFFER_SIZE);
                        printf("|\t%s\t", str);
                    }
                }
                node = (lnode *)get_next_node(_cdf, node);
                col_pos++;
            }
            printf("|\n");
        } else {
            lnode *node = (lnode *)get_first_node(_cdf);
            COLUMN *col = (COLUMN *)node->data;
            for (int i = 0; i < col->size; i++) {
                node = (lnode *)get_first_node(_cdf);
                while (node != NULL) {
                    col = (COLUMN *)node->data;
                    if (col != NULL) {
                        char str[BUFFER_SIZE];
                        convert_value(col, i, str, BUFFER_SIZE);
                        printf("|\t%s\t", str);
                    }
                    node = (lnode *)get_next_node(_cdf, node);
                }
            printf("|\n");
            }
        }
    }
}

//Returning the size of a line in the cdataframe
int cdf_line_size(CDATAFRAME *_cdf) {
    if (_cdf != NULL) {
        lnode *node = (lnode *)get_first_node(_cdf);
        COLUMN *col = (COLUMN *)node->data;        
        return col->size;
    }
    return 0;
}

/*
void print_col_data_by_index(COLUMN *_col, unsigned int _index) {
    cdf_log("print_col_data_by_index()");
    if (_col != NULL && _col->column_type != NULLVAL) {
        convert_value();
        print_data_by_enum(_col->column_type, _col->data[_index]);
        printf("\t|\t");
    }
}
char *print_data_by_enum(ENUM_TYPE _type, void *_data) {
    if (_data != NULL && _type != NULLVAL) {
        if (_type == INT) {
            cdf_log("INT");
            printf("%i", _data);
        } else if (_type == UINT) {
            cdf_log("UINT");
            printf("%u", _data);
        } else if (_type == FLOAT) {
            cdf_log("FLOAT");
            printf("%f", _data);
        } else if (_type == DOUBLE) {
            cdf_log("DOUBLE");
            printf("%f", _data);
        } else if (_type == CHAR) {
            cdf_log("CHAR");
            printf("%c", _data);
        } else if (_type == STRING) {
            cdf_log("STRING");
            printf("%s", _data);
        } else if (_type == STRUCTURE) {
            cdf_log("STRUCTURE");
            printf("TODO", _data);
        } 
    }
}

*/


/*

    if (_cdf != null) {
        lnode *node = (lnode *)get_first_node(_cdf);
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;        
            node = (lnode *)get_next_node(_cdf, node);
        }
    }


*/