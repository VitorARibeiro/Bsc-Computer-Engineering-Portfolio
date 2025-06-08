#include <iostream>

using namespace std;

class Entidade{
public: 

virtual void funcao(){
        cout<< "ola Identidade";
    };

};

class Inimigo:public Entidade{
public:
    
    void funcao(){
        cout<< "ola enemy";
    }

};

class Player:public Entidade{
public:

void funcao(){
        cout<< "ola player";
    }
};

int main(){

Entidade *vitor = new Player; // temos de alocar memoria para um apontador
Entidade *ent = new Entidade;
Entidade *in = new Inimigo;

   // vitor->funcao();

Player* p1 = dynamic_cast<Player*> (vitor); // cast de vitor para player, vitor ja é player
Inimigo* e1 = dynamic_cast<Inimigo*> (ent); // transformar entidade num inimigo
Player* p2 = dynamic_cast<Player*> (in); //transformar inimigo em player

p1->funcao();
e1->funcao();
p2->funcao();

delete vitor;
delete ent;
delete in;
delete p1;
delete e1;
delete p2;

    return 0;
}