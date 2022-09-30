#include <iostream>
#include <sstream>
#include <memory>
#include <aux.hpp>

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
        std::ostringstream oss;
        oss << name << ":" << age;
        return oss.str();
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

    std::shared_ptr<Person> removePerson() {
        return {}; // todo
    }

    void buyTime(int time) {
    }

    void drive(int time) {
    }

    std::string str() const{
        std::ostringstream os;
        os << "power:" << power << ", time:" << time;
        os << ", person:(" << (person == nullptr ? "empty" : person->str()) << ")";
        return os.str();
    }
};

std::ostream& operator<<(std::ostream& os, const Motorcycle& m) {
    return os << m.str();
}


int main() {
    aux::Chain chain;
    aux::Param param;

    Motorcycle m(1);


    auto __int = [&](int index) { return aux::to<int>(param[index]); };

    chain["show"]  = [&]() { aux::show << m; };
    chain["leave"] = [&]() { 
        auto person = m.removePerson(); 
        if (person != nullptr) {
            aux::show << *person;
        }
    };
    chain["honk"]  = [&]() { aux::show << m.honk(); };
    chain["init"]  = [&]() { m = Motorcycle(__int(1));};
    chain["enter"] = [&]() { m.insertPerson(std::make_shared<Person>(param[1], __int(2))); };
    chain["buy"]   = [&]() { m.buyTime(__int(1)); };
    chain["drive"] = [&]() { m.drive  (__int(1)); };

    aux::execute(chain, param);
}
