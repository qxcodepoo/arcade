#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

struct Espiral{
    string nome;
    int qtd;
    float preco;
    Espiral(string nome = "empty", int qtd = 0, float preco = 0.0){
        this->nome = nome;
        this->qtd = qtd;
        this->preco = preco;    
    }
    string toString(){
        stringstream ss;
        ss << "[" << setw(8) << this->nome << " :"
                  << setw(2) << this->qtd << " U :"
                  << setw(5) << fixed << setprecision(2)
                  << this->preco << " RS]";
        return ss.str();
    }
};

class Maquina{
    vector<Espiral> espirais;
    float saldo, lucro;
    int max_produtos;
public:
    Maquina(int qtd = 0, int max_produtos = 0):
        espirais(qtd){
        saldo = 0;
        lucro = 0;
        this->max_produtos = max_produtos;
    }
    Espiral& get(int indice){
        if((indice < 0)||(indice >= (int) espirais.size()))
            throw "fail: indice nao existe";
        return espirais[indice];
    }
    void set(int indice, Espiral espiral){
        if(espiral.qtd > max_produtos)
            throw "fail: limite excedido";
        if(espiral.qtd < 0)
            throw "fail: valores invalidos";
        get(indice) = espiral;
    }
    string toString(){
        stringstream ss;
        ss << "saldo: " << fixed << setprecision(2) << saldo << endl;
        int i = 0;
        for(auto& espiral : espirais){
            ss << i << " " << espiral.toString() << endl;
            i += 1;
        }
        return ss.str();
    }

    void inserirDinheiro(float value){
        if(value <= 0)
            throw "fail: fail: valores invalidos";
        saldo += value;
    }
    float pedirTroco(){
        auto troco = saldo;
        saldo = 0;
        return troco;
    }
    void comprar(int ind){
        if(saldo < get(ind).preco)
            throw "fail: saldo insuficiente";
        if(espirais[ind].qtd == 0)
            throw "fail: espiral sem produtos";
        saldo -= get(ind).preco;
        get(ind).qtd -= 1;
    }
    float getSaldo(){
        return saldo;
    }
};

struct Controller{
    Maquina maq;
    Controller(){
    }
    void shell(string line){
        stringstream in(line);
        string op;
        in >> op;
        if(op == "init"){
            int qtd, max_produtos;
            in >> qtd >> max_produtos;
            maq = Maquina(qtd, max_produtos);
        }else if(op == "show"){
            cout << maq.toString();
        }else if(op == "set"){
            int ind, qtd;
            float preco;
            string desc;
            in >> ind >> desc >> qtd >> preco;
            maq.set(ind, Espiral(desc, qtd, preco));
        }else if(op == "limpar"){
            int ind;
            in >> ind;
            maq.set(ind, Espiral());
        }else if(op == "dinheiro"){
            float din;
            in >> din;
            maq.inserirDinheiro(din);
        }else if(op == "troco"){
            auto troco = maq.pedirTroco();
            cout << "voce recebeu " << fixed << setprecision(2) << troco << " RS" << endl;
        }else if(op == "comprar"){
            int ind;
            in >> ind;
            maq.comprar(ind);
            cout << "voce comprou um " << maq.get(ind).nome << endl;
        }else
            throw "fail: comando invalido";
    }

    void exec(){
        string line;
        while(true){
            getline(cin, line);
            cout << "$" << line << endl;
            if(line == "end")
                return;
            try{
                shell(line);
            }catch(const char * e){
                cout << e << endl;
            }
        }
    }
};

int main(){
    Controller c;
    c.exec();
    return 0;
}