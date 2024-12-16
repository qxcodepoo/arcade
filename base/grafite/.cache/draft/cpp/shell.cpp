#include <iostream>
#include <memory>
#include <utility> //exchange
#include <sstream>
using namespace std;

int main() {
    
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "show") { // TODO
        } else if (cmd == "init") { // TODO
            // float thickness;
            // ss >> thickness;
        } else if (cmd == "insert") { // TODO
            // float thickness;
            // string hardness;
            // int size;
            // ss >> thickness >> hardness >> size;
        } else if (cmd == "remove") { // TODO
        } else if (cmd == "write") { // TODO
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
