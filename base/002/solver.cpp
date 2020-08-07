#include <iostream>
#include <cstdio>
#include <clocale>
#include <sstream>

using namespace std;

struct Carro{
    int pass; // Passageiros
    int passMax; // limite de Passageiros
    int gas; // tanque
    int gasMax; // limite do tanque
    int km; // quantidade de quilometragem

    Carro(int pass = 0, int passMax = 2, int gas = 0,int gasMax = 100, int km = 0){
        this->pass = pass; // Passageiros
        this->passMax = passMax; // limite de Passageiros
        this->gas = gas; // tanque
        this->gasMax = gasMax; // limite do tanque
        this->km = km; // quantidade de quilometragem
    }

    ~Carro(){
    }

    string toString(){
        stringstream saida;
        saida << "pass: " << pass << ", gas: " << gas << ", km: " << km; //nao endl
        return saida.str();
    }

    void in(){
        if (pass < passMax){
            pass += 1;
            return;
        }
        cout << "fail: limite de pessoas atingido" << endl;
    }

    void out(){
        if (pass > 0){
            pass-=1;
            return;
        }
        cout << "fail: nao ha ninguem no carro" << endl;
    }
    
    void fuel(int gas){
        this->gas += gas;
        if(this->gas > gasMax)
            this->gas = gasMax;
    }

    void drive (int km){
        if(this->pass == 0){
            cout << "fail: nao ha ninguem no carro" << endl;
        }else if(this->gas == 0){
            cout << "fail: tanque vazio" << endl;
        }
        else if(this->gas < km){
            cout << "fail: tanque vazio apos andar " << this->gas << " km" << endl;
            this->km += this->gas;
            this->gas = 0;
        }else{
            this->gas = gas - km;
            this->km = this->km + km;
        }
    }    
};

/*
int main(){
    //java
    Carro fusca1 = new Carro(0, 5, 0, 30, 100000);
    Carro fusca2 = new Carro(0, 5, 0, 30, 100000);
    Carro fusca3 = fusca2;
    Carro ferrari = new Carro(0, 2, 60, 60, 0);

    //c++ dinamico
    Carro * fusca1 = new Carro(0, 5, 0, 30, 100000);
    Carro * fusca2 = new Carro(0, 5, 0, 30, 100000);
    fusca1 == fusca2
    Carro * fusca3 = fusca2;
    Carro * ferrari = new Carro(0, 2, 60, 60, 0);

    //c++ estático
    Carro fusca1(0, 5, 0, 30, 100000);
    Carro fusca2(0, 5, 0, 30, 100000);
    fusca1 == fusca2
}
*/

int main(){
    Carro * car = new Carro;
    string line;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        cout << "$" << line << endl;
        ss >> cmd;
        if(line == "end"){
            break;
        }else if(cmd == "init"){//init 0 5 0 40 10000
            int pass, maxPass, gas, maxGas, km;
            ss >> pass >> maxPass >> gas >> maxGas >> km;
            if(car != nullptr){
                delete car;
                car = nullptr;
            }
            car = new Carro(pass, maxPass, gas, maxGas, km);
        }else if(cmd == "help")
            cout << "in; out; show; fuel _gas; drive _km" << endl;
        else if(cmd == "in"){
            car->in();
        }else if(cmd == "out"){
            car->out();
        }else if(cmd == "show"){
            cout << car->toString() << endl;
        }else if (cmd == "drive"){
            int km;
            ss >> km;
            car->drive(km);
        }else if (cmd == "fuel"){
            int gas;
            ss >> gas;
            car->fuel(gas);
        }else
            cout << "fail: comando invalido" << endl;
    }
    if(car != nullptr){
        delete car;
        car = nullptr;
    }
    return 0;
}


