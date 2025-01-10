#ifndef MYSHELL_H
#define MYSHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <strings.h>

char **splitstr(char *str);
char *env(void);
char *path(char *str);
void freestr(char **str);

#endif
