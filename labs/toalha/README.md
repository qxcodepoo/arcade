---
index_content: |2
    - Descrição: a toalha deve controlar seu estado de umidade e fornecer métodos para enxugar, torcer e consultar seu estado.
    - Domínio: o quanto a toalha enxuga depende do seu tamanho e ela não pode suportar água além de sua capacidade.
    - Objetivos: identificar estado e comportamento em uma classe coesa.
---
# [GUIDE] Toalha que enxuga

<!-- toc-table -->
[Intro](#intro) | [Regras](#regras) | [Diagrama](#diagrama) | [Guide](#guide)
-- | -- | -- | --
<!-- end -->

![_](assets/cover.webp)

## Intro

O objetivo dessa atividade é implementar uma toalha que possa absorver água, ser torcida e informar seu estado.

O foco é observar como uma classe junta estado e comportamento: a própria `Towel` controla sua umidade, enquanto o programa de demonstração apenas cria objetos e chama métodos.

## Regras

- A classe Toalha `Towel` possui as propriedades privadas cor `color: String`, tamanho `size: String` e umidade `wetness: Int`.
- O construtor `Towel(color: String, size: String)` inicia `wetness` com `0`.
- O método `absorb(waterAmount: Int): Boolean` recebe uma quantidade de água e aumenta `wetness` sem ultrapassar o limite.
  - Se `waterAmount` for negativo, retorna `false` e preserva `wetness`.
  - Se a quantidade ultrapassar a capacidade, armazena apenas o limite e retorna `false`.
  - Caso consiga absorver toda a quantidade, retorna `true`.
- O método `wringOut(): Unit` zera `wetness`.
- O método `maxWetness(): Int` retorna o limite de umidade conforme o tamanho:
  - `P` -> `10`
  - `M` -> `20`
  - `G` -> `30`
- O método `isDry(): Boolean` retorna `true` quando `wetness` é `0` e `false` caso contrário.
- `toString(): String` retorna o estado no formato `{color} {size} {wetness}`.
- A classe `Towel` não deve ler entrada nem imprimir dados.
- Use a função `main()` do programa de demonstração Kotlin para verificar o comportamento da classe.

## Diagrama

`Towel` concentra cor, tamanho e umidade porque esses dados formam um comportamento coeso. `maxWetness()` mantém a regra da capacidade junto ao tamanho; `absorb()` aplica o limite; `Main` apenas cria a toalha e demonstra as operações.

```mermaid
%%{init: { "fontFamily": "monospace" } }%%
classDiagram
    direction TB

    class Towel {
        -val color : String
        -val size : String
        -var wetness : Int
        +Towel(color : String, size : String)
        +maxWetness() Int
        +absorb(waterAmount : Int) Boolean
        +wringOut() Unit
        +isDry() Boolean
        +toString() String
    }

    class Main {
        +main() Unit
    }

    Main ..> Towel : creates and uses
```

## Guide

Implemente e verifique a classe em partes: estado inicial, absorção, limite de umidade, torção e consulta de estado.

- Comece pelo construtor e confira se uma toalha nova sempre inicia com `wetness` igual a `0`.
- Implemente `maxWetness(): Int` antes de `absorb`, porque o limite depende do tamanho.
- Em `absorb(waterAmount: Int): Boolean`, rejeite quantidades negativas e aumente a umidade apenas até o limite retornado por `maxWetness`.
- Em `wringOut()`, volte a umidade para `0`.
- Em `isDry()`, apenas consulte o estado, sem alterar a toalha.

Pergunta de reflexão: se o cálculo do limite ficasse espalhado pelo programa de demonstração, que mudança seria mais difícil quando surgisse um novo tamanho?

Verifique estes casos: uma toalha `P` começa seca, `absorb(5)` resulta em `wetness = 5`, `absorb(10)` limita a umidade em `10` e retorna `false`, `absorb(-1)` preserva a umidade, e `wringOut()` faz `isDry()` retornar `true`.
