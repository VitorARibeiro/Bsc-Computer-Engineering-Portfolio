#include <iostream>

using namespace std;

template <typename T,int Tamanho> class arrayM{
public:
    T array[Tamanho];

    void fill(T filler){
        for(int i = 0; i < Tamanho ; i++){
            array[i] = filler;
        }
    }

    T& at(int posicao){
        if(posicao >= Tamanho){
            throw "Excedeu Tamanho funcao at";
        }
        return array[posicao];
    }

    void put(T filler,int posicao){
        if(posicao >= Tamanho){
            throw "Excedeu Tamanho funcao put";
        }
        array[posicao] = filler;
    }

    void print_array(){
        for(int i = 0; i< Tamanho ; i++){
            cout << array[i] << " ";
        }
    }
    

};

int main(){

    arrayM<int ,10> array1; //objeto de array de inteiros com 10 de tamanhao 

    
    try{
        array1.fill(2);
        cout << array1.at(5);
        
    }
    catch(const char* ErrorText){
        cout << "Exception: " << ErrorText << endl;
    }

    return 0;
}