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

        if (cmd == "end") {
            break;
        } 
        // else if (cmd == "show") { 
        // }
        // else if (cmd == "setDriver") { 
        //     string name;
        //     int money;
        //     ss >> name >> money;
        // }
        // else if (cmd == "setPass") { 
        //     string name;
        //     int money;
        //     ss >> name >> money;
        // }
        // else if (cmd == "drive") { 
        //     int distance;
        //     ss >> distance;
        // }
        // else if (cmd == "leavePass") { 
        // }
        else {
            cout << "fail: command not found\n";
        }
    }
}
