# [GUIA] Toalha, o item mais útil do universo

<!-- toc-table -->
[Intro](#intro) | [Regras](#regras) | [Guide](#guide)
-- | -- | --
<!-- toc-table -->

![_](assets/cover.webp)

## Intro

O objetivo dessa atividade é implementar uma toalha que possa absorver água, ser torcida e informar seu estado.

## Regras

- A classe Toalha `Towel` possui os atributos cor `color`, tamanho `size` e umidade `wetness`.
- O construtor recebe a cor e o tamanho e inicia `wetness` com `0`.
- O método enxugar `dry` recebe uma quantidade inteira `amount` e aumenta `wetness` sem ultrapassar o limite.
- O método torcer `wringOut` zera `wetness`.
- O método `getMaxWetness` retorna o limite de umidade conforme o tamanho:
  - `P` -> `10`
  - `M` -> `20`
  - `G` -> `30`
- O método `isDry` retorna `true` quando `wetness` é `0` e `false` caso contrário.
- A classe `Towel` não deve ler entrada nem imprimir dados.
- Crie um código de teste para validar o comportamento da classe.

![diagrama](assets/diagrama.png)

## Guide

[![youtube icon](assets/youguide.webp)](https://youtu.be/fEvJns4NpTM?si=G-FDqGnt_5SPSZpg)

<!-- load src/py/solver.py --fenced -->
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

    def dry(self, amount: int) -> bool:
        self.wetness += amount
        if self.wetness > self.getMaxWetness():
            self.wetness = self.getMaxWetness()
            return False # não conseguiu enxugar tudo
        return True
    
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
if not towel.dry(5): # msg: toalha encharcada
    print("toalha encharcada")
towel.show()  # Azul P 10

towel.wringOut()
towel.show()  # Azul P 0

towel = Towel("Verde", "G")
print(towel.isDry()) # True
towel.dry(30)
towel.show()  # Verde G 30
print(towel.isDry()) # False
if not towel.dry(1):  # msg: toalha encharcada
    print("toalha encharcada")
```
<!-- load -->

Implemente e teste a classe em partes: estado inicial, absorção, limite de umidade, torção e consulta de estado.
