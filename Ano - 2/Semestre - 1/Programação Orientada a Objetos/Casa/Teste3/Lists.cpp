#include <iostream>
#include <list>

using namespace std;

void printLista(list<int> lista){

    for(list<int>::iterator it = lista.begin(); it != lista.end() ; it++){
        cout << *it << " ";
    }
}

int main(){

    list<int> minhaLista = {1,2,3,4,5,6,7,8,9,10};

    printLista(minhaLista);

    return 0;
}