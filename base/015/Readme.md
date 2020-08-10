# Agenda 1 - Varios contatos com vários telefones TODO Raio X
![](figura.jpg)

<!--TOC_BEGIN-->
- [Requisitos](#requisitos)
- [Opcional](#opcional)
- [Shell](#shell)

<!--TOC_END-->

Sua agenda possui vários contatos e cada contato possui vários telefones.
***
## Requisitos

- O contato possui o nome como chave. Portanto, não permita que existam dois contatos com o mesmo nome.
- Adicionar os novos números de telefone no contato já existente.
- Mostrar os números de telefone pela ordem de inserção.
- Mostrar os contatos da agenda pela ordem alfabética.
- Remover contato pela chave.

## Opcional
- Remover o telefone pelo índice.
- Fazaer uma busca por padrão em todos os atributos do contato, nome e telefones.


## Shell

```bash
#__begin__
$addContato eva 8585 9999 2221
$addContato ana 3434 
$addContato bia 5454

$agenda
- ana [0:3434]
- bia [0:5454]
- eva [0:8585][1:9999][2:2221]

# como ana ja existe, apenas adicione o telefone
$addContato ana 4567 8754

$agenda
- ana [0:3434][1:4567][2:8754]
- bia [0:5454]
- eva [0:8585][1:9999][2:2221]

# remove o elemento indice 0 da ana
$rmFone ana 0

$agenda
- ana [0:4567][1:8754]
- bia [0:5454]
- eva [0:8585][1:9999][2:2221]

$rmContato bia

$agenda
- ana [0:4567][1:8754]
- eva [0:8585][1:9999][2:2221]

$addContato ava 5454
$addContato rui 2222 9991
$addContato zac 3131

$agenda
- ana [0:4567][1:8754]
- ava [0:5454]
- eva [0:8585][1:9999][2:2221]
- rui [0:2222][1:9991]
- zac [0:3131]

$search va
- ava [0:5454]
- eva [0:8585][1:9999][2:2221]

$search 999
- eva [0:8585][1:9999][2:2221]
- rui [0:2222][1:9991]

$search 222
- eva [0:8585][1:9999][2:2221]
- rui [0:2222][1:9991]

$end

#__end__
```
