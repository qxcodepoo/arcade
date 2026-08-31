# Comprando uma camisa XG

<!-- toc-table -->
<!-- toc-table -->

![_](assets/cover.webp)

## Intro

O objetivo dessa atividade é implementar uma classe que controle o tamanho válido de uma camisa.

Nesta atividade você vai praticar **encapsulamento** com um atributo privado, um getter para consulta e um setter validador. O setter deve preservar a **invariante** de que o tamanho pertence ao conjunto permitido.

## Regras

- Os tamanhos serão identificados como uma variável tipo texto, e os valores válidos são "PP", "P", "M" e "G", "GG" e "XG".
- Faça o objeto roupa iniciar o tamanho como uma string vazia, para expressar que nenhum tamanho foi atribuído.
- Crie o método setTamanho que apenas aceita os valores válidos de tamanho.
- O método `getTamanho` deve consultar o estado sem alterá-lo.
- O método `setTamanho` deve validar o valor antes de alterar o atributo.
- Caso o valor seja inválido, retorne false e informe quais os valores permitidos.
- Faça um código de teste iniciando uma roupa com tamanho vazio e pedindo para o usuário informar o tamanho da roupa.
- Mantenha o usuário preso no loop até que ele insira um valor válido.

## Guide

Aqui um exemplo de código python incompleto que implementa a classe Camisa e um loop para pedir o tamanho da camisa ao usuário.

```py

class Camisa:
    def __init__(self): # isso é o construtor em python
        self.__tamanho: str = "" # atributos em python com __ na frente são privados

    def getTamanho(self) -> str: # métodos em python tem self como primeiro atributo
        return self.__tamanho

    def setTamanho(self, valor: str) -> bool:
        # implementar os testes de valor e disparar os avisos caso necessário

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
