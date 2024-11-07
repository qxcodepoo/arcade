#include <fn.hpp> // https://raw.githubusercontent.com/senapk/cppaux/master/fn.hpp
#include <algorithm>


class Fone{
    std::string id;
    std::string number;
public:
    Fone(std::string id = "", std::string number= "") {
    }
    std::string getId() {
    }
    std::string getNumber() {
    }
    bool isValid() {
    }
    std::string str() {
    }   
};

class Contact{
    std::string name;
    bool favorited;
    std::vector<Fone> fones;
public:
    Contact(std::string name = ""):
    }

    std::string getName() {
    }

    std::vector<Fone> getFones() {
    }

    void addFone(std::string id, std::string number) {
    }

    void rmFone(int index) {
    }

    void toogleFavorited() {
    }

    bool isFavorited() {
    }

    std::string str() {
    }
};





class Agenda {
    std::vector<Contact> contatos;

    int findContact(std::string id) {
    }

public:
    //add contato que não existe ou adicionar fones ao contato que existe
    void addContato(std::string name, std::vector<Fone> fones) {
    }

    void rmContact(std::string name) {
    }

    Contact * getContact(std::string id) {
    }

    std::vector<Contact> getContatos() {
    }

    std::vector<Contact> search(std::string pattern) {
    }

    std::vector<Contact> getFavorited() {
    }

    std::string str() {
    }
};


std::ostream& operator<<(std::ostream& out, Fone fone      ) { return out << fone.str();    }
std::ostream& operator<<(std::ostream& out, Contact contato) { return out << contato.str(); }
std::ostream& operator<<(std::ostream& out, Agenda agenda  ) { return out << agenda.str();  }

int main() {
    Agenda agenda;
    while(true) {
        auto line = fn::input();
        fn::write("$" + line);
        auto args = fn::split(line, ' ');
        if(args[0] == "end") {
            break;
        }
        else if(args[0] == "add") {//name id:fone id:fone ...
            std::vector<Fone> fones;
            for (int i = 2; i < (int) args.size(); i++) {
                auto parts = fn::split(args[i], ':');
                fones.push_back(Fone(parts[0], parts[1]));
            }
            agenda.addContato(args[1], fones);
        }
        else if(args[0] == "show") {
            fn::write(agenda);
        }
        else if(args[0]== "rmFone") {//id index
            Contact * contato = agenda.getContact(args[1]);
            if(contato != nullptr)
                contato->rmFone((int) +args[2]);
        }
        else if(args[0] == "rm") {//id
            agenda.rmContact(args[1]);
        }
        else if(args[0] == "tfav") {//id 1 ou 0
            Contact * contato = agenda.getContact(args[1]);
            if(contato != nullptr)
                contato->toogleFavorited();
        }
        else if(args[0] == "favs") {
            agenda.getFavorited() | fn::JOIN("\n") | fn::WRITE();
        }
        else if(args[0] == "search") {//pattern
            agenda.search(args[1]) | fn::JOIN("\n") | fn::WRITE();
        }
        else{
            fn::write("fail: comando invalido");
        }
    }
}