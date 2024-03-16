# Gerencie a fila de espera e atendimento da @budega

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/budega/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo budega`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell)
-- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/budega/cover.jpg)

Nosso objetivo no trabalho é modelar uma fila de atendimento de um Mercatil.

## Intro

- Quando o mercantil é incializado, é definido a quantidade de caixas que ele terá.
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

## Guide

- [draft.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/budega/.cache/draft.cpp)
- [draft.java](https://github.com/qxcodepoo/arcade/blob/master/base/budega/.cache/draft.java)
- [draft.ts](https://github.com/qxcodepoo/arcade/blob/master/base/budega/.cache/draft.ts)

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/budega/diagrama.png)

[![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/budega/../_images/resolucao.png)](https://youtu.be/Z7karsbg1ok)

***

## Shell

```sh
#__case iniciar
$init 2
$show
Caixas: [-----, -----]
Espera: []

#__case arrive
$arrive carla
$arrive maria
$arrive rubia

$show
Caixas: [-----, -----]
Espera: [carla, maria, rubia]

#__case call
$call 0
$show
Caixas: [carla, -----]
Espera: [maria, rubia]

#__case finish
$finish 0
$show
Caixas: [-----, -----]
Espera: [maria, rubia]

$end

```

```sh
#__case iniciar2
$init 3
$show
Caixas: [-----, -----, -----]
Espera: []

$arrive carla
$arrive maria

$show
Caixas: [-----, -----, -----]
Espera: [carla, maria]

#__case call
$call 0
$call 0
fail: caixa ocupado
$show
Caixas: [carla, -----, -----]
Espera: [maria]

#__case empty waiting
$call 2
$show
Caixas: [carla, -----, maria]
Espera: []

#__case empty waiting
$call 1
fail: sem clientes

#__case finish
$finish 0
$show
Caixas: [-----, -----, maria]
Espera: []

$finish 2
$show
Caixas: [-----, -----, -----]
Espera: []

#__case error
$finish 3
fail: caixa inexistente
$finish 1
fail: caixa vazio

$end

```
