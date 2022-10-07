#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    
    printf("Forking process\n");

    pid_t forked = fork();

    printf("PID: %d\n", getpid());

    if ( forked == 0 )
        printf("This is child process bufbau\n");
    else
        printf("FORKED PID: %d\n", forked);

    return EXIT_SUCCESS;
}