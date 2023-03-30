#include <fn.hpp> //usr/local/include

struct Car {
    int pass {0};
    int passMax {2};
    int gas {0};
    int gasMax {100};
    int km {0};

    std::string str() {
        return fn::format("pass: {}, gas: {}, km: {}", pass, gas, km);
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
    void fuel(int value) {
        gas += value;
        if (gas > gasMax) {
            gas = gasMax;
        }
    }
    void drive(int distance) {
        if (pass == 0) {
            fn::write("fail: nao ha ninguem no carro");
            return;
        }
        if (gas == 0) {
            fn::write("fail: tanque vazio");
            return;
        }
        if (gas < distance) {
            fn::write("fail: tanque vazio apos andar " + fn::tostr(gas) + " km");
            km += gas;
            gas = 0;
            return;
        }
        gas -= distance;
        km += distance;
    }
};

int main() {
    Car car;
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if (args[0] == "end") {
            break;
        } else if (args[0] == "show") {
            fn::write(car.str());
        } else if (args[0] == "enter") {
            car.enter();
        } else if (args[0] == "leave") {
            car.leave();
        } else if (args[0] == "fuel") {
            car.fuel(+args[1]);
        } else if (args[0] == "drive") {
            car.drive(+args[1]);
        } else {
            fn::write("fail: comando invalido");
        }
    }
}