# Comprando uma chinela 40/41

<!-- toch -->
[Intro](#intro) | [Guide](#guide)
-- | --
<!-- toch -->

![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/chinela/cover.jpg)

## Intro

- Vamos implementar uma classe que controla os possíveis valores de calçados para uma chinela.
- As regras de validação de valores são as seguintes.
- Uma chinela tem um valor tamanho que é um número par entre 20 e 50, incluindo 20 e 50.
- Faça o objeto chinela iniciar com tamanho 0 e controle através do método setTamanho que apenas valores válidos de tamanho sejam atribuídos.
- Por fim, crie um loop no qual um objeto chinela é criado e é perguntado ao usuário qual seu tamanho de chinela.
- Mantenha o usuário preso no loop até que ele insira um valor válido.
- Caso ele digite um valor inválido, avise e dê uma mensagem de erro adequada.

## Guide

[![youtube icon](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/animal/../youguide.png)](https://youtu.be/pC3DMuHVFHE?si=XIylk3z3zABCD0hj)


```py

class Chinela:
    # inicialização da chinela com valor de tamanho 0
    def __init__(self):    # isso é o construtor em python
        self.__tamanho = 0 # quando tem __ na frente em python é privado

    def getTamanho(self): # métodos em python tem self como primeiro atributo
        return self.__tamanho

    def setTamanho(self, valor: int):
        # implementar os testes de valor e disparar os avisos caso necessário

# loop principal
chinela = Chinela() # criando chinela com valor tamanho padrão

while chinela.getTamanho() == 0: # mantendo usuário no loop
    print("Digite seu tamanho de chinela")
    tamanho = int(input()) # lendo a resposta e convertendo pra inteiro
    chinela.setTamanho(tamanho) # tentando atribuir e disparando 

print("Parabens, você comprou uma chinela tamanho", chinela.getTamanho())
```
