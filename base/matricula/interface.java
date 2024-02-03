import java.util.*;

interface Sistema{
    void addAluno(String id);
    void addDiscp(String id);
    void matricular(String idAluno, String idDiscp);
    void desmatricular(String idAluno, String idDiscp);
    void rmAluno(String idAluno);
}
public class Solver {
    public static void main(String[] args) {
        Sistema sys = new Sistema();
        for(String id : Arrays.asList("alice", "edson", "bruno"))
            sys.addAluno(id);
        for(String id : Arrays.asList("fup", "aps", "poo"))
            sys.addDiscp(id);
        System.out.println(sys);
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
        for(String id : Arrays.asList("fup", "aps", "poo"))
            sys.matricular("bruno", id);
        for(String id : Arrays.asList("fup", "poo"))
            sys.matricular("alice", id);
        sys.matricular("edson", "fup");
        System.out.println(sys);
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
        System.out.println(sys);
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
        System.out.println(sys);
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
}
