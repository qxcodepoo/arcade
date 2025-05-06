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
int main()
{
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
            // string name;
            // ss >> name;
        }
        else if (cmd == "add")
        {
            // string id, number;
            // ss >> id >> number;
        }
        else if (cmd == "rm")
        {
            // int index{};
            // ss >> index;
        }
        else if (cmd == "tfav")
        {
        }
        else if (cmd == "show")
        {
        }
        else
        {
            cout << "fail: comando invalido" << endl;
        }
    }
}
