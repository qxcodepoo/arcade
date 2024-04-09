# @grafite2 - Porta minas

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft)
-- | -- | -- | --
<!-- toch -->

![cover](cover.jpg)

Faça o modelo de uma lapiseira que pode conter um único grafite.

[![explicação](../../pages/images/explicacao.png)](https://youtu.be/LvZODN2rL6s)

***

## Intro

O objetivo dessa atividade é implementar uma lapiseira que permite inserir, remover grafite e escrever em uma folha, considerando a dureza e tamanho do grafite.

- Descrição
  - A lapiseira é capaz de iniciar, inserir e remover grafite, além de escrever em uma folha.
  - Para inserir um grafite, é necessário especificar o calibre (float), a dureza (string) e o tamanho em mm (int).
  - A remoção do grafite só é possível se houver algum na lapiseira.
  - A escrita na folha só é possível se houver grafite suficiente e se o tamanho do grafite for superior a 10mm.
  - A quantidade de grafite gasto varia de acordo com a dureza do grafite.
  - Quando o tamanho do grafite atinge 10mm, não é mais possível escrever.
  - Se não houver grafite suficiente para terminar a escrita na folha, é emitido um aviso de texto incompleto.

- Responsabilidades
  - O código deve ser implementado em duas classes: `Grafite` e `Lapiseira` e a integração deve ser feita no `Adapter`.
  - A classe `Grafite` é responsável por armazenar as informações do grafite.
    - O método `usagePerSheet` retorna a quantidade de grafite gasto por folha.
  - A classe `Lapiseira` é responsável por gerenciar as operações de inserção, remoção de grafite e escrita na folha.

- Comandos
  - Todos os comandos seguem o modelo `$comando arg1 arg2 ...`.
  - `$iniciar calibre` - Inicializa a lapiseira com um determinado calibre.
  - `$inserir calibre dureza tamanho` - Insere um grafite com o calibre, dureza e tamanho especificados.
    - erros:
      - `fail: calibre incompativel` - Se o calibre do grafite for diferente do calibre da lapiseira.
      - `fail: ja existe grafite` - Se já houver um grafite na lapiseira.
  - `$remover` - Remove o grafite da lapiseira, se houver.
    - erros:
      - `fail: nao existe grafite` - Se não houver grafite na lapiseira.
  - `$escrever` - Escreve na folha, considerando o grafite presente na lapiseira.
    - O grafite é gasto de acordo com a dureza.
    - erros:
      - `fail: nao existe grafite` - Se não houver grafite na lapiseira.
      - `fail: tamanho insuficiente` - Se o tamanho do grafite for insuficiente para começar a escrita.
      - `fail: folha incompleta` - Se o grafite não for suficiente para terminar a escrita.

## Guide

![diagrama](diagrama.png)

- Parte 1: Inserir
  - Crie a classe `Grafite` com o atributo `size`.
  - Crie a classe `Lapiseira` com o atributo `tip` inicializado como `null`.
  - Implemente o método `hasGrafite` que retorna `true` se houver grafite na lapiseira.
  - Implemente o método `insert` que insere um grafite na lapiseira, se não houver grafite.
  - Implemente o método `toString` que mostra a lapiseira e o grafite presente.
  - Crie um objeto `lapiseira` e verifique se está vazia.
  - Crie um objeto `grafite` e insira na lapiseira.
  - Verifique se a lapiseira possui o grafite inserido.

- Parte 2: Remover Grafite
  - Implemente o método `remove` que retira o grafite da lapiseira, se houver.
  - Verifique se o grafite foi removido corretamente.
  - Verifique se o método `remove` retorna o grafite removido ou `null` se não havia grafite.

- Parte 3: Escrever na Folha
  - Implemente o método `writePage` que escreve na folha.
  - Implemente o método `usagePerSheet` que retorna a quantidade de grafite gasto por folha.
  - Verifique se a lapiseira consegue escrever na folha.
  - Faça as verificações antes de escrever na folha.
  - Para ver se o grafite será suficiente para escrever na folha, verifique qual o tamanho final que ele teria se fizesse a folha completa. Se esse tamanho for menor que 10mm, ele deve gastar o que for possível e parar a folha pela metade.

***

## Shell

```bash
#__case inserindo grafites
$init 0.5
$show
calibre: 0.5, grafite: null

#__case incompativel
$insert 0.7 2B 50
fail: calibre incompativel
$insert 0.5 2B 50
$show
calibre: 0.5, grafite: [0.5:2B:50]
$end
```

***

```bash
#__case inserindo
$init 0.3
$insert 0.3 2B 50
$show
calibre: 0.3, grafite: [0.3:2B:50]

#__case ja existe
$insert 0.3 4B 70
fail: ja existe grafite
$show
calibre: 0.3, grafite: [0.3:2B:50]

#__case removendo
$remove
$show
calibre: 0.3, grafite: null

#__case reinserindo
$insert 0.3 4B 70
$show
calibre: 0.3, grafite: [0.3:4B:70]
$end
```

***

```bash
#__case sem grafite
$init 0.9
$write
fail: nao existe grafite

#__case escrevendo 1
$insert 0.9 4B 14
$write
$write
fail: tamanho insuficiente
$show
calibre: 0.9, grafite: [0.9:4B:10]
$end
```

***

```bash
#__case escrevendo 2
$init 0.9
$insert 0.9 4B 16
$write
$show
calibre: 0.9, grafite: [0.9:4B:12]
#__case escrevendo 3
$write
fail: folha incompleta
$show
calibre: 0.9, grafite: [0.9:4B:10]
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
