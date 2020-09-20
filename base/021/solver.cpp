using namespace std;

#include <functional> //reference_wrapper
#include <iostream>
#include <vector>
#include <sstream>
#include <map>

class Aluno; //forward declaration

class Discp{
    string id;
    map<string, Aluno*> m_aluno;
public:
    Discp(string nome = ""): id {nome} {};
    string getId(){return id;};
    void addAluno(Aluno* aluno);    //after
    void rmAluno(Aluno* aluno);   //after
    friend ostream& operator<<(ostream& os, Discp& discp); //after
};

class Aluno{
    string id;
    map<string, Discp*> m_discp;
public:
    Aluno(string nome = ""): id {nome}{};
    string getId(){return id;};
    vector<Discp*> getDiscps(){
        vector<Discp*> discps;
        for(auto &[k, v] : m_discp) //c++17
            discps.push_back(v);
        return discps;
    }
    friend ostream& operator<<(ostream& os, Aluno& aluno){
        os << "    " << aluno.getId() << " [ ";
        for(auto& [k, v] : aluno.m_discp)
            os << k << " ";
        os << "]";
        return os;
    }
    friend void Discp::addAluno(Aluno*);
    friend void Discp::rmAluno(Aluno*);
};

void Discp::addAluno(Aluno* aluno){
    if(this->m_aluno.count(aluno->getId()) == 1) //ja existe
        return;
    this->m_aluno[aluno->getId()] = aluno;
    aluno->m_discp[this->getId()] = this;
}

void Discp::rmAluno(Aluno* aluno){
    if(this->m_aluno.count(aluno->getId()) == 0) //nao existe
        return;
    this->m_aluno.erase(aluno->getId());
    aluno->m_discp.erase(this->getId());
}

ostream& operator<<(ostream& os, Discp& discp){
    os << "    " << discp.getId() << " [ ";
    for(auto& [k, v] : discp.m_aluno)
        os << k << " ";
    os << "]";
    return os;
}


template <class T>
T& get(map<string, T>& m, string key){
    try{
        return m.at(key);
    }catch(exception& e){
        throw string("chave " + key + " nao existe");
    }
}

class Sistema {
    map<string, Aluno> m_aluno;
    map<string, Discp> m_discp;

public:
    void addAluno(string idAluno){
        if(m_aluno.count(idAluno) == 0)
            m_aluno[idAluno] = Aluno(idAluno);
    }
    void addDiscp(string idDiscp){
        if(m_discp.count(idDiscp) == 0)
            m_discp[idDiscp] = Discp(idDiscp);
    }
    void matricular(string idAluno, string idDiscp){
        m_discp.at(idDiscp).addAluno(&m_aluno.at(idAluno));
    }
    void desmatricular(string idAluno, string idDiscp){
        m_discp.at(idDiscp).rmAluno(&m_aluno.at(idAluno));
    }
    void rmAluno(string idAluno){
        Aluno& aluno = get(m_aluno, idAluno);
        for(auto* discp : aluno.getDiscps())
            discp->rmAluno(&aluno);
        this->m_aluno.erase(idAluno);
    }
    friend ostream& operator<<(ostream& os, Sistema& sis){
        os << "alunos:\n";
        for(auto& [k, v] : sis.m_aluno)
            os << v << "\n";
        os << "discps:\n";
        for(auto& [k, v] : sis.m_discp)
            os << v << "\n";
        return os;
    }
};


template <class T>
T get(stringstream& ss){
    T value;
    ss >> value;
    return value;
}

struct Solver{
    Sistema sistema;

    void exec(){
        while (true){
            string line;
            getline(cin, line);
            cout << "$" << line<< "\n";
            if(line == "end")
                break;
            else{
                try{
                    shell(line);
                }catch(exception &e){
                    cout << e.what() << "\n";
                }
            }
        }
    }

    void shell(string line){
        stringstream ss(line);
        string cmd, value;
        ss >> cmd;
        if(cmd == "nwalu"){
            while(ss >> value)
                sistema.addAluno(value);
        }else if(cmd == "nwdis"){
            while(ss >> value)
                sistema.addDiscp(value);
        }else if(cmd == "show"){
            cout << sistema;
        }else if(cmd == "tie"){
            string aluno = get<string>(ss);
            while(ss >> value)
                sistema.matricular(aluno, value);
        }else if(cmd == "untie"){
            string aluno = get<string>(ss);
            while(ss >> value)
                sistema.desmatricular(aluno, value);
        }else if(cmd == "rmalu"){
            sistema.rmAluno(get<string>(ss));
        }else{
            cout << "comando invalido " << "[" << cmd << "]\n";
        }
    }
};

int main(){
    Solver().exec();
}
