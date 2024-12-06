#include "fn.hpp"

class Adapter {
public:
    Adapter() {
    }
    void size(const std::string& size) {
        (void) size;
    }
    void show() {
    }
};

int main() {
    Adapter adapter;
    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write(line);

        if      (args[0] == "end")  { break;                         }
        else if (args[0] == "size") { adapter.size(args[1]);         }
        else if (args[0] == "show") { adapter.show();                }
        else                        { fn::write("Comando inválido"); }
    }
}