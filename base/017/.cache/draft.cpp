#include <iostream>
#include <vector>
#include <utility>
#include <aux.hpp>

enum Coin {M10, M25, M50, M100};

struct CoinDef {
    float value;
    int volume;
    std::string label;
};

CoinDef getDef(Coin coin) {
    switch (coin) {
        case M10 : return {0.10, 1, "M10" };
        case M25 : return {0.25, 2, "M25" };
        case M50 : return {0.50, 3, "M50" };
        case M100: return {1.00, 4, "M100"};
    }
    return {0, 0, ""};
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
    std::vector<std::string> itens;
    double value {0};
    int volume {0};
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

    double getCoins() {
        return {}; // todo
    }

    std::string getItems() {
        return {}; // todo
    }

    std::string str() const {
        std::stringstream ss;
        ss << aux::fmt(this->itens) << " : "
           << aux::fmt(value) << "$ : "
           << volume <<  "/" << volumeMax << " : " 
           <<  (broken ? "broken" : "unbroken");
        return ss.str();
    }
};

std::ostream& operator<<(std::ostream& os, const Pig& pig) {
    return os << pig.str();
}

int main() {
    aux::Chain chain;
    aux::Param par;

    Pig pig;
    
    auto toint = aux::to<int>;

    chain["addCoin"] = [&]() { 
        if      (par[1] == "10") pig.addCoin(M10);
        else if (par[1] == "25") pig.addCoin(M25);
        else if (par[1] == "50") pig.addCoin(M50);
        else if (par[1] == "100") pig.addCoin(M100);
    };
    chain["init"]     = [&]() { pig = Pig(toint(par[1])); };
    chain["addItem"]  = [&]() { pig.addItem(Item(par[1], toint(par[2]))); };
    chain["break"]    = [&]() { pig.breakPig(); };
    chain["getCoins"] = [&]() { aux::show << pig.getCoins(); };
    chain["getItems"] = [&]() { aux::show << pig.getItems(); };
    chain["show"]     = [&]() { aux::show << pig.str(); };

    aux::execute(chain, par);
}

