#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//mostra o vetor
void vet_show(vector<int>& vet){
    cout << "[ ";
    for(size_t i = 0; i < vet.size(); i++)
        cout << vet[i] << " ";
    cout << "]\n";
}

void vet_rshow(vector<int>& vet){
}

//retorna o índice que contém value ou -1 se não existir
int vet_find(vector<int>& vet, int value){
    return -1;
}

int main(){
    vector<int> vet;
    string line;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        cout << "$" << line << "\n";
        string cmd;
        ss >> cmd; //pegando o primeiro token

        if(line == "end"){
            break;
        }else if(cmd == "add"){
            int value;
            while(ss >> value) //enquanto conseguir retirar valores
                vet.push_back(value);
        }else if(cmd == "show"){
            vet_show(vet);
        }else if(cmd == "rshow"){
            vet_rshow(vet);
        }else if(cmd == "find"){
        }else if(cmd == "rmi"){
        }else if(cmd == "ins"){
        }else if(cmd == "rma"){
        }else{
            cout << "Comando invalido\n";
        }
    }
    return 0;
}
