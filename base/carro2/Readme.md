# @carro2 - Se não pode comprar um, construa

<!-- toch -->
[Model](#model) | [Intro](#intro) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft)
-- | -- | -- | -- | --
<!-- toch -->

![cover](cover.jpg)

## Model

Essa atividade utiliza um padrão de projeto de requisições e respostas.

- Os testes são feitos através de requisições de texto e podem ser vistos na seção [Shell](#shell).
- A classe `Shell` é responsável por ler as requisições de texto, decodificar e chamar os métodos da classe `Adapter`.
- Na classe `Adapter` é onde você deve implementar e conectar seu código.
- A classe `Adapter` é apenas a classe de conexão, você deve as classes que implementam a lógica do problema. Use como base o diagrama de classes e a descrição do problema.
- Mensagens de erros podem ser lançadas por exceções ou comandos de `print` diretamente para o terminal.
- Ao mostrar uma string formatada, será utilizado o modelo do python `f"{variavel:param}"`.
- Se houver, na seção de [Cheat](#cheat), você pode conferir as respostas dessa atividade.

## Intro

Nessa atividade, vamos implementar um carro ecológico. Ele deve poder embarcar e desembarcar pessoas, colocar combustível e andar.

- Descrição
  - O carro deve ser inicializado de tanque vazio, sem ninguém dentro e com 0 de quilometragem.
  Para simplificar, nosso carro esportivo suporta até 2 pessoas e seu tanque suporta até 100 litros de combustível.
- Responsabilidades
  - O código deve ser implementado na classe Carro.
  - A classe Adapter é responsável por chamar os métodos da classe Carro.
  - A classe Shell é responsável por ler as requisições de texto e chamar os métodos da classe Adapter.
- Comandos
  - Todos os comandos seguem o modelo `$comando arg1 arg2 ...`
  - `$show` - Mostra o estado atual do carro.
    - `f"pass:{this.pass},gas:{this.gas},km:{this.km}"`
    - exemplo: `pass: 0, gas: 0, km: 0`
  - `$init` - inicializa todos os atributos
    - tanque vazio
    - 0 passageiros
    - 0 de quilometragem
    - máximo de 2 pessoas
    - máximo de 100 litros de gasolina
  - `$enter` - embarca uma pessoa por vez, mas não além do máximo.
    - Se o carro estiver lotado, emita a mensagem de erro `fail: limite de pessoas atingido`.
  - `$leave` - Desembarca uma pessoa por vez.
    - Se não houver ninguém no carro, emita a mensagem de erro `fail: nao ha ninguem no carro`
  - `$fuel qtd` -  Abastece o tanque passando a quantidade de litros de combustível
    - Caso tente abastecer acima do limite, descarte o valor que passou.
  - `$drive dist` - Para dirigir, o carro gasta combustível e aumenta a quilometragem.
    - Só pode dirigir se houver combustível e se houver alguém no carro.
    - Caso não haja ninguém no carro, emita a mensagem de erro “fail: nao ha ninguém no carro”.
    - Caso não haja combustível, emita a mensagem de erro “fail: tanque vazio”;
    - Caso não exista combustível suficiente para completar a viagem inteira, dirija o que for possível e emita uma mensagem indicando quanto foi percorrido, como no exemplo `fail: tanque vazio apos andar {qtd} km`.

## Guide

![diagrama](diagrama.png)

- Parte 1: entrar
  - Crie a classe Car com os atributos pass, passMax, gas, gasMax e km;
  - Inicialize os atributos no construtor;
  - Crie o método enter que incrementa pass;
  - Crie um if para impedir que pass ultrapasse passMax;
  - Crie o método toString mostrar o estado do carro.
  - Teste seu código.
- Parte 2: sair.
  - Crie o método leave que decrementa pass;
  - Crie um if para impedir que pass seja menor que 0;
  - Teste seu código.
- Parte 3: abastecer.
  - Crie o método fuel que incrementa gas com o valor passado;
  - Crie um if para impedir que gas ultrapasse gasMax;
  - Teste seu código.
- Parte 4: dirigir.
  - Crie o método drive que incrementa km e decrementa gas com o valor passado;
  - Crie testes para impedir que o carro dirija em passageiros ou sem combustível;
  - Teste seu código.
- Parte 5: dirigir longe.
  - Crie testes para impedir que o carro dirija mais do que o combustível permite;
  - Teste seu código.
- Parte 6: Adapter
  - Na classe Adapter, crie um atributo carro e o inicialize no construtor.
  - Nos outros métodos de Adapter, chame o método equivalente da classe Carro.

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
