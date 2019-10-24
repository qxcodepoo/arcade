#include <iostream>
#include <sstream>
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
    bool gastarBateria(){
        if(bateria == 0){
            cout << "fail: bateria insuficiente" << endl;
            return false;
        }
        this->bateria -= 1;
        return true;
    }
    string soma(int a, int b){
        if(gastarBateria())
            return to_string(a + b);
        return "";
    }
    string div(int a, int b){
        if(!gastarBateria())
            return "";
        if(b != 0)
            return to_string(a/b);
        cout << "fail: divisao por zero" << endl;        
        return "";
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
            string value = calc.soma(a, b);
            if(value != "")
                cout << value << endl;
        }else if(op == "div"){
            int a, b;
            ss >> a >> b;
            string value = calc.div(a, b);
            if(value != "")
                cout << value << endl;
        }else if(op == "charge"){
            int charge;
            ss >> charge;
            calc.charge(charge);
        }else if(op == "show"){
            cout << calc.toString() << endl;
        }else 
            cout << "fail: comando invalido" << endl;
    }
    return 0;
}