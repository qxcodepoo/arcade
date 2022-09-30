#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <aux.hpp>
using namespace aux;

std::vector<std::pair<int, int>> occurr(std::vector<int> vet) {
    return {}; // todo
}

std::vector<std::pair<int, int>> teams(std::vector<int> vet) {
    return {}; // todo
}

std::vector<int> mnext(std::vector<int> vet) {
    return {}; // todo
}

std::vector<int> alone(std::vector<int> vet) {
    return {}; // todo
}

int couple(std::vector<int> vet) {
    return {}; // todo
}

bool has_subseq(std::vector<int> vet, std::vector<int> seq, int pos) {
    return {}; // todo
}

int subseq(std::vector<int> vet, std::vector<int> seq) {
    return {}; // todo
}

std::vector<int> erase(std::vector<int> vet, std::vector<int> pos_list) {
    return {}; // todo
}

std::vector<int> clear(std::vector<int> vet, int value) {
    return {}; // todo
}


//loop principal
int main(){
    Chain chain;
    Param ui;

    chain["occurr"] = [&] { show << occurr(to_vet<int>(ui[1])); };
    chain["mnext"]  = [&] { show <<  mnext(to_vet<int>(ui[1])); };
    chain["alone"]  = [&] { show <<  alone(to_vet<int>(ui[1])); };
    chain["couple"] = [&] { show << couple(to_vet<int>(ui[1])); };
    chain["teams"]  = [&] { show <<  teams(to_vet<int>(ui[1])); };
    chain["subseq"] = [&] { show << subseq(to_vet<int>(ui[1]), to_vet<int>(ui[2])); };
    chain["erase"]  = [&] { show <<  erase(to_vet<int>(ui[1]), to_vet<int>(ui[2])); };
    chain["clear"]  = [&] { show <<  clear(to_vet<int>(ui[1]), to<int>(ui[2])); };

    execute(chain, ui);
}


