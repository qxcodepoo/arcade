#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp


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
        fn::write("fail: pet esta morto");
        return false;
    }

    void setHungry(int value) {
        if (value <= 0) {
            hungry = 0;
            fn::write("fail: pet morreu de fome");
            alive = false;
        } else if (value > hungryMax) {
            hungry = hungryMax;
        } else {
            hungry = value;
        }
    }
    void setEnergy(int value);

    void setClean(int value);


public:
    Pet(int energy = 0, int hungry = 0, int clean = 0);

    void play() {
        if (!testAlive())
            return;
        setEnergy(getEnergy() - 2);
        setHungry(getHungry() - 1);
        setClean(getClean() - 3);
        diamonds += 1;
        age += 1;
    }

    void shower();

    void eat();

    void sleep();


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
        return fn::format("E:{}/{}, S:{}/{}, L:{}/{}, D:{}, I:{}", 
            energy, energyMax, hungry, hungryMax, clean, cleanMax, diamonds, age);
    }

};


int main() {
    Pet pet;
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');

        fn::write("$" + line);

        if (args[0] == "end") {
            break;
        } else if (args[0] == "init") {
            pet = Pet(+args[1], +args[2], +args[3]);
        } else if (args[0] == "show") {
            fn::write(pet.toString());
        } else if (args[0] == "play") {
            pet.play();
        } else if (args[0] == "eat") {
            pet.eat();
        } else if (args[0] == "sleep") {
            pet.sleep();
        } else if (args[0] == "shower") {
            pet.shower();
        } else {
            fn::write("fail: comando invalido");
        }
    }
}
