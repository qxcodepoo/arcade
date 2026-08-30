#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// @DROP

class Veiculo {
protected:
    string id;
    string tipo;
    int entrada;

public:
    Veiculo(string id) : id(id), tipo(""), entrada(0) {}

    void setEntrada(int entrada) {
        this->entrada = entrada;
    }

    int getEntrada() const {
        return entrada;
    }

    string getTipo() const {
        return tipo;
    }

    string getId() const {
        return id;
    }

    virtual string toString() const {
        stringstream ss;
        ss << setw(10) << setfill('_') <<  tipo << " : " << setw(10) << setfill('_') << id << " : " << entrada;
        return ss.str();
    }

    virtual double calcularValor(int saida) const = 0;

    virtual ~Veiculo() = default;
};

class Bike : public Veiculo {
public:
    Bike(string id) : Veiculo(id) {
        tipo = "Bike";
    }

    double calcularValor(int saida) const override {
        (void) saida;
        return 3.0;
    }
};

class Moto : public Veiculo {
public:
    Moto(string id) : Veiculo(id) {
        tipo = "Moto";
    }

    double calcularValor(int saida) const override {
        int tempo = saida - entrada;
        return tempo / 20.0;
    }
};

class Carro : public Veiculo {
public:
    Carro(string id) : Veiculo(id) {
        tipo = "Carro";
    }

    double calcularValor(int saida) const override {
        int tempo = saida - entrada;
        return max(tempo / 10.0, 5.0);
    }
};

class Estacionamento {
private:
    vector<Veiculo*> veiculos;
    int tempo;

    int procurarVeiculo(const string& id) const {
        for (size_t i = 0; i < veiculos.size(); i++) {
            if (veiculos[i]->getId() == id) {
                return i;
            }
        }
        return -1;
    }

public:
    Estacionamento() : tempo(0) {}

    void estacionar(Veiculo* veiculo) {
        veiculo->setEntrada(tempo);
        veiculos.push_back(veiculo);
    }

    void pagar(const string& id) {
        int pos = procurarVeiculo(id);
        if (pos == -1) {
            cout << "fail: veiculo nao encontrado" << endl;
            return;
        }

        Veiculo* veiculo = veiculos[pos];
        cout << veiculo->getTipo() << " chegou " << veiculo->getEntrada() << " saiu " << tempo
             << ". Pagar R$ " << fixed << setprecision(2) << veiculo->calcularValor(tempo) << endl;
    }

    Veiculo* sair(const string& id) {
        int pos = procurarVeiculo(id);
        if (pos == -1) {
            cout << "fail: veiculo nao encontrado" << endl;
            return nullptr;
        }

        auto aux = veiculos[pos];
        veiculos.erase(veiculos.begin() + pos);
        return aux;
    }

    void passarTempo(int tempo) {
        this->tempo += tempo;
    }

    string str() const {
        string result;
        for (const auto& v : veiculos) {
            result += v->toString() + "\n";
        }
        result += "Hora atual: " + to_string(tempo);
        return result;
    }

    ~Estacionamento() {
        for (auto& veiculo : veiculos) {
            delete veiculo;
        }
    }
};

// @KEEP
int main() {
    // @DROP
    Estacionamento estacionamento;
    // @KEEP
    
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "show") {
            // @DROP
            cout << estacionamento.str() << endl;
        } else if (cmd == "estacionar") {
            // @COM
            string tipo, id;
            ss >> tipo >> id;
            // @DROP
            if (tipo == "bike") {
                estacionamento.estacionar(new Bike(id));
            } else if (tipo == "moto") {
                estacionamento.estacionar(new Moto(id));
            } else if (tipo == "carro") {
                estacionamento.estacionar(new Carro(id));
            }
        } else if (cmd == "tempo") {
            // @COM
            int tempo {};
            ss >> tempo;
            // @DROP
            estacionamento.passarTempo(tempo);
        } else if (cmd == "pagar") {
            // @COM
            string id;
            ss >> id;
            // @DROP
            estacionamento.pagar(id);
            auto aux = estacionamento.sair(id);
            if (aux != nullptr) {
                delete aux;
            }
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
