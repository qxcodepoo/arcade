#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// @DROP
#include <algorithm>

class Roupa {
    string size;
public:
    Roupa() {
    }
    void setSize(const string& size) {
        vector<string> sizes = {"PP", "P", "M", "G", "GG"};
        if (find(sizes.begin(), sizes.end(), size) == sizes.end()) {
            cout << "fail: Valor inválido, tente PP, P, M, G, GG ou XG" << endl;
            return;
        }
        this->size = size;
    }
    string getSize() const {
        return this->size;
    }

    string str() const {
        return "size: (" + this->size + ")";
    }
};
// @KEEP
int main() {
    // CRIE SEU OBJETO AQUI
    // @DROP
    Roupa roupa;
    // @KEEP
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "size") { // TENTE ATRIBUIR UM TAMANHO
            // @COM
            string size;
            ss >> size;
            // @DROP
            roupa.setSize(size);
        } else if (cmd == "show") { // MOSTRE AS INFORMAÇÕES DO OBJETO
            // @DROP
            cout << roupa.str() << endl;
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: Comando inválido" << endl;
        }
    }
}