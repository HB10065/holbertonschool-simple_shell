#ifndef MYSHELL_H
#define MYSHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

void printppid(void);
char **splitstr(char *str);
void prompt(void);
char *read_input(void);
void execute_command(char *command);

#endif
