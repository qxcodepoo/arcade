# Animal que nasce, cresce, morre

<!-- toch -->
[Model](#model) | [Guide](#guide) | [Intro](#intro) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft) | [Cheat](#cheat)
-- | -- | -- | -- | -- | -- | --
<!-- toch -->

![cover](cover.jpg)

UML | Testes | Rascunho | Adapter | Esqueleto
--- | ------ | -------- | ------- | ---------
sim | sim    | sim      | sim     | não

## Model

Essa atividade utiliza testes através de requisições e respostas em texto. Ela é composta por três componentes.

- `Suas classes de resolução`: Classes que você deve implementar e que resolvem o problema proposto.
- `Shell`: Responsável por ler as requisições de texto e chamar os métodos da classe `Adapter`.
  - Normalmente, você não precisa alterar essa classe.
- `Adapter`: Responsável por instanciar e chamar os métodos das `Suas classes de resolução`.
  - Todos os métodos do `Adapter` são `void`, sem retorno.
  - Todos os métodos possuem o mesmo nome e parâmetros das requisições dos testes.
    - `linha de teste`: `$somar 1 2`
    - `método Adapter`: `void somar(int a, int b)`
  - Se a requisição exigir uma resposta, ela deve ser impressa no `Adapter`.
    - `print(calculadora.somar(a, b))`

## Guide

- Implemente a sua classe se orientando pela descrição, pelo UML(se houver) e pelos testes cadastrados.
- Começe analisando os testes e entendendo tudo que seu código precisa fazer.
- Depois que tiver uma ideia do que vai implementar, se deixe guiar pelos testes, implementando apenas o que é pedido para passar em cada teste.
- Após implementar sua classe e conectar no `Adapter`, rode os testes para verificar se a atividade está correta.
- Passe para o próximo teste até implementar tudo que é pedido.

- Na seção de [Cheat](#cheat), você pode conferir as respostas dessa atividade.

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
    - Como não são mensagens de erro, o barulho do animal deve ser retornado no método `makeSound` e impresso no `Adapter`.

![_](diagrama.png)

___

<!--
## Guide

- Parte 1
  - Crie uma classe `Animal` com os atributos `especie`, `estagio` e `barulho`.
  - Crie um método `toString(): string` que retorna a representação do animal no formato `especie:estagio:barulho`.
  - Teste seu código
- Parte 2
  - Crie um método `envelhecer(qtd: number): void` que envelhece o animal em `qtd` estágios.
    - Se ele for nível 1, e você pedir para envelhecer 2 vezes, ele deve passar para o estágio 3.
    - Se ele for nível 2, e você pedir para envelhecer 3 vezes, ele deve passar para o estágio 4, pois 4 é o estágio máximo.
  - Implemente a lógica de crescimento do animal e verifique se ele morreu.
  - Certifique-se de que o animal não pode crescer após a morte.
- Parte 3
  - Crie um método `fazerBarulho(): string` que retorna o barulho.
  - Implemente a lógica de barulho do animal fazendo tratamento especial para bebês e mortos.
- Parte 4: Adapter
  - Na classe `Adapter`, crie um atributo `animal` e o inicialize no construtor.
  - Faça os ajustes necessários para chamar os métodos da classe Animal na classe Adapter.

-->

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
  - [fn.hpp](.cache/draft/cpp/fn.hpp)
  - [shell.cpp](.cache/draft/cpp/shell.cpp)
- java
  - [Shell.java](.cache/draft/java/Shell.java)
- ts
  - [shell.ts](.cache/draft/ts/shell.ts)
<!-- links -->

## Cheat

<!-- links .cache/cheat -->
- cpp
  - [shell.cpp](.cache/cheat/cpp/shell.cpp)
- java
  - [Shell.java](.cache/cheat/java/Shell.java)
- ts
  - [shell.ts](.cache/cheat/ts/shell.ts)
<!-- links -->
