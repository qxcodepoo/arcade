#include <iostream>
#include <sstream>
#include <cstdio>
using namespace std;

int main(){
    string line;
    string cmd;
    float acc = 0;
    while(true){
        getline(cin, line);
        cout << "$" << line << "\n";
        stringstream ss(line);
        ss >> cmd;

        if(line == "end"){
            break;
        }else if(cmd == "show"){
            printf("%.2f\n", acc);
        }else if(cmd == "add"){
            float value;
            ss >> value;
            acc += value;
        }else if(cmd == "mult"){
            float value;
            ss >> value;
            acc *= value;
        }else if(cmd == "div"){
            float value;
            ss >> value;
            if(value == 0)
                puts("fail: division by zero");
            else
                acc /= value;
        }else if(cmd == "addm"){
            float value;
            while(ss >> value){
                acc += value;
            }
        }else{
            puts("fail: command not found");
        }

    }

}