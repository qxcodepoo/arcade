# [GUIDE] Toalha: estado e comportamento em uma classe coesa

<!-- toc-table -->
<!-- toc-table -->

![_](assets/cover.webp)

## Intro

O objetivo dessa atividade é implementar uma toalha que possa absorver água, ser torcida e informar seu estado.

O foco é observar como uma classe junta estado e comportamento: a própria `Towel` controla sua umidade, enquanto o código de teste apenas cria objetos e chama métodos.

## Regras

- A classe Toalha `Towel` possui os atributos cor `color`, tamanho `size` e umidade `wetness`.
- O construtor recebe a cor e o tamanho e inicia `wetness` com `0`.
- O método enxugar `dry` recebe uma quantidade inteira `amount` e aumenta `wetness` sem ultrapassar o limite.
- O método torcer `wringOut` zera `wetness`.
- O método `getMaxWetness` retorna o limite de umidade conforme o tamanho:
  - `P` -> `10`
  - `M` -> `20`
  - `G` -> `30`
- O método `isDry` retorna `true` quando `wetness` é `0` e `false` caso contrário.
- A classe `Towel` não deve ler entrada nem imprimir dados.
- Crie um código de teste para validar o comportamento da classe.

## Diagrama

O diagrama apresenta uma única classe porque cor, tamanho e umidade formam um comportamento coeso. Criar classes separadas para cada atributo aumentaria a complexidade sem melhorar a manutenção ou os testes nesta etapa.

![diagrama](assets/diagrama.png)

## Guide

[![youtube icon](assets/youguide.webp)](https://youtu.be/fEvJns4NpTM?si=G-FDqGnt_5SPSZpg)

Implemente e teste a classe em partes: estado inicial, absorção, limite de umidade, torção e consulta de estado.

- Comece pelo construtor e confira se uma toalha nova sempre inicia com `wetness` igual a `0`.
- Implemente `getMaxWetness` antes de `dry`, porque o limite depende do tamanho.
- Em `dry`, aumente a umidade apenas até o limite retornado por `getMaxWetness`.
- Em `wringOut`, volte a umidade para `0`.
- Em `isDry`, apenas consulte o estado, sem alterar a toalha.

Pergunta de reflexão: se o cálculo do limite ficasse espalhado pelo código de teste, que mudança seria mais difícil quando surgisse um novo tamanho?
