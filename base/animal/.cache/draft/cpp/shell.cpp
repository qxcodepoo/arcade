#include "fn.hpp"

struct Animal {
    Animal(std::string species = "", std::string noise = "") {
        (void) species;
        (void) noise;
    }

    std::string makeSound() const {
        return "";
    }

    void oldBy(int increment) {
        (void) increment;
    }

    std::string str() const {
        return "";
    }
};

struct Adapter {
    Animal animal;
    void init(std::string species = "", std::string noise = "") {
        animal = Animal(species, noise);
    }

    void grow(int increment) {
        animal.oldBy(increment);
    }

    void noise() {
        std::cout << animal.makeSound() << std::endl;
    }

    void show() {
        std::cout << animal.str() << std::endl;
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
