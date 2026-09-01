# [GUIA] Comprando uma camisa XG

<!-- toc-table -->

![_](assets/cover.webp)

## Intro

O objetivo dessa atividade é implementar uma classe que controle o tamanho válido de uma camisa.

Nesta atividade você vai praticar **encapsulamento** com o atributo privado `size`, um getter para consulta e um setter validador. O setter deve preservar a **invariante** de que o tamanho pertence ao conjunto permitido.

## Regras

- Os tamanhos serão identificados como uma variável tipo texto, e os valores válidos são "PP", "P", "M" e "G", "GG" e "XG".
- Faça o objeto `Shirt` iniciar `size` como uma string vazia, para expressar que nenhum tamanho foi atribuído.
- Crie o método `setSize()` que apenas aceita os valores válidos de tamanho.
- O método `getSize()` deve consultar o estado sem alterá-lo.
- O método `setSize()` deve validar o valor antes de alterar o atributo.
- Caso o valor seja válido, retorne `true` e atualize `size`. Caso seja inválido, retorne `false` sem alterar o estado.
- O setter não deve imprimir mensagens; o loop da interface deve informar quais são os valores permitidos quando receber `false`.
- Faça um código de teste iniciando uma camisa com tamanho vazio e pedindo para o usuário informar o tamanho da camisa.
- Mantenha o usuário preso no loop até que ele insira um valor válido.

## Diagrama

A classe `Shirt` protege seu `size` privado e garante que apenas os tamanhos permitidos façam parte de seu estado. O getter, o setter e o loop têm responsabilidades distintas: consulta, validação/alteração e interação.

![diagrama](assets/diagrama.png)

## Guide

Aqui um exemplo de código python incompleto que implementa a classe `Shirt` e um loop para pedir o tamanho da camisa ao usuário.

O ponto principal é preservar a invariante dentro de `setSize()`: se o valor não pertence ao conjunto permitido, o método retorna `false` e mantém o estado anterior.

Pergunta de reflexão: por que a lista de tamanhos válidos não deve ficar apenas no loop de entrada?

```py

class Shirt:
    def __init__(self): # isso é o construtor em python
        self.__size: str = "" # atributos em python com __ na frente são privados

    def getSize(self) -> str: # métodos em python tem self como primeiro atributo
        return self.__size

    def setSize(self, size: str) -> bool:
        # validar o valor; retorne false sem alterar o estado se ele for inválido

# loop principal
shirt = Shirt() # criando camisa com valor tamanho padrão

while True: # mantendo usuário no loop
    print("Digite seu tamanho de roupa")
    size = input() # lendo a resposta
    if shirt.setSize(size): # tentando atribuir e disparando erros
        break
    else:
        print("Tamanho inválido, os tamanhos válidos são: PP, P, M, G, GG e XG")

print("Parabens, você comprou uma camisa tamanho", shirt.getSize())
```

## Draft

<!-- links .cache/starter -->
<!-- links -->
