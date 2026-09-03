# [ALONE] Relógio: invariantes de tempo e atualização coordenada

<!-- toc-table -->

![cover](assets/cover.webp)

## Intro

Seu objetivo é construir uma classe `Time` que garanta que hora e minuto permaneçam válidos.

Nesta atividade você vai consolidar **encapsulamento**, **getters**, **setters validadores**, **invariantes de estado** e **separação entre domínio e interface**. O relógio protege seus atributos; o `Shell` interpreta comandos e imprime mensagens.

### Mensagens do programa

As explicações da atividade estão em português, mas o texto produzido pelo programa deve ficar em inglês:

- `fail: invalid hour`
- `fail: invalid minute`
- `fail: invalid command`

## Regras

- Construtor
  - O construtor deve receber 2 parâmetros: hora e minuto.
  - O construtor deve primeiro inicializar hora e minuto com `0`.
  - Depois, utilize os métodos `set` para tentar aplicar os valores recebidos.
- Crie os métodos getters e setters para cada atributo.
  - Os métodos set devem garantir que o valor atribuído sempre seja válido, ou não realizar nenhuma mudança.
  - Os setters devem retornar sucesso ou falha sem imprimir mensagens.
  - No comando `$set`, cada campo válido deve ser atualizado mesmo que outro campo do mesmo comando seja inválido.
- `toString`
  - Crie um método que retorne a hora mostrando também o modo de exibição.
  - No modo 24h, use o formato `24h: HH:MM`.
  - No modo AM/PM, use o formato `AM/PM: HH:MM AM` ou `AM/PM: HH:MM PM`.
  - Você precisará pesquisar como formatar números menores que 10 com 2 dígitos (ex: 01, 02, 03).
- Nos métodos set, realize a validação dos valores.
  - Hora deve ser entre 0 e 23.
  - Minuto deve ser entre 0 e 59.
  - Quando um valor for inválido, o campo correspondente deve manter o valor anterior.
- Próximo minuto `nextMinute`
  - Crie um método nextMinute que incrementa o minuto em 1.
  - Se o minuto for 59, ele deve ser zerado e a hora incrementada.
  - Se a hora for 23, ela deve ser zerada.
- Modo de exibição
  - O relógio deve iniciar em modo 24h.
  - O comando `$mode` deve alternar entre o modo 24h e o modo AM/PM.
  - A hora interna continua sendo guardada em 24h. O modo AM/PM muda apenas a forma de exibir a hora.
- A classe `Time` não deve ler entrada nem imprimir mensagens. O `Shell` deve interpretar os retornos dos setters e imprimir as falhas.
- O comando `$init` não imprime mensagens de falha. Ele apenas cria um novo relógio; valores inválidos permanecem como `0` por causa da inicialização do construtor.

## Diagrama

As constantes indicam os limites válidos do domínio. Os setters concentram as validações de cada campo, enquanto `nextMinute()` coordena a passagem de minuto e hora sem depender do `Shell`. O modo de exibição também pertence ao domínio, porque altera a representação textual do relógio sem mudar sua hora interna.

![diagrama](assets/diagrama.png)

## Guide

[Vídeo de apoio](https://youtu.be/7vD5le9DeZE?si=uA_wG0fD8HBN_At5)

Para formatar com 2 dígitos utilize a seguinte estratégia:

```py
def __str__(self) -> str:
    return f"24h: {self.__hour:02d}:{self.__minute:02d}"
```

Implemente em partes: primeiro os setters com validação, depois o construtor usando esses setters, depois `toString`, `nextMinute` e por último a alternância de modo.

Pergunta de reflexão: por que `nextMinute` pode alterar dois campos sem usar o `Shell`?

## Shell

```bash
#TEST_CASE initial state
$show
24h: 00:00

#TEST_CASE set valid time
$set 10 02
$show
24h: 10:02

#TEST_CASE set valid boundary
$set 15 59
$show
24h: 15:59

#TEST_CASE invalid hour preserves other valid fields
$set 25 10
fail: invalid hour

$show
24h: 15:10

#TEST_CASE invalid minute preserves previous minute
$set 1 70
fail: invalid minute
$show
24h: 01:10

#TEST_CASE next rolls hour
$set 15 59
$show
24h: 15:59

$next
$show
24h: 16:00

$end
```

***

```bash
#TEST_CASE next rolls day
$set 23 59
$show
24h: 23:59

$next
$show
24h: 00:00

$end
```

***

```bash
#TEST_CASE init valid time
$init 10 20
$show
24h: 10:20

#TEST_CASE init invalid hour
$init 90 20

$show
24h: 00:20

#TEST_CASE init invalid values
$init 90 100

$show
24h: 00:00

$end
```

***

```bash
#TEST_CASE mode toggles to am pm
$show
24h: 00:00

$mode
$show
AM/PM: 12:00 AM

#TEST_CASE pm display
$set 13 05
$show
AM/PM: 01:05 PM

#TEST_CASE midnight and noon display
$set 00 00
$show
AM/PM: 12:00 AM

$set 12 00
$show
AM/PM: 12:00 PM

#TEST_CASE mode toggles back to 24h
$mode
$show
24h: 12:00

$end
```

## Draft

<!-- links .cache/starter -->
<!-- links -->
