## @015 Busca

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/015/cover.jpg)

[](toc)

- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
[](toc)

Sua agenda possui vários contatos e cada contato possui vários telefones.

Implemente a classe Contact e Fone utilizando as regras descritas no projeto Contato ou reaproveite o código que você fez.

***

## Intro

- Adicionar
  - O contato possui o nome como chave.
  - Se tentar adicionar outro contato com o mesmo nome, adicione os telefones ao contato existente.
  - Adicionar os novos números de telefone no contato já existente.
- Agenda
  - Mostrar os contatos da agenda pela ordem alfabética.
- Remoção
  - Remover contato pela chave.
  - Remover telefone do contato.
- Busca
  - Fazer uma busca por padrão em todos os atributos do contato, nome e telefones.
  - Se o contato tiver qualquer campo que combine com a string pattern de busca, ele deve ser retornado. Se o pattern é maria, devem ser retornados os contatos como "maria julia", "mariana", "ana maria", etc. Também inclua na busca o id do telefone ou o número do telefone.

***

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/015/diagrama.png)

## Shell

```python
#__case adicionando em lote
$add eva oio:8585 cla:9999
$add ana tim:3434 
$add bia viv:5454

# como ana já existe, não crie um novo contato
# adicione os telefones ao contato existente
$add ana cas:4567 oio:8754

$show
- ana [0:tim:3434] [1:cas:4567] [2:oio:8754]
- bia [0:viv:5454]
- eva [0:oio:8585] [1:cla:9999]


#__case removendo telefone
# remove o elemento indice 0 da ana
$rmFone ana 0

$show
- ana [0:cas:4567] [1:oio:8754]
- bia [0:viv:5454]
- eva [0:oio:8585] [1:cla:9999]

#__case removendo contato
$rm bia

$show
- ana [0:cas:4567] [1:oio:8754]
- eva [0:oio:8585] [1:cla:9999]

$add ava tim:5454
$add rui viv:2222 oio:9991
$add zac rec:3131

$show
- ana [0:cas:4567] [1:oio:8754]
- ava [0:tim:5454]
- eva [0:oio:8585] [1:cla:9999]
- rui [0:viv:2222] [1:oio:9991]
- zac [0:rec:3131]

#__case busca por padrao
$search va
- ava [0:tim:5454]
- eva [0:oio:8585] [1:cla:9999]

$search 999
- eva [0:oio:8585] [1:cla:9999]
- rui [0:viv:2222] [1:oio:9991]

$end

#__end__
```
