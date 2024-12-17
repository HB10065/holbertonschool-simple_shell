#include "myshell.h"

/**
 * printppid - prints the parent process of the current one
 */
void printppid(void)
{
	pid_t pntid;
	pntid = getppid();
	printf("%u\n", pntid);
}
