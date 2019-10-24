## 40 Época de Matrícula
### Oba, aceitaram minha matrícula em POO.
![](figura.png)


Vamos criar um sistema da cadastro de alunos e disciplinas. Após isso, vamos matricular e remover alunos das disciplinas. Aqui, cada aluno sabe quais as disciplinas em que está matriculado e a disciplina sabe os alunos que ela contém.

## Funcionalidades

- **Repositórios Individuais - 3.0 P**
    - Adicionar aluno passando id do aluno.
    - Mostrar os todos os alunos cadastrados.
    - Adicionar disciplina passando o id da disciplina.
    - Mostrar as todas as disciplinas cadastradas.

```
# :addAlu _name _name ...
nwalu alice edson bruno
    done
nwdis poo aps
  done
nwdis fup
  done
la
  alunos:
    alice []
    bruno []
    edson []
  discps:
    aps []
    fup []
    poo []
```

- **Realizar Matrícula - 4 P**
    - Matricular o aluno em uma ou mais disciplinas.
    - Mostrar as disciplinas de um aluno.
    - Mostrar os alunos de uma disciplina.

```
# mat _aluno _disc _disc ...
mat bruno fup aps poo
  done
mat alice fup poo
  done
mat edson fup
  done
la
  alunos:
    alice [fup poo]
    bruno [aps fup poo]
    edson [fup]
  discps:
    aps [bruno]
    fup [alice bruno edson]
    poo [alice bruno]

```
- **Desmatricular - 2.0 P**
    - Remover disciplinas de um aluno.

```
# rmmat _aluno _disc _disc ...
rmmat bruno poo aps
  done
la
  alunos:
    alice [fup poo]
    bruno [fup]
    edson [fup]
  discps:
    aps []
    fup [alice bruno edson]
    poo [alice]
```

- **Removendo alunos do sistema - 1.0 P**
    - Remover aluno mantendo a integridade do sistema.

```
# rmalu _aluno
rmalu alice
  done
la
  alunos:
    bruno [fup]
    edson [fup]
  discps:
    aps []
    fup [bruno edson]
    poo []
```
---
## Raio X

````java
class Aluno
- idAluno: String
~ m_discp: List<Discp>
--
+ matricular(discp: Discp): void
+ desmatricular(idAluno: String): void
+ getDisciplinas(): List<Discp>
--
+ constructor(idAluno)
+ getIdAluno()
````

````java
class Discp
- idDiscp: String
~ m_aluno: List<Aluno>
--
+ matricular(aluno: Aluno): void
+ desmatricular(idAluno: String): void
+ getAlunos(): List<Aluno>
--
+ constructor(idDiscp)
+ getIdDiscp()
````

````java
class Repository<T>
- typename: String
- mapa: Map<String, T>
--
+ add(key: String, t: T): void
+ get(key:String): T
+ rm(key: String): void
+ has(key: String): boolean
+ keys(): List<String>
+ getAll() List<T>
--
+ constructor(typename: String)
OBS: lançar exceções em caso de erros
````

````java
class Controller
- r_alu: Repository<Aluno>
- r_dis: Repository<Discp>
````  
