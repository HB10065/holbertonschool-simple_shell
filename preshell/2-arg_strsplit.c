#include "myshell.h"

/**
 *
 */
char **splitstr(char *str)
{
	char **spstr;
	char *token;
	int i = 0, size = 10;

	spstr = malloc(size * sizeof(char *));
	if (spstr == NULL)
		return (NULL);

	token = strtok(str, " ");
	while (token != NULL)
	{
		if (i >= size)
		{
			size = size * 2;
			spstr = realloc(spstr, size * sizeof(char *));
			if (spstr)
				return (NULL);
		}
		spstr[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	return (spstr);
}
