#include "shmLib.h"




int main(int argc, char* argv[]){

   char* block = AtachMemoryBlock(FILENAME, SIZE);

   //iniciar semaforos
   sem_t *semEscrita = sem_open(SEMESCRITA,0);
    if(semEscrita == SEM_FAILED){
        perror("Erro ao gerar semaforo\n");
        return 1;
    }

    
    sem_t *semLeitura = sem_open(SEMLEITURA,0);
    if(semLeitura == SEM_FAILED){
        perror("Erro ao gerar semaforo\n");
        return 1;
    }

    //vamos escrever uma mensagem no bloco


    for(int i =0 ;i<atoi(argv[2]);i++){
        sem_wait(semLeitura);
        printf("Writing : %s \n", argv[1]);
        strncpy(block, argv[1] , SIZE);
        sem_post(semEscrita);
    }
    

    //deslinkar bloco
       

        if(shmdt(block) == ERROR){
                perror("Erro ao Deslinkar bloco de memoria\n");
            }

    sem_close(semLeitura);
    sem_close(semEscrita);

    return 0;
}