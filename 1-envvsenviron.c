#include <stdio.h>
extern char **environ;

/**
 * main - Punto de entrada
 * @argc: Num de argumentos pasados al programa
 * @argv: Array de punteros para los argumentos
 * @env : Array de punteros a  las variables de entorno
 * Return: 0
 *
 */

int main(int argc, char **argv, char **env)
{

	(void)argc;
	(void)argv;

	printf("Address of env): %p\n", (void *)env);
	printf("Address of environ : %p\n", (void *)environ);

	if (env == environ)
	{
		printf("Both addresses are the same. \n");

	}

	else
	{
		printf("The addresses are different.\n");
	}

	return (0);

}
