#include <iostream>
#include <sstream>
#include <aux.hpp>

int main() {
    aux::Chain chain;
    aux::Param ui;

    Car car;

    chain["help"]  = [&](){ aux::show << "show; enter; leave; fuel _gas; drive _km; end"; };
    chain["show"]  = [&](){ aux::show << car.str(); };
    chain["enter"] = [&](){ car.enter(); };
    chain["leave"] = [&](){ car.leave(); };
    chain["fuel"]  = [&](){ car.fuel(aux::to<int>(ui[1])); };
    chain["drive"] = [&](){ car.drive(aux::to<int>(ui[1])); };

    aux::execute(chain, ui);
}
