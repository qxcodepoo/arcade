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

    //verifica se o indice é válido para acessar os caixas
    bool validarIndice(int indice) {
        return {}; // todo
    }

public:
    //inicializa esperando como uma lista de tamanho vazio
    //inicializa caixas como um vetor de tamanho qtd_caixas com todas as posições iguais a null
    Mercantil(int qtd_caixas) { //todo //número de caixas no mercado
    }
    
    //adiciona um cliente à lista de espera
    void chegar(const std::shared_ptr<Pessoa>& person) {
    }

    //1. verifica se o indice é válido
    //2. verifica se o caixa chamado está vazio
    //3. verifica se existe alguém na lista de espera
    //4. se tudo estiver ok, o primeiro cliente da lista de espera é movido para este caixa
    bool chamarNoCaixa(int indice) {
        return {}; // todo
    }
    //1. verifica se o indice é válido
    //2. verifica se este caixa possui um cliente
    //Se tudo estiver ok, o cliente é removido do caixa e o caixa volta a ser null para indicar que está vazio
    std::shared_ptr<Pessoa> finalizar(int indice) {
        return {}; // todo
    }

    std::string str() const {
        std::stringstream os;
        os << "Caixas: |";
        for (int i = 0; i < (int) this->caixas.size(); i++) {
            auto& caixa = this->caixas[i];
            os << " " <<  i << ":" ;
            if (caixa != nullptr)
                os << std::setw(5) << *caixa;
            else
                os << "-----";
            os << " |";
        }
        os << "\nEspera: " << aux::fmt(aux::map(this->esperando, [](auto x) { return *x;}), ", ");
        return os.str();
    }
};

std::ostream& operator<<(std::ostream& os, const Mercantil& b) {
    return (os << b.str());
}

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

