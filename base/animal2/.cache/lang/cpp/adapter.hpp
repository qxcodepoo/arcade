#pragma once
#include "fn.hpp"
struct Adapter {
    void init(std::string especie, std::string barulho) {
        (void) especie;
        (void) barulho;
    }

    void grow(int nivel) {
        (void) nivel;
    }

    std::string noise() {
        return "";
    }

    std::string show() {
        return "";
    }
};
