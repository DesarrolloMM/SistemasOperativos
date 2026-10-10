#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// int main() {
//     int p = fork();
//     if (p != 0) for(;;);
//     if (p == 0) execl("/bin/ls", "ls", "-l", NULL);
//     printf("Mi pid es %d", getpid());
//     return 0;
// }

//Fork: crea un proceso hijo que es una copia del proceso padre. 
//El proceso hijo tiene su propio espacio de memoria y puede ejecutar código de manera independiente del proceso padre. 
//En este caso, el proceso padre entra en un bucle infinito, mientras que el proceso hijo ejecuta el comando "ls -l" utilizando la función execl.

//Execl: reemplaza el proceso actual con un nuevo programa. 
//En este caso, el proceso hijo reemplaza su código con el comando "ls -l", que lista los archivos en el directorio actual en formato largo.

// int main() {
// int i, j, k;
// for (i=0; i<3; i++) {
// j = getpid();
// k = fork();
// printf("%d - %d\n",j, k);
// }
// return 0;
// }

// getpid: devuelve el identificador de proceso (PID) del proceso actual.
// fork: crea un nuevo proceso (proceso hijo) que es una copia del proceso actual (proceso padre).
// en la segunda iteracion el proceso padre crea un nuevo proceso hijo, y ambos procesos (padre e hijo) continúan ejecutando el bucle.

int main() {
int p = fork();
if (p == 0) for(;;);
wait(NULL);
printf("Mi pid es %d", getpid());
return 0;
}

//for(;;) es un bucle infinito que se ejecuta mientras el proceso hijo esté activo.}
//wait() es una función que hace que el proceso padre espere a que el proceso hijo termine su ejecución antes de continuar.

