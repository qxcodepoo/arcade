#include <sstream>
#include <iostream>
using namespace std;

template <typename CONTAINER, typename FN>
string map_join(const CONTAINER& container, FN fn, string sep = ", ") {
    stringstream ss;
    for (auto it = container.begin(); it != container.end(); ++it) {
        ss << (it != container.begin() ? sep : "") << fn(*it);
    }
    return ss.str();
}

int main() {
    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if(cmd == "end") {
            break;
        }
        else if(cmd == "addCli") {
            // string name;
            // int limite {};
            // ss >> name >> limite;
        }
        else if(cmd == "show") {
        }
        else if(cmd == "showCli") {
            // string name;
            // ss >> name;
        }
        else if(cmd == "kill") {
            // string name;
            // ss >> name;
        }
        else if(cmd == "give") {
            // string name;
            // int value;
            // ss >> name >> value;
        }
        else if(cmd == "take") {
            // string name;
            // int value;
            // ss >> name >> value;
        }
        else if(cmd == "plus") {
        }
        else {
            cout << "fail: comando invalido\n";
        }
    }
}
