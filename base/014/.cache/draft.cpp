#include <fn.hpp>


class Fone{
    std::string id;
    std::string number;
public:
    Fone(std::string id = "", std::string number= "") {
    }
    std::string getId() {
        return {}; // todo
    }
    std::string getNumber() {
        return {}; // todo
    }
    bool isValid() {
        return {}; // todo
    }
    std::string str() {
        return {}; // todo
    }   
};

class Contact{
    std::string name;
    bool favorited;
    std::vector<Fone> fones;
public:
    Contact(std::string name = "") { //todo
    }

    std::string getName() {
        return {}; // todo
    }

    std::vector<Fone> getFones() {
        return {}; // todo
    }

    void addFone(std::string id, std::string number) {
    }

    void rmFone(int index) {
    }

    void toogleFavorited() {
    }

    bool isFavorited() {
        return {}; // todo
    }

    std::string str() {
        return {}; // todo
    }
};

std::ostream& operator<<(std::ostream& out, Contact contato) { return out << contato.str(); }
std::ostream& operator<<(std::ostream& out, Fone fone      ) { return out << fone.str();    }


int main() {
    Contact contato;
    while(true) {
        auto line = fn::input();
        fn::write("$" + line);
        auto args = fn::split(line, ' ');

        if(args[0] == "end") {
            break;
        }
        else if(args[0] == "init") {//name
            contato = Contact(args[1]);
        }
        else if(args[0] == "add") {//id fone
            contato.addFone(args[1], args[2]);
        }
        else if(args[0] == "rm") {//id
            contato.rmFone(+args[1]);
        }
        else if(args[0] == "tfav") {
            contato.toogleFavorited();
        }
        else if(args[0] == "show") {
            fn::write(contato);
        }
        else{
            fn::write("fail: comando invalido");
        }
    }
}