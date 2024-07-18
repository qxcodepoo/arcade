#pragma once
#include <iostream>
class Adapter {
public:
    Adapter(int power = 1) {
        (void) power;
    }

    void enter(std::string name, int age) {
        (void) name;
        (void) age;
    }

    std::string leave() {
        return "";
    }

    std::string honk() const {
        return "";
    }

    void buy(int time) {
        (void) time;
    }

    void drive(int time) {
        (void) time;
    }

    std::string show() const {
        return "";
    }
};