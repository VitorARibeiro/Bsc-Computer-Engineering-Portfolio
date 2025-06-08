#include <iostream>

using namespace std;

template <typename T>

class meuVetor{    
public:
    T array[10];

    void fill(T value){
        for(int i = 0; i < 10 ; i++){
            array[i] = value;
        }
    }

    T& at(int index){
        return array[index];
    }

};

int main(){

    meuVetor<int> intArray;
    meuVetor<string> stringArray;

    intArray.fill(2);
    cout <<  intArray.at(5) << endl;

    stringArray.fill("Vitor");
    cout << stringArray.at(2) << endl;


    return 0;
}