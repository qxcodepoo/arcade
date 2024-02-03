#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp


struct Cliente{
    std::string id;
    std::string fone;

    Cliente(std::string id = "", std::string fone = "");
    std::string str() const;
};

std::ostream& operator<<(std::ostream& os, const Cliente& c) { return os << c.str(); }

class Sala{
    std::vector<std::shared_ptr<Cliente>> cadeiras;

    int procurar(std::string nome);

public:
    Sala(int qtd = 0);


    void reservar(std::string id, std::string fone, int ind);

    void cancelar(std::string id);

    std::string str() const;
};


std::ostream& operator<<(std::ostream& os, const Sala& c) { return os << c.str(); }

int main() {
    Sala sala;
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if      (args[0] == "end")      { break; } 
        else if (args[0] == "show")     { fn::write(sala); } 
        else if (args[0] == "init")     { sala = Sala(+args[1]); } 
        else if (args[0] == "reservar") { sala.reservar(args[1], args[2], (int) +args[3]); }
        else if (args[0] == "cancelar") { sala.cancelar(args[1]); } 
        else                            { fn::write("fail: comando invalido"); }
    }
}

