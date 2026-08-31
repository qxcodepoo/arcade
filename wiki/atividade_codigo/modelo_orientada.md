# Título da atividade

<!-- toc-table -->
[Intro](#intro) | [Regras](#regras) | [Diagrama](#diagrama) | [Guide](#guide)
-- | -- | -- | --
<!-- toc-table -->

![cover](assets/cover.webp)

## Intro

Descreva em poucas linhas o projeto que o aluno vai implementar.

- Contexto:
- Objetivo pedagógico principal:
- Invariante ou decisão de modelagem que a atividade deve tornar visível:
- O objetivo dessa atividade é implementar `...`.
- A classe `NomeEmIngles` representa `conceito em português`.
- Essa atividade não possui Shell obrigatório.
- O aluno deve implementar os requisitos e criar um código de teste ou demonstração para validar o comportamento.

## Regras

### Modelo

- Classe `NomeEmIngles`
  - Atributo `attribute`: descreva o valor guardado.
  - Atributo `limit`: descreva o limite, se existir.
  - Invariantes:
    - `...`
  - Construtor
    - Recebe `...`.
    - Inicializa `...`.

### Métodos

- Método `methodName(arg)`
  - Entrada:
  - Pré-condições:
  - Efeito em sucesso:
  - Retorno:
  - Falhas:
  - Estado após falha:

- Método `anotherMethod()`
  - Efeito:
  - Retorno:

### Limites

- Defina os valores máximos, mínimos ou casos especiais.
- Informe o que acontece quando uma operação ultrapassa o limite.
- Informe se a operação deve retornar `true`, `false`, `null`, lançar erro ou apenas ajustar o estado.

### Representação

- Defina o formato textual do objeto, se houver.
- Formato literal:
  - `campo outro valor`

### Verificação

O aluno deve criar um código de teste ou demonstração cobrindo:

- Criação do objeto.
- Estado inicial.
- Operação principal em caso normal.
- Operação no limite.
- Método de consulta ou representação textual.

## Diagrama

Use a convenção definida em [Padrão para atividades de código](README.md#diagramas).

O arquivo fonte deve ser `assets/diagrama.puml`. Gere a imagem na pasta `assets` com `plantuml diagrama.puml`.

## Guide

![diagrama](assets/diagrama.png)

Implemente a atividade em partes.

- Parte 1: modelo mínimo
  - Represente o estado necessário para cumprir o primeiro caso de uso.
  - Inicialize os atributos de modo que as invariantes comecem válidas.
  - Confira o estado inicial.
- Parte 2: métodos de consulta
  - Implemente métodos que retornam informações sem alterar o estado.
  - Implemente a representação textual, se existir.
- Parte 3: métodos de alteração
  - Implemente operações que modificam o objeto.
  - Faça cada validação no componente que conhece a regra.
  - Confira os limites e o estado após falhas definidos em `Regras`.
- Parte 4: código de teste
  - Crie objetos com valores diferentes.
  - Chame os métodos principais.
  - Confira visualmente ou por asserts se o comportamento bate com o enunciado.

Perguntas de reflexão:

- Qual regra pertence ao objeto que guarda o estado?
- Que pequena mudança futura esta modelagem deve facilitar?
