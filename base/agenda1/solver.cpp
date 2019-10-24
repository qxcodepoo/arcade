#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;

class Contato {
public:
    string m_id;
    vector<string> m_fones;

    Contato(string id = ""){
        this->m_id = id;
    }

    void addFone(string number){
        if(std::find(m_fones.begin(), m_fones.end(), number) == m_fones.end())
            m_fones.push_back(number);
    }

    void rmFone(int ind){
        if(ind >= 0 && ind <= (int) m_fones.size())
            m_fones.erase(m_fones.begin() + ind);
    }

    vector<string> getFones(){
        return m_fones;
    }

    string toString(){
        string saida = "- " + m_id + " ";
        int i = 0;
        for(auto fone: m_fones)
            saida += "[" + to_string(i++) + ":" + fone + "]";
        return saida;
    }
};

class Agenda {
    vector<Contato> m_contatos;

    vector<Contato>::iterator getIterator(string id){
        for(auto it = m_contatos.begin(); it != m_contatos.end(); it++)
            if(it->m_id == id)
                return it;
        throw string("fail: contato " + id + " nao existe");
    }

public:
    //add ou merge de contato
    void addContato(Contato contato) {
        try{
            auto it = getIterator(contato.m_id);
            if(it != m_contatos.end()){
                for(auto fone : contato.m_fones)
                    it->addFone(fone);
            }
        }catch(string e){
            m_contatos.push_back(contato);
        }
        std::sort(m_contatos.begin(), m_contatos.end(), [](auto a, auto b){return a.m_id < b.m_id;});
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
