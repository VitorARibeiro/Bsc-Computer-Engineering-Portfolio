#include "Funcionario.h"


Funcionario::Funcionario(){name = "Unknown";idade = 0 ; salario = 0;}

Funcionario::Funcionario(string _name,int _idade,float _salario){
    name = _name;idade = _idade;salario = _salario;}

Funcionario::~Funcionario(){}

ostream& operator << (ostream& output,Funcionario& obj){
    output << obj.name <<"/"<< obj.idade <<"/"<< obj.salario << endl;
    return output;
}