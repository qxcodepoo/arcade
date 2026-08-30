#include <iostream>
#include <memory>
#include <utility> //exchange
#include <sstream>
using namespace std;

// @DROP
class Lead {
    float thickness;
    string hardness;
    int size;

public:
    Lead(float thickness, string hardness, int size) {
        this->thickness = thickness;
        this->hardness = hardness;
        this->size = size;
    }
    int usagePerSheet() const {
        if (hardness == "HB") {
            return 1;
        } else if (hardness == "2B") {
            return 2;
        } else if (hardness == "4B") {
            return 4;
        } else {
            return 6;
        }
    }
    float getThickness() const {
        return thickness;
    }

    string getHardness() const {
        return hardness;
    }

    int getSize() const {
        return size;
    }

    void setSize(int size) {
        this->size = size;
    }

    string str() const {
        char buffer[256];
        sprintf(buffer, "%.1f:%s:%d", thickness, hardness.c_str(), size);
        return buffer;
    }
};

struct Pencil {
    float thickness {0.f};
    shared_ptr<Lead> tip {nullptr};

    Pencil(float thickness = 0.0)
        : thickness{thickness} {
    }
    bool hasLead() const {
        return tip != nullptr;
    }

    bool insert(shared_ptr<Lead> grafite) {
        if (this->tip != nullptr) {
            cout << "fail: ja existe grafite\n";
            return false;
        }
        if (this->thickness != grafite->getThickness()) {
            cout << "fail: calibre incompativel\n";
            return false;
        }
        this->tip = grafite;
        return true;
    }

    shared_ptr<Lead> remove() {
        if (this->tip == nullptr) {
            cout << "fail: nao existe grafite\n";
            return nullptr;
        }
        return exchange(this->tip, nullptr);
    }

    void writePage() {
        if (this->tip == nullptr) {
            cout << "fail: nao existe grafite\n";
            return;
        }
        if (this->tip->getSize() <= 10) {
            cout << "fail: tamanho insuficiente\n";
            return;
        }
        if (this->tip->getSize() - this->tip->usagePerSheet() < 10) {
            this->tip->setSize(10);
            cout << "fail: folha incompleta\n";
            return;
        }
        this->tip->setSize(this->tip->getSize() - this->tip->usagePerSheet());
    }

    string str() const {
        auto grafite = tip != nullptr ? "[" + tip->str() + "]" : "null";
        char buffer[256];
        sprintf(buffer, "calibre: %.1f, grafite: %s", thickness, grafite.c_str());
        return buffer;
    }
};


// @KEEP
int main() {
    Pencil pencil(0.7); // @DROP
    
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } 
        // @COM
        else if (cmd == "show") { 
            // @DROP
            cout << pencil.str() << endl;
        }
        else if (cmd == "init") { 
            float thickness;
            ss >> thickness;
            // @DROP
            pencil = Pencil(thickness);
        }
        else if (cmd == "insert") { 
            float thickness;
            string hardness;
            int size;
            ss >> thickness >> hardness >> size;
            // @DROP
            pencil.insert(make_shared<Lead>(thickness, hardness, size));
        }
        else if (cmd == "remove") { 
            // @DROP
            pencil.remove();
        }
        else if (cmd == "write") { 
            // @DROP
            pencil.writePage();
        }
        // @KEEP
        else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
