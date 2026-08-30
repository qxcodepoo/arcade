#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

class Fone{
public:
    string id;
    string number;

    Fone(string serial = ""){
        stringstream ss(serial);
        getline(ss, this->id, ':');
        ss >> this->number;
    }
    
    Fone(string id, string number){
        this->id = id;
        this->number = number;
    }

    static bool validar(string number){
        string valid = "0123456789()-.";
        for(char c : number)
            if(valid.find(c) == string::npos)
                return false;
        return true;
    }
    friend ostream& operator<<(ostream& out, const Fone& fone){
        out << fone.id << ":" << fone.number;
        return out;
    }
};

class Contact {
public:
    string id;
    vector<Fone> fones;
    bool starred;
    int calls;

    Contact(string id = string(""), vector<Fone> fones= {}) : 
        id{id}, fones{fones}, starred{false}, calls{0} {
    }

    void addFone(Fone fone){
        fones.push_back(fone);
    }

    void rmFone(int index){
        fones.erase(fones.begin() + index);
    }

    vector<Fone> getAllFones(){
        return fones;
    }

    bool matchNumber(string number){
        for(Fone fone : fones)
            if(fone.number == number)
                return true;
        return false;
    }

    void increaseCallCount(){
        this->calls += 1;
    }

    friend ostream& operator<<(ostream& out, Contact contact){
        out << (contact.starred ? "@ " : "- ");
        out << contact.id;
        if(contact.calls > 0)
            out << " {" << contact.calls << " call}";
        int i = 0;
        for(auto fone: contact.fones)
            out << " [" << i++ << ":" << fone << "]";
        return out;
    }
};

template <class T>
string toString(T t){
    stringstream ss;
    ss << t;
    return ss.str();
}

#include <algorithm>

class Agenda {
    map<string, Contact*> contacts; //vetor
    map<string, Contact*> bookmarks;

public:
    ~Agenda(){
        for(auto& par : contacts)
            delete par.second;
    }

    void addContact(string id, vector<Fone> fones){
        if(contacts.count(id) == 1){
            for(auto fone : fones)
                contacts[id]->addFone(fone);
            return;
        }
        contacts[id] = new Contact(id, fones);
    }

    void rmContact(string nome) {
        auto contact = getContact(nome);
        if(contact != nullptr){
            contacts.erase(nome);
            bookmarks.erase(nome);
            delete contact;
        }
    }

    Contact * getContact(string nome){
        auto it = contacts.find(nome);
        if(it == contacts.end())
            return nullptr;
        return it->second;
    }

    void star(string nome) {
        Contact * contact = getContact(nome);
        if(contact == nullptr){
            throw "fail: contato " + nome + " nao existe";
            return;
        }
        if(contact->starred)
            return;
        contact->starred = true;
        bookmarks[nome] = contact;
    }

    void unstar(string nome){
        if(bookmarks.count(nome) == 0)
            return;
        bookmarks[nome]->starred = false;
        bookmarks.erase(nome);
    }

    vector<Contact> getStarred(){
        vector<Contact> resp;
        for(auto par : bookmarks)
            resp.push_back(*par.second);
        return resp;
    }

    vector<Contact*> getContacts(){
        vector<Contact*> resp;
        for(auto par : contacts)
            resp.push_back(par.second);
        return resp;
    }

    vector<Contact> search(string pattern){
        vector<Contact> resp;
        for(auto par : contacts){
            if(toString(*par.second).find(pattern) != string::npos)
                resp.push_back(*par.second);
        }
        return resp;
    }
};


class CallManager{
    Agenda & agenda;
    CallManager(Agenda & ag): agenda{ag}{
    }

    vector<Contact*> searchByNumber(string number){
        vector<Contact*> output;
        for(Contact * contact : agenda.getContacts())
            if(contact->matchNumber(number))
                output.push_back(contact);
        return output;
    }

    void call(string number){
        auto matches = searchByNumber(number);
        if(matches.size() > 0)
            matches[0]->increaseCallCount();
        
    }
}

Fone format_fone(string sfone){
    stringstream ss(sfone);
    string id, fone;
    getline(ss, id, ':');
    ss >> fone;
    return Fone(id, fone);
}

template <class T>
T get(stringstream& ss){
    T value;
    ss >> value;
    return value;
}

int main(){
    Agenda agenda;
    while(true){
        string line, cmd;
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;
        cout << "$" << line << endl;
        try{
            if(cmd == "end"){
                break;
            }else if(cmd == "add"){ //id label-fone label-fone label-fone
                string name = get<string>(ss);
                vector<Fone> fones;
                string fonestr;
                while(ss >> fonestr)
                    fones.push_back(format_fone(fonestr));
                agenda.addContact(name, fones);
            }else if(cmd == "rmContact"){
                agenda.rmContact(get<string>(ss));
            }else if(cmd == "rmFone"){
                Contact * cont = agenda.getContact(get<string>(ss));
                cont->rmFone(get<int>(ss));
            }else if(cmd == "show"){
                for(auto elem : agenda.getContacts())
                    cout << elem << "\n";
            }else if(cmd == "search"){
                for(auto elem : agenda.search(get<string>(ss)))
                    cout << elem << "\n";
            }else if(cmd == "star"){
                agenda.star(get<string>(ss));
            }else if(cmd == "unstar"){
                agenda.unstar(get<string>(ss));
            }else if(cmd == "starred"){
                for(auto elem : agenda.getStarred())
                    cout << elem << "\n";
            }else{
                cout << "fail: comando invalido\n";
            }
        }catch(string e){
            cout << e << endl;
        }
    }
}