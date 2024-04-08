#include "fn.hpp"
#include "time.hpp"

int main() {
    Time time(0, 0, 0);
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');

        write("$" + line);

        if (args[0] == "set") {
            time.setHour(+args[1]);
            time.setMinute(+args[2]);
            time.setSecond(+args[3]);
        } 
        else if (args[0] == "init") {
            time = Time(+args[1], +args[2], +args[3]);
        }
        else if (args[0] == "show") {
            fn::write(time);
        }
        else if (args[0] == "next") {
            time.nextSecond();
        }
        else if (args[0] == "end") {
            break;
        }
        else {
            fn::write("fail: comando invalido");
        }
    }
}