# Gerenciando entradas e saídas de um @pula-pula

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo pula-pula`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

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

<!-- draft -->
- cpp
  - [fn.hpp](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/lang/cpp/fn.hpp)
  - [kid.hpp](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/lang/cpp/kid.hpp)
  - [shell.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/lang/cpp/shell.cpp)
  - [trampoline.hpp](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/lang/cpp/trampoline.hpp)
- java
  - [Kid.java](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/lang/java/Kid.java)
  - [Shell.java](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/lang/java/Shell.java)
  - [Trampoline.java](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/lang/java/Trampoline.java)
- ts
  - [kid.ts](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/lang/ts/kid.ts)
  - [shell.ts](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/lang/ts/shell.ts)
  - [trampoline.ts](https://github.com/qxcodepoo/arcade/blob/master/base/pula-pula/.cache/lang/ts/trampoline.ts)

<!-- draft -->

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
#__case unico
# $chegou _nome _idade
# insere uma criança na fila de entrada do brinquedo
$arrive mario 5
$arrive livia 4
$arrive luana 3

# show
# mostra a fila de entrada e o pula pula
$show
[luana:3, livia:4, mario:5] => []

#__case entrando
# entrar
# tira a primeira criança da fila de entrada e insere no pula pula

$enter
$show
[luana:3, livia:4] => [mario:5]

#__case segunda pessoa
$enter
$show
[luana:3] => [livia:4, mario:5]

#__case saindo
$leave
$show
[mario:5, luana:3] => [livia:4]

#__case remove
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
#__case 2
$show
[] => []
$arrive mario 5
$show
[mario:5] => []
#__case empty enter
$enter
$show
[] => [mario:5]
#__case empty leave
$leave
$show
[mario:5] => []
$leave
$show
[mario:5] => []
#__case remove from waiting
$remove mario
$show
[] => []
#__case remove empty
$remove rebeca
$show
[] => []
$end
```
