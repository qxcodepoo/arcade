# @ligacao

<!-- toch -->
[Intro](#intro) | [Shell](#shell) | [Diagrama de Classes](#diagrama-de-classes)
-- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/ligacao/cover.jpg)

- TODO
- solver
- raiox
- diagrama

_Você digita o número de Maria no celular e aparece que você está ligando pra João. Hum, alguma coisa errada não está certa._

Vamos criar o módulo que gerência ligações da nossa agenda telefônica. Ele vai ser capaz de encontrar o número da agenda que corresponde à aquele número, montar nossa lista de contatos mais ligados e histórico de ligações.

## Intro

- Contato
  - O contato agora guarda um contato de ligações para registrar quantas vezes foi feita uma ligação para ele.
  - Atualize o toString do contato para apresentar o contador de ligações.

- Ligação
  - Ligar pra um número, incrementando no Contato a quantidade de vezes que ele recebeu uma ligação.
  - Se o número ligado pertencer a vários contatos, incremente o contador de ligações em todos eles.
  - Se o número não pertencer a nenhum contato, incremente o contador de ligações de um contato com o número do telefone igual ao número ligado.
  - Se não for passado o número, mas o nome de um contato, ligue para o primeiro número do contato.

- SpeedList
  - Mostrar a speedList, uma lista dos contatos ordenados pela quantidade de ligações recebidas, começando pelos que receberam mais ligações primeiro.
  - Não mostre contatos os que nunca receberam ligações.
  - Se dois contatos tiverem a mesma quantidade de ligações, mostre primeiro o que estiver em ordem alfabética.
  - Mostre a quantidade de ligações recebidas entre parênteses.
  - Não mostre o contato se ele não está cadastrado.

- Histórico
  - Mostra o histórico das ligações efetuadas.
  - Ao mostrar o contato que foi ligado, se o número estiver em mais de um contato, mostre o primeiro contato relacionado àquele número.
  - Se não encontrar contato, mostre apenas o número e a quantidade de ligações feitas para ele.

- Ao adicionar ou remover um contato ou telefone
  - Mantenha a integridade dos dados, removendo o contato ou telefone de todos os lugares que ele aparece.

## Shell

```sh
#TEST_CASE inicializando agenda
$add eva oi:8585 claro:9999 tim:3434
$add ana casa:4567 oi:8754
$add ivo tim:5454
$add rui vivo:2222 oi:9991
$add zac recado:3131

$agenda
- ana [casa:4567, oi:8754]
- eva [claro:9999, oi:8585, tim:2221]
- ivo [tim:5454]
- rui [oi:9991, vivo:2222]
- zac [recado:5454] 

#TEST_CASE ligando
$call ana
ligando ana casa:4567
$call 8754
ligando ana oi:8754
$call 8585
ligando eva oi:8585

#TEST_CASE ivo e rui
$call 5454
ligando ivo tim:5454

#TEST_CASE numero que nao existe
$call 555
ligando 555

$call 555
ligando 555

$speedList
- ana {2 call}[casa:4567, oi:8754]
- eva {1 call}[claro:9999, oi:8585, tim:2221]
- ivo {1 call}[tim:5454]
- rui {1 call}[oi:9991, vivo:2222]

$history
:call 4567 - ana {2 call}
:call 8754 - ana {2 call}
:call 8585 - eva {1 call}
:call 5454 - ivo {1 call}
:call 555 - {2 call}
:call 555 - {2 call}

#TEST_CASE update contatos e mantendo a integridade
$rmFone ana casa
$rmFone eva oi

$speedList
- ana {1 call}[oi:8754]
- ivo {1 call}[tim:5454]
- rui {1 call}[oi:9991, vivo:2222]

$historico
:call 4567 - {1 call}
:call 8754 - ana {1 call}
:call 8585 - {1 call}
:call 5454 - ivo {1 call}
:call 555 - 555 {2 call}
:call 555 - 555 {2 call}

#TEST_CASE removendo contatos e mantendo a integridade
$rm ivo

$speedList
- ana {1 call}[oi:8754]
- rui {1 call}[oi:9991, vivo:2222]

$historico
:call 4567 - 4567 {1 call}
:call 8754 - ana {1 call}
:call 8585 - 8585 {1 call}
:call 5454 - rui {1 call}
:call 555 - 555 {2 call}
:call 555 - 555 {2 call}

$add vei budega:555

$speedList
- vei {2 call}[budega:555]
- ana {1 call}[oi:8754]
- rui {1 call}[oi:9991, vivo:2222]

$historico
:call 4567 - 4567 {1 call}
:call 8754 - ana {1 call}
:call 8585 - 8585 {1 call}
:call 5454 - rui {1 call}
:call 555 - vei {2 call}
:call 555 - vei {2 call}

$end
```

## Diagrama de Classes

- Métodos Get e Set de atributos básicos omitidos.
