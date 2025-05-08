# Toalha, o item mais útil do universo

<!-- toch -->
[Intro](#intro) | [Guide](#guide)
-- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/toalha/cover.jpg)

## Intro

- Crie uma classe Toalha `Towel` com os atributos cor `color`, tamanho `size` e umidade `wetness`.
- Crie um construtor que inicialize todos os atributos cor e tamanho com valores recebidos como parâmetro e umidade com 0.
- Crie um método enxugar `dry` que recebe um valor inteiro quantidade `amout` e AUMENTA o atributo umidade da toalha.
- Crie um método torcer `wringOut` que zera o atributo umidade da towel.
- Crie um método para pegar máximo de umidade `getMaxWetness` que retorna o valor máximo de umidade que essa toalha pode ter.
- O máximo de umidade que uma toalha pode ter é de acordo com o tamanho dela:
  - `P` -> 10
  - `M` -> 20
  - `G` -> 30
- Crie um método que retorna se a toalha esta seca `isDry`, que retorna `true` se a umidade da toalha for 0 e `false` caso contrário.
- Faça um código de teste para validar o comportamento da classe Toalha.

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/toalha/diagrama.png)

## Guide

[![youtube icon](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/toalha/../youguide.png)](https://youtu.be/fEvJns4NpTM?si=G-FDqGnt_5SPSZpg)

- Abaixo você tem um exemplo de código em python que implementa a classe `Towel` e testa seu comportamento.
- Adapte a ideia para a linguagem que você está estudando e crie seus próprios testes.

<!-- load solver.py fenced:filter:py -->

```py
class Towel:
    def __init__(self, color: str, size: str):
        self.color: str = color
        self.size: str = size
        self.wetness: int = 0
    
    def getMaxWetness(self) -> int:
        if self.size == "P":
            return 10
        if self.size == "M":
            return 20
        if self.size == "G":
            return 30
        return 0

    def dry(self, amount: int) -> None:
        self.wetness += amount
        if self.wetness > self.getMaxWetness():
            print("toalha encharcada")
            self.wetness = self.getMaxWetness()
    
    def wringOut(self) -> None:
        self.wetness = 0
    
    def isDry(self) -> bool:
        return self.wetness == 0


    def show(self) -> None:
        print(self)

    def __str__(self) -> str:
        return f"{self.color} {self.size} {self.wetness}"

# Testes
towel = Towel("Azul", "P")
towel.show()  # Azul P 0
towel.dry(5)
towel.show()  # Azul P 5
print(towel.isDry()) # False
towel.dry(5)
towel.show()  # Azul P 10
towel.dry(5) # msg: toalha encharcada
towel.show()  # Azul P 10

towel.wringOut()
towel.show()  # Azul P 0

towel = Towel("Verde", "G")
print(towel.isDry()) # True
towel.dry(30)
towel.show()  # Verde G 30
print(towel.isDry()) # False
towel.dry(1)  # msg: toalha encharcada

```

<!-- load -->
