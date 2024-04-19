#include <stdio.h>
#include "column.h"

int main() {
    // Create a column
    COLUMN* mycol = create_column("My column");

    // Insert values into the column
    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);

    // Print the content of the column
    print_col(mycol);

    // Test other functions
    int value_to_find = 44;
    printf("Number of occurrences of %d: %d\n", value_to_find, count_occ(mycol, value_to_find));

    int position_to_get = 1;
    printf("Value at position %d: %d\n", position_to_get, pos_val(mycol, position_to_get));

    int x = 20;
    printf("Number of values greater than %d: %d\n", x, great_val(mycol, x));
    printf("Number of values less than %d: %d\n", x, less_val(mycol, x));
    printf("Number of values equal to %d: %d\n", x, equal_val(mycol, x));

    // Delete the column to free memory
    delete_column(&mycol);

}