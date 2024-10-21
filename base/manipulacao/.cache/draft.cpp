#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

std::vector<int> get_men(std::vector<int> vet) {
    (void) vet;
    return {};
}

std::vector<int> get_calm_women(std::vector<int> vet) {
    (void) vet;
    return {};
}

std::vector<int> sort(std::vector<int> vet) {
    (void) vet;
    return {};
}

std::vector<int> sort_stress(std::vector<int> vet) {
    (void) vet;
    return {};
}

std::vector<int> reverse(std::vector<int> vet) {
    (void) vet;
    return {};
}

void reverse_inplace(std::vector<int> &vet) {
    (void) vet;
}

std::vector<int> unique(std::vector<int> vet) {
    (void) vet;
    return {};
}

std::vector<int> repeated(std::vector<int> vet) {
    (void) vet;
    return {};
}

std::string input() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

template <typename T>
void write(T t) {
    std::cout << t << std::endl;
}

void write(std::vector<int> vet) {
    std::cout << '[';
    for (int i = 0; i < (int) vet.size(); i++) {
        std::cout << (i == 0 ? "" : ", ");
        std::cout << vet[i];
    }
    std::cout << ']' << std::endl;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    std::string elem;
    for (auto c : s) {
        if (c == delim) {
            elems.push_back(elem);
            elem.clear();
        } else {
            elem += c;
        }
    }
    elems.push_back(elem);
    return elems;
}

std::vector<int> str2vet(std::string s) {
    s = s.substr(1, s.size() - 2);
    std::vector<int> vet;
    std::stringstream ss(s);
    std::string elem;
    while (std::getline(ss, elem, ',')) {
        vet.push_back(std::stoi(elem));
    }
    return vet;
}

int main() {
    
    while(true) {
        std::string line = input();
        auto args = split(line, ' ');
        write('$' + line);

        if     (args[0] == "get_men"        ) { write(get_men(str2vet(args[1])));        }
        else if(args[0] == "get_calm_women" ) { write(get_calm_women(str2vet(args[1]))); }
        else if(args[0] == "sort"           ) { write(sort(str2vet(args[1])));           }
        else if(args[0] == "sort_stress"    ) { write(sort_stress(str2vet(args[1])));    }
        else if(args[0] == "reverse"        ) { write(reverse(str2vet(args[1])));        }
        else if(args[0] == "reverse_inplace") { 
            auto vet = str2vet(args[1]);
            reverse_inplace(vet);
            write(vet);
        }
        else if(args[0] == "unique"         ) { write(unique(str2vet(args[1])));         }
        else if(args[0] == "repeated"       ) { write(repeated(str2vet(args[1])));       }
        else if(args[0] == "end"            ) { break;                                   }
    }
}
