#include <stdio.h>
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
	char com[] = "TEMPXXXXXX";
	int comfile = mkstemp(com);
	
	if(comfile == -1){
		printf("Erro ao criar ficheiro");
		return 1;
	}
	
	int id = fork();
	
	if(id == -1){
		printf("Erro ao criar processo");
	}
	if(id == 0){
		//processo filho
		char mensagem[MAXBUFFER];

		printf("Digite uma frase: ");
		fgets(mensagem,MAXBUFFER,stdin);

		int size = strlen(mensagem);
		mensagem[size - 1] = '\0';

		write(comfile,&size,sizeof(int));
	       	write(comfile,mensagem,sizeof(char) * size);
		
		close(comfile);
		unlink(com);
	}
	else{
		//Processo Pai

		char mensagem[MAXBUFFER];
		int size;
		int file = open(com,O_RDONLY);

		while(read(file,&size,sizeof(int)) != sizeof(int) * 1){
            sleep(1);
        }

		read(file, mensagem, sizeof(char) * size);
		

		printf("Mensagem recebida pelo pai: %s\n", mensagem);	
		
		close(file);
		unlink(com);
			
		}
return 0;
}
