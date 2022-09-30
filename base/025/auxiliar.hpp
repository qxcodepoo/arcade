#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <functional>
#include <map>


#define slambda(x_fn) [](auto& x){ return x_fn; }

namespace aux {

    auto fn_identity = slambda(x);
    //dereferencing
    auto fn_deref = slambda(*x);
    auto fn_pair_key = slambda(x.first);
    auto fn_pair_value = slambda(x.second);
    //dereferencing value of the pair
    auto fn_pair_value_deref = slambda(*x.second);

    //retorna um vector com a transformaçao de cada elemento que passou no predicado
    auto map_filter(const auto& container, auto fn, auto predicate) {
        using output_type = decltype(fn(*container.begin()));
        std::vector<output_type> result;
        for (const auto& item : container)
            if (predicate(item))
                result.push_back(fn(item));
        return result;
    }

    // aplica a função fn em cada elemento do container
    // retorna um vector com os elementos resultantes da função
    auto map(const auto& container, auto fn) {
        return map_filter(container, fn, [](auto& x){ (void) x; return true;});
    }

    // recebe um vector ou um list e retorna um novo container apenas com os elementos
    // que satisfazem o predicado
    template <typename T>
    T filter(const T& container, auto predicate) {
        return map_filter(container, slambda(x), predicate);
    }

    // aplica a função fn sobre cada elemento do container
    // depois junta os resultados em uma string
    // separando os elementos com o delimiter
    // auto fn = [](auto v){return *v;};
    // std::vector<int*> vi = {new int(1), new int(2), new int(3)};
    // std::cout << aux::join(vi, ", ", fn) << '\n';
    std::string join(const auto& container, const std::string& delimiter, auto fn) {
        if(container.size() == 0)
            return "";
        std::ostringstream ss;
        for (const auto& item : container)
            ss << delimiter << fn(item);
        return ss.str().substr(delimiter.size());
    }

    // junta todos os elementos de um container numa string separando com o delimiter
    // join({"a", "b", "c"}, ",") -> "a,b,c"
    // join(std::vector<int>{1, 2, 3}, ",") -> "1,2,3"
    auto join(const auto& container, const std::string& delimiter) {
        return join(container, delimiter, fn_identity);
    }

    // formats a container to a string [v0, v1, v2, v3]
    std::string format(const auto& container) {
        std::stringstream ss;
        ss << "[" << join(container, ", ") << "]";
        return ss.str();
    }

    // extrai um subvetor
    // extrai de início a fim, sem incluir o final
    // se não for passado o final, extrai até o final
    // se não for passado o início, extrai do início ao final
    // se o índice for negativo, conta a partir do final como no python e no js
    template <typename T>
    std::vector<T> slice(const std::vector<T>& container, int start = 0, int end = 0) {
        std::vector<T> result;
        if (end == 0)
            end = container.size();
        if (start < 0)
            start = container.size() + start;
        if (end < 0)
            end = container.size() + end;
        if (start >= end)
            return result;
        auto it_start = container.begin();
        auto it_end = container.begin();
        std::advance(it_start, start);
        std::advance(it_end, end);
        std::copy(it_start, it_end, std::back_inserter(result));
        return result;
    }

    // splits a line in a vector of strings using delimiter ignoring empty strings
    std::vector<std::string> split(const std::string& line, char delimiter) {
        std::istringstream is(line);
        std::vector<std::string> output;
        std::string token;
        while(std::getline(is, token, delimiter))
            if(token.size() > 0)
                output.push_back(token);
        return output;
    }

    // returns a line until \n throwing a exception if stream finishes
    std::string getline(std::istream& is) {
        std::string line;
        if (!std::getline(is, line))
            throw std::runtime_error("EOF");
        return line;
    }

    // convert object to string using os << overload
    template <typename T>
    std::string to_string(T& t) {
        std::stringstream ss;
        ss << t;
        return ss.str();
    }

    std::vector<std::string> getcmd() {
        static bool echo { true };
        std::string line;
        if (!echo)
            std::cout << "$";
        std::getline(std::cin, line);
        if (line == "echo") {
            echo = !echo;
            return {};
        }
        if (echo)
            std::cout << "$" << line << "\n";
        return aux::split(line, ' ');
    }
}