#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    // CRIE SEU OBJETO AQUI
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "size") { // TENTE ATRIBUIR UM TAMANHO
            // string size;
            // ss >> size;
        } else if (cmd == "show") { // MOSTRE AS INFORMAÇÕES DO OBJETO
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: Comando inválido" << endl;
        }
    }
}