#include <iostream>
#include <sstream>
#include <iomanip>
#include "shell.hpp"

struct Calculator {
    int batteryMax;
    int battery;
    float display;

    //Inicia os atributos, battery e display começam com o zero.
    Calculator(int batteryMax) {
    }

    //Aumenta a bateria, porém não além do máximo.
    void chargeBattery(int value) { 
    }

    //Tenta gastar uma unidade da bateria e emite um erro se não conseguir.
    bool useBattery() {
        return {}; // todo 
    }

    //Se conseguir gastar bateria, armazene a soma no atributo display.
    void sum(int a, int b) { 
    }

    //Se conseguir gastar bateria e não for divisão por 0.
    void division(int num, int den) {
    }

    //Retorna o conteúdo do display com duas casas decimais.
    std::string str() { 
        std::stringstream ss;
        ss << "display = " << std::fixed << std::setprecision(2) << this->display;
        ss << ", battery = " << this->battery;
        return ss.str();
    }
};

std::ostream& operator<<(std::ostream& os, Calculator c) {
    return (os << c.str());
}

int main() {
    Calculator c(0);
    aux::Chain chain;
    aux::Param param;

    // função para obter um parâmetro convertido para inteiro
    auto __int = [&param](int index) { return aux::str2<int>(param[index]); };

    chain["show"]   = [&]() { std::cout << c << std::endl;         };
    chain["init"]   = [&]() {  c = Calculator(__int(1)          ); };
    chain["charge"] = [&]() { c.chargeBattery(__int(1)          ); };
    chain["sum"]    = [&]() {           c.sum(__int(1), __int(2)); };
    chain["div"]    = [&]() {      c.division(__int(1), __int(2)); };

    aux::evaluate(chain, param);
}
