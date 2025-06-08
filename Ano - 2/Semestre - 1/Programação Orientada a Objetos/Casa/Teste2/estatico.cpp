#include <iostream>

using namespace std;


class teste{
public:

    static int idade;
    string nome;

    teste(){

        nome ="unknown";
    }
};

int teste::idade = 0;

int main(){

    teste t1;

    cout << t1.idade << endl;

    teste t2;

    t2.idade = 4;

    cout << t1.idade << endl;


    return 0;
}