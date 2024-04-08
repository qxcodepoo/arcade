#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
#include "calculator.hpp"

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
        else if (args[0] == "div") {
            c.division(+args[1], +args[2]);
        }
        else if (args[0] == "end") {
            break;
        }
        else {
            fn::write("fail: comando inválido"); 
        }
    }
}
