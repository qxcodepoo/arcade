#include "fn.hpp"
#include "adapter.hpp"

int main() {
    Adapter adp;
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if      (args[0] == "show")  { fn::write(adp.str());                }
        else if (args[0] == "enter") { adp.enter();                         } 
        else if (args[0] == "leave") { adp.leave();                         }
        else if (args[0] == "fuel")  { adp.fuel(+args[1]);                  }
        else if (args[0] == "drive") { adp.drive(+args[1]);                 }

        else if (args[0] == "end")   { break;                               }
        else                         { fn::write("fail: comando invalido"); }
    }
}
