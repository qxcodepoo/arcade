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
        return 0;
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
    std::vector<Client> alive_list;

    //nome não precisa ser único na lista de clientes mortos
    //ordenado pela data da morte
    std::vector<Client> death_list;

    //as transações dos vivos
    std::vector<std::shared_ptr<Operation>> alive_oper;
    //as transações dos mortos
    std::vector<std::shared_ptr<Operation>> death_oper;
        
    //guarda o id da próxima transação
    int nextOpId = 0;

    //retorna a posição desse cliente no vetor de vivos ou -1 se não existir
    int searchClient(std::string name) {
        (void) name;
        return -1;
    }

    //cria uma transação com o próximo id e adiciona no vetor de transações
    //a transação deve ter o nome do cliente, o label e o valor
    //o MESMO objeto operaçao deve ser adicionado no vetor de operações do cliente
    //e no vetor de operações do agiota
    //incrementa o id da próxima transação
    void pushOperation(Client& cli, Label label, int value) {
        (void) cli;
        (void) label;
        (void) value;
    }

public:
    Agiota() {
    }

    //usa a função search, se encontrar o cliente, retorne o ponteiro para ele
    //se não encontrar emite a mensagem de erro
    //e retorne nullptr
    Client* getClient(std::string name) {
        (void) name;
        return nullptr;
    }

    // utilize a função search para verificar se o cliente existe
    // se ja existir, informe o erro
    // se não existir, crie um novo cliente e adicione no vetor de vivos
    // depois ordene o vetor de vivos pelo nome
    void addClient(std::string name, int limite) {
        (void) name;
        (void) limite;
    }

    //use a função getClient para verificar se o cliente existe
    //e emitir o erro caso não exista
    //se existir, verifique se ainda é possível conceder esse valor
    //sem que o cliente fique devendo mais do que o limite
    //se for possível chame o método pushOperation do Agiota
    //passando esse cliente, o label GIVE e o valor
    void give(std::string name, int value) {
        (void) name;
        (void) value;
    }


    //use a função getClient para verificar se o cliente existe
    //e emitir o erro caso não exista
    //se existir, chame o método pushOperation do Agiota
    void take(std::string name, int value) {
        (void) name;
        (void) value;
    }

    //atenção a problemas de concorrência
    //navegue por todos os clientes vivos
    //obtenha o balance de cada um
    //adicione uma operação de PLUS para cada cliente
    //com valor igual a 10% do balance atual
    //arredonde para cima as moedas.
    //atenção na hora de fazer as divisões e conversões
    //depois de adicionar as operações de PLUS
    //verifique se algum cliente ficou devendo mais do que o limite
    //se ficou, chame o método kill
    //lembre que você pode ter problemas de concorrência
    //se tentar percorrer uma lista ao mesmo tempo que tenta modificá-la
    void plus() {
    }

    //use a função search para verificar se o cliente existe
    //se não existir emita a mensagem de erro
    //se existir, remova o cliente do vetor de vivos
    //e adicione no final do vetor de mortos
    //percorra o vetor de transações e remova todas as transações
    //do cliente morto e adicione no vetor de transações dos mortos
    //lembre que você pode ter problemas de concorrência
    //pesquise como fazer isso
    void kill(std::string name) {
        (void) name;
    }

    std::string str() {
        std::stringstream ss;
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


