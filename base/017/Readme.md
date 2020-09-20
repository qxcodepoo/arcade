# Agenda 4 - Híbrida com notas e contatos
![](figura.jpg)

<!--TOC_BEGIN-->
- [Requisitos](#requisitos)
- [Shell](#shell)
- [Raio X](#raio-x)

<!--TOC_END-->

## Requisitos
Algum dia você já utilizou a agenda do seu telefone para guardar outra coisa além de contatos e telefones? Eu mesmo já utilizei a minha para guardar algumas notas e até números ou senhas. O objetivo da agenda híbrida é fazer uma agenda capaz de guardar e favoritar várias coisas além de contatos.

Você vai partir do projeto da agenda de contatos e seguir a seguinte sequência de implementações do projeto.

- Utilize o nome do contato e o título da nota como chave única da entrada.
- Tanto na apresentação da agenda como da lista de favoritos, a lista deve ser apresentada ordenada pela chave.
- Na formação toString da entrada utilize:
    - `-` para marcar as entradas normais e `@` para as entradas favoritadas.
    - `C` para marcar os contatos e `N` para marcar as notas.

## Shell
```bash
#__case init contatos
# adicionava o contato e vários telefones ao contato
# se o contato ja existir, apenas adicione os novos telefones
$addContato eva oi:8585 claro:9999
$addContato ana tim:3434 casa:4567 oi:8754
$addContato xuxa claro:99
$agenda
- C ana [0:tim:3434][1:casa:4567][2:oi:8754]
- C eva [0:oi:8585][1:claro:9999]
- C xuxa [0:claro:99]

#__case fav contatos
$fav eva
$fav ana
@ C ana [0:tim:3434][1:casa:4567][2:oi:8754]
@ C eva [0:oi:8585][1:claro:9999]
- C xuxa [0:claro:99]

#__case lista favoritos
$favorited
@ C ana [0:casa:4567][1:oi:8754]
@ C eva [0:oi:8585][1:claro:9999]

#__case add notes
$addNote mercantil ovo chiclete fandangos
$addNote mercantil pao
$agenda
@ C ana [0:tim:3434][1:casa:4567][2:oi:8754]
@ C eva [0:oi:8585][1:claro:9999]
- N mercantil (ovo chiclete fandangos pao)
- C xuxa [0:claro:99]

#__case fav notes
$fav mercantil
$favorited
@ C ana [0:tim:3434][1:casa:4567][2:oi:8754]
@ C eva [0:oi:8585][1:claro:9999]
@ N mercantil (ovo chiclete fandangos pao)

$agenda
@ C ana [0:tim:3434][1:casa:4567][2:oi:8754]
@ C eva [0:oi:8585][1:claro:9999]
@ N mercantil (ovo chiclete fandangos pao)
- C xuxa [0:claro:99]

$end
```

## Raio X

```java

abstract class Entry{
    id: string
    favorited: bool

    setId(value: string, type: Type): void
    getId(): string
    isFavorited(): bool
    setFavorited(value:bool): void
    toString(): string
}

class Agenda{
    - entries: Entry[]
    - favorites: Entry[]
    ***
    addEntry(Entry entry)
    rmEntry(id: String)  //desfavorita se preciso e remove a entrada
    getEntries(): Entry[] //retorna todas as entradas
    getFavorites(): Entry[] //retorna todos os favoritos
    setFavorited(idEntry: string, value: bool)
    filter(pattern: string)
}

//opcao 1
class MasterAgenda extends Agenda{
    getContatos(): Contato[]
    getNotes(): Note[]
    getContato(string id): Contato
    getNote(string id): Note
}

class Fone{
    id: string
    number: string
}

class Contato extends Entry{
    fones: Fone[]
    addFone(fone: Fone)
    rmFone(id)
}

class Note extends Entry {
    text: string
    itens: string[]
    addItem(string item)
}

class Controller {
    master: MasterAgenda
}

```
