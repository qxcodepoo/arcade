#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
using namespace std;

template <typename CONTAINER, typename FUNC>
string join(const CONTAINER& c, FUNC f, const string& delim) {
    stringstream ss;
    for (auto it = c.begin(); it != c.end(); ++it) {
        ss << (it == c.begin() ? "" : delim) << f(*it);
    }
    return ss.str();
}

int main()
{
    std::vector<int> vet;
    while (true)
    {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << '\n';

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end")
        {
            break;
        }
        else if (cmd == "push")
        {
            int value{};
            while (ss >> value)
            {
                vet.push_back(value);
            }
        }
        else if (cmd == "show")
        {
            cout << "[" + join(vet, [](auto x){return x;}, ", ") + "]" << '\n';
        }
        else if (cmd == "erase")
        {
            int index{};
            ss >> index;
            vet.erase(vet.begin() + index);
        }
        else if (cmd == "media")
        {
            double sum = 0;
            for (auto item : vet)
            {
                sum += item;
            }
            cout << fixed << setprecision(2) << sum / vet.size() << '\n';
        }
        else
        {
            cout << "fail: invalid command" << '\n';
        }
    }
}