#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

bool in(std::vector<int> vet, int x) {
    return {};
}

int index_of(std::vector<int> vet, int x) {
    return {};
}

int find_if(const std::vector<int>& vet) {
    return {};
}

int min_element(const std::vector<int>& vet) {
    return {};
}

int find_min_if(const std::vector<int>& vet) {
    return {};
}
#include <algorithm>

using namespace fn;

int main() {

    auto str2vet = [](auto s) { return s | SLICE(1, -1) | JOIN() | SPLIT(',') | MAP([](auto x){return (int)+x;}); };

    while (true) {
        auto line = input();
        write("$" + line);
        auto args = split(line);

        if      (args[0] == "end"        ) { break;                                            }
        else if (args[0] == "in"         ) { write(   tostr(in(str2vet(args[1]), +args[2]))); }
        else if (args[0] == "index_of"   ) { write(   index_of(str2vet(args[1]), +args[2]));  }
        else if (args[0] == "find_if"    ) { write(    find_if(str2vet(args[1])));            }
        else if (args[0] == "min_element") { write(min_element(str2vet(args[1])));            }
        else if (args[0] == "find_min_if") { write(find_min_if(str2vet(args[1])));            }
        else                               { write("fail: unknown command");                   }
    }     
}