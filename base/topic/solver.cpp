#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Pass{
    string id;
    int idade;

    Pass(string id = "", int idade = 0  ){
        this->id = id;
        this->idade = idade;
    }
    string toString(){
        stringstream ss;
        ss << this->id << ":" << this->idade;
        return ss.str();
    }
};

struct Topic{
    vector<Pass*> cadeiras;
    int qtdPref;

    Topic(int lotacao = 0, int qtdPref = 0):
        cadeiras(lotacao, nullptr), qtdPref(qtdPref)
    {
    }

    ~Topic(){
        for(Pass * pass : cadeiras)
            delete(pass);
    }

    int find(string id){
        for(int i = 0; i < (int) cadeiras.size(); i++)
            if(cadeiras[i] != nullptr && cadeiras[i]->id == id)
                return i;
        return -1;
    }

    int findPref(){
        for(int i = 0; i < qtdPref; i++)
            if(cadeiras[i] == nullptr)
                return i;
        return -1;
    }
    
    int findNormal(){
        for(int i = qtdPref; i < (int) cadeiras.size(); i++)
            if(cadeiras[i] == nullptr)
                return i;
        return -1;
    }
    

    bool reservar(string id, int idade){
        if(this->find(id) != -1){
            cout << "fail: pass ja esta na topic" << endl;
            return false;
        }
        int pref = findPref();
        int norm = findNormal();
        if(pref == -1 && norm == -1){
            cout << "fail: topic lotada" << endl;
            return false;
        }
        int pos = 0;
        if(idade >= 65)
            pos = pref != -1? pref : norm;
        else
            pos = norm != -1? norm : pref;
        cadeiras[pos] = new Pass(id, idade);
        return true;
    }

    bool cancelar(string id){
        for(int i = 0; i < (int) cadeiras.size(); i++){
            if(cadeiras[i] != nullptr && cadeiras[i]->id == id){
                delete cadeiras[i];
                cadeiras[i] = nullptr;
                return true;
            }
        }
        cout << "fail: pass nao esta na topic" << endl;
        return false;
    }

    string toString(){
        stringstream ss;
        ss << "[ ";
        for(int i = 0; i < (int) cadeiras.size(); i++){
            ss << (i < qtdPref ? "@" : "=");
            if(cadeiras[i] != nullptr)
                ss << cadeiras[i]->toString();
            ss << " ";
        }
        ss << "]";
        return ss.str();
    }
};

struct Controller{
    Topic topic;

    void shell(string line){
        stringstream in(line);
        string op;
        in >> op;
        if(op == "show"){
            cout << topic.toString() << endl;
        }else if(op == "init"){
            int qtd, pref;
            in >> qtd >> pref;
            topic = Topic(qtd, pref);
        }else if(op == "in"){
            string id;
            int idade;
            in >> id >> idade;
            topic.reservar(id, idade);
        }else if(op == "out"){
            string id;
            in >> id;
            topic.cancelar(id);
        }else
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