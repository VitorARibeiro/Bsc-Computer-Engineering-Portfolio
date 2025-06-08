#include <stdio.h>

int main(int argc, char *argv[])
{

    int NumeroDeProcessos = atoi(argv[1]);

    int id = 0;
    for (int i = 1; i < NumeroDeProcessos; i++)
    {   

        if (id == 0)
        {
            printf("foi criado um processo\n");
            printf("\n");
            id = fork();
        }
        

    }

    return 0;
}