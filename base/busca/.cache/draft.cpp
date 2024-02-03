#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

bool in(std::vector<int> vet, int x) {
}

int index_of(std::vector<int> vet, int x) {
}

int find_if(const std::vector<int>& vet) {
}

int min_element(const std::vector<int>& vet) {
}

int find_min_if(const std::vector<int>& vet) {
}

#include <algorithm>

using namespace fn;

int main() {

    auto str2vet = [](auto s) { return s | SLICE(1, -1) | JOIN() | SPLIT(',') | MAP([](auto x){return (int)+x;}); };

    while (true) {
        auto line = input();
        write("$" + line);
        auto args = split(line);

        if      (args[0] == "in"         ) { 
            auto result = in(str2vet(args[1]), +args[2]);
            write(result ? "true" : "false");
        }
        else if (args[0] == "index_of"   ) { 
            auto result = index_of(str2vet(args[1]), +args[2]);
            write(result);
        }
        else if (args[0] == "find_if"    ) { 
            auto result = find_if(str2vet(args[1]));
            write(result);
        }
        else if (args[0] == "min_element") { 
            auto result = min_element(str2vet(args[1]));
            write(result);
        }
        else if (args[0] == "find_min_if") { 
            auto result = find_min_if(str2vet(args[1]));
            write(result);
        }
        else if (args[0] == "end") {
            break;
        }
        else {
            write("fail: unknown command");
        }
    }
}