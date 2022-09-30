#include <iostream>
#include <algorithm>
#include <vector>
#include <aux.hpp>
using namespace aux;


std::vector<int> get_men(std::vector<int> vet) {
    return {}; // todo
}

std::vector<int> get_calm_women(std::vector<int> vet) {
    return {}; // todo
}

std::vector<int> sort(std::vector<int> vet) {
    return {}; // todo
}

std::vector<int> sort_stress(std::vector<int> vet) {
    return {}; // todo
}

std::vector<int> reverse(std::vector<int> vet) {
    return {}; // todo
}

void reverse_inplace(std::vector<int> &vet) {
}

std::vector<int> unique(std::vector<int> vet) {
    return {}; // todo
}

std::vector<int> repeated(std::vector<int> vet) {
    return {}; // todo

}


//loop principal
int main(){
    Chain chain;
    Param ui;

    chain["get_men"]         = [&] { show <<        get_men(to_vet<int>(ui[1])); };
    chain["get_calm_women"]  = [&] { show << get_calm_women(to_vet<int>(ui[1])); };
    chain["sort"]            = [&] { show <<           sort(to_vet<int>(ui[1])); };
    chain["sort_stress"]     = [&] { show <<    sort_stress(to_vet<int>(ui[1])); };
    chain["reverse"]         = [&] { show <<        reverse(to_vet<int>(ui[1])); };
    chain["reverse_inplace"] = [&] { 
        auto vet = to_vet<int>(ui[1]);
        reverse_inplace(vet);
        show << (vet);
    };
    chain["unique"]          = [&] { show <<         unique(to_vet<int>(ui[1])); };
    chain["repeated"]        = [&] { show <<       repeated(to_vet<int>(ui[1])); };

    execute(chain, ui);
}


