#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
using namespace std;

template<class CONTAINER, class FUNC>
string map_join(const CONTAINER& c, FUNC f, string sep) {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); it++) {
        ss << (it == c.begin() ? "" : sep);
        ss << f(*it);
    }
    return ss.str();
}

int main() {

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;    
        } else if (cmd == "show") {
        } else if (cmd == "init") {
            // int qtd;
            // ss >> qtd;
        } else if (cmd == "reserve") {
            // string id, phone;
            // int index;
            // ss >> id >> phone >> index;
        } else if (cmd == "cancel") {
            // string id;
            // ss >> id;
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
