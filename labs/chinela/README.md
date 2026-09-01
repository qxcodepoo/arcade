# [GUIA] Comprando uma chinela 40/41

<!-- toc-table -->

![_](assets/cover.webp)

## Intro

O objetivo dessa atividade é implementar uma classe que controle o tamanho válido de uma chinela.

Nesta atividade você vai praticar **encapsulamento**: o tamanho fica no atributo privado `size` e só pode ser consultado por `getSize()` ou alterado por `setSize()`. O setter deve preservar a **invariante** de que o tamanho seja par e esteja entre 20 e 50.

## Regras

- Uma chinela tem um valor tamanho que é um número par entre 20 e 50, incluindo 20 e 50.
- Faça o objeto `Slipper` iniciar com `size` igual a 0 e controle o atributo através de `setSize()` para que apenas valores válidos sejam atribuídos.
- O método `setSize()` deve retornar `true` quando alterar o tamanho e `false` quando rejeitar o valor. Ele não deve imprimir mensagens.
- O método `getSize()` deve apenas consultar o estado do objeto.
- Por fim, crie um loop no qual um objeto chinela é criado e é perguntado ao usuário qual seu tamanho de chinela.
- Mantenha o usuário preso no loop até que ele insira um valor válido.
- Caso ele digite um valor inválido, o loop deve interpretar o retorno do setter e exibir uma mensagem de erro adequada.

## Diagrama

O tamanho é um detalhe interno da classe `Slipper`. O getter permite a consulta e o setter concentra a validação da invariante, mantendo a interface responsável apenas pela leitura e pelas mensagens.

![diagrama](assets/diagrama.png)

## Guide

[Vídeo de apoio](https://youtu.be/pC3DMuHVFHE?si=XIylk3z3zABCD0hj)

Implemente a classe `Slipper` antes do loop. O ponto principal é garantir que apenas `setSize()` consiga alterar o atributo privado.

Pergunta de reflexão: o que poderia acontecer se o código do loop alterasse o tamanho diretamente?

```py

class Slipper:
    # inicialização da chinela com valor de tamanho 0
    def __init__(self):    # isso é o construtor em python
        self.__size = 0 # quando tem __ na frente em python é privado

    def getSize(self): # métodos em python tem self como primeiro atributo
        return self.__size

    def setSize(self, size: int) -> bool:
        # validar o valor; retorne false sem alterar o estado se ele for inválido

# loop principal
slipper = Slipper() # criando chinela com valor tamanho padrão

while slipper.getSize() == 0: # mantendo usuário no loop
    print("Digite seu tamanho de chinela")
    size = int(input()) # lendo a resposta e convertendo pra inteiro
    if not slipper.setSize(size): # o domínio retorna falha sem imprimir
        print("Tamanho inválido, informe um número par entre 20 e 50")

print("Parabens, você comprou uma chinela tamanho", slipper.getSize())
```
