# Leitura - Classes Aninhadas

## Resultado Final

[Video demonstration](https://user-images.githubusercontent.com/4747652/266043291-ebbc8b47-2d46-4c3a-adc9-29d2c04a4250.mp4)

## Introdução

A criação de classes aninhadas é uma técnica que permite a criação de classes dentro de outras classes. Essa técnica é muito utilizada para criar classes que representam estruturas de dados complexas.

Por exemplo, a class `Vector2d` representa um vetor bidimensional. Esse vetor pode ser utilizado para representar uma posição no espaço, uma velocidade, uma aceleração, uma força, etc.

## Vector2d

```typescript
class Vector2d {
  x: number;
  y: number;
  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  } 
}
```

O construtor da classe `Vector2d` recebe dois parâmetros, `x` e `y`, que são utilizados para inicializar os atributos `x` e `y` da classe.

A classe `Vector2d` pode ser utilizada para representar uma posição no espaço, como no exemplo abaixo:

```typescript
let center: Vector2d = new Vector2d(10, 20);
```

Podemos utilizar a classe `Vector2d` para guardar a última posição do clique do mouse:

```typescript

//variavel global
let clique: Vector2d = new Vector2d(0, 0); //criando e inicializando

function draw() {
    background(0);
    fill(255);
    circle(clique.x, clique.y, 50);
}

function mouseClicked() {
  clique.x = mouseX;
  clique.y = mouseY;
}
```

## Circle

Uma classe `Circle` pode ser criada para representar um círculo. Essa classe pode ser utilizada para representar um círculo na tela, como no exemplo abaixo:

```typescript
class Circle {
  center: Vector2d;
  radius: number;

  constructor(x: number, y: number, radius: number) {
    this.center = new Vector2d(x, y);
    this.radius = radius;
  }

  draw() {
    circle(this.center.x, this.center.y, this.radius * 2);
  }
}
```

O objeto `center` pode ser inicializado da seguinte forma:

```typescript

//variavel global
let circulo: Circle = new Circle(100, 100, 50);
```

O objeto `circulo` é do tipo `Circle` e o atributo `center` é do tipo `Vector2d`. O objeto `circulo` pode ser utilizado para desenhar um círculo na tela, como no exemplo abaixo:

```typescript
function draw() {
    background(0);
    fill(255);
    circulo.draw();
}
```

Atualizar a posição do círculo através do clique do mouse pode ser feito da seguinte forma:

```typescript
function mouseClicked() {
  circulo.center.x = mouseX;
  circulo.center.y = mouseY;
}
```

Observe os desempacotamentos de atributos que ocorrem no código acima. O atributo `center` do objeto `circulo` é do tipo `Vector2d` e o atributo `x` do objeto `center` é do tipo `number`. O código acima poderia ainda ser reescrito da seguinte forma:

```typescript
function mouseClicked() {
  circulo.center = new Vector2d(mouseX, mouseY);
}
```

Aqui, estamos substituindo o objeto `center` por um novo objeto `Vector2d` criado a partir das coordenadas do mouse.

Para verificar se o mouse está dentro do círculo, podemos utilizar o método `dist` da do p5.

```typescript
function draw() {
    background(0);
    fill(255);
    circulo.draw();
    if (dist(mouseX, mouseY, circulo.center.x, circulo.center.y) < circulo.radius) {
      fill(255, 0, 0);
    }
    circle(mouseX, mouseY, 10);
}
```

Como a função `dist` está relacionada com a classe Vector2d, podemos criar um método `dist` na classe `Vector2d`:

```typescript
class Vector2d {
  x: number;
  y: number;

  constructor(x: number, y: number) {
    this.x = x;
    this.y = y;
  } 

  dist(other: Vector2d) {
    return dist(this.x, this.y, other.x, other.y);
  }
}
```

Outra manipulação interessantes seria criar um método booleano que retorna verdade se um ponto está dentro do círculo.

```typescript
class Circle {
  center: Vector2d;
  radius: number;

  constructor(x: number, y: number, radius: number) {
    this.center = new Vector2d(x, y);
    this.radius = radius;
  }

  draw(): void {
    circle(this.center.x, this.center.y, this.radius * 2);
  }

  contains(ponto: Vector2d): boolean {
    return this.center.dist(ponto) < this.radius;
  }
}
```

O método `contains` retorna verdade se o ponto passado como parâmetro está dentro do círculo. Esse método pode ser utilizado para verificar se o mouse está dentro do círculo:

```typescript
function draw() {
    background(0);
    fill(255);
    circulo.draw();
    if (circulo.contains(new Vector2d(mouseX, mouseY))) {
      fill("red");
    } else {
      fill("blue");
    }
    circle(mouseX, mouseY, 10);
}
```
