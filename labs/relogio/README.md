---
index_content: |2
    - Descrição: o relógio controla hora, minuto e modo de exibição, além de avançar um minuto por vez.
    - Domínio: atributos com valores válidos; validação individual de cada atributo, passagem do tempo, mostrar a hora em 24h ou AM/PM não altera a hora interna.
    - Objetivos: o validações independentes de cada atributo e manter o estado interno variando a forma como a hora é exibida.
---
# [ALONE] Hora 24h ou AM/PM

<!-- toc-table -->

![cover](assets/cover.webp)

## Intro

Seu objetivo é construir uma classe `Time` que garanta que hora e minuto permaneçam válidos.

Nesta atividade você vai consolidar **encapsulamento**, consultas, setters validadores, invariantes de estado e separação entre domínio e interface. O relógio protege seus atributos; o `Shell` interpreta comandos e imprime mensagens.

O modelo usa notação Kotlin: propriedades e parâmetros são escritos como `name: Type`, e o tipo de retorno vem depois dos parênteses, como em `setHour(hour: Int): Boolean`.

### Mensagens do programa

As explicações da atividade estão em português, mas o texto produzido pelo programa deve ficar em inglês:

- `fail: invalid hour`
- `fail: invalid minute`
- `fail: invalid command`

## Regras

- Construtor
- `Time()` não recebe parâmetros e inicializa `hour: Int` e `minute: Int` com `0`, no modo 24h.
- Crie as consultas `getHour(): Int`, `getMinute(): Int` e `isAm(): Boolean`.
  - `getHour(): Int` retorna a hora interna no modo 24h. No modo 12h, retorna uma hora entre `1` e `12`.
  - `isAm(): Boolean` retorna se a hora interna é anterior a `12`.
  - O estado booleano `is24hMode: Boolean` não precisa de getter ou setter: `toggleMode(): Unit` é a operação responsável por alterná-lo.
- Crie os setters `setHour(hour: Int): Boolean` e `setMinute(minute: Int): Boolean`.
  - Os métodos set devem garantir que o valor atribuído sempre seja válido, ou não realizar nenhuma mudança.
  - Os setters devem retornar sucesso ou falha sem imprimir mensagens.
  - No comando `$set`, cada campo válido deve ser atualizado mesmo que outro campo do mesmo comando seja inválido.
- `toString(): String`
  - Retorne a hora mostrando também o modo de exibição.
  - No modo 24h, use o formato `24h -> HH:MM`.
  - No modo 12h, use o formato `12h -> HH:MM AM` ou `12h -> HH:MM PM`.
  - Formate números menores que `10` com dois dígitos, como `01`, `02` e `03`.
- Nos métodos set, realize a validação dos valores.
  - Hora deve ser entre 0 e 23.
  - Minuto deve ser entre 0 e 59.
  - Quando um valor for inválido, o campo correspondente deve manter o valor anterior.
- Próximo minuto `nextMinute(): Unit`
  - Incremente o minuto em `1`.
  - Se o minuto for 59, ele deve ser zerado e a hora incrementada.
  - Se a hora for 23, ela deve ser zerada.
- Modo de exibição
  - O relógio deve iniciar em modo 24h.
  - O comando `$mode` deve alternar entre o modo 24h e o modo 12h.
  - A hora interna continua sendo guardada em 24h. O modo 12h muda apenas a forma de exibir a hora.
- A classe `Time` não deve ler entrada nem imprimir mensagens. O `Shell` deve interpretar os retornos `Boolean` dos setters e imprimir as falhas.
- O comando `$init hour minute` não imprime mensagens de falha. Ele cria um novo relógio e tenta aplicar cada campo com os setters; cada valor inválido permanece em `0`.

## Diagrama

As constantes `MIN_VALUE`, `MAX_HOUR`, `MAX_MINUTE` e `MID_DAY` definem os limites do domínio. Os setters retornam `Boolean` e concentram a validação de cada campo; `nextMinute()` coordena a passagem de minuto e hora sem depender do `Shell`. O modo de exibição, armazenado em `is24hMode: Boolean`, muda apenas a representação textual da hora.

```mermaid
%%{init: { "fontFamily": "monospace" } }%%
classDiagram
    direction TB

    class Time {
        +MIN_VALUE : Int$
        +MAX_HOUR : Int$
        +MAX_MINUTE : Int$
        +MID_DAY : Int$
        -var hour : Int
        -var minute : Int
        -var is24hMode : Boolean
        +Time()
        +getHour() Int
        +getMinute() Int
        +isAm() Boolean
        +setHour(hour : Int) Boolean
        +setMinute(minute : Int) Boolean
        +nextMinute() Unit
        +toggleMode() Unit
        +toString() String
    }

    class Shell {
        +main() Unit
    }

    Shell ..> Time : creates and uses
```

## Guide

Para formatar com 2 dígitos utilize a seguinte estratégia:

```kotlin
override fun toString(): String {
    val hourText: String = hour.toString().padStart(2, '0')
    val minuteText: String = minute.toString().padStart(2, '0')
    return "24h -> $hourText:$minuteText"
}
```

Implemente em partes: primeiro os setters com validação, depois o construtor, as consultas, `toString(): String`, `nextMinute()` e por último a alternância de modo.

## Shell

```bash
#TEST_CASE initial state
$show
24h -> 00:00

#TEST_CASE set valid time
$set 10 02
$show
24h -> 10:02

#TEST_CASE set valid boundary
$set 15 59
$show
24h -> 15:59

#TEST_CASE invalid hour still updates valid minute
$set 25 10
fail: invalid hour

$show
24h -> 15:10

#TEST_CASE invalid minute still updates valid hour
$set 1 70
fail: invalid minute
$show
24h -> 01:10

#TEST_CASE both invalid fields preserve time
$set -1 60
fail: invalid hour
fail: invalid minute
$show
24h -> 01:10

#TEST_CASE next rolls hour
$set 15 59
$show
24h -> 15:59

$next
$show
24h -> 16:00

#TEST_CASE invalid command
$invalid
fail: invalid command

$end
```

***

```bash
#TEST_CASE next rolls day
$set 23 59
$show
24h -> 23:59

$next
$show
24h -> 00:00

$end
```

***

```bash
#TEST_CASE init valid time
$init 10 20
$show
24h -> 10:20

#TEST_CASE init invalid hour
$init 90 20

$show
24h -> 00:20

#TEST_CASE init invalid values
$init 90 100

$show
24h -> 00:00

$end
```

***

```bash
#TEST_CASE mode toggles to am pm
$show
24h -> 00:00

$mode
$show
12h -> 12:00 AM

#TEST_CASE pm display
$set 13 05
$show
12h -> 01:05 PM

#TEST_CASE midnight and noon display
$set 00 00
$show
12h -> 12:00 AM

$set 12 00
$show
12h -> 12:00 PM

#TEST_CASE mode toggles back to 24h
$mode
$show
24h -> 12:00

$end
```

## Draft

<!-- links .cache/starter -->
<!-- end -->

<!-- MERMAID -->
