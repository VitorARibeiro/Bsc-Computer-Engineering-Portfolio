#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{

    int fd[2];

    // fd[1] onde se escreve
    // fd[0] onde se lê

    if (pipe(fd) < 0)
    {
        perror("Erro na criacao do tubo\n");
    }

    int id = fork();

    if (id == -1)
    {

        perror("Erro na forquilha\n");
    }
    else if (id == 0)
    {
        close(fd[0]);
        printf("Dentro do filho\n");
        char mensagem[100] = "Cesar Gosta de Pipes";
        int size = strlen(mensagem);

        write(fd[1], &size, sizeof(int) * 1);
        write(fd[1], mensagem, sizeof(char) * size);
        close(fd[1]);
    }
    else
    {

        printf("Dentro del pai\n");
        close(fd[1]);
        char mensagem[100];
        int size;

        read(fd[0], &size, sizeof(int) * 1);
        read(fd[0], mensagem, sizeof(char) * size);
        close(fd[0]);

        // conversao para maiuscula

        for(int i = 0 ; i < size ; i++){
            mensagem[i] = toupper(mensagem[i]);
        }

        
        printf("O Pai recebeu a mensagem : %s\n", mensagem);
        
    }

    return 0;
}