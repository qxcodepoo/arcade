---
index_content: |2
    - Descrição: o porquinho armazena moedas e itens até sua capacidade e pode ser quebrado para permitir extrações.
    - Domínio: moedas e itens são imutáveis; adições só ocorrem enquanto o porquinho está intacto e há volume disponível; depois da quebra, novas adições falham e moedas ou itens podem ser extraídos separadamente.
    - Objetivos: proteger capacidade e estado terminal, compor coleções de objetos imutáveis e preservar o estado após operações recusadas.
---
# [TRAIN] Guardando moedas e itens em um cofrinho

<!-- toc-table -->
[Intro](#intro) | [Regras](#regras) | [Exceções](#exceções) | [Diagrama](#diagrama) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft)
-- | -- | -- | -- | -- | -- | --
<!-- toc-table -->

![cover](assets/cover.webp)

## Intro

Esta atividade modela um porquinho com capacidade limitada que deixa de ser
utilizável quando é quebrado. O objetivo principal é proteger invariantes de
capacidade e de estado. Como objetivo secundário, a atividade pratica a
composição de objetos e a imutabilidade de valores armazenados.

## Regras

- `Coin` é uma `data class` imutável com `value: Double`, `volume: Int` e `label: String`. Os códigos disponíveis são `10`, `25`, `50` e `100`.
- `Item` é uma `data class` imutável com `label: String` e `volume: Int`.
- Moedas e itens são imutáveis depois de criados. Não há setters, pois alterar
  um objeto já guardado poderia quebrar a capacidade do porquinho.
- `Pig(capacity: Int)` começa intacto e vazio. Seu volume ocupado nunca ultrapassa a capacidade.
- `addCoin(coin: Coin): Unit` e `addItem(item: Item): Unit` lançam `PigError` se o porquinho estiver quebrado ou o objeto não couber.
- `breakPig(): Unit` muda o estado para quebrado uma única vez.
- `extractCoins(): List<Coin>` e `extractItems(): List<Item>` só funcionam depois da quebra; cada método devolve uma cópia e esvazia somente sua coleção.
- `value(): Double` soma o valor das moedas que ainda estão guardadas.
- `volume(): Int` soma os volumes enquanto intacto e retorna `0` depois da quebra.
- `toString(): String` mostra estado, coleções, valor e volume no formato dos testes.
- Uma adição que não cabe ou ocorre depois da quebra falha sem alterar o estado.
- Quebrar o porquinho é uma transição terminal para as operações de adição.
- Antes da quebra, não é possível extrair moedas ou itens.
- Depois da quebra, a extração devolve os objetos e esvazia apenas a coleção
  extraída. A lista devolvida é uma cópia.
- Depois da quebra, o volume ocupado é `0`, pois o porquinho deixou de funcionar
  como recipiente. O valor continua representando as moedas ainda guardadas.
- As classes de domínio não imprimem mensagens. Elas lançam `PigError`; o Shell converte as falhas para o texto observável.

## Exceções

`PigError` comunica as regras de estado e capacidade. O `Shell` captura essa exceção e apresenta a mensagem nela contida com o prefixo `fail:`. Moedas inválidas e comandos malformados são tratados pelo Shell, pois não correspondem a uma operação válida do domínio.

## Diagrama

`Pig` compõe coleções de `Coin` e `Item`, que são valores imutáveis. O recipiente começa intacto, controla a capacidade e, depois de quebrado, permite apenas as extrações.

```mermaid
%%{init: {'theme': 'base', 'fontFamily': 'monospace'}}%%
classDiagram
    direction LR

    class PigError {
        <<exception>>
    }

    class Coin {
        <<immutable>>
        +val value : Double
        +val volume : Int
        +val label : String
        +Coin(value : Double, volume : Int, label : String)
        +toString() String
    }

    class Item {
        <<immutable>>
        +val label : String
        +val volume : Int
        +Item(label : String, volume : Int)
        +toString() String
    }

    class Pig {
        -val capacity : Int
        -val coins : MutableList~Coin~
        -val items : MutableList~Item~
        -var broken : Boolean
        +Pig(capacity : Int)
        -checkCanAdd(volume : Int) Unit
        +addCoin(coin : Coin) Unit
        +addItem(item : Item) Unit
        +breakPig() Unit
        +extractCoins() List~Coin~
        +extractItems() List~Item~
        +value() Double
        +volume() Int
        +toString() String
    }

    class Shell {
        +main() Unit
    }

    Pig "1" *-- "0..*" Coin : stores
    Pig "1" *-- "0..*" Item : stores
    Pig ..> PigError : throws
    Shell ..> Pig : commands
```

## Guide

Implemente em incrementos pequenos:

1. Crie `Coin` e `Item` como `data class` imutáveis e implemente `toString()` no formato que aparece nos testes. O Shell seleciona a moeda pelo código recebido.
2. Crie `Pig(capacity: Int)` com coleções vazias e estado intacto. Implemente `volume`, `addCoin` e `addItem`, verificando primeiro o estado e a capacidade.
3. Implemente `value` e `toString`. O volume considera moedas e itens somente enquanto o porquinho está intacto; o valor das moedas continua disponível após a quebra.
4. Implemente `breakPig` como transição terminal. Uma segunda quebra lança `PigError` sem apagar conteúdo.
5. Implemente as extrações somente para o estado quebrado. Devolva uma cópia e limpe apenas a coleção extraída.
6. No Shell, mapeie códigos de moeda, crie itens, capture `PigError` e converta os resultados para a saída observável. O domínio não deve conhecer entrada ou saída.

A atividade usa somente três classes. `Coin` e `Item` representam objetos que
   podem ser guardados; `Pig` possui esses objetos e protege as invariantes do
   recipiente. Não há necessidade de uma classe para catálogo de moedas, um
   gerenciador de itens ou getters e setters para todos os atributos.

Perguntas de reflexão:

- Por que a capacidade deve ser verificada antes de adicionar o objeto?
- O que poderia ficar inconsistente se `Item` tivesse `setVolume`?
- Por que o valor continua disponível depois da quebra, mas o volume passa a ser
  zero?
- Por que extrair moedas não deve extrair os itens automaticamente?

## Shell

```bash
#TEST_CASE init and coins
$init 20
$show
state=intact : coins=[] : items=[] : value=0.00 : volume=0/20
$addCoin 10
$addCoin 50
$show
state=intact : coins=[0.10:1, 0.50:3] : items=[] : value=0.60 : volume=4/20
$end
```

```bash
#TEST_CASE items and capacity
$init 5
$addCoin 10
$addCoin 25
$addItem ouro 1
$show
state=intact : coins=[0.10:1, 0.25:2] : items=[ouro:1] : value=0.35 : volume=4/5
$addCoin 50
fail: the pig is full
$addItem pirulito 2
fail: the pig is full
$show
state=intact : coins=[0.10:1, 0.25:2] : items=[ouro:1] : value=0.35 : volume=4/5
$end
```

```bash
#TEST_CASE extraction before breaking
$init 10
$addCoin 10
$addItem bilhete 2
$extractItems
fail: you must break the pig first
$extractCoins
fail: you must break the pig first
$show
state=intact : coins=[0.10:1] : items=[bilhete:2] : value=0.10 : volume=3/10
$end
```

```bash
#TEST_CASE break and extraction
$init 20
$addCoin 10
$addCoin 50
$addItem ouro 3
$break
$show
state=broken : coins=[0.10:1, 0.50:3] : items=[ouro:3] : value=0.60 : volume=0/20
$addItem bilhete 1
fail: the pig is broken
$break
fail: the pig is already broken
$extractItems
[ouro:3]
$show
state=broken : coins=[0.10:1, 0.50:3] : items=[] : value=0.60 : volume=0/20
$extractCoins
[0.10:1, 0.50:3]
$show
state=broken : coins=[] : items=[] : value=0.00 : volume=0/20
$end
```

```bash
#TEST_CASE independent extraction
$init 10
$addCoin 100
$addItem passport 2
$break
$extractItems
[passport:2]
$show
state=broken : coins=[1.00:4] : items=[] : value=1.00 : volume=0/10
$extractCoins
[1.00:4]
$show
state=broken : coins=[] : items=[] : value=0.00 : volume=0/10
$end
```

## Draft

<!-- links .cache/starter -->
<!-- links -->
<!-- MERMAID -->
<!-- KOTLIN -->
