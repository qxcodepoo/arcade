#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

template <typename CONTAINER, typename FUNC>
string map_join(const CONTAINER& cont, FUNC func, string sep = " ") {
    stringstream ss;
    for (auto it = cont.begin(); it != cont.end(); it++) {
        ss << (it == cont.begin() ? "" : sep);
        ss << func(*it);
    }
    return ss.str();
}

// @DROP

class Fone{
    std::string id;
    std::string number;
public:
    Fone(std::string id = "", std::string number= "") {
        this->id = id;
        this->number = number;
    }
    std::string getId() {
        return id;
    }
    std::string getNumber() {
        return number;
    }
    bool isValid() {
        std::string valid = "0123456789()-.";
        for(char c : number)
            if(valid.find(c) == std::string::npos)
                return false;
        return true;
    }
    std::string str() {
        return id + ":" + number;
    }   
};

class Contact{
    std::string name;
    bool favorited;
    std::vector<Fone> fones;
public:
    Contact(std::string name = ""):
        name(name), favorited{false} {
    }

    std::string getName() {
        return name;
    }

    std::vector<Fone> getFones() {
        return fones;
    }

    void addFone(std::string id, std::string number) {
        Fone fone(id, number);
        if(fone.isValid()) {
            fones.push_back(Fone(id, number));
        } else {
            cout << "fail: invalid number" << endl;
        }
    }

    void rmFone(int index) {
        if(index < 0 || index >= (int) fones.size())
            return;
        fones.erase(fones.begin() + index);
    }

    void toogleFavorited() {
        this->favorited = !this->favorited;
    }

    bool isFavorited() {
        return favorited;
    }

    std::string str() {
        stringstream ss;
        ss << (favorited ? "@" : "-") << " " << name << " [" << map_join(fones, [](Fone fone) { return fone.str(); }, ", ") << "]";
        return ss.str();
    }
};


class Agenda {
    std::vector<Contact> contatos;

    int findContact(std::string id) {
        for(int i = 0; i < (int) contatos.size(); i++)
            if(contatos[i].getName() == id)
                return i;
        return -1;
    }

public:
    //add contato que não existe ou adicionar fones ao contato que existe
    void addContato(std::string name, std::vector<Fone> fones) {
        int ind = findContact(name);
        if(ind == -1) {
            contatos.push_back(Contact(name));
            std::sort(contatos.begin(), contatos.end(), [](auto a, auto b) {
                return a.getName() < b.getName();
            });
            ind = findContact(name);
        }
        for(Fone fone : fones) {
            contatos[ind].addFone(fone.getId(), fone.getNumber());
        }
    }

    void rmContact(std::string name) {
        int ind = findContact(name);
        if(ind != -1) {
            contatos.erase(contatos.begin() + ind);
        }
    }

    Contact * getContact(std::string id) {
        int ind = findContact(id);
        if(ind != -1)
            return &contatos[ind];
        return nullptr;
    }

    std::vector<Contact> getContatos() {
        return contatos;
    }

    std::vector<Contact> search(std::string pattern) {
        std::vector<Contact> resp;
        for(auto elem : contatos) {
            if(elem.str().find(pattern) != std::string::npos)
                resp.push_back(elem);
        }
        return resp;
    }

    std::vector<Contact> getFavorited() {
        vector<Contact> resp;
        for(auto elem : contatos) {
            if(elem.isFavorited())
                resp.push_back(elem);
        }
        return resp;
    }

    std::string str() {
        return map_join(contatos, [](Contact contato) { return contato.str(); }, "\n");
    }
};


// @KEEP
pair<string, string> decodeFone(string fone) {
    stringstream ss(fone);
    string id, number;
    getline(ss, id, ':');
    getline(ss, number);
    return {id, number};
}

int main() {
    // @DROP
    Agenda agenda;
    // @KEEP
    while(true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if(cmd == "end") {
            break;
        } else if(cmd == "add") {//name id:fone id:fone ...
            // @COM
            string name;
            ss >> name;
            vector<Fone> fones;
            string token;
            while(ss >> token) {
                auto [id, number] = decodeFone(token);
                fones.push_back(Fone(id, number));
            }
            // @DROP
            agenda.addContato(name, fones);
        } else if(cmd == "show") {
            // @DROP
            cout << agenda.str() << endl;
        } else if(cmd == "rmFone") {//id index
            // @COM
            string name;
            int index;
            ss >> name >> index;
            // @DROP
            Contact * contato = agenda.getContact(name);
            if(contato != nullptr)
                contato->rmFone(index);
        } else if(cmd == "rm") {//id
            // @COM
            string name;
            ss >> name;
            // @DROP
            agenda.rmContact(name);
        } else if(cmd == "tfav") {//id 1 ou 0
            // @COM
            string name;
            ss >> name;
            // @DROP
            Contact * contato = agenda.getContact(name);
            if(contato != nullptr)
                contato->toogleFavorited();
        } else if(cmd == "favs") {
            // @DROP
            cout << map_join(agenda.getFavorited(), [](Contact contato) { return contato.str(); }, "\n") << endl;
        } else if(cmd == "search") {//pattern
            // @COM
            string pattern;
            ss >> pattern;
            // @DROP
            cout << map_join(agenda.search(pattern), [](Contact contato) { return contato.str(); }, "\n") << endl;
        } else{
            cout << "fail: comando invalido" << endl;
        }
    }
}
