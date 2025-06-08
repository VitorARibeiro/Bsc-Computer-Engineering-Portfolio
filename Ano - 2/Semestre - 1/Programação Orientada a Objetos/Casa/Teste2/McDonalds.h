#include "Edificio.h"
#include "Funcionario.h"
#include <vector>

class McDonalds:public Edificio{
private:
    vector<Funcionario*> lista_funcionarios;
public:

    //construtores

    McDonalds();
    McDonalds(string _cidade, float _tamanho, float _preco);

    void ShowFuncionarios();
    void AddFuncionarios(vector<Funcionario*> &lista);
    





};