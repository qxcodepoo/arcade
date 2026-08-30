#include <iostream>
#include <vector>
#include <sstream>
#include <memory>
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
struct Client {
    string id;
    string phone;

    Client(string id = "", string phone = "") {
        this->id = id;
        this->phone = phone;
    }
    string str() const {
        return id + ":" + phone;
    }
};

class Theater{
    vector<shared_ptr<Client>> seats;

    int search(string name) {
        for (int i = 0; i < (int) seats.size(); i++) {
            if (seats[i] != nullptr && seats[i]->id == name) {
                return i;
            }
        }
        return -1;
    }

public:
    Theater(int qtd = 0):
        seats(qtd, nullptr) {
    }


    void reserve(string id, string phone, int index) {
        int qtd = seats.size();
        if ((index < 0) || (index >= qtd)) {
            cout << "fail: cadeira nao existe" << endl;
            return;
        }
        if (seats[index] != nullptr) { 
            cout << "fail: cadeira ja esta ocupada" << endl;
            return;
        }
        if (search(id) != -1) {
            cout << "fail: cliente ja esta no cinema" << endl;
            return;
        }
        seats[index] = make_shared<Client>(id, phone);
    }

    void cancel(string id) {
        int index = search(id);
        if (index == -1) {
            cout << "fail: cliente nao esta no cinema" << endl;
            return;
        }
        seats[index] = nullptr;
    }

    string str() const {
        auto fn = [](auto c) { return (c == nullptr) ? "-" : c->str(); };
        auto data = map_join(seats, fn, " ");
        return "[" + data + "]";
    }
};

// @KEEP
int main() {
    // @DROP
    Theater adp;
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
            cout << adp.str() << endl;
        } else if (cmd == "init") {
            // @COM
            int qtd;
            ss >> qtd;
            // @DROP
            adp = Theater(qtd);
        } else if (cmd == "reserve") {
            // @COM
            string id, phone;
            int index;
            ss >> id >> phone >> index;
            // @DROP
            adp.reserve(id, phone, index);
        } else if (cmd == "cancel") {
            // @COM
            string id;
            ss >> id;
            // @DROP
            adp.cancel(id);
        } else {
            cout << "fail: comando invalido" << endl;
        }
    }
}
