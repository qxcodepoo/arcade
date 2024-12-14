#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

int main() {
    // Calculator calc;

    while (true) {
        auto line = fn::input();
        fn::write("$" + line);

        auto par = fn::split(line, ' ');
        auto cmd = par[0];

        if (cmd == "init") {
            // TODO
            // int batteryMax = std::stoi(par[1]);
        } else if (cmd == "show") {
            // TODO
        } else if (cmd == "charge") {
            // TODO
            // int increment = std::stoi(par[1]);
        } else if (cmd == "sum") {
            // TODO
            // int a = std::stoi(par[1]);
            // int b = std::stoi(par[2]);
        } else if (cmd == "div") {
            // TODO
            // int num = std::stoi(par[1]);
            // int den = std::stoi(par[2]);
        } else if (cmd == "end") {
            break;
        } else {
            fn::write("fail: comando invalido");
        }
    }


}
