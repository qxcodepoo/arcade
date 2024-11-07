#include <iostream>
#include <string>

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