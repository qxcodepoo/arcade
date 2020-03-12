#include <iostream>
#include <cstdio>
#include <clocale>
#include <sstream>
#include <iomanip> //setprecision

using namespace std;

struct Grafite{
    float calibre;
    string dureza;
    int tamanho;

    Grafite(float calibre, string dureza, int tamanho){
        this->calibre = calibre;
        this->dureza = dureza;
        this->tamanho = tamanho;
    }
    string toString(){
        stringstream ss;
        ss << std::fixed << setprecision(1) << calibre << ":" << dureza << ":" << tamanho;
        return ss.str();

    }
};

struct Lapiseira{
    float calibre;
    Grafite * grafite;

    Lapiseira(float calibre = 0.0){
        this->calibre = calibre;
        this->grafite = nullptr;
    }

    string toString(){
        stringstream saida;
        saida << "calibre: " << this->calibre << ", grafite: ";
        if (this->grafite != nullptr)
            saida << "[" << grafite->toString() << "]";
        else
            saida << "null";
        return saida.str();
    }

    void inserir(Grafite * grafite){
        if(this->grafite == nullptr){
            if(this->calibre != grafite->calibre)
                cout << "fail: calibre incompatível\n";
            else
                this->grafite = grafite;
        }else
            cout << "fail: ja existe grafite\n";
    }

    void remover(){
        if(this->grafite == nullptr)
            cout << "fail: nao existe grafite\n";
        else
            this->grafite = nullptr;
    }

    void write(int pressao){
        if(this->grafite == nullptr)
            cout << "fail: nao existe grafite\n";
        else if(this->grafite->tamanho <= 2 * pressao){
            if(this->grafite->tamanho < 2 * pressao)
                cout << "fail: folha ficou pela metade\n";
            delete this->grafite;
            this->grafite = nullptr;
            cout << "fail: grafite acabou\n";
        }else{
            this->grafite->tamanho -= 2 * pressao;
        }
    }
};

int main(){
    Lapiseira lapiseira;
    string line;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        cout << "$" << line << endl;
        ss >> cmd;
        if(line == "end")
            break;
        else if(cmd == "help"){
            cout << "in; out; show; fuel _gat; drive _km" << endl;
        }else if(cmd == "init"){
            float calibre;
            ss >> calibre;
            lapiseira = Lapiseira(calibre);
        }else if(cmd == "inserir"){
            float calibre;
            string dureza;
            int tamanho;
            ss >> calibre >> dureza >> tamanho;
            lapiseira.inserir(new Grafite(calibre, dureza, tamanho));
        }else if(cmd == "remover"){
            lapiseira.remover();
        }else if(cmd == "show"){
            cout << lapiseira.toString() << endl;
        }else if (cmd == "write"){
            int pressao;
            ss >> pressao;
            lapiseira.write(pressao);
        }else{
            cout << "fail: comando invalido" << endl;
        }
    }
    return 0;
}
