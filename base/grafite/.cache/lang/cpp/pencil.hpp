#pragma once
#include "lead.hpp"
#include "fn.hpp"
#include <utility> //exchange

struct Pencil {
    float thickness {0.f};
    std::shared_ptr<Lead> tip {nullptr};

    Pencil(float thickness = 0.0)
    {
        (void) thickness;
    }
    bool hasLead() const {
        return false;
    }

    bool insert(std::shared_ptr<Lead> grafite) {
        (void) grafite;
        return false;
    }

    std::shared_ptr<Lead> remove() {
        return nullptr;
    }

    void writePage() {
    }

    std::string str() const {
        auto grafite = tip != nullptr ? "[" + tip->str() + "]" : "null";
        return fn::format("calibre: {%.1f}, grafite: {}", thickness, grafite);
    }
};

std::ostream& operator<<(std::ostream& os, const Pencil& l) {
    return os << l.str();
}