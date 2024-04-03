#pragma once
#include "fn.hpp"
class Adapter {

public:
    Adapter() {
    }
    std::string show() {
        return "";
    }
    void init(int batteryMax) {
        (void) batteryMax;
    }
    void charge(int value) {
        (void) value;
    }
    void sum(int a, int b) {
        (void) a;
        (void) b;
    }
    void div(int num, int den) {
        (void) num;
        (void) den;
    }
};

