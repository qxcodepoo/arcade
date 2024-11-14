#pragma once
#include "fn.hpp"

struct Student {
    // Animal animal;
    void init(std::string especie = "", std::string barulho = "") {
        (void) especie;
        (void) barulho;
        // animal = Animal(especie, barulho);
    }

    void grow(int nivel) {
        (void) nivel;
        // animal.envelhecer(nivel);
    }

    void noise() {
        // std::cout << animal.fazerBarulho() << std::endl;
    }

    void show() {
        // std::cout << animal.str() << std::endl;
    }
};