#include <iostream>
#include "student.hpp"
#include "fn.hpp"

int main() {
    Student stu(0);

    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line);
        fn::write(line);

        if      (args[0] == "show"  ) { stu.show();                                    }
        else if (args[0] == "init"  ) { stu = Student(+args[1]);                       }
        else if (args[0] == "insert") { stu.insert(+args[1], args[2], (int) +args[3]); }
        else if (args[0] == "remove") { stu.remove();                                  }
        else if (args[0] == "write" ) { stu.writePage();                               }
        else if (args[0] == "end"   ) { break;                                         }
        else                          { fn::write("fail: comando invalido");           }
    }
}
