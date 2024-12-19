#include <iostream>
#include <sstream>
using namespace std;

struct Animal {
    string species;
    string sound;
    int age;
    Animal(string species = "", string noise = "") {
        this->species = species;
        this->sound = noise;
        this->age = 0;
    }

    string makeSound() const {
        if (age == 0) {
            return "---";
        }
        if (age == 4) {
            return "RIP";
        }
        return this->sound;
    }

    void ageBy(int increment) {
        age += increment;
        if (age >= 4) {
            cout << "warning: " << species << " morreu\n";
            age = 4;
        }
    }

    string str() const {
        return (stringstream() << species << ":" << age << ":" << sound).str();
    }
};


int main () {
    Animal animal("", "");
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << '\n';

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        }
        else if (cmd == "init" ) {
            string species, sound;
            ss >> species >> sound;
            animal = Animal(species, sound);
        } 
        else if (cmd == "show" ) {
            cout << animal.str() << '\n';
        } 
        else if (cmd == "grow" ) {
            int increment {};
            ss >> increment;
            animal.ageBy(increment);
        } 
        else if (cmd == "noise") {
            cout << animal.makeSound() << '\n';
        } 
        else {
            cout << "fail: comando invalido\n";
        }
    }
}