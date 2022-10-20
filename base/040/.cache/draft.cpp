#include <iostream>
#include <vector>



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

#include <aux.hpp>
using namespace aux;

//loop principal
int main(){
    Chain chain;
    Param ui;

    auto float2str= LAMBDA(x, x | aux::STR("%.2f"));                            //converte de float para string com 2 casas
    auto INT      = LAMBDA(x, x | aux::STR2<int>());                            //converte de string para int
    auto VET      = LAMBDA(x, x | COPY(1, -1) | SPLIT(',') | MAP(STR2<int>())); //converte de string para vetor de int

    chain["count"]        = [&] {        count(VET(ui[1]), INT(ui[2])) | PRINT(); };
    chain["sum"]          = [&] {          sum(VET(ui[1])            ) | PRINT(); };
    chain["average"]      = [&] {      average(VET(ui[1])            ) | PIPE(float2str) | PRINT(); };
    chain["more_men"]     = [&] {     more_men(VET(ui[1])            ) | PRINT(); };
    chain["half_compare"] = [&] { half_compare(VET(ui[1])            ) | PRINT(); };
    chain["sex_battle"]   = [&] {   sex_battle(VET(ui[1])            ) | PRINT(); };

    execute(chain, ui);
}
