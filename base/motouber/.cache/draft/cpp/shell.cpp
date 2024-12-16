#include <iostream>
#include <sstream>
#include <memory>
using namespace std;


int main() {

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "show") { // TODO
        } else if (cmd == "setDriver") { // TODO
            // string name;
            // int money;
            // ss >> name >> money;
        } else if (cmd == "setPass") { // TODO
            // string name;
            // int money;
            // ss >> name >> money;
        } else if (cmd == "drive") { // TODO
            // int distance;
            // ss >> distance;
        } else if (cmd == "leavePass") { // TODO
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: command not found\n";
        }
    }
}