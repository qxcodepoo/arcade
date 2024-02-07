# Alimente, brinque e mate o @tamagotchi

Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/tamagotchi/Readme.md)

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/tamagotchi/cover.jpg)

Você deve implementar um simulador de bichinho virtual. Ele poderá comer, brincar, dormir e tomar banho. E eventualmente morrerá, se você não cuidar bem dele.

***

## Intro

Seu sistema deverá:

- **Inicializar**
  - passando energia, saciedade e limpeza máximas do pet.
  - Todos os níveis devem ser iniciados no máximo na criação do pet.
  - Os outros atributos são
    - diamantes, que ele vai ganhar jogando.
    - e idade que aumenta a cada ação realizada,
    - ambos iniciando em 0.
- **Comendo, Jogando, Dormindo e tomando banho**
  - Cada operação causa aumento e reduções nos atributos.
  - Nenhum atributo pode passar do máximo ou ir abaixo de 0.
- **Morrendo**
  - Se algum atributo chegar a 0, o pet morre e nenhuma ação pode ser feita a não ser mostrar os dados.

***

## Draft

- [solver.java](https://github.com/qxcodepoo/arcade/blob/master/base/tamagotchi/.cache/draft.java)
- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/tamagotchi/.cache/draft.cpp)
- [solver.ts](https://github.com/qxcodepoo/arcade/blob/master/base/tamagotchi/.cache/draft.ts)

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/tamagotchi/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts

+class Pet {
    ' se o pet está vivo
    - alive     : boolean

    - clean     : int
    - cleanMax  : int
    - energy    : int
    - energyMax : int
    - hungry    : int
    - hungryMax : int
    
    - age       : int
    - diamonds  : int
    __

    ' verifique se o pet está vivo
    ' se estiver morto emita uma mensagem de erro
    ' retorne true ou false de acordo com o estado do pet
    - testAlive() : boolean
    __

    ' inicialize todos os atributos
    ' inicialize os atributos Max de acordo com os parâmetros
    '   do construtor
    ' hungry, energy e clean iniciam com os valores máximo
    ' idade e diamantes iniciam com 0
    ' alive deve ser true
    + Pet(energyMax : int, hungryMax : int, cleanMax : int)
    + toString() : string
    __
    
    ' invoque o método testAlive para verificar se o pet esta vivo
    ' altere os atributos do pet de acordo com as regras de comer
    ' utilizando os métodos get e set
    + eat()
    
    
    ' invoque o método testAlive para verificar se o pet esta vivo
    ' altere os atributos do pet de acordo com as regras de jogar
    ' utilizando os métodos get e set
    + play()
    
    
    ' invoque o método testAlive para verificar se o pet esta vivo
    ' altere os atributos do pet de acordo com as regras de comer
    ' utilizando os métodos get e set
    + shower()
    
    ' invoque o método testAlive para verificar se o pet esta vivo
    ' altere os atributos do pet de acordo com as regras de comer
    ' utilizando os métodos get e set
    + sleep()
    __

    + getClean()      : int
    + getCleanMax()   : int
    + getEnergy()     : int
    + getEnergyMax()  : int
    + getHungry()     : int
    + getHungryMax()  : int
    
    ' atribui o valor do parâmetro ao atributo clean
    ' se o valor for menor que 0 o pet morre de sujo
    ' garanta que os valores ficarão no interalo 0 - max

    + setClean (value : int)
    
    ' atribui o valor de energia
    ' se o valor ficar abaixo de 0, o pet morre de fraqueza
    ' garanta que os valores ficarão no interalo 0 - max
    + setEnergy(value : int)
    
    ' atribui o valor da hungry
    ' se o valor for menor ou igual a 0 o pet morre de fome
    ' garanta que os valores ficarão no interalo 0 - max
    + setHungry(value : int)
}

class Legenda {
  + atributoPublic
  - atributoPrivate
  # atributoProtected
  __
  + métodoPublic()
  - métodoPrivate()
  # métodoProtected()
}

```

<!-- load -->

[![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/tamagotchi/../_images/resolucao.png)](https://youtu.be/X6SV1izH67w)

***

## Shell

```bash
#__case inicio
# O comando "$init energia saciedade limpeza" recebe os valores do pet.
# O pet inicia com 0 diamantes e 0 de idade.
# Toda vez que $init é chamado, um novo pet é criado.
$init 20 10 15
# O comando "$show" mostra os parâmetros do Pet na seguinte ordem
# Energia/Max, Saciedade/Max, Limpeza/Max, Diamantes, Idade
$show
E:20/20, S:10/10, L:15/15, D:0, I:0
$init 10 20 50
$show
E:10/10, S:20/20, L:50/50, D:0, I:0
$end
```

***

```bash
#__case play - Brincar 
# O comando "$play" altera em -2 energia, -1 saciedade, -3 limpeza, +1 diamante, +1 idade.
$init 20 10 15
$play
$show
E:18/20, S:9/10, L:12/15, D:1, I:1
$play
$show
E:16/20, S:8/10, L:9/15, D:2, I:2

#__case comer 
# O Comando "$eat" altera em -1 a energia, +4 a saciedade, -2 a limpeza, +0 diamantes,  +1 a idade
$eat
$show
E:15/20, S:10/10, L:7/15, D:2, I:3

#__case dormir
# O Comando "$sleep" aumenta energia até o máximo e idade aumenta do número de turnos que o pet dormiu.
# Também perde 1 de saciedade.
$sleep
$show
E:20/20, S:9/10, L:7/15, D:2, I:8

#__case tomar banho
# O comando "$shower" alteram em -3 energia, -1 na saciedade, MAX na limpeza, +0 diamantes, +2 na idade.
$shower
$show
E:17/20, S:8/10, L:15/15, D:2, I:10

#__case dormir sem sono
# Para dormir, precisa ter perdido pelo menos 5 unidades de energia
$sleep
fail: nao esta com sono

#__case morrer
# Se algum atributo atingir 0, o pet morre e não poderá executar nenhuma ação
$play
$play
$play
$play
$show
E:9/20, S:4/10, L:3/15, D:6, I:14
$play
fail: pet morreu de sujeira
$show
E:7/20, S:3/10, L:0/15, D:7, I:15
$play
fail: pet esta morto
$eat
fail: pet esta morto
$shower
fail: pet esta morto
$sleep
fail: pet esta morto
$end
```

***

```bash
#__case fraqueza
$init 5 10 10
$play
$play
$play
fail: pet morreu de fraqueza
#__case morto de fraqueza
$play
fail: pet esta morto
$show
E:0/5, S:7/10, L:1/10, D:3, I:3
$end
```

***

```bash
#__case fome
$init 10 3 10
$play
$play
$play
fail: pet morreu de fome
$play
fail: pet esta morto
$show
E:4/10, S:0/3, L:1/10, D:3, I:3
$end
```
