#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
#include <memory>

class Person {
    std::string name; //atributo
    int age;
public:
    Person(std::string name = "", int age = 0) {
    }

    Person(int age) : Person("", age) {
    }

    int getAge() const {
    }
    std::string getName() const {
    }
    std::string str() const {
    }
};
std::ostream& operator<<(std::ostream& os, const Person& p) {
    return os << p.str();
}

class Motorcycle {
    std::shared_ptr<Person> person {nullptr}; //agregação
    int time {0};
    int power {1};

public:
    Motorcycle(int power = 1): power {power} {
    }

    bool insertPerson(std::shared_ptr<Person> p) {
    }


    std::shared_ptr<Person> remove() {
    }

    std::string honk() const {
    }

    void buyTime(int time) {
    }

    void drive(int time) {
    }
    std::string str() const {
        auto value = person == nullptr ? "empty" : person->str();
        return fn::format("power:{}, time:{}, person:({})", power, time, value);
    }
};

std::ostream& operator<<(std::ostream& os, const Motorcycle& m) {
    return os << m.str();
}



int main() {
    Motorcycle m(1);

    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write('$' + line);

        if      (args[0] == "show")   { fn::write(m.str());                                          }
        else if (args[0] == "leave")  { 
            auto person = m.remove(); 
            if (person != nullptr)
                fn::write(person->str());
        }
        else if (args[0] == "init")   { m = Motorcycle(+args[1]);                                    }
        else if (args[0] == "enter")  { m.insertPerson(std::make_shared<Person>(args[1], +args[2])); }
        else if (args[0] == "honk")   { fn::write(m.honk());                                         }
        else if (args[0] == "buy")    { m.buyTime(+args[1]);                                         }
        else if (args[0] == "drive")  { m.drive(+args[1]);                                           }
        else if (args[0] == "end")    { break;                                                       }
        else                          { fn::write("fail: invalid command");                          }
    }
}
