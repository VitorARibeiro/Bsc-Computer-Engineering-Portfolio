#include <signal.h>
#include <stdio.h>
#include <unistd.h>


void signalHandler(int signal){
    printf("Recebeu um sinal %i\n", signal);
}

int main(){

    printf("Processo numero : %d \n", getpid());
    printf("Waiting for signals...\n");

    //signal overloading

    signal(SIGHUP, signalHandler);
    signal(SIGINT, signalHandler);

    while(1){
        pause();
    }

    return 0;
}