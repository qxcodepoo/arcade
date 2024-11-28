# Toalha, o item mais útil do universo

- Crie uma classe `Toalha` com os atributos `cor`, `tamanho` e `umidade`.
- Crie um construtor que inicialize todos os atributos `cor` e `tamanho` com valores recebidos como parâmetro e `umidade` com 0.
- Crie um método `enxugar` que recebe um valor inteiro `umidade` e aumenta o atributo `umidade` da toalha.
- Crie um método `torcer` que zera o atributo `umidade` da toalha.
- Crie um método `pegarMaximoUmidade` que retorna o valor máximo de umidade que essa toalha pode ter.
- O máximo de umidade que uma toalha pode ter é de acordo com o tamanho dela:
  - `P` -> 10
  - `M` -> 20
  - `G` -> 30
- Crie um método `estaSeca` que retorna `true` se a umidade da toalha for 0 e `false` caso contrário.
- Faça um código de teste para validar o comportamento da classe `Toalha`.

## Exemplo

<!-- load solver.py fenced:filter:py -->

```py
class Toalha:
    def __init__(self, cor: str, tamanho: str):
    def getMaxUmidade(self) -> int:
    def enxugar(self, quantidade: int) -> None:
    def torcer(self) -> None:
    def estaSeca(self) -> bool:
    def __str__(self) -> str:
    def mostrar(self) -> None:
# Testes
toalha = Toalha("Azul", "P")
toalha.mostrar()  # Azul P 0
toalha.enxugar(5)
toalha.mostrar()  # Azul P 5
toalha.estaSeca() # False
toalha.enxugar(5)
toalha.mostrar()  # Azul P 10
toalha.enxugar(5) # msg: toalha encharcada
toalha.mostrar()  # Azul P 10

toalha.torcer()
toalha.mostrar()  # Azul P 0

toalha = Toalha("Verde", "G")
toalha.estaSeca() # True
toalha.enxugar(30)
toalha.mostrar()  # Verde G 30
toalha.estaSeca() # False
toalha.enxugar(1)  # msg: toalha encharcada
```

<!-- load -->
