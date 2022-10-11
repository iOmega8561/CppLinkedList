#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(){

    pid_t pid;
    pid=fork();

    if(pid>0){
        //CODICE PADRE
        printf("sono il processo padre(%d)\n",getpid());
        printf("(padre) La varibile PID è %d\n", pid);
    }
    else {
        //CODICE FIGLIO
        printf("sono il processo figlio(%d)\n",getpid());
        printf("(figlio) La varibile PID è %d\n", pid);

    }

    return 0;
}
