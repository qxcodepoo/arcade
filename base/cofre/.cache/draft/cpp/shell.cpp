#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

template <typename CONTAINER, typename FUNC>
string map_join(const CONTAINER& container, FUNC func, const string& separator) {
    stringstream ss;
    for (auto it = container.begin(); it != container.end(); ++it) {
        ss << (it == container.begin() ? "" : separator);
        ss << func(*it);
    }
    return ss.str();
}


int main() {
    while (true) {
        try {
            string line, cmd;
            getline(cin, line);
            cout << '$' << line << endl;

            stringstream ss(line);
            ss >> cmd;

            if (cmd == "end" ) {
                break;
            }
            else if (cmd == "init") {
                // int volumeMax;
                // ss >> volumeMax;
            }
            else if (cmd == "addCoin") {
                // int value;
                // ss >> value;
            }
            else if (cmd == "addItem") {
                // string label;
                // double value;
                // int volume;
                // ss >> label >> value >> volume;
            }
            else if (cmd == "break") {
            }
            else if (cmd == "extractCoins") {
            }
            else if (cmd == "extractItems") { 
            }
            else if (cmd == "show") { 
            }
            else { 
                cout << "fail: invalid command" << endl;
            }
        } catch (string s) {
            cout << s << endl;
        }
    }

}
