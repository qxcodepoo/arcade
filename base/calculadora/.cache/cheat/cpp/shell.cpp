#include <iostream> // fixed, cout, endl, string
#include <sstream> // stringstream
#include <iomanip> // setprecision
using namespace std;

struct Calculator {
    int batteryMax;
    int battery;
    float display;

    Calculator(int batteryMax = 0) : batteryMax(batteryMax) {
        this->battery = 0;
        this->display = 0.0f;
    }

    void chargeBattery(int value) {
        if(value < 0) {
            return;
        }
        this->battery += value;
        this->battery = std::min(this->battery, this->batteryMax);
    }

    void sum(int a, int b) {
        if(this->battery == 0){
            cout << "fail: bateria insuficiente" << endl;
            return;
        }
        this->battery -= 1;
        this->display = (a + b);
        
    }

    void division(int num, int den) {
        if(this->battery == 0){
            cout << "fail: bateria insuficiente" << endl;
            return;
        }
        this->battery -= 1;
        if(den == 0) {
            cout << "fail: divisao por zero" << endl;
            return;
        }
        this->display = (float) num / den;
    }

    std::string str() const {
        stringstream ss;
        ss << "display = " << fixed << setprecision(2) << this->display << ", battery = " << this->battery;
        return ss.str();
    }
};

int main() {
    Calculator calc;

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << '\n';

        stringstream par(line);
        par >> cmd;

        if (cmd == "init") {
            int batteryMax {};
            par >> batteryMax;
            calc = Calculator(batteryMax);
        } else if (cmd == "show") {
            cout << calc.str() << '\n';
        } else if (cmd == "charge") {
            int increment {};
            par >> increment;
            calc.chargeBattery(increment);
        } else if (cmd == "sum") {
            int a {}, b {};
            par >> a >> b;
            calc.sum(a, b);
        } else if (cmd == "div") {
            int num {}, den {};
            par >> num >> den;
            calc.division(num, den);
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }


}