#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAXBUFFER 200

int main(){

    int fd[2];

    if(pipe(fd) < 0){
        perror("Erro ao criar pipe\n");
        return 1;
    }

    int id = fork();

    if (id < 0){
        perror("Erro ao gerar fork\n");
        return 2;
    }
    
    if(id == 0){
        //dentro do processo filho
        close(fd[0]);
        char str[MAXBUFFER];
        printf("Processo filho pede um input:  \n");
        fgets(str,MAXBUFFER,stdin);
        
        int size = strlen(str) + 1;

        //remover /n
        str[size -1] = '\0';

        write(fd[1], &size, sizeof(int) * 1);
        write(fd[1], str ,sizeof(char) * size);
        close(fd[1]);
    }
    else{
        //dentro do processo pai
        close(fd[1]);
        char str[MAXBUFFER];
        int size;

        read(fd[0],&size, sizeof(int) * 1);
        read(fd[0], str , sizeof(char) * size);
        close(fd[0]);

        printf("Mensagem recebida pelo pai : %s\n", str);

    }

    return 0;
}
