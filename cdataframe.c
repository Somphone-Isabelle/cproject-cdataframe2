#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdataframe.h"
#include "list.h"
#include "tools.h"

#define TITLE_MAX_LENGTH 50

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

void delete_cdataframe(CDATAFRAME **cdf) {
    /*
        if (*cdf != NULL) {
        for (int i = 0; i < get_nbcols(*cdf); i++) {
            del_column(&((*cdf)->columns[i]));
        }
        free((*cdf)->columns);
        lst_delete_list((*cdf)->rows);
        free(*cdf);
        *cdf = NULL;
    }
    */
}

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

int get_nbcols(CDATAFRAME *cdf){
    cdf_log("get_nbcols");
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

void    run_cdf_test() {
    ENUM_TYPE cdftype [] = {INT,CHAR,INT};
    CDATAFRAME *cdf = create_cdataframe(cdftype, 3);
    
    int i = 1;
    printf("\n\n");
    lnode *node = (lnode *)get_first_node(cdf);
    while (node != NULL) {
        COLUMN *col = (COLUMN *)node->data;
        if (i == 1) {
            int v11 = 11, v12 = -12, v13 = 13;
            printf("col[%i] load : %i, %i, %i \n", i, v11, v12, v13);
            insert_value(col, &v11);
            insert_value(col, &v12);
            insert_value(col, &v13);
        } else if (i == 2) {
            char v21 = 'a', v22 = 'b', v23 = 'z';
            printf("col[%i] load : %c, %c, %c \n", i, v21, v22, v23);
            insert_value(col, &v21);
            insert_value(col, &v22);
            insert_value(col, &v23);
        } else if (i == 3) {
            int v31 = 3333333, v32 = -987654321, v33 = 0;
            printf("col[%i] load : %i, %i, %i \n", i, v31, v32, v33);
            insert_value(col, &v31);
            insert_value(col, &v32);
            insert_value(col, &v33);
        }
        node = (lnode *)get_next_node(cdf, node);
        i++;
    }

    printf("\n\n");
    display_cdf(cdf);
}