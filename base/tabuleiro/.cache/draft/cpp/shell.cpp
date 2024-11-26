#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

struct Adapter {
    // Board board;
    Adapter() {}
    void init(int n_players, int size) {
        (void) n_players;
        (void) size;
        // this->board = Board(n_players, size);
    }

    void addTrap(int pos) {
        (void) pos;
        // this->board.addTrap(pos);
    }

    void roll(int value) {
        (void) value;
        // this->board.rollDice(value);
    }

    void show() {
        // fn::write(this->board.toString());
    }
};

int main() {
    Adapter board;

    while(true) {
        auto line = fn::input();
        fn::write("$" + line);
        auto args = fn::split(line);

        if      (args[0] == "end"    ) { break;                                 }
        else if (args[0] == "init"   ) { board.init(+args[1], +args[2]);        }
        else if (args[0] == "addTrap") { board.addTrap(+args[1]);               }
        else if (args[0] == "roll"   ) { board.roll(+args[1]);                  }
        else if (args[0] == "show"   ) { board.show();                          }
        else                           { fn::write("fail: command not found");  }
    }
}
