#include "McDonalds.h"

int main(){
    McDonalds barcelos("Barcelos",1600,300000);


    Funcionario* vitor = new Funcionario("Vitor Alberto", 21, 12);
    Funcionario* barbara = new Funcionario("Barbara Costa", 21, 10);

    //lista de funcionarios

    vector<Funcionario*> listaFunc;

    listaFunc.push_back(vitor);
    listaFunc.push_back(barbara);

    barcelos.AddFuncionarios(listaFunc);
    barcelos.ShowFuncionarios();

  

    return 0;
}