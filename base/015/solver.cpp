#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;


class Fone{
    string id;
    string fone;
public:
    Fone(string id = "", string fone = ""){
        this->id = id;
        this->fone = fone;
    }

    static bool validar(string number){
        string valid = "0123456789()-.";
        for(char c : number)
            if(valid.find(c) == string::npos)
                return false;
        return true;
    }
    friend ostream& operator<<(ostream& out, const Fone& fone){
        out << fone.id << ":" << fone.fone;
        return out;
    }
};
    

class Contato{
    string name;
    vector<Fone> fones;
public:
    Contato(string name = "", vector<Fone> fones = vector<Fone>()):
        name(name), fones(fones){
    }
    string getName(){
        return name;
    }
    void addFone(string id, string fone){
        if(Fone::validar(fone))
            fones.push_back(Fone(id, fone));
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
        for(int i = 0; i < contatos.size(); i++)
            if(contatos[i].getName() == id)
                return i;
        return -1;
    }

public:
    //add ou merge de contato
    void addContato(string name, vector<Fone> fones) {
        int ind = findContato(name);
        if(ind == -1){
            contatos.push_back(Contato(name, fones));
        }
        //std::sort(contatos.begin(), contatos.end(), [](auto a, auto b){return a.name < b.name;});
    }

    void rmContato(string id) {
        m_contatos.erase(getIterator(id));
    }

    Contato * getContato(string id) {
        return &*getIterator(id);
    }

    vector<Contato> getContatos() {
        return m_contatos;
    }

    vector<Contato> search(string pattern) {
        vector<Contato> resp;
        for(auto& cont : m_contatos)
            if(cont.toString().find(pattern) != string::npos)
                resp.push_back(cont);
        return resp;
    }
    string toString(){
        string saida;
        for(auto contato : m_contatos)
            saida += contato.toString() + "\n";
        return saida;
    }
};

class Controller {
    Agenda agenda;

    //recebe uma linha de comando e retorna a saida
    void shell(string line) {
        stringstream ss(line);
        string op;
        ss >> op;

        if(op == "addContato"){
            string id, number;
            ss >> id;
            Contato contato(id);
            while(ss >> number){
                contato.addFone(number);
            }
            agenda.addContato(contato);
        }
        else if(op == "rmContato"){
            string id;
            ss >> id;
            agenda.rmContato(id);
        }
        else if(op == "rmFone"){
            string id;
            int ind;
            ss >> id >> ind;
            agenda.getContato(id)->rmFone(ind);
        }
        else if(op == "agenda"){
            cout << agenda.toString();
        }
        else if(op == "search"){
            string pattern;
            ss >> pattern;
            for(auto contato : agenda.search(pattern))
                cout << contato.toString() << "\n";
        }
        else 
            cout << "comando invalido\n";
    }

public:
    void exec(){
        string line = "";
        while(true){
            getline(cin, line);
            cout << "$" << line << "\n";
            if(line == "end")
                break;
            try{
                shell(line);
            }catch(string s){
                cout << s << "\n";
            }
        }
    }
};

int main(){
    Controller c;
    c.exec();
}
