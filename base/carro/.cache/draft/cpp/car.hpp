#pragma once
#include "fn.hpp"

#include <iostream>
class Car {
public:
    int pass;
    int passMax;
    int gas;
    int gasMax;
    int km;

    Car() {
    }

    void enter() {
    }

    void leave() {
    }

    void fuel(int gas) {
    }

    void drive(int km) {
    }

    std::string str() const {
    }
};

std::ostream& operator<<(std::ostream& os, const Car& car) {
    return os << car.str();
}
