#include <iostream>
#include <cstdio>
#include <clocale>
#include <sstream>

using namespace std;

struct Carro{
    int pass; // Passageiros
    int passMax; // limite de Passageiros
    float gas; // tanque
    float gasMax; // limite do tanque
    float km; // quantidade de quilometragem

    Carro(int pass = 0, int passMax = 2, float gas = 0,float gasMax = 10,float km = 0){
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
    
    void fuel(float gas){
        this->gas += gas;
        if(this->gas > gasMax)
            this->gas = gasMax;
    }

    void drive (float km){
        if(this->pass == 0){
            cout << "fail: nao ha ninguem no carro" << endl;
        }
        else if(this->gas < (km / 10)){
            cout << "fail: gasolina insuficiente" << endl;
        }else{
            this->gas = gas - km / 10;
            this->km = this->km + km;
        }
    }    
};

struct Controller{
    Carro car;

    void shell(string line){
        stringstream in(line);
        string op;
        in >> op;
        if(op == "help")
            cout << "in; out; show; fuel _gat; drive _km" << endl;
        else if(op == "in"){
            car.in();
        }else if(op == "out"){
            car.out();
        }else if(op == "show"){
            cout << car.toString() << endl;
        }else if (op == "drive"){
            float km;
            in >> km;
            car.drive(km);
        }else if (op == "fuel"){
            float gas;
            in >> gas;
            car.fuel(gas);
        }else
            cout << "fail: comando invalido" << endl;
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
    setlocale(LC_ALL, "Portuguese");
    Controller c;
    c.exec();
    return 0;
}

