## @047 Shapes

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/047/cover.jpg)

[](toc)

- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
[](toc)

Faça um programa para gerenciar figuras geométricas. Devemos conseeguir obter a área e o perímetro de cada figura. Também devemos conseguir checar se um ponto está dentro de uma figura.

## Intro

As figuras geométricas podem ser círculos ou retângulos.

O retângulo é definido por dois pontos: o ponto inferior esquerdo e o ponto superior direito.

O círculo pode ser definido pelo ponto do centro e pelo raio.

## Guide

- [solver.cpp](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/047/.cache/draft.cpp)

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/047/diagrama.png)

[](load)[](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/047/diagrama.puml)[](fenced:filter:plantuml)

## Shell

```sh
circle 2 3 5
$circle 2 3 5
rect 1 1 3 3 
$rect 1 1 3 3 
show
$show
Circle: (2.00, 3.00), R=5.00, Area=78.50, Perimetro=31.40
Rectangle: (1.00, 1.00) (3.00, 3.00), Area=4.00, Perimetro=8.00
end
$end
```