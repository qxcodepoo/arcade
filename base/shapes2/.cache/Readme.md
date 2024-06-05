# @shapes2 - Utilizando interface em círculos e retângulos

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/shapes2/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo shapes2`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell)
-- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/shapes2/cover.jpg)

## Intro

O objetivo desta atividade é implementar um sistema para gerenciar formas geométricas. Você precisará criar classes para representar pontos, círculos e retângulos, além de uma classe de controle chamada `Adapter` que gerenciará essas formas. O sistema permitirá adicionar formas e obter informações sobre elas.

- **Descrição**
  - A interface `Shape` define métodos que todas as formas geométricas devem implementar.
  - A classe `Point2D` representa um ponto no plano bidimensional.
  - As classes `Circle` e `Rectangle` implementam a interface `Shape` e representam um círculo e um retângulo, respectivamente.
  - A classe `Adapter` serve como uma classe de controle, gerenciando a criação e manipulação das formas geométricas.

### Interface Shape

A interface `Shape` exige a implementação dos seguintes métodos (os métodos abaixo não são implementadas na classe Shape, apenas nas classes filhas):

- `getArea()`: Retorna a área da forma.
- `getPerimeter()`: Retorna o perímetro da forma.
- `getName()`: Retorna o nome da forma.

### Classe Point2D

A classe `Point2D` representa um ponto no plano bidimensional e possui:

- **Atributos:**
  - `x`: coordenada x do ponto.
  - `y`: coordenada y do ponto.
- **Métodos:**
  - `constructor(x: number, y: number)`: Inicializa os atributos x e y.
  - `toString()`: Retorna a representação do ponto no formato `(x, y)`. Exemplo: `(0.00, 0.00)`.

### Classe Circle

A classe `Circle` implementa a interface `Shape` e representa um círculo. Deve incluir:

- **Atributos:**
  - `name`: Nome da forma, que é "Circ".
  - `center`: Centro do círculo, representado por um `Point2D`.
  - `radius`: Raio do círculo.
- **Métodos:**
  - `constructor(center: Point2D, radius: number)`: Inicializa os atributos center e radius.
  - `getName()`: Retorna o nome "Circ".
  - `getArea()`: Calcula e retorna a área do círculo usando a fórmula `π * raio²`.
  - `getPerimeter()`: Calcula e retorna o perímetro do círculo usando a fórmula `2 * π * raio`.
  - `toString()`: Retorna uma string no formato `Circ: C=(x, y), R=radius`.

### Classe Rectangle

A classe `Rectangle` também implementa a interface `Shape` e representa um retângulo. Deve incluir:

- **Atributos:**
  - `name`: Nome da forma, que é "Rect".
  - `p1`: Um vértice do retângulo (ponto superior esquerdo), representado por um `Point2D`.
  - `p2`: O vértice oposto do retângulo (ponto inferior direto), representado por um `Point2D`.
- **Métodos:**
  - `constructor(p1: Point2D, p2: Point2D)`: Inicializa os atributos p1 e p2.
  - `getName()`: Retorna o nome "Rect".
  - `getArea()`: Calcula e retorna a área do retângulo usando a fórmula `largura * altura`.
    - `largura` é a diferença absoluta entre `x` de `p1` e `p2`.
    - `altura` é a diferença absoluta entre `y` de `p1` e `p2`.
  - `getPerimeter()`: Calcula e retorna o perímetro do retângulo usando a fórmula `2 * (largura + altura)`.
  - `toString()`: Retorna uma string no formato "Rect: P1=(x1, y1) P2=(x2, y2)".

### Classe de Controle Adapter

A classe `Adapter` serve como uma classe de controle para gerenciar as formas geométricas. Deve incluir:

- **Atributos:**
  - `shapes`: Array para armazenar as formas.
- **Métodos:**
  - `constructor()`: Inicializa o array `shapes`.
  - `circle(x: number, y: number, r: number)`: Cria um novo círculo com centro em `(x, y)` e raio `r`, adicionando-o ao array `shapes`.
  - `rectangle(x1: number, y1: number, x2: number, y2: number)`: Cria um novo retângulo com os vértices `(x1, y1)` e `(x2, y2)`, adicionando-o ao array `shapes`.
  - `info()`: Retorna uma string com informações sobre todas as formas no array `shapes`, incluindo nome, área e perímetro.
  - `toString()`: Retorna uma string com a representação de todas as formas no array `shapes`.

A implementação desta atividade exige que você siga rigorosamente as instruções para garantir a correta funcionalidade e integridade do sistema de gerenciamento de formas geométricas.

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/shapes2/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts

class Point2D {
    + x: double
    + y: double
    
    + Point2D(x: double, y: double)

    ' gera uma string no formato
    ' (0.00, 0.00)
    + toString(): string
}

class Calc {
    ' método estático para calcular a distância entre dois pontos
    + {static} distance(a: Point2D, b: Point2D): double
}

interface Shape {
    ' getName(): string
    + getName(): string

    ' os métodos abaixo não são implementadas
    ' na classe Shape, apenas nas classes filhas

    ' retorna se o ponto está dentro da forma
    + inside(Point2D: point): boolean

    ' retorna a área da forma
    + getArea(): double

    ' retorna o perímetro da forma
    + getPerimeter(): double
}

class Circle {
    + center: Point2D
    + radius: double

    __
    ' invoca o construtor da superclasse
    ' passando o nome Circ
    ' guarda os outros valores nos atributos
    ' da classe Circle
    + Circle(center: Point2D, radius: double)

    ' implementa os métodos abstratos
    + inside(point: Point2D): boolean
    + getArea(): double
    + getPerimeter(): double

    ' retorna o nome da classe e os valores no seguinte formato
    ' Circ: C=(0.00, 0.00), R=0.00
    ' O ponto deve ser gerado pelo método toString da classe Point2D
    + toString(): string
}

class Rectangle {
    ' ponto superior esquerdo
    + P1: Point2D
    ' ponto inferior direito
    + P2: Point2D

    __
    ' invoca o construtor da superclasse
    ' passando o nome Rect
    ' inicializa o resto dos atributos
    + Rectangle(P1: Point2D, P2: Point2D)

    ' implementa os métodos abstratos
    + inside(point: Point2D): boolean
    + getArea(): double
    + getPerimeter(): double

    ' retorna o nome da classe e os valores no seguinte formato
    ' Rect: P1=(0.00, 0.00) P2=(0.00, 0.00)
    + toString(): string
}

```

<!-- load -->

## Shell

```sh
#__case creating figures
$circle 2 3 5

#__case showing
$show
Circ: C=(2.00, 3.00), R=5.00

#__case creating more figures
$rect 1 1 3 3
$rect 2 4.53 5 10
$circle 1 1 1.5

#__case showing all
$show
Circ: C=(2.00, 3.00), R=5.00
Rect: P1=(1.00, 1.00) P2=(3.00, 3.00)
Rect: P1=(2.00, 4.53) P2=(5.00, 10.00)
Circ: C=(1.00, 1.00), R=1.50


#__case showing area and perimeter
$info
Circ: A=78.54 P=31.42
Rect: A=4.00 P=8.00
Rect: A=16.41 P=16.94
Circ: A=7.07 P=9.42

$end
```
