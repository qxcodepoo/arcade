#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp


int main() {
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        try {
            if (args[0] == "show") {
                // IMPRIMIR
            } else if (args[0] == "init") {
                // int n_espirais = +args[1];
            } else if (args[0] == "limpar") {
                // int indice = +args[1];
            } else if (args[0] == "dinheiro") {
                // int value = +args[1];
            } else if (args[0] == "comprar") {
                // int index = +args[1];
            } else if (args[0] == "set") {
                // int index = +args[1];
                // std::string name = args[2];
                // int qtd = +args[3];
                // double price = +args[4];
            } else if (args[0] == "troco") {
                // double troco = machine.pedirTroco();
                // fn::print("voce recebeu {%.2f} RS\n", troco); 
            } else if (args[0] == "end") {
                break;
            } else {
                fn::write("comando invalido");
            }
        } catch (const char* e) {
            fn::write(e);
        }
    }
}
