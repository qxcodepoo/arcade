#include "fn.hpp"
#include "student.hpp"

int main () {
    Student stu("", "");
    
    if (Debug::debug) {
        Debug::run();
        return 0;
    }

    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');

        fn::write(line); //test echo

        if      (args[0] == "end"  ) { break;                               }

        else if (args[0] == "init" ) { stu = Student(args[1], args[2]);     }
        else if (args[0] == "grow" ) { stu.grow(+args[1]);                  }
        else if (args[0] == "noise") { stu.noise();              }
        else if (args[0] == "show" ) { stu.show();               }

        else                         { fn::write("fail: comando invalido"); }
    }
}