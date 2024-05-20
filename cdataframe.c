//Cdataframe project led by Isabelle and Ambre - File for the cdataframe functions - source file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdataframe.h"
#include "list.h"
#include "tools.h"

//Creating empty cdataframe
CDATAFRAME *create_expty_cdataframe() {
    CDATAFRAME *cdf = (CDATAFRAME *)lst_create_list();
    cdf->head = NULL;
    cdf->tail = NULL;
    return cdf;
}

//Creating the cdataframe in function of the type of data and the size we want
CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size) {
    CDATAFRAME *cdf = (CDATAFRAME *)lst_create_list();
    if (size == 1) {
        COLUMN *col = create_column(cdftype[0], "Untitled");
        lnode *node = lst_create_lnode(col);
        lst_insert_head(cdf, node);
    } else {
        for (int i = 0; i < size; i++) {   
            COLUMN *col = create_column(cdftype[i], "Untitled");
            lnode *node = lst_create_lnode(col);
            
            if (cdf->head == NULL) {
                lst_insert_head(cdf, node);
            }
            lst_insert_tail(cdf, node);
        }
    }
    return cdf;
}

//Delete the cdatafrme
void delete_cdataframe(CDATAFRAME *cdf) {
    lst_erase(cdf);
    cdf = create_expty_cdataframe();

//    free(cdf);
    printf("CDATAFRAME deleted");
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
                return;
            }
            node = (lnode *)get_next_node(cdf, node);
        }
    }
}

void delete_column2(CDATAFRAME *cdf, int pos) {
    cdf_log("delete_column");

    if (cdf != NULL) {
        int ncol = 1;
        lnode *node = (lnode *)get_first_node(cdf);
        node = (lnode *)get_first_node(cdf);
        while (node != NULL) {
            if (ncol == pos) {
                COLUMN *col = (COLUMN *)node->data;
                lst_delete_lnode(cdf, node);
                return;
            }
            node = (lnode *)get_next_node(cdf, node);
            ncol++;
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
void display_cdf_titles(CDATAFRAME *cdf) {
    cdf_log("display_cdf");

    if (cdf != NULL) {        
        int nb = 0;
        printf("Columns :\n");
        lnode *node = (lnode *)get_first_node(cdf);
        node = (lnode *)get_first_node(cdf);
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            printf("- %s\n", col->title);
            node = (lnode *)get_next_node(cdf, node);
            nb++;
        }
        printf("\ntotal : %d columns\n", nb);
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
void    run_cdf_test(CDATAFRAME *_cdf) {
    cdf_log("run_cdf_test()");

    ENUM_TYPE cdftype [] = {INT,CHAR,INT};
    // CDATAFRAME *cdf = create_cdataframe(cdftype, 3);
    _cdf = create_cdataframe(cdftype, 3);
    
    int i = 1;
    printf("\n\nINSERT DATA\n\n");
    lnode *node = (lnode *)get_first_node(_cdf);
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
        node = (lnode *)get_next_node(_cdf, node);
        i++;
    }

    cdf_print_line(_cdf, 0);
    printf("\n");

    char *r1[BUFFER_SIZE];
    r1[0] = "42", r1[1] = "43", r1[2] = "44", r1[3] = NULL; 
    char *r2[BUFFER_SIZE];
    r2[0] = "55", r2[1] = "56", r2[2] = "57", r2[3] = NULL; 
    row_add(_cdf, r1);
    cdf_print_line(_cdf, 0);

    row_add(_cdf, r2);
    cdf_print_line(_cdf, 0);

    csv_to_cdataframe(_cdf, "data.csv");
/*
    row_delete(_cdf, 1);
//    row_delete(_cdf, 5);
    cdf_print_line(_cdf, 0);

    col_add(_cdf, "INT", "Integer");
    col_add(_cdf, "STRING", "Str");
    cdf_print_line(_cdf, 0);

    
    edit(_cdf, "999", 4, 2);
//    edit(_cdf, "8", 1, 1);
*/
    cdf_print_line(_cdf, 0);
//    delete_column2(_cdf, 2);
//    cdf_print_line(_cdf, 0);

    //    display_cdf(CDF);
}

// Add row
void row_add(CDATAFRAME *_cdf, char **_data) {
    if (_cdf != NULL) {
        lnode *node = (lnode *)get_first_node(_cdf);
        int i = 0;
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            insert_value2(col, _data[i++]);
            node = (lnode *)get_next_node(_cdf, node);
        }
    }
}

// Delete row at line
void row_delete(CDATAFRAME *_cdf, int _line) {
    if (_cdf != NULL) {
        lnode *node = (lnode *)get_first_node(_cdf);
        int i = 0;
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;            
            remove_value(col, _line);
            node = (lnode *)get_next_node(_cdf, node);
        }
    }
}

//Taking the content of a 'csv' file to store its data in the cdataframe
void csv_to_cdataframe(CDATAFRAME *cdf, char *filename) {
    cdf_log("csv_to_cdataframe");

    FILE *file = fopen(filename, "r");

    if (file != NULL) {
        char str[BUFFER_SIZE];
        while(fgets(str, BUFFER_SIZE, file)) {
            char **data = malloc(100000);
            char* token = strtok(str, ",");
            int i = 0;
            while (token != NULL) {
                char *tmp = malloc(BUFFER_SIZE);
                stpcpy(tmp, token);
                // printf("%s - %s", str, tmp);
                data[i++] = tmp;
                token = (char *)strtok(NULL, ",");
            }
            row_add(cdf, data);
        }
        // Store the content of the file
        // Close the file
        fclose(file); 
    } 
}

void csv_from_cdataframe(CDATAFRAME *cdf, char *filename) {
    cdf_log("csv_from_cdataframe");

    FILE *file = fopen(filename, "r");

    if (file != NULL) {
        char str[BUFFER_SIZE];
        while(fgets(str, BUFFER_SIZE, file)) {
            char **data = malloc(100000);
            char* token = strtok(str, ",");
            int i = 0;
            while (token != NULL) {
                char *tmp = malloc(BUFFER_SIZE);
                stpcpy(tmp, token);
                // printf("%s - %s", str, tmp);
                data[i++] = tmp;
                token = (char *)strtok(NULL, ",");
            }
            row_add(cdf, data);
        }
        // Store the content of the file
        // Close the file
        fclose(file); 
    } 
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

// Display one line of the cdataframe if _line = 0 display all 
void cdf_print_line(CDATAFRAME *_cdf, int _line) {
    cdf_log("cdf_print_line()");

    if (_cdf != NULL && _cdf->tail != NULL) {
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
                        printf("|\t[%u] %s\t", col->index[pos], str);
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
//                        printf("|\t%s\t", str);
                        printf("|\t[%u] %s\t", col->index[i], str);
                    }
                    node = (lnode *)get_next_node(_cdf, node);
                }
                printf("|\n");
            }
        }
    }
}

// Returning the number of line in the cdataframe
int cdf_line_size(CDATAFRAME *_cdf) {
    cdf_log("cdf_line_size()");

    int nb = 0;
    if (_cdf != NULL) {
        lnode *node = (lnode *)get_first_node(_cdf);
        COLUMN *col = (COLUMN *)node->data;
        return col->size;
    }
    return nb;
}

int cdf_eq_test(CDATAFRAME *_cdf, float _val) {
    int res = 0;
    if (_cdf != NULL && _cdf->tail != NULL) {
        lnode *node = (lnode *)get_first_node(_cdf);
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            if (col->column_type == INT) {
                for (int i = 0; i < col->size; i++) {
                    int x = col->data[i]->int_value;
                    if (x == _val) {
                        res++;
                    }
                }
            }
            node = (lnode *)get_next_node(_cdf, node);
        }
        return res;
    }
}

int col_add(CDATAFRAME *_cdf, char *_type, char *_title) {
    ENUM_TYPE type = string_to_enumtype(_type);
    
    COLUMN *col = create_column(type, _title);
    for (int i = 0; i < cdf_line_size(_cdf); i++) {
        insert_value2(col, " ");
    }
    if (col != NULL) {
        lnode *node = lst_create_lnode(col);
        if (node != NULL) {
            if (_cdf->head == NULL) {
                lst_insert_head(_cdf, node);
            }
            lst_insert_tail(_cdf, node);
        }
    }            
}

int edit(CDATAFRAME *_cdf, void *_data, int _ncol, int _nline) {
    printf("edit");
    if (_cdf != NULL && _cdf->tail != NULL) {
        lnode *node = (lnode *)get_first_node(_cdf);
        int ncol = 1;
        _nline--;
        while (node != NULL) {
            if (ncol == _ncol) {
                COLUMN *col = (COLUMN *)node->data;
                for (int i = 0; i < col->size; i++) {
                    if (col->column_type == INT) {
                        // printf("\nint : %d\n", col->data[i]->int_value);
                        int tmp = atoi(_data);
                        if (col->index[i] == _nline) {
                            col->data[i]->int_value = tmp;
                        }
                    } else if (col->column_type == UINT) {
                        printf("\nuint : %i\n", col->data[i]->uint_value);
                        int tmp = atoi(_data);
                        if (col->index[i] == _nline) {
                            col->data[i]->uint_value = tmp;
                        }
                    } else if (col->column_type == FLOAT) {
                        printf("\nfloat : %f\n", col->data[i]->float_value);
                        float tmp = atof(_data);
                        if (col->index[i] == _nline) {
                            col->data[i]->float_value = tmp;
                        }
                    } else if (col->column_type == DOUBLE) {
                        printf("\ndouble : %f\n", col->data[i]->double_value);
                        double tmp = atof(_data);
                        if (col->index[i] == _nline) {
                            col->data[i]->double_value = tmp;
                        }
                    } else if (col->column_type == CHAR) {
                        if (col->index[i] == _nline) {
                            printf("\nchar : %c\n", col->data[i]->char_value);
                            char *str=(char *)_data;
                            col->data[i]->char_value = str[0];
                        }
                    } else {
                        printf("\nstring : %s\n", col->data[i]->string_value);
                        if (col->index[i] == _nline) {
                            char *str=(char *)_data;
                            col->data[i]->string_value = str;
                        }
                    }
                }
            }
            node = (lnode *)get_next_node(_cdf, node);
            ncol++;
        }
    }
    return 0;
}


int cdf_search(CDATAFRAME *_cdf, void *_data) {
    if (_cdf != NULL && _cdf->tail != NULL) {
        lnode *node = (lnode *)get_first_node(_cdf);
        int nb = 0;
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            for (int i = 0; i < col->size; i++) {
                if (col->column_type == INT) {
//                    printf("\nint : %d\n", col->data[i]->int_value);
                    int tmp = atoi(_data);
                    if (col->data[i]->int_value == tmp) {
                        nb++;
                    }
                } else if (col->column_type == UINT) {
                    printf("\nuint : %i\n", col->data[i]->uint_value);
                    int tmp = atoi(_data);
                    if (col->data[i]->uint_value == tmp) {
                        nb++;
                    }
                } else if (col->column_type == FLOAT) {
                    printf("\nfloat : %f\n", col->data[i]->float_value);
                    float tmp = atof(_data);
                    if (col->data[i]->float_value == tmp) {
                        nb++;
                    }
                } else if (col->column_type == DOUBLE) {
                    printf("\ndouble : %f\n", col->data[i]->double_value);
                    double tmp = atof(_data);
                    if (col->data[i]->double_value == tmp) {
                        nb++;
                    }
                } else if (col->column_type == CHAR) {
                    char *str=(char *)_data;
                    if (col->data[i]->char_value == str[0]) {
                        nb++;
                    }
                } else {
                    char *str=(char *)_data;
                    if (strcmp(col->data[i]->string_value,str) == 0) {
                        nb++;
                    }
                }
            }
            node = (lnode *)get_next_node(_cdf, node);
        }
        printf("find : %d", nb);
    }
    return 0;
}

int cdf_eq(CDATAFRAME *_cdf, void *_data) {
    if (_cdf != NULL && _cdf->tail != NULL) {
        lnode *node = (lnode *)get_first_node(_cdf);
        int nb = 0;
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            for (int i = 0; i < col->size; i++) {
                if (col->column_type == INT) {
                    int tmp = atoi(_data);
                    if (col->data[i]->int_value == tmp) {
                        nb++;
                    }
                } else if (col->column_type == UINT) {
                    int tmp = atoi(_data);
                    if (col->data[i]->uint_value == tmp) {
                        nb++;
                    }
                } else if (col->column_type == FLOAT) {
                    float tmp = atof(_data);
                    if (col->data[i]->float_value == tmp) {
                        nb++;
                    }
                } else if (col->column_type == DOUBLE) {
                    double tmp = atof(_data);
                    if (col->data[i]->double_value == tmp) {
                        nb++;
                    }
                } else if (col->column_type == CHAR) {
                    char *str=(char *)_data;
                    if (col->data[i]->char_value == str[0]) {
                        nb++;
                    }
                } else {
                    char *str=(char *)_data;
                    if (strcmp(col->data[i]->string_value,str) == 0) {
                        nb++;
                    }
                }
            }
            node = (lnode *)get_next_node(_cdf, node);
        }
        printf("eq : %d", nb);
    }
    return 0;
}

int cdf_gt(CDATAFRAME *_cdf, void *_data) {
    if (_cdf != NULL && _cdf->tail != NULL) {
        lnode *node = (lnode *)get_first_node(_cdf);
        int nb = 0;
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            for (int i = 0; i < col->size; i++) {
                if (col->column_type == INT) {
                    int tmp = atoi(_data);
                    if (col->data[i]->int_value > tmp) {
                        nb++;
                    }
                } else if (col->column_type == UINT) {
                    int tmp = atoi(_data);
                    if (col->data[i]->uint_value > tmp) {
                        nb++;
                    }
                } else if (col->column_type == FLOAT) {
                    float tmp = atof(_data);
                    if (col->data[i]->float_value > tmp) {
                        nb++;
                    }
                } else if (col->column_type == DOUBLE) {
                    double tmp = atof(_data);
                    if (col->data[i]->double_value > tmp) {
                        nb++;
                    }
                }
            }
            node = (lnode *)get_next_node(_cdf, node);
        }
        printf("gt : %d", nb);
    }
    return 0;
}

int cdf_lt(CDATAFRAME *_cdf, void *_data) {
    if (_cdf != NULL && _cdf->tail != NULL) {
        lnode *node = (lnode *)get_first_node(_cdf);
        int nb = 0;
        while (node != NULL) {
            COLUMN *col = (COLUMN *)node->data;
            for (int i = 0; i < col->size; i++) {
                if (col->column_type == INT) {
                    int tmp = atoi(_data);
                    if (col->data[i]->int_value < tmp) {
                        nb++;
                    }
                } else if (col->column_type == UINT) {
                    int tmp = atoi(_data);
                    if (col->data[i]->uint_value < tmp) {
                        nb++;
                    }
                } else if (col->column_type == FLOAT) {
                    float tmp = atof(_data);
                    if (col->data[i]->float_value < tmp) {
                        nb++;
                    }
                } else if (col->column_type == DOUBLE) {
                    double tmp = atof(_data);
                    if (col->data[i]->double_value < tmp) {
                        nb++;
                    }
                }
            }
            node = (lnode *)get_next_node(_cdf, node);
        }
        printf("lt : %d", nb);
    }
    return 0;
}

