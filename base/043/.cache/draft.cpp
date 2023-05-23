#include <fn.hpp>

class Valuable {
public:
    virtual std::string getLabel()  const = 0;
    virtual double      getValue()  const = 0;
    virtual int         getVolume() const = 0;
    virtual std::string str()       const = 0;
    virtual ~Valuable() {}
};

std::ostream& operator<<(std::ostream& os, const Valuable& valuable) {
    return os << valuable.str();
}

class Coin : public Valuable {
    Coin(const std::string& label, double value, int volume) : label(label), value(value), volume(volume) {}
public:

    static const Coin C10;
    static const Coin C25;
    static const Coin C50;
    static const Coin C100;

    std::string getLabel() const override {
        return label;
    }

    int getVolume() const override {
        return volume;
    }

    double getValue() const override {
        return value;
    }

    std::string str() const override {
        return fn::format("{}:{%.2f}:{}", label, value, volume);
    }

private:
    std::string label;
    double value;
    int volume;
};

const Coin Coin::C10  { "M10", 0.10, 1};
const Coin Coin::C25  { "M25", 0.25, 2};
const Coin Coin::C50  { "M50", 0.50, 3};
const Coin Coin::C100 {"M100", 1.00, 4};


class Item : public Valuable {
public:
    Item(const std::string& label, double value, int volume) { //todo
    }

    std::string getLabel() const override {
    }

    int getVolume() const override {
    }

    double getValue() const override {
    }

    std::string str() const {
        return {}; // todo
    }

private:
    std::string label;
    double value;
    int volume;
};

class Pig {
    int volumeMax;
    bool broken;
    std::vector<std::shared_ptr<Valuable>> valuables;
public:
    Pig(int volumeMax) { //todo 
    }


    void addValuable(const std::shared_ptr<Valuable>& val) {
    }

    void breakPig() {
    }

    std::vector<std::shared_ptr<Coin>> extractCoins() {
        return {}; // todo
    }

    std::vector<std::shared_ptr<Item>> extractItems() {
        return {}; // todo
    }

    int getVolume() const {
        return {}; // todo
    }

    double getValue() const {
        return {}; // todo
    }

    std::string str() const{
    }
};


std::ostream& operator<<(std::ostream& os, const Pig& pig) {
    return os << pig.str();
}

int main() {
    Pig pig(0);
    while (true) {
        try {
            auto line = fn::input();
            auto args = fn::split(line, ' ');
            fn::write("$" + line);

            if      (args[0] == "end" ) { break; } 
            else if (args[0] == "init") { pig = Pig(+args[1]); }
            else if (args[0] == "addCoin") {
                switch((int) +args[1]) {
                    case  10: pig.addValuable(std::make_shared<Coin>(Coin::C10 )); break;
                    case  25: pig.addValuable(std::make_shared<Coin>(Coin::C25 )); break;
                    case  50: pig.addValuable(std::make_shared<Coin>(Coin::C50 )); break;
                    case 100: pig.addValuable(std::make_shared<Coin>(Coin::C100)); break;
                }
            }
            else if (args[0] == "addItem") {
                pig.addValuable(std::make_shared<Item>(args[1], +args[2], (int) +args[3]));
            }
            else if (args[0] == "break"       ) { pig.breakPig();                               }
            else if (args[0] == "extractCoins") { fn::write(pig.extractCoins());                }
            else if (args[0] == "extractItems") { fn::write(pig.extractItems());                }
            else if (args[0] == "show"        ) { fn::write(pig);                               }
            else                                { fn::write("fail: invalid command");           }
        } catch (std::string s) {
            fn::write(s);
        }
    }

}


