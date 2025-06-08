#include "Edificio.h"

Edificio::Edificio() {
    cidade = "unknown";
    tamanho = 0;
    preco = 0;
}

Edificio::Edificio(string _cidade, float _tamanho, float _preco){
    cidade = _cidade;
    tamanho = _tamanho;
    preco = _preco;
}

Edificio::~Edificio(){}

Edificio::Edificio(Edificio& obj){

    cidade = obj.cidade;
    tamanho = obj.tamanho;
    preco = obj.preco;
}

//operator overloading 

ostream& operator << (ostream& os, Edificio& obj){

    os << "Cidade: " << obj.cidade << endl;
    os << "tamanho: " << obj.tamanho << endl;
    os << "preco: " << obj.preco << endl;

    return os;
}

istream& operator >> (istream& is, Edificio& obj){

    cout << "indique uma cidade:";
    getline(is,obj.cidade);


    cout << "Indique um tamanho:";
    is >> obj.tamanho;

    cout << "Indique um preco";
    is >> obj.preco;
    
    return is;
}
  

