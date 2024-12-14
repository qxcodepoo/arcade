#include "fn.hpp"


int main () {
    // Animal animal("", "");
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if (args[0] == "init" ) {
            // auto species = args[1];
            // auto sound = args[2];
        } else if (args[0] == "grow" ) {
            // auto increment = +args[1];
        } else if (args[0] == "noise") {
        } else if (args[0] == "show" ) {
        } else if (args[0] == "end") {
            break;
        } else {
            fn::write("fail: comando invalido");
        }
    }
}
