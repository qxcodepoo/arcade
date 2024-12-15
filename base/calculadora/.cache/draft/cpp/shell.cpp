#include <iostream> // fixed, cout, endl, string
#include <sstream> // stringstream
#include <iomanip> // setprecision
using namespace std;

int main() {
    // CRIE SUA CALCULADORA AQUI

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << '\n';

        stringstream par(line);
        par >> cmd;

        if (cmd == "init") {
            // SUBSTITUA A CALCULADORA UTILIZANDO O CONSTRUTOR
            // int batteryMax {};
            // par >> batteryMax;
        } else if (cmd == "show") {
            // MOSTRE A CALCULADORA
        } else if (cmd == "charge") {
            // RECARREGAR
            // int increment {};
            // par >> increment;
        } else if (cmd == "sum") {
            // SOMAR
            // int a {}, b {};
            // par >> a >> b;
        } else if (cmd == "div") {
            // DIVIDIR
            // int num {}, den {};
            // par >> num >> den;
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }


}
