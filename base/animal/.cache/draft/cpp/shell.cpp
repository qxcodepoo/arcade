#include "fn.hpp"

struct Adapter {
    // Animal animal;
    void init(std::string especie = "", std::string barulho = "") {
        (void) especie;
        (void) barulho;
        // animal = Animal(especie, barulho);
    }

    void grow(int nivel) {
        (void) nivel;
        // animal.envelhecer(nivel);
    }

    void noise() {
        // std::cout << animal.fazerBarulho() << std::endl;
    }

    void show() {
        // std::cout << animal.str() << std::endl;
    }
};

int main () {
    Adapter adp;

    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');

        fn::write(line); //test echo

        if      (args[0] == "end"  ) { break;                               }
        else if (args[0] == "init" ) { adp.init(args[1], args[2]);          }
        else if (args[0] == "grow" ) { adp.grow(+args[1]);                  }
        else if (args[0] == "noise") { adp.noise();                         }
        else if (args[0] == "show" ) { adp.show();                          }
        else                         { fn::write("fail: comando invalido"); }
    }
}
