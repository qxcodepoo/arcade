#define __MEMORY
#define __LIST
#include "fn.hpp"
class Adapter {
    // Trampoline tr;
public:
    void init() {
        // tr = Trampoline();
    }
    void arrive(std::string name, int age) {
        (void) age;
        (void) name;
        // tr.arrive(std::make_shared<Kid>(name, age));
    }
    void enter() {
        // tr.enter();
    }
    void leave() {
        // tr.leave();
    }
    void remove(std::string name) {
        (void) name;
        // tr.removeKid(name);
    }
    void show() {
        // fn::write(tr);
    }
};

int main() {
    Adapter adp;

    while (true) {
        auto line = fn::input();
        fn::write("$" + line);
        auto args = fn::split(line);

        if      (args[0] == "end"   ) { break;                               }
        else if (args[0] == "arrive") { adp.arrive(args[1], (int) +args[2]); }
        else if (args[0] == "enter" ) { adp.enter();                         }
        else if (args[0] == "leave" ) { adp.leave();                         }
        else if (args[0] == "remove") { adp.remove(args[1]);                 }
        else if (args[0] == "show"  ) { adp.show();                          }
        else                          { fn::write("fail: invalid command");  }
    }
}