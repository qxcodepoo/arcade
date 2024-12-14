#define __LIST
#define __MEMORY
#include "fn.hpp" // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp


struct Adapter {
    // Lapiseira lapiseira;
    void show() {
        // std::cout << lapiseira << std::endl;
    }

    void init(float calibre) {
        (void) calibre;
        // lapiseira = Lapiseira(calibre);
    }

    void insert(float calibre, std::string dureza, int tamanho) {
        (void) calibre;
        (void) dureza;
        (void) tamanho;
        // lapiseira.inserir(std::make_shared<Grafite>(calibre, dureza, tamanho));
    }

    void remove() {
        // lapiseira.remover();
    }

    void pull() {
        // lapiseira.puxar();
    }

    void write() {
        // lapiseira.write();
    }

};

int main() {
    Adapter adp;
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if (args[0] == "end") { break; }
        else if (args[0] == "show") { adp.show(); }
        else if (args[0] == "init") { adp.init((float) +args[1]); }
        else if (args[0] == "insert") { adp.insert((float) +args[1], args[2], +args[3]); }
        else if (args[0] == "remove") { adp.remove(); }
        else if (args[0] == "pull") { adp.pull(); }
        else if (args[0] == "write") { adp.write(); }
        else { fn::write("fail: comando invalido"); }
    }
}
