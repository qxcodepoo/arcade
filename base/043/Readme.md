# Cofre & Utilizando enum para definir as moedas e um bool para controlar o estado do porco

![cover](cover.jpg)

[](toc)

- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
[](toc)

## Intro
O sistema deverá:

- Gerenciar um cofrinho do tipo Porquinho capaz de guardar moedas e itens.
- As moedas devem ser criadas através de uma `enum`.
- Ambos moedas e itens deve implementar a Interaface Valuable.
- O volume do cofre incrementa conforme ele recebe itens e moedas.
- A lógica da utilização do cofre é:
    - Para inserir moedas e itens, o cofre deve estar inteiro.
    - Para obter moedas e itens, o cofre deve estar quebrado.
    - Ao quebrar, o volume do porco deve ser zerado e o status de broken deve ser alterado para true.
    - Ao obter moedas e itens, você deve retornar os objetos armazenados.
    - Calcular o valor e o volume atual do porco deve ser feito através do método getValue() e getVolume().
    - Moedas e Itens devem ser armazenados em uma mesma lista de Valuables.

***

## Guide
![diagrama](diagrama.png)

- [Solver.java](.cache/draft.java)

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
[M10:0.10:1] : 0.10$ : 1/20 : unbroken

$addCoin 50
$show
[M10:0.10:1, M50:0.50:3] : 0.60$ : 4/20 : unbroken

#__case itens
$addItem ouro 3 50.0
$show
[M10:0.10:1, M50:0.50:3, ouro:50.00:3] : 50.60$ : 7/20 : unbroken

$addItem passaporte 2 0.0
$show
[M10:0.10:1, M50:0.50:3, ouro:50.00:3, passaporte:0.00:2] : 50.60$ : 9/20 : unbroken

#__case failed break
$getItems
fail: you must break the pig first
[]

$getCoins
fail: you must break the pig first
[]

$show
[M10:0.10:1, M50:0.50:3, ouro:50.00:3, passaporte:0.00:2] : 50.60$ : 9/20 : unbroken

#__case breaking
$break
$show
[M10:0.10:1, M50:0.50:3, ouro:50.00:3, passaporte:0.00:2] : 50.60$ : 0/20 : broken

#__case getItems

$getItems
[ouro:50.00:3, passaporte:0.00:2]

$show
[M10:0.10:1, M50:0.50:3] : 0.60$ : 0/20 : broken

#__case getCoins

$getCoins
[M10:0.10:1, M50:0.50:3]

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

$addItem bilhete 2 0.00
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
[M10:0.10:1, M25:0.25:2] : 0.35$ : 3/5 : unbroken

$addCoin 50
fail: the pig is full

$show
[M10:0.10:1, M25:0.25:2] : 0.35$ : 3/5 : unbroken

#__case full item
$addItem ouro 1 100.0

$show
[M10:0.10:1, M25:0.25:2, ouro:100.00:1] : 100.35$ : 4/5 : unbroken

$addItem pirulito 2 5.00
fail: the pig is full

$show
[M10:0.10:1, M25:0.25:2, ouro:100.00:1] : 100.35$ : 4/5 : unbroken

$end
```