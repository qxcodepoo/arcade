#define __LIST
#define __MEMORY
#include "fn.hpp"
#include "student.hpp"

int main() {
    Adapter adp;

    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if      (args[0] == "end"   ) { break;                                          }
        else if (args[0] == "init"  ) { adp.init(+args[1]);                             }
        else if (args[0] == "call"  ) { adp.call(+args[1]);                             }
        else if (args[0] == "finish") { adp.finish(+args[1]);                           }
        else if (args[0] == "arrive") { adp.arrive(args[1]);                            }
        else if (args[0] == "show"  ) { adp.show();                          }
        else                          { fn::write("fail: comando invalido");            }
    }
}
