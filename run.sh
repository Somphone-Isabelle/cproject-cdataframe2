#!/bin/sh

gcc main.c column.c cdataframe.c tools.c list.c -o maintest.exe
echo Compilation success. Please run :
echo ./maintest.exe
