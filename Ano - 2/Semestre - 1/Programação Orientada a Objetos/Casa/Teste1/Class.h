#include <iostream>
#include <fstream>

//isto é a class

using namespace std;

//dia/mes/ano

class Data{
private:
    int dia,mes,ano;
public:
    //construtor
    Data(){dia = 0;mes = 0;ano = 0;}

    Data(int _dia,int _mes, int _ano){
        dia = _dia;
        mes = _mes;
        ano = _ano;
    }

    ~Data(){}
  
    //setters e getter

    int GetDia(){
        return dia;
    }

    void SetDia(int _dia){
        dia = _dia;
    }

    //operator overloading

    friend ostream& operator << (ostream& os,Data& obj){

        os << obj.dia << "/" << obj.mes << "/" << obj.ano;
        return os;

    }

    friend istream& operator >> (istream& is,Data& obj){

        string aux;

        cout << "indique uma data no formato (dia/mes/ano)";

        getline(is,aux,'/');
        obj.dia = stoi(aux);

        getline(is,aux,'/');
        obj.mes = stoi(aux);

        getline(is,aux);
        obj.ano = stoi(aux);

        return is;

    }

    int operator == (Data& obj2){

        if (dia == obj2.dia ){
            return 0;
        }
        else if (dia < obj2.dia){
            return 1;

        }
        else{
            return -1;
        }

    }

   
};

class Pessoa{
private:
    Data data_nascimento;
    int idade;
    string nome;
public:
    Pessoa():data_nascimento(){}

    Pessoa(int _idade,string _nome , int _dia , int _mes , int _ano):data_nascimento(_dia, _mes, _ano), idade(_idade){
        nome = _nome;
    }


    //operator overloading

    friend ostream& operator<< (ostream& os, Pessoa& obj){
        os << "Idade: " << obj.idade << endl;
        os << "nome: " << obj.nome << endl;
        os << obj.data_nascimento;

        return os;
    }   

    friend istream& operator>> (istream& is, Pessoa& obj){
        cout << "Indique uma idade: ";
        is >> obj.idade;
        cin.clear();
        cout << "Indique um nome: ";
        getline(is,obj.nome);
        is.ignore();

        is >> obj.data_nascimento;

        return is;
    }   

};
