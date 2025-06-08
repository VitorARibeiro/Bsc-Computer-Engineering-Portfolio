#include <iostream>
#include <list>

using namespace std;
class cesar{
    public:
        int idade;
        char* nome;

    //construtor
    cesar(int _idade , char* _nome){
        idade = _idade;
        nome = _nome;
    }


};


int main(){

    cesar c1(10,"Cesar1") , c2(11,"Cesar2"), c3(12,"Cesar3");

    list<cesar> listaDoCesar ; 

    listaDoCesar.push_back(c1);
    listaDoCesar.push_back(c2);
    listaDoCesar.push_back(c3);

    

    
    for(list<cesar> :: iterator it = listaDoCesar.begin() ; it != listaDoCesar.end() ; it++){
        cout << it->idade << endl;

    }

    return 0;
}