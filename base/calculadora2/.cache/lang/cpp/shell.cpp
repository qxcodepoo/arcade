#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
#include "adapter.hpp"

int main() {
    Adapter adapter;

    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if (args[0] == "end") {
            break;
        } else if (args[0] == "show") {
            fn::write(adapter.show());
        } else if (args[0] == "init") {
            adapter.init(+args[1]);
        } else if (args[0] == "charge") {
            adapter.charge(+args[1]);
        } else if (args[0] == "sum") {
            adapter.sum(+args[1], +args[2]);
        } else if (args[0] == "div") {
            adapter.div(+args[1], +args[2]);
        } else {
            fn::write("fail: comando invalido");
        }
    }
}
