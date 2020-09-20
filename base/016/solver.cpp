#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

// raw string inicio
const char * HELP_TEXT = R"(# crud de contatos
addContato _idContato
rmContato  _idContato

# crud de telefone
addFone    _idContato _idFone _number
rmFone     _idContato _idFone

# buscas e visualizações
show       _idContato
showAll
search     _pattern

# favoritos
fav        _idContato
desfav     _idContato
showFav

# default
fim
help)";
// raw string fim

class Fone {
public:
    string idFone;
    string numero;

    Fone(string id, string numero) {
        idFone = id;
        this->numero = numero;
    }

    static bool validate(string numero) {
        string data = "1234567890()- ";
        for(auto c : numero)
            if(data.find(c) == string::npos)
                return false;
        return true;
    }

    bool operator==(const Fone& other){
        return this->idFone == other.idFone;
    }

    string toString(){
        return "[" + this->idFone + " " + this->numero + "]";
    }

    friend ostream& operator<<(ostream& out, Fone fone){
        out << "[" << fone.idFone << " " << fone.numero + "]";
        return out;
    }
};
    


class Contato {
public:
    string id;
    vector<Fone> fones;
    bool favorited;
    Contato(string id = ""){
        this->id = id;
        this->favorited = false;
    }

    void addFone(Fone fone){
        fones.push_back(fone);
    }

    void rmFone(int index){
        fones.erase(fones.begin() + index);
    }

    vector<Fone> getAllFones(){
        return fones;
    }


    friend ostream& operator<<(ostream& out, Contato contato){
        out << (contato.favorited ? "@" : "-");
        out << " " << contato.id << " ";
        for(auto fone: contato.fones)
            out << fone.toString();
        return out;
    }
};

template <class T>
string toString(T t){
    stringstream ss;
    ss << t;
    return ss.str();
}

#include <algorithm>

class Agenda {
    map<string, Contato*> contatos; //vetor
    map<string, Contato*> favoritos;

public:
    void addContato(string id, vector<Fone> fones){
        //se nao existe, adicione

        std::sort(contatos.begin(), contatos.end(), [](Contato one, Contato two) -> bool {
            return one.id < two.id;
        });
    }

    void rmContato(string nome) {
        if(contatos.erase(nome))
            favoritos.erase(nome);
    }

    Contato * getContato(string nome){
        auto it = contatos.find(nome);
        if(it == contatos.end())
            return nullptr;
        return it->second;
    }

    void favoritar(string nome) {
        
    }

    void desfavoritar(string nome){
        
    }

    vector<Contato> getFavoritos(){
        vector<Contato> resp;
        for(auto par : favoritos)
            resp.push_back(*par.second);
        return resp;
    }

    vector<Contato> getContatos(){
        vector<Contato> resp;
        for(auto par : contatos)
            resp.push_back(*par.second);
        return resp;
    }

    vector<Contato> search(string pattern){
        vector<Contato> resp;
        for(auto par : contatos){
            if(toString(*par.second).find(pattern) != string::npos)
                resp.push_back(*par.second);
        }
        return resp;
    }
};


Fone format_fone(string sfone){
    stringstream ss(sfone);
    string id, fone;
    getline(ss, id, '-');
    ss >> fone;
    return Fone(id, fone);
}

template <class T>
T get(stringstream& ss){
    T value;
    ss >> value;
    return value;
}

int main(){
    Agenda agenda;
    while(true){
        string line, cmd;
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;
        try{
            if(cmd == "help"){
                cout << HELP_TEXT << endl;
            }
            else if(cmd == "add"){ //id label-fone label-fone label-fone
                string name = get<string>(ss);
                vector<Fone> fones;
                string fonestr;
                while(ss >> fonestr)
                    fones.push_back(format_fone(fonestr));

                Contato * contato = agenda.getContato(name);
                if(contato == nullptr){
                    Contato cont(name);
                    for(Fone fone : fones)
                        cont.addFone(fone);
                    agenda.addContato(cont);
                }else{
                    for(Fone fone : fones)
                        contato->addFone(fone);
                }
            }
            else if(cmd == "rmContato"){
                agenda.rmContato(get<string>(ss));
            }
            else if(cmd == "rmFone"){
                Contato * cont = agenda.getContato(get<string>(ss));
                cont->rmFone(get<int>(ss));
            }
            else if(cmd == "show"){
                agenda.getContato(ui[1])->toString();
            }
            else if(cmd == "showAll"){
                for(auto elem : agenda.getContatos())
                    cout << elem.toString() + "\n";
            }
            else if(cmd == "search"){
                for(auto elem : agenda.search(ui[1]))
                    cout << elem.toString() + "\n";
            }
            else if(cmd == "fav"){
                agenda.favoritar(ui[1]);
            }
            else if(cmd == "desfav"){
                agenda.desfavoritar(ui[1]);
            }
            else if(cmd == "favorited"){
                for(auto elem : agenda.getFavoritos())
                    cout << elem.toString() + "\n";
            }
            else{
                cout << "comando invalido";
            }
        }catch(string e){
            cout << e << endl;
        }
    }
}