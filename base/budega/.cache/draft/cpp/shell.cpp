#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include <sstream>
#include <utility>
using namespace std;


// Função auxiliar para mapear e juntar elementos de um container
template <typename CONTAINER, typename FUNC>
auto map_join(const CONTAINER& c, FUNC f, const string& sep = ", ") {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ss << (it != c.begin() ? sep : "") << f(*it);
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
            // int qtd_caixas;
            // ss >> qtd_caixas;
        } else if (cmd == "arrive") { 
            // string nome;
            // ss >> nome;
        } else if (cmd == "call") { 
            // int indice;
            // ss >> indice;
        } else if (cmd == "finish") { 
            // int indice;
            // ss >> indice;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
}
