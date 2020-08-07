#ifndef AGENDA_H
#define AGENDA_H
#include <iostream>
#include <vector>
#include <map>
#include "split.h"


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

class Controller {
    Agenda agenda;

    //recebe uma linha de comando e retorna a saida
    string process(string line) {
        auto ui = split(line, ' ');
        auto cmd = ui[0];

        if(cmd == "help"){
            return  HELP_TEXT;
        }
        if(cmd == "addContato"){
            agenda.addContato(Contato(ui[1]));
            return "done";
        }
        if(cmd == "rmContato"){
            agenda.rmContato(ui[1]);
            return "done";
        }
        if(cmd == "addFone"){
            Contato * cont = agenda.getContato(ui[1]);
            cont->addFone(Fone(ui[2], ui[3]));
            return "done";
        }
        if(cmd == "rmFone"){
            Contato * cont = agenda.getContato(ui[1]);
            cont->rmFone(ui[2]);
            return "done";
        }
        if(cmd == "show"){
            return agenda.getContato(ui[1])->toString();
        }
        if(cmd == "showAll"){
            string saida = "";
            for(auto elem : agenda.getContatos())
                saida += elem.toString() + "\n";
            return saida;
        }
        if(cmd == "search"){
            string saida = "";
            for(auto elem : agenda.search(ui[1]))
                saida += elem.toString() + "\n";
            return saida;
        }
        if(cmd == "fav"){
            agenda.favoritar(ui[1]);
            return "done";
        }
        if(cmd == "desfav"){
            agenda.desfavoritar(ui[1]);
            return "done";
        }
        if(cmd == "showFav"){
            string saida = "";
            for(auto elem : agenda.getFavoritos())
                saida += elem.toString() + "\n";
            return saida;
        }
        if(cmd == "fim")
            return "";
        return "comando invalido";
    }

public:
    void commandLine(){
        string line = "";
        while(line != "fim"){
            cout << "(help): ";
            getline(cin, line);
            if(line != ""){
                cout << ">> " << line << endl;
                cout << process(line);
            }
        }
    }
};

int main()
{
    Controller c;
    c.commandLine();
}

#endif // AGENDA_H

