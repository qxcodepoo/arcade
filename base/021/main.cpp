#include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, int> mapa {{"oi", 1}, {"tim", 2}, {"claro", 3}};
    for(auto& [k, v] : mapa)
        cout << k << " " << v << "\n";
    int x = stoi(string("86"));
    cout << x << endl;
}