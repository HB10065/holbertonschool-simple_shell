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
				&& environ[i][2] == 'T' && environ[i][3] == 'H' &&
				environ[i][4] == '=')
		{
			path_size = strlen(environ[i] + 5);
			pathd = malloc(path_size + 1);
			if (pathd == NULL)
			{
				free(pathd);
				return (NULL);
			}
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
	char *path = env(), *token, *final_path = NULL;

	if (str[0] == '/')
		return (str);
	token = strtok(path, ":");
	while(token != NULL)
	{
		final_path = malloc(strlen(token) + strlen(str) + 2);
		if (final_path == NULL)
			return(NULL);

		strcpy(final_path, token);
		strncat(final_path, "/", 2);
		strncat(final_path, str, strlen(str));
		if (access(final_path, F_OK) == 0)
		{
			free(path);
			return (final_path);
		}

		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
