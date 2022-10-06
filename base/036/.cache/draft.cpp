#include <iostream>
#include <sstream>
#include <aux.hpp>

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
        std::stringstream ss;
        ss << std::setfill('0') << std::setw(2) << hour << ":"
           << std::setfill('0') << std::setw(2) << minute << ":"
           << std::setfill('0') << std::setw(2) << second;
        return ss.str();
    }
};

int main() {
    aux::Chain chain;
    aux::Param param;
    Time time;

    auto INT = aux::to<int>;

    chain["set"] = [&]() {
        time.setHour(INT(param[1]));
        time.setMinute(INT(param[2]));
        time.setSecond(INT(param[3]));
    };
    chain["init"] = [&]() {
        time = Time(INT(param[1]), INT(param[2]), INT(param[3]));
    };
    chain["show"] = [&]() {
        std::cout << time.str() << '\n';
    };
    chain["next"] = [&]() {
        time.nextSecond();
    };

    aux::execute(chain, param);
}