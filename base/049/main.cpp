#include <iostream>
#include <sstream>
#include <vector>
#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
using namespace fn;

int main() {
    std::vector<int> vet;
    while (true) {
        auto line = input();
        write("$" + line);
        auto args = split(line);

        if      (args[0] == "end")   { break;                                                               }
        else if (args[0] == "push")  { 
            for (size_t i = 1; i < args.size(); ++i) { 
                vet.push_back((int) number(args[i])); 
            } 
        }
        else if (args[0] == "show")  { write("[" + join(vet, ", ") + "]");                                  }
        else if (args[0] == "erase") { vet.erase(vet.begin() + (int) number(args[1]));                      }
        else if (args[0] == "media") {
            double sum = 0;
            for (auto item : vet) {
                sum += item;
            }
            write(format("{%.2f}", sum / vet.size()));
        }
        else                         { write("fail: invalid command");                                      }
    }
}