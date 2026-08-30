# Animal que nasce, cresce, morre

<!-- toc-table -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell) | [Cheat](#cheat)
-- | -- | -- | --
<!-- toc-table -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/main/labs/animal/assets/cover.webp)

## Intro

O objetivo dessa atividade é implementar um animal que passa pelas diversas fases de crescimento até a morte.

- Regras
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
    - Se o animal conseguir envelhecer sem chegar na morte, retorne true.
    - Retorne false se ele já estiver morto ou acabar morrendo.
    - A camada de interação deverá mostrar a mensagem "warning: {nome} morreu"
  - Ao fazer barulho, o animal emite o som característico da sua espécie, com as seguintes restrições:
    - Se for filhote, emite um "---".
    - Se estiver morto, emite um "RIP".
    - Como não são mensagens de erro, o barulho do animal deve ser retornado no método `makeSound` e impresso na `main`.
- Separe as responsabilidades
  - A classe Animal não deve fazer nenhuma ação de leitura ou impressão de dados.
  - A camada de interação (main) é quem deve fazer a leitura dos dados e impressão das saídas.

## Guide

- Implemente a sua classe se orientando pela descrição, pelo UML(se houver) e pelos testes cadastrados.
- Começe analisando os testes e entendendo tudo que seu código precisa fazer.
- Depois que tiver uma ideia do que vai implementar, se deixe guiar pelos testes, implementando apenas o que é pedido para passar em cada teste.
- Passe para o próximo teste até implementar tudo que é pedido.

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/main/labs/animal/assets/diagrama.png)

- Na seção de [Cheat](#cheat) ou no vídeo abaixo, você pode conferir as respostas dessa atividade.

[![youtube icon](https://raw.githubusercontent.com/qxcodepoo/arcade/main/labs/animal/assets/yousolver.webp)](https://youtu.be/QZfjLVrk7p8)

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

## Cheat

<!-- links .cache/cheat -->
- java
  - [Shell.java](https://github.com/qxcodepoo/arcade/blob/main/labs/animal/.cache/cheat/java/Shell.java)
<!-- links -->
