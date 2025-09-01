# Jogo de tabuleiro e armadilhas

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/tabuleiro/cover.jpg)

## Intro

Nosso jogo consiste em um tabuleiro contendo uma trilha de quadrados e um conjunto de peças coloridas. No início do jogo, cada jogador recebe uma peça; todas as peças são inicialmente posicionadas na posição 0 da trilha.

O jogo prossegue em rodadas. Em cada rodada, os jogadores rolam um D20 (dado de 20 faces) e movem suas peças para frente um número de quadrados igual ao resultado obtido pelos dados. Os jogadores rolam os dados sempre na mesma ordem (jogador A, depois jogador B, etc.) nas rodadas.

A maioria dos quadrados no tabuleiro são quadrados simples, mas alguns são “armadilhas”. Se a peça de um jogador cair em um quadrado da armadilha no final do movimento do jogador. O jogador ficará preso na armadilha até que na sua rodada jogue um número par se libertando da armadilha. Ao rolar um número par e se libertar da armadilha, sua peça não se move nessa rodada, mas na próxima poderá se mover normalmente.

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/tabuleiro/tabuleiro.png)

Haverá exatamente três armadilhas na trilha.

O vencedor do jogo é o jogador cuja peça chega primeiro ao final da trilha. O fim da trilha é depois da última casa do tabuleiro. Considere, por exemplo, a placa da figura acima, que tem quadrados numerados de 1 a 48. No início, as peças são posicionadas no local marcado como 'Início', ou seja, antes do quadrado número 1. Portanto, se um jogador rolar um 7, sua peça é posicionada na casa número 7 no final da primeira rodada do jogo.
Além disso, se a peça de um jogador estiver posicionada na casa 41, o jogador precisa de um resultado de rolagem de pelo menos 8 para chegar ao final da trilha e ganhar o jogo. Observe também que não haverá empate no jogo.

___

Questão adaptada da maratona ACM 2003 por @WladimirTavares

___

## Draft

- [solver.ts](https://github.com/qxcodepoo/arcade/blob/master/base/tabuleiro/.cache/draft.ts)
- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/tabuleiro/.cache/draft.cpp)
  
## Guide

[![youtube icon](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/tabuleiro/../youguide.png)](https://youtu.be/x3_hlVYdCdU?si=g0fR-AAgvzkMxU9G)

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/tabuleiro/diagrama.png)


<!-- load diagrama.puml fenced=ts:filter -->

```ts

@startuml

skinparam defaultFontName "Source Code Pro"
skinparam dpi 150
left to right direction
class Player {
  - label: number  
  - pos  : number
  - free : boolean
  __
  + Player(label: number)
  + isFree()   : boolean
  + toString() : string
  __
  + getLabel(): number
  + getPos()  : number
  + setPos(pos: number)
  + setFree(free : boolean): void
}

class Board {
  - trapList : Array<number>
  - players  : Array<Player>
  - running  : boolean
  - boardSize: number
  __
  + Board(nPlayers: number, boardSize: number)
  + toString(): string
  __
  + addTrap (pos  : number): void
  + rollDice(value: number): void
}

Board "1" *--  "2..*" Player : > has
@enduml

```

<!-- load -->

___

## Shell

```s
#TEST_CASE init
$init 2 10
$show
player1: 1..........
player2: 2..........
traps__: ...........

$addTrap 2
$addTrap 4
$addTrap 8
$show
player1: 1..........
player2: 2..........
traps__: ..x.x...x..

#TEST_CASE move
$roll 1
player1 andou para 1

#TEST_CASE trap
$roll 2
player2 andou para 2
player2 caiu em uma armadilha

#TEST_CASE show
$show
player1: .1.........
player2: ..2........
traps__: ..x.x...x..

#TEST_CASE keep trapped
$roll 4
player1 andou para 5
$roll 3
player2 continua preso

$show
player1: .....1.....
player2: ..2........
traps__: ..x.x...x..

#TEST_CASE trap
$roll 3
player1 andou para 8
player1 caiu em uma armadilha

#TEST_CASE release
$roll 6
player2 se libertou

$show
player1: ........1..
player2: ..2........
traps__: ..x.x...x..

#TEST_CASE win
$roll 2
player1 se libertou
$roll 10
player2 ganhou

#TEST_CASE boundary
$show
player1: ........1..
player2: ..........2
traps__: ..x.x...x..

#TEST_CASE game over
$roll 1
game is over
$end
```
