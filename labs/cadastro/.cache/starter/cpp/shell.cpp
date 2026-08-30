#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iomanip>
#include <sstream>

using namespace std;


int main() {
    string line;

    while (getline(cin, line)) {
        try {
            istringstream iss(line);
            string cmd;
            iss >> cmd;
            cout << "$" << line << endl;

            if (cmd == "end") {
                break;
            } else if (cmd == "show") {
            } else if (cmd == "addCli") {
                // string clientId;
                // iss >> clientId;
            } else if (cmd == "saque") {
                // int accountId;
                // double value;
                // iss >> accountId >> value;
            } else if (cmd == "deposito") {
                // int accountId;
                // double value;
                // iss >> accountId >> value;
            } else if (cmd == "transf") {
                // int accountIdFrom, accountIdTo;
                // double value;
                // iss >> accountIdFrom >> accountIdTo >> value;
            } else if (cmd == "update") {
            } else {
                cout << "fail: comando invalido" << endl;
            }
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
