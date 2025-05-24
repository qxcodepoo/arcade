# Toalha com testes

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Testes](#testes) | [Draft](#draft)
-- | -- | -- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/enxugar/cover.jpg)

## Intro

- Crie uma classe Toalha `Towel` com os atributos cor `color`, tamanho `size` e umidade `wetness`.
- Crie um construtor que inicialize todos os atributos cor e tamanho com valores recebidos como parâmetro e umidade com 0.
- Crie um método enxugar `dry` que recebe um valor inteiro quantidade `amout` e AUMENTA o atributo umidade da toalha.
- Crie um método torcer `wringOut` que zera o atributo umidade da towel.
- Crie um método para pegar máximo de umidade `getMaxWetness` que retorna o valor máximo de umidade que essa toalha pode ter.
- O máximo de umidade que uma toalha pode ter é de acordo com o tamanho dela:
  - `P` -> 10
  - `M` -> 20
  - `G` -> 30
- Crie um método que retorna se a toalha esta seca `isDry`, que retorna `true` se a umidade da toalha for 0 e `false` caso contrário.

## Guide

[![youtube icon](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/enxugar/../youguide.png)](https://youtu.be/S956ep2PSzI?si=q9IYxafhWjaDVHTp)

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/enxugar/diagrama.png)

## Testes

```bash
#TEST_CASE criação
$criar azul P
$mostrar
Cor: azul, Tamanho: P, Umidade: 0

#TEST_CASE esta_seca
$seca
sim

#TEST_CASE enxugar
$enxugar 5
$mostrar
Cor: azul, Tamanho: P, Umidade: 5

#TEST_CASE nao esta seca
$seca
nao

#TEST_CASE toalha encharcada
$enxugar 5
toalha encharcada

#TEST_CASE umidade maxima alcançada
$mostrar
Cor: azul, Tamanho: P, Umidade: 10

$enxugar 5
toalha encharcada

$mostrar
Cor: azul, Tamanho: P, Umidade: 10

#TEST_CASE torcer
$torcer
$mostrar
Cor: azul, Tamanho: P, Umidade: 0

$end

```

---

```bash

#TEST_CASE criação
$criar verde G

$mostrar
Cor: verde, Tamanho: G, Umidade: 0

#TEST_CASE limite de 30 e encharcada

$enxugar 30
toalha encharcada
$mostrar
Cor: verde, Tamanho: G, Umidade: 30

#TEST_CASE não passa do limite
$enxugar 1
toalha encharcada
$mostrar
Cor: verde, Tamanho: G, Umidade: 30
$end
```

## Draft

<!-- links .cache/draft -->
- cpp
  - [shell.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/enxugar/.cache/draft/cpp/shell.cpp)
- java
  - [Shell.java](https://github.com/qxcodepoo/arcade/blob/master/base/enxugar/.cache/draft/java/Shell.java)
- ts
  - [shell.ts](https://github.com/qxcodepoo/arcade/blob/master/base/enxugar/.cache/draft/ts/shell.ts)
<!-- links -->
