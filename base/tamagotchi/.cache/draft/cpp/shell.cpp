#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "init") {
            // CRIE UM NOVO JOGO COM UM NOVO PET
            // int energy, clean;
            // ss >> energy >> clean;
        } else if (cmd == "show") { // TODO
        } else if (cmd == "play") { // TODO
        } else if (cmd == "shower") { // TODO
        } else if (cmd == "eat") { // TODO
        } else if (cmd == "sleep") { // TODO
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
    return 0;
}
