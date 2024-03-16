#include <memory>  //sharedptr
#include <iomanip> //setprecision
#include <utility> //exchange
#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp

class Lead {
    float thickness;
    std::string hardness;
    int size;

public:
    Lead(float thickness, std::string hardness, int size) {
    }
    int usagePerSheet() const {
        if (hardness == "HB")
            return 1;
        else if (hardness == "2B")
            return 2;
        else if (hardness == "4B")
            return 4;
        else
            return 6;
    }
    float getThickness() const {
    }

    std::string getHardness() const {
    }

    int getSize() const {
    }

    void setSize(int size) {
    }
    std::string str() const {
        return fn::format("{%.1f}:{}:{}", thickness, hardness, size);
    }
};

std::ostream& operator<<(std::ostream& ss, const Lead& gr) {
    return ss << gr.str();
}

struct Pencil {
    float thickness {0.f};
    std::shared_ptr<Lead> tip {nullptr};

    Pencil(float thickness = 0.0): thickness{thickness} {
    }

    bool hasLead() const {
    }

    bool insert(std::shared_ptr<Lead> grafite) {
    }

    std::shared_ptr<Lead> remove() {
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

int main() {
    Pencil pencil;

    while (true) {
        auto line = fn::input();
        auto args = fn::split(line);
        fn::write("$" + line);

        if      (args[0] == "show"  ) { fn::write(pencil);                                                        }
        else if (args[0] == "init"  ) { pencil = Pencil(+args[1]);                                                }
        else if (args[0] == "insert") { pencil.insert(std::make_shared<Lead>(+args[1], args[2], (int) +args[3])); }
        else if (args[0] == "remove") { pencil.remove();                                                          }
        else if (args[0] == "write" ) { pencil.writePage();                                                       }
        else if (args[0] == "end"   ) { break;                                                                    }
        else                          { fn::write("fail: comando invalido");                                      }
    }
}
