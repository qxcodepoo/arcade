#include "animal.hpp"


struct Adapter {
    Adapter(std::string especie = "", std::string barulho = "") {
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

struct Student {
    // Se a variável debug for true, os testes não serão executados
    // Apenas o conteúdo do método run() será executado
    // Você pode usar isso para testar seu código manualmente
    static const bool debug = false;
    static void run() {
    }
};