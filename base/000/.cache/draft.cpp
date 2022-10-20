#include <iostream>
#include <vector>
#include <aux.hpp>  // https://raw.githubusercontent.com/senapk/cppaux/master/aux.hpp
using namespace aux;

bool in(std::vector<int> vet, int x) {
    return {}; // todo
}

int index_of(std::vector<int> vet, int x) {
    return {}; // todo
}

int find_if(const std::vector<int>& vet) {
    return {}; // todo
}

int min_element(const std::vector<int>& vet) {
    return {}; // todo
}

int find_min_if(const std::vector<int>& vet) {
    return {}; // todo
}


using namespace aux;

int main(){
    Chain chain;
    Param ui;

    auto bool2str = LAMBDA(x, x ? "true" : "false"); //converte de bool para string true or false
    auto INT  = LAMBDA(x, x | aux::STR2<int>());                            //converte de string para int
    auto VET  = LAMBDA(x, x | COPY(1, -1) | SPLIT(',') | MAP(STR2<int>())); //converte de string para vetor de int

    chain["in"]           = [&] {          in(VET(ui.at(1)), INT(ui.at(2))) | PIPE(bool2str) | PRINT(); };
    chain["index_of"]     = [&] {    index_of(VET(ui.at(1)), INT(ui.at(2))) | PRINT(); };
    chain["find_if"]      = [&] {     find_if(VET(ui.at(1))               ) | PRINT(); };
    chain["min_element"]  = [&] { min_element(VET(ui.at(1))               ) | PRINT(); };
    chain["find_min_if"]  = [&] { find_min_if(VET(ui.at(1))               ) | PRINT(); };

    execute(chain, ui);
}
