#pragma once
#include <iostream>
class Student {
    // Motorcycle motorcycle;
public:

    void init(int power = 1) {
        (void) power;
        // motorcycle = Motorcycle(power);
    }

    void enter(std::string name, int age) {
        (void) name;
        (void) age;
        // auto person = std::make_shared<Person>(name, age);
        // motorcycle.insertPerson(person);
    }

    void leave() {
        // auto person = motorcycle.remove();
        // fn::write(person == nullptr ? "---" : person->str());
    }

    void honk() const {
        // fn::write(motorcycle.honk());
    }

    void buy(int time) {
        (void) time;
        // motorcycle.buyTime(time);
    }

    void drive(int time) {
        (void) time;
        // motorcycle.drive(time);
    }

    void show() const {
        // fn::write(motorcycle.str());
    }
};