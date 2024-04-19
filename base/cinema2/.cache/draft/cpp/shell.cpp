#include "adapter.hpp"
#include "flow.hpp"

int main() {
    Adapter adp;
    while (true) {
        auto line = fw::input();
        auto args = fw::split(line, " ");
        fw::write("$" + line);

        if      (args[0] == "end")      { break; } 
        else if (args[0] == "show")     { fw::write(adp); } 
        else if (args[0] == "init")     { adp = Adapter(+args[1]); } 
        else if (args[0] == "reservar") { adp.reservar(args[1], args[2], (int) +args[3]); }
        else if (args[0] == "cancelar") { adp.cancelar(args[1]); } 
        else                            { fw::write("fail: comando invalido"); }
    }
}

