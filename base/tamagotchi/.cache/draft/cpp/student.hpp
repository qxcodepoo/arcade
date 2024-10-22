#include <iostream>
#include <string>

class Pet {
private:
    int energyMax;
    int hungryMax;
    int cleanMax;

    int energy;
    int hungry;
    int clean;

    int diamonds;
    int age;
    bool alive;

public:
    Pet(int energy = 0, int hungry = 0, int clean = 0) {
        this->energyMax = energy;
        this->hungryMax = hungry;
        this->cleanMax = clean;

        this->energy = energy;
        this->hungry = hungry;
        this->clean = clean;

        this->diamonds = 0;
        this->age = 0;
        this->alive = true;
    }

    void setEnergy(int value) {
        if (value <= 0) {
            this->alive = false;
            this->energy = 0;
            std::cout << "fail: pet morreu de fraqueza" << std::endl;
            return;
        }
        if (value > this->energyMax) {
            this->energy = this->energyMax;
            return;
        }
        this->energy = value;
    }

    void setHungry(int value) {
        if (value <= 0) {
            this->alive = false;
            this->hungry = 0;
            std::cout << "fail: pet morreu de fome" << std::endl;
            return;
        }
        if (value > this->hungryMax) {
            this->hungry = this->hungryMax;
            return;
        }
        this->hungry = value;
    }

    void setClean(int value) {
        if (value <= 0) {
            this->alive = false;
            this->clean = 0;
            std::cout << "fail: pet morreu de sujeira" << std::endl;
            return;
        }
        if (value > this->cleanMax) {
            this->clean = this->cleanMax;
            return;
        }
        this->clean = value;
    }

    void setDiamonds(int value) {
        this->diamonds = value;
    }

    void setAge(int value) {
        this->age = value;
    }

    std::string str() const {
        return "E:" + std::to_string(this->energy) + "/" + std::to_string(this->energyMax) +
               ", S:" + std::to_string(this->hungry) + "/" + std::to_string(this->hungryMax) +
               ", L:" + std::to_string(this->clean) + "/" + std::to_string(this->cleanMax) +
               ", D:" + std::to_string(this->diamonds) + ", I:" + std::to_string(this->age);
    }

    int getClean() const {
        return this->clean;
    }

    int getHungry() const {
        return this->hungry;
    }

    int getEnergy() const {
        return this->energy;
    }

    int getCleanMax() const {
        return this->cleanMax;
    }

    int getHungryMax() const {
        return this->hungryMax;
    }

    int getEnergyMax() const {
        return this->energyMax;
    }

    int getDiamonds() const {
        return this->diamonds;
    }

    int getAge() const {
        return this->age;
    }

    bool isAlive() const {
        return this->alive;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Pet& pet) {
    return os << pet.str();
}

class Game {
private:
    Pet pet;

    bool testAlive() const {
        if (!this->pet.isAlive()) {
            std::cout << "fail: pet esta morto" << std::endl;
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
        this->pet.setHungry(this->pet.getHungry() - 1);
        this->pet.setClean(this->pet.getClean() - 3);
        this->pet.setAge(this->pet.getAge() + 1);
        this->pet.setDiamonds(this->pet.getDiamonds() + 1);
    }

    void shower() {
        if (!this->testAlive())
            return;
        this->pet.setEnergy(this->pet.getEnergy() - 3);
        this->pet.setHungry(this->pet.getHungry() - 1);
        this->pet.setClean(this->pet.getCleanMax());
        this->pet.setAge(this->pet.getAge() + 2);
    }

    void eat() {
        if (!this->testAlive())
            return;
        this->pet.setEnergy(this->pet.getEnergy() - 1);
        this->pet.setHungry(this->pet.getHungry() + 4);
        this->pet.setClean(this->pet.getClean() - 2);
        this->pet.setAge(this->pet.getAge() + 1);
    }

    void sleep() {
        if (!this->testAlive())
            return;
        if (this->pet.getEnergyMax() - this->pet.getEnergy() < 5) {
            std::cout << "fail: nao esta com sono" << std::endl;
            return;
        }
        this->pet.setAge(this->pet.getAge() + (this->pet.getEnergyMax() - this->pet.getEnergy()));
        this->pet.setEnergy(this->pet.getEnergyMax());
        this->pet.setHungry(this->pet.getHungry() - 1);
    }

    std::string str() const {
        return this->pet.str();
    }
};

inline std::ostream& operator<<(std::ostream& os, const Game& game) {
    return os << game.str();
}

class Student {
private:
    // Game game;
public:
    Student(int energy, int hungry, int clean) {
        (void) energy;
        (void) hungry;
        (void) clean;
        // this->game = Game(Pet(energy, hungry, clean));
    }

    void show() {
        // std::cout << this->game.str() << std::endl;
    }

    void play() {
        // this->game.play();
    }

    void shower() {
        // this->game.shower();
    }

    void eat() {
        // this->game.eat();
    }

    void sleep() {
        // this->game.sleep();
    }
};
