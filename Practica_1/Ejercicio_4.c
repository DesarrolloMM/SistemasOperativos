#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
#include<signal.h>
#include <sys/types.h>


void manejar_sigusr1(int señal){
    const char mensaje[] = "Recibida la señal";
    (void)señal;
    write(STDOUT_FILENO, mensaje,sizeof(mensaje)-1);
    _exit(EXIT_SUCCESS);
}

int main(int argc, char * argv[]){

    pid_t p = fork();
    if(p==0){
        printf("Proceso padre esperando por hijo: %d\n", (int)p); 
        execlp("cal","cal",argv[1],argv[2] , NULL);
        //no se llega a la linea siguiente, execlp reemplaza el proceso actual
        printf("Inalcanzable");
        return EXIT_SUCCESS;
    }
    else{
        wait(NULL);
        printf("Hijo PID: %d finalizó\n", (int)p);
    }
        
    p = fork();
    if(p==0){
        struct sigaction accion = {0};
        accion.sa_handler = manejar_sigusr1;
        sigemptyset(&accion.sa_mask);

        if(sigaction(SIGUSR1, &accion, NULL) == -1){
            _exit(EXIT_FAILURE);
        }
        pause();
    }
    else{
        wait(NULL);
        printf("Hijo PID: %d finalizó\n", (int)p);
    }

    printf("Proceso padre %d finalizando...", getpid());
    
    return EXIT_SUCCESS;
}
