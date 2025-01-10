#include "myshell.h"

/**
 * env - Obtiene la variable PATH del entorno
 * Return: Un string con el contenido de la variable PATH
 */
char	*env(void)
{
	extern char **environ;
	int	i = 0;
	char	*pathd = NULL;
	size_t	path_size;

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
				return (NULL);
			}
			strcpy(pathd, environ[i] + 5);
			break;
		}
		i++;
	}
	return (pathd);
}

/**
 * path - Busca la ruta completa de un comando
 * @str: El nombre del comando a buscar
 * Return: La ruta completa si el comando existe, o NULL si no existe
 */

char	*path(char *str)
{
	char	*path = env(), *token, *final_path = NULL, *path_copy = NULL;
	char	*temp;
	size_t	len;

	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		free(path);
		return (NULL);
	}

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		len = strlen(token) + strlen(str) + 2;
		temp = realloc(final_path, len);
		if (temp == NULL)
		{
			free(final_path);
			free(path_copy);
			free(path);
			return (NULL);
		}
		final_path = temp;

		strcpy(final_path, token);
		strcat(final_path, "/");
		strcat(final_path, str);

		if (access(final_path, F_OK) == 0)
		{
			free(path_copy);
			free(path);
			return (final_path);
		}

		token = strtok(NULL, ":");
	}

	free(final_path);
	free(path_copy);
	free(path);
	return (NULL);
}

