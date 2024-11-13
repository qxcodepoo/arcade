#pragma once
#include <iostream>
#include <string>
class Student {
private:
    // Pencil pencil;
public:
    Student(double thickness) {
        (void) thickness;
    };
    
    void insert(double thickness, std::string hardness, int length) {
        (void) thickness;
        (void) hardness;
        (void) length;
        // pencil.insert(std::make_shared<Lead>(thickness, hardness, length));
    }

    void remove() {
        // pencil.remove();
    }

    void writePage() {
        // pencil.writePage();
    }

    void show() {
        // fn::write(pencil.str());
    }
};