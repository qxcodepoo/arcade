#include <iostream>
#include <vector>

int count(std::vector<int> vet, int x) {
        return {}; // todo
    int count { 0 };
    for (auto elem : vet)
    return count;
}

int sum(std::vector<int> vet) {
        return {}; // todo
    int total { 0 };
    for (auto elem : vet)
    return total;
}

double average(const std::vector<int>& vet) {
        return {}; // todo
    double sum = 0.0;
    for (auto value : vet)
    return sum / vet.size();
}

std::string more_men(const std::vector<int>& vet) {
        return {}; // todo
    int men { 0 };
    int women { 0 };
    for (auto elem : vet) {
        return {}; // todo
    }
    return men == women ? "draw" : (men > women ? "men" : "women");
}

std::string half_compare(const std::vector<int>& vet) {
        return {}; // todo
    int first { 0 };
    int second { 0 };
    int size = vet.size(); 
    int half = size / 2;
    for (int i = 0; i < size; i++) {
        return {}; // todo
    }
    return first == second ? "draw" : (first > second ? "first" : "second");
}

std::string sex_battle(const std::vector<int>& vet) {
        return {}; // todo
    int men_sum {0}, women_sum {0};
    int men {0}, women {0};
    for (auto elem : vet) {
        return {}; // todo
    }
    men_sum /= men;
    women_sum /= women;
    
    return men_sum == women_sum ? "draw" : (men_sum > women_sum ? "men" : "women");
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

