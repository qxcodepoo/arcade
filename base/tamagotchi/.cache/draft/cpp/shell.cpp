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

        if (cmd == "end") {
            break;
        } 
        // else if (cmd == "init") {
        //     // CRIE UM NOVO JOGO COM UM NOVO PET
        //     int energy, clean;
        //     ss >> energy >> clean;
        // }
        // else if (cmd == "show") { 
        // } 
        // else if (cmd == "play") { 
        // } 
        // else if (cmd == "shower") { 
        // } 
        // else if (cmd == "eat") { 
        // } 
        // else if (cmd == "sleep") { 
        // } 
        else {
            cout << "fail: comando invalido" << endl;
        }
    }
    return 0;
}
