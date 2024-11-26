#include <iostream>
#include <string>

class Adapter {
private:
    // Game game;
public:
    Adapter(int energy, int hungry, int clean) {
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
