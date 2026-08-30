#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

template <typename CONTAINER, typename FUNC>
string map_join(const CONTAINER& container, FUNC func, const string& separator) {
    stringstream ss;
    for (auto it = container.begin(); it != container.end(); ++it) {
        ss << (it == container.begin() ? "" : separator);
        ss << func(*it);
    }
    return ss.str();
}

// @DROP
class Valuable {
public:
    virtual string getLabel()  const = 0;
    virtual double      getValue()  const = 0;
    virtual int         getVolume() const = 0;
    virtual string str()       const = 0;
    virtual ~Valuable() {}
};

ostream& operator<<(ostream& os, const Valuable& valuable) {
    return os << valuable.str();
}

class Coin : public Valuable {
    Coin(const string& label, double value, int volume) : label(label), value(value), volume(volume) {}
public:

    static const Coin C10;
    static const Coin C25;
    static const Coin C50;
    static const Coin C100;

    string getLabel() const override {
        return label;
    }

    int getVolume() const override {
        return volume;
    }

    double getValue() const override {
        return value;
    }

    string str() const override {
        char buffer[100];
        sprintf(buffer, "%s:%.2f:%d", label.c_str(), value, volume);
        return buffer;
    }

private:
    string label;
    double value;
    int volume;
};

const Coin Coin::C10  { "M10", 0.10, 1};
const Coin Coin::C25  { "M25", 0.25, 2};
const Coin Coin::C50  { "M50", 0.50, 3};
const Coin Coin::C100 {"M100", 1.00, 4};

class Item : public Valuable {
public:
    Item(const string& label, double value, int volume) :
        label(label), value(value), volume(volume) {
    }

    string getLabel() const override {
        return label;
    }

    int getVolume() const override {
        return volume;
    }

    double getValue() const override {
        return value;
    }

    string str() const {
        char buffer[100];
        sprintf(buffer, "%s:%.2f:%d", label.c_str(), value, volume);
        return buffer;
    }

private:
    string label;
    double value;
    int volume;
};

class Pig {
    int volumeMax;
    bool broken;
    vector<shared_ptr<Valuable>> valuables;
public:
    Pig(int volumeMax) : 
        volumeMax(volumeMax), broken(false) {
    }


    void addValuable(const shared_ptr<Valuable>& val) {
        if (broken) 
            throw "fail: the pig is broken"s;
        if (val->getVolume() + getVolume() > volumeMax)
            throw "fail: the pig is full"s;
        valuables.push_back(val);
    }

    void breakPig() {
        if (broken) {
            throw "fail: the pig is already broken"s;
        }
        broken = true;
    }

    vector<shared_ptr<Coin>> extractCoins() {
        if (!broken) {
            throw "fail: you must break the pig first"s;
        }
        vector<shared_ptr<Coin>> coins;
        vector<shared_ptr<Valuable>> left;
        for (const auto& val : valuables) {
            auto coin = dynamic_pointer_cast<Coin>(val);
            if (coin) {
                coins.push_back(coin);
            } else {
                left.push_back(val);
            }
        }
        valuables = left;
        return coins;
    }

    vector<shared_ptr<Item>> extractItems() {
        if (!broken) {
            throw "fail: you must break the pig first"s;
        }
        vector<shared_ptr<Item>> items;
        vector<shared_ptr<Valuable>> left;
        for (const auto& val : valuables) {
            auto item = dynamic_pointer_cast<Item>(val);
            if (item) {
                items.push_back(item);
            } else {
                left.push_back(val);
            }
        }
        valuables = left;
        return items;
    }

    int getVolume() const {
        if (broken)
            return 0;
        int volume = 0;
        for (const auto& val : valuables) {
            volume += val->getVolume();
        }
        return volume;
    }

    double getValue() const {
        double value = 0.0;
        for (const auto& val : valuables) {
            value += val->getValue();
        }
        return value;
    }

    string str() const{
        auto valuables = map_join(this->valuables, [](const auto& x) { return x->str(); }, ", ");
        stringstream ss;
        ss << "[" << valuables << "] : " << fixed << setprecision(2) << getValue() << "$ : " << getVolume() << "/" << volumeMax << " : " << (broken ? "broken" : "intact");
        return ss.str();
    }
};

// @KEEP

int main() {
    // @DROP
    Pig pig(0);
    // @KEEP
    while (true) {
        try {
            string line, cmd;
            getline(cin, line);
            cout << '$' << line << endl;

            stringstream ss(line);
            ss >> cmd;

            if (cmd == "end" ) {
                break;
            }
            else if (cmd == "init") {
                // @COM
                int volumeMax;
                ss >> volumeMax;
                // @DROP
                pig = Pig(volumeMax);
            }
            else if (cmd == "addCoin") {
                // @COM
                int value;
                ss >> value;
                // @DROP
                switch(value) {
                    case  10: pig.addValuable(make_shared<Coin>(Coin::C10 )); break;
                    case  25: pig.addValuable(make_shared<Coin>(Coin::C25 )); break;
                    case  50: pig.addValuable(make_shared<Coin>(Coin::C50 )); break;
                    case 100: pig.addValuable(make_shared<Coin>(Coin::C100)); break;
                }
            }
            else if (cmd == "addItem") {
                // @COM
                string label;
                double value;
                int volume;
                ss >> label >> value >> volume;
                // @DROP
                pig.addValuable(make_shared<Item>(label, value, volume));
            }
            else if (cmd == "break") {
                // @DROP
                pig.breakPig();                              
            }
            else if (cmd == "extractCoins") {
                // @DROP
                auto result = map_join(pig.extractCoins(), [](const auto& x) { return x->str(); }, ", ");
                cout << "[" << result << "]" << endl;
            }
            else if (cmd == "extractItems") { 
                // @DROP
                auto result = map_join(pig.extractItems(), [](const auto& x) { return x->str(); }, ", ");
                cout << "[" << result << "]" << endl;
            }
            else if (cmd == "show") { 
                // @DROP
                cout << pig.str() << endl;
            }
            else { 
                cout << "fail: invalid command" << endl;
            }
        } catch (string s) {
            cout << s << endl;
        }
    }

}
