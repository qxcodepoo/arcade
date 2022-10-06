## @009 Pula pula

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/009/cover.jpg)

[](toc)

- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
[](toc)

Nosso objetivo no trabalho é modelar um gestor de pula pulas em um parquinho.

## Intro

- Inserir crianças na fila de espera do pula pula
- Mover a primeira criança da fila de espera do pula pula para dentro do pula pula.
- Mover a primeira criança que entrou no pula pula para o final da fila de espera.

***

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/009/diagrama.png)

[](load)[](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/009/diagrama.puml)[](plantuml:fenced:filter)

```plantuml
package com.qxcode {
  class Kid {
    - age : int
    - name : string
    __
    + Kid(name : string, age : int)
    + toString() : string
    __
    + getAge()  : int
    + getName() : string
    + setAge(age : int)
    + setName(name : string)
  }
  class Trampoline {
    - playing : List<Kid>
    - waiting : List<Kid>
    __
    - {static} removeKid(name : string, list : List<Kid>) : Kid | null
    __
    + Trampoline()
    + toString() : string
    __
    ' 
    ' insere na lista de espera
    + arrive(kid : Kid)
    '
    ' se existir alguém na lista de espera
    ' remove o que estiver na frente da lista
    ' e insere na no fim da lista de playing
    + enter()
    '
    ' se existir alguém em playing, remove o primeiro da lista
    ' e insere no final da lista de espera
    + leave()
    '
    ' procura nas lista passada por parametro a criança
    ' utilizando o nome
    ' se encontrar, remove a criança da lista e retorna
    ' retorna null se não encontrar
    + remove_kid(name : string) : Kid | null
  }
}
```

[](load)

- [solver.cpp](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/009/.cache/draft.cpp)
- [Solver.java](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/009/.cache/draft.java)

***

## Shell

```bash
#__case unico
# $chegou _nome _idade
# insere uma criança na fila de entrada do brinquedo
$arrive mario 5
$arrive livia 4
$arrive luana 3

# show
# mostra a fila de entrada e o pula pula
$show
=> luana:3 livia:4 mario:5 => [ ]

#__case entrando
# entrar
# tira a primeira criança da fila de entrada e insere no pula pula

$enter
$show
=> luana:3 livia:4 => [ mario:5 ]

#__case segunda pessoa
$enter
$show
=> luana:3 => [ livia:4 mario:5 ]

#__case saindo
$leave
$show
=> mario:5 luana:3 => [ livia:4 ]

#__case remove
$remove luana

$show
=> mario:5 => [ livia:4 ]
$remove livia
$show
=> mario:5 => [ ]
$end
```

```bash
#__case 2
$show
=> => [ ]
$arrive mario 5
$show
=> mario:5 => [ ]
#__case empty enter
$enter
$show
=> => [ mario:5 ]
#__case empty leave
$leave
$show
=> mario:5 => [ ]
$leave
$show
=> mario:5 => [ ]
#__case remove from waiting
$remove mario
$show
=> => [ ]
#__case remove empty
$remove rebeca
$show
=> => [ ]
$end
```
