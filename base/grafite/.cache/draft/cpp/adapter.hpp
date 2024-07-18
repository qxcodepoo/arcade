#pragma once
#include <iostream>
#include <string>
class Adapter {
public:
    Adapter(double thickness) {
        (void) thickness;
    };
    void insert(double thickness, std::string hardness, int length) {
        (void) thickness;
        (void) hardness;
        (void) length;
    }

    void remove() {
    }

    void writePage() {
    }

    std::string str() {
        return "";
    }
};
