#include <iostream>
#include <vector>
#include <sstream>
#include <aux.hpp>

int main() {
    aux::Chain chain;
    aux::Param param;
    Sala sala;
    chain["init"]     = [&](){ sala = Sala(aux::to<int>(param[1])); };
    chain["reservar"] = [&](){ sala.reservar(param[1], param[2], aux::to<int>(param[3])); };
    chain["cancelar"] = [&](){ sala.cancelar(param[1]); };
    chain["show"]     = [&](){ cout << sala.toString() << endl; };
    aux::execute(chain, param);
}
