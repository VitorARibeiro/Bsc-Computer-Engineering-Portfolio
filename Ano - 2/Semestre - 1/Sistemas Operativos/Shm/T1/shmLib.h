#ifndef __MYCODE__
#define __MYCODE__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <stdbool.h>

#define FILENAME "shmWrite.c"
#define ERROR (-1)
#define SIZE 4096

int GetMemoryBlock(char* filename, int size);
char* AtachMemoryBlock(char* filename, int size);
bool DestroyMemoryBlock(int shared_block_id);


#endif 
