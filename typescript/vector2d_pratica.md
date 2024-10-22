# Prática - Classes Aninhadas

Crie uma class Retangulo que representa um retângulo na tela. Essa classe deve ter os seguintes atributos:

- `posicao`: um objeto do tipo `Vector2d` que representa a posição do retângulo na tela.
- `tamanho`: um objeto do tipo `Vector2d` que representa o tamanho do retângulo na tela.

A classe `Retangulo` deve ter os seguintes métodos:

- `constructor(x: number, y: number, width: number, height: number)`: inicializa os atributos `posicao` e `tamanho
- `contemPonto(ponto: Vector2d)`: retorna `true` se o ponto passado como parâmetro estiver dentro do retângulo e `false` caso contrário.
- `desenhar()`: desenha o retângulo na tela.

- No seu programa, crie um retângulo na posição (100, 100) e com tamanho (50, 50).
- Desenhe o retângulo na tela.
- Sempre que clicar com o mouse, mude a posição do retângulo para a posição do clique.
- Sempre que o mouse estiver dentro do retângulo, mude a cor do retângulo para vermelho e diminua o tamanho em x e y em 1 pixel.
- Sempre que o mouse estiver fora do retângulo, mude a cor do retângulo para azul e aumente o tamanho em x e y em 1 pixel.

## Resultado Esperado

[resultado](https://user-images.githubusercontent.com/4747652/266047852-5d58bcef-fc82-49da-b887-b62f535e5e90.mp4)
