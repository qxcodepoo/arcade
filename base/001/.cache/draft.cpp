#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

struct Calculator {
    int batteryMax;
    int battery;
    float display;

    Calculator(int batteryMax) :
        batteryMax(batteryMax) {
        this->battery = 0;
        this->display = 0.0f;
    }

    void chargeBattery(int value) {
        if(value < 0)
            return;
        this->battery += value;
        this->battery = std::min(this->battery, this->batteryMax);
    }

    bool useBattery() {
        if(this->battery == 0){
            fn::write("fail: bateria insuficiente");
            return false;
        }
        this->battery -= 1;
        return true;
    }

    void sum(int a, int b) {
        if(useBattery()) {
            this->display = (a + b);
        }
    }

    void division(int num, int den) {
        if(!useBattery()) {
            return;
        }
        if(den == 0) {
            fn::write("fail: divisao por zero");
            return;
        }
        this->display = (float) num / den;
    }

    std::string str() const {
        return fn::format("display = {%.2f}, battery = {}", this->display, this->battery); 
    }
};

std::ostream& operator<<(std::ostream& os, const Calculator& c) {
    return (os << c.str());
}
