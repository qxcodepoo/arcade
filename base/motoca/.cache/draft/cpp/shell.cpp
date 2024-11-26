#include "fn.hpp"
#include "student.hpp"

int main() {
    Adapter adp;

    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write('$' + line);

        if      (args[0] == "end"  ) { break;                              }

        else if (args[0] == "init" ) { adp.init(+args[1]);                 }
        else if (args[0] == "show" ) { adp.show();                         }
        else if (args[0] == "leave") { adp.leave();                        }
        else if (args[0] == "honk" ) { adp.honk();                         }
        else if (args[0] == "enter") { adp.enter( args[1], +args[2]);      }
        else if (args[0] == "buy"  ) { adp.buy(  +args[1]);                }
        else if (args[0] == "drive") { adp.drive(+args[1]);                }

        else                         { fn::write("fail: invalid command"); }
    }
}
