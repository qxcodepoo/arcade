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


#include <fn.hpp>
using namespace fn;

int main() {

    auto str2vet = [](auto s) { return s.substr(1, s.size() - 2) | SPLIT(',') | MAP(FNT(x, (int)+x)); };

    while (true) {
        auto line = input();
        write("$" + line);
        auto args = split(line);

        if      (args[0] == "end"              ) { break;                                              }
        else if (args[0] == "count"            ) { count(str2vet(args[1]), +args[2])         | WRITE();}
        else if (args[0] == "sum"              ) { sum(str2vet(args[1]))                     | WRITE();}
        else if (args[0] == "more_men"         ) { more_men(str2vet(args[1]))                | WRITE();} 
        else if (args[0] == "half_compare"     ) { half_compare(str2vet(args[1]))            | WRITE();}
        else if (args[0] == "more_men_or_women") { more_men(str2vet(args[1]))                | WRITE();}
        else if (args[0] == "sex_battle"       ) { sex_battle(str2vet(args[1]))              | WRITE();}
        else if (args[0] == "average"          ) { average(str2vet(args[1])) | TOSTR("%.2f") | WRITE();}
        else                                     { "fail: unknown command"                   | WRITE();}
    }     
}

