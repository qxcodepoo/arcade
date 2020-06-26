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
//_B
    cout << "[ ";
    for(std::vector<int>::reverse_iterator it = vet.rbegin(); it != vet.rend(); it++)
        cout << *it << " ";
    cout << "]\n";
//_E
}

//retorna o índice que contém value ou -1 se não existir
int vet_find(vector<int>& vet, int value){
//_B
    for(size_t i = 0; i < vet.size(); i++)
        if(vet[i] == value)
            return i;
//_E
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
        }else if(cmd == "get"){
            int ind;
            ss >> ind;
            cout << vet[ind] << "\n";
        }else if(cmd == "set"){
            int ind, value;
            ss >> ind >> value;
            vet[ind] = value;
        }else if(cmd == "find"){
            //_B
            int value;
            cout << "[ ";
            while(ss >> value) //enquanto conseguir retirar tokens
                cout << vet_find(vet, value) << " "; //converte pra inteiro e imprime
            cout << "]\n";
            //_E
        }else if(cmd == "rmi"){
            //_B
            int ind;
            ss >> ind;
            if(ind >=0 && ind < (int) vet.size())
                vet.erase(vet.begin() + ind);
            else
                cout << "fail\n";
            //_E
        }else if(cmd == "ins"){
            //_B
            int ind; 
            int value;
            ss >> ind >> value;
            if(ind < 0)
                continue;
            if(ind >= (int)vet.size())
                ind = vet.size();
            vet.insert(vet.begin() + ind, value);
            //_E
        }else if(cmd == "rma"){
            //_B
            int value;
            ss >> value;
            for(vector<int>::iterator it = vet.begin(); it != vet.end();){
                if(*it == value){
                    it = vet.erase(it);
                }else{
                    it++;
                }
            }
            //_E
        }else{
            cout << "Comando invalido\n";
        }
    }
    return 0;
}
