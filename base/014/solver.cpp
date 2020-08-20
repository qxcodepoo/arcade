#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
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




template <class T>
T get(stringstream& ss){
    T t;
    ss >> t;
    return t;
}

int main(int argc, char const *argv[]){
    Contato contato;
    while(true){
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        }
        else if(cmd == "init"){//name
            contato = Contato(get<string>(ss));
        }
        else if(cmd == "add"){//id fone
            string id = get<string>(ss);
            string fone = get<string>(ss);
            contato.addFone(id, fone);
        }
        else if(cmd == "rm"){//id
            contato.rmFone(get<int>(ss));
        }
        else if(cmd == "show"){
            cout << contato << "\n";
        }
        else{
            cout << "fail: comando invalido";
        }
    }
}