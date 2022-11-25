#include <iostream>
#include <list>
#include <sstream>
#include <memory>
#include <vector>

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

    template <class T> void write(T data, std::string end = "\n") {
        std::cout << data << end;
    }
}
using namespace aux;
using namespace std::string_literals;

class Kid {
private:
    int age;
    std::string name;
public:
    Kid(std::string name, int age) {
        this->age = age;
        this->name = name;
    }
    int getAge() {
        return age;
    }
    std::string getName() {
        return name;
    }
    std::string str() {
        return name + ":" + std::to_string(age);
    }
};

using PtrKid = std::shared_ptr<Kid>;

std::ostream& operator<<(std::ostream& os,  PtrKid kid) {
    return os << kid->str();
}

class Trampoline {
    std::list<PtrKid> waiting;
    std::list<PtrKid> playing;
    
    PtrKid removeFromList(std::string name, std::list<PtrKid>& lista) {
    }

public:
    Trampoline() {
    }
    
    void arrive(PtrKid kid) {
    }

    void enter() {
    }

    void leave() {
    }

    PtrKid removeKid(std::string name) {
    }
    std::string str() {
        return "["s + join(waiting) + "] => [" + join(playing) + "]";
    }
};

int main() {
    Trampoline tr;

    while (true) {
        auto line = input();
        write("$" + line);
        auto args = split(line);

        if      (args[0] == "end"   ) { break;                                                     }
        else if (args[0] == "arrive") { tr.arrive(std::make_shared<Kid>(args[1], (int) +args[2])); }
        else if (args[0] == "enter" ) { tr.enter();                                                }
        else if (args[0] == "leave" ) { tr.leave();                                                }
        else if (args[0] == "remove") { tr.removeKid(args[1]);                                     }
        else if (args[0] == "show"  ) { write(tr.str());                                           }
        else                          { write("fail: invalid command");                            }
    }
}