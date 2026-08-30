# Sistema de Animais no Zoológico

Implemente um conjunto de classes para representar animais em um zoológico, utilizando herança e polimorfismo. A ideia é ter uma classe base abstrata com métodos e atributos concretos, e subclasses que implementam comportamento específico.

## Requisitos

1. Definir uma classe abstrata `Animal` com:

- um atributo concreto `nome: str` inicializado em `__init__`
- um método concreto `apresentar_nome()` que imprime `Eu sou um(a) <nome>!`
- dois métodos abstratos que devem ser implementados pelas subclasses:
  - `fazer_som()`
  - `mover()`

2. Criar pelo menos três subclasses concretas (por exemplo: `Leao`, `Elefante`, `Cobra`) que:

- recebam `nome` no construtor e chamem `super().__init__(nome)`
- implementem `fazer_som()` com um som característico
- implementem `mover()` com um movimento característico

3. Criar uma função `apresentar(animal: Animal)` que:

- chama `apresentar_nome()`
- chama `fazer_som()`
- chama `mover()`
- imprime o tipo/classe do objeto

4. Montar uma lista de instâncias diferentes e testar o polimorfismo chamando `apresentar` para cada uma.
