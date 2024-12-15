#include <iostream>
#include <sstream>
using namespace std;

int main() {
    // CRIE SUA TOALHA AQUI
    while (true) {
        string line, cmd;
        getline(cin, line);

        stringstream par(line);
        par >> cmd;

        if (cmd == "mostrar") { // MOSTRE A TOALHA
        } else if (cmd == "criar") { // ATUALIZE A TOALHA UTILIZAND O CONSTRUTOR
            // string cor, tamanho;
            // par >> cor >> tamanho;
        } else if (cmd == "enxugar") { // USE O METODO ENXUGAR
            // int umidade {};
            // par >> umidade;
        } else if (cmd == "torcer") { // USE O METODO TORCER
        } else if (cmd == "seca") { // VERIFIQUE SE ESTA SECA E IMPRIMA "sim" OU "nao"
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}