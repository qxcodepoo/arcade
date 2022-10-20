#include <iostream>
#include <algorithm>
#include <vector>


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


#include <aux.hpp>
using namespace aux;

//loop principal
int main(){
    Chain chain;
    Param ui;

    auto VET  = LAMBDA(x, x | COPY(1, -1) | SPLIT(',') | MAP(STR2<int>())); //converte de string para vetor de int
    auto par2vet = LAMBDAE(&, index, VET(ui.at(index)));

    chain["get_men"]         = [&] {        get_men(par2vet(1)) | FMT() | PRINT(); };
    chain["get_calm_women"]  = [&] { get_calm_women(par2vet(1)) | FMT() | PRINT(); };
    chain["sort"]            = [&] {           sort(par2vet(1)) | FMT() | PRINT(); };
    chain["sort_stress"]     = [&] {    sort_stress(par2vet(1)) | FMT() | PRINT(); };
    chain["reverse"]         = [&] {        reverse(par2vet(1)) | FMT() | PRINT(); };
    chain["repeated"]        = [&] {       repeated(par2vet(1)) | FMT() | PRINT(); };
    chain["unique"]          = [&] {         unique(par2vet(1)) | FMT() | PRINT(); };
    chain["reverse_inplace"] = [&] { 
        auto vet = par2vet(1);
        reverse_inplace(vet);
        vet | FMT() | PRINT();
    };

    execute(chain, ui);
}


