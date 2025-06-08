#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAXBUFFER 80

int main(){

    char com[] = "TempXXXXXX";
    int comfile = mkstemp(com);

    if(comfile == - 1){
        perror("Erro ao gerar comfile");
    }

    int id = fork();

    if (id < 0){
        perror("Erro ao gerar fork\n");
    }
    else if(id == 0){
        //dentro do filho
        char mensagem[MAXBUFFER];
        printf("Indique uma mensagem: ");
        fgets(mensagem,MAXBUFFER,stdin);
        int size = strlen(mensagem);
        mensagem[size - 1] = '\0';

        write(comfile,&size,sizeof(int) * 1);
        write(comfile,mensagem,sizeof(char) * size);

        printf("Mensagem Enviada: %s\n",mensagem);
        close(comfile);
        unlink(com);
    }
    else{
        //dentro do pai
        char mensagem[MAXBUFFER];
        int size;
        int file = open(com,O_RDONLY);

        while(read(file,&size,sizeof(int) * 1) != sizeof(int) * 1){
            sleep(1);
        }
        read(file,mensagem,size);
        //podemos brincar com a mensagem

        for(int i = 0 ; i < size ; i++){
            mensagem[i] = toupper(mensagem[i]);
        }
        printf("Mensagem Recebida : %s\n",mensagem);




        close(file);
        unlink(com);
    }


    return 0;
}