#include <iostream>
#include <list>
#include <sstream>
#include <memory>
using namespace std;

// Função auxiliar para mapear e juntar elementos de um container
template <typename CONTAINER, typename FUNC>
auto map_join(const CONTAINER& c, FUNC f, const string& sep = ", ") {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ss << (it != c.begin() ? sep : "");
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

        if (cmd == "show") { // TODO
        } else if (cmd == "init") { // TODO
            // float calibre;
            // ss >> calibre;
        } else if (cmd == "insert") { // TODO
            // float calibre;
            // string dureza;
            // int tamanho;
            // ss >> calibre >> dureza >> tamanho;
        } else if (cmd == "remove") { // TODO
        } else if (cmd == "pull") { // TODO
        } else if (cmd == "write") { // TODO
        } else if (cmd == "end") {
            break;  
        } else {
            cout << "fail: comando invalido\n";
        }
    }
}
