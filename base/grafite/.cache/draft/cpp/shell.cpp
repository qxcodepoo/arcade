#include "fn.hpp"
#include <iostream>
class Adapter {
private:
    // Pencil pencil;
public:
    Adapter(double thickness) {
        (void) thickness;
    };
    
    void insert(double thickness, std::string hardness, int length) {
        (void) thickness;
        (void) hardness;
        (void) length;
        // pencil.insert(std::make_shared<Lead>(thickness, hardness, length));
    }

    void remove() {
        // pencil.remove();
    }

    void writePage() {
        // pencil.writePage();
    }

    void show() {
        // fn::write(pencil.str());
    }
};


int main() {
    Adapter adp(0);

    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line);
        fn::write(line);

        if      (args[0] == "show"  ) { adp.show();                                    }
        else if (args[0] == "init"  ) { adp = Adapter(+args[1]);                       }
        else if (args[0] == "insert") { adp.insert(+args[1], args[2], (int) +args[3]); }
        else if (args[0] == "remove") { adp.remove();                                  }
        else if (args[0] == "write" ) { adp.writePage();                               }
        else if (args[0] == "end"   ) { break;                                         }
        else                          { fn::write("fail: comando invalido");           }
    }
}
