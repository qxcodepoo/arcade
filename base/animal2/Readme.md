# @animal2 - Nasce, cresce, morre

<!-- toch -->
[Model](#model) | [Intro](#intro) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft) | [Cheat](#cheat)
-- | -- | -- | -- | -- | --
<!-- toch -->

![cover](cover.jpg)

## Model

Essa atividade utiliza um padrão de projeto de requisições e respostas.

- Os testes são feitos através de requisições de texto e podem ser vistos na seção [Shell](#shell).
- A classe `Shell` é responsável por ler as requisições de texto, decodificar e chamar os métodos da classe `Adapter`.
- Na classe `Adapter` é onde você deve implementar e conectar seu código.
- A classe `Adapter` é apenas a classe de conexão, você deve as classes que implementam a lógica do problema. Use como base o diagrama de classes e a descrição do problema.
- Mensagens de erros podem ser lançadas por exceções ou comandos de `print` diretamente para o terminal.
- Ao mostrar uma string formatada, será utilizado o modelo do python `f"{variavel:param}"`.
- Na seção de [Cheat](#cheat), você pode conferir as respostas dessa atividade.

## Intro

O objetivo dessa atividade é implementar um animal que passa pelas diversas fases de crescimento até a morte.

- Descrição
  - O animal tem uma espécie, um estágio de vida e um barulho que ele faz.
  - Os estágios pelos quais o animal passa são:
    - 0: Filhote
    - 1: Criança
    - 2: Adulto
    - 3: Idoso
    - 4: Morto
  - Ao fazer barulho, o animal emite o som característico da sua espécie, com as seguintes restrições:
    - Se for filhote, emite um "---".
    - Se for idoso, emite um "RIP".
  - Ao crescer, o animal avança estágios na sua vida.
    - Ao morrer, deve ser exibida uma mensagem de aviso: `warning: {especie} morreu`.
    - Invocar o método de crescimento após a morte do animal deve exibir uma mensagem de aviso: `warning: {especie} morreu`.
- Responsabilidades
  - O código deve ser implementado na classe `Animal`.
  - Os métodos da classe `Animal` devem ser chamados na classe `Adapter`.
  - A classe `Shell` é responsável por ler as requisições de texto e chamar os métodos da classe `Adapter`.
- Comandos
  - Todos os comandos seguem o modelo `$comando arg1 arg2 ...`.
  - `$show`: Mostra o estado atual do animal.
    - formato: `f"{especie}:{estagio}:{barulho}"`
    - exemplo: `gato:0:miau`
  - `$init especie barulho`: Inicializa o animal passando a espécie e o barulho.
  - `$grow qtd`: Faz o animal crescer uma `qtd` etapas na vida.
  - `$noise`: Faz o animal emitir um som.
  - `$end`: Finaliza a execução.

***

## Guide

![_](diagrama.png)

- Parte 1
  - Crie uma classe `Animal` com os atributos `especie`, `estagio` e `barulho`.
  - Crie um método `String toString()` que retorna a representação do animal no formato `especie:estagio:barulho`.
  - Teste seu código
- Parte 2
  - Crie um método `void envelhecer(int qtd)` que envelhece o animal em `qtd` estágios.
    - Se ele for nível 1, e você pedir para envelhecer 2 vezes, ele deve passar para o estágio 3.
    - Se ele for nível 2, e você pedir para envelhecer 3 vezes, ele deve passar para o estágio 4, pois 4 é o estágio máximo.
  - Implemente a lógica de crescimento do animal e verifique se ele morreu.
  - Certifique-se de que o animal não pode crescer após a morte.
- Parte 3
  - Crie um método `fazerBarulho()` que faz o animal fazer barulho.
  - Implemente a lógica de barulho do animal fazendo tratamento especial para bebês e mortos.
- Parte 4: Adapter
  - Na classe `Adapter`, crie um atributo `animal` e o inicialize no construtor.
  - Faça os ajustes necessários para chamar os métodos da classe Animal na classe Adapter.

## Shell

### Primeira simulação

```bash
#TEST_CASE iniciando

$init gato miau
$show
gato:0:miau

$init cachorro auau
$show
cachorro:0:auau

$init galinha cocorico
$show
galinha:0:cocorico

$end
```

### Segunda simulação

```bash
#TEST_CASE grow

$init vaca muu
$show
vaca:0:muu

$grow 2
$show
vaca:2:muu
$grow 2
warning: vaca morreu
$show
vaca:4:muu
$grow 3
warning: vaca morreu
$show
vaca:4:muu

$end
```

### Terceira simulação

```bash
#TEST_CASE noise

$init cabra beeh

$noise
---

$grow 1
$noise
beeh
$grow 3
warning: cabra morreu

$noise
RIP

$end
```

### Quarta simulação

```bash
#TEST_CASE extra

$init passaro piupiu

$show
passaro:0:piupiu

$noise
---

$grow 1
$noise
piupiu

$grow 2
$noise
piupiu

$grow 1
warning: passaro morreu

$noise
RIP

$end
```

## Draft

<!-- links .cache/draft -->
- cpp
  - [adapter.hpp](.cache/draft/cpp/adapter.hpp)
  - [fn.hpp](.cache/draft/cpp/fn.hpp)
  - [shell.cpp](.cache/draft/cpp/shell.cpp)
- java
  - [Adapter.java](.cache/draft/java/Adapter.java)
  - [Shell.java](.cache/draft/java/Shell.java)
- ts
  - [aashell.ts](.cache/draft/ts/aashell.ts)
  - [adapter.ts](.cache/draft/ts/adapter.ts)
<!-- links -->

## Cheat

<!-- links .cache/cheat -->
- cpp
  - [adapter.hpp](.cache/cheat/cpp/adapter.hpp)
  - [animal.hpp](.cache/cheat/cpp/animal.hpp)
- java
  - [Adapter.java](.cache/cheat/java/Adapter.java)
  - [Animal.java](.cache/cheat/java/Animal.java)
- ts
  - [adapter.ts](.cache/cheat/ts/adapter.ts)
  - [animal.ts](.cache/cheat/ts/animal.ts)
<!-- links -->
