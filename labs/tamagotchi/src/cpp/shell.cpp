#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// @DROP
class Pet {
private:
    int energyMax;
    int cleanMax;

    int energy;
    int clean;

    int age;
    bool alive;

public:
    Pet(int energy = 0, int clean = 0) {
        this->energyMax = energy;
        this->cleanMax = clean;

        this->energy = energy;
        this->clean = clean;

        this->age = 0;
        this->alive = true;
    }

    void setEnergy(int value) {
        if (value <= 0) {
            this->alive = false;
            this->energy = 0;
            cout << "fail: pet morreu de fraqueza" << endl;
            return;
        }
        if (value > this->energyMax) {
            this->energy = this->energyMax;
            return;
        }
        this->energy = value;
    }

    void setClean(int value) {
        if (value <= 0) {
            this->alive = false;
            this->clean = 0;
            cout << "fail: pet morreu de sujeira" << endl;
            return;
        }
        if (value > this->cleanMax) {
            this->clean = this->cleanMax;
            return;
        }
        this->clean = value;
    }

    void setAge(int value) {
        this->age = value;
    }

    string str() const {
        stringstream ss;
        ss << "E:" << this->energy << "/" << this->energyMax << ", ";
        ss << "L:" << this->clean << "/" << this->cleanMax << ", ";
        ss << "I:" << this->age;
        return ss.str();
    }

    int getClean() const {
        return this->clean;
    }

    int getEnergy() const {
        return this->energy;
    }

    int getCleanMax() const {
        return this->cleanMax;
    }

    int getEnergyMax() const {
        return this->energyMax;
    }

    int getAge() const {
        return this->age;
    }

    bool isAlive() const {
        return this->alive;
    }
};

class Game {
private:
    Pet pet;

    bool testAlive() const {
        if (!this->pet.isAlive()) {
            cout << "fail: pet esta morto" << endl;
            return false;
        }
        return true;
    }

public:
    Game(Pet pet = Pet()) {
        this->pet = pet;
    }

    void play() {
        if (!this->testAlive())
            return;
        this->pet.setEnergy(this->pet.getEnergy() - 2);
        this->pet.setClean(this->pet.getClean() - 3);
        this->pet.setAge(this->pet.getAge() + 1);
    }

    void shower() {
        if (!this->testAlive())
            return;
        this->pet.setEnergy(this->pet.getEnergy() - 3);
        this->pet.setClean(this->pet.getCleanMax());
        this->pet.setAge(this->pet.getAge() + 2);
    }

    void eat() {
        if (!this->testAlive())
            return;
        this->pet.setEnergy(this->pet.getEnergy() - 1);
        this->pet.setClean(this->pet.getClean() - 2);
        this->pet.setAge(this->pet.getAge() + 1);
    }

    void sleep() {
        if (!this->testAlive())
            return;
        if (this->pet.getEnergyMax() - this->pet.getEnergy() < 5) {
            cout << "fail: nao esta com sono" << endl;
            return;
        }
        this->pet.setAge(this->pet.getAge() + (this->pet.getEnergyMax() - this->pet.getEnergy()));
        this->pet.setEnergy(this->pet.getEnergyMax());
    }

    string str() const {
        return this->pet.str();
    }
};

// @KEEP
int main() {
    // @DROP
    Game game;
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
        else if (cmd == "init") {
            // CRIE UM NOVO JOGO COM UM NOVO PET
            int energy, clean;
            ss >> energy >> clean;
            // @DROP
            game = Game(Pet(energy, clean));
        }
        else if (cmd == "show") { 
            // @DROP
            cout << game.str() << endl;
        } 
        else if (cmd == "play") { 
            // @DROP
            game.play();
        } 
        else if (cmd == "shower") { 
            // @DROP
            game.shower();
        } 
        else if (cmd == "eat") { 
            // @DROP
            game.eat();
        } 
        else if (cmd == "sleep") { 
            // @DROP
            game.sleep();
        } 
        // @KEEP
        else {
            cout << "fail: comando invalido" << endl;
        }
    }
    return 0;
}
