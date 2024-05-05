#include <stdio.h>
#include <stdlib.h>
#include "column.h"

int main() {
    // Create a column of type CHAR
    COLUMN *mycol = create_column(CHAR, "Column 1");
    
    // Insert values into the column
    char a = 'A', c = 'C';
    insert_value(mycol, &a);
    insert_value(mycol, NULL);
    insert_value(mycol, &c);
    
    // Print the contents of the column
    print_col(mycol);
    
    // Free the memory allocated for the column
 //   delete_column(&mycol);
    
    return 0;
}
