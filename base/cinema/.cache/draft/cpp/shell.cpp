#define __MEMORY
#include "fn.hpp"

class Adapter{
public:
    Adapter() {}
    void init(int qtd) {
        (void) qtd;
    }

    void reserve(std::string id, std::string phone, int index) {
        (void) id;
        (void) phone;
        (void) index;
    }

    void cancel(std::string id) {
        (void) id;
    }

    void show() const {
    }
};

int main() {
    Adapter adp;
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if      (args[0] == "end")     { break;                                        } 
        else if (args[0] == "show")    { adp.show();                                   } 
        else if (args[0] == "init")    { adp.init(+args[1]);                           } 
        else if (args[0] == "reserve") { adp.reserve(args[1], args[2], (int) +args[3]);}
        else if (args[0] == "cancel")  { adp.cancel(args[1]);                          } 
        else                           { fn::write("fail: comando invalido");          }
    }
}
