# Gerencie a fila de espera e atendimento da @budega

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![cover](cover.jpg)

Nosso objetivo no trabalho é modelar uma fila de atendimento de um Mercatil.

## Intro

- Quando o mercantil é incializado, é definido a quantidade de caixas que ele terá para sempre.
- Os caixas são modelados como um vetor de clientes de tamanho fixo. Uma posição do caixa ou terá o valor
null para indicar que o caixa está vazio ou terá um objeto cliente.
- A fila de espera é uma lista de clientes de tamanho variável. Todo cliente que chega é inserido no final da fila.
- As operações são entrar, chamarNoCaixa e finalizarAtendimento.

- Em Java
  - Os caixas devem ser implementados com um ArrayList e a fila de espera como um LinkedList.
- Em C++
  - Os caixas devem ser implementados com um vector e a fila de espera como um list.
  - Os clientes devem ser criados dinamicamente e gerenciados por um shared_ptr.

***

## Draft

<!-- links .cache/draft -->
- cpp
  - [adapter.hpp](.cache/draft/cpp/adapter.hpp)
  - [fn.hpp](.cache/draft/cpp/fn.hpp)
  - [shell.cpp](.cache/draft/cpp/shell.cpp)
- java
  - [Shell.java](.cache/draft/java/Shell.java)
- ts
  - [aashell.ts](.cache/draft/ts/aashell.ts)
  - [adapter.ts](.cache/draft/ts/adapter.ts)
<!-- links -->

## Guide

![diagrama](diagrama.png)

[![_](../../pages/images/resolucao.png)](https://youtu.be/Z7karsbg1ok)

***

## Shell

```sh
#TEST_CASE iniciar

$init 2
$show
Caixas: [-----, -----]
Espera: []

#TEST_CASE arrive

$arrive carla
$arrive maria
$arrive rubia

$show
Caixas: [-----, -----]
Espera: [carla, maria, rubia]

#TEST_CASE call

$call 0
$show
Caixas: [carla, -----]
Espera: [maria, rubia]

#TEST_CASE finish

$finish 0
$show
Caixas: [-----, -----]
Espera: [maria, rubia]

$end

```

```sh
#TEST_CASE iniciar2

$init 3
$show
Caixas: [-----, -----, -----]
Espera: []

$arrive carla
$arrive maria

$show
Caixas: [-----, -----, -----]
Espera: [carla, maria]

#TEST_CASE call

$call 0
$call 0
fail: caixa ocupado
$show
Caixas: [carla, -----, -----]
Espera: [maria]

#TEST_CASE empty waiting

$call 2
$show
Caixas: [carla, -----, maria]
Espera: []

#TEST_CASE empty waiting

$call 1
fail: sem clientes

#TEST_CASE finish

$finish 0
$show
Caixas: [-----, -----, maria]
Espera: []

$finish 2
$show
Caixas: [-----, -----, -----]
Espera: []

#TEST_CASE error

$finish 3
fail: caixa inexistente
$finish 1
fail: caixa vazio

$end

```
