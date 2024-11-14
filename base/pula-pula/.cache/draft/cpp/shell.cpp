#include <memory>
#include "fn.hpp"
#include "kid.hpp"
#include "trampoline.hpp"

int main() {
    Trampoline tr;

    while (true) {
        auto line = fn::input();
        fn::write("$" + line);
        auto args = fn::split(line);

        if      (args[0] == "end"   ) { break;                                                     }
        else if (args[0] == "arrive") { tr.arrive(std::make_shared<Kid>(args[1], (int) +args[2])); }
        else if (args[0] == "enter" ) { tr.enter();                                                }
        else if (args[0] == "leave" ) { tr.leave();                                                }
        else if (args[0] == "remove") { tr.removeKid(args[1]);                                     }
        else if (args[0] == "show"  ) { fn::write(tr);                                             }
        else                          { fn::write("fail: invalid command");                        }
    }
}