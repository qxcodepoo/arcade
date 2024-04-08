#pragma once
#include <iostream>

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
