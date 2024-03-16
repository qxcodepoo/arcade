#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
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
    int getHour() const {
    }
    int getMinute() const {
    }
    int getSecond() const {
    }
    void nextSecond() {
    }

    std::string str() const {
        return fn::format("{%02d}:{%02d}:{%02d}", hour, minute, second);
    }
};

std::ostream &operator<<(std::ostream &os, const Time &time) {
    return os << time.str();
}


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