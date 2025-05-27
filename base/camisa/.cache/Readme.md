# Comprando uma camisa XG

<!-- toch -->
[Intro](#intro) | [Guide](#guide)
-- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/camisa/cover.jpg)

## Intro

- Vamos implementar uma classe que controla os possíveis valores de tamanho para uma roupa.
- Os tamanhos serão identificados como uma variável tipo texto, e os valores válidos são "PP", "P", "M" e "G", "GG" e "XG".
- Faça o objeto roupa iniciar o tamanho como uma string vazia, para expressar que nenhum tamanho foi atribuído.
- Crie o método setTamanho que apenas aceita os valores válidos de tamanho.
- Caso o valor seja inválido, avise e dê uma mensagem de erro informando quais os valores permitidos.
- Faça um código de teste iniciando uma roupa com tamanho vazio e pedindo para o usuário informar o tamanho da roupa.
- Mantenha o usuário preso no loop até que ele insira um valor válido.

## Guide

[![youtube icon](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/animal/../youguide.png)](https://youtu.be/tvQgaO2j7I8?si=IOcNHNKJio03sep_)

Aqui um exemplo de código python incompleto que implementa a classe Camisa e um loop para pedir o tamanho da camisa ao usuário.

```py

class Camisa:
    def __init__(self): # isso é o construtor em python
        self.__tamanho: str = "" # atributos em python com __ na frente são privados

    def getTamanho(self) -> str: # métodos em python tem self como primeiro atributo
        return self.__tamanho

    def setTamanho(self, valor: str):
        # implementar os testes de valor e disparar os avisos caso necessário

# loop principal
roupa = Roupa() # criando roupa com valor tamanho padrão

while roupa.getTamanho() == "": # mantendo usuário no loop
    print("Digite seu tamanho de roupa")
    tamanho = input() # lendo a resposta
    roupa.setTamanho(tamanho) # tentando atribuir e disparando erros

print("Parabens, você comprou uma roupa tamanho", roupa.getTamanho())
```
