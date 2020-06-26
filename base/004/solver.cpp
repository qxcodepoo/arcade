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
    ~Lapiseira(){
        if(this->grafite != nullptr)
            delete this->grafite;
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

    bool inserir(Grafite * grafite){
        if(this->grafite == nullptr){
            if(this->calibre != grafite->calibre){
                cout << "fail: calibre incompatível\n";
                return false;
            }else{
                this->grafite = grafite;
                return true;
            }
        }
        cout << "fail: ja existe grafite\n";
        return false;
    }

    void remover(){
        if(this->grafite == nullptr)
            cout << "fail: nao existe grafite\n";
        else{
            delete this->grafite;
            this->grafite = nullptr;
        }
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
            cout << "init _calibre; inserir _calibre _dureza _tamanho; remover; write _pressao" << endl;
        }else if(cmd == "init"){
            float calibre;
            ss >> calibre;
            lapiseira = Lapiseira(calibre);
        }else if(cmd == "inserir"){
            float calibre;
            string dureza;
            int tamanho;
            ss >> calibre >> dureza >> tamanho;
            auto grafite = new Grafite(calibre, dureza, tamanho);
            if(!lapiseira.inserir(grafite))
                delete grafite;
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
