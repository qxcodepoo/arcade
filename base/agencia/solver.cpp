#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <sstream>

using namespace std;

struct Conta{
    int id;
    float saldo;
    string idCliente;
    string tipo;

    Conta(int id, string idCliente){
        this->id = id;
        this->idCliente = idCliente;
    }

    virtual void atualizarMes() = 0;

    void sacar(float value){
        if(saldo >= value)
            saldo -= value;
        else
            throw string("fail: saldo insuficiente");
    }
    void depositar(float value){
        saldo += value;
    }
    void transferir(Conta& other, float value){
        this->sacar(value);
        other.depositar(value);
    }
    virtual string toString(){
        char saida[200];
        sprintf(saida, "%d:%s:%.2f:%s", 
            this->id, this->idCliente.c_str(), this->saldo, this->tipo.c_str());
        return string(saida);
    }
};

struct ContaCorrente : public Conta{

    ContaCorrente(int id, string idClient): Conta(id, idClient){
        this->tipo = "CC";
    }
    virtual void atualizarMes(){
        saldo -= 20;
    }
};

struct ContaPoupanca : public Conta{
    ContaPoupanca(int id, string idClient): Conta(id, idClient){
        this->tipo = "CP";
    }
    virtual void atualizarMes(){
        saldo *= 1.01;
    }
};

struct Cliente{
    string idCliente;
    vector<shared_ptr<Conta>> contas;
    Cliente(string id){
        this->idCliente = id;
    }
};

struct Agencia{
    map<string, shared_ptr<Cliente>> clientes;
    map<int, shared_ptr<Conta>> contas;
    int nextContaId {};

    Agencia(){}

    void addCli(string id){
        if(clientes.find(id) == clientes.end()){
            auto client = make_shared<Cliente>(id);
            auto cc = make_shared<ContaCorrente>(nextContaId, id);
            contas[nextContaId++] = cc;
            auto cp = make_shared<ContaPoupanca>(nextContaId, id);
            contas[nextContaId++] = cp;
            client->contas.push_back(cc);
            client->contas.push_back(cp);
            clientes[id] = client;
        }
    }

    Conta& getConta(int id){
        try{
            return *contas.at(id);
        }catch(exception& e){
            throw string("fail: conta nao encontrada");
        }
    }

    string toString(){
        stringstream ss;
        for(auto& pair : contas)
            ss << pair.second->toString() << "\n";
        return ss.str();
    }
};

int main(){
    string line, cmd;
    Agencia ag;
    while(true){
        try{
            getline(cin, line);
            cout << "$" << line << endl;
            stringstream ss(line);
            ss >> cmd;
            if(cmd == "end")
                break;
            else if(cmd == "addCli"){
                string idCliente;
                ss >> idCliente;
                ag.addCli(idCliente);
            }else if(cmd == "show"){
                cout << ag.toString();
            }else if(cmd == "saque"){
                int conta; float value;
                ss >> conta >> value;
                ag.getConta(conta).sacar(value);
            }else if(cmd == "deposito"){
                int conta; float value;
                ss >> conta >> value;
                ag.getConta(conta).depositar(value);
            }else if(cmd == "transf"){
                int contaDe, contaPara; float value;
                ss >> contaDe >> contaPara >> value;
                ag.getConta(contaDe).transferir(ag.getConta(contaPara), value);
            }else if(cmd == "update"){
                for(auto& par : ag.contas)
                    par.second->atualizarMes();
            }else{
                cout << "fail: comando invalido\n";
            }
        }catch(string e){
            cout << e << endl;
        }
    }
}