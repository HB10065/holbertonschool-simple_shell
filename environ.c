#include "myshell.h"

/**
 *
 */
char *env(void)
{
	extern char **environ;
	int i = 0;
	char *pathd = NULL;
	size_t path_size;

	while (environ[i] != NULL)
	{
		if (environ[i][0] == 'P' && environ[i][1] == 'A' 
				&& environ[i][1] == 'T' && environ[i][1] == 'H' &&
				environ[i][1] == '=')
		{
			path_size = strlen(environ[i] + 5);
			pathd = malloc(path_size + 1);
			if (pathd == NULL)
				return (NULL);
			strcpy(pathd, environ[i] +5);
			break;
		}
		i++;
	}
	return (pathd);
}

/**
 *
 */
char *path(char* str)
{
	char *path = env(), *token;

	token = strtok(path, ":");
	while(token != NULL)
	{
		token = strncat(token, "/");
		token = strncat(token, str);
		if (access(token, F_OK) == 0)
			return (token);

		token = strtok(NULL, ":");
	}
	return (NULL);
}
