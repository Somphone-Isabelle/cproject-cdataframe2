//Cdataframe project led by Isabelle and Ambre - Commands functions for the cdataframe - header file

#ifndef CMD_H
#define CMD_H

extern CDATAFRAME   *CDF;

int cmd_test(Command* cmd);

int cmd_csv_import(Command* cmd);

int cmd_csv_export(Command* cmd);

int cmd_search(Command* cmd);

void free_cmd(Command* cmd);

int read_exec_command(Command* cmd);

int cmd_exit(Command* cmd);

int cmd_error(char *msg);

int cmd_clear(Command* cmd);

int cmd_help(Command* cmd);

void cmd_run();

#endif 