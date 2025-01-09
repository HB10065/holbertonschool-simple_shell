#include "myshell.h"

/**
 *
 */
void freestr(char **str)
{
	if (str == NULL)
		return;
	free(str);
}

/**
 * splitstr - Separa un String en varios utilizando strtok
 * @str: String que recibe
 * Return: Un array de Strings con cada Token de strtok
 */
char **splitstr(char *str)
{
	char **spstr;
	char *token, *str_copy = strdup(str);
	int i = 0, cantidad = 0;

	token = strtok(str_copy, " ");
	while (token != NULL)
	{
		cantidad++;
		token = strtok(NULL, " ");
	}
	free(str_copy);
	spstr = malloc((cantidad + 1) * sizeof(char*));
	if (spstr == NULL)
		return (NULL);
	token = strtok(str, " ");
	while (token != NULL)
	{
		spstr[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	return (spstr);
}

/**
 * main - shell
 * Return: 0
 */
int main(void)
{
	extern char **environ;
	ssize_t gl = 0;
	size_t strlength;
	char *string, *com_path;
	char **split;
	pid_t pid;

	while(gl != -1)
	{
		printf("Sheesh: ");
		gl = getline(&string, &strlength, stdin);
		if (gl == - 1 || strcmp(string, "exit\n") == 0)
		{
				break;
		}
		if (string[0] != '\n' && string[gl -1] == '\n')
			string[gl - 1] = '\0';

		split = splitstr(string);

		com_path = path(split[0]);
		if (com_path != NULL)
		{
			pid = fork();
			if (pid == 0)
				execve(com_path, split, environ);
			else
				wait(NULL);
			free(com_path);
		}
		freestr(split);
		com_path = NULL;
		split = NULL;
	}
	free(string);
	return (0);
}
