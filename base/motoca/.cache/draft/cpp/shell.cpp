#include <iostream>
#include <memory> //shared_ptr
#include <sstream> //stringstream
#include <utility> //exchange
using namespace std;

int main() {
    // CRIE SUA MOTO AQUI COM POTENCIA 1
    while (true) {
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;

        stringstream ss(line);
        ss >> cmd;

        if (cmd == "init") {
            // INICIE A MOTO AQUI USANDO O CONSTRUTOR
            // int power {};
            // ss >> power;
        } else if (cmd == "show") {
            // MOSTRE A MOTO AQUI
        } else if (cmd == "leave") {
            // RETIRE A PESSOA DA MOTO
            // SE EXISTIR, MOSTRE A PESSOA
        } else if (cmd == "honk") {
            // BUZINE A MOTO
        } else if (cmd == "enter") {
            // CRIE UM PONTEIRO PARA PESSOA E INICIE-O AQUI
            // DEPOIS INSIRA A PERSON NA MOTO
            // string name {};
            // int age {};
            // ss >> name >> age;
        } else if (cmd == "buy") {
            // COMPRE TEMPO PARA DIRIGIR
            // int time {};
            // ss >> time;
        } else if (cmd == "drive") {
            // DIRIJA A MOTO POR UM TEMPO
            // int time {};
            // ss >> time;
        } else if (cmd == "end") {
            break;
        } else {
            cout << "fail: invalid command\n";
        }
    }
}
