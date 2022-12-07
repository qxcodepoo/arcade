#include <iostream>
#include <vector>

bool in(std::vector<int> vet, int x) {
    return {}; // todo
}

int index_of(std::vector<int> vet, int x) {
    return {}; // todo
}

int find_if(const std::vector<int>& vet) {
    return {}; // todo
}

int min_element(const std::vector<int>& vet) {
    return {}; // todo
}

int find_min_if(const std::vector<int>& vet) {
    return {}; // todo
}



#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#define fmap(x, fx) [](auto x){return fx;}

namespace aux {
    double number(std::string text) {
        std::stringstream ss(text);
        double value {};
        if (ss >> value) {
            return value;
        }
        std::cout << "fail: (" << text << ") is not a number\n";
        return 0.0;
    }
    
    double operator+(std::string text) {
        return number(text);
    }

    std::vector<std::string> split(std::string line, char delimiter = ' ') {
        std::stringstream ss(line);
        std::vector<std::string> result;
        std::string token;
        while (std::getline(ss, token, delimiter)) {
            result.push_back(token);
        }
        return result;
    }

    template <class T, class FN> std::string join(T container, std::string sep, FN fn) { 
        std::stringstream ss;
        for (auto it = container.begin(); it != container.end(); ++it) {
            ss << (it == container.begin() ? "" : sep) << fn(*it);
        }
        return ss.str();
    }

    template <class T> std::string join(T container, std::string sep = ", ") {
        return join(container, sep, [](auto item) { return item; });
    }

    std::string input() {
        std::string line;
        std::getline(std::cin, line);
        return line;
    }

    template <class T> T write(T data, std::string end = "\n") {
        std::cout << data << end;
        return data;
    }

    template<typename CONTAINER, typename FN>
    auto map(CONTAINER container, FN fn) {
        std::vector<decltype(fn(*container.begin()))> aux;
        for (auto item : container) {
            aux.push_back(fn(item));
        }
        return aux;
    };


}
using namespace aux;

int main() {

    std::vector<int> vet = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto BOOL2STR = fmap(x, x ? "true" : "false");
    auto STRTOVET = [](auto s) { return map(split(s.substr(1, s.size() - 2), ','), fmap(x, (int)+x)); };

    while (true) {
        auto line = input();
        write("$" + line);
        auto args = split(line);

        if      (args[0] == "end"        ) { break; }
        else if (args[0] == "in"         ) { write(BOOL2STR(in(STRTOVET(args[1]), +args[2]))); }
        else if (args[0] == "index_of"   ) { write(   index_of(STRTOVET(args[1]), +args[2])); }
        else if (args[0] == "find_if"    ) { write(    find_if(STRTOVET(args[1]))); }
        else if (args[0] == "min_element") { write(min_element(STRTOVET(args[1]))); }
        else if (args[0] == "find_min_if") { write(find_min_if(STRTOVET(args[1]))); }
        else                               { write("fail: unknown command"); }
    }    
}
