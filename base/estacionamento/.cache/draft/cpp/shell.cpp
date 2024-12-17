#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "show") {
        } else if (cmd == "estacionar") {
            // string tipo, id;
            // ss >> tipo >> id;
        } else if (cmd == "tempo") {
            // int tempo {};
            // ss >> tempo;
        } else if (cmd == "pagar") {
            // string id;
            // ss >> id;
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
