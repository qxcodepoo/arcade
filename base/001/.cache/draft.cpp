#include <iostream>
#include <sstream>
#include <iomanip>
#include "aux.hpp"

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

int main() {
    Calculator c(0);
    aux::Chain chain;
    aux::Param param;

    // função para obter um parâmetro convertido para inteiro
    auto par_int = [&param](int index) { return aux::to<int>(param[index]); };

    chain["show"]   = [&]() { std::cout << c << std::endl;         };
    chain["init"]   = [&]() {  c = Calculator(par_int(1)          ); };
    chain["charge"] = [&]() { c.chargeBattery(par_int(1)          ); };
    chain["sum"]    = [&]() {           c.sum(par_int(1), par_int(2)); };
    chain["div"]    = [&]() {      c.division(par_int(1), par_int(2)); };

    aux::execute(chain, param);
}

