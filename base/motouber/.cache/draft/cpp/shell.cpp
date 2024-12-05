#include <iostream>
#include "fn.hpp"


class Adapter {
public:
    void setDriver(std::string name, int money) {
        (void) name;
        (void) money;
    }
    void setPass(std::string name, int money) {
        (void) name;
        (void) money;
    }
    void drive(int distance) {
        (void) distance;
    }
    void leavePass() {
    }
    void show() {
    }
};

int main() {
    Adapter adp;
    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write(line);

        if      (args[0] == "end")       { break;                                  }
        else if (args[0] == "setDriver") { adp.setDriver(args[1], +args[2]);       }
        else if (args[0] == "setPass")   { adp.setPass(args[1], +args[2]);         }
        else if (args[0] == "drive")     { adp.drive(+args[1]);                    }
        else if (args[0] == "leavePass") { adp.leavePass();                        }
        else if (args[0] == "show")      { adp.show();                             }
        else                             { fn::write("fail: command not found\n"); }
    }
}