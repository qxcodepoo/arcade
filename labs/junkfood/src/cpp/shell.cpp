#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

template<typename CONTAINER, typename FUNC>
string map_join(const CONTAINER& cont, FUNC func, string delim) {
    stringstream ss;
    for (auto it = cont.begin(); it != cont.end(); it++) {
        ss << (it == cont.begin() ? "" : delim);
        ss << func(*it);
    }
    return ss.str();
}

// @DROP
struct Slot{
    string nome;
    int qtd;
    double preco;

    Slot(string nome = "empty", int qtd = 0, double preco = 0.0) {
        this->nome = nome;
        this->qtd = qtd;
        this->preco = preco;
    }


    string str() const {
        stringstream ss;
        ss << "[" << setw(8) << nome << " :"
           << setw(2) << qtd << " U :"
           << setw(5) << fixed << setprecision(2) << preco << " RS]";
        return ss.str();
    }
};


class Machine{
    vector<Slot> espirais;
    double saldo, lucro;
public:
    Machine(int qtd = 0):
        espirais(qtd) {
        saldo = 0;
        lucro = 0;
    }

    Slot& get(int indice) {
        if((indice < 0)||(indice >= (int) espirais.size()))
            throw "fail: indice nao existe";
        return espirais[indice];
    }

    void set(int indice, string name, int qtd, double price) {
        Slot espiral(name, qtd, price);
        if(espiral.qtd < 0)
            throw "fail: valores invalidos";
        get(indice) = espiral;
    }

    void limpar(int indice) {
        get(indice) = Slot();
    }
    
    void inserirDinheiro(double value) {
        if(value <= 0)
            throw "fail: fail: valores invalidos";
        saldo += value;
    }

    double pedirTroco() {
        auto troco = saldo;
        saldo = 0;
        return troco;
    }

    void comprar(int ind) {
        if ((ind < 0) || (ind >= (int)espirais.size()))
            throw "fail: indice nao existe";
        if(saldo < get(ind).preco)
            throw "fail: saldo insuficiente";
        if(espirais[ind].qtd == 0)
            throw "fail: espiral sem produtos";
        saldo -= get(ind).preco;
        get(ind).qtd -= 1;
        cout << "voce comprou um " << get(ind).nome << endl;
    }

    double getSaldo() const {
        return saldo;
    }

    string str() const {
        stringstream ss;
        ss << "saldo: " << fixed << setprecision(2) << saldo << endl;
        for(int i = 0; i < (int)espirais.size(); i++)
            ss << i << " " << espirais[i].str() << endl;
        string output = ss.str();
        output.pop_back();
        return output;
    }
};


// @KEEP

int main() {
    // @DROP
    Machine machine(0);
    // @KEEP
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        try {
            if (cmd == "show") {
                // IMPRIMIR
                // @DROP            
                cout << machine.str() << endl;                        
            } else if (cmd == "init") {
                // @COM
                int n_espirais {};
                ss >> n_espirais;
                // @DROP
                machine = Machine(n_espirais);                          
            } else if (cmd == "limpar") {
                // @COM
                int indice {};
                ss >> indice;
                // @DROP
                machine.limpar(indice);                                   
            } else if (cmd == "dinheiro") {
                // @COM
                int value {};
                ss >> value;
                // @DROP
                machine.inserirDinheiro(value);                          
            } else if (cmd == "comprar") {
                // @COM
                int index {};
                ss >> index;
                // @DROP
                machine.comprar(index);                                  
            } else if (cmd == "set") {
                // @COM
                int index {};
                string name;
                int qtd {};
                double price {};
                ss >> index >> name >> qtd >> price;
                // @DROP
                machine.set(index, name, qtd, price);         
            } else if (cmd == "troco") {
                // @DROP
                double troco = machine.pedirTroco();
                cout << "voce recebeu " << fixed << setprecision(2) << troco << " RS" << endl;
            } else if (cmd == "end") {
                break;
            } else {
                cout << "comando invalido" << endl;
            }
        } catch (const char* e) {
            cout << e << endl;
        }
    }
}
