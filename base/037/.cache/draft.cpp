#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <string>
#include <utility>
#include <aux.hpp>


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
        int i = 0;
        std::stringstream os;
        os  << "Caixas: |"
            << join(this->caixas, "|", [&i](auto p) {
                std::stringstream ss; 
                ss << " " << i++ << ":"<< std::setw(5) << (p == nullptr ? "-----" : p->getNome()) << " ";
                return ss.str();
            })  
            << "|\nEspera: " (esperando | join(this->esperando, ", ", [](auto x) { return *x;}) << "]";
        return os.str();
    }
};

std::ostream& operator<<(std::ostream& os, const Mercantil& b) {
    return (os << b.str());
}


#include <ranges>
using namespace std::ranges;

int main() {
    aux::Chain chain;
    aux::Param par;
    
    Mercantil bank(0);

    chain["init"]   = [&]() {   bank = Mercantil(aux::to<int>(par[1])); };
    chain["call"]   = [&]() { bank.chamarNoCaixa(aux::to<int>(par[1])); };
    chain["finish"] = [&]() {     bank.finalizar(aux::to<int>(par[1])); };
    chain["arrive"] = [&]() { bank.chegar(make_shared<Pessoa>(par[1])); };
    chain["show"]   = [&]() { aux::show << bank; };

    aux::execute(chain, par);    
}

template <class CONTAINER, class LAMBDA>
std::string join(CONTAINER container, const std::string& delimiter, LAMBDA fn) {
    if(container.size() == 0)
        return "";
    std::ostringstream ss;
    for (const auto& item : container)
        ss << delimiter << fn(item);
    return ss.str().substr(delimiter.size());
}



