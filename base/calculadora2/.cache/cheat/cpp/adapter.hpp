#pragma once
#include "calculator.hpp"

class Adapter {
    Calculator c;

public:
    Adapter() {
        c = Calculator(0);
    }
    std::string show() {
        return c.str();
    }
    void init(int batteryMax) {
        c = Calculator(batteryMax);
    }
    void charge(int value) {
        c.chargeBattery(value);
    }
    void sum(int a, int b) {
        c.sum(a, b);
    }
    void div(int num, int den) {
        c.division(num, den);
    }
};

