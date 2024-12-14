#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

struct Calculator {
    int batteryMax;
    int battery;
    float display;

    Calculator(int batteryMax = 0) : batteryMax(batteryMax) {
        this->battery = 0;
        this->display = 0.0f;
    }

    void chargeBattery(int value) {
        if(value < 0) {
            return;
        }
        this->battery += value;
        this->battery = std::min(this->battery, this->batteryMax);
    }

    void sum(int a, int b) {
        if(this->battery == 0){
            fn::write("fail: bateria insuficiente");
            return;
        }
        this->battery -= 1;
        this->display = (a + b);
        
    }

    void division(int num, int den) {
        if(this->battery == 0){
            fn::write("fail: bateria insuficiente");
            return;
        }
        this->battery -= 1;
        if(den == 0) {
            fn::write("fail: divisao por zero");
            return;
        }
        this->display = (float) num / den;
    }

    std::string str() const {
        return fn::format("display = {%.2f}, battery = {}", this->display, this->battery); 
    }
};

inline std::ostream& operator<<(std::ostream& os, const Calculator& c) {
    return (os << c.str());
}

int main() {
    Calculator calc;

    while (true) {
        auto line = fn::input();
        fn::write("$" + line);

        auto par = fn::split(line, ' ');
        auto cmd = par[0];

        if (cmd == "init") {
            int batteryMax = std::stoi(par[1]);
            calc = Calculator(batteryMax);
        } else if (cmd == "show") {
            fn::write(calc.str());
        } else if (cmd == "charge") {
            int increment = std::stoi(par[1]);
            calc.chargeBattery(increment);
        } else if (cmd == "sum") {
            int a = std::stoi(par[1]);
            int b = std::stoi(par[2]);
            calc.sum(a, b);
        } else if (cmd == "div") {
            int num = std::stoi(par[1]);
            int den = std::stoi(par[2]);
            calc.division(num, den);
        } else if (cmd == "end") {
            break;
        } else {
            fn::write("fail: comando invalido");
        }
    }


}