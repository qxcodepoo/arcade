#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Pet{
private:
    int energyMax, hungryMax, cleanMax;
    int energy, hungry, clean;
    int diamonds;
    int age;
    bool alive;

    void setEnergy(int value){
        if(value <= 0){
            energy = 0;
            cout << "fail: pet morreu de fraqueza" << endl;
            alive = false;
        }
        else if(value > energyMax)
            energy = energyMax;
        else
            energy = value;
    }

    void setHungry(int value){
        if(value <= 0){
            hungry = 0;
            cout << "fail: pet morreu de fome" << endl;
            alive = false;
        }
        else if(value > hungryMax)
            hungry = hungryMax;
        else
            hungry = value;
    }
    
    void setClean(int value){
        if(value <= 0){
            clean = 0;
            cout << "fail: pet morreu de sujeira" << endl;
            alive = false;
        }
        else if(value > cleanMax)
            clean = cleanMax;
        else
            clean = value;
    }


public:
    Pet(int energy = 0, int hungry = 0, int clean = 0):
        energyMax(energy), hungryMax(hungry), cleanMax(clean),
        energy(energy), hungry(hungry), clean(clean){
        age = 0;
        diamonds = 0;
        alive = true;
    }

    int getClean(){
        return clean;
    }
    int getHungry(){
        return hungry;
    }
    int getEnergy(){
        return energy;
    }
    int getEnergyMax(){
        return energyMax;
    }
    int getCleanMax(){
        return cleanMax;
    }
    int getHungryMax(){
        return hungryMax;
    }

    string toString(){
        stringstream ss;
        ss <<  "E:" << energy << "/" << energyMax << ", "
           <<  "S:" << hungry << "/" << hungryMax << ", "
           <<  "L:" << clean << "/" << cleanMax << ", "
           <<  "D:" << diamonds << ", " << "I:"  << age;
        return ss.str();
    }

    bool testAlive(){
        if(alive)
            return true;
        cout << "fail: pet esta morto" << endl;
        return false;
    }

    void play(){
        if(!testAlive())
            return;
        setEnergy(getEnergy() - 2);
        setHungry(getHungry() - 1);
        setClean(getClean() - 3);
        diamonds += 1;
        age += 1;
    }

    void shower(){
        if(!testAlive())
            return;
        setEnergy(getEnergy() - 3);
        setHungry(getHungry() - 1);
        setClean(cleanMax);
        age += 2;
    }

    void eat(){
        if(!testAlive())
            return;
        setEnergy(getEnergy() - 1);
        setHungry(getHungry() + 4);
        setClean(getClean() - 2);
        age += 1;
    }

    void sleep(){
        if(!testAlive())
            return;
        if(energyMax - getEnergy() < 5){
            cout << "fail: nao esta com sono" << endl;
            return;
        }
        age += energyMax - getEnergy();
        setEnergy(energyMax);
        setHungry(getHungry() - 1);
    }

};


struct Controller{
    Pet pet;

    void shell(string line){
        stringstream in(line);
        string op;
        in >> op;
        if(op == "show"){
            cout << pet.toString() << endl;
        }else if(op == "init"){
            int energy, hungry, clean;
            in >> energy >> hungry >> clean;
            pet = Pet(energy, hungry, clean);
        }else if(op == "play"){
            pet.play();
        }else if(op == "eat"){
            pet.eat();
        }else if(op == "clean"){
            pet.shower();
        }else if(op == "sleep"){
            pet.sleep();
        }else{
            cout << "fail: operacao invalida" << endl;
        }
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            cout << "$" << line << endl;
            if(line == "end")
                return;
            shell(line);
        }
    }
};

int main(){
    Controller c;
    c.exec();
    return 0;
}
