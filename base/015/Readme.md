# Agenda 2 - Varios contatos TODO Raio X, fone com ID
![](figura.jpg)

<!--TOC_BEGIN-->
- [Requisitos Novos](#requisitos-novos)
- [Shell](#shell)
- [Ajuda](#ajuda)

<!--TOC_END-->

Sua agenda possui vários contatos e cada contato possui vários telefones.
***
## Requisitos Novos
- Adicionar
    - O contato possui o nome como chave. Portanto, não permita que existam dois contatos com o mesmo nome.
    - Adicionar os novos números de telefone no contato já existente.
- Agenda
    - Mostrar os contatos da agenda pela ordem alfabética.
- Remoção
    - Remover contato pela chave.
- Busca
    - Fazer uma busca por padrão em todos os atributos do contato, nome e telefones.
    - Se o contato tiver qualquer campo que combine com a string pattern de busca, ele deve ser retornado. Se o pattern é maria, devem ser retornados os contatos como "maria julia", "mariana", "ana maria", etc. Também inclua na busca o id do telefone ou o número do telefone.


## Shell

```bash
#__case adicionando em lote
$add eva oi:8585 claro:9999
$add ana tim:3434 
$add bia vivo:5454

# como ana já existe, não crie um novo contato
# adicione os telefones ao contato existente
$add ana casa:4567 oi:8754

$agenda
- ana [0:3434]
- bia [0:5454]
- eva [0:8585][1:9999][2:2221]


#__case removendo telefone
# remove o elemento indice 0 da ana
$rmFone ana 0

$agenda
- ana [0:4567][1:8754]
- bia [0:5454]
- eva [0:8585][1:9999][2:2221]

#__case removendo contato
$rmContato bia

$agenda
- ana [0:4567][1:8754]
- eva [0:8585][1:9999][2:2221]

$add ava tim:5454
$add rui vivo:2222 oi:9991
$add zac recado:3131

$agenda
- ana [0:4567][1:8754]
- ava [0:5454]
- eva [0:8585][1:9999][2:2221]
- rui [0:2222][1:9991]
- zac [0:3131]

#__case busca por padrao
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

## Ajuda
- Inserção
    - Opção 1: Guarde os contato em uma estrutura de dados ordenada como um map(c++) ou TreeMap(Java) utilizando o Id do contato como chave.
    - Opção 2: Utilizar uma estrutura linear, tal como um vector(c++) ou ArrayList(Java), mas lembrar de reordenar o vetor para cada nova inserção de contato.
- Busca: 
    - Na busca por pattern verifique faça uma busca usando a substring com o valor toString() to contato.