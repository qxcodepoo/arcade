#include <iostream>
#include<vector>
#include<sstream>
using namespace std;

class Cliente{
public:
    string chave;
    string name;
    int saldo;
    // Construtor
    Cliente(string chave = "", string name = "", int saldo = 0):
        chave(chave), name(name), saldo(saldo)
    {
    }
    // toString
    string toString(){
        stringstream ss;
        ss << this->chave << " :" << this->name << " : " << this->saldo;
        return ss.str();
    }
};

class Transacao{
public:
    int ind;
    string id;
    int value;

    Transacao(int ind = 0, string id = "", int value = 0):
        ind(ind), id(id), value(value)
    {
    }

    string toString(){
        return "id:" + to_string(ind) + " [" + id + " " + to_string(value) + "]";
    }
};

class Agiota{
        //retorna indice no vector ou -1
    int findCliente(string chave){
        for(int i = 0; i < (int) clientes.size(); i++){
            if(clientes[i].chave == chave){
                return i;
            }
        }
        return -1;
    }
    
public:
    vector<Cliente> clientes;
    vector<Transacao> transacoes;
    int saldo;

    // Construtor
    Agiota(int saldo = 0):
        saldo(saldo)
    {
    }

    void pushTr(string user, int value){
        static int nextId = 0;
        transacoes.push_back(Transacao(nextId, user, value));
        nextId++;
    }

    string getSaldo(){
        stringstream ss;
        ss << "Saldo agiota: " << saldo <<endl;
        return ss.str();
    }

    Cliente * getCliente(string chave){
        int ind = findCliente(chave);
        if(ind == -1)
            return nullptr;
        return &clientes[ind];
    }

    // Adicionar cliente
    void inserir(string chave, string fullname){
        Cliente * pcli = getCliente(chave);
        if(pcli == nullptr)
            clientes.push_back(Cliente(chave, fullname, 0));
        else
            cout << "fail: cliente ja existe" << endl;
    }

    // Emprestar dinheiro
    bool emprestar(string chave, int value){
        if((this->saldo < value)){
            cout << "fail: fundos insuficientes" << endl;
            return false;
        }
        if(value <= 0){
            cout << "fail: operação invalida" << endl;
            return false;
        }
        Cliente * pcli = getCliente(chave);
        if(pcli == nullptr){
            cout << "fail: cliente nao existe" << endl;
            return false;
        }
        saldo -= value;
        pcli->saldo -= value;
        pushTr(chave, -value);
        return true;
    }

    bool receber(string chave, int value){
        Cliente * pcli = getCliente(chave);
        if(pcli == nullptr)
            return false;
        if(value > -pcli->saldo){
            cout << "fail: valor maior que a divida" << endl;
            return false;
        }else{
            pcli->saldo += value;
            pushTr(chave,value);
            saldo += value;
            return true;
        }
        return false;
    }

    bool matar(string name){
        int ind = findCliente(name);
        if(ind == -1)
            return false;
        clientes.erase(clientes.begin() + ind);
        for(int j = (int) transacoes.size() - 1; j >= 0; j--){
            if(name == transacoes[j].id)
                transacoes.erase(transacoes.begin() + j);
        }
        return true;
    }

    string showTransacoes(){
        stringstream ss;
        for(auto& tr : transacoes)
            ss << tr.toString() << endl;
        return ss.str();
    }

    string filterTransacoes(string name){
        auto * cli = getCliente(name);
        if(cli == nullptr)
            return "";
        stringstream ss;
        for(auto& tr : transacoes)
            if(tr.id == name)
                ss << tr.toString() << endl;
        ss << "saldo " << cli->chave << ": " << cli->saldo << endl;
        return ss.str();
    }

    // toString
    string showClientes(){
        stringstream ss;
        for(auto& cli : clientes)
            ss << cli.toString() << endl;
        return ss.str();
    }
};

struct Controller{
    Agiota agiota;

    void shell(string line){
        stringstream in(line);
        string op;
        in >> op;
        if(op == "init"){
            int valor;
            in >> valor;
            agiota = Agiota(valor);
        }else if(op == "help"){
            cout <<"init; show; tr; his; mostrar; mt; end; clear\n";
        }else if(op == "addCli"){
            string nome, chave;
            in >> chave;
            getline(in, nome,'\n');
            agiota.inserir(chave, nome);
        }else if(op == "resumo"){
            cout << agiota.showClientes();
            cout << "agiota : " << agiota.saldo << endl;
        }else if(op == "emprestar"){
            string chave;
            int value;
            in >> chave >> value;
            agiota.emprestar(chave, value);
        }else if(op == "historico"){
            cout << agiota.showTransacoes();
        }else if(op == "filtrar"){
            string name;
            in >> name;
            cout << agiota.filterTransacoes(name);
        }else if(op == "receber"){
            string name;
            int valor;
            in >> name >> valor;
            agiota.receber(name, valor);
        }else if(op == "matar"){
            string chave;
            in >> chave;
            agiota.matar(chave);
        }
        else
            cout << "fail: comando invalido" << endl;

    }

    void exec(){
        string line;

        while(true){
            getline(cin, line);
            cout << "$" <<  line << endl;
            if(line == "end")
                break;
            shell(line);
        }
    }
};


int main(){
    Controller controller;
    controller.exec();
    return 0;
}
