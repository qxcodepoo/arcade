---
index_content: |2
    - Objetivo: tratar espécies diferentes por meio de um contrato comum.
    - Conceitos: classe abstrata, herança, substituição e despacho polimórfico.
    - Técnicas: implementar métodos abstratos e escrever clientes dependentes da abstração.
    - Pré-requisito: classes, herança, composição e delegação.
---
# [ALONE] Zoo: contrato comum e comportamento polimórfico

<!-- toc-table -->
[Intro](#intro) | [Regras](#regras) | [Diagrama](#diagrama) | [Guide](#guide) | [Verificação](#verificação) | [Draft](#draft)
-- | -- | -- | -- | -- | --
<!-- toc-table -->

## Intro

Um zoológico precisa apresentar animais diferentes. Todos possuem um nome,
mas cada espécie produz um som e se movimenta de uma maneira própria.

O objetivo principal é usar um contrato comum para tratar objetos diferentes
sem testar sua classe concreta. A função `present` recebe um `Animal`, mas o
comportamento executado depende do objeto real recebido.

## Regras

- `Animal` é uma classe abstrata com a propriedade `name : String`.
- Toda subclasse deve implementar `makeSound() : String` e `move() : String`.
- `Lion`, `Elephant` e `Snake` são animais concretos.
- `present(animal : Animal) : String` deve usar somente o contrato de `Animal`.
- `present` não pode verificar tipos concretos nem consultar o
  nome da classe para decidir o comportamento.
- Os métodos retornam textos; nenhuma classe imprime diretamente.
- `main()` deve construir uma `List<Animal>` contendo objetos de espécies
  diferentes e apresentar todos pela mesma função.

## Diagrama

```mermaid
%%{init: {"theme": "base", "themeVariables": {"fontFamily": "monospace"}}}%%
classDiagram
    direction TB

    class Animal {
        <<abstract>>
        +val name : String
        +makeSound() String
        +move() String
    }

    class Lion {
        +makeSound() String
        +move() String
    }

    class Elephant {
        +makeSound() String
        +move() String
    }

    class Snake {
        +makeSound() String
        +move() String
    }

    class Main {
        +present(animal : Animal) String
        +main() Unit
    }

    Animal <|-- Lion
    Animal <|-- Elephant
    Animal <|-- Snake
    Main ..> Animal : uses
```

## Guide

1. Crie `Animal` como uma classe abstrata com `name : String` e os métodos
   abstratos `makeSound() : String` e `move() : String`.
2. Crie as três subclasses e implemente os dois comportamentos de cada uma.
3. Implemente `present` recebendo `Animal`. Não acrescente condicionais para
   distinguir as espécies.
4. Monte uma `List<Animal>` com as três espécies e chame `present` para cada
   elemento.
5. Compare a função antes e depois de adicionar uma nova espécie. Se nenhuma
   alteração for necessária em `present`, o contrato está cumprindo seu papel.

A herança é usada aqui porque cada espécie é um `Animal` e precisa cumprir o
mesmo contrato. A classe abstrata evita animais incompletos, enquanto o
despacho polimórfico permite que a coordenação permaneça simples. Não há
necessidade de criar classes para jaulas, cuidadores ou alimentação nesta
primeira atividade de polimorfismo.

Perguntas de reflexão:

- Por que `present` não precisa saber se recebeu um leão ou uma cobra?
- O que mudaria se `present` verificasse a classe concreta para escolher o som?
- Por que `Animal` é uma abstração útil mesmo não sendo instanciada diretamente?
- Que nova espécie poderia ser adicionada sem modificar `present`?

## Verificação

Execute a implementação Kotlin:

```bash
tko run . -l kt
```

O resultado esperado é:

```text
Simba: roar, run
Babar: trumpet, walk
Kaa: hiss, slither
```

## Draft

<!-- links .cache/starter -->
<!-- links -->

<!-- KOTLIN -->
