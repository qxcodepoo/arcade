---
index_content: |2
    - Descrição: a camisa guarda um tamanho textual e informa os tamanhos permitidos.
    - Domínio: o objeto começa com um tamanho válido e aceita somente `PP`, `P`, `M`, `G`, `GG` ou `XG`, mantendo o estado anterior em caso de falha.
    - Objetivos: consolidar a validação de um conjunto de valores e a inicialização segura no construtor.
---
# [TRAIN] Camisa de tamanho fixo

<!-- toc-table -->

![_](assets/cover.webp)

## Intro

O objetivo dessa atividade é implementar uma classe que controle o tamanho válido de uma camisa.

Nesta atividade você vai praticar **encapsulamento** com o atributo privado `size`, um getter para consulta e um setter validador. O objeto já deve nascer em estado válido, e o setter deve preservar a **invariante** de que o tamanho pertence ao conjunto permitido.

### Mensagens do programa

As explicações da atividade estão em português, mas o texto produzido pelo programa deve ficar em inglês. Use, por exemplo:

- `Enter shirt size`
- `fail: invalid size`
- `Congratulations, you bought a shirt size`

## Regras

- Os tamanhos serão identificados como uma variável tipo texto, e os valores válidos são "PP", "P", "M" e "G", "GG" e "XG".
- Faça o objeto `Shirt` iniciar com um tamanho padrão válido.
- O construtor deve primeiro inicializar o atributo privado com esse tamanho padrão e depois chamar `set_size()` para tentar aplicar o tamanho recebido.
- Crie o método estático `get_allowed_sizes()` para retornar uma nova lista com os tamanhos permitidos.
- Crie o método `set_size()` que apenas aceita os valores válidos de tamanho.
- O método `get_size()` deve consultar o estado sem alterá-lo.
- O método `set_size()` deve validar o valor antes de alterar o atributo.
- Caso o valor seja válido, retorne `true` e atualize `size`. Caso seja inválido, retorne `false` sem alterar o estado.
- O setter não deve imprimir mensagens; o loop da interface deve informar quais são os valores permitidos quando receber `false`.
- Faça um código de teste criando uma camisa com tamanho padrão e pedindo para o usuário informar o tamanho desejado.
- Mantenha o usuário preso no loop até que ele insira um valor válido.

## Diagrama

`Shirt` protege seu tamanho e concentra a lista de tamanhos válidos. `set_size()` valida antes de alterar o estado; `get_allowed_sizes()` devolve uma nova lista; `main` conduz o loop e apresenta as mensagens.

```mermaid
%%{init: { "fontFamily": "monospace" } }%%
classDiagram
    direction TB

    class Shirt {
        +DEFAULT_SIZE : string$
        -size : string
        +constructor(size : string)
        +getSize() string
        +getAllowedSizes() Array<string>$
        +setSize(size : string) boolean
    }

    class Main {
        +main() void
    }

    Main ..> Shirt : creates and uses
```

## Guide

Aqui um exemplo de código python incompleto que implementa a classe `Shirt` e um loop para pedir o tamanho da camisa ao usuário.

O ponto principal é preservar a invariante dentro de `set_size()`: se o valor não pertence ao conjunto permitido, o método retorna `false` e mantém o estado anterior.

Pergunta de reflexão: por que a lista de tamanhos válidos não deve ficar apenas no loop de entrada?

```py

class Shirt:
    DEFAULT_SIZE: str = "P"

    def __init__(self, size: str) -> None:
        self.__size: str = Shirt.DEFAULT_SIZE
        self.set_size(size)

    def get_size(self) -> str:
        return self.__size

    @staticmethod
    def get_allowed_sizes() -> list[str]:
        return ["PP", "P", "M", "G", "GG", "XG"]

    def set_size(self, size: str) -> bool:
        # valide o valor; retorne False sem alterar o estado se ele for inválido
        pass

# loop principal
shirt = Shirt(Shirt.DEFAULT_SIZE) # criando camisa

while True: # mantendo usuário no loop
    print("Enter shirt size")
    size = input() # lendo a resposta
    if shirt.set_size(size): # tentando atribuir o tamanho informado
        break
    else:
        print("fail: invalid size")
        print("Allowed sizes are:", ", ".join(Shirt.get_allowed_sizes()))

print("Congratulations, you bought a shirt size", shirt.get_size())
```

Verifique os limites e o estado após falha: `PP`, `P`, `M`, `G`, `GG` e `XG` devem ser aceitos; `XXL` deve ser rejeitado; depois de criar a camisa com `P`, uma tentativa inválida deve manter `get_size()` igual a `P`. Cada chamada de `get_allowed_sizes()` deve devolver uma lista nova.

<!-- MERMAID -->

## Draft

<!-- links .cache/starter -->
<!-- links -->
