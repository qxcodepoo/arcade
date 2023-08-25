#include <iostream>
#include <list>
#include <sstream>
#include <memory>
#include <vector>
#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
using namespace fn;

class Kid {
private:
    int age;
    std::string name;
public:
    Kid(std::string name, int age) {
        this->age = age;
        this->name = name;
    }
    int getAge() const {
        return age;
    }
    std::string getName() const {
        return name;
    }
    std::string str() const {
        return name + ":" + std::to_string(age);
    }
};

std::ostream& operator<<(std::ostream& os,  const Kid& kid) {
    return os << kid.str();
}

using PtrKid = std::shared_ptr<Kid>;

class Trampoline {
    std::list<PtrKid> waiting;
    std::list<PtrKid> playing;
    
    PtrKid removeFromList(std::string name, std::list<PtrKid>& lista);

public:
    Trampoline();
    
    void arrive(PtrKid kid);

    void enter();

    void leave();

    PtrKid removeKid(std::string name);
    std::string str() const {
        return fn::tostr(waiting) + " => " + fn::tostr(playing);
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