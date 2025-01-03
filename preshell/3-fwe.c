#include "myshell.h"

/**
 *
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "./", NULL};
	int i = 0, status;
	pid_t pid, pid2;
	
	pid = getpid();

	while (i != 5)
	{
		pid2 = fork();

		if (pid != getpid())
		{
			execve("/bin/ls", argv, NULL);
		}
		
		wait(&status);
		i++;
	}
	return (0);
}
