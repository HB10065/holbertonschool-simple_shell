#include "myshell.h"

/**
 * lslfunc - ls con la flag -l
 */
void lslfunc(void)
{
        char *argv[] = {"/bin/ls", "-l", "./", NULL};
        int status;
        pid_t pid, pid2;

        pid = getpid();

        pid2 = fork();

        if (pid != getpid())
        {
                execve("/bin/ls", argv, NULL);
        }

        wait(&status);
}

/**
 * lsfunction - ls
 */
void lsfunction(void)
{
        char *argv[] = {"/bin/ls", "./", NULL};
        int status;
        pid_t pid, pid2;

        pid = getpid();

        pid2 = fork();

        if (pid != getpid())
        {
                execve("/bin/ls", argv, NULL);
        }

        wait(&status);
}

void lsfunc(char** str)
{
	if (str_comp(str[1], "-l") == 0)
		      lslfunc();
	else if (str_comp(str[1], NULL) == 0)
		      lsfunction();
}
