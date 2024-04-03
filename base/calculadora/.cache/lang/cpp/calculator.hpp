#pragma once
#include "fn.hpp"

struct Calculator {
    int batteryMax;
    int battery;
    float display;

    Calculator(int batteryMax) 
    {
    }

    void chargeBattery(int value) {
    }

    bool useBattery() {
    }

    void sum(int a, int b) {
    }

    void division(int num, int den) {
    }
    std::string str() const {
        return fn::format("display = {%.2f}, battery = {}", this->display, this->battery); 
    }
};

std::ostream& operator<<(std::ostream& os, const Calculator& c) {
    return (os << c.str());
}