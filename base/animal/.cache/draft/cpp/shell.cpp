#include <iostream>
#include <sstream>
using namespace std;


int main () {
    // CRIE SEU OBJETO AQUI
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << '\n';

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "init" ) {
            // INICIE SEU OBJETO AQUI USANDO O CONSTRUTOR
            // string species, sound;
            // ss >> species >> sound;
        } else if (cmd == "grow" ) {
            // CHAME O MÉTODO PARA CRESCER
            // int increment {};
            // ss >> increment;
        } else if (cmd == "noise") {
            // OBTENHA O SOM DO ANIMAL E IMPRIMA
        } else if (cmd == "show" ) {
            // IMPRIMA O ANIMAL
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
}
