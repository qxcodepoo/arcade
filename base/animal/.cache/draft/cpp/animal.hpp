#include "fn.hpp"

struct Animal {
    std::string especie;
    std::string barulho;
    int estagio;

    Animal(std::string especie, std::string barulho):
        especie(especie), barulho(barulho), estagio(0) {
    }

    std::string fazerBarulho() const {
        if (estagio == 0) {
            return "---";
        }
        if (estagio == 4) {
            return "RIP";
        }
        return this->barulho;
    }

    void envelhecer(int nivel) {
        estagio += nivel;
        if (estagio >= 4) {
            fn::print("warning: {} morreu\n", especie);
            estagio = 4;
        }
    }

    std::string str() const {
        return fn::format("{}:{}:{}", especie, estagio, barulho);
    }
};

std::ostream& operator<<(std::ostream& os, const Animal& animal) {
    return os << animal.str();
}