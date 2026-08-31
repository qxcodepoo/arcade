# [GUIA] Comprando uma camisa XG

<!-- toc-table -->
<!-- toc-table -->

![_](assets/cover.webp)

## Intro

O objetivo dessa atividade é implementar uma classe que controle o tamanho válido de uma camisa.

Nesta atividade você vai praticar **encapsulamento** com um atributo privado, um getter para consulta e um setter validador. O setter deve preservar a **invariante** de que o tamanho pertence ao conjunto permitido.

## Regras

- Os tamanhos serão identificados como uma variável tipo texto, e os valores válidos são "PP", "P", "M" e "G", "GG" e "XG".
- Faça o objeto camisa iniciar o tamanho como uma string vazia, para expressar que nenhum tamanho foi atribuído.
- Crie o método setTamanho que apenas aceita os valores válidos de tamanho.
- O método `getTamanho` deve consultar o estado sem alterá-lo.
- O método `setTamanho` deve validar o valor antes de alterar o atributo.
- Caso o valor seja válido, retorne `true` e atualize o tamanho. Caso seja inválido, retorne `false` sem alterar o estado.
- O setter não deve imprimir mensagens; o loop da interface deve informar quais são os valores permitidos quando receber `false`.
- Faça um código de teste iniciando uma camisa com tamanho vazio e pedindo para o usuário informar o tamanho da camisa.
- Mantenha o usuário preso no loop até que ele insira um valor válido.

## Diagrama

A classe `Camisa` protege seu tamanho privado e garante que apenas os tamanhos permitidos façam parte de seu estado. O getter, o setter e o loop têm responsabilidades distintas: consulta, validação/alteração e interação. O exemplo trabalha encapsulamento, responsabilidade única, KISS, DRY e testabilidade.

![diagrama](assets/diagrama.png)

## Guide

Aqui um exemplo de código python incompleto que implementa a classe Camisa e um loop para pedir o tamanho da camisa ao usuário.

```py

class Camisa:
    def __init__(self): # isso é o construtor em python
        self.__tamanho: str = "" # atributos em python com __ na frente são privados

    def getTamanho(self) -> str: # métodos em python tem self como primeiro atributo
        return self.__tamanho

    def setTamanho(self, valor: str) -> bool:
        # validar o valor; retorne false sem alterar o estado se ele for inválido

# loop principal
camisa = Camisa() # criando camisa com valor tamanho padrão

while True: # mantendo usuário no loop
    print("Digite seu tamanho de roupa")
    tamanho = input() # lendo a resposta
    if camisa.setTamanho(tamanho): # tentando atribuir e disparando erros
        break
    else:
        print("Tamanho inválido, os tamanhos válidos são: PP, P, M, G, GG e XG")

print("Parabens, você comprou uma camisa tamanho", camisa.getTamanho())
```

## Draft

<!-- links .cache/starter -->
<!-- links -->
