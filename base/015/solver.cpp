#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;


class Fone{
public:
    string id;
    string number;
    Fone(string serial = ""){
        stringstream ss(serial);
        getline(ss, this->id, ':');
        ss >> this->number;
    }
    Fone(string id, string number){
        this->id = id;
        this->number = number;
    }

    static bool validar(string number){
        string valid = "0123456789()-.";
        for(char c : number)
            if(valid.find(c) == string::npos)
                return false;
        return true;
    }
    friend ostream& operator<<(ostream& out, const Fone& fone){
        out << fone.id << ":" << fone.number;
        return out;
    }
};
    

class Contato{
    string name;
    vector<Fone> fones;
public:
    Contato(string name = ""):
        name(name){
    }
    string getName(){
        return name;
    }
    void addFone(string id, string number){
        if(Fone::validar(number))
            fones.push_back(Fone(id, number));
        else
            cout << "fail: fone invalido" << endl;
    }
    void rmFone(int index){
        if(index < 0 || index >= (int) fones.size())
            return;
        fones.erase(fones.begin() + index);
    }
    vector<Fone> getFones(){
        return fones;
    }
    friend ostream& operator<<(ostream& out, Contato& contato){
        out << "- " << contato.getName();
        int i = 0;
        for(Fone fone : contato.getFones()){
            out << " [" << i << ":" << fone << "]";
            i++;
        }
        return out;
    }
};

bool compare_contato(Contato one, Contato two){
    return one.getName() < two.getName();
}


class Agenda {
    vector<Contato> contatos;

    int findContato(string id){
        for(int i = 0; i < (int) contatos.size(); i++)
            if(contatos[i].getName() == id)
                return i;
        return -1;
    }

public:
    //add contato que não existe ou adicionar fones ao contato que existe
    void addContato(string name, vector<Fone> fones) {
        int ind = findContato(name);
        if(ind == -1){
            contatos.push_back(Contato(name));
            //opcao 1
            //std::sort(contatos.begin(), contatos.end(), [](auto a, auto b){return a.name < b.name;});
            std::sort(contatos.begin(), contatos.end(), compare_contato);
            ind = findContato(name);
        }
        for(Fone fone : fones)
            contatos[ind].addFone(fone.id, fone.number);
        
    }

    void rmContato(string name) {
        int ind = findContato(name);
        if(ind != -1)
            contatos.erase(contatos.begin() + ind);
    }

    Contato * getContato(string id) {
        int ind = findContato(id);
        if(ind != -1)
            return &contatos[ind];
        return nullptr;
    }

    vector<Contato> getContatos() {
        return contatos; //retorna a cópia
    }

    vector<Contato> search(string pattern) {
        vector<Contato> resp;
        for(auto& cont : contatos){
            stringstream ss;
            ss << cont;
            if(ss.str().find(pattern) != string::npos)
                resp.push_back(cont);
        }
        return resp;
    }
    friend ostream& operator<<(ostream& out, Agenda& agenda){
        for(auto contato : agenda.contatos)
            out << contato << "\n";
        return out;
    }
};

template <class T>
T get(stringstream& ss){
    T t;
    ss >> t;
    return t;
}

int main(int argc, char const *argv[]){
    Agenda agenda;
    while(true){
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        }
        else if(cmd == "add"){//name id:fone id:fone ...
            string name, serial;
            ss >> name;
            vector<Fone> fones;
            while(ss >> serial){
                fones.push_back(Fone(serial));
            }
            agenda.addContato(name, fones);
        }
        else if(cmd == "agenda"){
            cout << agenda;
        }
        else if(cmd == "rmFone"){//id index
            string id;
            int index;
            ss >> id >> index;
            Contato * contato = agenda.getContato(id);
            if(contato != nullptr)
                contato->rmFone(index);
        }
        else if(cmd == "rmContato"){//id
            string id;
            ss >> id;
            agenda.rmContato(id);
        }
        else if(cmd == "search"){//pattern
            string pattern;
            ss >> pattern;
            for(Contato contato : agenda.search(pattern))
                cout << contato << endl;
        }
        else{
            cout << "fail: comando invalido\n";
        }
    }
}