#include "fn.hpp"


class Adapter {
public:
    Adapter() {}

    void criar(const std::string& cor, const std::string& tamanho) {
        (void) cor;
        (void) tamanho;
    }

    void enxugar(int quantidade) {
        (void) quantidade;
    }

    void seca() {
    }

    void torcer() {
    }

    void mostrar() const {
    }
};

int main() {
    Adapter adapter;
    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write(line);

        if      (args[0] == "end"    ) { break;                           }
        else if (args[0] == "criar"  ) { adapter.criar(args[1], args[2]); }
        else if (args[0] == "enxugar") { adapter.enxugar(+args[1]);       }
        else if (args[0] == "seca"   ) { adapter.seca();                  }
        else if (args[0] == "torcer" ) { adapter.torcer();                }
        else if (args[0] == "mostrar") { adapter.mostrar();               }
        else                           { fn::write("comando invalido");   }
    }
}
