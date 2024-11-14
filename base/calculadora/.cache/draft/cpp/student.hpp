#pragma once
#include "fn.hpp"

class Student {
    // Calculator c;
public:
    void init() {
        // c = Calculator(0);
    }
    void show() {
        // std::cout << c.str() << std::endl;
    }
    void init(int batteryMax) {
        (void) batteryMax;
        // c = Calculator(batteryMax);
    }
    void charge(int value) {
        (void) value;
        // c.chargeBattery(value);
    }
    void sum(int a, int b) {
        (void) a;
        (void) b;
        // c.sum(a, b);
    }
    void div(int num, int den) {
        (void) num;
        (void) den;
        // c.division(num, den);
    }
};
