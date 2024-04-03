#pragma once
#include "fn.hpp"

struct Calculator {
    int batteryMax;
    int battery;
    float display;

    Calculator(int batteryMax = 0) : batteryMax(batteryMax) {
        this->battery = 0;
        this->display = 0.0f;
    }

    void chargeBattery(int value) {
        if(value < 0) {
            return;
        }
        this->battery += value;
        this->battery = std::min(this->battery, this->batteryMax);
    }

    void sum(int a, int b) {
        if(this->battery == 0){
            fn::write("fail: bateria insuficiente");
            return;
        }
        this->battery -= 1;
        this->display = (a + b);
        
    }

    void division(int num, int den) {
        if(this->battery == 0){
            fn::write("fail: bateria insuficiente");
            return;
        }
        this->battery -= 1;
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

