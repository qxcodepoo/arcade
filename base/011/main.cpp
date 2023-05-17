#include <fn.hpp>
#include <iomanip>
#include <utility>

class Slot {
    std::string name;
    double price;
    int qtd;
public:
    Slot(std::string name = "empty", double price = 0.0, int qtd = 0) {
        this->name = name;
        this->price = price;
        this->qtd = qtd;
    }
    int getQtd() {
        return this->qtd;
    }
    double getPrice() {
        return this->price;
    }
    void setQtd(int qtd) {
        this->qtd = qtd;
    }
    std::string getName() {
        return this->name;
    }
    std::string str() {
        return "[{>8} :{>2} U : {.2f} RS]" | fn::FORMAT(this->name, this->qtd, this->price);
    }
};

class Machine {
    std::vector<Slot> espirais;
    double saldo;
public:
    Machine(int qtd = 0): espirais(qtd) {
    }

    void setSlot(int index, std::string nome, int qtd, double value) {
        if (!validarIndex(index))
            return;
        espirais[index] = Slot(nome, value, qtd);
    }

    bool validarIndex(int index) {
        if (index < (int) espirais.size() && index >= 0)
            return true;
        fn::write("fail: indice nao existe");
        return false;
    }

    void dinheiro(double value) {
        saldo += value;
    }

    double pegarTroco() {
        return std::exchange(saldo, 0);
    }

    void limpar(int index) {
        if (!validarIndex(index))
            return;
        espirais[index] = Slot();
    }

    void comprar(int index) {
        if (!validarIndex(index))
            return;
        if (espirais[index].getQtd() == 0) {
            fn::write("fail: espiral sem produtos");
            return;
        }
        if (espirais[index].getPrice() > saldo) {
            fn::write("fail: saldo insuficiente");
            return;
        }
        saldo -= espirais[index].getPrice();
        espirais[index].setQtd(espirais[index].getQtd() - 1);
        fn::write("voce comprou um " + espirais[index].getName());
    }

    std::string str() {
        return fn::format("saldo: {.2f}\n{}", this->saldo,
            espirais | fn::ENUMERATE() | fn::MAP([](auto e) {
                return fn::format("{} {}", std::get<0>(e), std::get<1>(e).str());})
                | fn::JOIN("\n"));
    }
};

std::ostream& operator<<(std::ostream& os, Slot slot) {
    return os << slot.str();
}

std::ostream& operator<<(std::ostream& os, Machine machine) {
    return os << machine.str();
}

int main() {
    Machine machine(0);
    while (true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);

        if (args[0] == "end") {
            break;
        } else if (args[0] == "init") {
            machine = Machine(+args[1]);
        } else if (args[0] == "show") {
            fn::write(machine);
        } else if (args[0] == "set") {
            machine.setSlot(+args[1], args[2], +args[3], +args[4]);
        } else if (args[0] == "limpar") {
            machine.limpar(+args[1]);
        } else if (args[0] == "dinheiro") {
            machine.dinheiro(+args[1]);
        } else if (args[0] == "comprar") {
            machine.comprar(+args[1]);
        } else if (args[0] == "troco") {
            fn::write(fn::format("voce recebeu {%.2f} RS", machine.pegarTroco()));
        } else {
            fn::write("fail: comando invalido");
        }
    }
}
