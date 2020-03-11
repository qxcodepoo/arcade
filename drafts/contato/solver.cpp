#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Fone{
    string label;
    string fone;

    Fone(string label = "", string fone = ""){
        this->label = label;
        this->fone = fone;
    }
    static bool validate(string fone){
        string valid = "0123456789().";
        for(auto c: fone)
            if(valid.find(c) == string::npos) //nao encontrou
                return false;
        return true;
    }

    string toString(){
        stringstream ss;
        ss << this->label << ":" << this->fone;
        return ss.str();
    }
};

struct Contato{
    vector<Fone> fones;
    string nome;
    Contato(string nome = "vazio"):
        nome(nome){
    }

    void add(Fone fone){
        fones.push_back(fone);
    }

    bool rm(int indice){
        if(indice < 0 || indice >= (int) fones.size()){
            cout << "fail: indice invalido" << endl;
            return false;
        }
        fones.erase(fones.begin() + indice);
        return true;
    }

    string toString(){
        stringstream ss;
        ss << this->nome << "=>";
        for(int i = 0; i < (int) fones.size(); i++)
            ss << "[" << i << ":" << fones[i].label << ":" << fones[i].fone << "]";
        return ss.str();
    }
};

struct Controller{
    Contato cont;
    Controller(){
    }
    void shell(string line){
        stringstream in(line);
        string op;
        in >> op;
        if(op == "show"){
            cout << cont.toString() << endl;
        }else if(op == "init"){
            string nome;
            in >> nome;
            cont.nome = nome;
        }else if(op == "add"){
            string label, fone;
            in >> label >> fone;
            if(!Fone::validate(fone))
                cout << "fail: fone invalido" << endl;
            else{
                cont.add(Fone(label, fone));
            }
        }else if(op == "rm"){
            int indice;
            in >> indice;
            cont.rm(indice);
        }else if(op == "update"){
            string nome;
            in >> nome;
            cont = Contato(nome);
            string fone_serial;
            while(in >> fone_serial){
                stringstream ss(fone_serial);
                string label, fone;
                getline(ss, label, ':');
                getline(ss, fone);
                if(Fone::validate(fone))
                    cont.add(Fone(label, fone));
            }
        }
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