#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
#include <utility>
#include <aux.hpp>

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

    static int procurarPorNome(std::string id, std::vector<std::shared_ptr<Pass>> &cadeiras) {
        return {}; // todo
    }
    static int procurarVaga(std::vector<std::shared_ptr<Pass>> &cadeiras) {
        return {}; // todo
    }
    static int sentar(std::shared_ptr<Pass> pass, std::vector<std::shared_ptr<Pass>> &cadeiras) {
        return {}; // todo
    }
    static std::shared_ptr<Pass> descer(std::string id, std::vector<std::shared_ptr<Pass>> &cadeiras) {
        return {}; // todo
    }

public:

    Topic(int lotacao = 0, int qtdPref = 0) { //todo 
    }

    bool subir(std::shared_ptr<Pass> pass) {
        return {}; // todo
    }

    std::shared_ptr<Pass> descer(std::string id) {
        return {}; // todo
    }
    std::string str(); 
};


int main(){
    aux::Chain chain;
    aux::Param param;
    Topic topic;

    chain["init"] = [&](){
        topic = Topic(aux::to<int>(param[1]), aux::to<int>(param[2]));
    };
    chain["show"] = [&](){
        std::cout << topic.str() << std::endl;
    };
    chain["in"] = [&](){
        topic.subir(std::make_shared<Pass>(param[1], aux::to<int>(param[2])));
    };
    chain["out"] = [&](){
        topic.descer(param[1]);
    };
    aux::execute(chain, param);
}
