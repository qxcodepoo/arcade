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

class Adapter {
    Calculator c;
public:
    void init() {
        c = Calculator(0);
    }
    void show() {
        std::cout << c.str() << std::endl;
    }
    void init(int batteryMax) {
        (void) batteryMax;
        c = Calculator(batteryMax);
    }
    void charge(int value) {
        (void) value;
        c.chargeBattery(value);
    }
    void sum(int a, int b) {
        (void) a;
        (void) b;
        c.sum(a, b);
    }
    void div(int num, int den) {
        (void) num;
        (void) den;
        c.division(num, den);
    }
};


int main() {
    Adapter adp;

    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write(line);

        if      (args[0] == "end"   ) { break;                           }
        else if (args[0] == "show"  ) { adp.show();                      }
        else if (args[0] == "init"  ) { adp.init(+args[1]);              }
        else if (args[0] == "charge") { adp.charge(+args[1]);            }
        else if (args[0] == "sum"   ) { adp.sum(+args[1], +args[2]);     }
        else if (args[0] == "div"   ) { adp.div(+args[1], +args[2]);     }
        else                          { fn::write("fail: comando invalido"); }
    }
}