#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp


// Nesse rascunho estão faltando os atributos e métodos
// correspondentes às funcionalidades de abastecer e dirigir o carro.


class Car {
public:
    int pass;
    int passMax;

    Car();

    void enter();

    void leave();

    std::string str();
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
        else if (args[0] == "end")   { break;                               }
        else                         { fn::write("fail: comando invalido"); }
    }
}
