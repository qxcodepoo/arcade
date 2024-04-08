#include <iostream>
#include "pencil.hpp"
#include "lead.hpp"
#include "fn.hpp"

int main() {
    Pencil pencil;

    while (true) {
        auto line = fn::input();
        auto args = fn::split(line);
        fn::write("$" + line);

        if      (args[0] == "show"  ) { fn::write(pencil);                                                        }
        else if (args[0] == "init"  ) { pencil = Pencil(+args[1]);                                                }
        else if (args[0] == "insert") { pencil.insert(std::make_shared<Lead>(+args[1], args[2], (int) +args[3])); }
        else if (args[0] == "remove") { pencil.remove();                                                          }
        else if (args[0] == "write" ) { pencil.writePage();                                                       }
        else if (args[0] == "end"   ) { break;                                                                    }
        else                          { fn::write("fail: comando invalido");                                      }
    }
}
