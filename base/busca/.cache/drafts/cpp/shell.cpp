#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

inline bool in(vector<int> vet, int x) {
    (void) vet;
    (void) x;
    return false;
}

inline int index_of(vector<int> vet, int x) {
    (void) vet;
    (void) x;
    return 0;
}

inline int find_if(const vector<int>& vet) {
    (void) vet;
    return 0;
}

inline int min_element(const vector<int>& vet) {
    (void) vet;
    return 0;
}

inline int find_min_if(const vector<int>& vet) {
    (void) vet;
    return 0;
}

vector<int> str2vet(string s) {
    auto sub = s.substr(1, s.size() - 2);
    stringstream ss(sub);
    vector<int> vet;
    string token;
    while (getline(ss, token, ',')) {
        vet.push_back(stoi(token));
    }
    return vet;
}

int main() {
    while (true) {
        string line, cmd, svet, value;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "in") {
            ss >> svet >> value;
            cout << (in(str2vet(svet), stoi(value)) ? "true" : "false") << endl;
        } else if (cmd == "index_of") {
            ss >> svet >> value;
            cout << index_of(str2vet(svet), stoi(value)) << endl;
        } else if (cmd == "find_if") {
            ss >> svet;
            cout << find_if(str2vet(svet)) << endl;
        } else if (cmd == "min_element") {
            ss >> svet;
            cout << min_element(str2vet(svet)) << endl;
        } else if (cmd == "find_min_if") {
            ss >> svet;
            cout << find_min_if(str2vet(svet)) << endl;
        } else {
            cout << "fail: unknown command" << endl;
        }
    }
}
