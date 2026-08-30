#include <iostream>
#include <sstream>
#include <memory>
#include <utility>
using namespace std;

// @DROP

class Bateria {
private:
    int capacity;
    int charge;

public:
    Bateria(int capacity) : capacity(capacity), charge(capacity) {}

    int getCapacity() const { return capacity; }
    int getCharge() const { return charge; }
    void setCharge(int value) {
        if (value <= 0) {
            this->charge = 0;
        } else if (value >= capacity) {
            this->charge = capacity;
        } else {
            this->charge = value;
        }
    }

    string str() const {
        stringstream ss;
        ss << charge << "/" << capacity;
        return ss.str();
    }
};

class Charger {
private:
    int power;

public:
    Charger(int potencia) : power(potencia) {}

    int getPower() const { return power; }

    string str() const {
        stringstream ss;
        ss << power << "W";
        return ss.str();
    }
};

class Notebook {
private:
    bool in_use {false};
    int usage {0};
    shared_ptr<Bateria> battery = nullptr;
    shared_ptr<Charger> charger = nullptr;

public:
    string str() const {
        stringstream ss;
        ss << "Notebook: ";
        
        if (!this->in_use) {
            ss << "desligado";
        } else {
            ss << "ligado por " << usage << " min";
        }
        
        if (this->charger) {
            ss << ", Carregador " << this->charger->str();
        }
        if (this->battery) {
            ss <<  ", Bateria " << battery->str();
        }
        return ss.str();
    }

    void turn_on() {
        if (charger || (battery && battery->getCharge() > 0)) {
            in_use = true;
        } else {
            cout << "fail: não foi possível ligar\n";
        }
    }

    void turn_off() {
        this->in_use = false;
        this->usage = 0;
    }

    void use(int minutes) {
        if (!in_use) {
            cout << "fail: desligado\n";
            return;
        }
        if (charger != nullptr and battery == nullptr) {
            this->usage += minutes;
            return;
        }
        if (charger == nullptr and battery != nullptr) {
            if (battery->getCharge() > minutes) {
                battery->setCharge(battery->getCharge() - minutes);
                this->usage += minutes;
            } else {
                battery->setCharge(battery->getCharge() - minutes);
                in_use = false;
                cout << "fail: descarregou\n";
            }
            return;
        }
        if (charger != nullptr and battery != nullptr) {
            usage += minutes;
            battery->setCharge(battery->getCharge() + charger->getPower() * minutes);
            return;
        }
    }

    void setBattery(shared_ptr<Bateria> newBattery) {
        battery = newBattery;
    }

    shared_ptr<Bateria> rmBattery() {
        if (battery) {
            if (charger == nullptr and in_use) {
                in_use = false;
            }
            auto removed = battery;
            this->battery = nullptr;
            return removed;
        }
        return nullptr;
    }

    void setCharger(shared_ptr<Charger> newCharger) {
        if (charger != nullptr) {
            cout << "fail: carregador já conectado\n";
            return;
        }
        charger = newCharger;
    }
    shared_ptr<Charger> rmCharger() {
        if (charger != nullptr) {
            if (battery == nullptr or battery->getCharge() == 0) {
                in_use = false;
            }
            return exchange(charger, nullptr);
        }
        return nullptr;
    }
};

// @KEEP
int main() {
    // @DROP
    auto adp = Notebook();
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
            cout << adp.str() << endl;
        } 
        else if (cmd == "turn_on") { 
            // @DROP
            adp.turn_on();
        }
        else if (cmd == "turn_off") { 
            // @DROP
            adp.turn_off();
        } 
        else if (cmd == "use") { 
            int minutes;
            ss >> minutes;
            // @DROP
            adp.use(minutes);
        } 
        else if (cmd == "set_charger") {
            // CRIE UM OBJETO Charger E ATRIBUA AO NOTEBOOK
            int power;
            ss >> power;
            // @DROP
            adp.setCharger(make_shared<Charger>(power));
        } 
        else if (cmd == "rm_charger") {
            // REMOVA O CARREGADOR DO NOTEBOOK E IMPRIMA SE ELE EXISTIR
            // @DROP
            auto charger = adp.rmCharger();
            if (charger) {
                cout << "Removido " << charger->str() << endl;
            } else {
                cout << "fail: Sem carregador\n";
            }
        } 
        else if (cmd == "set_battery") {
            // CRIE UM OBJETO Bateria E ATRIBUA AO NOTEBOOK
            int capacity;
            ss >> capacity;
            // @DROP
            adp.setBattery(make_shared<Bateria>(capacity));
        } 
        else if (cmd == "rm_battery") {
            // REMOVA A BATERIA DO NOTEBOOK E IMPRIMA SE ELA EXISTIR
            // @DROP
            auto battery = adp.rmBattery();
            if (battery) {
                cout << "Removido " << battery->str() << endl;
            } else {
                cout << "fail: Sem bateria\n";
            }
        } 
        // @KEEP
        else {
            cout << "fail: comando inválido\n";
        }
    }    
}
