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
        int numero = 1;
        while(numero != 0){
            printf("Indique um numero: ");
            scanf("%i",&numero);
            write(fd[1],&numero, sizeof(int) * 1);
        }
        close(fd[1]);
    }
    else
    {

        
        close(fd[1]);
        int numero = 1,soma = 0;

        while(numero != 0){
            read(fd[0], &numero, sizeof(int) * 1);
            soma += numero;
        }
        
        close(fd[0]);

        printf("O Pai recebeu a mensagem : %i \n", soma);
        
    }

    return 0;
}