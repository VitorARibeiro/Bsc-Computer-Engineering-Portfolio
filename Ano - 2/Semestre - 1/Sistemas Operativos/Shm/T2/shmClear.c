#include "shmLib.h"



int main(){
   
    int shared_block_id = GetMemoryBlock(FILENAME,SIZE);

    return DestroyMemoryBlock(shared_block_id);
}