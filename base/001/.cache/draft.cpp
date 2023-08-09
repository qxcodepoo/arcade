#include <iostream>
#include <sstream>
#include <iomanip>

struct Calculator {
    int batteryMax;
    int battery;
    float display;

    Calculator(int batteryMax) { return {}; }

    void chargeBattery(int value) { 

    bool useBattery() { 

    void sum(int a, int b) { 

    void division(int num, int den) { return {}; }

    std::string str() { 
        std::stringstream ss;
        ss << "display = " << std::fixed << std::setprecision(2) << this->display;
        ss << ", battery = " << this->battery;
        return ss.str();
    }
};

std::ostream& operator<<(std::ostream& os, Calculator c) {
    return (os << c.str());
}

#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
using namespace fn;

int main() {
    Calculator c(0);

    while(true)
    {
        std::string line = input();
        auto args = split(line, ' ');
        write('$' + line);

        if      (args[0] == "show")     { std::cout << c << std::endl;                        }
        else if (args[0] == "init")     { c = Calculator(number(args[1]));                    }
        else if (args[0] == "charge")   { c.chargeBattery(number(args[1]));                   }
        else if (args[0] == "sum")      { c.sum(number(args[1]), number(args[2]));            }
        else if (args[0] == "div")      { c.division(number(args[1]), number(args[2]));       }
        else if (args[0] == "end")      { break;                                              }
        else                            { std::cout << "fail: comando inválido" << std::endl; }  
    }
}

