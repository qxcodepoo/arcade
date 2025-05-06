# Comendo estrelas

## Parte 1 - Criando as estrelas

Crie a class V2d que representa um vetor bidimensional. Essa classe deve ter os seguintes atributos e métodos:

```ts
class V2d {
    x: number;
    y: number;

    constructor(x: number, y: number) {
        ...
    }
    dist(other: V2d): number {
        // retorna a distância entre o vetor atual e o vetor other
    }
    draw() {
        // fazer um círculo de raio 10 no canvas
    }
    clone(): V2d {
        // retorna um novo V2d com os mesmos valores de x e y
    }
    toString(): string {
        // retorna uma string no formato "(x, y)"
    }
}
```

- Crie as variáveis globais `largura` e `altura` que representam a largura e altura do canvas.
- Crie como variável global a variável `pontos` como um vetor de pontos.
- Na função `setup`
  - crie o canvas com `largura` e `altura`.
  - crie 200 pontos aleatórios e coloque-os no vetor `pontos`.
- Na função `draw`
  - limpe a tela de cinza. `background(100)`
  - desenhe todos os pontos do vetor `pontos` com cor `branca`.
- Esse deve ser o resultado

![image](https://user-images.githubusercontent.com/4747652/268647667-ee7086df-4d79-4536-ad0f-1c4708982c69.png)

## Parte 2 - Movendo o personagem

- crie a classe Circle que representa um círculo. Essa classe deve ter os seguintes atributos e métodos:

```ts
class Circle {
    center: V2d;
    radius: number;

    constructor(center: V2d, radius: number) {
        ...
    }
    draw() {
        // desenha o círculo no canvas
    }
    contains(point: V2d): boolean {
        // retorna true se o ponto estiver dentro do círculo
    }
    toString(): string {
        // retorna uma string no formato "Circle(center, radius)"
    }
}
```

- Como variável global crie a variável `personagem`, que é o círculo que representa o personagem e inicie o personagem no meio do canvas.
- Na função `draw`
  - desenhe o personagem com cor `verde`.
  - utilize a função `keyIsDown` para movimentar o personagem com as teclas `w`, `a`, `s` e `d` ou com as setas do teclado.

[link](https://user-images.githubusercontent.com/4747652/268650285-5674fdd6-bfc5-42cd-be8b-be6cf96be47c.mp4)

## Parte 3 - Marcando estrelas

- Pinte de vermelho todos os pontos que estão dentro do círculo do personagem.
- Crie na função `keyPressed` uma tecla para aumentar e outra para diminuir o raio do personagem.

[link](https://user-images.githubusercontent.com/4747652/268651971-b6d0a4cf-7a05-4e80-b171-19d94ebe9c34.mp4)

## Parte 4 - Contando Estrelas

- Onde achar mais fácil, crie a função `contaEstrelas` que recebe um círculo e retorna a quantidade de estrelas que estão dentro do círculo.
- Utilize a função `text(texto, x, y)` para imprimir dentro do personagem a quantidade de estrelas que ele está cobrindo.

[link](https://user-images.githubusercontent.com/4747652/268653437-2a8a3ec0-77bb-414e-adbf-3040fcc4b43c.mp4)

## Parte 5 - Comendo estrelas

- Crie a função `comeEstrelas` que recebe um círculo e remove do vetor `pontos` todas as estrelas que estão dentro do círculo. Dica, utilize a função `filter` para filtrar os pontos que não estão dentro do círculo e atualize o vetor `pontos` com o resultado.
- Crie uma entrada na função `keyPressed` para comer as estrelas com a tecla `c`.

[LINK](https://user-images.githubusercontent.com/4747652/268654548-12b26527-1eb3-4be0-84e3-e55bf7620428.mp4)

## Parte desafio

Permita que o personagem ande pelo cenário, mas o impeça de andar ou crescer a ponto de ter mais de 10 estrelas dentro do círculo.

[LINK](https://user-images.githubusercontent.com/4747652/268656415-54f78b11-cf80-4575-9de0-ee5460b4c73f.mp4)
