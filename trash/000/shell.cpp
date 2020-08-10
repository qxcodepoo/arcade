#include <iostream>
#include <sstream>
using namespace std;
int main(){
    string line;
    string cmd;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;
        if(line == "end"){
            break;
        }else{
            puts("fail: command not found");
        }
    }
}