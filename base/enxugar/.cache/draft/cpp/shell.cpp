#include "fn.hpp"

int main() {
    // Toalha toalha("", "");
    while (true) {
        auto line = fn::input();
        fn::write("$" + line);

        auto par = fn::split(line, ' ');
        auto cmd = par[0];

        if (cmd == "mostrar") {
            // TODO
        } else if (cmd == "criar") {
            // TODO
            // auto cor = par[1];
            // auto tamanho = par[2];
        } else if (cmd == "enxugar") {
            // TODO
            // auto umidade = std::stoi(par[1]);
        } else if (cmd == "torcer") {
            // TODO
        } else if (cmd == "seca") {
            // TODO
        } else if (cmd == "end") {
            break;
        } else {
            fn::write("fail: comando invalido");
        }
    }
}