#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

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
