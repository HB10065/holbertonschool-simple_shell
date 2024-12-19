#ifndef MYSHELL_H
#define MYSHELL_H
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void printppid(void);
char **splitstr(char *str);

#endif
