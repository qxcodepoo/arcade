#include "fn.hpp"
#include "student.cpp"

#include <iostream>
#include <string>

void testeEntrando() {
    Student car;
    std::cout << "$Carro criado" << std::endl;
    car.show();
    std::cout << "$Entrando no carro" << std::endl;
    car.enter();
    car.show();
    std::cout << "$Entrando no carro" << std::endl;
    car.enter();
    car.show();
    std::cout << "$Entrando no carro" << std::endl;
    car.enter();
    car.show();
}

void testeSaindo() {
    Student car;
    std::cout << "$Carro criado" << std::endl;
    car.show();
    std::cout << "$Entrando 2 pessoas no carro" << std::endl;
    car.enter();
    car.enter();
    car.show();
    std::cout << "$Saindo do carro" << std::endl;
    car.leave();
    car.show();
    std::cout << "$Saindo do carro" << std::endl;
    car.leave();
    car.show();
    std::cout << "$Saindo do carro" << std::endl;
    car.leave();
    car.show();
}

void testeAbastecendo() {
    Student car;
    std::cout << "$Carro criado" << std::endl;
    car.show();
    std::cout << "$Abastecendo 10 litros" << std::endl;
    car.fuel(10);
    car.show();
    std::cout << "$Abastecendo 30 litros" << std::endl;
    car.fuel(30);
    car.show();
    std::cout << "$Abastecendo 100 litros" << std::endl;
    car.fuel(100);
    car.show();
}

void testeDirigindo() {
    Student car;
    std::cout << "$Carro criado" << std::endl;
    car.show();
    std::cout << "$Tentando dirigir com carro vazio" << std::endl;
    car.drive(10);
    car.show();
    std::cout << "$Entrando no carro" << std::endl;
    car.enter();
    car.show();
    std::cout << "$Testando dirigir sem gasolina" << std::endl;
    car.drive(10);
    car.show();
    std::cout << "$Abastecendo 30 litros" << std::endl;
    car.fuel(30);
    car.show();
    std::cout << "$Testando dirigir com gasolina" << std::endl;
    car.drive(10);
    car.show();
    std::cout << "$Testando dirigir só parte do caminho" << std::endl;
    car.drive(50);
    car.show();
}

int main() {
    std::string cmd;
    std::getline(std::cin, cmd);

    if (cmd == "entrando") {
        testeEntrando();
    } else if (cmd == "saindo") {
        testeSaindo();
    } else if (cmd == "abastecendo") {
        testeAbastecendo();
    } else if (cmd == "dirigindo") {
        testeDirigindo();
    } else {
        std::cout << "Comando não reconhecido." << std::endl;
    }

    return 0;
}
