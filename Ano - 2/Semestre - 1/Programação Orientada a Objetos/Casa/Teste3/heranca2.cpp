#include <iostream>

using namespace std;

class Base1{
public: 
    void frase1(){
        cout << "classe base 1" << endl;
    }
};

class Base2{
public:
    void frase2(){
            cout << "classe base 2"<<endl;
        }
};

class Derivada: public Base2 , public Base1{
public:

    void frase3(){
            cout << "classe base 3" <<endl;
        }
};



int main(){

    Derivada objeto;

    objeto.frase1();

    return 0;
}