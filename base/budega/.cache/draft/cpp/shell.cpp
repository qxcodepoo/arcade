#include "fn.hpp"
#include "student.hpp"

int main() {
    Adapter adp;

    if (Student::debug) {
        Student::run();
        return 0;
    }

    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if      (args[0] == "end"   ) { break;                                          }
        else if (args[0] == "init"  ) { adp.init(+args[1]);                             }
        else if (args[0] == "call"  ) { adp.call(+args[1]);                             }
        else if (args[0] == "finish") { adp.finish(+args[1]);                           }
        else if (args[0] == "arrive") { adp.arrive(args[1]);                            }
        else if (args[0] == "show"  ) { fn::write(adp.str());                          }
        else                          { fn::write("fail: comando invalido");            }
    }
}
