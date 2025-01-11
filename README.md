# Simple Shell

Bienvenidos a Simple Shell. Este proyecto implementa un shell simple en C, simulando funcionalidades b√sicas de un shell Unix. Permite ejecutar comandos de manera interactiva o desde un archivo.

---

## Archivos del proyecto:

- `shell.c`: Archivo principal del proyecto, contiene el bucle del shell y toda la logica principal
- `environ.c`: Funciones relacionadas con el manejo del entorno, como buscar comandos en el `PATH`.
- `myshell.h`: Archivo de cabecera que contiene las definiciones de funciones y macros.
- `README.md`: Este archivo, explica como funciona el proyecto y como usarlo.
- `AUTHORS`: Lista de los autores que trabajaron en el proyecto.
- `man_1_simple_shell`: Pagina de manual que explica co≥mo usar el shel.

---

## Compilacion

Para compilar el shell, se utiliza el siguiente comando en la terminal:

```bash
gcc -Wall -Werror -Wextra -pedantic shell.c environ.c -o hsh

