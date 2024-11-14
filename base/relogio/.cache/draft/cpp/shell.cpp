#include "fn.hpp"
#include "student.hpp"

int main() {
    Student stu;

    while (true) {
        fn::write("$", "");

        auto line = fn::input();
        auto args = fn::split(line, ' ');

        fn::write(line);

        if (args[0] == "end") {
            break;
        }
        else if (args[0] == "set") {
            stu.setHour(+args[1]);
            stu.setMinute(+args[2]);
            stu.setSecond(+args[3]);
        } 
        else if (args[0] == "init") {
            stu.init(+args[1], +args[2], +args[3]);
        }
        else if (args[0] == "show") {
            stu.show();
        }
        else if (args[0] == "next") {
            stu.nextSecond();
        }
        else {
            fn::write("fail: comando invalido");
        }
    }
}