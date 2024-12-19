#include "myshell.h"

/**
 *
 */
char **splitstr(char *str)
{
	char **spstr;
	char *token;
	int i = 1, j = 1;

	token = strtok(str, " ");
	spstr = malloc(8);
	spstr[0] = token;
	printf("antes del while: todo correcto\n");
	while (token != NULL)
	{
		token = strtok(NULL, " ");
		if (token == NULL)
			break;
		i++;
		spstr = realloc(spstr, 8 * i);
		spstr[j] = token;
		j++;
	}
	return (spstr);
}
