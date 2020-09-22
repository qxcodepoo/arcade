class Discp{
    string id;
    map<string, Aluno*> m_aluno;
public:
    Discp(string nome = "");
    string getId();
    void addAluno(Aluno* aluno);
    void rmAluno(string idAluno);
    friend ostream& operator<<(ostream& os, Discp& discp);
};

class Aluno{
    string id;
    map<string, Discp*> m_discp;
public:
    Aluno(string nome = "");
    string getId();
    vector<Discp*> getDiscps();
    friend ostream& operator<<(ostream& os, Aluno& aluno);
    friend void Discp::addAluno(Aluno*);
    friend void Discp::rmAluno(string);
};

class Sistema {
    map<string, Aluno> m_aluno;
    map<string, Discp> m_discp;
public:
    void addAluno(string idAluno);
    void addDiscp(string idDiscp);
    void matricular(string idAluno, string idDiscp);
    void desmatricular(string idAluno, string idDiscp);
    void rmAluno(string idAluno);
    friend ostream& operator<<(ostream& os, Sistema& sis);
};