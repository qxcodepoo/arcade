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
};

class Contato {
public:
    string id;
    vector<Fone> fones;
    bool favorited;
    Contato(string id = ""){
        this->id = id;
        this->favorited = true;
    }

    void addFone(Fone fone){
        for(auto elem : fones)
            if(elem.idFone == fone.idFone)
                throw "fone " + fone.idFone + " ja existe";
        fones.push_back(fone);
    }

    void rmFone(string idFone){
        for(int i = 0; i < (int) fones.size(); i++){
            if(fones[i].idFone == idFone){
                fones.erase(fones.begin() + i);
                return;
            }
        }
        throw "fone " + idFone + " nao existe";
    }

    vector<Fone> getAllFones(){
        return fones;
    }

    string toString(){
        string saida = favorited ? "@" : "-";
        saida += " " + id + " ";
        for(auto fone: fones)
            saida += fone.toString();
        return saida;
    }
};

class Agenda {
    map<string, Contato> contatos;
    map<string, Contato*> favoritos;

public:
    void addContato(Contato contato){
        if(contatos.count(contato.id))
            throw "contato " + contato.id + " ja existe";
        contatos[contato.id] = contato;
    }

    void rmContato(string nome) {
        if(contatos.erase(nome))
            favoritos.erase(nome);
        else
            throw "contato " + nome + " nao existe";
    }

    Contato * getContato(string nome){
        auto it = contatos.find(nome);
        if(it == contatos.end())
            throw "contato " + nome + " nao existe";
        return &it->second;
    }

    void favoritar(string nome) {
        Contato * contato = getContato(nome);
        if(contato->favorited)
            return;
        contato->favorited = true;
        favoritos[nome] = contato;
    }

    void desfavoritar(string nome){
        Contato * contato = getContato(nome);
        if(!contato->favorited)
            return;
        contato->favorited = false;
        favoritos.erase(nome);
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
            resp.push_back(par.second);
        return resp;
    }

    vector<Contato> search(string pattern){
        vector<Contato> resp;
        for(auto par : contatos)
            if(par.second.toString().find(pattern) != string::npos)
                resp.push_back(par.second);
        return resp;
    }
};



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
            else if(cmd == "addContato"){
                agenda.addContato(Contato(ui[1]));
            }
            else if(cmd == "rmContato"){
                agenda.rmContato(ui[1]);
            }
            else if(cmd == "addFone"){
                Contato * cont = agenda.getContato(ui[1]);
                cont->addFone(Fone(ui[2], ui[3]));
            }
            else if(cmd == "rmFone"){
                Contato * cont = agenda.getContato(ui[1]);
                cont->rmFone(ui[2]);
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