#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

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
    
    std::string str() {
    }
};

int main() {
    Car car;
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if      (args[0] == "show")  { fn::write(car.str());                }
        else if (args[0] == "enter") { car.enter();                         } 
        else if (args[0] == "leave") { car.leave();                         }
        else if (args[0] == "fuel")  { car.fuel(+args[1]);                  }
        else if (args[0] == "drive") { car.drive(+args[1]);                 }
        else if (args[0] == "end")   { break;                               }
        else                         { fn::write("fail: comando invalido"); }
    }
}
