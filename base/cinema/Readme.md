## Sala de Cinema
### Vamos ao cinema? Dá para parcelar em quantas vezes?.
![](figura.jpg)

O objetivo dessa atividade é implementar o sistema de alocação de uma única sala de cinema. Se existem cadeiras livres, os clientes podem reservá-las. Também podem desistir da reserva. O sistema deve mostrar quem está sentado em cada cadeira.

Nessa atividade, você deverá criar:
- Uma classe que representa o cliente.
- Uma classe que representa a sala de cinema e guarda os clientes.
- Uma classe que controle o fluxo de entrada e saída e processe as chamadas.

## Funcionalidades
Seu sistema deverá:

- **[3.0 P] Inicializando.** 
    - Iniciar a sala de cinema. 
        - Ao iniciar, você deve informar quantos assentos existem na sua sala.
    - Mostrar o estado da sala, escrevendo um - para cada cadeira vazia.
    - Se uma nova sala for iniciada, apague todas as informações da sala antiga.
- **[4.0 P] Reservas.** 
    - reservar uma cadeira para um cliente passando id, telefone e número da cadeira.
        - avise que houve erro ao tentar colocar duas pessoas na mesma cadeira.
        - avise que houve erro ao tentar colocar duas pessoas com mesmo id na sala.
        - atualize a função show para mostrar os clientes onde estiverem sentados.
- **[3.0 P] Cancelamentos.** 
    - Cancele reserva passando o id do cliente.

```bash
#__case inicializar

$show
[ ]
$init 5
$show
[ - - - - - ]
$init 4
$show
[ - - - - ]

#__case reservas

$reservar davi 3232 0
$reservar joao 3131 3
$show
[ davi:3232 - - joao:3131 ]
$reservar rute 3030 0
failure: cadeira ja esta ocupada
$reservar davi 3234 2
failure: cliente ja esta no cinema

#__case cancelamentos

$cancelar davi
$show
[ - - - joao:3131 ]
$cancelar rita
failure: cliente nao esta no cinema
$show
[ - - - joao:3131 ]
$end
#__end__
```


---
## Raio X

```java
class Cliente
+ id: string
+ fone: string

class Cinema 
+ cadeiras:Cliente[]
--
+ reservar(id, fone, indice): bool    //reservar
+ cancelar(id): bool   //cancelar
--
+ contructor(lotacao)
```
## Respostas


[C++](solver.cpp)













