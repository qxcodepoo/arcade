# [TRAIN] Roupa: extensão testável de Camisa

<!-- toc-table -->

![_](assets/cover.webp)

## Intro

O objetivo dessa atividade é transformar a modelagem de `Shirt`, vista em Camisa, em uma versão testável com `Shell`.

Nesta atividade você vai consolidar **encapsulamento**, **getter**, **setter validador** e **invariante de estado**. A classe `Garment` protege seu `size`; o `Shell` cuida da interação com o usuário e transforma falhas em mensagens.

### Mensagens do programa

As explicações da atividade estão em português, mas o texto produzido pelo programa deve ficar em inglês:

- `fail: invalid size`
- `fail: invalid command`

## Regras

- Os tamanhos válidos são `PP`, `P`, `M`, `G`, `GG` e `XG`.
- Faça o objeto `Garment` iniciar com um tamanho padrão válido.
- O construtor deve primeiro inicializar o atributo privado com esse tamanho padrão e depois chamar `setSize()` para tentar aplicar o tamanho recebido.
- Crie o método estático `getAllowedSizes()` para retornar uma nova lista com os tamanhos permitidos.
- Crie o método `setSize()` que apenas aceita os valores válidos de tamanho.
- Coloque o atributo `size` como privado e crie `getSize()` para consultar o estado.
- Caso o valor seja válido, `setSize()` deve alterar o tamanho e retornar `true`.
- Caso o valor seja inválido, `setSize()` deve retornar `false` sem alterar o tamanho anterior.
- O setter não deve imprimir mensagens. A impressão da falha pertence ao `Shell`, aplicando a separação entre domínio e interface.

## Diagrama

O diagrama mostra `Garment` com o atributo privado `size`. A constante indica o tamanho padrão e `getAllowedSizes()` concentra o conjunto permitido sem expor uma lista interna compartilhada. O `Shell` conhece apenas os métodos públicos e transforma o retorno `false` em mensagem de erro.

![diagrama](assets/diagrama.png)

## Guide

- Implemente `Garment` mantendo `size` privado.
- Comece pelo construtor: inicialize `size` com `DEFAULT_SIZE` e depois chame `setSize()` com o valor recebido.
- Implemente `getAllowedSizes()` retornando uma nova lista com os tamanhos permitidos.
- Faça `setSize()` retornar `true` quando alterar o estado e `false` quando rejeitar o valor.
- Implemente o `Shell` apenas para interpretar comandos, chamar o domínio e imprimir resultados.
- Confira nos testes os casos de tamanho inválido, tamanho válido e estado preservado após uma falha.

Pergunta de reflexão: qual invariante seria quebrada se `size` fosse público?

## Shell

```bash
#TEST_CASE initial state
$show
size: (P)

#TEST_CASE invalid size preserves state
$size F
fail: invalid size

$show
size: (P)

#TEST_CASE valid size
$size PP
$show
size: (PP)

#TEST_CASE invalid size after valid size
$size XGG
fail: invalid size

$show
size: (PP)

$end

```

## Draft

<!-- links .cache/starter -->
<!-- links -->
