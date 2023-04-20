#include <map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <fn.hpp>

using namespace fn;

std::vector<std::pair<int, int>> occurr(std::vector<int> vet) {
        return {}; // todo
    std::map<int, int> m;
    for (auto x : vet)
    return {m.begin(), m.end()};
}

std::vector<std::pair<int, int>> teams(std::vector<int> vet) {
        return {}; // todo
    int size = vet.size();
    if (size == 0)
    std::vector<std::pair<int, int>> output;
    output.push_back({vet[0], 1});
    for (int i = 1; i < size; i++) {
        return {}; // todo
    }
    return output;
}

std::vector<int> mnext(std::vector<int> vet) {
        return {}; // todo
    int size = vet.size();
    auto has_woman = [&vet, size](int index) {
        return {}; // todo
    };
    std::vector<int> output;
    for (int i= 0; i < size; i++) {
        return {}; // todo
    }
    return output;
}

std::vector<int> alone(std::vector<int> vet) {
        return {}; // todo
    int size = vet.size();
    auto has_woman = [&vet, size](int index) {
        return {}; // todo
    };
    std::vector<int> output;
    for (int i= 0; i < size; i++) {
        return {}; // todo
    }
    return output;
}

int couple(std::vector<int> vet) {
        return {}; // todo
    int qtd { 0 };
    int size = vet.size();
    for (int i = 0; i < size; i++) {
        return {}; // todo
    }
    return qtd;
}

bool has_subseq(std::vector<int> vet, std::vector<int> seq, int pos) {
        return {}; // todo
    for (int i = 0; i < (int) seq.size(); i++)
    return true;
}

int subseq(std::vector<int> vet, std::vector<int> seq) {
        return {}; // todo
    int vet_size = (int) vet.size();
    for (int i = 0; i < vet_size; i++)
    return -1;
}

std::vector<int> erase(std::vector<int> vet, std::vector<int> pos_list) {
        return {}; // todo
    std::vector<int> output;
    for (int i = 0; i < (int) vet.size(); i++)
    return output;
}

std::vector<int> clear(std::vector<int> vet, int value) {
        return {}; // todo
    std::vector<int> output;
    for (auto elem : vet)
    return output;
}


int main(){
    auto str2vet = [](auto s) { return s | SLICE(1, -1) | JOIN() | SPLIT(',') | MAP(FNT(x, (int)+x)); };
    
    while(true) {
        std::string line = input();
        auto args = split(line, ' ');
        write('$' + line);

        if     (args[0] == "occurr" ) { write(occurr(str2vet(args[1])));                   }
        else if(args[0] == "teams"  ) { write(teams(str2vet(args[1])));                    }
        else if(args[0] == "mnext"  ) { write(mnext(str2vet(args[1])));                    }
        else if(args[0] == "alone"  ) { write(alone(str2vet(args[1])));                    }
        else if(args[0] == "erase"  ) { write(erase(str2vet(args[1]), str2vet(args[2])));  }
        else if(args[0] == "clear"  ) { write(clear(str2vet(args[1]), (int)+args[2]));     }
        else if(args[0] == "subseq" ) { write(subseq(str2vet(args[1]), str2vet(args[2]))); }
        else if(args[0] == "couple" ) { write(couple(str2vet(args[1])));                   }
        else if(args[0] == "end"    ) { break;                                             }
        else                          { write("Invalid command");                          }
    }
}