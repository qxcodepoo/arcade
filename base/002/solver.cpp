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

    Carro(int pass = 0, int passMax = 2, int gas = 0,int gasMax = 100,int km = 0){
        this->pass = pass; // Passageiros
        this->passMax = passMax; // limite de Passageiros
        this->gas = gas; // tanque
        this->gasMax = gasMax; // limite do tanque
        this->km = km; // quantidade de quilometragem
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

int main(){
    Carro car;
    string line;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        cout << "$" << line << endl;
        ss >> cmd;
        if(line == "end")
            break;
        else if(cmd == "help")
            cout << "in; out; show; fuel _gat; drive _km" << endl;
        else if(cmd == "in"){
            car.in();
        }else if(cmd == "out"){
            car.out();
        }else if(cmd == "show"){
            cout << car.toString() << endl;
        }else if (cmd == "drive"){
            int km;
            ss >> km;
            car.drive(km);
        }else if (cmd == "fuel"){
            int gas;
            ss >> gas;
            car.fuel(gas);
        }else
            cout << "fail: comando invalido" << endl;
    }
    return 0;
}

