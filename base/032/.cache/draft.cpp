#include <iostream>
#include <algorithm>
#include <vector>
#include <fn.hpp>

using namespace fn;

std::vector<int> get_men(std::vector<int> vet) {
        return {}; // todo
    std::vector<int> unique;
    for (auto elem : vet)
    return unique;
}

std::vector<int> get_calm_women(std::vector<int> vet) {
        return {}; // todo
    std::vector<int> unique;
    for (auto elem : vet)
    return unique;
}

std::vector<int> sort(std::vector<int> vet) {
        return {}; // todo
    std::sort(vet.begin(), vet.end());
    return vet;
}

std::vector<int> sort_stress(std::vector<int> vet) {
        return {}; // todo
    std::sort(vet.begin(), vet.end(), [] (int a, int b) {
        return {}; // todo
    });
    return vet;
}

std::vector<int> reverse(std::vector<int> vet) {
        return {}; // todo
    std::reverse(vet.begin(), vet.end());
    return vet;
}

std::vector<int> unique(std::vector<int> vet) {
    return {}; // todo
}

std::vector<int> repeated(std::vector<int> vet) {
    return {}; // todo

}


int main() {
    auto strToVet = [](auto s) { return s.substr(1, s.size() - 2) | SPLIT(',') | MAP(FNT(x, (int)+x)); };

    while(true) {
        std::string line = input();
        auto args = split(line, ' ');
        write('$' + line);

        if     (args[0] == "get_men"        ) { write(get_men(strToVet(args[1])));        }
        else if(args[0] == "get_calm_women" ) { write(get_calm_women(strToVet(args[1]))); }
        else if(args[0] == "sort"           ) { write(sort(strToVet(args[1])));           }
        else if(args[0] == "sort_stress"    ) { write(sort_stress(strToVet(args[1])));    }
        else if(args[0] == "reverse"        ) { write(reverse(strToVet(args[1])));        }
        else if(args[0] == "unique"         ) { write(unique(strToVet(args[1])));         }
        else if(args[0] == "repeated"       ) { write(repeated(strToVet(args[1])));       }
        else if(args[0] == "end"            ) { break;                                    }
    }
}


