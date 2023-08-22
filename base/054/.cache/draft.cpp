#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

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

int main () {
    Animal animal("", "");
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        
        if (args[0] == "init") {
            animal = Animal(args[1], args[2]);
        }
        else if (args[0] == "grow") {
            animal.envelhecer(+args[1]);
        }
        else if (args[0] == "noise") {
            fn::write(animal.fazerBarulho());
        }
        else if (args[0] == "show") {
            fn::write(animal);
        }
        else if (args[0] == "end") {
            break;
        }
        else {
            fn::write("fail: comando invalido");
        }
    }
}
