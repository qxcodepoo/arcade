# Cinema

![cover](cover.jpg)

[](toc)

- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
[](toc)

O objetivo dessa atividade é implementar o sistema de alocação de uma única sala de cinema. Se existem cadeiras livres, os clientes podem reservá-las. Também podem desistir da reserva. O sistema deve mostrar quem está sentado em cada cadeira.

Nessa atividade, você deverá criar:

1. Uma classe que representa o cliente.
2. Uma classe que representa a sala de cinema e guarda os clientes.

## Intro

Seu sistema deverá:

- **Inicializando.**
  - Iniciar a sala de cinema.
    - Ao iniciar, você deve informar quantos assentos existem na sua sala.
  - Mostrar o estado da sala, escrevendo um - para cada cadeira vazia.
  - Se uma nova sala for iniciada, apague todas as informações da sala antiga.
- **Reservas.**
  - reservar uma cadeira para um cliente passando id, telefone e número da cadeira.
    - avise que houve erro ao tentar colocar duas pessoas na mesma cadeira.
    - avise que houve erro ao tentar colocar duas pessoas com mesmo id na sala.
    - atualize a função show para mostrar os clientes onde estiverem sentados.
- **Cancelamentos.**
  - Cancele reserva passando o id do cliente.

***

## Guide

![diagrama](diagrama.png)

[](load)[](diagrama.puml)[](plantuml:fenced:filter)

```plantuml
class Client {
  - fone : string
  - id   : string
  __
  + Client(id : string, fone : string)
  __
  + getFone() : string
  + getId()   : string
  + setFone(fone : string)
  + setId(id : string)
  __
  + toString() : string
}

class Sala {
  '
  - cadeiras : Array<Client | null>
  '
  ' procura em todas as cadeiras não nulas
  ' pelo nome do cliente e se encontrar
  ' retorna o índice ou então -1
  - procurar(nome: string): int
  '
  ' verifica se o indice da cadeira é válido
  - verificarIndice(indice: int): boolean
  __
  '
  ' inicia todas as cadeiras como null
  + Sala(capacidade : int)
  '
  ' verifica se o índice é válido (use o método verificarIndice)
  ' verifica se a cadeira está ocupada
  ' verifica se o cliente já está na sala (use o método procurar)
  ' cria o cliente e coloca na cadeira
  + reservar(id : string, fone : string, ind : int) : boolean
  '
  ' procura o cliente pelo nome (use o método procurar)
  ' remover o cliente da cadeira
  + cancelar(id : string)
  __
  + getCadeiras() : Array<Client | null>
  __
  + toString() : string
}
```

[](load)

- [solver.cpp](.cache/draft.cpp)
- [Solver.java](.cache/draft.java)

***

## Shell

```bash
#__case init 1
$show
[]
#__case init 2
$init 5
$show
[- - - - -]
#__case init 3
$init 4
$show
[- - - -]
$end
```

```sh

#__case reservas
$init 4
$reservar davi 3232 0
$reservar joao 3131 3
$show
[davi:3232 - - joao:3131]

#__case ocupado
$reservar rute 3030 0
fail: cadeira ja esta ocupada

#__case duplicado
$reservar davi 3234 2
fail: cliente ja esta no cinema
$end
```

```sh
#__case cadeira invalida
$init 4
$reservar davi 3232 5
fail: cadeira nao existe
#__case cancelamentos
$reservar davi 3232 0
$reservar joao 3131 3
$cancelar davi
$show
[- - - joao:3131]
#__case cancelamentos errado
$cancelar rita
fail: cliente nao esta no cinema
$show
[- - - joao:3131]
$end
#__end__
```
