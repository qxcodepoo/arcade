## @009 Pula pula & Movendo objetos entre duas listas

![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/009/cover.jpg)

[](toc)

- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
[](toc)


Nosso objetivo no trabalho é modelar um gestor de pula pulas em um parquinho.

## Intro
- Inserir crianças na fila de espera do pula pula
- Mover a primeira criança da fila de espera do pula pula para dentro do pula pula.
- Mover a primeira criança que entrou no pula pula para o final da fila de espera.


***
## Guide
![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/009/diagrama.png)

- [solver.cpp](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/009/.cache/draft.cpp)
- [Solver.java](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/009/.cache/draft.java)

***
## Shell
```bash
#__case unico
# $chegou _nome _idade
# insere uma criança na fila de entrada do brinquedo
$arrive mario 5
$arrive livia 4
$arrive luana 3

# show
# mostra a fila de entrada e o pula pula
$show
=> luana:3 livia:4 mario:5 => [ ]

#__case entrando
# entrar
# tira a primeira criança da fila de entrada e insere no pula pula

$enter
$show
=> luana:3 livia:4 => [ mario:5 ]

#__case segunda pessoa
$enter
$show
=> luana:3 => [ livia:4 mario:5 ]

#__case saindo
$leave
$show
=> mario:5 luana:3 => [ livia:4 ]

#__case remove
$remove luana

$show
=> mario:5 => [ livia:4 ]
$remove livia
$show
=> mario:5 => [ ]
$end
```

```bash
#__case 2
$show
=> => [ ]
$arrive mario 5
$show
=> mario:5 => [ ]
#__case empty enter
$enter
$show
=> => [ mario:5 ]
#__case empty leave
$leave
$show
=> mario:5 => [ ]
$leave
$show
=> mario:5 => [ ]
#__case remove from waiting
$remove mario
$show
=> => [ ]
#__case remove empty
$remove rebeca
$show
=> => [ ]
$end
```
