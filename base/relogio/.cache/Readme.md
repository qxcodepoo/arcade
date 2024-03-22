# Garante uma hora válida no @relogio

<!-- toch -->
[Intro](#intro) | [Treino](#treino) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | --
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

## Treino

- Parte 1: atributos públicos
  - Crie a classe relógio com os atributos públicos hora, minuto e segundo.
  - Crie o método construtor que inicializa os atributos com 0.
  - Crie o método toString que retorna a hora no formato HH:MM:SS.
  - Crie um objeto relógio, atribua valores para hora, minuto e segundo e imprima a hora.
  - Atribua valores inválidos para hora, minuto e segundo e imprima a hora.
- Parte 2: atributos privados
  - Torne os atributos hora, minuto e segundo privados.
  - Crie os métodos getters e setters para cada atributo.
    - Nos métodos set, NÃO realize nenhuma validação.
  - Crie um objeto relógio, atribua valores para hora, minuto e segundo e imprima a hora.
  - Atribua valores inválidos para hora, minuto e segundo e imprima a hora.
- Parte 3: validação
  - Nos métodos set, realize a validação dos valores.
    - Hora deve ser entre 0 e 23. Minuto e segundo devem ser entre 0 e 59.
  - Crie um objeto relógio, atribua valores para hora, minuto e segundo e imprima a hora.
  - Tente atribuir valores inválidos para hora, minuto e segundo e verifique se a hora permaneceu a mesma.
- Parte 4: construtor
  - Crie um método construtor que recebe hora, minuto e segundo.
  - Utilize os métodos set para fazer a inicialização dos atributos.
  - Tente atribuir valores inválidos para hora, minuto e segundo através do construtor e verifique se a hora permaneceu a mesma.
- Parte 5: nextSecond
  - Crie um método nextSecond que incrementa o segundo em 1.
  - Crie um objeto relógio, atribua valores para hora, minuto e segundo e imprima a hora.
  - Teste o método nextSecond criando horas com os seguintes valores e testando:
    - 10:02:30
    - 15:50:59
    - 21:59:59
    - 23:59:59

## Guide

- [Solver.java](https://github.com/qxcodepoo/arcade/blob/master/base/relogio/.cache/draft.java)
- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/relogio/.cache/draft.cpp)
- [solver.ts](https://github.com/qxcodepoo/arcade/blob/master/base/relogio/.cache/draft.ts)

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/relogio/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts
'--
@startuml

skinparam defaultFontName Hasklig
skinparam dpi 150

'==
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

'--
@enduml
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
