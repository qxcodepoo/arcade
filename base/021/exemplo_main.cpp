int main(){
    Sistema sys;
    for(auto aluno : {"alice", "edson", "bruno"})
        sys.addAluno(aluno);
    for(auto discp : {"fup", "aps", "poo"})
        sys.addDiscp(discp);
    cout << sys;
/*
alunos:
    alice [ ]
    bruno [ ]
    edson [ ]
discps:
    aps [ ]
    fup [ ]
    poo [ ]
*/
    for(auto discp : {"fup", "aps", "poo"})
        sys.matricular("bruno", discp);
    for(auto discp : {"fup", "poo"})
        sys.matricular("alice", discp);
    sys.matricular("edson", "fup");
    cout << sys;
/*
alunos:
    alice [ fup poo ]
    bruno [ aps fup poo ]
    edson [ fup ]
discps:
    aps [ bruno ]
    fup [ alice bruno edson ]
    poo [ alice bruno ]
*/
    sys.desmatricular("bruno", "poo");
    sys.desmatricular("bruno", "aps");
    cout << sys;
/*
alunos:
    alice [ fup poo ]
    bruno [ fup ]
    edson [ fup ]
discps:
    aps [ ]
    fup [ alice bruno edson ]
    poo [ alice ]
*/
    sys.rmAluno("alice");
    cout << sys;
/*
alunos:
    bruno [ fup ]
    edson [ fup ]
discps:
    aps [ ]
    fup [ bruno edson ]
    poo [ ]
*/
}