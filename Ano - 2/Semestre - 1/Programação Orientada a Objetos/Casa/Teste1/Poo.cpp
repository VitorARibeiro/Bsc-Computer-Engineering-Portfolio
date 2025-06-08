#include<iostream>


using namespace std;

class Quartos{

    private:
        float Tamanho; //m2
        int Nivel; // 0-10
    public:

        Quartos(float _Tamanho, int _Nivel):Tamanho(_Tamanho),Nivel(_Nivel){}

        //getters
        float GetTamanho(){return Tamanho;}
        int GetNivel(){return Nivel;}


};

class Casa{
    private:
        
        Quartos quarto;
        float preco;


    public: 

        Casa(float _Tamanho, int _Nivel, float _preco):quarto(_Tamanho,_Nivel),preco(_preco){}

        //getters

        Quartos GetQuartos(){return quarto;}

        float GetPreco(){return preco;}

    
};

int main(){
    

    Casa moradia5(830,9,254000);

    cout << "Preco da moradia5: "<< moradia5.GetPreco() << endl;

    cout << "Quarto da moradia5: " << moradia5.GetQuartos().GetNivel() << ":" << moradia5.GetQuartos().GetTamanho() <<endl;


    


    return 0;
}