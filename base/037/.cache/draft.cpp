#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <fn.hpp>

class Pessoa {
    std::string nome;
public:
    Pessoa(std::string nome) { //todo 
    }
    std::string getNome() const {
        return {}; // todo 
    }
    std::string str() const {
        return {}; // todo
    }
};
std::ostream& operator<<(std::ostream& os, const Pessoa& p) {
    return (os << p.str());
}

class Mercantil {
    std::vector<std::shared_ptr<Pessoa>> caixas; //caixas do supermercado
    std::list  <std::shared_ptr<Pessoa>> esperando; //lista de clientes esperando

    bool validarIndice(int indice) {
        return {}; // todo
    }

public:
    Mercantil(int qtd_caixas) { //todo
    }
    
    void chegar(const std::shared_ptr<Pessoa>& person) {
    }

    bool chamarNoCaixa(int indice) {
        return {}; // todo
    }
    
    std::shared_ptr<Pessoa> finalizar(int indice) {
        return {}; // todo
    }

    std::string str() const {
        auto caixas_str = caixas | fn::MAP(FNT(c, c == nullptr ? "-----" : c->getNome()));
        return "Caixas: " + fn::tostr(caixas_str) + "\n" + "Espera: " + fn::tostr(esperando);
    }
};

std::ostream& operator<<(std::ostream& os, const Mercantil& b) {
    return (os << b.str());
}

int main() {
    Mercantil bank(0);
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if      (args[0] == "end"   ) { break;                                          }
        else if (args[0] == "init"  ) { bank = Mercantil(+args[1]);                     }
        else if (args[0] == "call"  ) { bank.chamarNoCaixa(+args[1]);                   }
        else if (args[0] == "finish") { bank.finalizar(+args[1]);                       }
        else if (args[0] == "arrive") { bank.chegar(std::make_shared<Pessoa>(args[1])); }
        else if (args[0] == "show"  ) { fn::write(bank);                                }
        else                          { fn::write("fail: comando invalido");            }
        
    }
}

