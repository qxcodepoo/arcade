#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

// Esse rascunho não possui o método de divisão, nem a invocação na main.

struct Calculator {
    int batteryMax;
    int battery;
    float display;

    Calculator(int batteryMax) ;

    void chargeBattery(int value);

    bool useBattery();

    void sum(int a, int b);

    std::string str() const {
        return fn::format("display = {%.2f}, battery = {}", this->display, this->battery); 
    }
};

std::ostream& operator<<(std::ostream& os, const Calculator& c) {
    return (os << c.str());
}

int main() {
    Calculator c(0);

    while(true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write('$' + line);

        if (args[0] == "show") {
            fn::write(c);
        }
        else if (args[0] == "init") { 
            c = Calculator(+args[1]);
        }
        else if (args[0] == "charge") {
            c.chargeBattery(+args[1]);
        }
        else if (args[0] == "sum") {
            c.sum(+args[1], +args[2]);
        }
        else if (args[0] == "end") {
            break;
        }
        else {
            fn::write("fail: comando inválido"); 
        }
    }
}
