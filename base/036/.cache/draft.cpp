#include <iostream>
#include <sstream>
#include <iomanip>
#include <fn.hpp>
using namespace fn;

class Time {
private:
    int hour {0}, minute {0}, second {0};
public:
    Time(int hour = 0, int minute = 0, int second = 0) {
    }
    void setHour(int hour) {
    }
    void setMinute(int minute) {
    }
    void setSecond(int second) {
    }
    int getHour() {
        return {}; // todo
    }
    int getMinute() {
        return {}; // todo
    }
    int getSecond() {
        return {}; // todo
    }
    void nextSecond() {
    }
    std::string str() {
        return fn::format("{%02d}:{%02d}:{%02d}", hour, minute, second);
    }
};

int main() {
    Time time(0, 0, 0);
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');

        write("$" + line);

        if (args[0] == "end") {
            break;
        } else if (args[0] == "set") {
            time.setHour(+args[1]);
            time.setMinute(+args[2]);
            time.setSecond(+args[3]);
        } else if (args[0] == "init") {
            time = Time(+args[1], +args[2], +args[3]);
        } else if (args[0] == "show") {
            fn::write(time.str());
        } else if (args[0] == "next") {
            time.nextSecond();
        } else {
            fn::write("fail: comando invalido");
        }
    }
}