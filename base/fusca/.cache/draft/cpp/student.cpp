#include "fn.hpp"
struct CarAdp {
    // Car car;
    CarAdp() {}

    void enter() {
        // car.enter();
    }
    void leave() {
        // car.leave();
    }
    void fuel(int q) {
        // car.fuel(q);
        (void) q;
    }
    void drive(int q) {
        // car.drive(q);
        (void) q;
    }
    std::string str() {
        // return car.str();
        return "";
    }
};

struct Student {
    // Se a variável debug for true, os testes não serão executados
    // Apenas o conteúdo do método run() será executado
    // Você pode usar isso para testar seu código manualmente
    static const bool debug = false;
    static void run() {
        std::cout << "Debug ativado" << std::endl;
    }
};
