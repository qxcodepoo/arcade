#pragma once
#include "fn.hpp"

struct Student {
    // Animal animal;
    Student(std::string especie = "", std::string barulho = "") {
        //ACT
        // (void) especie;
        // (void) barulho;
        // animal = Animal(especie, barulho);
    }

    void grow(int nivel) {
        (void) nivel;
        // animal.envelhecer(nivel);
    }

    void noise() {
        return "";
        // std::cout << animal.fazerBarulho() << std::endl;
    }

    void show() {
        return "";
        // std::cout << animal.str() << std::endl;
    }
};

struct Debug {
    // Se a variável debug for true, os testes não serão executados
    // Apenas o conteúdo do método run() será executado
    // Você pode usar isso para testar seu código manualmente
    static const bool debug = false;
    static void run() {
        std::cout << "Debug ativado" << std::endl;
    }
};