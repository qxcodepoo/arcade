#define __LIST
#define __MEMORY
#include "fn.hpp"

class Adapter {
    // Mercantil bank;
public:
    void init(int qtd_caixas) {
        (void) qtd_caixas;
        // bank = Mercantil(qtd_caixas);
    }
    void call(int indice) {
        (void) indice;
        // bank.chamarNoCaixa(indice);
    }
    void finish(int indice) {
        (void) indice;
        // bank.finalizar(indice);
    }
    void arrive(const std::string& nome) {
        (void) nome;
        // bank.chegar(std::make_shared<Pessoa>(nome));
    }

    void show() {
        // fn::write(bank.str());
    }
};

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
        else if (args[0] == "show"  ) { adp.show();                                     }
        else                          { fn::write("fail: comando invalido");            }
    }
}
