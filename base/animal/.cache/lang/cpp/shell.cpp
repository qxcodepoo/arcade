#include "fn.hpp"
#include "animal.hpp"

int main () {
    Animal animal("", "");
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        
        if (args[0] == "init") {
            animal = Animal(args[1], args[2]);
        }
        else if (args[0] == "grow") {
            animal.envelhecer(+args[1]);
        }
        else if (args[0] == "noise") {
            fn::write(animal.fazerBarulho());
        }
        else if (args[0] == "show") {
            fn::write(animal);
        }
        else if (args[0] == "end") {
            break;
        }
        else {
            fn::write("fail: comando invalido");
        }
    }
}
