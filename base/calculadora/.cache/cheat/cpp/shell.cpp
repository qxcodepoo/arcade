#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
#include "student.hpp"

int main() {
    Student stu;

    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write(line);

        if      (args[0] == "end"   ) { break;                               }

        else if (args[0] == "show"  ) { stu.show();                      }
        else if (args[0] == "init"  ) { stu.init(+args[1]);              }
        else if (args[0] == "charge") { stu.charge(+args[1]);            }
        else if (args[0] == "sum"   ) { stu.sum(+args[1], +args[2]);     }
        else if (args[0] == "div"   ) { stu.div(+args[1], +args[2]);     }

        else                          { fn::write("fail: comando invalido"); }
    }
}