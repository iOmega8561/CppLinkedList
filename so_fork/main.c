#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    pid_t pid;
    pid=fork();

    if(pid>0){
        //CODICE PADRE
        printf("sono il processo padre(%d)\n",getpid());
        printf("(padre) La varibile PID è %d\n", pid);
        printf("Prima della wait...\n");
        wait(NULL);
        printf("Dopo la wait...\n");
        
    }
    else {
        //CODICE FIGLIO
        printf("sono il processo figlio(%d)\n",getpid());
        printf("(figlio) La varibile PID è %d\n", pid);
        sleep(10);
    }

    return EXIT_SUCCESS;
}
