#include "myshell.h"

/**
 *
 */
int main(int ac, char **av)
{
	int i = 0;

	for(; av[i] != NULL; i++)
		printf("arg %d: %s\n", ac, av[i]);
	return (0);
}
