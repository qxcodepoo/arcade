#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

template <class CONTAINER, class FUNC>
string map_join(const CONTAINER &cont, FUNC func, string sep = " ")
{
    stringstream ss;
    for (auto it = cont.begin(); it != cont.end(); it++)
    {
        ss << (it == cont.begin() ? "" : sep) << func(*it);
    }
    return ss.str();
}
// @DROP

class Fone
{
    string id;
    string number;

public:
    Fone(string id = "", string number = "")
    {
        this->id = id;
        this->number = number;
    }
    string getId()
    {
        return id;
    }
    string getNumber() const
    {
        return number;
    }
    bool isValid() const
    {
        string valid = "0123456789()-.";
        for (char c : number)
            if (valid.find(c) == string::npos)
                return false;
        return true;
    }
    string str() const
    {
        return id + ":" + number;
    }
};

class Contact
{
    string name;
    bool favorited;
    vector<Fone> fones;

public:
    Contact(string name = "") : name(name), favorited{false}
    {
    }

    string getName()
    {
        return name;
    }

    vector<Fone> getFones()
    {
        return fones;
    }

    void addFone(string id, string number)
    {
        Fone fone(id, number);
        if (fone.isValid())
        {
            fones.push_back(Fone(id, number));
        }
        else
        {
            cout << "fail: invalid number" << endl;
        }
    }

    void rmFone(int index)
    {
        if (index < 0 || index >= (int)fones.size())
            return;
        fones.erase(fones.begin() + index);
    }

    void toogleFavorited()
    {
        this->favorited = !this->favorited;
    }

    bool isFavorited()
    {
        return favorited;
    }

    string str()
    {
        stringstream ss;
        ss << (favorited ? "@" : "-") << " " << name << " ";
        ss << "[" << map_join(fones, [](Fone fone)
                              { return fone.str(); }, ", ")
           << "]";
        return ss.str();
    }
};

// @KEEP
int main()
{
    Contact contato; // @DROP
    while (true)
    {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end")
        {
            break;
        }
        else if (cmd == "init")
        {
            // @COM
            string name;
            ss >> name;
            // @DROP
            contato = Contact(name);
        }
        else if (cmd == "add")
        {
            // @COM
            string id, number;
            ss >> id >> number;
            // @DROP
            contato.addFone(id, number);
        }
        else if (cmd == "rm")
        {
            // @COM
            int index{};
            ss >> index;
            // @DROP
            contato.rmFone(index);
        }
        else if (cmd == "tfav")
        {
            // @DROP
            contato.toogleFavorited();
        }
        else if (cmd == "show")
        {
            // @DROP
            cout << contato.str() << endl;
        }
        else
        {
            cout << "fail: comando invalido" << endl;
        }
    }
}