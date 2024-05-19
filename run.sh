#!/bin/sh

gcc main.c column.c cdataframe.c tools.c cmd.c cmd_cdf.c cmd_col.c cmd_row.c list.c -o maintest.exe
echo Compilation success. Please run :
echo ./maintest.exe
