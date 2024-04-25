# Guardando moedas e itens em um @porquinho

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/porquinho/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo porquinho`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/porquinho/cover.jpg)

## Intro

O sistema deverá:

- Gerenciar um cofrinho do tipo Porquinho capaz de guardar moedas e itens.
- As moedas devem ser criadas através de uma `enum`.
- Ambos moedas e itens tem um método getVolume() e getLabel().
- O volume do cofre incrementa conforme ele recebe itens e moedas.
- A lógica da utilização do cofre é:
  - Para inserir moedas e itens o cofre deve estar inteiro.
  - Para extrair moedas e itens o cofre deve estar quebrado.
  - Ao quebrar, o volume do porco deve ser zerado e o status de broken deve ser alterado para true.
  - Ao extrair moedas e itens, os atribuitos `valor` e `itens` devem se tornar listas vazias.

***

## Draft

- [draft.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/porquinho/.cache/draft.cpp)
- [draft.java](https://github.com/qxcodepoo/arcade/blob/master/base/porquinho/.cache/draft.java)
- [draft.ts](https://github.com/qxcodepoo/arcade/blob/master/base/porquinho/.cache/draft.ts)

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/porquinho/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts

class Coin {
  - value  : double
  - volume : int
  - label  : string
  __
  ' static const Coin C10; //c++
  + {static} C10  : Coin
  + {static} C25  : Coin
  + {static} C50  : Coin
  + {static} C100 : Coin
  __
  - Coin(value: double, volume: int, label: string)
  __
  + getValue()  : double
  + getVolume() : int
  + getLabel()  : string
  __
  ' retorna value:volume
  + toString() : string
}

class Item {
  - label  : string
  - volume : int
  __
  + Item(label : string, volume : int)
  __
  + getLabel()  : string
  + getVolume() : int
  + setLabel (label  : string)
  + setVolume(volume : int)
  __
  ' retorna label:volume
  + toString() : String
}

class Pig {
  - broken    : boolean

  - coins     : Array<Coin>
  - items     : Array<Item>

  - volumeMax : int
  __
  
  ' inicializa o volumeMax
  + Pig(volumeMax : int)
  
  ' se nao estiver quebrado e couber, adicione a moeda ao vetor de moedas
  + addCoin(coin  : Coin) : boolean
  
  ' se não estiver quebrado e couber, adicione o item ao vetor de itens
  + addItem(item  : Item) : boolean
  
  ' se o porco não estiver quebrado, quebre o porco
  + breakPig() : boolean
  
  ' se estiver quebrado, pegue e retorne as moedas
  ' se não estiver quebrado, retorne um vetor vazio
  + extractCoins() : Array<Coin>
  
  ' se estiver quebrado, pegue e retorne os itens
  ' se não estiver quebrado, retorne um vetor vazio
  + extractItems() : Array<Item>
  
  ' retorna uma string com uma lista de itens, valor, volume / volumeMax, 
  ' e se o porquinho está quebrado ou não
  + toString() : String
  __
  ' se estiver quebrado
    ' retorne zero
  ' se não estiver quebrado
    ' percorre o vetor de moedas e o vetor de itens somando o volume de cada um
  + getVolume()    : int

  ' percorre o vetor de moedas somando o valor de cada moeda
  + getValue()     : double

  ' retorna o volumeMax
  + getVolumeMax() : int

  ' retorna se o porquinho está quebrado ou não
  + isBroken()     : boolean
}
```

<!-- load -->

***

## Shell

```py
#__case init
$init 20
$show
state=intact : coins=[] : items=[] : value=0.00 : volume=0/20

#__case insert
$addCoin 10
$addCoin 50
$show
state=intact : coins=[0.10:1, 0.50:3] : items=[] : value=0.60 : volume=4/20

#__case itens
$addItem ouro 3
$show
state=intact : coins=[0.10:1, 0.50:3] : items=[ouro:3] : value=0.60 : volume=7/20

$addItem passaporte 2
$show
state=intact : coins=[0.10:1, 0.50:3] : items=[ouro:3, passaporte:2] : value=0.60 : volume=9/20

#__case failed break
$extractItems
fail: you must break the pig first
[]

$extractCoins
fail: you must break the pig first
[]

$show
state=intact : coins=[0.10:1, 0.50:3] : items=[ouro:3, passaporte:2] : value=0.60 : volume=9/20

#__case breaking
$break
$show
state=broken : coins=[0.10:1, 0.50:3] : items=[ouro:3, passaporte:2] : value=0.60 : volume=0/20

#__case getItems

$extractItems
[ouro:3, passaporte:2]

$show
state=broken : coins=[0.10:1, 0.50:3] : items=[] : value=0.60 : volume=0/20

#__case getCoins

$extractCoins
[0.10:1, 0.50:3]

$show
state=broken : coins=[] : items=[] : value=0.00 : volume=0/20
$end
```

***

```sh
#__case
$init 10

$break

$addCoin 10
fail: the pig is broken


$show
state=broken : coins=[] : items=[] : value=0.00 : volume=0/10

$addItem bilhete 2
fail: the pig is broken

$show
state=broken : coins=[] : items=[] : value=0.00 : volume=0/10

$end
```

***

```sh
#__case full coin
$init 5

$addCoin 10
$addCoin 25
$show
state=intact : coins=[0.10:1, 0.25:2] : items=[] : value=0.35 : volume=3/5

$addCoin 50
fail: the pig is full

$show
state=intact : coins=[0.10:1, 0.25:2] : items=[] : value=0.35 : volume=3/5

#__case full item
$addItem ouro 1

$show
state=intact : coins=[0.10:1, 0.25:2] : items=[ouro:1] : value=0.35 : volume=4/5

$addItem pirulito 2
fail: the pig is full

$show
state=intact : coins=[0.10:1, 0.25:2] : items=[ouro:1] : value=0.35 : volume=4/5

$end
```
