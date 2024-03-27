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
        //todo
    }

    void enter() {
        //todo
    }

    void leave() {
        //todo
    }

    void fuel(int gas) {
        (void) gas;
        //todo
    }

    void drive(int km) {
        (void) km;
        //todo
    }

    std::string str() const {
        return "";
        //todo
    }
};

std::ostream& operator<<(std::ostream& os, const Car& car) {
    return os << car.str();
}
