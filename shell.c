#include "myshell.h"

/**
 * freestr - Libera un array de strings
 * @str: Array de strings
 */
void freestr(char **str)
{
	int i = 0;

	if (str == NULL)
		return;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
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
	char *token, *str_copy;
	int i = 0, cantidad = 0;

	str_copy = strdup(str);
	if (str_copy == NULL)
		return (NULL);
	token = strtok(str_copy, " \t\n");
	while (token != NULL)
	{
		cantidad++;
		token = strtok(NULL, " \n\t");
	}
	free(str_copy);
	spstr = malloc((cantidad + 1) * sizeof(char *));
	if (spstr == NULL)
		return (NULL);
	str_copy = strdup(str);
	if (str_copy == NULL)
	{
		free(spstr);
		return (NULL);
	}
	token = strtok(str_copy, " \n\t");
	while (token != NULL)
	{
		spstr[i] = strdup(token);
		if (spstr[i] == NULL)
		{
			freestr(spstr);
			free(str_copy);
			return (NULL);
		}
		i++;
		token = strtok(NULL, " \n\t");
	}
	spstr[i] = NULL;
	free(str_copy);
	return (spstr);
}

/**
 * execute_command - Ejecuta un comando en un proceso hijo
 * @com_path: Ruta del comando
 * @split: Array de argumentos
 * @environ: Variables de entorno
 */
void execute_command(char *com_path, char **split, char **environ)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(com_path, split, environ);
		perror("Error");
		freestr(split);
		free(com_path);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
		wait(NULL);
}

/**
 * main - shell
 * Return: 0
 */
int main(void)
{
	extern char **environ;
	ssize_t gl = 0;
	size_t strlength = 0;
	char *string = NULL, *com_path = NULL, **split = NULL;

	while (gl != -1)
	{
		if (isatty(STDIN_FILENO))
			printf("Sheesh: ");
		gl = getline(&string, &strlength, stdin);
		if (gl == -1 || strcmp(string, "exit\n") == 0)
			break;
		if (strcmp(string, "\n") == 0)
			continue;
		split = splitstr(string);
		if (split == NULL || split[0] == NULL)
		{
			freestr(split);
			continue;
		}
		if (access(split[0], F_OK) == 0)
			execute_command(split[0], split, environ);
		else
		{
			com_path = path(split[0]);
			if (com_path != NULL)
			{
				execute_command(com_path, split, environ);
				free(com_path);
			}
			else
				printf("not found: %s\n", split[0]);
		}
		freestr(split);
		split = NULL;
	}
	free(string);
	return (0);
}

