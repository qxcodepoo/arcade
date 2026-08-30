# Toalha com testes

<!-- toc-table -->
[Intro](#intro) | [Guide](#guide) | [Testes](#testes) | [Draft](#draft)
-- | -- | -- | --
<!-- toc-table -->

![_](assets/cover.webp)

## Intro

* Crie uma classe Toalha `Towel` com os atributos cor `color`, tamanho `size` e umidade `wetness`.
* Crie um construtor que inicialize `color` e `size` com os valores recebidos como parâmetros e `wetness` com `0`.
* Crie um método torcer `wringOut` que zera o atributo `wetness` da toalha.
* Crie um método `getMaxWetness` que retorna o valor máximo de umidade que a toalha pode atingir.
* O máximo de umidade depende do tamanho da toalha:

  * `P` → `10`
  * `M` → `20`
  * `G` → `30`
* Crie um método enxugar `dry` que recebe uma quantidade inteira `amount` e tenta usar a toalha para enxugar essa quantidade de água.

  * Enxugar aumenta a umidade (`wetness`) da toalha.
  * A umidade nunca pode ultrapassar o limite máximo da toalha.
  * Se a toalha conseguir absorver toda a quantidade solicitada, retorne `true`.
  * Se a toalha não tiver capacidade para absorver toda a quantidade, absorva apenas o que for possível até atingir o limite máximo e retorne `false`.
* Crie um método `isDry` que retorna `true` se a umidade (`wetness`) for `0` e `false` caso contrário.

deve existir uma separação entre lógica de negócio e interação com o usuário.

- A classe Towel deve conter seu estado e suas regras de negócio.
- A classe Shell representa a interface de linha de comando e deve cuidar da leitura dos comandos e da apresentação dos resultados.
- A classe Towel não deve utilizar nenhum comando de impressão como `print` ou `System.out`, deve apenas retornar valores.
- O Shell deve interpretar esse resultado e decidir qual mensagem apresentar ao usuário.

## Guide

![diagrama](assets/diagrama.png)

[![youtube icon](../youguide.webp)](https://youtu.be/S956ep2PSzI?si=q9IYxafhWjaDVHTp)


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
$enxugar 6
fail: toalha nao conseguiu enxugar tudo

#TEST_CASE umidade maxima alcançada
$mostrar
Cor: azul, Tamanho: P, Umidade: 10

$enxugar 5
fail: toalha nao conseguiu enxugar tudo

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
$mostrar
Cor: verde, Tamanho: G, Umidade: 30

#TEST_CASE não passa do limite
$enxugar 1
fail: toalha nao conseguiu enxugar tudo
$mostrar
Cor: verde, Tamanho: G, Umidade: 30
$end
```

## Draft

<!-- links .cache/drafts -->
<!-- links -->
