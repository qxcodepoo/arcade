#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <iomanip>
#include <sstream>

using namespace std;

// @DROP

// excessão lançada em quaisquer erros relacionados à conta
class AccountException : public runtime_error {
public:
    AccountException(const string& message) : runtime_error(message) {}
};

class Account {
protected:
    int id;
    double balance;
    string clientId;
    string type; // CC ou CP

public:
    Account(int id, const string& clientId) : id(id), balance(0), clientId(clientId) {}

    // Método abstrato
    virtual void monthlyUpdate() = 0;

    // saque
    virtual void withdraw(double value) {
        if (balance >= value)
            balance -= value;
        else
            throw AccountException("fail: saldo insuficiente");
    }

    // depósito
    virtual void deposit(double value) {
        balance += value;
    }

    // transferência para outra conta
    virtual void transfer(Account& other, double value) {
        this->withdraw(value);
        other.deposit(value);
    }

    virtual string toString() const {
        stringstream ss;
        ss << id << ":" << clientId << ":" << fixed << setprecision(2) << balance << ":" << type;
        return ss.str();
    }

    // GETs
    int getId() const { return id; }
    double getBalance() const { return balance; }
    string getClientId() const { return clientId; }
    string getType() const { return type; }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(int id, const string& clientId) : Account(id, clientId) {
        type = "CC";
    }

    // retira 20 do saldo
    void monthlyUpdate() override {
        balance -= 20;
    }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(int id, const string& clientId) : Account(id, clientId) {
        type = "CP";
    }

    // aumenta saldo em 1%
    void monthlyUpdate() override {
        balance *= 1.01;
    }
};

class Client {
private:
    string clientId;
    vector<shared_ptr<Account>> accounts;

public:
    Client(const string& clientId) : clientId(clientId) {}

    void addAccount(shared_ptr<Account> account) {
        for (const auto& acc : accounts) {
            if (acc->getId() == account->getId())
                return;
        }
        accounts.push_back(account);
    }

    string toString() const {
        stringstream ss;
        ss << clientId << " [";
        for (size_t i = 0; i < accounts.size(); ++i) {
            if (i > 0) ss << ", ";
            ss << accounts[i]->getId();
        }
        ss << "]";
        return ss.str();
    }

    // GETs
    string getClientId() const { return clientId; }
    const vector<shared_ptr<Account>>& getAccounts() const { return accounts; }
};

class BankAgency {
private:
    map<string, shared_ptr<Client>> clients;
    map<int, shared_ptr<Account>> accounts;
    int nextAccountId = 0;

    // obtém conta ou lança exceção
    shared_ptr<Account> getAccount(int id) {
        auto it = accounts.find(id);
        if (it == accounts.end())
            throw AccountException("fail: conta nao encontrada");
        return it->second;
    }

public:
    BankAgency() = default;

    // adiciona cliente com contas
    void addClient(const string& clientId) {
        if (clients.find(clientId) == clients.end()) {
            auto client = make_shared<Client>(clientId);
            auto cc = make_shared<CheckingAccount>(nextAccountId++, clientId);
            auto cp = make_shared<SavingsAccount>(nextAccountId++, clientId);

            accounts[cc->getId()] = cc;
            accounts[cp->getId()] = cp;

            client->addAccount(cc);
            client->addAccount(cp);
            clients[clientId] = client;
        }
    }

    // realiza saque
    void withdraw(int accountId, double value) {
        getAccount(accountId)->withdraw(value);
    }

    // realiza depósito
    void deposit(int accountId, double value) {
        getAccount(accountId)->deposit(value);
    }

    // realiza transferência
    void transfer(int accountIdFrom, int accountIdTo, double value) {
        getAccount(accountIdFrom)->transfer(*getAccount(accountIdTo), value);
    }

    // aplica atualização mensal
    void monthlyUpdate() {
        for (auto& [id, account] : accounts) {
            account->monthlyUpdate();
        }
    }

    string toString() const {
        stringstream ss;
        ss << "- Clients\n";
        for (const auto& [id, client] : clients) {
            ss << client->toString() << "\n";
        }
        ss << "- Accounts\n";
        for (const auto& [id, account] : accounts) {
            ss << account->toString() << "\n";
        }
        return ss.str();
    }
};

// @KEEP

int main() {
    BankAgency agency; // @DROP
    string line;

    while (getline(cin, line)) {
        try {
            istringstream iss(line);
            string cmd;
            iss >> cmd;
            cout << "$" << line << endl;

            if (cmd == "end") {
                break;
            } else if (cmd == "show") {
                // @DROP
                cout << agency.toString();
            } else if (cmd == "addCli") {
                // @COM
                string clientId;
                iss >> clientId;
                // @DROP
                agency.addClient(clientId);
            } else if (cmd == "saque") {
                // @COM
                int accountId;
                double value;
                iss >> accountId >> value;
                // @DROP
                agency.withdraw(accountId, value);
            } else if (cmd == "deposito") {
                // @COM
                int accountId;
                double value;
                iss >> accountId >> value;
                // @DROP
                agency.deposit(accountId, value);
            } else if (cmd == "transf") {
                // @COM
                int accountIdFrom, accountIdTo;
                double value;
                iss >> accountIdFrom >> accountIdTo >> value;
                // @DROP
                agency.transfer(accountIdFrom, accountIdTo, value);
            } else if (cmd == "update") {
                // @DROP
                agency.monthlyUpdate();
            } else {
                cout << "fail: comando invalido" << endl;
            }
        } catch (const exception& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
