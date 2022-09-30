# Cofre & Utilizando enum para definir as moedas e um bool para controlar o estado do porco

![](cover.jpg)

[](toc)

- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
[](toc)

## Intro
O sistema deverá:

- Gerenciar um cofrinho do tipo Porquinho capaz de guardar moedas e itens.
- As moedas devem ser criadas através de uma `enum`.
- Ambos moedas e itens tem um método getVolume() e getDescription().
- O volume do cofre incrementa conforme ele recebe itens e moedas.
- A lógica da utilização do cofre é:
    - Para inserir moedas e itens o cofre deve estar inteiro.
    - Para obter moedas e itens o cofre deve estar quebrado.
    - Ao quebrar, o volume do porco deve ser zerado e o status de broken deve ser alterado para true.
    - Ao obter moedas e itens, os atribuitos `valor` e `itens` do porco devem ser zerados.

***
## Guide
![](diagrama.png)

- [Solver.java](.cache/draft.java), [Shell.java](./Shell.java)
- [solver.cpp](.cache/draft.cpp)
- [solver.ts](.cache/draft.ts), [shell.ts](./shell.ts)

***
## Shell

```sh
#__case init
$init 20
$show
[] : 0.00$ : 0/20 : unbroken

#__case insert
$addCoin 10
$show
[] : 0.10$ : 1/20 : unbroken

$addCoin 50
$show
[] : 0.60$ : 4/20 : unbroken

#__case itens
$addItem ouro 3
$show
[ouro] : 0.60$ : 7/20 : unbroken

$addItem passaporte 2
$show
[ouro, passaporte] : 0.60$ : 9/20 : unbroken

#__case failed break
$getItems
fail: you must break the pig first
[]

$getCoins
fail: you must break the pig first
0.00

$show
[ouro, passaporte] : 0.60$ : 9/20 : unbroken

#__case breaking
$break
$show
[ouro, passaporte] : 0.60$ : 0/20 : broken

#__case getItems

$getItems
[ouro, passaporte]

$show
[] : 0.60$ : 0/20 : broken

#__case getCoins

$getCoins
0.60

$show
[] : 0.00$ : 0/20 : broken
$end
```

```sh
#__case
$init 10

$break

$addCoin 10
fail: the pig is broken

$show
[] : 0.00$ : 0/10 : broken

$addItem bilhete 2
fail: the pig is broken

$show
[] : 0.00$ : 0/10 : broken

$end
```

```sh
#__case full coin
$init 5

$addCoin 10
$addCoin 25
$show
[] : 0.35$ : 3/5 : unbroken

$addCoin 50
fail: the pig is full

$show
[] : 0.35$ : 3/5 : unbroken

#__case full item
$addItem ouro 1

$show
[ouro] : 0.35$ : 4/5 : unbroken

$addItem pirulito 2
fail: the pig is full

$show
[ouro] : 0.35$ : 4/5 : unbroken

$end
```