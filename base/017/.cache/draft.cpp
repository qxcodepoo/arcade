#include <fn.hpp>
#include <utility>

class Coin {
    std::string label;
    double value;
    int volume;

    Coin(std::string label, double value, int volume) :
        label(label), value(value), volume(volume) {
    }
public:
    const static Coin C10;
    const static Coin C25;
    const static Coin C50;
    const static Coin C100;

    double getValue() const { 
        return value; 
    }
    int getVolume() const { 
        return volume; 
    }
    std::string getLabel() const { 
        return label; 
    }

    std::string str() const {
        return fn::format("{%.2f}:{}", value, volume);
    }
};

const Coin Coin::C10  { "C10", 0.10, 1};
const Coin Coin::C25  { "C25", 0.25, 2};
const Coin Coin::C50  { "C50", 0.50, 3};
const Coin Coin::C100 {"C100", 1.00, 4};

std::ostream& operator<<(std::ostream& os, const Coin& coin) {
    return os << coin.str();
}

class Item {
    std::string label;
    int volume;
public:
    Item(std::string label, int volume) { //todo
    }
    int getVolume() const {
        return {}; // todo
    }
    std::string getLabel() const {
        return {}; // todo
    }
    void setVolume(int volume) {
    }
    void setLabel(std::string label) {
    }
    std::string str() const {
        return {}; // todo
    }
};

std::ostream& operator<<(std::ostream& os, const Item& item) {
    return os << item.str();
}

class Pig {
    std::vector<Item> itens;
    std::vector<Coin> coins;

    int volumeMax {0};
    bool broken {false};

public:
    Pig(int volumeMax = 0) { //todo
    }
    
    bool addCoin(Coin coin) {
        return {}; // todo
    }

    bool addItem(Item item) {
        return {}; // todo

    }

    bool breakPig() {
        return {}; // todo
    }

    std::vector<Coin> extractCoins() {
        return {}; // todo
    }

    std::vector<Item> extractItems() {
        return {}; // todo
    }

    double getValue() const {
        return {}; // todo
    }

    int getVolume() const {
        return {}; // todo
    }

    std::string str() const {
        return {}; // todo
    }
};

std::ostream& operator<<(std::ostream& os, const Pig& pig) {
        return {}; // todo
    return os << pig.str();
}


int main() {

    Pig pig;
    while (true) {
        auto line = fn::input();
        fn::write("$" + line);
        auto args = fn::split(line);

        if      (args[0] == "end"    ) { break; }
        else if (args[0] == "addCoin") { 
            if      (args[1] == "10" ) pig.addCoin(Coin::C10);
            else if (args[1] == "25" ) pig.addCoin(Coin::C25);
            else if (args[1] == "50" ) pig.addCoin(Coin::C50);
            else if (args[1] == "100") pig.addCoin(Coin::C100);
        }
        else if (args[0] == "init"        ) { pig = Pig( (int) +(args[1]));                 }
        else if (args[0] == "addItem"     ) { pig.addItem(Item(args[1], (int) +(args[2]))); }
        else if (args[0] == "break"       ) { pig.breakPig();                               }
        else if (args[0] == "extractCoins") { fn::write(pig.extractCoins());                }
        else if (args[0] == "extractItems") { fn::write(pig.extractItems());                }
        else if (args[0] == "show"        ) { fn::write(pig);                               }
        else                                { fn::write("fail: invalid command");           }
    }
}
