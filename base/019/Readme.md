# Agenda 5 - Serviço de Ligações

- TODO
    - solver
    - raiox
    - diagrama

![](figura.jpg)

<!--TOC_BEGIN-->
- [Requisitos Novos](#requisitos-novos)
- [Shell](#shell)
- [Diagrama de Classes](#diagrama-de-classes)

<!--TOC_END-->

_Você digita o número de Maria no celular e aparece que você está ligando pra João. Hum, alguma coisa errada não está certa._

Vamos criar o módulo que gerencia ligações da nossa agenda telefônica. Ele vai ser capaz de encontrar o número da agenda que corresponde à aquele número, montar nossa lista de contatos mais ligados e histórico de ligações.

## Requisitos Novos

- Contato
    - O contato agora guarda um contato de ligações para registrar quantas vezes foi feita uma ligação para ele.
    - Atualize o toString do contato para apresentar o contador de ligações.

- Ligação
    - Ligar pra um número, incrementando no Contato a quantidade de vezes que ele recebeu uma ligação.
    - Se o número ligado pertencer a vários contatos, incremente o contador de ligações em todos eles.

- SpeedList
    - Mostrar a speedList, uma lista dos contatos ordenandos pela quantidade de ligações recebidas, começando pelos que receberam mais ligações primeiro.
    - Não mostre contatos os que nunca receberam ligações.

- Histórico
    - Mostra o histórico das ligações efetuadas.
    - Ao mostrar o contato que foi ligado, se o número estiver em mais de um contato, mostre o primeiro contato relacionado àquele número.
    - Se não encontrar contato, mostre apenas o número.

## Shell
```sh
#__case inicializando agenda
$add eva oi:8585 claro:9999 tim:3434
$add ana casa:4567 oi:8754
$add ivo tim:5454
$add rui vivo:2222 oi:9991
$add zac recado:3131

$agenda
- ana [0:4567][1:8754]
- eva [0:8585][1:9999][2:2221]
- ivo [0:5454]
- rui [0:2222][1:9991]
- zac [0:5454]

#__case ligando
$call 4567
ligando ana
$call 8754
ligando ana
$call 5454
ligando eva
$call 5555
ligando 555

$speedList
- ana {2 call}[0:4567][1:8754]
- eva {1 call}[0:8585][1:9999][2:2221]
- ivo [0:5454]
- rui [0:2222][1:9991]
- zac [0:5454]

$history
:call 8832 - silva {2 lig}[oi 8832][tim 9934][casa 3232]
:call 5555 @ alves {1 lig}[oi 123]
:call 9934 - silva {2 lig}[oi 8832][tim 9934][casa 3232]
:call 5555 - 5555 {1 lig}[fone 5555]

#__case update contatos e mantendo a integridade
$rmFone eva 0

$speedList
$historico

#__case removendo contatos e mantendo a integridade
$rm alves

$speedList
$historico
```

## Diagrama de Classes

- Métodos Get e Set de atributos básicos omitidos.

![](/assets/ligacoes/diagrama.png)
