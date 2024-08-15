#pragma once
#include "fn.hpp"
class Car {
public:
    int pass;
    int passMax;
    int gas;
    int gasMax;
    int km;

    Car() {
        pass = 0;
        passMax = 2;
        gas = 0;
        gasMax = 100;
        km = 0;
    }

    void enter() {
        if (pass < passMax) {
            pass++;
        } else {
            fn::write("fail: limite de pessoas atingido");
        }
    }

    void leave() {
        if (pass > 0) {
            pass--;
        } else {
            fn::write("fail: nao ha ninguem no carro");
        }
    }

    void fuel(int gas) {
        this->gas += gas;
        if (this->gas > gasMax) {
            this->gas = gasMax;
        }
    }

    void drive(int km) {
        if (pass == 0) {
            fn::write("fail: nao ha ninguem no carro");
        } else if (gas == 0) {
            fn::write("fail: tanque vazio");
        } else if (this->gas < km) {
            fn::print("fail: tanque vazio apos andar {} km\n", this->gas);
            this->km += this->gas;
            this->gas = 0;
        } else {
            this->km += km;
            this->gas -= km;
        }
    }

    std::string str() const {
        return fn::format("pass: {}, gas: {}, km: {}", pass, gas, km);
    }
};

inline std::ostream& operator<<(std::ostream& os, const Car& car) {
    return os << car.str();
}
