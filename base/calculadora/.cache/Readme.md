# Cuidado com a bateria da @calculadora

Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/calculadora/Readme.md)

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/calculadora/cover.jpg)

O objetivo dessa atividade é implementar uma calculadora a bateria. Se há bateria, ela executa operações de soma, multiplicação e divisão. É possível também mostrar a quantidade de bateria e recarregar a calculadora. Ela avisa quando está sem bateria e se há tentativa de divisão por 0.

***

## Intro

- Mostrar bateria da calculadora.
- Recarregar a bateria.
- Realizar operações matemáticas de soma e divisão.
- Se o usuário tentar realizar operações e a bateria estiver vazia, deverá ser mostrada uma notificação sobre falta de bateria.
- Se for tentada divisão por zero, deve ser notificado o erro.

***

## Draft

- [Solver.java](https://github.com/qxcodepoo/arcade/blob/master/base/calculadora/.cache/draft.java)
- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/calculadora/.cache/draft.cpp)
- [solver.ts](https://github.com/qxcodepoo/arcade/blob/master/base/calculadora/.cache/draft.ts)

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/calculadora/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts
class Calculator {

  ' a bateria atual
  + battery    : int

  ' o máximo de bateria suportado
  + batteryMax : int

  ' guarda o resultado da última operação
  + display    : float
  __

  ' inicia os atributos batteryMax utilizando o parametro passado
  ' battery e display começam com o zero
  + Calculator(batteryMax : int)

  ' aumenta a bateria de value, porém não além do máximo.
  + charge(value : int)
  
  ' realiza a soma de dois número e coloca o resultado no display
  ' tenta gastar bateria usando o método useBattery()
  '   verifica o resultado do retorno
  + sum(a : int, b : int)
  
  ' realiza a divisão de dois números e armazena o resultado no display
  ' tenta gastar bateria usando o método useBattery()
  '   verifica o resultado do retorno
  ' verifica se não é divisão por zero
  + division(num : int, den : int)
  
  ' tenta gastar uma unidade da bateria
  '   emite um erro se não conseguir.
  ' retorna se conseguiu gastar ou não.
  + useBattery(): boolean
  
  ' retorna uma string com o formato
  ' display = 0.00, bateria = 0
  + toString(): string
}

class Legenda {
  + atributoPublic
  - atributoPrivate
  # atributoProtected
  __
  + métodoPublic()
  - métodoPrivate()
  # métodoProtected()
}

```

<!-- load -->

***

## Shell

```bash
#__case iniciar mostrar e recarregar
# O comando "$init M" inicia uma calculadora passando por parâmetro a bateria máxima.
# O comando "$show" mostra o valor da última operação bem sucedida no display e o estado da bateria
# O comando "$charge V" recarrega a bateria de V
$init 5
$show
display = 0.00, battery = 0

#__ case charge
$charge 3
$show
display = 0.00, battery = 3
$charge 1
$show
display = 0.00, battery = 4

#__case boundary
$charge 2
$show
display = 0.00, battery = 5

#__case reset
$init 4
$charge 2
$show
display = 0.00, battery = 2
$charge 3
$show
display = 0.00, battery = 4
$end
```

***

```bash
#__case somando
$init 2
$charge 2
$sum 4 3
$show
display = 7.00, battery = 1

#__case gastando bateria
$sum 2 3
$show
display = 5.00, battery = 0

#__case sem bateria
$sum -4 -1
fail: bateria insuficiente

#__case recarregando
$charge 1
$show
display = 5.00, battery = 1
$sum -4 -2
$show
display = -6.00, battery = 0
$end
```

***

```bash
#__case dividindo
$init 3
$charge 3
$div 6 3
$show
display = 2.00, battery = 2
#__case dividindo por zero
$div 7 0
fail: divisao por zero

#__case gastando bateria
$show
display = 2.00, battery = 1
$div 7 2
$div 10 2
fail: bateria insuficiente
$show
display = 3.50, battery = 0
$end
```
