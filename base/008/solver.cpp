#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

template<typename K, typename V>
class Repository{
    map<K, V> rep;
    string _typename;
public:
    Repository(string _typename = ""){
        this->_typename = _typename;
    }
    void add(K k, V v){
        if(rep.count(k) != 0)
            throw "fail: " + _typename + " ja existe";
        rep[k] = v;
    }

    V& get(K k){
        auto it = rep.find(k);
        if(it == rep.end())
            throw "fail: " + _typename + " nao existe";
        return it->second;
    }

    bool existe(K k){
        return rep.count(k) != 0;
    }

    void remove(K k){
        auto it = rep.find(k);
        if(it == rep.end())
            throw "fail: " + _typename + " nao existe";
        rep.erase(it);
    }
    
    vector<K> getKeys(){
        vector<K> keys;
        for(auto& par : rep)
            keys.push_back(par.first);
        return keys;
    }

    vector<pair<K, V>> getPairs(){
        vector<K> pairs;
        for(auto& par : rep)
            pairs.push_back(par);
        return pairs;
    }
    
    vector<V> getValues(){
        vector<V> values;
        for(auto& par : rep)
            values.push_back(par.second);
        return values;
    }
};


class Cliente{
public:
    string name;
    string fullname;
    float saldo;

    Cliente(string name = "", string fullname = ""){
        this->name = name;
        this->fullname = fullname;
        this->saldo = 0;
    }
    friend ostream& operator<<(ostream &os, Cliente cliente);
};
ostream& operator<<(ostream &os, Cliente cliente){
    os << cliente.name << " : " << cliente.fullname
       << " : " << cliente.saldo;
    return os;
}

class Transacao{
public:
    int id;
    string idCli;
    float value;
    Transacao(int id = 0, string idCli = "", float value = 0.0){
        this->id = id;
        this->idCli = idCli;
        this->value = value;
    }
};

ostream& operator<<(ostream& os, Transacao tr){
    os << "id:" << tr.id << " [" << tr.idCli << " " << tr.value << "]";
    return os;
}

template<typename T>
T read(stringstream& ss){
    T t;
    ss >> t;
    return t;
}

class Agiota{
public:
    Repository<string, Cliente> repCli;
    Repository<int, Transacao> repTr;
    int nextTrId = 0;
    float saldo;

    Agiota(float saldo = 0.0):
        repCli("cliente"), repTr("transacao"){
        this->saldo = saldo;
    }

    void pushTransacao(string idCli, float value){
        repTr.add(nextTrId, Transacao(nextTrId, idCli, value));
        nextTrId++;
    }
    void receber(string idCli, float value){
        Cliente& cliente = repCli.get(idCli);
        if(value > cliente.saldo)
            throw string("fail: valor maior que a divida");
        cliente.saldo -= value;
        this->saldo += value;
        pushTransacao(idCli, -value);
    }
    void emprestar(string idCli, float value){
        if(value > this->saldo)
            throw string("fail: fundos insuficientes");
        Cliente& cliente = repCli.get(idCli);
        cliente.saldo += value;
        this->saldo -= value;
        pushTransacao(idCli, value);
    }
    void matar(string idCli){
        repCli.remove(idCli);
        for(auto chave : repTr.getKeys()){
            if(repTr.get(chave).idCli == idCli)
                repTr.remove(chave);
        }
    }
};

string operator+(string s, int i){
    return s + to_string(i);
}

class Controller{
public:
    Agiota agiota;

    void shell(string line){
        stringstream ss(line);
        string op;
        ss >> op;
        if(op == "init"){
            agiota = Agiota(read<float>(ss)); 
        }else if(op == "addCli"){
            string nome, fullname;
            ss >> nome;
            getline(ss, fullname);
            agiota.repCli.add(nome, Cliente(nome, fullname.substr(1)));
        }else if(op == "resumo"){
            for(auto& cli : agiota.repCli.getValues())
                cout << cli << endl;
            cout << "saldo : " << agiota.saldo << endl;
        }else if(op == "matar"){
            agiota.matar(read<string>(ss));
        }else if(op == "emprestar"){
            string nome;
            float value;
            ss >> nome >> value;
            agiota.emprestar(nome, value);
        }else if(op == "filtrar"){
            auto idCli = read<string>(ss);
            for(auto& tr : agiota.repTr.getValues())
                if(tr.idCli == idCli)
                    cout << tr << endl;
            cout << "saldo: " << agiota.repCli.get(idCli).saldo  << endl;
        }else if(op == "receber"){
            string nome;
            float value;
            ss >> nome >> value;
            agiota.receber(nome, value);
        }else if(op == "historico"){
            for(auto& tr : agiota.repTr.getValues())
                cout << tr << endl;
        }else
            cout << "fail: comando invalido" << endl;
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            cout << "$" << line << endl;
            if(line == "end")
                break;
            try{
                shell(line);
            }catch(string s){
                cout << s << endl;
            }
        }
    }
};

int main(){
    Controller controller;
    controller.exec();
}


