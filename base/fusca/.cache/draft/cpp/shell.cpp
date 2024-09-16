#include "fn.hpp"
#include "student.cpp"

#include <iostream>
#include <string>

void testeEntrando() {
    CarAdp car;
    std::cout << "$Carro criado" << std::endl;
    std::cout << car.str() << std::endl;
    std::cout << "$Entrando no carro" << std::endl;
    car.enter();
    std::cout << car.str() << std::endl;
    std::cout << "$Entrando no carro" << std::endl;
    car.enter();
    std::cout << car.str() << std::endl;
    std::cout << "$Entrando no carro" << std::endl;
    car.enter();
    std::cout << car.str() << std::endl;
}

void testeSaindo() {
    CarAdp car;
    std::cout << "$Carro criado" << std::endl;
    std::cout << car.str() << std::endl;
    std::cout << "$Entrando 2 pessoas no carro" << std::endl;
    car.enter();
    car.enter();
    std::cout << car.str() << std::endl;
    std::cout << "$Saindo do carro" << std::endl;
    car.leave();
    std::cout << car.str() << std::endl;
    std::cout << "$Saindo do carro" << std::endl;
    car.leave();
    std::cout << car.str() << std::endl;
    std::cout << "$Saindo do carro" << std::endl;
    car.leave();
    std::cout << car.str() << std::endl;
}

void testeAbastecendo() {
    CarAdp car;
    std::cout << "$Carro criado" << std::endl;
    std::cout << car.str() << std::endl;
    std::cout << "$Abastecendo 10 litros" << std::endl;
    car.fuel(10);
    std::cout << car.str() << std::endl;
    std::cout << "$Abastecendo 30 litros" << std::endl;
    car.fuel(30);
    std::cout << car.str() << std::endl;
    std::cout << "$Abastecendo 100 litros" << std::endl;
    car.fuel(100);
    std::cout << car.str() << std::endl;
}

void testeDirigindo() {
    CarAdp car;
    std::cout << "$Carro criado" << std::endl;
    std::cout << car.str() << std::endl;
    std::cout << "$Tentando dirigir com carro vazio" << std::endl;
    car.drive(10);
    std::cout << car.str() << std::endl;
    std::cout << "$Entrando no carro" << std::endl;
    car.enter();
    std::cout << car.str() << std::endl;
    std::cout << "$Testando dirigir sem gasolina" << std::endl;
    car.drive(10);
    std::cout << car.str() << std::endl;
    std::cout << "$Abastecendo 30 litros" << std::endl;
    car.fuel(30);
    std::cout << car.str() << std::endl;
    std::cout << "$Testando dirigir com gasolina" << std::endl;
    car.drive(10);
    std::cout << car.str() << std::endl;
    std::cout << "$Testando dirigir só parte do caminho" << std::endl;
    car.drive(50);
    std::cout << car.str() << std::endl;
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
