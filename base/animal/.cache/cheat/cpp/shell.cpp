#include "fn.hpp"

struct Animal {
    std::string species;
    std::string sound;
    int age;
    Animal(std::string species = "", std::string noise = "") {
        (void) species;
        (void) noise;
        this->species = species;
        this->sound = noise;
        this->age = 0;
    }

    std::string makeSound() const {
        if (age == 0) {
            return "---";
        }
        if (age == 4) {
            return "RIP";
        }
        return this->sound;
    }

    void oldBy(int increment) {
        (void) increment;
        age += increment;
        if (age >= 4) {
            fn::print("warning: {} morreu\n", species);
            age = 4;
        }
    }

    std::string str() const {
        return fn::format("{}:{}:{}", species, age, sound);
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