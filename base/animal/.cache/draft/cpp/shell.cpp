#include "fn.hpp"
#include "adapter.hpp"

int main () {
    Adapter adp("", "");
    
    if (Student::debug) {
        Student::run();
        return 0;
    }

    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if      (args[0] == "end"  ) { break;                               }

        else if (args[0] == "init" ) { adp = Adapter(args[1], args[2]);     }
        else if (args[0] == "grow" ) { adp.grow(+args[1]);                  }
        else if (args[0] == "noise") { fn::write(adp.noise());              }
        else if (args[0] == "show" ) { fn::write(adp.show());               }

        else                         { fn::write("fail: comando invalido"); }
    }
}
