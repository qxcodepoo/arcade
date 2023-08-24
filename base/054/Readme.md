# Animal

![_](cover.jpg)

<!-- toc -->
- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
<!-- toc -->

O objetivo dessa atividade é implementar um animal que passa pelas diversas fases de crescimento até a morte.

***

## Intro

- Criar um animal passando por parâmetro a espécie e o barulho que ele faz.
- Invocar o método para que o animal faça barulho.
- Envelhecer o animal que vai passar por 4 estágios:
  - 0: bebe. Muito pequeno, não faz barulho `---`.
  - 1: criança. Faz barulho normal.
  - 2: adulto. Faz barulho normal.
  - 3: idoso. Faz barulho normal.
  - 4: morto. Não faz mais barulho `RIP`.

***

## Guide

- [Solver.java](.cache/draft.java)
- [solver.cpp](.cache/draft.cpp )
- [solver.ts](.cache/draft.ts )

- [cases.tio](cases.tio)

![_](diagrama.png)

***

## Shell

```bash
#__case iniciando
# O comando "$init _especie _barulho" cria uma animal bebe dessa especie
# O comando "$show" mostra, sem manipulação, os atributos especie:estagio:barulho
$init gato miau
$show
gato:0:miau

$init cachorro auau
$show
cachorro:0:auau

$init galinha cocorico
$show
galinha:0:cocorico

$end
```

```bash
# O comando grow _valor envelhece o animal em _valor etapas
#__case envelhecendo
$init vaca muu
$show
vaca:0:muu

$grow 2
$show
vaca:2:muu

$grow 2
warning: vaca morreu

$show
vaca:4:muu

$grow 3
warning: vaca morreu

$show
vaca:4:muu

$end
```

```bash
# O comando noise faz o animal fazer barulho, se ele estiver vivo e não for bebe
#__case fazer barulho
$init cabra beeh

$noise
---

$grow 1
$noise
beeh
$grow 3
warning: cabra morreu

$noise
RIP

$end
```

```bash
#__case extra
$init passaro piupiu

$show
passaro:0:piupiu

$noise
---

$grow 1
$noise
piupiu

$grow 2
$noise
piupiu

$grow 1
warning: passaro morreu

$noise
RIP

$end
```
