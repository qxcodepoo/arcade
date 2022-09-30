## @010 Cinema & Vetor de null

![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/010/cover.jpg)

[](toc)

- [Requisitos](#requisitos)
- [Guide](#guide)
- [Shell](#shell)
[](toc)


O objetivo dessa atividade é implementar o sistema de alocação de uma única sala de cinema. Se existem cadeiras livres, os clientes podem reservá-las. Também podem desistir da reserva. O sistema deve mostrar quem está sentado em cada cadeira.

Nessa atividade, você deverá criar:

1. Uma classe que representa o cliente.
2. Uma classe que representa a sala de cinema e guarda os clientes.

## Requisitos
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
![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/010/diagrama.png)

- [solver.cpp](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/010/.cache/draft.cpp)
- [Solver.java](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/010/.cache/draft.java)

***
## Shell

```bash
#__case init 1
$show
[ ]
#__case init 2
$init 5
$show
[ - - - - - ]
#__case init 3
$init 4
$show
[ - - - - ]
$end
```

```sh

#__case reservas
$init 4
$reservar davi 3232 0
$reservar joao 3131 3
$show
[ davi:3232 - - joao:3131 ]

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
[ - - - joao:3131 ]
#__case cancelamentos errado
$cancelar rita
fail: cliente nao esta no cinema
$show
[ - - - joao:3131 ]
$end
#__end__
```











