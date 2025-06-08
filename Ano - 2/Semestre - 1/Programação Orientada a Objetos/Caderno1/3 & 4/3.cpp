#include "Class.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main(){

    Data Ultimo(14,10,15),Primeiro;

    ofstream escrever;
    ifstream ler;

    escrever.open("escrita.txt");
    
    if(!escrever){
        cout << "erro ao abrir ficheiro" <<endl;
    }

    ler.open("escrita.txt");

     if(!escrever){
        cout << "erro ao abrir ficheiro" <<endl;
    }
    

    
    Ultimo.WriteFile(escrever);

    escrever.close();


    Primeiro.ReadFile(ler);

    cout << Primeiro ;

    ler.close();




    

    return 0;
}

