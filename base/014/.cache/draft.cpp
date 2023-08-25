#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp


class Fone{
    std::string id;
    std::string number;
public:
    Fone(std::string id = "", std::string number= "");
    std::string getId();
    std::string getNumber();
    bool isValid();
    std::string str();
    }   
};

class Contact{
    std::string name;
    bool favorited;
    std::vector<Fone> fones;
public:
    Contact(std::string name = "");

    std::string getName();

    std::vector<Fone> getFones();

    void addFone(std::string id, std::string number);

    void rmFone(int index);

    void toogleFavorited();

    bool isFavorited();

    std::string str();
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