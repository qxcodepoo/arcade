# Listas em Python: ações mais comuns

<!-- toc-table -->
[Intro](#intro) | [Criar e consultar](#criar-e-consultar) | [Percorrer](#percorrer) | [Inserir](#inserir) | [Remover](#remover) | [Buscar](#buscar) | [Filtrar e transformar](#filtrar-e-transformar) | [Copiar e ordenar](#copiar-e-ordenar) | [Cuidados](#cuidados) | [Referência completa](#referência-completa)
-- | -- | -- | -- | -- | -- | -- | -- | -- | --
<!-- toc-table -->

## Intro

Esta leitura complementa a atividade `@array`. O objetivo é servir como referência rápida para as operações mais comuns sobre listas em Python, usando objetos `Person` em vez de valores primitivos.

Como conhecimento prévio, você precisará de variáveis, condicionais, laços, funções, classes simples e listas básicas.

Nos exemplos, cada pessoa é representada por uma `dataclass`:

```py
from dataclasses import dataclass


@dataclass
class Person:
    name: str
    age: int
```

Uma lista mantém seus elementos em ordem. Cada elemento possui uma posição, chamada índice, que começa em `0`.

## Criar e consultar

Use uma anotação para deixar explícito qual tipo de elemento pertence à lista.

```py
empty: list[Person] = []

people: list[Person] = [
    Person("ana", 20),
    Person("bia", 17),
    Person("caio", 31),
]
```

As consultas abaixo não alteram a lista:

```py
size: int = len(people)          # 3
first: Person = people[0]        # ana
last: Person = people[-1]        # caio
is_empty: bool = len(people) == 0
```

Acessar uma posição inexistente produz `IndexError`. Confira se a lista possui elementos antes de acessar suas extremidades:

```py
if people:
    first = people[0]
```

## Percorrer

Quando você precisa apenas dos elementos, percorra a lista diretamente:

```py
for person in people:
    print(person.name)
```

Quando a posição também importa, use `enumerate`:

```py
for index, person in enumerate(people):
    print(index, person.name)
```

Evite controlar manualmente um índice quando o laço direto já fornece o elemento necessário.

## Inserir

`append` adiciona ao final. `insert` adiciona na posição indicada e desloca os elementos seguintes.

```py
people.append(Person("dora", 25))
people.insert(0, Person("eva", 19))
```

Para adicionar vários elementos ao final, use `extend`:

```py
new_people: list[Person] = [Person("fabi", 22), Person("gabi", 28)]
people.extend(new_people)
```

Essas três operações alteram a lista original e retornam `None`.

## Remover

`pop` remove e retorna um elemento. Sem argumento, atua no final; com índice `0`, atua no início.

```py
if people:
    removed_from_back: Person = people.pop()

if people:
    removed_from_front: Person = people.pop(0)
```

Para remover por posição sem usar o elemento removido, use `del`:

```py
index: int = 1
if 0 <= index < len(people):
    del people[index]
```

`remove` procura um valor e remove somente a primeira ocorrência igual a ele. Confira a presença antes da remoção para evitar `ValueError`:

```py
target: Person = Person("bia", 17)
if target in people:
    people.remove(target)
```

Nesse caso, a igualdade da `dataclass` compara nome e idade. Essa operação não serve para remover por nome quando a idade for desconhecida.

Para remover apenas a primeira pessoa com determinado nome, busque sua posição e interrompa o laço após a remoção:

```py
name_to_remove: str = "ana"

for index, person in enumerate(people):
    if person.name == name_to_remove:
        people.pop(index)
        break
```

O `break` é importante: sem ele, o laço continuaria depois de alterar as posições da lista.

Para remover todos os elementos, use `clear`:

```py
people.clear()
```

## Buscar

Use `in` quando quiser verificar se o próprio valor está presente:

```py
target: Person = Person("bia", 17)
contains_target: bool = target in people
```

Para buscar por apenas um atributo, percorra os objetos. A próxima expressão retorna a primeira pessoa com o nome procurado ou `None`:

```py
searched_name: str = "caio"
found: Person | None = next(
    (person for person in people if person.name == searched_name),
    None,
)
```

Se você precisa somente saber se alguma pessoa atende à condição, use `any`:

```py
has_adult: bool = any(person.age >= 18 for person in people)
```

## Filtrar e transformar

Uma compreensão cria uma nova lista apenas com os elementos que atendem à condição:

```py
adults: list[Person] = [person for person in people if person.age >= 18]
```

Se o objetivo é substituir o conteúdo da variável, atribua a nova lista:

```py
minimum_age: int = 18
people = [person for person in people if person.age >= minimum_age]
```

A condição descreve quem permanece. Nesse exemplo, pessoas com idade menor que `minimum_age` são removidas.

Uma compreensão também pode transformar cada elemento. O exemplo produz uma lista de nomes sem alterar `people`:

```py
names: list[str] = [person.name for person in people]
```

## Copiar e ordenar

Uma atribuição simples não copia uma lista. As duas variáveis passam a apontar para o mesmo objeto:

```py
same_people: list[Person] = people
same_people.append(Person("heitor", 40))  # também altera people
```

Use `copy` quando precisar de uma nova lista com os mesmos elementos:

```py
copied_people: list[Person] = people.copy()
```

A cópia é rasa: as duas listas ainda guardam referências para os mesmos objetos `Person`.

`sort` altera a lista. `sorted` cria outra lista ordenada:

```py
people.sort(key=lambda person: person.age)

by_name: list[Person] = sorted(
    people,
    key=lambda person: person.name,
)
```

Use o atributo que representa a ordem desejada como `key`. Não é necessário ensinar `Person` a comparar todos os seus campos para ordenar por nome ou idade.

## Cuidados

### Não use o retorno de uma mutação como se fosse a lista

Métodos como `append`, `insert`, `extend` e `sort` alteram a lista e retornam `None`.

```py
people.append(Person("iris", 21))
```

Evite:

```py
# people = people.append(Person("iris", 21))
```

### Não remova vários elementos durante um laço direto

Ao remover um elemento, os seguintes mudam de posição. O laço pode pular itens sem avisar. Para remover todos os elementos que atendem a uma regra, prefira criar uma lista filtrada.

```py
people = [person for person in people if person.age >= 18]
```

### Escolha a operação pela intenção

- `append`: inserir um elemento no final;
- `insert`: inserir em uma posição;
- `extend`: acrescentar vários elementos;
- `pop`: remover e obter o elemento;
- `del`: remover por posição sem precisar do retorno;
- `remove`: remover a primeira ocorrência de um valor;
- `clear`: remover todos os elementos;
- compreensão: criar uma lista filtrada ou transformada;
- `sort`: ordenar a lista existente;
- `sorted`: obter uma nova lista ordenada.

## Referência completa

O arquivo [reference.py](reference.py) reúne exemplos executáveis e tipados. Execute-o com:

```bash
python reference.py
```

Use esta leitura como consulta durante `@array`. Depois, tente implementar cada comando da atividade sem copiar o arquivo completo: identifique primeiro qual operação expressa melhor a intenção desejada.
