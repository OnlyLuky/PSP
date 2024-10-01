#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid_p2, pid_p3; 

    pid_p2 = fork();

    if (pid_p2 < 0) {
        perror("Error al crear el proceso P2");
        exit(1);
    } 
    else if (pid_p2 == 0) {
        sleep(10); 
        printf("Despierto\n");
        exit(0);  
    } 
    else {
        pid_p3 = fork();

        if (pid_p3 < 0) {
            perror("Error al crear el proceso P3");
            exit(1);
        } 
        else if (pid_p3 == 0) {
            printf("Soy el proceso P3. Mi PID: %d, PID de mi padre: %d\n", getpid(), getppid());
            exit(0); 
        } 
        else {
            wait(NULL);  
            wait(NULL);  
            printf("Soy el proceso P1. He esperado a mis hijos.\n");
        }
    }

    return 0;
}

