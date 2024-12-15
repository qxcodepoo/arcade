#include <iostream>
#include <sstream>
using namespace std;

int main() {
    // CRIE SEU CARRO AQUI
    while (true) {
        
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << '\n';

        stringstream ss(line);
        ss >> cmd;
        
        if (cmd == "show") {
            // MOSTRE O CARRO
        } else if (cmd == "enter") {
            // TENTE EMBARCAR
        } else if (cmd == "leave") {
            // TENTE DESCEMBARCAR
        } else if (cmd == "fuel") {
            // AUMENTE O COMBUSTIVEL
            // int increment{};
            // ss >> increment;
        } else if (cmd == "drive") {
            // TENTE DIRIGIR
            // int distance {};
            // ss >> distance;
        } else if (cmd == "end")   {
            break;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
}
