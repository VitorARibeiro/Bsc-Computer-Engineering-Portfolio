#include <iostream>
#include <string.h>

using namespace std;

class Data{

private:
    int dia,mes,ano;
public:
//construtor
    Data(){dia = 0;mes=0;ano=0;}
    Data (int _dia, int _mes, int _ano){
        dia = _dia;
        mes = _mes;
        ano = _ano;
    } 

    //operator overloading
    friend ostream& operator << (ostream& os, Data& obj){

        os << obj.dia << "/" << obj.mes << "/" << obj.ano << endl;

        return os;
    }

    
    friend istream& operator >> (istream& is, Data& obj){

        string aux;
        cout << "indique uma data no formato (dd/mm/aa): ";
        getline(is,aux,'/');
        obj.dia = stoi(aux);
        getline(is,aux,'/');
        obj.mes = stoi(aux);
        getline(is,aux);
        obj.ano = stoi(aux);

        return is;
    }
};

class Pessoa {
private:
    string nome;
    int idade;
    Data data_nascimento;
public:
    Pessoa():data_nascimento(){
        nome = "NaN";
        idade = 0;
    }

    Pessoa(string _nome,int _idade,int _dia,int _mes, int _ano):data_nascimento(_dia,_mes,_ano){
        nome = _nome;
        idade = _idade;
    }

    //op overloading

    friend ostream& operator << (ostream& os , Pessoa& obj){

        os << "Nome: " << obj.nome << endl;
        os << "Idade: "<< obj.idade << endl;
        os << "Data de nascimento: ";
        os << obj.data_nascimento;

        return os;
    }

    
    friend istream& operator >> (istream& is , Pessoa& obj){

        
        cout << "Indique um nome: ";
        getline(is, obj.nome);
        cout << "Indique uma idade:";
        is >> obj.idade;
        is >> obj.data_nascimento;
        
        return is;
    }

};

int main(){

    Pessoa pessoa_diferente;

    cin >> pessoa_diferente;
    cout << pessoa_diferente;

    return 0;
}