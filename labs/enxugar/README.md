# Enxugar: comportamento observável e Shell

<!-- toc-table -->
[Intro](#intro) | [Regras](#regras) | [Diagrama](#diagrama) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft)
-- | -- | -- | -- | -- | --
<!-- toc-table -->

![_](assets/cover.webp)

## Intro

O objetivo dessa atividade é praticar uma classe de domínio que controla a umidade de uma toalha e retorna o resultado de cada operação.

Esta versão acrescenta um `Shell` para testar o comportamento observável sem mover as regras de umidade para a entrada e saída.

## Regras

- A classe `Towel` possui cor `color`, tamanho `size` e umidade `wetness`.
- O construtor recebe cor e tamanho e inicia `wetness` com `0`.
- `wringOut()` zera a umidade.
- `getMaxWetness()` retorna `10` para `P`, `20` para `M` e `30` para `G`.
- `dry(amount)` aumenta a umidade sem ultrapassar o limite; retorna `true` quando absorve tudo e `false` quando absorve apenas o possível.
- `isDry()` retorna `true` quando a umidade é `0`.
- O `toString` retorna `Color: {color}, Size: {size}, Wetness: {wetness}`.
- `Towel` não deve ler entrada nem imprimir dados; o `Shell` interpreta os retornos e apresenta as mensagens.
- Se `dry(amount)` retornar `false`, o `Shell` deve imprimir `fail: towel is soaked`.
- A classe permanece única porque suas regras formam um comportamento coeso. Não crie classes separadas para cor, tamanho ou umidade nesta etapa.

## Diagrama

O diagrama representa uma classe simples e coesa. A atividade reforça a separação inicial entre domínio e `Shell`, sem antecipar modificadores de acesso do próximo bloco.

![diagrama](assets/diagrama.png)

## Guide

`Towel` concentra apenas o estado e as regras de umidade. O `Shell` lê comandos e decide o que apresentar.

[Vídeo de apoio](https://youtu.be/S956ep2PSzI?si=q9IYxafhWjaDVHTp)

- Comece pelo construtor e pelo `toString`, usando `$create` e `$show`.
- Implemente `getMaxWetness`, porque `dry` depende desse limite.
- Faça `dry` retornar `false` quando a toalha não conseguir absorver toda a quantidade.
- No `Shell`, transforme esse `false` em `fail: towel is soaked`.

Pergunta de reflexão: por que o limite de umidade pertence à `Towel` e não ao `Shell`?

## Shell

```bash
#TEST_CASE small creation
$create azul P
$show
Color: azul, Size: P, Wetness: 0

#TEST_CASE is dry
$is_dry
yes

#TEST_CASE dry
$dry 5
$show
Color: azul, Size: P, Wetness: 5

#TEST_CASE is not dry
$is_dry
no

#TEST_CASE soaked towel
$dry 6
fail: towel is soaked

#TEST_CASE max wetness reached
$show
Color: azul, Size: P, Wetness: 10

$dry 5
fail: towel is soaked

$show
Color: azul, Size: P, Wetness: 10

#TEST_CASE wring out
$wring_out
$show
Color: azul, Size: P, Wetness: 0

$end

```

---

```bash

#TEST_CASE large creation
$create verde G

$show
Color: verde, Size: G, Wetness: 0

#TEST_CASE limit 30 and soaked

$dry 30
$show
Color: verde, Size: G, Wetness: 30

#TEST_CASE does not pass limit
$dry 1
fail: towel is soaked
$show
Color: verde, Size: G, Wetness: 30
$end
```

## Draft

<!-- links .cache/starter -->
<!-- links -->
