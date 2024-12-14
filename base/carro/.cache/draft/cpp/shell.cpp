#include "fn.hpp"


int main() {
    // Car car;
    while (true) {
        auto line = fn::input();
        fn::write("$" + line);

        auto par = fn::split(line, ' ');
        auto cmd = par[0];
        
        if (cmd == "show") {
            // TODO
        } else if (cmd == "enter") {
            // TODO
        } else if (cmd == "leave") {
            // TODO
        } else if (cmd == "fuel") {
            // int increment = std::stoi(par[1]);
        } else if (cmd == "drive") {
            // int distance = std::stoi(par[1]);
        } else if (par[0] == "end")   {
            break;
        } else {
            fn::write("fail: comando invalido");
        }
    }
}
