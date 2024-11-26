#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

class Adapter {
    // Calculator c;
public:
    void init() {
        // c = Calculator(0);
    }
    void show() {
        // std::cout << c.str() << std::endl;
    }
    void init(int batteryMax) {
        (void) batteryMax;
        // c = Calculator(batteryMax);
    }
    void charge(int value) {
        (void) value;
        // c.chargeBattery(value);
    }
    void sum(int a, int b) {
        (void) a;
        (void) b;
        // c.sum(a, b);
    }
    void div(int num, int den) {
        (void) num;
        (void) den;
        // c.division(num, den);
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
