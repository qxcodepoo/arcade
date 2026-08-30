#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
#include <cmath>
#include <iomanip>
using namespace std;

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
    // vector<shared_ptr<Shape>> shapes;
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end")  { 
            break;                                  
        }
        else if (cmd == "show") { 
            // Imprima as formas, uma por linha
        }
        else if (cmd == "circle") { 
            // Crie um novo circulo e adicione ao vetor
            // double x{}, y{}, radius{};
            // ss >> x >> y >> radius;
        }
        else if (cmd == "rect") {
            // Crie um retangulo e insira no vetor
            // double x1{}, y1{}, x2{}, y2{};
            // ss >> x1 >> y1 >> x2 >> y2;
        }
        else if (cmd == "info") {
            // Imprima as informações de área e perímetro de todas as formas
        }
        else {
            cout << "fail: comando inválido" << '\n';
        }
    }
}
