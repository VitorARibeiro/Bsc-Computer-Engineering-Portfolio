#include <stdio.h>

int main(int argc , char* argv[]){

    printf("Numero de argumento : %i \n", argc);

    int soma = 0;

    int max = atoi(argv[1]) , min = atoi(argv[1]);

    for(int i = 1 ; i < argc ; i++){

        if(atoi(argv[i]) > max){
            max = atoi(argv[i]);
        }

        if(atoi(argv[i]) < min){
            min = atoi(argv[i]);
        }
    
    }

    printf("Max/Min : %d /%d\n", max , min);


    return 0;
}