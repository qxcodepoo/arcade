#include <iostream>
#include <sstream>
#include <memory>
using namespace std;

// @DROP
#include <memory>
#include <utility>
class Person {
    string name;
    int money;
public:
    Person(string name = "", int money = 0): name(name), money(money) {}
    
    string str() {
        return name + ":" + to_string(money);
    }

    string getName() {
        return this->name;
    }
    void setMoney(int money) {
        this->money = money;
    }
    int getMoney() {
        return this->money;
    }
};

class Uber {
    shared_ptr<Person> driver;
    shared_ptr<Person> pass;
    int runCost;
public:
    Uber(): driver{nullptr}, pass{nullptr} {
        runCost = 0;
    }
    void setDriver(shared_ptr<Person> driver) {
        if (this->driver != nullptr) {
            cout << "fail: Driver is already set\n";
            return;
        }
        this->driver = driver;
    }
    void setPass(shared_ptr<Person> pass) {
        if (this->driver == nullptr) {
            cout << "fail: Driver is not set\n";
            return;
        }
        this->pass = pass;
        this->runCost = 0;
    }
    void drive(int distance) {
        if (this->driver == nullptr) {
            cout << "fail: Driver is not set\n";
            return;
        }
        if (this->pass != nullptr) {
            this->runCost += distance;
        }
    }

    shared_ptr<Person> leave() {
        if (this->driver == nullptr) {
            cout << "fail: Driver is not set\n";
            return nullptr;
        }
        if (this->pass == nullptr) {
            cout << "fail: Passenger is not set\n";
            return nullptr;
        }
        if (this->pass->getMoney() < this->runCost) {
            this->pass->setMoney(0);
            cout << "fail: Passenger does not have enough money\n";
        } else {
            this->pass->setMoney(this->pass->getMoney() - this->runCost);
        }
        this->driver->setMoney(this->driver->getMoney() + this->runCost);
        this->runCost = 0;
        return exchange(this->pass, nullptr);
    }
    string str() {
        auto driver = this->driver == nullptr ? "None" : this->driver->str();
        auto pass = this->pass == nullptr ? "None" : this->pass->str();
        stringstream ss;
        ss << "Cost: " << this->runCost << ", Driver: " << driver << ", Passenger: " << pass;
        return ss.str();
    }
};

// @KEEP

int main() {
    // @DROP
    Uber moto;
    // @KEEP

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
            cout << moto.str() << endl;
        }
        else if (cmd == "setDriver") { 
            string name;
            int money;
            ss >> name >> money;
            // @DROP
            moto.setDriver(make_shared<Person>(name, money));
        }
        else if (cmd == "setPass") { 
            string name;
            int money;
            ss >> name >> money;
            // @DROP
            moto.setPass(make_shared<Person>(name, money));
        }
        else if (cmd == "drive") { 
            int distance;
            ss >> distance;
            // @DROP
            moto.drive(distance);
        }
        else if (cmd == "leavePass") { 
            // @DROP
            auto pass = moto.leave();
            if (pass != nullptr) {
                cout << pass->str() << " left\n";
            }
        }
        // @KEEP
        else {
            cout << "fail: command not found\n";
        }
    }
}