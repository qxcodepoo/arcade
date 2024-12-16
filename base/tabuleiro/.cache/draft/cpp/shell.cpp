#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main() {

    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "init") {
            // int nPlayers, size;
            // ss >> nPlayers >> size;
            // board = Board(nPlayers, size);
        } else if (cmd == "addTrap") {
            // int pos;
            // ss >> pos;
            // board.addTrap(pos);
        } else if (cmd == "roll") {
            // int value;
            // ss >> value;
        } else if (cmd == "show") {
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: command not found" << endl;
        }

    }
}
