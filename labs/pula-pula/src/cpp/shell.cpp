#include <iostream>
#include <memory>
#include <sstream>
#include <list>
using namespace std;

template<class CONTAINER, class FUNC>
string map_join(const CONTAINER& c, FUNC f, string sep) {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); it++) {
        ss << (it == c.begin() ? "" : sep);
        ss << f(*it);
    }
    return ss.str();
}

// @DROP

class Kid {
private:
    int age;
    std::string name;
public:
    Kid(std::string name, int age) {
        this->age = age;
        this->name = name;
    }
    int getAge() const {
        return age;
    }
    std::string getName() const {
        return name;
    }
    std::string str() const {
        return name + ":" + std::to_string(age);
    }
};

class Trampoline {
    std::list<shared_ptr<Kid>> waiting;
    std::list<shared_ptr<Kid>> playing;
    
    shared_ptr<Kid> removeFromList(std::string name, std::list<shared_ptr<Kid>>& lista) {
        for(auto it = lista.begin(); it != lista.end(); it++) {
            if((*it)->getName() == name) {
                auto kid = *it;
                lista.erase(it);
                return kid;
            }
        }
        return nullptr;
    }

public:
    Trampoline() {
    }
    
    void arrive(shared_ptr<Kid> kid) {
        waiting.push_front(kid);
    }

    void enter() {
        if (waiting.size() == 0) {
            return;
        }
        playing.push_front(waiting.back());
        waiting.pop_back();
    }

    void leave() {
        if (playing.size() == 0) {
            return;
        }
        waiting.push_front(playing.back());
        playing.pop_back();
    }

    shared_ptr<Kid> removeKid(std::string name) {
        auto kid = removeFromList(name, waiting);
        if(kid != nullptr) {
            return kid;
        }
        kid = removeFromList(name, playing);
        if(kid != nullptr) {
            return kid;
        }
        return nullptr;
    }

    std::string str() const {
        auto fn = [](shared_ptr<Kid> kid) { return kid->str(); };
        auto waiting = map_join(this->waiting, fn, ", ");
        auto playing = map_join(this->playing, fn, ", ");
        return "[" + waiting + "] => [" + playing + "]";
    }
};

// @KEEP

int main() {
    // @DROP
    Trampoline trampoline;
    // @KEEP

    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } else if (cmd == "show") {
            // @DROP
            cout << trampoline.str() << endl;
        } else if (cmd == "arrive") {
            // @COM
            string name;
            int age;
            ss >> name >> age;
            // @DROP
            trampoline.arrive(make_shared<Kid>(name, age));
        } else if (cmd == "enter") {
            // @DROP
            trampoline.enter();
        } else if (cmd == "leave") {
            // @DROP
            trampoline.leave();
        } else if (cmd == "remove") {
            // @COM
            string name;
            ss >> name;
            // @DROP
            auto kid = trampoline.removeKid(name);
            if(kid == nullptr) {
                cout << "fail: " << name << " nao esta no pula-pula" << endl;
            }
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}