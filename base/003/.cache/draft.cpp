#include <iostream>
#include <sstream>
#include <memory>

class Person {
    std::string name; //atributo
    int age;
public:
    Person(std::string name = "", int age = 0) {
    }

    Person(int age) { //todo Person("", age) {
    }

    int getAge() {
        return {}; // todo
    }
    std::string getName() {
        return {}; // todo
    }
    std::string str() {
        return {}; // todo
    }
};
std::ostream& operator<<(std::ostream& os, Person& p) {
    return os << p.str();
}

class Motorcycle {
    std::shared_ptr<Person> person {nullptr}; //agregação
    int time {0};
    int power {1};

public:
    Motorcycle(int power = 1) { //todo power {power} {
    }

    bool insertPerson(std::shared_ptr<Person> p) {
        return {}; // todo
    }

    std::string honk() {
        return {}; // todo
    }

    std::shared_ptr<Person> remove() {
        return {}; // todo
    }

    void buyTime(int time) {
    }

    void drive(int time) {
    }
    std::string str() {
        std::ostringstream os;
        os << "power:" << power << ", time:" << time;
        os << ", person:(" << (person == nullptr ? "empty" : person->str()) << ")";
        return os.str();
    }
};

std::ostream& operator<<(std::ostream& os, Motorcycle m) {
    return os << m.str();
}

#include <fn.hpp>
using namespace fn;

int main() {
    Motorcycle m(1);

    while (true) {
        std::string line = input();
        auto args = split(line, ' ');
        write('$' + line);

        if      (args[0] == "show")   { write(m.str());                                                     }
        else if (args[0] == "leave")  { 
            auto person = m.remove(); 
            if (person != nullptr)
                write(person->str());
        }
        else if (args[0] == "honk")   { write(m.honk());                                                    }
        else if (args[0] == "init")   { m = Motorcycle(number(args[1]));                                    }
        else if (args[0] == "enter")  { m.insertPerson(std::make_shared<Person>(args[1], number(args[2]))); }
        else if (args[0] == "buy")    { m.buyTime(number(args[1]));                                         }
        else if (args[0] == "drive")  { m.drive(number(args[1]));                                           }
        else if (args[0] == "end")    { break;                                                              }
        else                          { write("fail: invalid command");                                     }
    }
}
