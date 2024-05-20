# cproject-cdataframe2

'CDataframe' project for EFREI Algorithmmics and Data Structure Course

SOMPHONE Isabelle - BERDERY Ambre 

For windows user:
    Install Cygwin64 Terminal in order to compile and execute the code.
    -> Go to the finder of the project then:
        To compile it:
            -$ ./run.sh
        To execute it:
            -$ ./cdf.exe

For mac user:
    Go to your terminal.
    -> Go the finder of the project then:
        To compile it:
            -$ ./run.sh
        To execute it:
            -$ ./cdf.exe


Git Repository url: https://github.com/Somphone-Isabelle/cproject-cdataframe2.git

 The goal of this project is to create a CDataFrame.
For an intermediate filling, we choose to focus on the basics functions just for the integers type in order to be comfortable and comprehend the subject in deep.
So in order to do, we first create an column.c and column.h file that allow us to manage the functions around the column thanks to the structure of the column given in the file project.

Then next, we created a cdataframe.c and a cdataframe.h that will have all the main functions that are the fondation of the project and that will be use for the commands that will be called in main.c with all the cmd files.

We first started with the integer type only then we declined the functions to every types(string, char, float, etc).
We tried with arrays but it turned out that we switched in SLL.
To read the code, here is the order of the files:
- README.txt
- run.sh
- main.c
- tools.c
- cmd.c
- cmd_cdf.c
- cmd_col.c
- cmd_row.c
- list.c
- cdataframe.c
- column.c 

List of the commands :

Cdataframe
----------------------------------------
cdf_new : Create an empty cDataframe -> type : 'cdf_new TYPE TYPE' with TYPE being (INT, CHAR, STRING, ...)
cdf_init : Filling from the users inputs and hard fillig of the CDataframe -> type : 'cdf_init 
cdf_display : Display the whole cDataframe -> type : 'cdf_display'
cdf_search : Verify the existence of a value (search) in the CDataframe -> type 'cdf_search data' 
cdf_edit : Access/Replace a value in a cell of the CDataframe using its positon -> type 'cdf_edit data posy posy'
cdf_lines : Display the number of lines -> type 'cdf_lines'
cdf_colomns : Display the number of columns -> type 'cdf_colomns'
cdf_eq : Number of cells containing a value equal to x (x given in parameter) -> type 'cdf_eq val'
cdf_gt : Number of cells containing a value greater than x(x given in parameter) -> type 'cdf_gt val'
cdf_lt : Number of cells containing a value less than x(x given in parameter) -> type 'cdf_lt val' 
csv_export : Import data from csv file -> type 'csv_import data.csv
csv_import : Export date to csv file -> type 'csv_export out.csv

Column
----------------------------------------
col_display : Display a part of the columns of the CDataframe according to a limit defined by the user -> type 'col_display'
col_add : Add a column to the CDataframe -> type 'col_add TYPE title' 
col_delete : Delete a column from the CDataframe -> type 'col_delete posx'
col_title : Rename the title of a column of the CDataframe -> type 'col_title title new_title'
col_sort : Sorting the columns of the CDataframe -> type 'col_sort asc/desc' 

Row
----------------------------------------
row_display : Display a part of the lines of the CDataframe according to a limit defined by the user -> type 'row_display'
row_add : Add a line of values to the CDataframe -> type 'row_add val1 val2...'
row_delete : Delete a line of values to the CDataframe -> type 'row_delete pos'


Thank you for reading!
