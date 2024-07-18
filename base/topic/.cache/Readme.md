# @topic - Gerenciando assentos prioritários e normais

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/topic/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo topic`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/topic/cover.jpg)

O objetivo dessa atividade é exercitar o que vocês aprenderam no cinema com algumas variações. Aqui, vamos implementar um sistema de alocação de passageiros em uma topic. Nossa topic tem uma quantidade máxima de passageiros, mas também define alguns assentos preferenciais.

***

## Intro

Seu sistema deverá:

- **Inicializar e Mostrar.**
  - Iniciar a topic solicitando a lotação máxima e a quantidade de cadeiras preferenciais.
  - Mostrar o estado do trem
    - Coloque @ na frente das cadeiras preferenciais
    - Coloque = na frente das cadeiras normais.
- **Inserir.**
  - Inserir passageiros informando id e idade
    - Se o passageiro for idoso:
      - Se houver cadeiras preferenciais
        - O coloque na primeira cadeira preferência.
    - Senão
      - O coloque na primeira cadeira normal.
    - Se o passageiro não for idoso.
      - Se houver cadeiras não preferenciais
        - O coloque na primeira não preferencial.
      - Se não
        - O coloque na primeira cadeira preferencial.
- **Remover.**
  - Remover passageiros por id

Existe uma lista para as cadeiras normais e outra para as preferenciais. Para facilitar nas operações de busca e inserção, você deverá criar vários métodos privados para simplificar a lógica dos métodos principais.

***

## Draft

-[Solver.java](https://github.com/qxcodepoo/arcade/blob/master/base/topic/.cache/draft.java)
-[solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/topic/.cache/draft.cpp)

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/topic/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts
class Pass {
  - age  : int
  - name : string
  __
  + Pass(name : string, age : int)
  __
  + getAge()     : int
  + getName()    : string
  
  ' return true se o passageiro tem mais de 64 anos
  + isPriority() : boolean
  + setAge(age : int)
  + setName(name : string)
  __
  + toString() : string
}

class Topic {
  - prioritySeats : Array<Pass | null>
  - normalSeats   : Array<Pass | null>
  __
  
  ' inicia prioritySeats com qtdPriority nulls
  ' inicia normalSeats com (capacity - qtdPriority) nulls
  + Topic(capacity : int, qtdPriority : int)
  
  ' verifica se já está na topic
  ' utilize o método estático para realizar as inserções
  ' se for prioridade 
  '     tenta primeiro na prioridade, depois na normal
  ' se não for prioridade
  '     tenta primeiro na normal, depois na prioridade
  ' se nao conseguir
  '     avisa que esta lotado
  + insert(pass : Pass) : boolean
  
  ' chama o método remover privado estático para 
  ' tentar remover de ambas as listas
  + remove(name : string) : boolean
  __
  
  ' procura pela primeira posição vazia ou -1
  - findFree(list : List<Pass | null>) : int {static}
  
  ' procura por nome nos elementos não nulos e retorna o indice ou -1 
  - findName(list : List<Pass | null>, name : string) : int {static}
  
  ' usa o método findFree para encontrar a posição vazia e inserir o passageiro
  - insert  (list : List<Pass | null>, pass : Pass)   : boolean {static}
  
  ' usa o método findName para encontrar o passageiro e remover
  - remove  (list : List<Pass | null>, name : string) : boolean {static}
  __
  + toString() : string
}
```

<!-- load -->

***

## Shell

```bash

#######################################
#__case Inicializar
#######################################
# init _lotacao _qtd_prioritarios
$show
[]
$init 5 2
$show
[@ @ = = =]

#__case Embarque

$in davi 17
$show
[@ @ =davi:17 = =]

#__case Embarque 2

$in joao 103
$show
[@joao:103 @ =davi:17 = =]

#__case Embarque 3

$in ana 35
$show
[@joao:103 @ =davi:17 =ana:35 =]

#__case Embarque 4

$in rex 20
$in bia 16
$show
[@joao:103 @bia:16 =davi:17 =ana:35 =rex:20]

#__case Desembarque
$out davi
$show
[@joao:103 @bia:16 = =ana:35 =rex:20]

#__ case vaga
$in aragao 96
$show
[@joao:103 @bia:16 =aragao:96 =ana:35 =rex:20]

#__case lotada
$in lucas 23
fail: topic lotada

#__case não existe
$out marcelo
fail: marcelo nao esta na topic

$out ana

#__case dobrado
$in bia 13
fail: bia ja esta na topic


#__ final
$show
[@joao:103 @bia:16 =aragao:96 = =rex:20]
$end
```
