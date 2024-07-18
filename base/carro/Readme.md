# @carro - Se não pode comprar um, construa

<!-- toch -->
[Model](#model) | [Intro](#intro) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft)
-- | -- | -- | -- | --
<!-- toch -->

![cover](cover.jpg)

## Model

Esta atividade utiliza um padrão de projeto de requisições e respostas.

- Os testes são feitos através de requisições de texto e podem ser vistos na seção [Shell](#shell).
- A classe `Shell` é responsável por ler as requisições de texto, decodificar e chamar os métodos da classe `Adapter`.
- Na classe `Adapter`, você deve implementar e conectar seu código.
- A classe `Adapter` é apenas a classe de conexão. Você deve implementar as classes que contêm a lógica do problema. Utilize como base o diagrama de classes e a descrição do problema.
- Mensagens de erro podem ser lançadas por exceções ou por comandos de `print` diretamente para o terminal.
- Ao mostrar uma string formatada, será utilizado o modelo do Python `f"{variavel:param}"`.
- Se houver, na seção [Cheat](#cheat), você pode conferir as respostas desta atividade.

## Intro

Nesta atividade, vamos implementar um carro ecológico. Ele deve ser capaz de embarcar e desembarcar pessoas, abastecer e andar.

- Descrição
  - O carro deve ser inicializado com o tanque vazio, sem ninguém dentro e com 0 quilômetros percorridos. Para simplificar, nosso carro esportivo suporta até 2 pessoas e seu tanque suporta até 100 litros de combustível.
- Responsabilidades
  - O código deve ser implementado na classe `Carro`.
  - A classe `Adapter` é responsável por chamar os métodos da classe `Carro`.
  - A classe `Shell` é responsável por ler as requisições de texto e chamar os métodos da classe `Adapter`.
- Comandos
  - Todos os comandos seguem o modelo `$comando arg1 arg2 ...`.
  - `$show` - Mostra o estado atual do carro.
    - `f"pass:{this.pass},gas:{this.gas},km:{this.km}"`.
    - Exemplo: `pass: 0, gas: 0, km: 0`.
  - `$init` - Inicializa todos os atributos.
    - Tanque vazio.
    - 0 passageiros.
    - 0 quilômetros percorridos.
    - Máximo de 2 pessoas.
    - Máximo de 100 litros de gasolina.
  - `$enter` - Embarca uma pessoa por vez, mas não além do máximo.
    - Se o carro estiver lotado, emite a mensagem de erro `fail: limite de pessoas atingido`.
  - `$leave` - Desembarca uma pessoa por vez.
    - Se não houver ninguém no carro, emite a mensagem de erro `fail: nao ha ninguem no carro`.
  - `$fuel qtd` - Abastece o tanque com a quantidade de litros de combustível passada.
    - Caso tente abastecer acima do limite, descarta o valor excedente.
  - `$drive dist` - Para dirigir, o carro consome combustível e aumenta a quilometragem.
    - Só pode dirigir se houver combustível e se houver alguém no carro.
    - Caso não haja ninguém no carro, emite a mensagem de erro “fail: não há ninguém no carro”.
    - Caso não haja combustível, emite a mensagem de erro “fail: tanque vazio”.
    - Caso não exista combustível suficiente para completar a viagem inteira, dirige o máximo possível e emite uma mensagem indicando quanto foi percorrido, como no exemplo `fail: tanque vazio após andar {qtd} km`.

## Guide

![diagrama](diagrama.png)

## Shell

```bash
#TEST_CASE inicializar
$show
pass: 0, gas: 0, km: 0

#TEST_CASE entrar
$enter
$enter
$show
pass: 2, gas: 0, km: 0

#TEST_CASE limite
$enter
fail: limite de pessoas atingido
$show
pass: 2, gas: 0, km: 0

#TEST_CASE sair
$leave
$show
pass: 1, gas: 0, km: 0

#TEST_CASE limite saida
$leave
$leave
fail: nao ha ninguem no carro
$show
pass: 0, gas: 0, km: 0
$end
```

***

```bash
#TEST_CASE abastecer
$fuel 60
$show
pass: 0, gas: 60, km: 0

#TEST_CASE dirigir vazio
$drive 10
fail: nao ha ninguem no carro

#TEST_CASE dirigir
$enter
$drive 10
$show
pass: 1, gas: 50, km: 10

#TEST_CASE para longe
$drive 70
fail: tanque vazio apos andar 50 km
$drive 10
fail: tanque vazio
$show
pass: 1, gas: 0, km: 60

#TEST_CASE enchendo o tanque
$fuel 200
$show
pass: 1, gas: 100, km: 60
$end
#
```

## Draft

<!-- links .cache/draft -->
- cpp
  - [adapter.hpp](.cache/draft/cpp/adapter.hpp)
  - [fn.hpp](.cache/draft/cpp/fn.hpp)
  - [shell.cpp](.cache/draft/cpp/shell.cpp)
- java
  - [Adapter.java](.cache/draft/java/Adapter.java)
  - [Shell.java](.cache/draft/java/Shell.java)
- ts
  - [aashell.ts](.cache/draft/ts/aashell.ts)
  - [adapter.ts](.cache/draft/ts/adapter.ts)
<!-- links -->
