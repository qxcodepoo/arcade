#include <iostream>
#include <vector>
#include <sstream>

template <class T, class FN> 
std::string join(T container, std::string sep, FN fn) { 
    std::stringstream ss;
    for (auto item : container)
        ss << sep << fn(item);
    return ss.str().substr(sep.size());
}

template <class T> 
std::string join(T container, std::string sep) { 
    return join(container, sep, [](auto item) { return item; });
}

int main() {
    std::vector<std::string> v = {"a", "b", "c"};
    std::cout << join(v, ", ") << std::endl;
    {
        int i = 0;
        std::cout << join(v, ", ", [&i](std::string s) { return s + s; }) << std::endl;
    }
    std::cout << join(v, ", ", [](std::string s) { return s + s + s; }) << std::endl;
}