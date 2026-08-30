## Raio X

```c++
class Fone
- id: string
- number: string
--
+ _validar_(number): bool
--
+ constructor(id, number)
```

```c++
class Contato
- id: string
- fones: Fone[]
- favorited: bool
--
+ addFone(id, number)
+ rmFone(id)
--
+ constructor(id, number)
```

```c++
class Agenda
- contatos: Contato[]
- favoritos: Contato[]

    map<string, Contato> contatos;
    map<string, Contato*> favoritos;
--
+ addContato(idContato, Contato): void
    se contatos

+ rmContato(id): void
    se contato existe
        remove da lista de contatos
        e remove da lista de favoritos

+ getAllContatos(): Contato[]

+ favoritar(id)
    contato = getContato(id)
    if not contato.favorited:
        contato.favorited = true
        favoritos[id] = contato

+ desfavoritar(id)
    contato = getContato(id)
    if contato.favorited:
        contato.favorited = false
        favoritos.remove(id)
    
+ getFavoritos(): Contato[]
    return favorited
--
```

___
## Raio X2

```c++
class Fone
- id: string
- number: string
--
+ _validar_(number): bool
--
+ constructor(id, number)
```

```c++
class Contato
- id: string
- fones: Fone[]
--
+ addFone(id, number)
+ rmFone(id)
--
+ constructor(id, number)
```

```c++
class Agenda
- contatos: Contato[]
--
+ addContato(idContato, Contato): void
+ rmContato(id): void
+ getAllContatos(): Contato[]
```

```c++
class ServicoFavoritagem
+ agenda: Agenda
+ favoritos: Contato[]

+ favoritar(id)
    pegar o contato na agenda
    adicionar o contato nos favoritos

+ desfavoritar(id)
    pegar o contato na agenda
    remover o contato dos favoritos

+ getFavoritos(): Contato[]
    retornar os favoritos

+ agendaComFavoritos(): string
--
ServicoFavoritagem(agenda: Agenda)
```