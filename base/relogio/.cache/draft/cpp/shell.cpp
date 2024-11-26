#include "fn.hpp"

class Adapter {
private:
    // Time time;

public:
    void init(int hour = 0, int minute = 0, int second = 0) {
        (void) hour;
        (void) minute;
        (void) second;
        // this->time = Time(hour, minute, second);
    }

    void setHour(int hour) {
        (void) hour;
        // this->time.setHour(hour);
    }

    void setMinute(int minute) {
        (void) minute;
        // this->time.setMinute(minute);
    }
    void setSecond(int second) {
        (void) second;
        // this->time.setSecond(second);
    }

    void nextSecond() {
        // this->time.nextSecond();
    }
    
    void show() {
        // fn::write(time);
    }
};

int main() {
    Adapter stu;

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