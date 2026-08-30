#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <sstream>
#include <utility>
using namespace std;


// Função auxiliar para mapear e juntar elementos de um container
template <typename CONTAINER, typename FUNC>
auto map_join(const CONTAINER& c, FUNC f, const string& sep = ", ") {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ss << (it != c.begin() ? sep : "") << f(*it);
    }
    return ss.str();
}

// @DROP
class Pessoa {
    string nome;
public:
    Pessoa(string nome = ""):
        nome(nome) {
    }
    string getNome() const {
        return nome; 
    }
    string str() const {
        return nome;
    }
};

class Mercantil {
    vector<shared_ptr<Pessoa>> caixas; //caixas do supermercado
    list  <shared_ptr<Pessoa>> espera; //lista de clientes esperando

    bool validarIndice(int indice) {
        if (indice < 0 || indice >= (int) this->caixas.size()) {
            cout << "fail: caixa inexistente\n";
            return false;
        }
        return true;
    }

public:
    Mercantil(int qtd_caixas = 0):
        caixas(qtd_caixas, nullptr) {
    }
    
    void chegar(const shared_ptr<Pessoa>& person) {
        this->espera.push_back(person);
    }

    bool chamarNoCaixa(int indice) {
        if(!this->validarIndice(indice))
            return false;
        if (this->caixas[indice] != nullptr) {
            cout << "fail: caixa ocupado\n";
            return false;
        }
        if (this->espera.empty()) {
            cout << "fail: sem clientes\n";
            return false;
        }
        this->caixas[indice] = this->espera.front();
        this->espera.pop_front();
        return true;
    }
    
    shared_ptr<Pessoa> finalizar(int indice) {
        if(!this->validarIndice(indice))
            return nullptr;
        if (this->caixas[indice] == nullptr) {
            cout << "fail: caixa vazio\n";
            return nullptr;
        }
        return exchange(this->caixas[indice], nullptr);
    }

    string str() const {
        auto caixas_fn = [](auto c) { return c ? c->str() : "-----"; };
        auto caixas_str = map_join(this->caixas, caixas_fn, ", ");
        auto espera = map_join(this->espera, [](auto c) { return c->str(); }, ", ");
        stringstream ss;
        ss << "Caixas: [" << caixas_str << "]\n";
        ss << "Espera: [" << espera << "]";
        return ss.str();
    }
};

// @KEEP
int main() {
    // @DROP
    Mercantil mercantil(3);
    // @KEEP
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "show") { 
            // @DROP
            cout << mercantil.str() << endl;
        } else if (cmd == "init") { 
            // @COM
            int qtd_caixas;
            ss >> qtd_caixas;
            // @DROP
            mercantil = Mercantil(qtd_caixas);
        } else if (cmd == "arrive") { 
            // @COM
            string nome;
            ss >> nome;
            // @DROP
            mercantil.chegar(make_shared<Pessoa>(nome));
        } else if (cmd == "call") { 
            // @COM
            int indice;
            ss >> indice;
            // @DROP
            mercantil.chamarNoCaixa(indice);
        } else if (cmd == "finish") { 
            // @COM
            int indice;
            ss >> indice;
            // @DROP
            mercantil.finalizar(indice);
        } else {
            cout << "fail: comando invalido\n";
        }
    }
}
