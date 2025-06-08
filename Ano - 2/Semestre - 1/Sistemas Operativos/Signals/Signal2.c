#include <signal.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char* argv[]){
    printf(" O numero de argumentos é %d \n" , argc);
    
    for(int i = 0 ; i < argc ; i++){

        printf("Arg %d : %s \n",i,argv[i]);
    }

    return 0;
}