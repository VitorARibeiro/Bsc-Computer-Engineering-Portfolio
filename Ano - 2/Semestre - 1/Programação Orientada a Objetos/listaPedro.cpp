#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(){


    list<int> MinhaLista = {8,4,3,6,2,1,6};

    MinhaLista.push_back(6);
    MinhaLista.sort();
    MinhaLista.reverse();



    for(list<int>::iterator it = MinhaLista.begin() ; it != MinhaLista.end() ; it++ ){

        cout << *it << "/";
    }



    // .begin() .end()

    return 0;
}

