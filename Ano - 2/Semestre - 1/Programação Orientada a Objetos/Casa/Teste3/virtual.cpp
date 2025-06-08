#include <iostream>

using namespace std;

class instrumento{
    public:
     void play(){
        cout << "playing instrument..." << endl;
    }
};


class guitarra : public instrumento{
public:
    void play() {
        cout << "playing guitar..."<< endl;
    }

};

class saxofone : public instrumento{
public:
    void play() {
        cout << "playing saxo..."<< endl;
    }

};

int main(){
    instrumento* inst = new instrumento;
    instrumento* guit = new guitarra;
    instrumento* sax = new saxofone;

   
    instrumento* saxdynamic = dynamic_cast<instrumento*>(sax);

    

    if (saxdynamic) {
        saxdynamic->play();
    } else {
        cout << "A conversão falhou." << endl;
    }
    

   
    
    return 0;
}