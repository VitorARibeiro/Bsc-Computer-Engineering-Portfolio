#include "shmLib.h"



int main(){
   
    char* block = AtachMemoryBlock(FILENAME, SIZE);

    printf("Reading : %s \n", block);

    //deslinkar bloco
       

        if(shmdt(block) == ERROR){
                perror("Erro ao Deslinkar bloco de memoria\n");
            }

    return 0;
}