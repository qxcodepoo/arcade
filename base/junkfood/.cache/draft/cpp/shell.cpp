#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp


int main() {
    Machine machine(0);
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        try {
            if      (args[0] == "end"     ) { break;                                                      }
            else if (args[0] == "show"    ) { fn::write(machine);                                         }
            else if (args[0] == "init"    ) { machine = Machine((int) +args[1]);                          }
            else if (args[0] == "limpar"  ) { machine.limpar(+args[1]);                                   }
            else if (args[0] == "dinheiro") { machine.inserirDinheiro(+args[1]);                          }
            else if (args[0] == "comprar" ) { machine.comprar(+args[1]);                                  }
            else if (args[0] == "set"     ) { machine.set(+args[1], args[2], +args[3], +args[4]);         }
            else if (args[0] == "troco"   ) { fn::print("voce recebeu {%.2f} RS\n", machine.pedirTroco()); }
            else                            { fn::write("comando invalido");                              }
        } catch (const char* e) {
            fn::write(e);
        }
    }
}