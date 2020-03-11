#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

struct Calc{
    int bateria;
    int limiteBateria;
    float display;

    Calc(int limiteBateria = 0){
        this->limiteBateria = limiteBateria;
        this->bateria = 0;
        this->display = 0.0;
    }
    void charge(int carga){
        bateria += carga;
        if(bateria > limiteBateria)
            bateria = limiteBateria;
    }
    bool gastarBateria(){
        if(bateria == 0){
            cout << "fail: bateria insuficiente" << endl;
            return false;
        }
        this->bateria -= 1;
        return true;
    }
    void soma(int a, int b){
        if(gastarBateria())
            display = a + b;
    }
    void div(int a, int b){
        if(!gastarBateria())
            return;
        if(b != 0)
            display = (float) a / b;
        else
            cout << "fail: divisao por zero" << endl;        
    }
    void show(){
        printf("display = %.2f, battery = %d\n", this->display, this->bateria);
    }
};

int main(){
    Calc calc;
    string line;
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        if(line == "end")
            break;

        stringstream ss(line);
        string op;
        ss >> op;
        if(op == "help"){
            cout << "sum _a _b; div _a _b; show; charge _carga; end";
        }else if(op == "init"){
            int max;
            ss >> max;
            calc = Calc(max);
        }else if(op == "sum"){
            int a, b;
            ss >> a >> b;
            calc.soma(a, b);
        }else if(op == "div"){
            int a, b;
            ss >> a >> b;
            calc.div(a, b);
        }else if(op == "charge"){
            int charge;
            ss >> charge;
            calc.charge(charge);
        }else if(op == "show"){
            calc.show();
        }else 
            cout << "fail: comando invalido" << endl;
    }
    return 0;
}