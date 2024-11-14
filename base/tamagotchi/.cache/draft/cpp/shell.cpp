#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
#include "student.hpp"

int main() {
    Student stu(0, 0, 0);
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');

        fn::write("$" + line);

        if      (args[0] == "end")    { break;                                       }
        else if (args[0] == "init")   { stu = Student(+args[1], +args[2], +args[3]); }
        else if (args[0] == "show")   { stu.show();                                  }
        else if (args[0] == "play")   { stu.play();                                  }
        else if (args[0] == "eat")    { stu.eat();                                   }
        else if (args[0] == "sleep")  { stu.sleep();                                 }
        else if (args[0] == "shower") { stu.shower();                                }
        else                          { fn::write("fail: comando invalido");         }
    }
}
