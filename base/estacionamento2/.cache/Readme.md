# Cobrando o valor de carros e motos no @estacionamento2

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/estacionamento2/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo estacionamento2`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/estacionamento2/cover.jpg)

## Intro

O sistema de estacionamento é responsável por gerenciar veículos em um estacionamento, registrando a entrada e saída de veículos, calculando o valor a ser pago pelo tempo de permanência e fornecendo informações sobre os veículos estacionados.

- Você deve utilizar herança para construir um sistema para gerenciar um estacionamento de bicicletas, carros e motos.
- A classe Veículo é uma classe abstrata que possui os atributos `id`, `entrada` e `tipo`.
- A classe Veículo possui um método abstrato `calcularValor()` que deve ser implementado pelas classes filhas.
- A classe Veículo possui um método `toString()`.

### Responsabilidades

- **Registrar Entrada de Veículo:**
  - O sistema deve permitir que novos veículos entrem no estacionamento, registrando o tipo de veículo e seu identificador.
  - O tempo de entrada do veículo deve ser registrado.

- **Registrar Saída de Veículo:**
  - O sistema deve permitir que veículos saiam do estacionamento, registrando o tempo de saída do veículo.
  - Com base no tempo de entrada e saída, o sistema deve calcular o valor a ser pago pelo estacionamento.

- **Calcular Valor a Pagar:**
  - O valor a ser pago pelo estacionamento é calculado com base no tipo de veículo estacionado e no tempo de permanência.
  - O cálculo do valor varia de acordo com o tipo de veículo:
    - **Bike:** paga R$3 fixos.
    - **Moto:** paga o valor em minutos dividido por 20.
    - **Carro:** paga o valor em minutos dividido por 10, mas o valor mínimo é 5.00.

- **Obter Lista de Veículos Estacionados:**
  - O sistema deve ser capaz de fornecer uma lista de todos os veículos atualmente estacionados, incluindo o tipo de veículo, identificador e tempo de entrada.

## Guide

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/estacionamento2/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts
abstract class Veiculo {
  - id : string
  # tipo : string
  # horaEntrada : number

  ' tipo será definido na classe filha
  ' id será o nome do dono da bike ou a placa do carro/moto
  + Veiculo(id : string, tipo : string)

  + setEntrada(horaEntrada : number) : void
  + getEntrada() : number

  + getTipo() : string
  + getId() : string

  ' mostra o valor a ser pago
  + abstract calcularValor(horaSaida: number): void

  ' retornar {tipo} : {id} : {horaEntrada}
  ' alinhado   10      10
  + toString() : string
}

class Bike extends Veiculo {
  + Bike(id : string)
  + calcularValor(horaSaida : number) : void
}

class Moto extends Veiculo {
  + Moto(id : string)
  + calcularValor(horaSaida : number) : void
}

class Carro extends Veiculo {
  + Carro(id : string)
  + calcularValor(horaSaida : number) : void
}

class Estacionamento {
  - veiculos : Veiculo[]
  - horaAtual : number

  + Estacionamento()

  ' retorna -1 se não encontrar ou o indice do veiculo no array
  - procurarVeiculo(id : string) : number

  ' estaciona o veiculo no array, salva a hora de entrada
  + estacionar(veiculo : Veiculo) : void

  ' procurar o veiculo no array, calcular o valor para pagar
  + pagar(id : string) : void

  ' procurar o veiculo no array e o remove
  + sair(id : string) : void

  ' incrementa a hora atual
  + passarTempo() : void

  ' mostra a lista de veículos na ordem que foram estacionados
  + toString() : string
}

```

<!-- load -->

## Shell

```sh

#__case entrada bike
$show
Hora atual: 0
$tempo 30
$estacionar bike elias
$show
______Bike : _____elias : 30
Hora atual: 30

#__case entrada moto
$tempo 20
$estacionar moto abc1234
$show
______Bike : _____elias : 30
______Moto : ___abc1234 : 50
Hora atual: 50
#__case entrada carro
$tempo 50
$estacionar carro pog1000
$show
______Bike : _____elias : 30
______Moto : ___abc1234 : 50
_____Carro : ___pog1000 : 100
Hora atual: 100
$tempo 100
$estacionar carro uva9999
$tempo 30
$show
______Bike : _____elias : 30
______Moto : ___abc1234 : 50
_____Carro : ___pog1000 : 100
_____Carro : ___uva9999 : 200
Hora atual: 230

#__case saida
$pagar elias
Bike chegou 30 saiu 230. Pagar R$ 3.00
$pagar abc1234
Moto chegou 50 saiu 230. Pagar R$ 9.00
$pagar pog1000
Carro chegou 100 saiu 230. Pagar R$ 13.00
$pagar uva9999
Carro chegou 200 saiu 230. Pagar R$ 5.00
$end
```
