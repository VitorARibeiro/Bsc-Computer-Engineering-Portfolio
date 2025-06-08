#include "McDonalds.h"

McDonalds::McDonalds(){cidade = "Unknown";tamanho = 0;preco = 0;}

McDonalds::McDonalds(string _cidade, float _tamanho, float _preco):Edificio(_cidade,_tamanho,_preco){}

void McDonalds::ShowFuncionarios(){
        for(int i = 0 ; i < lista_funcionarios.size();i++){
            cout << *lista_funcionarios[i];
        }
    }

void McDonalds::AddFuncionarios(vector<Funcionario*> &lista){

        for(int i = 0 ; i < lista.size();i++){
            lista_funcionarios.push_back(lista[i]);
        }
    }