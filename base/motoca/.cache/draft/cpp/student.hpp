#pragma once
#include <iostream>
class Student {
    // Motorcycle motorcycle;
public:

    Student(int power = 1) {
         (void) power;
    }

    void enter(std::string name, int age) {
        // auto person = std::make_shared<Person>(name, age);
        // motorcycle.insertPerson(person);
        (void) name;
        (void) age;
    }

    void leave() {
        // auto person = motorcycle.remove();
        // fn::write(person == nullptr ? "---" : person->str());
    }

    void honk() const {
        // fn::write(motorcycle.honk());
    }

    void buy(int time) {
        // motorcycle.buyTime(time);
        (void) time;
    }

    void drive(int time) {
        // motorcycle.drive(time);
        (void) time;
    }

    void show() const {
        // fn::write(motorcycle.str());
    }
};