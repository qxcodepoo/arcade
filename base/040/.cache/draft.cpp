#include <iostream>
#include <vector>
#include <aux.hpp> 
using namespace aux;


int count(std::vector<int> vet, int x) {
    return {}; // todo
}

int sum(std::vector<int> vet) {
    return {}; // todo
}

double average(const std::vector<int>& vet) {
    return {}; // todo
}

std::string more_men(const std::vector<int>& vet) {
    return {}; // todo
}

std::string half_compare(const std::vector<int>& vet) {
    return {}; // todo
}

std::string sex_battle(const std::vector<int>& vet) {
    return {}; // todo
}



//loop principal
int main(){
    Chain chain;
    Param ui;

    chain["count"]        = [&] { show <<        count(to_vet<int>(ui[1]), to<int>(ui[2])); };
    chain["sum"]          = [&] { show <<          sum(to_vet<int>(ui[1])                ); };
    chain["average"]      = [&] { show <<      average(to_vet<int>(ui[1])                ); };
    chain["more_men"]     = [&] { show <<     more_men(to_vet<int>(ui[1])                ); };
    chain["half_compare"] = [&] { show << half_compare(to_vet<int>(ui[1])                ); };
    chain["sex_battle"]   = [&] { show <<   sex_battle(to_vet<int>(ui[1])                ); };

    execute(chain, ui);
}
