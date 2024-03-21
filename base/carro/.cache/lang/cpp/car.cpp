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
        (void) gas;
    }

    void drive(int km) {
        (void) km;
    }
    
    std::string str() {
        return "";
    }
};

