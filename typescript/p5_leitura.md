# P5 revisão

<!-- toc -->
- [Instalação](#instalação)
- [Relembrando o P5](#relembrando-o-p5)
- [Funções úteis](#funções-úteis)
<!-- toc -->

## Instalação

## Relembrando o P5

- Você pode acessar o [editor online](https://editor.p5js.org/) para testar o p5.js
- E ver a [documentação](https://p5js.org/reference/)
- Esteja atento que o mesmo nome de função pode ser utilizado com diferentes parâmetros, seja no tipo ou na quantidade.

As funções principais que você precisa conhecer são:

- `setup()`: é executada uma vez no início do programa
- `draw()`: é executada a cada frame

As funções disparadas por eventos são:

- `mousePressed()`: é executada quando o mouse é pressionado
- `keyPressed()`: é executada quando uma tecla é pressionada
- `keyReleased()`: é executada quando uma tecla é solta
- e muitas outras...

As variáveis principais que você precisa conhecer são:

- `mouseX`: posição x do mouse
- `mouseY`: posição y do mouse
- `key`: tecla pressionada
- `keyCode`: código da tecla pressionada
- `width`: largura do canvas
- `height`: altura do canvas
- `frameCount`: número do frame atual

O p5.js oferece uma variedade de funções de desenho que permitem criar formas, linhas, texto e manipular cores. Aqui estão algumas das principais funções de desenho do p5.js:

1. **createCanvas(width, height)**: Essa função cria um canvas (área de desenho) com as dimensões especificadas.

2. **background(r, g, b)**: Define a cor de fundo do canvas usando valores RGB.

3. **fill(r, g, b)**: Define a cor de preenchimento para formas desenhadas subsequentemente usando valores RGB.

4. **stroke(r, g, b)**: Define a cor da linha para formas desenhadas subsequentemente usando valores RGB.

5. **strokeWeight(weight)**: Define a espessura das linhas para formas desenhadas subsequentemente.

6. **noFill()**: Desativa o preenchimento das formas desenhadas subsequentemente.

7. **noStroke()**: Desativa a linha de contorno das formas desenhadas subsequentemente.

8. **point(x, y)**: Desenha um ponto nas coordenadas especificadas.

9. **line(x1, y1, x2, y2)**: Desenha uma linha de (x1, y1) para (x2, y2).

10. **rect(x, y, width, height)**: Desenha um retângulo na posição (x, y) com a largura e altura especificadas.

11. **ellipse(x, y, width, height)**: Desenha uma elipse ou um círculo na posição (x, y) com as dimensões especificadas.

12. **arc(x, y, width, height, startAngle, endAngle)**: Desenha um arco ou parte de um círculo.

13. **triangle(x1, y1, x2, y2, x3, y3)**: Desenha um triângulo com vértices nas coordenadas especificadas.

14. **text(text, x, y)**: Desenha um texto na posição (x, y).

15. **textAlign(alignH, alignV)**: Define o alinhamento horizontal (LEFT, CENTER, RIGHT) e vertical (TOP, CENTER, BOTTOM) para o texto.

16. **textSize(size)**: Define o tamanho do texto.

Essas são apenas algumas das funções de desenho disponíveis no p5.js. A biblioteca oferece muito mais recursos e possibilidades para criar arte, animações e interações visuais. A documentação oficial do p5.js é uma excelente referência para aprender sobre todas as funções e suas opções.

## Funções úteis

O random sempre gera valores aleatório [min, max[, ou seja, inclui o min e exclui o max.

- `random(min, max)`: retorna um número aleatório entre min e max
- `random(max)`: retorna um número aleatório entre 0 e max
- `random()`: retorna um número aleatório entre 0 e 1

Cores podem ser passadas como:

- texto: `fill("red")`, `stroke("blue")`
- rgb: `fill(255, 0, 0)`, `stroke(0, 0, 255)`
- cinza: `fill(255)`, `stroke(0)`
- rgba: `fill(255, 0, 0, 100)`, `stroke(0, 0, 255, 100)`
- hex: `fill("#ff0000")`, `stroke("#0000ff")`
- objetos color: `fill(color(255, 0, 0))`, `stroke(color(0, 0, 255))`
