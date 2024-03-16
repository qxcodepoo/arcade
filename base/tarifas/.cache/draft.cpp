#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <fn.hpp>


class Label {
    std::string name;
public:
    static const Label WITHDRAW;
    static const Label DEPOSIT;
    static const Label FEE;
    static const Label REVERSE;
    static const Label OPENING;
    static const Label ERROR;

private:
    Label(std::string name) {
    }
public:
    std::string getName() const {
    }
    bool operator==(Label other) {
    }
    bool operator!=(Label other) {
    }
};

std::ostream& operator<<(std::ostream& os, Label& label) {
    return os << label.getName();
}

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
    }

    Label getLabel() {
    }
    float getValue() {
    }
    float getBalance() {
    }
    int getIndex() {
    }
    std::string str() const {
        return fn::format("{>2}:{>9}:{>5}:{>5}", index, label.getName(), value, balance);
    }
};
std::ostream& operator<<(std::ostream& os, const Operation& op) {
    os << op.str();
    return os;
}

class BalanceManager {
    float balance {0};
    int nextOp {0};
    std::vector<Operation> extract;

public:
    void pushOperation(Label label, float value) {
    }

    Operation getOperation(int index) {
    }

    float getBalance() const {
    }

    std::vector<Operation> getExtract(int qtd = 0) {
    }
};

class Account{
    int number;
    BalanceManager manager;
public:
    Account(int number = 0):
    }
    void deposit(float value) {
        if (value < 0) {
            std::cout << "fail: invalid value\n";
            return;
        }
        manager.pushOperation(Label::DEPOSIT, value);
    }
    void withdraw(float value) {
    }

    void fee(float value) {
    }

    void reverse(int index) {
    }

    BalanceManager& getManager() {
    }

    std::string str() const {
    }
};

std::ostream &operator<<(std::ostream &os, const Account &acc) {
    os << acc.str();
    return os;
}



int main() {
    Account acc;
    
    while(true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);
        
        if (args[0] == "end") {
            break;
        } else if (args[0] == "init") {
            acc = Account((int)+args[1]);
        } else if (args[0] == "show") {
            fn::write(acc);
        } else if (args[0] == "deposit") {
            acc.deposit(+args[1]);
        } else if (args[0] == "withdraw") {
            acc.withdraw(+args[1]);
        } else if (args[0] == "fee") {
            acc.fee((int) +args[1]);
        } else if (args[0] == "extract") {
            auto extract = acc.getManager().getExtract(+args[1]);
            fn::write(fn::join(extract, "\n"));
        } else if (args[0] == "reverse") {
            for (int i = 1; i < (int) args.size(); i++) {
                acc.reverse((int) +args[i]);
            }
        } else {
            std::cout << "fail: invalid command\n";
        }
    }
    return 0;
}