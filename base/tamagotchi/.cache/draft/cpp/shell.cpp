#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
#include "student.hpp"

int main() {
    Adapter adp(0, 0, 0);
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');

        fn::write("$" + line);

        if      (args[0] == "end")    { break;                                       }
        else if (args[0] == "init")   { adp = Adapter(+args[1], +args[2], +args[3]); }
        else if (args[0] == "show")   { adp.show();                                  }
        else if (args[0] == "play")   { adp.play();                                  }
        else if (args[0] == "eat")    { adp.eat();                                   }
        else if (args[0] == "sleep")  { adp.sleep();                                 }
        else if (args[0] == "shower") { adp.shower();                                }
        else                          { fn::write("fail: comando invalido");         }
    }
}
