#include <iostream>
#include <sstream>
#include <memory>
#include <utility>
using namespace std;

int main() {
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "end") {
            break;
        } 
        // else if (cmd == "show") { 
        // } 
        // else if (cmd == "turn_on") { 
        // }
        // else if (cmd == "turn_off") { 
        // } 
        // else if (cmd == "use") { 
        //     int minutes;
        //     ss >> minutes;
        // } 
        // else if (cmd == "set_charger") {
        //     // CRIE UM OBJETO Charger E ATRIBUA AO NOTEBOOK
        //     int power;
        //     ss >> power;
        // } 
        // else if (cmd == "rm_charger") {
        //     // REMOVA O CARREGADOR DO NOTEBOOK E IMPRIMA SE ELE EXISTIR
        // } 
        // else if (cmd == "set_battery") {
        //     // CRIE UM OBJETO Bateria E ATRIBUA AO NOTEBOOK
        //     int capacity;
        //     ss >> capacity;
        // } 
        // else if (cmd == "rm_battery") {
        //     // REMOVA A BATERIA DO NOTEBOOK E IMPRIMA SE ELA EXISTIR
        // } 
        else {
            cout << "fail: comando inválido\n";
        }
    }    
}
