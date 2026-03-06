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

        if (cmd == "end") {
            break;
        } 
        // else if (cmd == "show") { 
        // }
        // else if (cmd == "init") { 
        //     float thickness;
        //     ss >> thickness;
        // }
        // else if (cmd == "insert") { 
        //     float thickness;
        //     string hardness;
        //     int size;
        //     ss >> thickness >> hardness >> size;
        // }
        // else if (cmd == "remove") { 
        // }
        // else if (cmd == "write") { 
        // }
        else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
