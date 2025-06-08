#include<iostream>
#include<string>


using namespace std;



class PrinterBuffer{
private:
    string info;
    int PagNumber;
public:
    PrinterBuffer(){
        info = "NaN";
        PagNumber = 0;
        throw "Not Init";
    }

    PrinterBuffer(string buffer, int number){
        info = buffer;
        PagNumber = number;
        if (number < 10 ){
            throw "404";
        }
    }

// overloading

friend ostream& operator<< (ostream& os, PrinterBuffer& obj){
    os << obj.info << "//" << obj.PagNumber<< endl;
    return os;
}

};

int main(){

    
    try{
        PrinterBuffer B1("Vitor alberto" , 9);
    }
    catch(const char* textEx){
        cout << "ExceptionT: " << textEx << endl;
    }
    catch(const int intEx){
        cout << "Exception: " << intEx << endl;
    }


    return 0;
}