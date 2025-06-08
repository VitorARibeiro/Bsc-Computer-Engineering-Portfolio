#include<iostream>
#include<fstream>

using namespace std;

int main(){

    ofstream escrita;   //isto sao classes predefinidas na biblioteca fstream, estamos a criar objetos
    ifstream leitura;   // ofstream é class de escrita em ficheiros, ifstream é classe de leitura de ficheiros

    leitura.open("dados_ent.txt"); //open é um getter
    if (!leitura)
    {
        cout<< "erro ao abrir ficheiro de entrada" << endl;
        exit(1);
    }

    
    escrita.open("dados_saida.txt"); //open é um getter
    if (!escrita)
    {
        cout<< "erro ao abrir ficheiro de saida" << endl;
        exit(1);
    }

    string a,b;

    leitura >> a >> b; // a é a primeira palavra, b é a segunda

    escrita << "vitor 1235" << endl;

    cout << a << b << endl;






    return 0;
}