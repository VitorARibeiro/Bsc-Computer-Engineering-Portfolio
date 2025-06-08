#include <iostream>

using namespace std;

class Pessoa{
private:

    string nome;
    int* idade;
public:

    Pessoa(string nome,int idade){
        this->nome = nome;
        this->idade = new int;
        this->idade = &idade;

    }

    Pessoa(){
        nome = "Unknonw";
        idade = new int;
        *idade = 2;

    }

    /*
    
    Pessoa(Pessoa& obj)
        : nome(obj.nome) , idade(obj.idade){ //shalow copy
    }
    
    */

    Pessoa(Pessoa& obj) 
        : nome(obj.nome) { //deep copy

            idade = new int; //temos de alocar memoria para deep copy senao...
            *idade = *(obj.idade);               
        }
        

    ~Pessoa(){

        delete idade;
    }
    //setter para idade

    void setIdade(int _idade){
        *idade = _idade;  
    }

    //overloading zito

    friend ostream& operator << (ostream& os,Pessoa& obj){

        os<< "nome: " << obj.nome << endl << "Idade: " << *obj.idade << endl;
        return os;
    }

};

int main(){


    Pessoa p1("Vitor123",2),p2(p1);

    cout << p2;

    p1.setIdade(15);

    cout << p1 << p2;

    return 0;
}