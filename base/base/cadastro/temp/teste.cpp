#include <iostream>
#include <sstream>
using namespace std;

void teste(string a, string b, string c){
    cout << a << " " << b << " " << c << "\n";
}

void teste2(int a, string b, float c){
    cout << a << " " << b << " " << c << "\n";
}

template <class T>
T get(istream& is){
    T t;
    is >> t;
    return t;
}
#define getI get<int>
#define getS get<string>
#define getF get<float>


int main(){
    stringstream x("1 2 3");
    teste(get<string>(x), get<string>(x), get<string>(x));

    stringstream y("1 banana 3.4");
    teste2(get<int>(y), get<string>(y), get<float>(y));

}
