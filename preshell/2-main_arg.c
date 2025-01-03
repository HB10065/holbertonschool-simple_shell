#include "myshell.h"

/**
 *
 */
int main(void)
{
	char str[] = "Hola como estas, YYYYYYYYYYYYYYYYY aaaaaaaaaaaaa 125973241687";
	char **astr = splitstr(str);
	int i = 0;

	while (astr[i] != NULL)
	{
		printf("%s\n", astr[i]);
		i++;
	}
	free(astr);
	return (0);
}
