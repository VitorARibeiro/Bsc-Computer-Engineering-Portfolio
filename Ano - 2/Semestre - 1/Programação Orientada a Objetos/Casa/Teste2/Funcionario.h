#include <iostream>

using namespace std;


class Funcionario{
private:
    float salario;
    int idade;
    string name;

public:

    Funcionario();
    Funcionario(string _name,int _idade,float _salario);
    
    ~Funcionario();

    //op overloading 

    friend ostream& operator << (ostream& output,Funcionario& obj);



};