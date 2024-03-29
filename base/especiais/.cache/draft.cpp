#include <map>
#include <algorithm>
#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

using namespace fn;

std::vector<std::pair<int, int>> occurr(std::vector<int> vet) {
}

std::vector<std::pair<int, int>> teams(std::vector<int> vet) {
}

std::vector<int> mnext(std::vector<int> vet) {
}

std::vector<int> alone(std::vector<int> vet) {
}

int couple(std::vector<int> vet) {
}

bool has_subseq(std::vector<int> vet, std::vector<int> seq, int pos) {
}

int subseq(std::vector<int> vet, std::vector<int> seq) {
}

std::vector<int> erase(std::vector<int> vet, std::vector<int> pos_list) {
}

std::vector<int> clear(std::vector<int> vet, int value) {
}


int main(){
    auto str2vet = [](auto s) { return s | SLICE(1, -1) | JOIN() | SPLIT(',') | MAP([](auto x){return (int)+x;}); };    
    
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