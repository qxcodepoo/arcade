#include <iostream>
#include <vector>
#include <sstream>
#include <utility>
#include <iomanip>
#include <memory>
using namespace std;

template <typename CONTAINER, typename FN>
string map_join(const CONTAINER& container, FN fn, string sep = ", ", string prefix = "[", string suffix = "]") {
    stringstream ss;
    for (auto it = container.begin(); it != container.end(); ++it) {
        ss << (it != container.begin() ? sep : "") << fn(*it);
    }
    return prefix + ss.str() + suffix;
}

// @DROP
class Coin {
    string label;
    double value;
    int volume;

    Coin(string label, double value, int volume) :
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
    string getLabel() const { 
        return label; 
    }

    string str() const {
        stringstream ss;
        ss << fixed << setprecision(2) << value << ":" << volume;
        return ss.str();
    }
};

const Coin Coin::C10  { "C10", 0.10, 1};
const Coin Coin::C25  { "C25", 0.25, 2};
const Coin Coin::C50  { "C50", 0.50, 3};
const Coin Coin::C100 {"C100", 1.00, 4};

class Item {
    string label;
    int volume;
public:
    Item(string label, int volume) :
        label(label), volume(volume) {
    }
    int getVolume() const {
        return volume;
    }
    string getLabel() const {
        return label;
    }
    void setVolume(int volume) {
        this->volume = volume;
    }
    void setLabel(string label) {
        this->label = label;
    }
    string str() const {
        stringstream ss;
        ss << label << ":" << volume;
        return ss.str();
    }
};

class Pig {
    vector<Item> itens;
    vector<Coin> coins;

    int volumeMax {0};
    bool broken {false};

public:
    Pig(int volumeMax = 0) :
        volumeMax(volumeMax) {
    }
    
    bool addCoin(Coin coin) {
        if (this->broken) {
            cout << "fail: the pig is broken\n";
            return false;
        }
        if (this->getVolume() + coin.getVolume() > this->volumeMax) {
            cout << "fail: the pig is full\n";
            return false;
        }
        this->coins.push_back(coin);
        return true;
    }

    bool addItem(Item item) {
        if (this->broken) {
            cout << "fail: the pig is broken\n";
            return false;
        }
        if (item.getVolume() + this->getVolume() > this->volumeMax) {
            cout << "fail: the pig is full\n";
            return false;
        }
        this->itens.push_back(item);

        return true;
    }

    bool breakPig() {
        if (broken) {
            cout << "fail: the pig is already broken\n";
            return false;
        }
        this->broken = true;
        return true;
    }

    vector<Coin> extractCoins() {
        if (!broken) {
            cout << "fail: you must break the pig first\n";
            return {};
        }
        return exchange(this->coins, {});
    }

    vector<Item> extractItems() {
        if (!broken) {
            cout << "fail: you must break the pig first\n";
            return {};
        }
        return exchange(this->itens, {});
    }

    double getValue() const {
        double value = 0;
        for (auto coin : this->coins) {
            value += coin.getValue();
        }
        return value;
    }

    int getVolume() const {
        if (this->broken) {
            return 0;
        }
        int volume = 0;
        for (auto coin : this->coins) {
            volume += coin.getVolume();
        }
        for (auto item : this->itens) {
            volume += item.getVolume();
        }
        return volume;
    }

    string str() const {
        stringstream ss;
        ss << "state=" << (this->broken ? "broken" : "intact") << " : coins=";
        ss << map_join(this->coins, [](const Coin& coin) { return coin.str(); });
        ss << " : items=";
        ss << map_join(this->itens, [](const Item& item) { return item.str(); });
        ss << " : value=" << fixed << setprecision(2) << getValue() << " : volume=" << getVolume() << "/" << volumeMax;
        return ss.str();
    }
};

// @KEEP
int main() {
    // @DROP
    Pig pig;
    // @KEEP
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "init") {
            // @COM
            int volumeMax;
            ss >> volumeMax;
            // @DROP
            pig = Pig(volumeMax);
        } else if (cmd == "show") {
            // @DROP
            cout << pig.str() << endl;
        } else if (cmd == "break") {
            // @DROP
            pig.breakPig();
        } else if (cmd == "addCoin") {
            // @COM
            string label;
            ss >> label;
            // @DROP
            if (label == "10") {
                pig.addCoin(Coin::C10);
            } else if (label == "25") {
                pig.addCoin(Coin::C25);
            } else if (label == "50") {
                pig.addCoin(Coin::C50);
            } else if (label == "100") {
                pig.addCoin(Coin::C100);
            } else {
                cout << "fail: invalid coin\n";
            }
        } else if (cmd == "addItem") {
            // @COM
            string label;
            int volume;
            ss >> label >> volume;
            // @DROP
            pig.addItem(Item(label, volume));
        } else if (cmd == "extractItems") {
            // Obtenha os itens com o método extractItems
            // e imprima os itens obtidos
            // @DROP
            auto items = pig.extractItems();
            cout << map_join(items, [](const Item& item) { return item.str(); }) << endl;
        } else if (cmd == "extractCoins") {
            // Obtenha as moedas com o método extractCoins
            // e imprima as moedas obtidas
            // @DROP
            auto coins = pig.extractCoins();
            cout << map_join(coins, [](const Coin& coin) { return coin.str(); }) << endl;
        } else {
            cout << "fail: invalid command\n";
        }
    }
}
