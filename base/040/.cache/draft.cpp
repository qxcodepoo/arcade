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
        if (std::getline(std::cin, line))
            return line;
        std::cout << "fail: input error\n";
        return "";
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


//loop principal
int main(){
    Chain chain;
    Param ui;

    auto float2str= LAMBDA(x, x | aux::STR("%.2f"));                            //converte de float para string com 2 casas
    auto INT      = LAMBDA(x, x | aux::STR2<int>());                            //converte de string para int
    auto VET      = LAMBDA(x, x | COPY(1, -1) | SPLIT(',') | MAP(STR2<int>())); //converte de string para vetor de int

    chain["count"]        = [&] {        count(VET(ui[1]), INT(ui[2])) | PRINT(); };
    chain["sum"]          = [&] {          sum(VET(ui[1])            ) | PRINT(); };
    chain["average"]      = [&] {      average(VET(ui[1])            ) | PIPE(float2str) | PRINT(); };
    chain["more_men"]     = [&] {     more_men(VET(ui[1])            ) | PRINT(); };
    chain["half_compare"] = [&] { half_compare(VET(ui[1])            ) | PRINT(); };
    chain["sex_battle"]   = [&] {   sex_battle(VET(ui[1])            ) | PRINT(); };

    execute(chain, ui);
}
