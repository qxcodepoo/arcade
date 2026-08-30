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

// @DROP
#include <utility>

class Grafite{
    float calibre;
    string dureza;
    int tamanho;
public:
    Grafite(float calibre, string dureza, int tamanho) {
        this->calibre = calibre;
        this->dureza = dureza;
        this->tamanho = tamanho;
    }
    int desgastePorFolha() const {
        if (dureza == "HB")
            return 1;
        if (dureza == "2B")
            return 2;
        if (dureza == "4B")
            return 4;
        return 6;
    }
    float getCalibre() const {
        return calibre;
    }
    string getDureza() const {
        return dureza;
    }
    int getTamanho() const {
        return tamanho;
    }
    void setTamanho(int tamanho) {
        this->tamanho = tamanho;
    }
    string str() const {
        char buffer[256];
        sprintf(buffer, "%.1f:%s:%d", calibre, dureza.c_str(), tamanho);
        return buffer;
    }
};

using PGrafite = shared_ptr<Grafite>;


struct Lapiseira{
    float calibre {0.f};
    PGrafite tip {nullptr};
    list<PGrafite> tambor;

    Lapiseira(float calibre = 0.0):
        calibre{calibre} {
    }

    bool inserir(PGrafite tip) {

        if (this->calibre != tip->getCalibre()) {
            cout << "fail: calibre incompatível\n";
            return false;
        } else{
            this->tambor.push_back(tip);
            return true;
        }
        cout << "fail: ja existe grafite\n";
        return false;
    }

    PGrafite remover() {
        if (this->tip == nullptr) {
            cout << "fail: nao existe grafite no bico\n";
            return nullptr;
        }
        return exchange(this->tip, nullptr);
    }

    void writePage() {
        if (this->tip == nullptr) {
            cout << "fail: nao existe grafite no bico\n";
            return;
        }
        if (this->tip->getTamanho() == 10) {
            cout << "fail: tamanho insuficiente\n";
            return;
        }
        auto tamanho = this->tip->getTamanho();
        tamanho -= this->tip->desgastePorFolha();
        if (tamanho < 10) {
            cout << "fail: folha incompleta\n";
            this->tip->setTamanho(10);
            return;
        }
        this->tip->setTamanho(tamanho);
    }
    void puxar() {
        if (this->tambor.empty()) {
            cout << "fail: tambor vazio\n";
            return;
        }
        if (this->tip != nullptr) {
            cout << "fail: ja existe grafite no bico\n";
            return;
        }
        this->tip = this->tambor.front();
        this->tambor.pop_front();
    }

    static string fmt_lead(PGrafite g) {
        return g == nullptr ? "[]" : "[" + g->str() + "]";
    }

    string str() const {
        char buffer[256];
        auto grafites = map_join(tambor, fmt_lead, "");
        sprintf(buffer, "calibre: %.1f, bico: %s, tambor: <%s>", calibre, fmt_lead(tip).c_str(), grafites.c_str());
        return buffer;
    }
};

// @KEEP
int main() {
    // @DROP
    Lapiseira lapiseira(0.5);
    // @KEEP
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;  
        }
        else if (cmd == "show") { 
            // @DROP
            cout << lapiseira.str() << endl;
        } 
        else if (cmd == "init") { 
            // @COM
            float calibre;
            ss >> calibre;
            // @DROP
            lapiseira = Lapiseira(calibre);
        } 
        else if (cmd == "insert") { 
            // @COM
            float calibre;
            string dureza;
            int tamanho;
            ss >> calibre >> dureza >> tamanho;
            // @DROP
            lapiseira.inserir(make_shared<Grafite>(calibre, dureza, tamanho));
        } 
        else if (cmd == "remove") { 
            // @DROP
            lapiseira.remover();
        } 
        else if (cmd == "pull") { 
            // @DROP
            lapiseira.puxar();
        } 
        else if (cmd == "write") { 
            // @DROP
            lapiseira.writePage();
        } 
        else {
            cout << "fail: comando invalido\n";
        }
    }
}
