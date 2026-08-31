# Título da atividade

<!-- toc-table -->
[Intro](#intro) | [Regras](#regras) | [Diagrama](#diagrama) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft)
-- | -- | -- | -- | -- | --
<!-- toc-table -->

![cover](assets/cover.webp)

## Intro

Descreva em poucas linhas o projeto que o aluno vai implementar.

- Contexto:
- Objetivo pedagógico principal:
- Invariante ou decisão de modelagem que a atividade deve tornar visível:
- O objetivo dessa atividade é implementar `...`.
- A classe `NomeEmIngles` representa `conceito em português`.
- A classe `Shell` representa a interface de linha de comando.
- A classe de domínio não deve ler entrada nem imprimir saída.
- O Shell deve interpretar comandos, chamar os métodos e imprimir os resultados.

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

### Mostrar

- Comando: `$show`
- Deve imprimir a chamada do `toString` ou representação principal do objeto.
- Formato literal:
  - `campo:{valor}, outro:{valor}`

### Inicializar

- Comando: `$init arg1 arg2`
- Deve criar ou reiniciar o objeto principal.
- Estado inicial:
  - `campo`: `valor inicial`.
  - `limite`: `valor máximo`.

### Operação principal

- Comando: `$command arg`
- Entrada:
- Pré-condições:
- Efeito em sucesso:
- Saída em sucesso:
- Falhas:
  - Mensagem literal: `fail: mensagem de erro`.
- Estado após falha:

### Outra operação

- Comando: `$other arg1 arg2`
- Entrada:
- Efeito em sucesso:
- Limites:
- Falhas:
  - `fail: primeira falha`
  - `fail: segunda falha`
- Estado após falha:

## Diagrama

Use a convenção definida em [Padrão para atividades de código](README.md#diagramas).

O arquivo fonte deve ser `assets/diagrama.puml`. Gere a imagem na pasta `assets` com `plantuml diagrama.puml`.

## Guide

![diagrama](assets/diagrama.png)

Implemente a atividade em partes.

- Parte 1: modelo mínimo
  - Represente o estado necessário para cumprir o primeiro caso de uso.
  - Inicialize os atributos de modo que as invariantes comecem válidas.
- Parte 2: consultas e representação
  - Implemente consultas sem alterar estado.
  - Defina a representação textual usada pelo `$show`.
- Parte 3: comandos do domínio
  - Implemente as operações que alteram o objeto.
  - Faça cada validação no componente que conhece a regra.
  - Confira sucesso, limite, falha e estado após falha.
- Parte 4: integração com Shell
  - Converta os argumentos de entrada.
  - Chame o domínio sem mover regras para o Shell.
  - Imprima somente o que o contrato pedir.

Perguntas de reflexão:

- Qual regra ficaria mais difícil de testar se estivesse no Shell?
- Que pequena mudança futura esta modelagem deve facilitar?

## Shell

```bash
#TEST_CASE inicializar
$init 10
$show
campo:0, limite:10
$end
```

```bash
#TEST_CASE operacao basica
$init 10
$command 3
$show
campo:3, limite:10
$end
```

```bash
#TEST_CASE limite
$init 10
$command 11
fail: mensagem de erro
$show
campo:0, limite:10
$end
```

## Draft

<!-- links .cache/starter -->
<!-- links -->
