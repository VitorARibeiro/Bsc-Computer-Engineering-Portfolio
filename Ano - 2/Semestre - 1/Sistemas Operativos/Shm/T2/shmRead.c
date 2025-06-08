#include "shmLib.h"





int main(){
   
    char* block = AtachMemoryBlock(FILENAME, SIZE);
    //limpar semaforo
    sem_unlink(SEMESCRITA);
    sem_unlink(SEMLEITURA);
    

    //criar semaforo

    sem_t *semEscrita = sem_open(SEMESCRITA,O_CREAT,0660,0);
    if(semEscrita == SEM_FAILED){
        perror("Erro ao gerar semaforo\n");
        return 1;
    }

    
    sem_t *semLeitura = sem_open(SEMLEITURA,O_CREAT,0660,1);
    if(semLeitura == SEM_FAILED){
        perror("Erro ao gerar semaforo\n");
        return 1;
    }


    while(true){
        sem_wait(semEscrita);
        if(strlen(block)> 0){
            printf("Reading : %s \n", block);
            if(strcmp(block,"quit") == 0)
                break;
            block[0] = 0;
        }
        sem_post(semLeitura);


    }

    //deslinkar bloco
       

        if(shmdt(block) == ERROR){
                perror("Erro ao Deslinkar bloco de memoria\n");
            }

    sem_close(semLeitura);
    sem_close(semEscrita);

    return 0;
}