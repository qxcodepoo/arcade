#pragma once
#include "fn.hpp"

class Student {
    // Calculator c;
public:
    Student() {
        // c = Calculator(0);
    }
    void show() {
        // std::cout << c.str() << std::endl;
    }
    void init(int batteryMax) {
        // c = Calculator(batteryMax);
        (void) batteryMax;
    }
    void charge(int value) {
        // c.chargeBattery(value);
        // // ACT!
        // // (void) value;
    }
    void sum(int a, int b) {
        // c.sum(a, b);
        // // ACT!
        // // (void) a;
        // // (void) b;
    }
    void div(int num, int den) {
        // c.division(num, den);
        // // ACT!
        // // (void) num;
        // // (void) den;
    }
};
