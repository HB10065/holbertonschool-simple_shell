#include "myshell.h"

/**
 *
 */
int main(int ac, char **av)
{
	int i = 0;
	
	ac = ac;
	for(; av[i] != NULL; i++)
		printf("arg %d: %s\n", i, av[i]);
	return (0);
}
