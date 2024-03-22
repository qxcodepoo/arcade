#pragma once
#include "fn.hpp"

struct Calculator {
    int batteryMax;
    int battery;
    float display;

    Calculator(int batteryMax) 
    {
        (void) batteryMax;
        //todo
    }

    void chargeBattery(int value) {
        (void) value;
        //todo
    }

    bool useBattery() {
        return false;
        //todo
    }

    void sum(int a, int b) {
        (void) a;
        (void) b;
        //todo
    }

    void division(int num, int den) {
        (void) num;
        (void) den;
        //todo
    }
    std::string str() const {
        return fn::format("display = {%.2f}, battery = {}", this->display, this->battery); 
    }
};

std::ostream& operator<<(std::ostream& os, const Calculator& c) {
    return (os << c.str());
}