# MotoUber com motorista e passageiro

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell)
-- | -- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/motouber/cover.jpg)

## Intro

- Você vai gerenciar um objeto da classe moto que faz corridas com passageiros.
- A moto pode ter um motorista e pode ter um passageiro.
- A moto deve registrar o custo atual da corrida.
- O passageiro deve pagar o motorista quando descer da moto.
- Motorista e Passageiro são pessoas que tem nome e dinheiro.
- O passageiro não pode subir na moto se não tiver motorista.
- Quando o passageiro entra na moto, começa a contagem do custo da corrida.
- Cada km percorrido aumenta o custo da corrida em 1 real.
- Na hora de desembarcar, o passageiro paga o motorista de acordo com o que foi percorrido.
- Se não tiver dinheiro suficiente, o passageiro dá tudo que tem.
- O motorista sempre recebe o valor completo da corrida, porque o Uber paga o que falta.

## Guide

[![youtube icon](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/motouber/../youguide.png)](https://youtu.be/SR5B0QkEFpc?si=wHrdAy-3_aZ5Pv3j)

- Crie a classe Pessoa com os atributos nome e dinheiro.
- Crie a classe Moto com os atributos custo, motorista e passageiro.
- Ambas as classes devem ter atributos privados.
- Crie os métodos que julgar necessário com os devidos modificadores de acesso.

## Shell

```bash
#TEST_CASE criar
$show
Cost: 0, Driver: None, Passenger: None

#TEST_CASE inserir motorista
$setDriver Tobias 50
$show
Cost: 0, Driver: Tobias:50, Passenger: None

#TEST_CASE inserir passageiro
$setPass Ana 20
$show
Cost: 0, Driver: Tobias:50, Passenger: Ana:20

#TEST_CASE subir passageiro
$drive 10
$show
Cost: 10, Driver: Tobias:50, Passenger: Ana:20

#TEST_CASE descer passageiro
$leavePass
Ana:10 left

$show
Cost: 0, Driver: Tobias:60, Passenger: None

$end
```

---

```bash
#TEST_CASE criar
$show
Cost: 0, Driver: None, Passenger: None
$setDriver Tobias 20
$show
Cost: 0, Driver: Tobias:20, Passenger: None

$setPass Ana 10
$show
Cost: 0, Driver: Tobias:20, Passenger: Ana:10

#TEST_CASE Dirigir e Dirigir

$drive 20
$show
Cost: 20, Driver: Tobias:20, Passenger: Ana:10

$drive 10
$show
Cost: 30, Driver: Tobias:20, Passenger: Ana:10

#TEST_CASE descer passageiro fiado

$leavePass
fail: Passenger does not have enough money
Ana:0 left

$show
Cost: 0, Driver: Tobias:50, Passenger: None

$end
```
