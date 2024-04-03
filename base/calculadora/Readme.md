# Cuidado com a bateria da @calculadora

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![cover](cover.jpg)

O objetivo dessa atividade é implementar uma calculadora a bateria. Se há bateria, ela executa operações de soma e divisão. É possível também mostrar a quantidade de bateria e recarregar a calculadora. Ela avisa quando está sem bateria e se há tentativa de divisão por 0.

***

## Intro

- Iniciar: `$init M`
  - ações
    - Inicia a calculadora com uma quantidade máxima de bateria M.
- Mostrar: `$show`
  - ações
    - Mostra o resultado da última operação bem-sucedida no display e o estado atual da bateria.
    - Exemplo de formatação: `display = {%.2f}, bateria = {%.2f}`
- Recarregar: `$charge V`
  - ações
    - Recarrega um valor V à bateria.
    - Não recarregar além do valor máximo.
  - erros
    - nenhum, se tentar recarregar além do valor máximo, recarregue apenas o necessário.
- Somar: `$sum A B`
  - ações
    - Realiza uma operação de soma de A + B colocando o resultado no display.
    - Consume 1 ponto de bateria.
  - erros
    - `fail: bateria insuficiente`, se não conseguir gastar a bateria.
- Dividir: `$div A B`
  - ações
    - Realiza uma operação de divisão de A / B colocando o resultado no display
    - Consume 1 ponto de bateria.
  - erros
    - `fail: bateria insuficiente`, se não conseguir gastar a bateria.
    - `fail: divisão por zero`, se gastou a bateria, mas tentou dividir por 0.
- Finalizar: `$end`

## Draft

<!-- draft -->
- cpp
  - [calculator.hpp](.cache/lang/cpp/calculator.hpp)
  - [fn.hpp](.cache/lang/cpp/fn.hpp)
  - [shell.cpp](.cache/lang/cpp/shell.cpp)
- java
  - [Calculator.java](.cache/lang/java/Calculator.java)
  - [Shell.java](.cache/lang/java/Shell.java)
- ts
  - [calculator.ts](.cache/lang/ts/calculator.ts)
  - [shell.ts](.cache/lang/ts/shell.ts)

<!-- draft -->

## Guide

![diagrama](diagrama.png)

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

### Primeira simulação

```bash
#__case iniciar mostrar e recarregar
$init 5
$show
display = 0.00, battery = 0

```

***

```bash
#__case charge
$charge 3
$show
display = 0.00, battery = 3
$charge 1
$show
display = 0.00, battery = 4
```

***

```bash
#__case boundary
$charge 2
$show
display = 0.00, battery = 5
```

***

```bash
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

### Segunda simulação

```bash
#__case somando
$init 2
$charge 2
$sum 4 3
$show
display = 7.00, battery = 1
```

***

```bash
#__case gastando bateria
$sum 2 3
$show
display = 5.00, battery = 0
```

***

```bash
#__case sem bateria
$sum -4 -1
fail: bateria insuficiente
```

***

```bash
#__case recarregando
$charge 1
$show
display = 5.00, battery = 1
$sum -4 -2
$show
display = -6.00, battery = 0
$end
```

### Terceira simulação

```bash
#__case dividindo
$init 3
$charge 3
$div 6 3
$show
display = 2.00, battery = 2
```

***

```bash
#__case dividindo por zero gastando bateria
$div 7 0
fail: divisao por zero
$show
display = 2.00, battery = 1
```

***

```bash
#__case gastando bateria
$div 7 2
$div 10 2
fail: bateria insuficiente
$show
display = 3.50, battery = 0
$end
```
