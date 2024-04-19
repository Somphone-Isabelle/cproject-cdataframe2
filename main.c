#include <stdio.h>
#include <stdlib.h>
#include "cdataframe.h"

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Fill the CDATAFRAME\n");
    printf("2. Add a row\n");
    printf("3. Delete a row\n");
    printf("4. Add a column\n");
    printf("5. Delete a column\n");
    printf("6. Rename the title of a column\n");
    printf("7. Check the existence of a value\n");
    printf("8. Access/replace the value in a cell\n");
    printf("9. Display column names\n");
    printf("10. Display number of rows\n");
    printf("11. Display number of columns\n");
    printf("12. Display number of cells equal to x\n");
    printf("13. Display number of cells containing a value greater than x\n");
    printf("14. Display number of cells containing a value less than x\n");
    printf("15. Exit\n");
}
