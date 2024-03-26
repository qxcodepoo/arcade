#pragma once
#include "fn.hpp"
using namespace fn;

class Time {
private:
    int hour {0}, minute {0}, second {0};
public:
    Time(int hour = 0, int minute = 0, int second = 0) {
        (void) hour;
        (void) minute;
        (void) second;
    }

    void setHour(int hour) {
        (void) hour;
    }

    void setMinute(int minute) {
        (void) minute;
    }
    void setSecond(int second) {
        (void) second;
    }
    int getHour() const {
        return 0;
    }
    int getMinute() const {
        return 0;
    }
    int getSecond() const {
        return 0;
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