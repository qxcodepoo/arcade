#include <fn.hpp>
#include <algorithm>
#include <cmath>

enum Label {
    GIVE, TAKE, PLUS
};

std::ostream& operator<<(std::ostream& os, Label label) {
    switch (label) {
        case GIVE: os << "give"; break;
        case TAKE: os << "take"; break;
        case PLUS: os << "plus"; break;
    }
    return os;
}

class Operation {
    int id;           //id único da transação
    std::string name; //id único do cliente
    Label label;      //label da operação
    int value;        //valores são sempre positivo  
public:

    Operation(int id, std::string name, Label label, int value) {
        this->id    = id;
        this->name  = name;
        this->label = label;
        this->value = value;
    }

    std::string getName() {
        return name;
    }

    Label getLabel() {
        return label;
    }

    int getValue() {
        return value;
    }

    std::string str() {
        return "id:{} {}:{} {}" | fn::FORMAT(id, label, name, value);
    }
};

std::ostream& operator<<(std::ostream& os, Operation tr) {
    return os << tr.str();
}

class Client {
    std::string name; // nome do cliente
    int limite;    // o maximo que ele pode ficar devendo
    std::vector<std::shared_ptr<Operation>> operations; //dívidas e pagamentos 
public:

    Client(std::string name = "", int limite = 0) {
        this->name = name;
        this->limite = limite;
    }
    std::string getName() {
        return name;
    }
    int getLimite() {
        return limite;
    }
    //o quanto ele deve ao agiota
    // soma todas as operações de GIVE e PLUS
    // e subtrai todas as operações de TAKE 
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

    void addOperation(std::shared_ptr<Operation> tr) {
        operations.push_back(tr);
    }

    std::vector<std::shared_ptr<Operation>> getOperations() {
        return this->operations;
    }

    std::string str() {
        return "{} {}/{}" | fn::FORMAT(name, getBalance(), limite);
    }
};
std::ostream& operator<<(std::ostream &os, Client cliente) {
    return os << cliente.str();
}



class Agiota {
    //ordenado por nome do cliente
    //nome deve ser único
    std::map<std::string, Client> alive_list;

    //nome não precisa ser único na lista de clientes mortos
    //ordenado pela data da morte
    std::vector<Client> death_list;

    //as transações dos vivos
    std::vector<std::shared_ptr<Operation>> alive_oper;
    //as transações dos mortos
    std::vector<std::shared_ptr<Operation>> death_oper;
        
    //guarda o id da próxima transação
    int nextOpId = 0;

    //cria uma transação com o próximo id e adiciona no vetor de transações
    //a transação deve ter o nome do cliente, o label e o valor
    //o MESMO objeto operaçao deve ser adicionado no vetor de operações do cliente
    //e no vetor de operações do agiota
    //incrementa o id da próxima transação
    void pushOperation(Client& cli, Label label, int value) {
        auto tr = std::make_shared<Operation>(nextOpId, cli.getName(), label, value);
        alive_oper.push_back(tr);
        cli.addOperation(tr);
        nextOpId++;
    }

public:
    Agiota() {
    }


    Client* getClient(std::string name) {
	auto it = alive_list.find(name);
	if (it != alive_list.end()) {
	    return &it->second;
	}
        fn::write("fail: cliente nao existe");
        return nullptr;
    }

    // utilize a função search para verificar se o cliente existe
    // se ja existir, informe o erro
    // se não existir, crie um novo cliente e adicione no vetor de vivos
    // depois ordene o vetor de vivos pelo nome
    void addClient(std::string name, int limite) {
	auto it = alive_list.find(name);
	if (it == alive_list.end()) {
            alive_list[name] = Client(name, limite);
            return;
        }
        fn::write("fail: cliente ja existe");
    }

    void give(std::string name, int value) {
        auto cli = getClient(name);
        if (cli == nullptr)
            return;
        if(cli->getBalance() + value > cli->getLimite()){
            fn::write("fail: limite excedido");
            return;
        }
        this->pushOperation(*cli, GIVE, value);
    }



    void take(std::string name, int value) {
        auto cli = getClient(name);
        if (cli == nullptr)
            return;
        this->pushOperation(*cli, TAKE, value);
    }

    //atenção a problemas de concorrência
    void plus() {
        for (auto & [name, cli] : alive_list) {
            double amount = 0.1;
            double bal = cli.getBalance();
            this->pushOperation(cli, PLUS, ceil(bal * amount));
        }
        std::vector<std::string> to_die;
        for (auto & [name, cli] : alive_list) {
            if (cli.getBalance() > cli.getLimite())
                to_die.push_back(cli.getName());
        }
        for (auto name : to_die)
            kill(name);
    }

    void kill(std::string name) {
        auto cli = getClient(name);
        if (cli == nullptr) {
            fn::write("fail: cliente nao existe");
            return;
        }
        death_list.push_back(alive_list[name]);
        alive_list.erase(name);

        std::vector<std::shared_ptr<Operation>> remaining;
        for (auto tr : alive_oper) {
            if (tr->getName() == name) {
                death_oper.push_back(tr);
            } else {
                remaining.push_back(tr);
            }
        }
        alive_oper = remaining;
    }

    std::string str() {
        std::stringstream ss;
        for (auto &[key, cli] : alive_list)
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

std::ostream& operator<<(std::ostream& os, Agiota agiota) {
    return os << agiota.str();
}



int main() {
    Agiota agiota;
    while(true) {
        auto line = fn::input();
        auto args = fn::split(line, ' ');
        fn::write("$" + line);
        

        if(args[0] == "end") {
            break;
        } else if(args[0] == "addCli") {
            agiota.addClient(args[1], +args[2]);
        } else if(args[0] == "show") {
            agiota | fn::WRITE();
        } else if(args[0] == "showCli") {
            auto cli = agiota.getClient(args[1]);
            if (cli != nullptr) {
                cli->str() | fn::WRITE();
                cli->getOperations() | fn::JOIN("\n") | fn::WRITE();
            }
        } else if(args[0] == "kill") {
            agiota.kill(args[1]);
        } else if(args[0] == "give") {
            agiota.give(args[1], +args[2]);
        } else if(args[0] == "take") {
            agiota.take(args[1], +args[2]);
        } else if(args[0] == "plus") {
            agiota.plus();
        } else {
            fn::write("fail: comando invalido");
        }
    }
}


