#include <iostream>
#include <list>
#include <memory>
#include <sstream>
#include <utility>
#include <iomanip> //setprecision
#include <aux.hpp>


struct Grafite{
    float calibre;
    std::string dureza;
    int tamanho;

    Grafite(float calibre, std::string dureza, int tamanho) {
        this->calibre = calibre;
        this->dureza = dureza;
        this->tamanho = tamanho;
    }

    std::string str() const {
        std::ostringstream os;
        os << std::fixed << std::setprecision(1) << calibre << ":" << dureza << ":" << tamanho;
        return os.str();
    }

    int desgastePorFolha() {
        if (dureza == "HB")
            return 1;
        else if (dureza == "2B")
            return 2;
        else if (dureza == "4B")
            return 4;
        else
            return 6;
    }
};
std::ostream& operator<<(std::ostream& os, Grafite g) {
    return os << g.str();
}
struct Lapiseira{
    float calibre {0.f};
    std::shared_ptr<Grafite> grafite {nullptr};
    std::list<std::shared_ptr<Grafite>> tambor;

    Lapiseira(float calibre = 0.0) { //todo calibre{calibre} {
    }
    ~Lapiseira() {
    }

    std::string str() const {
        return {}; // todo
    }

    bool inserir(std::shared_ptr<Grafite> grafite) {
        return {}; // todo

    }

    std::shared_ptr<Grafite> remover() {
        return {}; // todo
    }

    void write() {
    }
    void puxar() {
    }
};

std::ostream& operator<<(std::ostream& os, const Lapiseira& l) {
    return os << l.str();
}

int main() {
    aux::Chain chain;
    aux::Param param;
    Lapiseira lapiseira;

    auto FLOAT = [&param](int index) {return aux::to<float>(param[index]);};
    auto __INT = [&param](int index) {return aux::to<int>(param[index]);};

    chain["init"]   = [&]() { lapiseira = Lapiseira(FLOAT(1)); };
    chain["show"]   = [&]() { std::cout << lapiseira << std::endl; };
    chain["insert"] = [&]() { lapiseira.inserir(make_shared<Grafite>(FLOAT(1), param[2], __INT(3))); };
    chain["remove"] = [&]() { lapiseira.remover(); };
    chain["pull"]   = [&]() { lapiseira.puxar(); };
    chain["write"]  = [&]() { lapiseira.write(); };

    aux::execute(chain, param);
}
