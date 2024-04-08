#pragma once
#include <iostream>
#include "fn.hpp"

class Lead {
    float thickness;
    std::string hardness;
    int size;

public:
    Lead(float thickness, std::string hardness, int size) {
        (void) thickness;
        (void) hardness;
        (void) size;
    }
    int usagePerSheet() const {
        return 0;
        
    }
    float getThickness() const {
        return 0;
    }

    std::string getHardness() const {
        return "";
    }

    int getSize() const {
        return 0;
    }

    void setSize(int size) {
        (void) size;
    }

    std::string str() const {
        return fn::format("{%.1f}:{}:{}", thickness, hardness, size);
    }
};

std::ostream& operator<<(std::ostream& ss, const Lead& gr) {
    return ss << gr.str();
}