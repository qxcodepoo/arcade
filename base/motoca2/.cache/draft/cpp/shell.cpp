#include "fn.hpp"
#include "adapter.hpp"

int main() {
    Adapter adp(1);

    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write('$' + line);

        if      (args[0] == "end"  ) { break;                              }

        else if (args[0] == "init" ) { adp = Adapter(+args[1]);            }
        else if (args[0] == "show" ) { adp.show()  | fn::WRITE();          }
        else if (args[0] == "leave") { adp.leave() | fn::WRITE();          }
        else if (args[0] == "honk" ) { adp.honk()  | fn::WRITE();          }
        else if (args[0] == "enter") { adp.enter( args[1], +args[2]);      }
        else if (args[0] == "buy"  ) { adp.buy(  +args[1]);                }
        else if (args[0] == "drive") { adp.drive(+args[1]);                }

        else                         { fn::write("fail: invalid command"); }
    }
}
