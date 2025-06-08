#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct Aluno
{
    string nome;
    int idade,numero;
};

int main()
{
   ifstream leitura;

   leitura.open("alunos.txt");
   
   if(!leitura){

    cout << "erro ao abrir ficheiro";
    exit(1);
   }
   else {
    cout << "aberto com sucesso"<<endl;
   }

   while (leitura.peek() != EOF)
   {
    string nome,numero,idade;
    

    getline(leitura ,nome,';');
    getline(leitura ,numero, ';');
    getline(leitura ,idade);


    cout << "nome: "<< nome << endl;
    cout << "numero: "<< numero << endl;
    cout << "idade: "<< idade << endl;

   }
   
    return 0;
}