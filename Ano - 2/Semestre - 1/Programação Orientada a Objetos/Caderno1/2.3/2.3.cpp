#include<fstream>
#include<iostream>
#include<string>

using namespace std;

struct Aluno
{
    string nome;
    int idade,numero;
};

int main()
{
    ofstream escrita;
    Aluno alunos[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "indique o nome do aluno: ";
        getline(cin,alunos[i].nome); // string lib
        cout << "indique a idade do aluno: ";
        cin >> alunos[i].idade ;
        cout << "indique o numero do aluno: ";
        cin >> alunos[i].numero ;
        cin.get(); // buffer clear
    }
    
    escrita.open("output.txt");

    if(!escrita){
        cout << "erro ao criar ficheiro";
        exit(1);
    }

    for (int i = 0; i < 3; i++)
    {
        escrita << alunos[i].nome << ";" << alunos[i].idade << ";" << alunos[i].numero << endl;  
    }
    
    escrita.close();


    return 0;
}