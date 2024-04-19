#pragma once
#include <iostream>
class Adapter{
public:
    Adapter(int qtd = 0)
    {
        (void) qtd;
    }

    void reservar(std::string id, std::string fone, int ind) {
        (void) id;
        (void) fone;
        (void) ind;
    }

    void cancelar(std::string id) {
        (void) id;
    }

    std::string str() const {
        return "";
    }
};

inline std::ostream& operator<<(std::ostream& os, const Adapter& c) {
    return os << c.str();
}

