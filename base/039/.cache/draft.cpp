#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

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


#include <aux.hpp>
using namespace aux;

//loop principal
int main(){
    Chain chain;
    Param ui;

    auto par2int   = LAMBDAE(&ui, i, ui.at(i) | aux::STR2<int>());                            //converte de string para int
    auto par2vet   = LAMBDAE(&ui, i, ui.at(i) | COPY(1, -1) | SPLIT(',') | MAP(STR2<int>())); //converte de string para vetor de int
    auto pair2str  = LAMBDA(p, STREAM() | p.first | ":" | p.second | COLLECT()); //converte de pair para string

    chain["occurr"] = [&] { occurr(par2vet(1)) | MAP(pair2str) | FMT() | PRINT(); };
    chain["teams"]  = [&] {  teams(par2vet(1)) | MAP(pair2str) | FMT() | PRINT(); };
    chain["mnext"]  = [&] {  mnext(par2vet(1))                 | FMT() | PRINT(); };
    chain["alone"]  = [&] {  alone(par2vet(1))                 | FMT() | PRINT(); };
    chain["erase"]  = [&] {  erase(par2vet(1), par2vet(2))     | FMT() | PRINT(); };
    chain["clear"]  = [&] {  clear(par2vet(1), par2int(2))     | FMT() | PRINT(); };
    chain["subseq"] = [&] { subseq(par2vet(1), par2vet(2))             | PRINT(); };
    chain["couple"] = [&] { couple(par2vet(1))                         | PRINT(); };

    execute(chain, ui);
}


