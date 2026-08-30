#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

template<typename CONTAINER, typename FUNC>
string join(const CONTAINER& cont, FUNC func, const string& delim) {
    stringstream ss;
    for (auto it = cont.begin(); it != cont.end(); it++) {
        ss << (it == cont.begin() ? "" : delim) << func(*it);
    }
    return ss.str();
}

// @DROP

class Label {
    string name;
public:
    static const Label WITHDRAW;
    static const Label DEPOSIT;
    static const Label FEE;
    static const Label REVERSE;
    static const Label OPENING;
    static const Label ERROR;

private:
    Label(string name) {
        this->name = name;        
    }
public:
    string getName() const {
        return this->name;
    }
    bool operator==(Label other) {
        return this->name == other.name;
    }
    bool operator!=(Label other) {
        return this->name != other.name;
    }
};

const Label Label::WITHDRAW = Label("withdraw");
const Label Label::DEPOSIT  = Label("deposit");
const Label Label::FEE      = Label("fee");
const Label Label::REVERSE  = Label("reverse");
const Label Label::OPENING  = Label("opening");
const Label Label::ERROR    = Label("error");


class Operation {
    int index;
    Label label;
    float value;
    float balance;
public:
    Operation(int index = 0, Label label = Label::ERROR, float value = 0, float balance = 0):
        index(index), label(label), value(value), balance(balance) {
    }

    Label getLabel() {
        return this->label;
    }
    float getValue() {
        return this->value;
    }
    float getBalance() {
        return this->balance;
    }
    int getIndex() {
        return this->index;
    }

    string str() const {
        stringstream ss;
        ss << setw(2) << index << ":" << setw(9) << label.getName() << ":" << setw(5) << value << ":" << setw(5) << balance;
        return ss.str();
    }
};

class BalanceManager {
    float balance {0};
    int nextOp {0};
    vector<Operation> extract;

public:
    void pushOperation(Label label, float value) {
        balance += value;
        extract.push_back(Operation(nextOp, label, value, balance));
        nextOp += 1;
    }

    Operation getOperation(int index) {
        if(index < 0 || index >= (int) extract.size()) {
            return Operation(0, Label::ERROR, 0, 0);
        }
        return extract.at(index);
    }

    float getBalance() const {
        return balance;
    }

    vector<Operation> getExtract(int qtd = 0) {
        int inicio = 0;
        if(qtd != 0) {
            inicio = extract.size() - qtd;
            if(inicio < 0) {
                inicio = 0;
            }
        }
        vector<Operation> extract;
        for (int i = inicio; i < (int) this->extract.size(); i++) {
            extract.push_back(this->extract[i]);
        }
        return extract;
    }
};

class Account{
    int number;
    BalanceManager manager;
public:
    Account(int number = 0):
        number(number) {
        manager.pushOperation(Label::OPENING, 0);
    }

    void deposit(float value) {
        if (value < 0) {
            cout << "fail: invalid value\n";
            return;
        }
        manager.pushOperation(Label::DEPOSIT, value);
    }

    void withdraw(float value) {
        if(value <= 0) {
            cout << "fail: invalid value\n";
            return;
        }
        if (manager.getBalance() < value) {
            cout << "fail: insufficient balance\n";
            return;
        }
        manager.pushOperation(Label::WITHDRAW, -value);
    }

    void fee(float value) {
        if(value <= 0) {
            cout << "fail: invalid value\n";
            return;
        }
        manager.pushOperation(Label::FEE, -value);
    }

    void reverse(int index) {
        auto op = manager.getOperation(index);
        if (op.getLabel() == Label::ERROR) {
            cout << "fail: index " << index << " invalid\n";
            return;
        }
        if(op.getLabel() != Label::FEE) {
            cout << "fail: index " << index << " is not a fee\n";
            return;
        }
        manager.pushOperation(Label::REVERSE, -op.getValue());
    }

    BalanceManager& getManager() {
        return manager;
    }

    string str() const {
        stringstream ss;
        ss << "account:" << this->number << " balance:" << this->manager.getBalance();
        return ss.str();
    }
};

// @KEEP
int main() {
    Account acc; // @DROP
    
    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        
        if (cmd == "end") {
            break;
        }
        else if (cmd == "init") {
            // @COM
            int number{};
            ss >> number;
            // @DROP
            acc = Account(number);
        }
        else if (cmd == "show") {
            // TODO
            // @DROP
            cout << acc.str() << endl;
        }
        else if (cmd == "deposit") {
            // @COM
            float value{};
            ss >> value;
            // @DROP
            acc.deposit(value);
        }
        else if (cmd == "withdraw") {
            // @COM
            float value{};
            ss >> value;
            // @DROP
            acc.withdraw(value);
        }
        else if (cmd == "fee") {
            // @COM
            float value{};
            ss >> value;
            // @DROP
            acc.fee(value);
        }
        else if (cmd == "extract") {
            // @COM
            int qtd{};
            ss >> qtd;
            // @DROP
            auto extract = acc.getManager().getExtract(qtd);
            cout << join(extract, [](Operation op) { return op.str(); }, "\n") << endl;
        }
        else if (cmd == "reverse") {
            // @COM
            int index{};
            while(ss >> index) {
                acc.reverse(index); // @DROP
            }
        }
        else {
            cout << "fail: invalid command\n";
        }
    }
    return 0;
}