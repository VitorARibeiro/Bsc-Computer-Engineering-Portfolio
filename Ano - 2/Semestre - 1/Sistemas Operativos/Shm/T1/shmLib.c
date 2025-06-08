

#include "shmLib.h"


int GetMemoryBlock(char* filename, int size){

     //primeiro devemos obter a key
        key_t key = ftok (filename,0);
        //gerar key a partir do ficheiro
        if (key  == ERROR){
            perror("Erro ao gerar key\n");
            return ERROR;
        }

        return shmget(key,size, 0644| IPC_CREAT); // vai retornar um id de um bloco
}

char* AtachMemoryBlock(char* filename, int size){

    int shared_block_id = GetMemoryBlock(filename, size);

    if(shared_block_id == ERROR){
        perror("Erro ao gerar id\n");
        return NULL;
    }

    char* result = shmat(shared_block_id, NULL, 0);
    if(result == (char*)ERROR){
        perror("Erro ao gerar bloco\n");
        return NULL;
    }
    return result;
}

bool DestroyMemoryBlock(int shared_block_id){

     if(shmctl(shared_block_id,IPC_RMID,NULL) == ERROR){
        perror("Erro ao gerar destruir bloco\n");
        return ERROR;
    }
    
    return 1;
}


