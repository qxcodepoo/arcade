# Animal que nasce, cresce, morre

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft) | [Cheat](#cheat)
-- | -- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/animal/cover.jpg)

## Intro

O objetivo dessa atividade é implementar um animal que passa pelas diversas fases de crescimento até a morte.

- Descrição
  - O animal tem uma espécie `species`, um estágio `age` de vida e um barulho `sound` que ele faz.
  - O construtor do animal
    - Recebe a espécie e o barulho e inicia o estágio com 0.
  - O toString do animal deve retornar a representação do animal no formato
    - `{species}:{age}:{sound}`.
  - Os estágios pelos quais o animal passa são:
    - 0: Filhote
    - 1: Criança
    - 2: Adulto
    - 3: Idoso
    - 4: Morto
  - Ao envelhecer no método `ageBy`, o animal avança estágios na sua vida de acordo com o parâmetro `increment`.
    - Ao morrer ou tentar envelhecer após a morte do aninal, deve ser exibida a mensagem de aviso:
      - `warning: {species} morreu`.
      - Como essa é uma mensagem de erro, você pode imprimir diretamente no método `ageBy`.
  - Ao fazer barulho, o animal emite o som característico da sua espécie, com as seguintes restrições:
    - Se for filhote, emite um "---".
    - Se estiver morto, emite um "RIP".
    - Como não são mensagens de erro, o barulho do animal deve ser retornado no método `makeSound` e impresso na `main`.

## Guide

- Implemente a sua classe se orientando pela descrição, pelo UML(se houver) e pelos testes cadastrados.
- Começe analisando os testes e entendendo tudo que seu código precisa fazer.
- Depois que tiver uma ideia do que vai implementar, se deixe guiar pelos testes, implementando apenas o que é pedido para passar em cada teste.
- Passe para o próximo teste até implementar tudo que é pedido.

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/animal/diagrama.png)

- Na seção de [Cheat](#cheat) ou no vídeo abaixo, você pode conferir as respostas dessa atividade.

[![youtube icon](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/animal/../yousolver.png)](https://youtu.be/QZfjLVrk7p8)

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
  - [shell.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/animal/.cache/draft/cpp/shell.cpp)
- java
  - [Shell.java](https://github.com/qxcodepoo/arcade/blob/master/base/animal/.cache/draft/java/Shell.java)
- ts
  - [shell.ts](https://github.com/qxcodepoo/arcade/blob/master/base/animal/.cache/draft/ts/shell.ts)
<!-- links -->

## Cheat

<!-- links .cache/cheat -->
- cpp
  - [shell.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/animal/.cache/cheat/cpp/shell.cpp)
- java
  - [Shell.java](https://github.com/qxcodepoo/arcade/blob/master/base/animal/.cache/cheat/java/Shell.java)
- ts
  - [shell.ts](https://github.com/qxcodepoo/arcade/blob/master/base/animal/.cache/cheat/ts/shell.ts)
<!-- links -->
