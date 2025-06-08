#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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
        int numero = 12;

        write(fd[1], &numero , sizeof(int) * 1 );

        close(fd[1]);
    }
    else
    {

        printf("Dentro del pai\n");
        close(fd[1]);
        int numero;

        read(fd[0], &numero, sizeof(int) * 1);
        
        close(fd[0]);

        printf("O Pai recebeu a mensagem : %i \n", numero);
        
    }

    return 0;
}