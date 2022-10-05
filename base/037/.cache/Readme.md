## @037 Budega & Gerenciando uma fila de espera e um vetor de nulos

![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/037/cover.jpg)

[](toc)

- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
[](toc)

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
![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/037/diagrama.png)

- [solver.cpp](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/037/.cache/draft.cpp)

***
## Shell


```sh
#__case iniciar
$init 2
$show
Caixas: | 0:----- | 1:----- |
Espera: []

#__case arrive
$arrive joao
$arrive maria
$arrive ana

$show
Caixas: | 0:----- | 1:----- |
Espera: [joao, maria, ana]

#__case call
$call 0
$show
Caixas: | 0: joao | 1:----- |
Espera: [maria, ana]

#__case finish
$finish 0
$show
Caixas: | 0:----- | 1:----- |
Espera: [maria, ana]

$end

```

```sh
#__case iniciar2
$init 3
$show
Caixas: | 0:----- | 1:----- | 2:----- |
Espera: []

$arrive joao
$arrive maria

$show
Caixas: | 0:----- | 1:----- | 2:----- |
Espera: [joao, maria]

#__case call
$call 0
$call 0
fail: caixa ocupado
$show
Caixas: | 0: joao | 1:----- | 2:----- |
Espera: [maria]

#__case empty waiting
$call 1
$show
Caixas: | 0: joao | 1:maria | 2:----- |
Espera: []

#__case empty waiting
$call 2
fail: sem clientes

#__case finish
$finish 0
$finish 1
$show
Caixas: | 0:----- | 1:----- | 2:----- |
Espera: []

#__case error
$finish 3
fail: caixa inexistente
$finish 1
fail: caixa vazio

$end

```