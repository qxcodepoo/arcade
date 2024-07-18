#include <iostream>
#include "adapter.hpp"
#include "fn.hpp"

int main() {
    Adapter adp(0);

    while (true) {
        auto line = fn::input();
        auto args = fn::split(line);
        fn::write("$" + line);

        if      (args[0] == "show"  ) { fn::write(adp.str());                                                        }
        else if (args[0] == "init"  ) { adp = Adapter(+args[1]);                                                }
        else if (args[0] == "insert") { adp.insert(+args[1], args[2], (int) +args[3]); }
        else if (args[0] == "remove") { adp.remove();                                                          }
        else if (args[0] == "write" ) { adp.writePage();                                                       }
        else if (args[0] == "end"   ) { break;                                                                    }
        else                          { fn::write("fail: comando invalido");                                      }
    }
}
