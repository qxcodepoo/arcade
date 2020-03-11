#include <iostream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

template <class T>
class Repository {
    std::map<std::string, T> _mapa;
    std::string nomeTipo;
public:
    Repository(std::string nomeTipo = ""){
        this->nomeTipo = nomeTipo;
    }

    //adiciona se a chave ainda nao existir
    T * add(std::string key, T t){
        if(_mapa.count(key) == 1)
            throw "fail: " + nomeTipo + " " + key + " ja existe";
        _mapa[key] = t;
        return &_mapa[key];
    }

    //retorna se o objeto está no repositório
    bool has(std::string key){
        return _mapa.count(key);
    }

    //remove o elemento
    void rm(std::string key){
        if(!_mapa.erase(key))
            throw "fail: " + nomeTipo + " " + key + " nao existe";
    }

    //retorna o endereço do objeto
    T * get(std::string key){
        if(_mapa.count(key) == 0)
            throw "fail: " + nomeTipo + " " + key + " nao existe";
        return &_mapa[key];
    }

    //retorna a referencia do objeto
    T& at(std::string key){
        if(_mapa.count(key) == 0)
            throw "fail: " + nomeTipo + " " + key + " nao existe";
        return _mapa[key];
    }

    //retonar um vetor com a cópia dos elementos
    std::vector<T> getValues(){
        std::vector<T> vet;
        for(auto& par : _mapa)
            vet.push_back(par.second);
        return vet;
    }

    //retorna um vetor com a cópia das chaves
    std::vector<std::string> getKeys(){
        std::vector<std::string> vet;
        for(auto& par : _mapa)
            vet.push_back(par.first);
        return vet;
    }

    string toString(string sep = "\n"){
        if(_mapa.size() == 0)
            return "";
        stringstream ss;
        for(auto it = _mapa.begin(); it != _mapa.end(); it++)
            ss << it->second << sep;

        string saida = ss.str();
        return saida.substr(0, saida.size() - sep.size());//removendo o último sep
    }
};

using namespace std;

struct Stud {
    string id;
    string curso;
    string nome;

    Stud(string id = "", string curso = "", string nome = ""):
        id(id), curso(curso), nome(nome){}
};

ostream& operator<<(ostream& os, const Stud &stud){
    os << stud.id << ":" << stud.curso << ":" << stud.nome;
    return os;
}

struct Prof {
    string id;
    string nome;
    Prof(string id = "", string nome = ""):
        id(id), nome(nome){}
};

ostream& operator<<(ostream& os, const Prof &prof){
    os << prof.id << ":" << prof.nome;
    return os;
}

struct Disc {
    string id;
    string nome;
    Disc(string id = "", string nome = ""):
        id(id), nome(nome){}
};

ostream& operator<<(ostream& os, const Disc &disc){
    os << disc.id << ":" << disc.nome;
    return os;
}

template<class T>
T read(stringstream& st){
    T t;
    st >> t;
    return t;
}

#include <sstream>
struct Controller {
    Repository<Stud> rstud;
    Repository<Prof> rprof;
    Repository<Disc> rdisc;

    Controller():
        rstud("aluno"), rprof("professor"), rdisc("disciplina")
    {
    }

    void shell(string line){
        stringstream ss(line);
        string op;
        ss >> op;
        if(op == "addAlu"){
            string id, curso, nome;
            ss >> id >> curso;
            getline(ss, nome);
            rstud.add(id, Stud(id, curso, nome.substr(1)));
        }else if(op == "addPro"){
            string id, nome;
            ss >> id;
            getline(ss, nome);
            rprof.add(id, Prof(id, nome.substr(1)));
        }else if(op == "addDis"){
            string id, nome;
            ss >> id;
            getline(ss, nome);
            rdisc.add(id, Disc(id, nome.substr(1)));
        }else if(op == "getAlu"){
            cout << rstud.at(read<string>(ss)) << endl;
        }else if(op == "getPro"){
            cout << rprof.at(read<string>(ss)) << endl;
        }else if(op == "getDis"){
            cout << rdisc.at(read<string>(ss)) << endl;
        }else if(op == "showAlu"){
            cout << rstud.toString() << endl;
        }else if(op == "showPro"){
            cout << rprof.toString() << endl;
        }else if(op == "showDis"){
            cout << rdisc.toString()<< endl;
        }else if(op == "rmAlu"){
            rstud.rm(read<string>(ss));
        }else if(op == "rmPro"){
            rprof.rm(read<string>(ss));
        }else if(op == "rmDis"){
            rdisc.rm(read<string>(ss));
        }else{
            cout << "fail: comando invalido" << endl;
        }
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
            }catch(string e){
                cout <<  e << endl;
            }
        }
    }
};

int main(){
    Controller controller;
    controller.exec();
    return 0;
}