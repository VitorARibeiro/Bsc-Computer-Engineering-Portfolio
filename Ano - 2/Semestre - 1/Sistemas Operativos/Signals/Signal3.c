#include <signal.h>
#include <stdio.h>
#include <unistd.h>


void SigHandler(int signal){
    printf("Sinal recebido : %i \n", signal);
}

int main(){

    printf("Recebendo Sinais (%i)...\n", getpid());
    

    signal(SIGHUP, SigHandler);

    while(1){
        pause();
    }

    return 0;
}