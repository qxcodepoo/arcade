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

        if (cmd == "set") {
            // TODO
            // Chame os métodos setHour, setMinute e setSecond
            // int hour {}, minute {}, second {};
            // ss >> hour >> minute >> second;
        } else if (cmd == "init") {
            // TODO
            // Chame o construtor para inicializar o relógio
            // int hour {}, minute {}, second {};
            // ss >> hour >> minute >> second;
        } else if (cmd == "show") {
            // TODO
            // Chame o método str e imprima o horário
            // cout << time.str() << endl;
        } else if (cmd == "next") {
            // TODO
            // Chame o método nextSecond
            // time.nextSecond();
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}