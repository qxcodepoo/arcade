---
index_content: |2
    - Descrição: o pula-pula controla uma fila de espera e uma lista de crianças brincando.
    - Domínio: as crianças mantêm sua ordem nas listas, entram e saem por operações de fila e podem ser removidas pelo nome em qualquer uma das duas coleções.
    - Objetivos: coordenar movimentos entre coleções lineares e perceber que a posição representa uma ordem variável, não um lugar fixo.
---
# [TRAIN] Pula-pula com crianças

<!-- toc-table -->
[Intro](#intro) | [Diagrama](#diagrama) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | -- | --
<!-- end -->

![cover](assets/cover.webp)

Nosso objetivo no trabalho é modelar um gestor de pula pulas em um parquinho, controlando as pessoas que entram e saem do pula pula, além de coordenar as pessoas que estão na fila de espera.

## Intro

Esta atividade trabalha coleções lineares de objetos. O pula pula possui duas listas: uma fila de espera e uma lista de crianças brincando. As operações movem crianças entre essas listas sem criar uma posição fixa para cada criança.

- Inserir crianças na fila de espera do pula pula.
- Mover a primeira criança da fila de espera para dentro do pula pula.
- Mover a primeira criança que entrou no pula pula para o final da fila de espera.
- Buscar uma criança pelo nome para removê-la, esteja ela esperando ou brincando.

O foco é perceber que a posição na lista muda conforme as operações acontecem. Aqui a posição indica ordem de chegada ou de saída, não uma cadeira, caixa ou slot permanente.

***

## Diagrama

`Trampoline` mantém duas ordens variáveis de crianças: a fila `waiting` e a lista `playing`. As crianças são criadas pelo `Shell` e apenas referenciadas pelo pula-pula, por isso a relação é uma agregação.

```mermaid
%%{init: {'fontFamily': 'monospace'}}%%
classDiagram
    direction LR

    class Kid {
        -val name : String
        -val age : Int
        +Kid(name : String, age : Int)
        +getName() String
        +getAge() Int
        +toString() String
    }

    class Trampoline {
        -val waiting : MutableList~Kid~
        -val playing : MutableList~Kid~
        +Trampoline()
        +arrive(kid : Kid) Unit
        +enter() Unit
        +leave() Unit
        +removeKid(name : String) Kid?
        +toString() String
    }

    class Shell {
        +main() Unit
    }

    Trampoline "1" o-- "0..*" Kid : waiting
    Trampoline "1" o-- "0..*" Kid : playing
    Shell ..> Trampoline : commands
```

***

## Draft

<!-- links .cache/starter -->
- java
  - [Shell.java](.cache/starter/java/Shell.java)
<!-- end -->

## Guide


`Kid` guarda nome e idade. `Trampoline` coordena duas `MutableList<Kid>`: `waiting` e `playing`. As listas ficam privadas, e as operações do pula-pula definem como as crianças mudam entre elas.

- `arrive(kid)` insere a criança no início de `waiting`.
- `enter()` remove a última criança de `waiting` e a insere no início de `playing`, mantendo a ordem de chegada.
- `leave()` remove a última criança de `playing` e a coloca no início de `waiting`.
- `removeKid(name)` procura primeiro em `waiting`, depois em `playing`, e devolve a criança removida ou `null`.
- `toString()` deve mostrar as duas listas como `[waiting] => [playing]`.

Os comandos do Shell (`arrive`, `enter`, `leave` e `remove`) permanecem iguais por serem parte do contrato externo.

## Shell

```bash
#TEST_CASE unico
# $chegou _nome _idade
# insere uma criança na fila de entrada do brinquedo
$arrive mario 5
$arrive livia 4
$arrive luana 3

# show
# mostra a fila de entrada e o pula pula
$show
[luana:3, livia:4, mario:5] => []

#TEST_CASE entrando
# entrar
# tira a primeira criança da fila de entrada e insere no pula pula

$enter
$show
[luana:3, livia:4] => [mario:5]

#TEST_CASE segunda pessoa
$enter
$show
[luana:3] => [livia:4, mario:5]

#TEST_CASE saindo
$leave
$show
[mario:5, luana:3] => [livia:4]

#TEST_CASE remove
$remove luana

$show
[mario:5] => [livia:4]
$remove livia
$show
[mario:5] => []
$end
```

***

```bash
#TEST_CASE 2
$show
[] => []
$arrive mario 5
$show
[mario:5] => []

#TEST_CASE empty enter
$enter
$show
[] => [mario:5]

#TEST_CASE empty leave
$leave
$show
[mario:5] => []
$leave
$show
[mario:5] => []

#TEST_CASE remove from waiting
$remove mario
$show
[] => []

#TEST_CASE remove empty
$remove rebeca
fail: rebeca nao esta no pula-pula

$show
[] => []
$end
```

<!-- MERMAID -->
