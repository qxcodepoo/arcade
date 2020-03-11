#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Cliente{
    string id;
    string fone;

    Cliente(string id = "", string fone = ""){
        this->id = id;
        this->fone = fone;
    }
    string toString(){
        stringstream ss;
        ss << this->id << ":" << this->fone;
        return ss.str();
    }
};

struct Sala{
    vector<Cliente*> cadeiras;

    Sala(int qtd = 0):
        cadeiras(qtd, nullptr)
    {
    }

    ~Sala(){
        for(Cliente * cli : cadeiras)
            delete(cli);
    }

    void reservar(string id, string fone, int ind){
        int qtd = cadeiras.size();
        if((ind < 0) || (ind >= qtd)){
            cout << "failure: cadeira nao existe" << endl;
            return;
        } 
        if(cadeiras[ind] != nullptr){ 
            cout << "failure: cadeira ja esta ocupada" << endl; 
            return;
        }
        for(int i = 0; i < (int) cadeiras.size(); i++){
            if((cadeiras[i] != nullptr) && (cadeiras[i]->id == id)){
                cout << "failure: cliente ja esta no cinema" << endl;
                return;
            }
        }
        cadeiras[ind] = new Cliente(id, fone);
    }

    void cancelar(string id){
        for(int i = 0; i < (int) cadeiras.size(); i++){
            if(cadeiras[i] != nullptr && cadeiras[i]->id == id){
                delete cadeiras[i];
                cadeiras[i] = nullptr;
                return;
            }
        }
        cout << "failure: cliente nao esta no cinema" << endl;
    }

    string toString(){
        stringstream ss;
        ss << "[ ";
        for(Cliente * cliente : cadeiras)
            if(cliente != nullptr)
                ss << cliente->toString() << " ";
            else
                ss << "- ";
        ss << "]";
        return ss.str();
    }
};

struct Controller{
    Sala sala;

    void shell(string line){
        stringstream in(line);
        string op;
        in >> op;
        if(op == "show"){
            cout << sala.toString() << endl;
        }else if(op == "init"){
            int qtd;
            in >> qtd;
            sala = Sala(qtd);
        }else if(op == "reservar"){
            string id, fone;
            int ind;
            in >> id >> fone >> ind;
            sala.reservar(id, fone, ind);
        }else if(op == "cancelar"){
            string id;
            in >> id;
            sala.cancelar(id);
        }
        else
            cout << "fail: comando invalido" << endl;
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            cout << "$" << line << endl;
            if(line == "end")
                return;
            shell(line);
        }
    }
};

int main(){
    Controller c;
    c.exec();
    return 0;
}