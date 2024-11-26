#include "fn.hpp"

struct Adapter {
    // Car car;
    Adapter() {}

    void enter() {
        // car.enter();
    }
    void leave() {
        // car.leave();
    }
    void fuel(int q) {
        // car.fuel(q);
        (void) q;
    }
    void drive(int q) {
        // car.drive(q);
        (void) q;
    }
    void show() {
        // std::cout << car.str() << std::endl;
    }
};

int main() {
    Adapter stu;

    while (true) {
        fn::write("$", "");
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write(line);

        if      (args[0] == "show")  { stu.show();                          }
        else if (args[0] == "enter") { stu.enter();                         } 
        else if (args[0] == "leave") { stu.leave();                         }
        else if (args[0] == "fuel")  { stu.fuel(+args[1]);                  }
        else if (args[0] == "drive") { stu.drive(+args[1]);                 }

        else if (args[0] == "end")   { break;                               }
        else                         { fn::write("fail: comando invalido"); }
    }
}
