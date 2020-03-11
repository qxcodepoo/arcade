## ©10_after 32 Agenda 3 #agregação #manager #template #herança
### Notas e Contatos juntos
![](figura.jpg)

Algum dia você já utilizou a agenda do seu telefone para guardar outra coisa além de contatos e telefones? Eu mesmo já utilizei a minha para guardar algumas notas e até números ou senhas. O objetivo da agenda híbrida é fazer uma agenda capaz de guardar e favoritar várias coisas além de contatos.

Você vai partir do projeto da agenda de contatos e seguir a seguinte sequência de implementações do projeto.

```bash
#__begin__
# adicionava o contato e vários telefones ao contato
# se o contato ja existir, apenas adicione os novos telefones

$addContato eva oi:8585 claro:9999
$addContato ana tim:3434 casa:4567 oi:8754
$addContato bia vivo:5454
$agenda
- ana C [0:tim:3434][1:casa:4567][2:oi:8754]
- bia C [0:vivo:5454]
- eva C [0:oi:8585][1:claro:9999]
$rmFone ana 0
$agenda
- ana C [0:casa:4567][1:oi:8754]
- bia C [0:vivo:5454]
- eva C [0:oi:8585][1:claro:9999]
$rmContato bia
$agenda
- ana C [0:casa:4567][1:oi:8754]
- eva C [0:oi:8585][1:claro:9999]
$search eva
- eva C [0:oi:8585][1:claro:9999]
$search 4567
- ana C [0:casa:4567][1:oi:8754]


$addContato bia vivo:5454
$addContato rui casa:3233
$addContato zac fixo:3131
$agenda
- ana C [0:casa:4567][1:oi:8754]
- bia C [0:vivo:5454]
- eva C [0:oi:8585][1:claro:9999]
- rui C [0:casa:3233]
- zac C [0:fixo:3131]

$fav eva
$fav ana
$fav ana
$fav zac
$fav rex
fail: contato rex nao existe

$agenda
@ ana C [0:casa:4567][1:oi:8754]
- bia C [0:vivo:5454]
@ eva C [0:oi:8585][1:claro:9999]
- rui C [0:casa:3233]
@ zac C [0:fixo:3131]

$favorited
@ ana C [0:casa:4567][1:oi:8754]
@ eva C [0:oi:8585][1:claro:9999]
@ zac C [0:fixo:3131]

$rmContato zac

$favorited
@ ana C [0:casa:4567][1:oi:8754]
@ eva C [0:oi:8585][1:claro:9999]

$unfav ana

$favorited
@ eva C [0:oi:8585][1:claro:9999]

$agenda
- ana C [0:casa:4567][1:oi:8754]
- bia C [0:vivo:5454]
@ eva C [0:oi:8585][1:claro:9999]
- rui C [0:casa:3233]

$addNote mercantil ovo chiclete fandangos
$addNote mercantil pao
$la
@ C dani [0:recado:324]
- C joao [1:oi:8775]
+ N mercantil (ovo chiclete fandangos pao)

$addContato xuxa claro:99
$agenda
@ C dani [0:recado:324]
- C joao [1:oi:8775]
- N mercantil (ovo chiclete fandangos pao)
- C xuxa [0:claro:99]

$fav mercantil
$favorited
@ C dani [0:recado:324]
@ N mercantil (ovo chiclete fandangos pao)
#__end__
```

## Raio X

```java

abstract class Entry{
    id: string
    favorited: bool

    ***
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
