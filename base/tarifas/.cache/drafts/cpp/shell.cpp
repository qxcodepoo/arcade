#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

template<typename CONTAINER, typename FUNC>
string join(const CONTAINER& cont, FUNC func, const string& delim) {
    stringstream ss;
    for (auto it = cont.begin(); it != cont.end(); it++) {
        ss << (it == cont.begin() ? "" : delim) << func(*it);
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

        
        if (cmd == "end") {
            break;
        }
        else if (cmd == "init") {
            // int number{};
            // ss >> number;
        }
        else if (cmd == "show") {
            // TODO
        }
        else if (cmd == "deposit") {
            // float value{};
            // ss >> value;
        }
        else if (cmd == "withdraw") {
            // float value{};
            // ss >> value;
        }
        else if (cmd == "fee") {
            // float value{};
            // ss >> value;
        }
        else if (cmd == "extract") {
            // int qtd{};
            // ss >> qtd;
        }
        else if (cmd == "reverse") {
            // int index{};
            // while(ss >> index) {
            // }
        }
        else {
            cout << "fail: invalid command\n";
        }
    }
    return 0;
}
