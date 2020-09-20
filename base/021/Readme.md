# Época de Matrícula - Associação NxN

<!--TOC_BEGIN-->
- [Funcionalidades](#funcionalidades)
- [Shell](#shell)
- [Raio X](#raio-x)

<!--TOC_END-->

![](figura.png)


Vamos criar um sistema da cadastro de alunos e disciplinas. Após isso, vamos matricular e remover alunos das disciplinas. Aqui, cada aluno sabe quais as disciplinas em que está matriculado e a disciplina sabe os alunos que ela contém.

## Funcionalidades

- **Repositórios Individuais - 3.0 P**
    - Adicionar aluno passando id do aluno.
    - Mostrar os todos os alunos cadastrados.
    - Adicionar disciplina passando o id da disciplina.
    - Mostrar as todas as disciplinas cadastradas.

- **Realizar Matrícula - 4 P**
    - Matricular o aluno em uma ou mais disciplinas.
    - Mostrar as disciplinas de um aluno.
    - Mostrar os alunos de uma disciplina.

- **Desmatricular - 2.0 P**
    - Remover disciplinas de um aluno.

- **Removendo alunos do sistema - 1.0 P**
    - Remover aluno mantendo a integridade do sistema.

## Shell

```bash
#__case adicionando alunos ao sistema
# nwalu _name _name ...
$nwalu alice edson bruno

# adicionando disciplinas ao sistema
# nwdis _disc _disc
$nwdis poo aps
$nwdis fup

# show mostra alunos e disciplinas
$show
alunos:
    alice [ ]
    bruno [ ]
    edson [ ]
discps:
    aps [ ]
    fup [ ]
    poo [ ]

#__case matriculando alunos
# tie _aluno _disc _disc ...
$tie bruno fup aps poo
$tie alice fup poo
$tie edson fup

$show
alunos:
    alice [ fup poo ]
    bruno [ aps fup poo ]
    edson [ fup ]
discps:
    aps [ bruno ]
    fup [ alice bruno edson ]
    poo [ alice bruno ]

#__case desmatriculando alunos
# untie _aluno _disc _disc ...
$untie bruno poo aps
$show
alunos:
    alice [ fup poo ]
    bruno [ fup ]
    edson [ fup ]
discps:
    aps [ ]
    fup [ alice bruno edson ]
    poo [ alice ]

#__case removendo alunos do sistema
# rmalu _aluno
$rmalu alice

$show
alunos:
    bruno [ fup ]
    edson [ fup ]
discps:
    aps [ ]
    fup [ bruno edson ]
    poo [ ]
$end
```

***
## Raio X

````java
class Aluno
- idAluno: String
~ m_discp: Map<String, Discp>
--
+ matricular(discp: Discp): void
+ desmatricular(idAluno: String): void
+ getDisciplinas(): List<Discp>
--
+ Aluno(idAluno)
+ getIdAluno(): String
````

````java
class Discp
- idDiscp: String
~ m_aluno: Map<String, Aluno>
--
+ matricular(aluno: Aluno): void
+ desmatricular(idAluno: String): void
+ getAlunos(): List<Aluno>
--
+ Discp(idDiscp)
+ getIdDiscp(): String
````

````java
class Sistema
- alunos: Map<String, Aluno>
- discps: Map<String, Discp>
--
+ addAluno(idAluno: String): void
+ addDiscp(idDiscp: String): void
+ matricular(idAluno: String, idDisc: List<String>): void
+ desmatricular(idAluno: String, idDisc: List<String>): void
+ rmAluno(idAluno: String): void
````
