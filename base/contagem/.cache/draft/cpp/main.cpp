#include "fn.hpp"
#include "student.hpp"
using namespace fn;

int main() {
    //função para converted de "[1,2,3,4]" em std::vector<int>{1,2,3,4}
    auto str2vet = [](auto s) { return s | SLICE(1, -1) | JOIN() | SPLIT(',') | MAP(strto<int>); };

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
