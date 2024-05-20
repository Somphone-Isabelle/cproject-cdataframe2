# cproject-cdataframe2
test 13/05/2024 19h05

'CDataframe' project for EFREI Algorithmmics and Data Structure Course

SOMPHONE Isabelle - BERDERY Ambre test

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

Thank you for reading ! :


Liste des commandes :

Cdataframe
----------------------------------------
cdf_new : Create an empty cDataframe
cdf_init : Remplissage du CDataframe à partir de saisies utilisateurs et remplissage en dur du CDataframe
cdf_display : Display the whole cDataframe
cdf_search : Vérifier l’existence d’une valeur (recherche) dans le CDataframe
cdf_edit : Accéder/remplacer la valeur se trouvant dans une cellule du CDataframe en utilisant son numéro de ligne et de colonne
cdf_lines : Afficher le nombre de lignes
cdf_colomns : Afficher le nombre de colonnes
cdf_eq : Nombre de cellules égales à x (x donné en paramètre)
cdf_gt : Nombre de cellules contenant une valeur supérieure à x (x donné en paramètre)
cdf_lt : Nombre de cellules contenant une valeur inférieure à x(x donné en paramètre)
csv_export :
csv_import : 

Column
----------------------------------------
col_display : Afficher une partie des colonnes du CDataframe selon une limite fournie par l’utilisateur
col_add : Ajouter une colonne au CDataframe
col_delete : Supprimer une colonne du CDataframe
col_title : Renommer le titre d’une colonne du CDataframe
col_sort : 

Row
----------------------------------------
row_display : Afficher une partie des lignes du CDataframe selon une limite fournie par l’utilisateur
row_add : Ajouter une ligne de valeurs au CDataframe
row_delete : Supprimer une ligne de valeurs du CDataframe
