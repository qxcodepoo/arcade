#include <iostream>
#include <sstream>
#include <iomanip> //setprecision
using namespace std;

struct Calc{
    int bateria;
    int limiteBateria;

    Calc(int limiteBateria = 0){
        this->limiteBateria = limiteBateria;
        this->bateria = 0;
    }
    void charge(int carga){
        bateria += carga;
        if(bateria > limiteBateria)
            bateria = limiteBateria;
    }
    void gastarBateria(){
        if(bateria <= 0)
            throw "fail: bateria insuficiente";
        this->bateria -= 1;
    }
    string soma(int a, int b){
        gastarBateria();
        return to_string(a + b);
    }
    string div(int a, int b){
        gastarBateria();
        if(b == 0)
            throw "fail: divisao por zero";
        return to_string(a/b);
    }
    string toString(){
        return "battery = " + to_string(this->bateria);
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
        try{
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
                cout << calc.soma(a, b) << endl;
            }else if(op == "div"){
                int a, b;
                ss >> a >> b;
                cout << calc.div(a, b) << endl;
            }else if(op == "charge"){
                int charge;
                ss >> charge;
                calc.charge(charge);
            }else if(op == "show"){
                cout << calc.toString() << endl;
            }else 
                cout << "fail: comando invalido" << endl;
        }catch(const char* error){
            cout << error << endl;
        }
    }
    return 0;
}