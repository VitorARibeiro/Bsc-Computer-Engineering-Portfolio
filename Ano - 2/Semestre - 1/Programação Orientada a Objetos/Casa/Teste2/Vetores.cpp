#include <iostream>
#include <vector>

using namespace std;

int main(){

vector<int> meu_vetor = {12,2,15,23};

meu_vetor.push_back(15);

meu_vetor.erase(meu_vetor.begin() + 1);

for(auto numero : meu_vetor){

    cout << numero << endl;
}

    return 0;
}