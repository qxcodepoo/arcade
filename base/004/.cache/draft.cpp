#include <iostream>
#include <sstream>
#include <memory>  //sharedptr
#include <iomanip> //setprecision
#include <utility> //exchange
#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

class Lead {
    float thickness;
    std::string hardness;
    int size;

public:
    Lead(float thickness, std::string hardness, int size) { return {}; }

    int usagePerSheet() const { return {}; }

    float getThickness() const { return {}; }

    std::string getHardness() const { return {}; }

    int getSize() const { return {}; }

    void setSize(int size) { return {}; }
    std::string str() const {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1) 
           << thickness << ":" << hardness << ":" << size;
        return ss.str();
    }
};

std::ostream& operator<<(std::ostream& ss, Lead gr) {
    return ss << gr.str();
}

struct Pencil {
    float thickness {0.f};
    std::shared_ptr<Lead> tip {nullptr};

    Pencil(float thickness = 0.0): thickness{thickness} { return {}; }

    bool hasGrafite() { return {}; }

    bool insert(std::shared_ptr<Lead> grafite) { return {}; }

    std::shared_ptr<Lead> remove() { return {}; }

    void writePage() { return {}; }

    std::string str() {
        std::stringstream ss;
        ss << "calibre: " << thickness << ", grafite: ";
        if (tip != nullptr)
            ss << "[" << *tip << "]";
        else
            ss << "null";
        return ss.str();
    }
};

std::ostream& operator<<(std::ostream& os, Pencil l) {
    return os << l.str();
}

using namespace fn;

int main() {
    Pencil pencil;

    while (true) {
        auto line = input();
        write("$" + line);
        auto args = split(line);

        if      (args[0] == "end"   ) { break;                                                                                  }
        else if (args[0] == "show"  ) { write(pencil);                                                                    }
        else if (args[0] == "init"  ) { pencil = Pencil(number(args[1]));                                                       }
        else if (args[0] == "insert") { pencil.insert(std::make_shared<Lead>(number(args[1]), args[2], (int) number(args[3]))); }
        else if (args[0] == "remove") { pencil.remove();                                                                        }
        else if (args[0] == "write" ) { pencil.writePage();                                                                     }
    }
}
