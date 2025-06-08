#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAXBUFFER 80
//pipe de passar strings;
int main (){

    int fd[2];

    if(pipe(fd) < 0){
        printf("erro ao gerar pipe");
        return 1;
    } // abrir pipe antes do fork

    int id = fork();

    /*menor que 0 = erro ao gerar pipe
        0 = filho
        diferented e 0 pai */
    if(id < 0){
        printf("Erro ao gerar pipeo");
        return 1;
    }
    else if(id == 0){
        close(fd[0]);
        char str[MAXBUFFER];
        printf("Processo filho pede um input:  \n");
        fgets(str,MAXBUFFER,stdin);

        int size = strlen(str);
        str[size - 1] = '\0';

        write(fd[1],&size, sizeof(int) * 1);
        write(fd[1],str,sizeof(char) * size);

        close(fd[1]);
        
    }
    else{

        char str[MAXBUFFER];
        int size;

        close(fd[1]);

        read(fd[0],&size,sizeof(int) * 1);
        read(fd[0],str,sizeof(char) * size);

        close(fd[0]);

        //por tudo para maiuscula

        for(int i = 0; i < size - 1 ; i++ ){
            str[i] = toupper(str[i]);
        }

        printf("Pai recebeu mensagem: %s \n",str);
      

    }

    return 0;

}