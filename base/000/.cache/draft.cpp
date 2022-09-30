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


//loop principal
int main(){
    Chain chain;
    Param ui;

    chain["in"]           = [&] { show <<          in(to_vet<int>(ui[1]), to<int>(ui[2])); };
    chain["index_of"]     = [&] { show <<    index_of(to_vet<int>(ui[1]), to<int>(ui[2])); };
    chain["find_if"]      = [&] { show <<     find_if(to_vet<int>(ui[1])                ); };
    chain["min_element"]  = [&] { show << min_element(to_vet<int>(ui[1])                ); };
    chain["find_min_if"]  = [&] { show << find_min_if(to_vet<int>(ui[1])                ); };

    execute(chain, ui);
}
