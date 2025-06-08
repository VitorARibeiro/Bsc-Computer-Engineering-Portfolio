#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Inicio do codigo \n");

    int fd[2];

    if (pipe(fd) < 0)
    {
        perror("Erro ao criar pipe");
        return 1;
    }
    else
    {
        
        switch (fork())
        {
        case -1:
            perror("Erro ao Gerar fork");
            return 1;
        case 0:
            printf("Dentro do processo filho \n");
            int mensagem = 5;

            close(fd[0]);
            write(fd[1], &mensagem, sizeof(int));
            close(fd[1]);
            break;
        default:
            sleep(1);
            printf("Dentro do pai \n");
            int x;
            close(fd[1]);
            read(fd[0], &x, sizeof(int));
            close(fd[0]);
            printf("Numero recebido foi %i \n", x);
            break;
        }
    }

    return 0;
}