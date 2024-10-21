# Eventos e setores em uma bilheteria

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![cover](cover.jpg)

## Intro

Fazer vendas usando papel e caneta é coisa do passado. Você foi contratado para modernizar a bilheteria do seu bairro e trazer ela pro século XXI.

Você deve desenvolver um sistema para gerenciar as vendas de uma bilheteria de shows.

Nessa variação do problema, cada evento pode ter vários setores e cada setor tem um preço.

A classe Bilheteria é o repositório de Vendas, Clientes e Eventos.

O Evento atua como repositório de Setores.

## Draft

- [draft.ts](.cache/draft.ts)

## Guide

![diagrama](diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts

class Pessoa {
  - nome: string
  - meia: boolean
  __
  + constructor(nome:string, meia:boolean)
  + getNome():string
  + getMeia():boolean
  + toString():string
}

class Setor {
  - evento: string
  - nome: string
  - preco: number
  __
  + constructor(evento: string, nome: string, preco: number)
  + getNome():string
  + getEvento():string
  + getPreco():number
  + toString():string
}

class Evento {
  - nome: string
  - setores: Map<string, Setor>
  __
  + constructor(nome: string)

  + getNome():string

  + getSetores(): Setor[]

  ' lançar exceção se o setor já existir
  + addSetor(nome: string, preco: number): void

  ' lançar exceção se o setor não existir
  + getSetor(nome: string): Setor
}

class Venda {
  - pessoa: Pessoa
  - setor: Setor
  - valor: number
  __

  ' o valor da venda é calculado no construtor
  + constructor(pessoa: Pessoa, setor: Setor, setor: Setor)
  
  + getPessoa():Pessoa
  + getSetor():Setor
  + getValor():number
  + toString():string
}

class Bilheteria {
  - repVendas: Venda[]
  - repPessoas: Map<string, Pessoa>
  - repEventos: Map<string, Evento>

  __

  + constructor()    

  ' retorna a lista das vendas
  + getVendas(): Venda[]

  ' retorna a lista das pessoas como array
  + getPessoas(): Pessoa[]

  ' retorna a lista dos eventos como array
  + getEventos(): Evento[]
  + getCaixa(): number
  
  __

  ' lançar exceção se a pessoa não existir
  + getPessoa(nome: string): Pessoa

  ' lançar exceção se o evento não existir
  + getEvento(nome: string): Evento

  __

  ' lançar exceção se nome for repetido
  + addPessoa(nome: string, meia:bool):void 
  
  ' lançar exceção se nome for repetido
  + addEvento(nome: string, preco: valor):void 

  ' se o setor já existir é lançada no pela classe Evento
  + addSetor(nome_evento: string, nome_setor: string, preco: number):void
  
  ' esse método usa os métodos getPessoa e getEvento
  ' o evento usa o metodo getSetor para obter o setor
  ' para fazer a venda, não é necessário lançar nenhuma exceção aqui
  + vender(nome_pessoa: string, nome_evento: string, nome_setor: string):void 
}

```

<!-- load -->

## Shell

```sh
#TEST_CASE cadastro pessoas
# addPessoa _nome _meia
$addPessoa bruno meia
$addPessoa chico meia
$addPessoa aline inteira

#TEST_CASE cadastro duplicado

$addPessoa chico meia
fail: pessoa chico ja existe

#TEST_CASE show pessoas
# imprima os dados ordenados pela chave
$pessoas
[aline:inteira, bruno:meia, chico:meia]

#TEST_CASE cadastro eventos

# addEvento _nome
$addEvento samba
$addEvento piano
$addEvento forro

#TEST_CASE show eventos
# imprima ordenado pelo nome
$eventos
forro []
piano []
samba []

#TEST_CASE cadastro duplicado
$addEvento samba 90
fail: evento samba ja existe

#TEST_CASE cadastro setores
$addSetor samba pista 35.00
$addSetor samba vip 70.00
$addSetor piano lateral 15.00
$addSetor piano fundos 7.50
$addSetor forro pista 30.00

#TEST_CASE show setores
$eventos
forro [pista:30.00]
piano [fundos:7.50, lateral:15.00]
samba [pista:35.00, vip:70.00]

#TEST_CASE vender ingressos

# vender _pessoa _evento
# se a pessoa for meia, aplique 50% de desconto no preço do evento
$vender bruno samba pista
$vendas
bruno:samba:pista:17.50

$vender chico samba vip
$vender aline samba vip
$vendas
bruno:samba:pista:17.50
chico:samba:vip:35.00
aline:samba:vip:70.00

$vender chico piano lateral
$vendas
bruno:samba:pista:17.50
chico:samba:vip:35.00
aline:samba:vip:70.00
chico:piano:lateral:7.50

#TEST_CASE erro nas vendas
$vender joao piano lateral
fail: pessoa joao nao existe

$vender aline pianU lateral
fail: evento pianU nao existe

$vender aline piano lateraU
fail: setor lateraU nao existe

$end
```
