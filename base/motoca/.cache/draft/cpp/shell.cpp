#include "fn.hpp"
#include "student.hpp"

int main() {
    Student stu(1);

    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write('$' + line);

        if      (args[0] == "end"  ) { break;                              }

        else if (args[0] == "init" ) { stu = Student(+args[1]);            }
        else if (args[0] == "show" ) { stu.show();                         }
        else if (args[0] == "leave") { stu.leave();                        }
        else if (args[0] == "honk" ) { stu.honk();                         }
        else if (args[0] == "enter") { stu.enter( args[1], +args[2]);      }
        else if (args[0] == "buy"  ) { stu.buy(  +args[1]);                }
        else if (args[0] == "drive") { stu.drive(+args[1]);                }

        else                         { fn::write("fail: invalid command"); }
    }
}
