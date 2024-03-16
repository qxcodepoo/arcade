# Gerencie os vários contatos da @agenda

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/agenda/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo agenda`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell)
-- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/agenda/cover.jpg)

Sua agenda possui vários contatos e cada contato possui vários telefones.

Essa atividade é uma continuação da @014 Contato. Lá é explicado com mais detalhes como criar a classe `Contact` e a classe `Fone`.

***

## Intro

- Adicionar contato
  - O contato possui o nome como chave.
  - Se tentar adicionar outro contato com o mesmo nome, adicione os telefones ao contato existente.
  - Adicionar os novos números de telefone no contato já existente.
- Mostrar
  - Mostrar os contatos da agenda pela ordem alfabética.
- Remoção
  - Remover contato pela chave.
  - Remover telefone do contato.
- Busca
  - Fazer uma busca por padrão em todos os atributos do contato, nome e telefones.
  - Se o contato tiver qualquer campo que combine com a string pattern de busca, ele deve ser retornado. Se o pattern é maria, devem ser retornados os contatos como "maria julia", "mariana", "ana maria", etc. Também inclua na busca o id do telefone ou o número do telefone.
- Favoritos
  - Favoritar e Desfavoritar um contato.
  - Mostrar os favoritos.
***

## Guide

- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/agenda/.cache/draft.cpp)
- [solver.ts](https://github.com/qxcodepoo/arcade/blob/master/base/agenda/.cache/draft.ts)

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/agenda/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts

class Fone {
  - id : str
  - number : str
  __
  ' inicializa as variaveis
  + Fone(id : str, number : str)
  
  ' verifica se o número é um número de telefone válido
  ' crie uma str "validos" com todos os caracteres válidos
  ' para cada caractere c do número:
  '   se c não estiver em validos:
  '     retorne false
  ' retorne true
  + isValid() : bool
  __
  + getId() : str
  + getNumber() : str
  __
  ' Gera uma string para impressão
  ' ex: oi:1234
  + toString() : str
}

class Contact {
  - favorited : bool
  - fones : List<Fone>
  - name : str
  __
  
  ' inicialize o fone com o nome, favorited como false e a lista de fones vazia
  + Contact(name : str)
  __
  ' se fone for válido:
  '   insira no fim da lista de fones
  ' se não:
  '   informe o erro
  + addFone(id: str, number : str): void
  
  ' se o índice existir:
  '   remove o fone pelo indice
  + rmFone(index : int): void
  
  __
  ' favorita ou desfavorita o contato
  + toogleFavorited(): void

  ' retorna se o contato está favoritado
  + isFavorited() : bool
  __
  + getFones() : List<Fone>
  + getName() : str
  + setName(name : str): void

  __
  ' use um contador para mostrar o índice do telefone
  ' use o toString do fone para adicioná-lo à saída
  ' se o contato estiver favoritado, adicione um @ antes do nome
  ' o resultado dever ficar assim:
  ' ex: - david [oi:123, tim:9081, claro:5431]
  + toString() : str
}

class Agenda {

  ' use um vector em c++
  ' um ArrayList em Java
  ' um Array em Typescript
  - contacts : List<Contact>
  __

  ' procura o contato pelo nome
  ' o nome do contato é único na agenda
  ' se encontrar, retorne o índice do contato no array
  ' se não encontrar, retorne -1
  - findPosByName(name : String) : int
  __
  + Agenda()
  __
  
  ' use a função findPosByName para encontrar o índice do contato
  ' se o contato existir:
  '   adicione todos os telefones válidos ao contato
  ' se não:
  '   crie um novo contato
  '   adicione todos os telefones válidos
  '   reordene a lista de contatos
  + addContact (name : String, fones : List<Fone>)

  ' use a função findPosByName para encontrar o índice do contato
  ' retorna uma referência para o contato
  ' em C++, retorne um 'Contact*'
  ' se não existir, retorne null
  + getContact(name : String) : Contact | null

  ' use a função findPosByName para encontrar o índice do contato
  ' se o contato existir:
  '   remova o contato
  + rmContact  (name : String)

  ' crie uma lista de contatos para armaenar os resultados
  ' para cada contato na lista de contatos:
  '   gere a string do contato usando contato.toString()
  '   use uma função de busca por substring para verificar se o padrão está na string do contato
  '   se estiver:
  '     adicione o contato à lista de resultados
  ' retorne a lista de resultados
  + search     (pattern : String) : List<Contact>


  ' cria uma lista de contatos vazia
  ' para cada contato na lista de contatos:
  '   se o contato estiver favoritado:
  '     adicione o contato à lista de favoritos
  ' retorne a lista de favoritos
  + getFavorited() : List<Contact>
  __

  ' retorne a lista de contatos
  + getContacts() : List<Contact>
  __

  ' retorna os contatos separados por uma quebra de linha
  + toString() : String
}

```

<!-- load -->

## Shell

```py
#__case adicionando em lote
$add eva oio:8585 cla:9999
$add ana tim:3434
$add bia viv:5454

$show
- ana [tim:3434]
- bia [viv:5454]
- eva [oio:8585, cla:9999]


#__case adicionando a um contato existente

# como ana já existe, não crie um novo contato
# adicione os telefones ao contato existente
$add ana cas:4567 oio:8754

$show
- ana [tim:3434, cas:4567, oio:8754]
- bia [viv:5454]
- eva [oio:8585, cla:9999]


#__case removendo telefone
# remove o elemento indice 0 da ana
$rmFone ana 0

$show
- ana [cas:4567, oio:8754]
- bia [viv:5454]
- eva [oio:8585, cla:9999]

#__case removendo contato
$rm bia

$show
- ana [cas:4567, oio:8754]
- eva [oio:8585, cla:9999]

#__case adicionando mais contatos

$add ava tim:5454
$add rui viv:2222 oio:9991
$add zac rec:3131

$show
- ana [cas:4567, oio:8754]
- ava [tim:5454]
- eva [oio:8585, cla:9999]
- rui [viv:2222, oio:9991]
- zac [rec:3131]

#__case busca por padrao
$search va
- ava [tim:5454]
- eva [oio:8585, cla:9999]

$search 999
- eva [oio:8585, cla:9999]
- rui [viv:2222, oio:9991]

#__case toggle favoritos
$tfav ana
$tfav rui

$show
@ ana [cas:4567, oio:8754]
- ava [tim:5454]
- eva [oio:8585, cla:9999]
@ rui [viv:2222, oio:9991]
- zac [rec:3131]

#__case favoritos
$favs
@ ana [cas:4567, oio:8754]
@ rui [viv:2222, oio:9991]

$end

#__end__
```
