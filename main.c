<<<<<<< HEAD

#include <stdio.h>
#include <stdlib.h>

int main()
{
    COLUMN *mycol = create_column("My column");

    return 0;

}
=======

=======
#include <stdio.h>
=======
#include <stdio.h>
#include <stdlib.h>
>>>>>>> d50816eaa3b32a36197cc5b3b2a867cbb23f5620
#include "column.h"
#include "cdataframe.h"
#include "list.h"

int main() {
    /*
    // Create a column of type STRING
    COLUMN *mycol = create_column(STRING, "Column 1");

    // Insert some string values into the column
    char str1[] = "apple";
    char str2[] = "banana";
    char str3[] = "orange";
    char str4[] = "apple";

    insert_value(mycol, str1);
    insert_value(mycol, str2);
    insert_value(mycol, str3);
    insert_value(mycol, str4);

    // Print the contents of the column
    printf("Contents of the column:\n");
    print_col(mycol);

    // Test the great_val function
    char *compare_str = "banana";
    int greater_count = great_val(mycol, compare_str);
    printf("Number of strings greater than '%s': %d\n", compare_str, greater_count);

    // Test the less_val function
    int less_count = less_val(mycol, compare_str);
    printf("Number of strings less than '%s': %d\n", compare_str, less_count);

    // Test the equal_val function
    int equal_count = equal_val(mycol, compare_str);
    printf("Number of strings equal to '%s': %d\n", compare_str, equal_count);

    // Free the memory allocated for the column
    delete_column(&mycol);

<<<<<<< HEAD

}
=======
    return 0;
}*/

ENUM_TYPE cdftype[] = {INT, CHAR, INT};
    CDATAFRAME *cdf = create_cdataframe(cdftype, 3);

    // Display the entire dataframe
    printf("Displaying the entire CDataframe:\n");
    display_cdf(cdf);

    // Delete the dataframe to free memory
    delete_cdataframe(&cdf);

    return 0;
}
    
>>>>>>> d50816eaa3b32a36197cc5b3b2a867cbb23f5620
