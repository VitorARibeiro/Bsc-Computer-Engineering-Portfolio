#include <iostream>

using namespace std;

class Edificio{
protected:
    string cidade;
    float tamanho;
    float preco;
public:
    Edificio();
    Edificio(string _cidade, float _tamanho, float _preco);
    ~Edificio();
    //construtor de copia

    Edificio(Edificio& obj);

    friend ostream& operator << (ostream& os, Edificio& obj);
    friend istream& operator >> (istream& is, Edificio& obj);
    
};