#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip> //setprecision
using namespace std;

inline int count(vector<int> vet, int x) {
    (void) vet;
    (void) x;
    return 0;
}

inline int sum(vector<int> vet) {
    (void) vet;
    return 0;
}

inline double average(const vector<int>& vet) {
    // (void) vet;
    return 0;
}

inline string more_men(const vector<int>& vet) {
    (void) vet;
    return "";
}

inline string half_compare(const vector<int>& vet) {
    (void) vet;
    return "";
}

inline string sex_battle(const vector<int>& vet) {
    (void) vet;
    return "";
}

vector<int> str2vet(string s);
vector<string> split(string s, char delim);

int main() {
    while (true) {

        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        auto args = split(line, ' ');

        if (args[0] == "end") {
            break;
        } else if (args[0] == "count") {
            cout << count(str2vet(args[1]), stoi(args[2])) << endl;
        } else if (args[0] == "sum") {
            cout << sum(str2vet(args[1])) << endl;
        } else if (args[0] == "more_men") {
            cout << more_men(str2vet(args[1])) << endl;
        } else if (args[0] == "half_compare") {
            cout << half_compare(str2vet(args[1])) << endl;
        } else if (args[0] == "more_men_or_women") {
            cout << more_men(str2vet(args[1])) << endl;
        } else if (args[0] == "sex_battle") {
            cout << sex_battle(str2vet(args[1])) << endl;
        } else if (args[0] == "average") {
            cout << fixed << setprecision(2) << average(str2vet(args[1])) << endl;
        } else {
            cout << "fail: unknown command" << endl;
        }
    }     
}

vector<int> str2vet(string s) {
    vector<int> vet;
    auto sub = s.substr(1, s.size() - 2);
    stringstream ss(sub);
    string token;
    while (getline(ss, token, ',')) {
        vet.push_back(stoi(token));
    }
    return vet;
}

vector<string> split(string s, char delim) {
    vector<string> tokens;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delim)) {
        tokens.push_back(token);
    }
    return tokens;
}
