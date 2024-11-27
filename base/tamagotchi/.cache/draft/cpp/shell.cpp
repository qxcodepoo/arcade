#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
#include <iostream>
#include <string>

class Adapter {
private:
    // Game game;
public:
    void init(int energy, int clean) {
        (void) energy;
        (void) clean;
        // this->game = Game(Pet(energy, clean));
    }

    void show() {
        // std::cout << this->game.str() << std::endl;
    }

    void play() {
        // this->game.play();
    }

    void shower() {
        // this->game.shower();
    }

    void eat() {
        // this->game.eat();
    }

    void sleep() {
        // this->game.sleep();
    }
};


int main() {
    Adapter adp;
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');

        fn::write("$" + line);

        if      (args[0] == "end")    { break;                                       }
        else if (args[0] == "init")   { adp.init(+args[1], +args[2]);                }
        else if (args[0] == "show")   { adp.show();                                  }
        else if (args[0] == "play")   { adp.play();                                  }
        else if (args[0] == "sleep")  { adp.sleep();                                 }
        else if (args[0] == "shower") { adp.shower();                                }
        else                          { fn::write("fail: comando invalido");         }
    }
}
