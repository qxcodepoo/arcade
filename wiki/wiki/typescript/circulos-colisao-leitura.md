# Leitura

<!-- toc -->
- [Explicação](#explicação)
- [O código final](#o-código-final)
- [O resultado em vídeo](#o-resultado-em-vídeo)
<!-- toc -->

## Explicação

Vamos continuar o projeto das classes aninhadas. Se você ainda não leu, reveja explicação da atividade [desenho](vector2d_leitura.md) para entender melhor os detalhes da classe `Vector2d` e da classe `Circle`.

```ts
class V2d {
    x: number;
    y: number;
    constructor(x: number, y: number) {
        this.x = x;
        this.y = y;
    }

    dist(other: V2d): number {
        return dist(this.x, this.y, other.x, other.y);
    }

    toString(): string {
        return `${this.x}:${this.y}`
    }
}

class Circulo {
    center: V2d;
    radius: number;
    constructor(x: number, y: number, r: number) {
        this.center = new V2d(x, y);
        this.radius = r;
    }
    desenhar(): void {
        circle(this.center.x, this.center.y, this.radius * 2);
    }
    contemPonto(ponto: V2d): boolean {
        return this.center.dist(ponto) < this.radius;
    }
    colideCirculo(other: Circulo): boolean {
        return this.center.dist(other.center) < this.radius + other.radius;
    }
    colideLista(lista: Circulo[]): boolean {
        for (let elem of lista) {
            if (this !== elem && this.colideCirculo(elem)) {
                return true;
            }
        }
        return false;
    }

    toString(): string {
        return `${this.center.x}:${this.center.y}:${this.radius}`
    }
}

let vet: Circulo[] = [new Circulo(100, 100, 50)];
let colorir: boolean = false;
let aumentar: boolean = false;

function setup() {
    createCanvas(300, 600);
    frameRate(10);
}
function draw() {
    background(100);
    for (let elem of vet) {
        if (colorir) {
            fill(random(255), random(255), random(255))
        }
        elem.desenhar();
    }
    if (aumentar) {
        for (let elem of vet) {
            if (elem.colideLista(vet))
                elem.radius -= 1;
            else
                elem.radius += 1;
        }
    }
}

function mousePressed() {
    vet.push(new Circulo(mouseX, mouseY, 50));
}

function keyPressed() {
    if (key == "c") {
        colorir = !colorir;
    }
    if (key == "a") {
        aumentar = !aumentar;
    }
}
```

Esse código tem algumas novidades:

- Os mecanismos de `toggle` ou alternadores. Eles ligam e desligam comportamentos da nossa simulação.

```ts

// criando os controles
// global
let colorir: boolean = false;
let aumentar: boolean = false;

// ligando e desligando
// global
function keyPressed() {
    if (key == "c") {
        colorir = !colorir;
    }
    if (key == "a") {
        aumentar = !aumentar;
    }
}

// aplicando
function draw() {
    ...
    if (colorir) {
        fill(random(255), random(255), random(255))
    }
    ...
}
```

Outra técnica nova são os laços. Utilizamos laços para percorrer a lista de círculos para pintá-los.

```ts
function draw() {
    ...
    for (let elem of vet) {
        if (colorir) {
            fill(random(255), random(255), random(255))
        }
        elem.desenhar();
    }
    ...
}
```

Utilizamos laço para percorrer a lista de círculos para procurar se tem algum outro círculo colidindo com ele.

```ts
    
class Circle {
    ...
    colideLista(lista: Circulo[]): boolean {
        for (let elem of lista) {
            if (this !== elem && this.colideCirculo(elem)) {
                return true;
            }
        }
        return false;
    }
    ...
}
```

Usamos o laço para verificar para cada círculo, se ele está colidindo com algum outro da lista.

```ts
function draw() {
    ...
    for (let elem of vet) {
        if (elem.colideLista(vet))
            elem.radius -= 1; //que tal só diminuir se for maior que 1??
        else
            elem.radius += 1;
    }
    ...
}
```

## O código final



## O resultado em vídeo

[resultado](https://user-images.githubusercontent.com/4747652/266102022-e62d1519-9651-4435-8be6-0525a7b7fac7.mp4)
