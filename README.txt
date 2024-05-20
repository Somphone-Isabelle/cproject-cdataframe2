# cproject-cdataframe2

'CDataframe' project for EFREI Algorithmmics and Data Structure Course

SOMPHONE Isabelle - BERDERY Ambre 

For windows user:
    Install Cygwin64 Terminal in order to compile and execute the code.
    Go to the finder of your project then:
        To compile it:
            -$ gcc *.c -o main.exe
        To execute it:
            -$ ./main.exe


Git Repository url: https://github.com/Somphone-Isabelle/cproject-cdataframe2.git

The goal of this project is to create a CDataFrame.
For an intermediate filling, we choose to focus on the basics functions in order to be comfortable and comprehend the subject in deep.
So in order to do, we first create an colomn.c and colomn.h file that allow us to manage the functions around the column thanks to the structure of the column.

Then next, we created a cdataframe.c and a cdataframe.h that will have all the main functions that are the fondation of the project and that will be use for the functionalities that will called in main.c thanks to a menu.

We first started with the integer type only then we declined the functions to every types(string, char, float, etc).
We tried with arrays but it turned out that we switched in SLL.
To read the code, here is the order of the files:
- main.c
- tools.c
- all the commands (cmd) files
- list.c
- cdataframee.c
- column.c


List of the commands :

Cdataframe
----------------------------------------
cdf_new : Create an empty cDataframe
cdf_init : Filling of the CDataframe from the users inputs and hard fillig of the CDataframe
cdf_display : Display the whole cDataframe
cdf_search : Verify this existence of a value (search) in the CDataframe
cdf_edit : Access/Replace a the value in a cell of the CDataframe using its number of line and column
cdf_lines : Display the number of lines
cdf_colomns : Display the number of columns
cdf_eq :Number of cells containing a value equal to x (x given in parameter)
cdf_gt : Number of cells containing a value greater than x(x given in parameter)
cdf_lt : Number of cells containing a value less than x(x given in parameter)
csv_export :
csv_import : 

Column
----------------------------------------
col_display : Display a part of the columns of the CDataframe according to a limit defined by the user
col_add : Add a column to the CDataframe
col_delete : Delete a column from the CDataframe
col_title : Rename the title of a column of the CDataframe
col_sort : 

Row
----------------------------------------
row_display : Display a part of the lines of the CDataframe according to a limit defined by the user
row_add : Add a line of values to the CDataframe
row_delete : Delete a line of values to the CDataframe


Thank you for reading!
