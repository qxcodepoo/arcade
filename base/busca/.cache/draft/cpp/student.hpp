#pragma once

#include <iostream>
#include <vector>

inline bool in(std::vector<int> vet, int x) {
    (void) vet;
    (void) x;
    return false;
}

inline int index_of(std::vector<int> vet, int x) {
    (void) vet;
    (void) x;
    return 0;
}

inline int find_if(const std::vector<int>& vet) {
    (void) vet;
    return 0;
}

inline int min_element(const std::vector<int>& vet) {
    (void) vet;
    return 0;
}

inline int find_min_if(const std::vector<int>& vet) {
    (void) vet;
    return 0;
}

struct Student {
    // Se a variável debug for true, os testes não serão executados
    // Apenas o conteúdo do método run() será executado
    // Você pode usar isso para testar seu código manualmente
    static const bool debug = false;
    static void run() {
        std::cout << "Rodando o arquivo do estudante" << std::endl;
    }
};
