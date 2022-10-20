#include <iostream>
#include <sstream>
#include <iomanip>

struct Calculator {
    int batteryMax;
    int battery;
    float display;

    Calculator(int batteryMax) {
    }

    void chargeBattery(int value) { 
    }

    bool useBattery() {
        return {}; // todo 
    }

    void sum(int a, int b) { 
    }

    void division(int num, int den) {
    }

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

#include <aux.hpp>

int main() {
    Calculator c(0);
    aux::Chain chain;
    aux::Param ui;

    // função para obter um parâmetro convertido para inteiro
    auto par2int   = LAMBDAE(&ui, index, ui.at(index) | aux::STR2<int>());                            //converte de string para int

    chain["show"]   = [&]() { std::cout << c << std::endl;         };
    chain["init"]   = [&]() {  c = Calculator(par2int(1)          ); };
    chain["charge"] = [&]() { c.chargeBattery(par2int(1)          ); };
    chain["sum"]    = [&]() {           c.sum(par2int(1), par2int(2)); };
    chain["div"]    = [&]() {      c.division(par2int(1), par2int(2)); };

    aux::execute(chain, ui);
}

