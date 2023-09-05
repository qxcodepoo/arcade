# @021 Matrícula

Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/021/Readme.md)

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell)
-- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/021/cover.jpg)

Vamos criar um sistema da cadastro de alunos e disciplinas. Após isso, vamos matricular e remover alunos das disciplinas. Aqui, cada aluno sabe quais as disciplinas em que está matriculado e a disciplina sabe os alunos que ela contém.

## Intro

- **Repositórios Individuais**
  - Adicionar aluno passando id do aluno.
  - Mostrar os todos os alunos cadastrados.
  - Adicionar disciplina passando o id da disciplina.
  - Mostrar as todas as disciplinas cadastradas.

- **Realizar Matrícula**
  - Matricular o aluno em uma ou mais disciplinas.
  - Mostrar as disciplinas de um aluno.
  - Mostrar os alunos de uma disciplina.

- **Desmatricular**
  - Remover disciplinas de um aluno.

- **Removendo alunos e disciplinas do sistema**
  - Remover aluno mantendo a integridade das relações.
  - Remover disciplinas mantendo a integridade das relações.

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/021/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts
class Aluno {

    - id: str

    - discps: map<str, Discp>
    __

    + Aluno(id: str)

    + getId(): str

    + getDiscps(): List<Discp>

    ' retorna o nome do aluno e o nome das disciplinas matriculadas
    + toString(): str
    '
    __vincular__

    ' cria o vínculo bidirecional aluno disciplina
    + addDiscp(discp: Discp)

    __desvincular__

    + rmDiscp(idDiscp: str)
}

class Discp {

    - id: str

    - alunos: map<str, Aluno>
    __

    + Discp(id: str)

    + getId(): str

    + getAlunos(): List<Aluno>

    ' mostra o id da disciplina e o nome dos alunos matriculados
    + toString(): str

    __vincular__

    ' cria o vínculo bidirecional aluno disciplina
    + addAluno(aluno: Aluno)

    __desvincular__
    '
    + rmAluno(idAluno: str)
}

class Sistema {
    '
    - discps: map<str, Discp>
    '
    - alunos: map<str, Aluno>
    '
    __
    '
    + Sistema()

    ' mostra os alunos e disciplinas cadastradas
    + toString(): str

    __cadastrar__

    ' adiciona um aluno com esse id no sistema
    + addAluno(idAluno: str)

    ' adiciona uma disciplina com esse id no sistema
    + addDiscp(idDiscp: str)
    
    __vincular__
    
    + getAlunos(): List<Aluno>
    
    + getDiscps(): List<Discp>
    
    ' recupera os objetos aluno e disciplina e vincula-os
    + matricular(idAluno: str, idDiscp: str)
    
    __desvincular__
    
    + desmatricular(idAluno: str, idDiscp: str)
    '
    __remover__
    
    ' remove um aluno com esse id do sistema desfazendo todos os vínculos
    + removerAluno(idAluno: str)
    
    ' remove uma disciplina com esse id do sistema desfazendo todos os vínculos
    + removerDiscp(idDiscp: str)
}
```

<!-- load -->

## Shell

```bash
#__case adicionando alunos ao sistema em lote
# nwalu _name _name ...
$nwalu alice edson bruno

# adicionando disciplinas ao sistema em lote
# nwdis _disc _disc
$nwdis poo aps
$nwdis fup

# show mostra alunos e disciplinas
$show
- alunos
alice []
bruno []
edson []
- discps
aps []
fup []
poo []

#__case matriculando alunos em lote
# tie _aluno _disc _disc ...
$tie bruno fup aps poo
$tie alice fup poo
$tie edson fup

$show
- alunos
alice [fup, poo]
bruno [aps, fup, poo]
edson [fup]
- discps
aps [bruno]
fup [alice, bruno, edson]
poo [alice, bruno]

#__case desmatriculando alunos em lote
# untie _aluno _disc _disc ...
$untie bruno poo aps
$show
- alunos
alice [fup, poo]
bruno [fup]
edson [fup]
- discps
aps []
fup [alice, bruno, edson]
poo [alice]

#__case removendo alunos do sistema
# rmalu _aluno
$rmalu alice

$show
- alunos
bruno [fup]
edson [fup]
- discps
aps []
fup [bruno, edson]
poo []
$end
```
