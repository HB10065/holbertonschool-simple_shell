#include "myshell.h"

/**
 *
 */
int str_comp(char* str, char* str2)
{
	int s1 = 0, s2 = 0;

	if (str == NULL && str2 == NULL)
		return (0);
	while (str[s1] != '\0' && str2[s2] != '\0' && str[s1] == str2[s2])
	{
		s1++;
		s2++;
	}
	return ((unsigned char) str[s1] - (unsigned char) str2[s2]);
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
                        if (spstr)
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
	ssize_t gl = 0;
	size_t strlength;
	char* string;
	char** split;

	while(gl != -1)
	{
		printf("Sheesh:");
		gl = getline(&string, &strlength, stdin);
		if (gl == -1)
			break;
		split = splitstr(string);
		if (str_comp(split[0], "ls") == 0)
				lsfunc(split);
	}
	free(split);
	free(string);
	return (0);
}
