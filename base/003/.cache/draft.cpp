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


int main() {
    aux::Chain chain;
    aux::Param param;

    Motorcycle m(1);

    auto INT = aux::to<int>;

    chain["show"]  = [&]() { m | aux::PRINT(); };
    chain["leave"] = [&]() { 
        auto person = m.remove(); 
        if (person != nullptr) {
            *person | aux::PRINT();
        }
    };
    chain["honk"]  = [&]() { m.honk()  | aux::PRINT(); };
    chain["init"]  = [&]() { m = Motorcycle(INT(param.at(1)));};
    chain["enter"] = [&]() { m.insertPerson(std::make_shared<Person>(param.at(1), INT(param.at(2)))); };
    chain["buy"]   = [&]() { m.buyTime(INT(param.at(1))); };
    chain["drive"] = [&]() { m.drive  (INT(param.at(1))); };

    aux::execute(chain, param);
}
