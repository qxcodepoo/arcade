#include <iostream>
#include <list>
#include <sstream>
#include <memory>
#include <aux.hpp>
class Kid {
private:
    int age;
    std::string name;
public:
    Kid(std::string name, int age) {
    }
    int getAge() {
        return {}; // todo
    }
    std::string getName() {
        return {}; // todo
    }
    std::string str() {
        return {}; // todo
    }
};
using PtrKid = std::shared_ptr<Kid>;
class Trampoline {
    std::list<PtrKid> waiting;
    std::list<PtrKid> playing;
    
    PtrKid remove_kid(std::string name, std::list<PtrKid>& lista) {
    }

public:
    Trampoline() {
    }
    ~Trampoline() {
    }
    
    void arrive(PtrKid kid) {
    }

    void enter() {
    }

    void leave() {
    }

    PtrKid remove(std::string name) {
    }
    std::string str() {
        std::string saida = "=> ";
        for(auto kid : waiting)
            saida += kid->str() + " ";
        saida += "=> [ ";
        for(auto kid : playing)
            saida += kid->str() + " ";
        return saida + "]";
    }
};

int main() {
    aux::Chain chain;
    aux::Param param;
    Trampoline tr;
    chain["arrive"] = [&]() { tr.arrive(std::make_shared<Kid>(param[1], aux::to<int>(param[2]))); };
    chain["enter"]  = [&]() { tr.enter(); };
    chain["leave"]  = [&]() { tr.leave(); };
    chain["remove"] = [&]() { tr.remove(param[1]); };
    chain["show"]   = [&]() { std::cout << tr.str() << std::endl; };

    aux::execute(chain, param);
}