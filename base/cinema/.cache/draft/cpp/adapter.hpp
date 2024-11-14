#pragma once
#include <iostream>
class Adapter{
public:
    Adapter(int qtd = 0)
    {
        : sala(qtd) {
        (void) qtd;
    }

    void reservar(std::string id, std::string fone, int ind) {
        sala.reservar(id, fone, ind);
        (void) id;
        (void) fone;
        (void) ind;
    }

    void cancelar(std::string id) {
        sala.cancelar(id);
        (void) id;
    }

    std::string str() const {
        return sala.str();
        return "";
    }
};

inline std::ostream& operator<<(std::ostream& os, const Adapter& c) {
    return os << c.str();
}
