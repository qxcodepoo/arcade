# Agenda 2 Favoritos - Lidando com redundâncias - TODO: solver

![](figura.jpg)

<!--TOC_BEGIN-->
- [Habilidades](#habilidades)
- [Requisitos](#requisitos)
- [Shell](#shell)
- [Ajuda](#ajuda)
- [Raio X](#raio-x)

<!--TOC_END-->

Ampliando a atividade de agenda 1, vamos criar uma agenda que gerencia os nossos contatos.

## Habilidades
O objetivo da ativade é trabalhar:
- Reforçar as operações de Crud usando contatos e telefones.
- Ordenação
    - Intrínseca atraves do uso de mapas ou utilizando métodos de ordenação de vetores.
- Uso de estruturas de dados como mapas.
    - Poderemos utilizar os mapas como alternativa superior aos vetores.
- Integridade e Redundância(mesma informação em vários lugares para agilizar o acesso)
    - Favoritar implica em guardar informação redundante.
- Uso de referências.
    - Os favoritos apenas guardam as referências para os contatos.
- Uso do método toString para fazer buscas de contatos.

## Requisitos

O sistema deverá:

- Adicionar contatos usando um idContato que pode ser nome ou cpf
    - Não deve ser possível adicionar dois contatos com o mesmo idContato.

- Remover um contato pelo idContato.

- Adicionar telefones ao contato.
    - Um telefone tem um idFone e um numero.
    - idFone serão nomes como: casa, fixo, oi.
    - Verifique se o número contém apenas os seguintes caracteres "0123456789 ().-".

- Remover telefones do contato pelo índice.

- Mostrar todos os contatos.
    - Ordenar os contatos pelo idContato com os contatos favoritos primeiro.
    - Marque os contatos que são favoritados com um @ antes do idContato. Se o contato não for favorito use - antes do idContato.
    - Coloque todos os telefones ordenados por id

- Buscar contatos por substring.
    - Se o contato tiver qualquer campo que combine com a string pattern de busca, ele deve ser retornado. Se o pattern é maria, devem ser retornados os contatos como "maria julia", "mariana", "ana maria", etc. Se o pattern combinar com qualquer campo do contato, ele deve fazer parte do retorno.
    - Mostre ordenado pelo idContato com os contatos favoritos primeiro

- Favoritar contatos

- Desfavoritar contatos.

- Mostrar favoritos.

## Shell

```bash
$addContato eva oi:8585 claro:9999
$addContato ana tim:3434 
$addContato ana casa:4567 oi:8754
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
```


***
## Ajuda
- Na busca por padrão verifiqueo valor do padrão com o valor toString() to contato.
- Crie métodos toString para todas as Classes.
- Quando remover um contato, verifique de removê-lo dos favoritos também.
- Quando desfavoritar um contato, lembre de tanto remover da lista como alterar o valor do atributo favorited no próprio contato.

***
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
--
+ addContato(idContato, Contato): void
+ rmContato(id): void
+ getAllContatos(): Contato[]

+ favoritar(id)
+ desfavoritar(id)
+ getFavoritos(): Contato[]
--
```
