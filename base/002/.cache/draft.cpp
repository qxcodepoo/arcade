#include <iostream>
#include <sstream>
#include <aux.hpp>

int main() {
    aux::Chain chain;
    aux::Param ui;

    Car car;

    auto par2int   = LAMBDAE(&ui, index, ui.at(index) | aux::STR2<int>()); //converte de string para int

    chain["show"]  = [&](){ car.str() | aux::PRINT(); };
    chain["enter"] = [&](){ car.enter(); };
    chain["leave"] = [&](){ car.leave(); };
    chain["fuel"]  = [&](){ car.fuel(par2int(1)); };
    chain["drive"] = [&](){car.drive(par2int(1)); };

    aux::execute(chain, ui);
}
