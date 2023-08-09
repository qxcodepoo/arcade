## @037 Budega

![cover](https://github.com/qxcodepoo/arcade/blob/master/base/037/cover.jpg)

<!-- toc -->
- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
<!-- toc -->

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

- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/037/.cache/draft.cpp)

![diagrama](https://github.com/qxcodepoo/arcade/blob/master/base/037/diagrama.png)

[](load)[](https://github.com/qxcodepoo/arcade/blob/master/base/037/diagrama.puml)[](fenced:filter:plantuml)

```plantuml
class Pessoa {
  - nome : string
  __
  + Pessoa(nome : string)
  + toString() : string
  __
  + getNome() : string
  + setNome(nome : string)
}

class Mercantil {
  
  ' se estiver em java , utilize ArrayList<Pessoa>
  ' se estiver em c++  , utilize vector<shared_ptr<Pessoa>>
  ' se estiver em ts   , utilize Array<Pessoa|null>
  - caixas    : Array<Pessoa | null>
  
  ' se estiver em java, utilize LinkedList<Pessoa>
  ' se estiver em c++ , utilize list<shared_ptr<Pessoa>>
  ' se estiver em ts  , utilize Array<Pessoa>
  - esperando : List <Pessoa>
  __
  
  ' verifica se existe essa posição no caixa
  ' emite erro se não existir
  - validarIndice(indice : int): boolean
  __
  
  ' inicializa os caixas com qtdCaixas posições iguais a null
  ' inicializa esperando como uma lista vazia
  + Mercantil(qtdCaixas : int)
  
  + toString() : string
  __
  
  ' adicione um cliente na fila de espera
  + chegar   (pessoa : Pessoa)
  
  ' verifica se indice é valido
  ' verifica se caixa[indice] está vazio
  ' verifica se tem alguém na fila de espera
  ' move o primeiro da fila de espera para o caixa[indice]
  + chamar   (indice : int): boolean
  
  ' verifica se indice é valido
  ' verifica se caixa[indice] tem alguém
  ' coloca o caixa[indice] como vazio
  + finalizar(indice : int): Pessoa | null

  '
  ' tenta colocar o furão na frente do besta na fila de espera
  ' procure pela posição do besta e se encontrar, 
  '   coloque o furão na frente do besta
  + furarFila(furao: Pessoa, besta: string): boolean

  ' procura pela pessoa na fila de espera
  ' e a remove da fila de espera
  + desistir(desistente: string): boolean

  ' o cliente que estava no caixa se revoltou com
  ' o preco do produto e fugiu no meio do atendimento
  ' procure o cliente por nome nos caixas e remova
  + revoltar(nome: string): boolean
}
```

[](load)

[![_](https://github.com/qxcodepoo/arcade/blob/master/base/037/../_images/resolucao.png)](https://youtu.be/Z7karsbg1ok)

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
