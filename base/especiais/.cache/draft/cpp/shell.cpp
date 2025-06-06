#include <map>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<pair<int, int>> occurr(vector<int> vet) {
    (void) vet;
    return {};
}

vector<pair<int, int>> teams(vector<int> vet) {
    (void) vet;
    return {};
}

vector<int> mnext(vector<int> vet) {
    (void) vet;
    return {};
}

vector<int> alone(vector<int> vet) {
    (void) vet;
    return {};
}

int couple(vector<int> vet) {
    (void) vet;
    return {};
}

bool has_subseq(vector<int> vet, vector<int> seq, int pos) {
    (void) vet;
    (void) seq;
    (void) pos;
    return {};
}

int subseq(vector<int> vet, vector<int> seq) {
    (void) vet;
    (void) seq;
    return {};
}

vector<int> erase(vector<int> vet, vector<int> pos_list) {
    (void) vet;
    (void) pos_list;
    return {};
}

vector<int> clear(vector<int> vet, int value) {
    (void) vet;
    (void) value;
    return {};
}


vector<string> split(string str, char delim) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim))
        tokens.push_back(token);
    return tokens;
}

vector<int> str2vet(string str) {
    vector<int> vet;
    stringstream ss(str.substr(1, str.size() - 2));
    string token;
    while (getline(ss, token, ','))
        vet.push_back(stoi(token));
    return vet;
}

void print(vector<pair<int, int>> output) {
    cout << "[";
    for (int i = 0; i < (int) output.size(); i++) {
        cout << "(" << output[i].first << ", " << output[i].second << ")";
        if (i != (int) output.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}
void print(vector<int> output) {
    cout << "[";
    for (int i = 0; i < (int) output.size(); i++) {
        cout << output[i];
        if (i != (int) output.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}
void print(string output) {
    cout << output << endl;
}
void print(int output) {
    cout << output << endl;
}

int main(){
 
    
    while(true) {
        string line;
        getline(cin, line);
        cout << "$" << line << endl;
        auto args = split(line, ' ');

        if     (args[0] == "occurr" ) { print(occurr(str2vet(args[1])));                   }
        else if(args[0] == "teams"  ) { print(teams(str2vet(args[1])));                    }
        else if(args[0] == "mnext"  ) { print(mnext(str2vet(args[1])));                    }
        else if(args[0] == "alone"  ) { print(alone(str2vet(args[1])));                    }
        else if(args[0] == "erase"  ) { print(erase(str2vet(args[1]), str2vet(args[2])));  }
        else if(args[0] == "clear"  ) { print(clear(str2vet(args[1]), stoi(args[2])));     }
        else if(args[0] == "subseq" ) { print(subseq(str2vet(args[1]), str2vet(args[2]))); }
        else if(args[0] == "couple" ) { print(couple(str2vet(args[1])));                   }
        else if(args[0] == "end"    ) { break;                                             }
        else                          { print("Invalid command");                          }
    }
}
