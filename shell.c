#include "myshell.h"

/**
 *
 */
int str_comp(char* str, char* str2)
{
	int s1 = 0, s2 = 0;

	if ((str == NULL && str2 != NULL) || (str != NULL && str2 == NULL))
		return (-1);
	if (str == NULL && str2 == NULL)
		return (0);

	while (str[s1] != '\0')
		s1++;
	while (str2[s2] != '\0')
		s2++;
	if (s1 != s2)
		return (-1);

	s1 = 0;
	while (str[s1] != '\0' && str2[s1] != '\0')
	{
		if (str[s1] != str2[s1])
			return (-1);
		s1++;
	}

	return (0);
}

/**
 * splitstr - Separa un String en varios utilizando strtok
 * @str: String que recibe
 * Return: Un array de Strings con cada Token de strtok
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
                        if (spstr == NULL)
                                return (NULL);
                }
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
			break;
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
		}
	}
	free(com_path);
	free(split);
	free(string);
	return (0);
}
