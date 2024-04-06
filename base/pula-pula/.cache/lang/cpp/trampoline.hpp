#pragma once
#include <iostream>
#include <memory>
#include <list>
#include "fn.hpp"
#include "kid.hpp"

using PtrKid = std::shared_ptr<Kid>;

class Trampoline {
    std::list<PtrKid> waiting;
    std::list<PtrKid> playing;
    
    PtrKid removeFromList(std::string name, std::list<PtrKid>& lista) {
    }

public:
    Trampoline() {
    }
    
    void arrive(PtrKid kid) {
    }

    void enter() {
    }

    void leave() {
    }

    PtrKid removeKid(std::string name) {
    }
    std::string str() const {
        return fn::format("{} => {}", waiting, playing);
    }
};

std::ostream& operator<<(std::ostream& os,  const Trampoline& tr) {
    return os << tr.str();
}
