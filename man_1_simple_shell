.TH SHEESH 1 "Enero 2025" "Simple Shell Manual" "Manual de Usuario"

.SH NOMBRE
sheesh \- Un shell simple basado en Unix.

.SH SINOPSIS
.B ./hsh
[\fIscriptfile\fR]

.SH DESCRIPCIÓN
.B sheesh
es una implementación básica de un shell Unix que permite ejecutar comandos en modo interactivo o no interactivo.

.PP
El programa busca comandos en los directorios definidos por la variable de entorno \fBPATH\fR y los ejecuta si están disponibles.

.SH MODO DE USO

.TP
Modo interactivo:
El shell muestra un prompt (\fBSheesh:\fR) y espera comandos del usuario.

Ejemplo:
.nf
$ ./hsh
Sheesh: ls -l
Sheesh: pwd
Sheesh: exit
.fi

.TP
Modo no interactivo:
El shell ejecuta comandos desde un archivo o una tubería.

Ejemplo:
.nf
$ echo "ls -l" | ./hsh
$ ./hsh < script_file
.fi

.SH COMANDOS INCORPORADOS
.B exit
El comando \fBexit\fR cierra el shell.

.SH ERRORES
Si se ingresa un comando inválido, el shell muestra:
.nf
not found: comando
.fi

.SH AUTORES
Escrito por Camila Romero y Martin Suarez.


