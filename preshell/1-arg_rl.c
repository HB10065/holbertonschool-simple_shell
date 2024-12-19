#include "myshell.h"

/**
 *
 */
int main(void)
{
	ssize_t gl = 0;
	size_t strlength;
	char* string;

	while(gl != -1)
	{
		printf("$");
		gl = getline(&string, &strlength, stdin);
		if (gl == -1)
			break;
		if (gl > 1)
			printf("%s", string);
	}
	free(string);
	return (0);
}
