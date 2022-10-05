## @036 Relógio & Utilizando os comandos set para manter a hora correta

![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/036/cover.jpg)

[](toc)

- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
[](toc)

***
## Intro
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
![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/036/diagrama.png)

- [Solver.java](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/036/.cache/draft.java)
- [solver.cpp ](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/036/.cache/draft.cpp)
- [solver.ts  ](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/036/.cache/draft.ts)

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
