# Garante uma hora válida no @relogio

Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/relogio/Readme.md)

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell)
-- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/relogio/cover.jpg)

## Intro

Utilizando os comandos set para manter a hora correta

O sistema deverá:

- Gerenciar uma classe que guarda a hora, minuto e segundo.
- Ao iniciar a classe, hora, minuto e segundo devem ser setados para 0.
  - O construtor deve receber 3 parâmetros, hora, minuto e segundo.
  - Para fazer a inicialização dos 3 parâmetros, utilize os métodos set.
- Crie os métodos getters e setters para cada atributo.
  - Os métodos set devem garantir que os valor atribuúido sempre seja válido, ou não realize nenhuma mudança.
- Crie um método que imprime a hora no formato HH:MM:SS.
- Crie um método que incrementa o segundo em 1.

***

## Guide

- [Solver.java](https://github.com/qxcodepoo/arcade/blob/master/base/relogio/.cache/draft.java)
- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/relogio/.cache/draft.cpp)
- [solver.ts](https://github.com/qxcodepoo/arcade/blob/master/base/relogio/.cache/draft.ts)

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/relogio/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts
class Time {
  - hour   : int
  - minute : int
  - second : int
  __
  
  ' inicializa os atributos todos para 0
  ' invoca os métodos setHour, setMinute e setSecond
  ' para tentar atribuir valores válidos
  + Time(hour : int, minute : int, second : int)
  
  ' retorna string no formato hh:mm:ss
  + toString() : string
  __
  
  ' apenas retorna o valor dos atributos
  + getHour()   : int
  + getMinute() : int
  + getSecond() : int
  __
  
  ' se valor for válido
  '  atribui ao atributo hour
  ' emite erro se for inválido
  + setHour  (value   : int)
  
  ' se valor for válido
  '   atribui ao atributo minute
  ' emite erro se for inválido
  + setMinute(value : int)
  
  ' se valor for válido
  '   atribui ao atributo second
  ' emite erro se for inválido
  + setSecond(value : int)
  __
  
  ' incrementa o atributo second em um segundo
  ' então, se necessário, incrementa o atributo minute
  ' e, se necessário, incrementa o atributo hour
  + nextSecond()
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
#__case set
$show
00:00:00

#__case set

$set 10 02 30
$show 
10:02:30

#__case set2
$set 15 50 59
$show
15:50:59

#__case error

$set 25 10 30
fail: hora invalida

$show
15:10:30

#__case error2
$set 1 70 50
fail: minuto invalido
$show
01:10:50

#__case error3
$set 23 59 70
fail: segundo invalido
$show
23:59:50

#__case next
$set 15 59 59
$show
15:59:59

#__case next2

$next
$show
16:00:00

$end
```

***

```bash
#__case set
$set 23 59 59
$show
23:59:59

#__case next3

$next
$show
00:00:00

$end
```

***

```bash
#__case init
$init 10 20 30
$show
10:20:30

#__case init2

$init 90 20 30
fail: hora invalida

$show
00:20:30

#__case init3
$init 90 100 60
fail: hora invalida
fail: minuto invalido
fail: segundo invalido

$show
00:00:00

$end
```
