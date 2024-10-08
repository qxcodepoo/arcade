#include "animal.hpp"


struct Adapter {
    Animal animal;
    Adapter(std::string especie = "", std::string barulho = "") {
        animal = Animal(especie, barulho);
    }

    void grow(int nivel) {
        animal.envelhecer(nivel);
    }

    std::string noise() {
        return animal.fazerBarulho();
    }

    std::string show() {
        return animal.str();
    }
};

struct Student {
    static const bool debug = false;
    static void run() {
        std::cout << "Debug ativado" << std::endl;
    }
};