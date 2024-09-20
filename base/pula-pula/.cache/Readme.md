# @pula-pula - Gerenciando entradas e saídas

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/pula-pula/cover.jpg)

Nosso objetivo no trabalho é modelar um gestor de pula pulas em um parquinho, controlando as pessoas que entram e saem do pula pula, além de coordenar as pessoas que estão na fila de espera.

## Intro

- Inserir crianças na fila de espera do pula pula
- Mover a primeira criança da fila de espera do pula pula para dentro do pula pula.
- Mover a primeira criança que entrou no pula pula para o final da fila de espera.

***

## Draft

<!-- links .cache/draft -->
- cpp
  - [fn.hpp](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/draft/cpp/fn.hpp)
  - [kid.hpp](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/draft/cpp/kid.hpp)
  - [shell.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/draft/cpp/shell.cpp)
  - [trampoline.hpp](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/draft/cpp/trampoline.hpp)
- java
  - [Kid.java](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/draft/java/Kid.java)
  - [Shell.java](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/draft/java/Shell.java)
  - [Trampoline.java](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/draft/java/Trampoline.java)
- ts
  - [aashell.ts](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/draft/ts/aashell.ts)
  - [kid.ts](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/draft/ts/kid.ts)
  - [trampoline.ts](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/draft/ts/trampoline.ts)
<!-- links -->

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/pula-pula/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts

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
  
  ' procura por uma criança na lista do parâmetro e se
  ' encontrar, remove a criança e a retorna
  - {static} removeFromList(name : string, list : List<Kid>) : Kid | null
  __
  + Trampoline()
  + toString() : string
  __
  
  ' insere na posição mais a esquerda da lista de espera
  + arrive(kid : Kid)
  
  ' se existir alguém na lista de espera
  ' remove o que estiver mais a direita e insere na posição mais 
  ' a esquerda da lista de playing
  + enter()
  
  ' se existir alguém em playing, remove o que estiver mais a direita
  ' e insere na posição mais a esquerda da lista de espera
  + leave()
  
  ' utilize o método estático removeFromList
  ' para tentar remover a criança das duas filas
  + removeKid(name : string) : Kid | null
}

```

<!-- load -->

***

## Shell

```bash
#TEST_CASE unico
# $chegou _nome _idade
# insere uma criança na fila de entrada do brinquedo
$arrive mario 5
$arrive livia 4
$arrive luana 3

# show
# mostra a fila de entrada e o pula pula
$show
[luana:3, livia:4, mario:5] => []

#TEST_CASE entrando
# entrar
# tira a primeira criança da fila de entrada e insere no pula pula

$enter
$show
[luana:3, livia:4] => [mario:5]

#TEST_CASE segunda pessoa
$enter
$show
[luana:3] => [livia:4, mario:5]

#TEST_CASE saindo
$leave
$show
[mario:5, luana:3] => [livia:4]

#TEST_CASE remove
$remove luana

$show
[mario:5] => [livia:4]
$remove livia
$show
[mario:5] => []
$end
```

***

```bash
#TEST_CASE 2
$show
[] => []
$arrive mario 5
$show
[mario:5] => []
#TEST_CASE empty enter
$enter
$show
[] => [mario:5]
#TEST_CASE empty leave
$leave
$show
[mario:5] => []
$leave
$show
[mario:5] => []
#TEST_CASE remove from waiting
$remove mario
$show
[] => []
#TEST_CASE remove empty
$remove rebeca
$show
[] => []
$end
```
