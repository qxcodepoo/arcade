# Gerenciando reservas e cancelamentos de uma sala de cinema

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Shell](#shell)
-- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/cinema/cover.jpg)

## Intro

O objetivo desta atividade é implementar métodos para manipular uma sala de cinema, permitindo a reserva, cancelamento e consulta de cadeiras.

- **Descrição**
  - A sala de cinema é representada pela classe Sala `Theater`, que possui um conjunto de cadeiras, cada uma associada a um cliente ou vazia.
  - Os métodos a serem implementados permitirão reservar uma cadeira para um cliente, cancelar a reserva de uma cadeira e consultar o estado das cadeiras na sala.
  - Cada cadeira pode estar associada a um objeto Cliente `Client`, representando um cliente que reservou a cadeira, ou ser nula, indicando que a cadeira está vazia.
  - Os métodos fornecidos devem lidar com validações, como verificar se a cadeira existe, se está ocupada e se o cliente já está presente na sala.

- **Responsabilidades**
  - A classe Sala `Theater` é responsável por gerenciar as operações relacionadas às cadeiras na sala de cinema.
    - Métodos a serem implementados:
      - públicos: são métodos acessados por outras classes.
        - `reserve(id: string, phone: number, index: number)`: Reserva uma cadeira para um cliente com o ID e telefone especificados.
        - `cancel(id: string)`: Cancela a reserva de uma cadeira para o cliente com o ID especificado.
        - `getSeats(): Array<Client | null>`: Retorna um array contendo o estado atual de todas as cadeiras na sala.
        - `toString(): string`: Retorna uma representação em string do estado atual das cadeiras na sala.
      - privados: são métodos apenas de uso interno, utilizados para auxiliar as operações da classe.
        - `search(name: string): int`: Procura o índice da cadeira reservada pelo cliente com o nome especificado.
        - `verifyIndix(index: number)`: Verifica se um índice de cadeira é válido na sala.
  - A classe `Client` é responsável por representar os clientes que reservam cadeiras na sala de cinema.
    - A classe possui métodos para obter e definir o ID e telefone do cliente, bem como uma representação em string do cliente.

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/cinema/diagrama.png)

## Draft

<!-- links .cache/draft -->
- cpp
  - [shell.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/cinema/.cache/draft/cpp/shell.cpp)
- java
  - [Shell.java](https://github.com/qxcodepoo/arcade/blob/master/base/cinema/.cache/draft/java/Shell.java)
- ts
  - [shell.ts](https://github.com/qxcodepoo/arcade/blob/master/base/cinema/.cache/draft/ts/shell.ts)
<!-- links -->

## Shell

```bash
#TEST_CASE init 1
$show
[]
#TEST_CASE init 2
$init 5
$show
[- - - - -]
#TEST_CASE init 3
$init 4
$show
[- - - -]
$end
```

```sh
#TEST_CASE reservas

$init 4
$reserve davi 3232 0
$reserve joao 3131 3
$show
[davi:3232 - - joao:3131]

#TEST_CASE ocupado

$reserve rute 3030 0
fail: cadeira ja esta ocupada

#TEST_CASE duplicado

$reserve davi 3234 2
fail: cliente ja esta no cinema
$end
```

```sh
#TEST_CASE cadeira invalida

$init 4
$reserve davi 3232 5
fail: cadeira nao existe

#TEST_CASE cancelamentos

$reserve davi 3232 0
$reserve joao 3131 3
$cancel davi
$show
[- - - joao:3131]

#TEST_CASE cancelamentos errado

$cancel rita
fail: cliente nao esta no cinema
$show
[- - - joao:3131]
$end
```
