#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include <utility>


class Pass{
    std::string id;
    int idade;
public:
    Pass(std::string id = "", int idade = 0  ){
        this->id = id;
        this->idade = idade;
    }
    bool isPref() {
        return idade >= 65;
    }
    std::string getId() {
        return id;
    }
    int getIdade() {
        return idade;
    }
    std::string str() {
        return (std::stringstream() << id << ":" << idade).str();
    }
};

std::ostream& operator<<(std::ostream& os, Pass p) {
    return os << p.str();
}
class Topic{
    std::vector<std::shared_ptr<Pass>> preferenciais;
    std::vector<std::shared_ptr<Pass>> normais;
    int qtdPref;

    static int procurarPorNome(std::string id, std::vector<std::shared_ptr<Pass>> &cadeiras) { return {}; }
    static int procurarVaga(std::vector<std::shared_ptr<Pass>> &cadeiras) { return {}; }
    static int sentar(std::shared_ptr<Pass> pass, std::vector<std::shared_ptr<Pass>> &cadeiras) { return {}; }
    static std::shared_ptr<Pass> descer(std::string id, std::vector<std::shared_ptr<Pass>> &cadeiras) { return {}; }

public:

    Topic(int lotacao = 0, int qtdPref = 0): 

    bool subir(std::shared_ptr<Pass> pass) { return {}; }

    std::shared_ptr<Pass> descer(std::string id) { return {}; }
};


