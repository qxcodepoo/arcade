---
index_content: |2
    - Objetivo: usar `ValueError` para comunicar uma alteração de estado inválida.
    - Conceitos: exceção padrão, `raise`, `try/except` e invariante.
    - Técnicas: validar no construtor e no setter, preservar estado e traduzir falhas no Shell.
    - Pré-requisito: encapsulamento, invariantes e `try/except` básicos.
---
# [TRAIN] Bermuda: exceções para invariantes de tamanho

<!-- toc-table -->
[Intro](#intro) | [Regras](#regras) | [Diagrama](#diagrama) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft)
-- | -- | -- | -- | -- | --
<!-- toc-table -->

![cover](../roupa/assets/cover.webp)

## Intro

Esta atividade modela uma bermuda que precisa manter um tamanho válido. O
contrato de falha usa uma exceção padrão apropriada para argumentos inválidos:
em vez de retornar `false`, o domínio interrompe a operação inválida.

O objetivo é praticar uma forma de comunicar uma operação inválida. Escolha a
exceção padrão que melhor representa um argumento incompatível com o contrato;
por exemplo, `ValueError` em Python ou `IllegalArgumentException` em Java. O
`Shell` decide como apresentar a falha.

## Regras

- `Bermuda` possui uma propriedade privada `size: string`.
- Os tamanhos permitidos são `P`, `M`, `G` e `GG`.
- O construtor recebe o tamanho inicial e lança uma exceção padrão apropriada se ele for inválido.
- `setSize(size: string): void` valida o novo tamanho antes de alterar a propriedade e lança uma exceção padrão apropriada quando o valor não é permitido.
- Uma falha em `setSize` preserva o tamanho anterior.
- `getSize(): string` consulta o tamanho atual sem alterar o objeto.
- `getAllowedSizes(): Array<string>` devolve os tamanhos permitidos sem expor uma coleção mutável interna.
- O comando `init` tenta criar uma nova bermuda. Se o tamanho for inválido, a bermuda anterior permanece ativa.
- O comando `size` altera a bermuda atual.
- O domínio não lê entrada nem imprime mensagens. O `Shell` captura a exceção de tamanho e imprime `fail: invalid size`.

## Diagrama

![diagrama](assets/diagrama.png)

## Guide

Implemente em etapas:

1. Crie `Bermuda` com `DEFAULT_SIZE`, a propriedade privada `size` e a coleção
   de tamanhos permitidos.
2. Crie `validateSize(size: string): void`. Esse método consulta os tamanhos
   permitidos e lança a exceção padrão escolhida quando o argumento é inválido.
3. Faça o construtor chamar `validateSize` antes de criar
   um estado inválido.
4. Faça `setSize` chamar `validateSize` antes da atribuição. Uma exceção não deve deixar uma
   alteração parcial no objeto.
5. Mantenha `getAllowedSizes` como uma consulta que devolve uma cópia,
   sem expor uma coleção interna mutável.
6. No `Shell`, capture a exceção de tamanho. Ao executar `init`, só substitua a
   bermuda atual depois que a nova construção terminar com sucesso.

`validateSize` existe porque o construtor e `setSize` precisam garantir a mesma
invariante: o tamanho atual deve estar na coleção de tamanhos permitidos. Ao
concentrar essa regra em um método, os dois pontos usam a mesma decisão e não
duplicam a condição nem a exceção. Cada operação continua responsável por sua
atribuição, mas só a executa depois que a validação termina com sucesso. Não é
necessário chamar `setSize` no construtor: a validação não depende de um estado
já criado, e o construtor pode estabelecer o primeiro estado válido diretamente.

Não crie uma exceção própria nesta atividade: a exceção padrão escolhida já
comunica adequadamente um argumento incompatível com o contrato.

Perguntas de reflexão:

- Qual é a diferença entre retornar `false` e lançar uma exceção padrão?
- Por que a validação precisa ocorrer antes da atribuição?
- Por que o `Shell` deve capturar a exceção em vez de `Bermuda` imprimir a falha?
- O que aconteceria se `init` substituísse a bermuda antes de validar o novo tamanho?

## Shell

```bash
#TEST_CASE initial state
$show
size: (P)

#TEST_CASE valid size
$size M
$show
size: (M)

#TEST_CASE invalid setter preserves state
$size XG
fail: invalid size
$show
size: (M)
$end
```

```bash
#TEST_CASE invalid constructor preserves previous object
$init GG
$show
size: (GG)
$init XG
fail: invalid size
$show
size: (GG)
$end
```

```bash
#TEST_CASE all allowed sizes
$init P
$size M
$size G
$size GG
$show
size: (GG)
$end
```

```bash
#TEST_CASE invalid command
$resize G
fail: invalid command
$end
```

## Draft

<!-- links .cache/starter -->
<!-- links -->
