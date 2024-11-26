#include "fn.hpp"

struct Animal {
    std::string especie;
    std::string barulho;
    int estagio;

    Animal(std::string especie = "", std::string barulho = ""):
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

inline std::ostream& operator<<(std::ostream& os, const Animal& animal) {
    return os << animal.str();
}

struct Adapter {
    Animal animal;
    void init(std::string especie = "", std::string barulho = "") {
        (void) especie;
        (void) barulho;
        animal = Animal(especie, barulho);
    }

    void grow(int nivel) {
        (void) nivel;
        animal.envelhecer(nivel);
    }

    void noise() {
        std::cout << animal.fazerBarulho() << std::endl;
    }

    void show() {
        std::cout << animal.str() << std::endl;
    }
};

int main () {
    Adapter adp;

    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');

        fn::write(line); //test echo

        if      (args[0] == "end"  ) { break;                               }
        else if (args[0] == "init" ) { adp.init(args[1], args[2]);          }
        else if (args[0] == "grow" ) { adp.grow(+args[1]);                  }
        else if (args[0] == "noise") { adp.noise();                         }
        else if (args[0] == "show" ) { adp.show();                          }
        else                         { fn::write("fail: comando invalido"); }
    }
}