//- EL proceso padre ejecuta un fork en 3 ciclos
//- En cada ciclo crea un proceso hijo 
// Si el proceso hijo tiene PID par se transformará en el proceso echo
// que imprime "Soy par y este es mi pid =<PID>"
// - Si el proceso hijo tiene PID impar presenta su pid y se transformara en el proceso date
// El padre espera la finalizacion de cada proceso hijo
//imprime al final "ejercicio terminado"


// Bash
// escribir un script que reciba n argumentos
// Si el arg recibido es un numero > 10 o es una secuencia de caracteres de largo > 10
// la lista es un archivo llamado long.txt
// en caso contrario lo lista en el archivo short.txt

// Elija el directorio donde guardar ambos archivos
// Debe consumirse todos los argumentos y exijirse al menos uno


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main (){
    for (int i = 0; i < 3; i++){
        int pid = fork();
        if (pid == 0){
            // proceso hijo
            if (getpid() % 2 == 0){
                // PID par
                char mensaje[256];
                snprintf(mensaje, sizeof mensaje,"Soy par y este es mi pid = %d", (int)getpid());
                execlp("echo", "echo", mensaje  , NULL);
            } else {
                // PID impar
                execlp("date", "date", NULL);
            }
        } else {
            // proceso padre
            wait(NULL); // espera a que el hijo termine
        }
    }
    printf("ejercicio terminado\n");
}


