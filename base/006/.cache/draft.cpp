#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <aux.hpp>


class Pet{
private:
    int energyMax, hungryMax, cleanMax;
    int energy, hungry, clean;
    int diamonds;
    int age;
    bool alive;

    bool testAlive() {
        if (alive)
            return true;
        std::cout << "fail: pet esta morto" << '\n';
        return false;
    }

    void setHungry(int value) {
        if (value <= 0) {
            hungry = 0;
            std::cout << "fail: pet morreu de fome" << '\n';
            alive = false;
        } else if (value > hungryMax) {
            hungry = hungryMax;
        } else {
            hungry = value;
        }
    }
    void setEnergy(int value) {
    }

    void setClean(int value) {
    }


public:
    Pet(int energy = 0, int hungry = 0, int clean = 0) { //todo
    }

    void play() {
        if (!testAlive())
            return;
        setEnergy(getEnergy() - 2);
        setHungry(getHungry() - 1);
        setClean(getClean() - 3);
        diamonds += 1;
        age += 1;
    }

    void shower() {
    }

    void eat() {
    }

    void sleep() {
    }


    int getClean() {
        return clean;
    }
    int getHungry() {
        return hungry;
    }
    int getEnergy() {
        return energy;
    }
    int getEnergyMax() {
        return energyMax;
    }
    int getCleanMax() {
        return cleanMax;
    }
    int getHungryMax() {
        return hungryMax;
    }

    std::string toString() {
        std::stringstream ss;
        ss <<  "E:" << energy << "/" << energyMax << ", "
           <<  "S:" << hungry << "/" << hungryMax << ", "
           <<  "L:" << clean << "/" << cleanMax << ", "
           <<  "D:" << diamonds << ", " << "I:"  << age;
        return ss.str();
    }

};


int main() {
    aux::Chain chain;
    aux::Param ui;
    Pet pet;
    auto toint = aux::to<int>;
    chain["show"]   = [&]() { std::cout << pet.toString() << '\n'; };
    chain["init"]   = [&]() { pet = Pet(toint(ui[1]), toint(ui[2]), toint(ui[3])); };
    chain["play"]   = [&]() { pet.play(); };
    chain["eat"]    = [&]() { pet.eat(); };
    chain["shower"] = [&]() { pet.shower(); };
    chain["sleep"]  = [&]() { pet.sleep(); };
    
    aux::execute(chain, ui);
};
