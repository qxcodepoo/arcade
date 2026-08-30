#include <sstream>
#include <iostream>
using namespace std;

template <typename CONTAINER, typename FN>
string map_join(const CONTAINER& container, FN fn, string sep = ", ") {
    stringstream ss;
    for (auto it = container.begin(); it != container.end(); ++it) {
        ss << (it != container.begin() ? sep : "") << fn(*it);
    }
    return ss.str();
}

// @DROP

#include <memory>
#include <algorithm>
#include <vector>
#include <cmath>

enum Label {
    GIVE, TAKE, PLUS
};

ostream& operator<<(ostream& os, Label label) {
    switch (label) {
        case GIVE: os << "give"; break;
        case TAKE: os << "take"; break;
        case PLUS: os << "plus"; break;
    }
    return os;
}

class Operation {
    int id;           //id único da transação
    string name; //id único do cliente
    Label label;      //label da operação
    int value;        //valores são sempre positivo  
public:

    Operation(int id, string name, Label label, int value) {
        this->id    = id;
        this->name  = name;
        this->label = label;
        this->value = value;
    }

    string getName() {
        return name;
    }

    Label getLabel() {
        return label;
    }

    int getValue() {
        return value;
    }

    string str() {
        stringstream ss;
        ss << "id:" << id << " " << label << ":" << name << " " << value;
        return ss.str();
    }
};

class Client {
    string name; // nome do cliente
    int limite;    // o maximo que ele pode ficar devendo
    vector<shared_ptr<Operation>> operations; //dívidas e pagamentos 
public:

    Client(string name = "", int limite = 0) {
        this->name = name;
        this->limite = limite;
    }
    string getName() {
        return name;
    }
    int getLimite() {
        return limite;
    }
    int getBalance() {
        int balance {0};
        for (auto tr : operations) {
            if (tr->getLabel() != TAKE) {
                balance += tr->getValue();
            } else {
                balance -= tr->getValue();
            }
        }
        return balance;
    }

    void addOperation(shared_ptr<Operation> tr) {
        operations.push_back(tr);
    }

    vector<shared_ptr<Operation>> getOperations() {
        return this->operations;
    }

    string str() {
        stringstream ss;
        ss << name << " " << getBalance() << "/" << limite;
        return ss.str();
    }
};

class Agiota {
    vector<Client> alive_list;
    vector<Client> death_list;

    vector<shared_ptr<Operation>> alive_oper;
    vector<shared_ptr<Operation>> death_oper;
        
    int nextOpId = 0;

    int searchClient(string name) {
        for (size_t i = 0; i < alive_list.size(); i++)
            if (alive_list[i].getName() == name)
                return i;
        return -1;
    }

    void pushOperation(Client& cli, Label label, int value) {
        auto tr = make_shared<Operation>(nextOpId, cli.getName(), label, value);
        alive_oper.push_back(tr);
        cli.addOperation(tr);
        nextOpId++;
    }

public:
    Agiota() {
    }

    Client* getClient(string name) {
        auto index = searchClient(name);
        if (index != -1) 
            return &alive_list[index];
        cout << "fail: cliente nao existe\n";
        return nullptr;
    }

    void addClient(string name, int limite) {
        auto index = this->searchClient(name);
        if (index == -1) {
            alive_list.push_back(Client(name, limite));
            sort(alive_list.begin(), alive_list.end(), [](auto a, auto b) {
                return a.getName() < b.getName();
            });
            return;
        }
        cout << "fail: cliente ja existe\n";
    }

    void give(string name, int value) {
        auto cli = getClient(name);
        if (cli == nullptr)
            return;
        if(cli->getBalance() + value > cli->getLimite()){
            cout << "fail: limite excedido\n";
            return;
        }
        this->pushOperation(*cli, GIVE, value);
    }



    void take(string name, int value) {
        auto cli = getClient(name);
        if (cli == nullptr)
            return;
        this->pushOperation(*cli, TAKE, value);
    }

    //atenção a problemas de concorrência
    void plus() {
        for (auto & cli : alive_list) {
            double amount = 0.1;
            double bal = cli.getBalance();
            this->pushOperation(cli, PLUS, ceil(bal * amount));
        }
        vector<string> to_die;
        for (auto & cli : alive_list) {
            if (cli.getBalance() > cli.getLimite())
                to_die.push_back(cli.getName());
        }
        for (auto name : to_die)
            kill(name);
    }

    void kill(string name) {
        auto index = this->searchClient(name);
        if (index == -1) {
            cout << "fail: cliente nao existe\n";
            return;
        }
        death_list.push_back(alive_list[index]);
        alive_list.erase(alive_list.begin() + index);

        vector<shared_ptr<Operation>> remaining;
        for (auto tr : alive_oper) {
            if (tr->getName() == name) {
                death_oper.push_back(tr);
            } else {
                remaining.push_back(tr);
            }
        }
        alive_oper = remaining;
    }

    string str() {
        stringstream ss;
        for (auto cli : alive_list)
            ss << ":) " << cli.str() << '\n';
        for (auto tr : alive_oper)
            ss << "+ " << tr->str() << '\n';
        for (auto cli : death_list)
            ss << ":( " << cli.str() << '\n';
        for (auto tr : death_oper)
            ss << "- " << tr->str() << '\n';
        auto output = ss.str();
        if (output.back() == '\n')
            output.pop_back();
        return output;
    }
    
};
// @KEEP
int main() {
    // @DROP
    Agiota agiota;
    // @KEEP
    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if(cmd == "end") {
            break;
        }
        else if(cmd == "addCli") {
            // @COM
            string name;
            int limite {};
            ss >> name >> limite;
            // @DROP
            agiota.addClient(name, limite);
        }
        else if(cmd == "show") {
            // @DROP
            cout << agiota.str() << endl;
        }
        else if(cmd == "showCli") {
            // @COM
            string name;
            ss >> name;
            // @DROP
            auto cli = agiota.getClient(name);
            if (cli != nullptr) {
                cout << cli->str() << endl;
                cout << map_join(cli->getOperations(), [](auto tr) { return tr->str(); }, "\n") << endl;
            }
        }
        else if(cmd == "kill") {
            // @COM
            string name;
            ss >> name;
            // @DROP
            agiota.kill(name);
        }
        else if(cmd == "give") {
            // @COM
            string name;
            int value;
            ss >> name >> value;
            // @DROP
            agiota.give(name, value);
        }
        else if(cmd == "take") {
            // @COM
            string name;
            int value;
            ss >> name >> value;
            // @DROP
            agiota.take(name, value);
        }
        else if(cmd == "plus") {
            // @DROP
            agiota.plus();
        }
        else {
            cout << "fail: comando invalido\n";
        }
    }
}
