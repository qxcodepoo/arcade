#include <iostream>
#include <sstream>
#include <iomanip> // std::setfill, std::setw
using namespace std;

int main() {
    // CRIE SEU RELÓGIO AQUI

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "set") {
            
            // Chame os métodos setHour, setMinute e setSecond
            // int hour {}, minute {}, second {};
            // ss >> hour >> minute >> second;
        } else if (cmd == "init") {
            
            // Chame o construtor para inicializar o relógio
            // int hour {}, minute {}, second {};
            // ss >> hour >> minute >> second;
        } else if (cmd == "show") {
            
            // Chame o método str e imprima o horário
            // cout << time.str() << endl;
        } else if (cmd == "next") {
            
            // Chame o método nextSecond
            // time.nextSecond();
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
