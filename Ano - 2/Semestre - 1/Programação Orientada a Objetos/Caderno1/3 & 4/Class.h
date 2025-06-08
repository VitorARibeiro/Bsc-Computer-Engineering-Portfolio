
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Data
{
private:
    int ano,mes,dia;
public:
    Data(){ano = 0; dia = 0 ; mes = 0;}
    Data(int _dia,int _mes, int _ano){ano = _ano;mes = _mes;dia = _dia;}
//setters

    void SetDia(int _dia){dia = _dia;}
    void SetMes(int _mes){dia = _mes;}
    void SetAno(int _ano){dia = _ano;}
    int GetDia(){return dia;}
    int GetMes(){return mes;}
    int GetAno(){return ano;}

//metodos

    void Show(){
        cout << "dia: " << dia << endl;
        cout << "mes: " << mes << endl;
        cout << "ano: " << ano << endl;
    }

    void Update(int _ano, int _mes, int _dia){
        ano = _ano;
        mes = _mes;
        dia = _dia;
    }

    bool Igual(Data x){
        if (x.ano == ano && x.mes == mes && x.dia == dia){
            return true;
        }
        else{
            return false;
        }
    }

    friend bool operator==(Data& x , Data& y){
        return(x.ano == y.ano && x.mes == y.mes && x.dia == y.dia);
    }

    friend bool operator!=(Data& x , Data& y){
      return !(x.ano == y.ano && x.mes == y.mes && x.dia == y.dia); 
    }

    friend ostream& operator<< (ostream& os, Data y){
        os << "dia: " << y.dia << endl;
        os << "mes: " << y.mes << endl;
        os << "ano: " << y.ano << endl;

        return os;
    }

    friend istream& operator>> (istream& is , Data& y){

        cout << "indique o dia : ";
        is >> y.dia ;
        cout << "indique o mes : ";
        is >> y.mes ;
        cout << "indique o ano : ";
        is >> y.ano ;

        return is;
    }

    void WriteFile(ofstream& os){

        os << dia << "/" << mes << "/" << ano <<endl; // ou entao usar getters
    }

    void ReadFile(ifstream& is){
        string aux;

        getline(is, aux, '/');
        dia = stoi(aux);

        getline(is, aux, '/');
        mes = stoi(aux);

        getline(is, aux);
        ano = stoi(aux);


    }

};
 // definicoes fora da class



class Pessoa{
    private:
        string nome;
        string morada;
        Data data;
    public:
    //construtor
    Pessoa():data(){
        nome = "NaN";
        morada = "Nan";
    }

    Pessoa(string _nome, int _dia ,int _mes, int _ano, string _morada):data(_dia,_mes,_ano){
        nome = _nome;
        morada = _morada;    
    }
    ~Pessoa(){}
    //getter setter
    void SetNome(string _nome){nome = _nome;} 
    void SetDatan(int _dia , int _mes , int _ano){
        data.SetAno(_ano);
        data.SetDia(_dia);
        data.SetMes(_mes);
    }
    void SetMorada(string _morada){morada = _morada;} 
    string GetNome(){return nome;} 
    Data GetDatan(){return data;} 
    string GetMorada(){return morada;}
    //metodos das perguntas

    void Show(){
        cout << "nome: "<< nome << endl;
        cout << data;
        cout<<"Morada: " << morada << endl;
    }

    void ReadK(){
        string _morada, _nome;
        cout << "Indique um nome: ";
        getline(cin,_nome);
        SetNome(_nome);
        cout << "Uma morada: ";
        getline(cin,_morada);
        SetMorada(_morada);
        cin >> data;
    }

    //operator overloading

    friend ostream& operator<< (ostream& os, Pessoa& obj){
        os << "Nome: " << obj.nome << endl;
        cout << obj.data;
        os << "Morada: " << obj.morada << endl;;
        return os;
    }

    
    friend istream& operator>> (istream& is, Pessoa& obj){
        cout<<"Indique um nome: ";
        getline(is,obj.nome);

        cin >> obj.data;

        is.ignore(); // clear do buffer por que cin >> obj.data gera um return que interfere com o proximo getline 

        cout<<"Indique uma morada: ";
        getline(is,obj.morada);

        return is;
    }

    friend bool operator== (Pessoa& p1,Pessoa& p2){

        return(p1.nome == p2.nome && p1.data == p2.data);
   
    }

    friend bool operator!= (Pessoa& p1,Pessoa& p2){

        return !(p1.nome == p2.nome && p1.data == p2.data);
    }

    void MaisNovo(Pessoa& p1,Pessoa& p2){
        int mais_novo;
        if (p1.data.GetAno() > p2.data.GetAno()){
            mais_novo = 1;
        }
        else if (p1.data.GetAno() < p2.data.GetAno()){
            mais_novo = 2;
        }
        else{ // caso o ano seja igual
            if (p1.data.GetMes() > p2.data.GetMes()){
                mais_novo = 1;
            }
            else if (p1.data.GetMes() < p2.data.GetMes()){
                mais_novo = 2;
            }
            else{ // caso o mes seja igual
                if (p1.data.GetAno() > p2.data.GetAno()){
                    mais_novo = 1;
                }
                else if (p1.data.GetAno() < p2.data.GetAno()){
                    mais_novo = 2;
                }
                else{ // caso o dia seja igual

                    cout << "Tem as mesma idade" << endl;
                }
            }

        }

        if (mais_novo == 1){
            cout << p1;
        }
        else{
            cout << p2;
        }

    }


    int SaveFile(string ficheiro){
        ofstream os ;
        os.open(ficheiro);

        if (!os)
        {
            cout<< "nao foi possivel guardar ficheiro com esse nome";
            return 0;
        }
        
        os << "Nome: " << nome << endl;
        os << data;
        os << "Morada: " << morada << endl;

        os.close();

        return 0;
        
    }

    int ReadFile(string ficheiro){
        ifstream is;
        is.open(ficheiro);

        if (!is)
        {
            printf("Impossivel abrir ficheiro");
            return 0;
        }

        string aux;
    
        getline(is,nome,':');
        getline(is,nome);
        getline(is,aux,':');
        getline(is,aux);
        data.SetDia(stoi(aux));
        getline(is,aux,':');
        getline(is,aux);
        data.SetMes(stoi(aux));
        getline(is,aux,':');
        getline(is,aux);
        data.SetAno(stoi(aux));
        getline(is,morada,':');
        getline(is,morada);

        
    }

};