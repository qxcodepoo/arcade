#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include <sstream>

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


