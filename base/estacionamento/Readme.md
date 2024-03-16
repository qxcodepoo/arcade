# Cobrando o valor de carros e motos no @estacionamento

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/estacionamento/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo estacionamento`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/estacionamento/cover.jpg)

- Você deve utilizar herança para construir um sistema para gerenciar um estacionamento de bicicletas, carros e motos.
- A classe Veículo é uma classe abstrata que possui os atributos `id`, `entrada` e `tipo`.
- A classe Veículo possui um método abstrato `calcularValor()` que deve ser implementado pelas classes filhas.
- A classe Veículo possui um método `toString()`.

- A lógica de pagamento é
  - bike paga 3.00 independente do tempo
  - moto paga o valor em minutos dividido por 20
  - carro paga o valor em minutos dividido por 10, mas o valor mínimo é 5.00

## Resolução

[![image](https://user-images.githubusercontent.com/4747652/282258761-fc22aa99-0758-40e7-96a7-75eda3bcc772.png)](https://www.youtube.com/watch?v=6eFGKyJMCE4)

## Draft

- [draft.ts](https://github.com/qxcodepoo/arcade/blob/master/base/estacionamento/.cache/draft.ts)

## Guide

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/estacionamento/diagrama.png)

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
$bike elias
$show
______Bike : _____elias : 30
Hora atual: 30

#__case entrada moto
$tempo 20
$moto abc1234
$show
______Bike : _____elias : 30
______Moto : ___abc1234 : 50
Hora atual: 50
#__case entrada carro
$tempo 50
$carro pog1000
$show
______Bike : _____elias : 30
______Moto : ___abc1234 : 50
_____Carro : ___pog1000 : 100
Hora atual: 100
$tempo 100
$carro uva9999
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
