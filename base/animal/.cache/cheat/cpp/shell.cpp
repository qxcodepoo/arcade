#include "fn.hpp"

struct Animal {
    std::string species;
    std::string sound;
    int age;
    Animal(std::string species = "", std::string noise = "") {
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

    void ageBy(int increment) {
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


int main () {
    Animal animal("", "");
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if (args[0] == "init" ) {
            auto species = args[1];
            auto sound = args[2];
            animal = Animal(species, sound);
        } else if (args[0] == "grow" ) {
            auto increment = +args[1];
            animal.ageBy(increment);
        } else if (args[0] == "noise") {
            fn::write(animal.makeSound());
        } else if (args[0] == "show" ) {
            fn::write(animal.str());
        } else if (args[0] == "end") {
            break;
        } else {
            fn::write("fail: comando invalido");
        }
    }
}