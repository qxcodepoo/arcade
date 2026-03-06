# Manipulações em Arrays

## Estruturas lineares em cada linguagem

- python: list
- java: ArrayList
- c++: vector
- typescript: Array

## Competências básicas de manipulação de dados

Você pode testar utilizando um array de inteiros ou um array de objetos.

- Criar um array vazio
  - tanto para um tipo primitivo (int, number) quanto para um tipo objeto (classe Foo)
- Criar um array preenchido
  - preenchendo já com valores durante a criação
- Obter o tamanho do array
- Adicionar e remover elementos ao final
- Adicionar e remover elementos no início
- Adicionar e remover elementos em uma posição específica
- Fazer impressão formatada utilizando o método join
- Criar um array com elementos em sequência de zero a n
- Criar um array com valores aleatórios
- Acessar elementos por índice
- Percorrer os elementos utilizando for-range
- Percorrer os elementos utilizando for indexado
- Procurar um elemento X usando laço
- Procurar um elemento X usando função nativa
- Criar um novo array com elementos filtrados, por exemplo, pares
- Criar um novo array com elementos transformados, por exemplo, ao quadrado
- Buscar e remover um elemento X
- Remover todos os elementos com valor X da lista
- Verificar quais funções existem nativamente na linguagem
  - busca
  - remoção
  - ordenação
  - embaralhamento

## Crie seu próprio código de testes

```py

class Foo:
    def __init__(self, x: int):
        self.x = x

    def __str__(self):
        return f'Foo({self.x})'

lista_vazia: list[int] = []
lista_preenchida: list[int] = [1, 2, 3, 4, 5]
lista_preencida_objetos: list[Foo] = [Foo(1), Foo(2), Foo(3), Foo(4), Foo(5)]

lista_vazia.append(1)
lista_preenchida.append(Foo(6))

# continue com seus próprios testes de manipulação de arrays
```
