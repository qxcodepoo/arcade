#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include <sstream>
#include <aux.hpp>

struct Cliente{
    std::string id;
    std::string fone;

    Cliente(std::string id = "", std::string fone = "") {
        this->id = id;
        this->fone = fone;
    }
    std::string str() {
        std::stringstream ss;
        ss << this->id << ":" << this->fone;
        return ss.str();
    }
};

std::ostream& operator<<(std::ostream& os, Cliente c) {
    return os << c.str();
}



class Sala{
    std::vector<std::shared_ptr<Cliente>> cadeiras;
    int procurar(std::string nome) {
        return {}; // todo
    }

public:
    Sala(int qtd = 0) { //todo
    }


    void reservar(std::string id, std::string fone, int ind) {
    }

    void cancelar(std::string id) {
    }

    std::string str() {
        return {}; // todo
    }
};

int main() {
    aux::Chain chain;
    aux::Param param;
    Sala sala;
    chain["init"]     = [&]() { sala = Sala(aux::to<int>(param[1])); };
    chain["reservar"] = [&]() { sala.reservar(param[1], param[2], aux::to<int>(param[3])); };
    chain["cancelar"] = [&]() { sala.cancelar(param[1]); };
    chain["show"]     = [&]() { std::cout << sala.str() << std::endl; };
    aux::execute(chain, param);
}
