---
index_content: |2
    - Objetivo: criar uma forma secundária de acesso sem duplicar os contatos.
    - Conceitos: índice, conjunto, redundância intencional e consistência.
    - Técnicas: manter uma fonte de verdade e sincronizar estruturas relacionadas.
    - Pré-requisito: mapas, conjuntos e encapsulamento.
---
# [TRAIN] Favoritos: índice secundário e consistência

<!-- toc-table -->
[Intro](#intro) | [Regras](#regras) | [Diagrama](#diagrama) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft)
-- | -- | -- | -- | -- | --
<!-- toc-table -->

![cover](assets/cover.webp)

## Intro

Esta atividade continua `agenda` e introduz uma mudança deliberada na forma de consultar favoritos. Em `agenda`, favoritos são um atributo de `Contact` e uma consulta percorre o mapa principal. Aqui a agenda também mantém um índice secundário com as chaves dos contatos favoritos.

O objetivo principal é compreender como um índice secundário pode acelerar uma consulta e cria uma obrigação de consistência. Como objetivos secundários, a atividade trabalha a fonte de verdade e a integridade referencial entre o mapa e o índice.

### Progressão pedagógica

- `contato` encapsula os telefones e o estado de um único contato.
- `agenda` coloca contatos em um `MutableMap<String, Contact>`, usando o nome como identidade única, e calcula favoritos sob demanda.
- `favoritos` mantém `favoriteIds: MutableSet<String>` como índice secundário persistente sobre o mapa de contatos.

O mapa `contacts` continua sendo a fonte de verdade dos objetos. O conjunto de identificadores não duplica contatos: ele armazena apenas chaves que apontam para objetos existentes no mapa. A redundância está na relação entre `Contact.starred` e a presença do nome em `favoriteIds`.

## Regras

### Modelo

- `Phone` mantém `label` e `number`, aceita números não vazios com pelo menos um dígito e usa somente `0123456789()-.`.
- `Phone.isValid(): Boolean` valida o número e `toString()` apresenta `label:number`.
- `Contact` mantém nome, telefones privados e o estado `starred`.
- `Contact.addPhone(phone: Phone): Boolean` ignora o telefone inválido e retorna `false`; `getPhones(): List<Phone>` retorna uma cópia.
- `Contact.setStarred(value: Boolean): Unit` altera o estado de favorito. A agenda usa esta operação junto com o índice.
- `Agenda` mantém `contacts: MutableMap<String, Contact>` e `favoriteIds: MutableSet<String>`.
- `Agenda.addContact(contact: Contact): Unit` incorpora telefones ao contato existente sem substituir seu estado de favorito.
- `Agenda.removeContact(name: String): Boolean` remove o contato e a entrada no índice, retornando `false` se o nome não existe.
- Adicionar um contato com nome já existente incorpora seus telefones ao contato existente.
- Telefones inválidos são ignorados e produzem `fail: invalid number`.

### Índice de favoritos

- `star name` marca o contato como favorito e adiciona `name` ao conjunto de índices.
- `unstar name` desmarca o contato e remove `name` do conjunto.
- `Agenda.star(name: String): Boolean` e `unstar(name: String): Boolean` retornam `false` quando o contato não existe; repetir operações válidas não compromete a consistência.
- Repetir `star` ou `unstar` não duplica nem corrompe o índice.
- Remover um contato também remove sua chave de `favoriteIds`.
- `getStarred(): List<Contact>` resolve as chaves no mapa, descarta qualquer chave inexistente e exibe os contatos em ordem alfabética.
- `search(pattern: String): List<Contact>` busca nome, label e número; `getAll(): List<Contact>` retorna todos em ordem alfabética.
- O estado deve preservar a invariante `contact.starred == (contact.name in favoriteIds)`.

### Comandos

- `add name label:number ...`: cria um contato ou incorpora telefones ao contato existente.
- `rm name`: remove o contato e sua entrada no índice.
- `star name`: favorita o contato ou exibe `fail: contact not found`.
- `unstar name`: desfavorita o contato ou exibe `fail: contact not found`.
- `starred`: exibe somente os favoritos, ordenados pelo nome.
- `search pattern`: busca no nome, label e número, em ordem alfabética.
- A busca diferencia maiúsculas e minúsculas.
- `show`: exibe todos os contatos, em ordem alfabética.
- `init`: reinicia mapa e índice.
- `end`: encerra o programa.
- Qualquer outro comando exibe `fail: invalid command`.

Mutações bem-sucedidas e consultas sem resultados são silenciosas.

## Diagrama

`contacts` é a fonte de verdade. `favoriteIds` é um índice secundário derivado: ele melhora o acesso aos favoritos, mas precisa ser atualizado em toda operação que altera a relação entre contato e favorito.

```mermaid
%%{init: {'theme': 'base', 'fontFamily': 'monospace'}}%%
classDiagram
    direction LR

    class Phone {
        +VALID_CHARS : String$
        +val label : String
        +val number : String
        +isValid() Boolean
        +toString() String
    }

    class Contact {
        +val name : String
        +val starred : Boolean
        -val phones : MutableList~Phone~
        +Contact(name : String)
        +addPhone(phone : Phone) Boolean
        +removePhone(index : Int) Boolean
        +getPhones() List~Phone~
        +setStarred(value : Boolean) Unit
        +matches(pattern : String) Boolean
        +toString() String
    }

    class Agenda {
        -val contacts : MutableMap~String, Contact~
        -val favoriteIds : MutableSet~String~
        +Agenda()
        +addContact(contact : Contact) Unit
        +getContact(name : String) Contact?
        +removeContact(name : String) Boolean
        +star(name : String) Boolean
        +unstar(name : String) Boolean
        +getStarred() List~Contact~
        +search(pattern : String) List~Contact~
        +getAll() List~Contact~
        +toString() String
    }

    class Shell {
        +main() Unit
    }

    Agenda "1" *-- "0..*" Contact : source of truth
    Contact "1" *-- "0..*" Phone : owns
    Agenda ..> Contact : resolves favorite IDs
    Shell ..> Agenda : commands
```

## Guide

### 1. Reutilize o modelo de `agenda`

Comece com `Phone` e `Contact` de `agenda`. Preserve a regra de validade do telefone, a coleção privada e a representação textual. A nova atividade deve mudar a coordenação da agenda, não reescrever regras que já pertencem ao contato.

### 2. Adicione o índice secundário

Crie um `MutableSet<String>` privado para guardar os nomes favoritados. Um conjunto evita duplicação de chaves e expressa diretamente que a ordem não faz parte do índice. Ao listar, recupere os contatos pelo mapa e ordene somente o resultado apresentado.

### 3. Preserve a consistência

Faça `star`, `unstar` e `removeContact` atualizarem o atributo do contato e o conjunto. Pergunte, após cada operação: o contato existe no mapa? O nome está ou não está no índice? O atributo e o índice contam a mesma história?

### 4. Observe o custo da decisão

O índice reduz a necessidade de filtrar todos os contatos para uma consulta de favoritos, mas aumenta o número de estados que precisam permanecer sincronizados. Esse é o custo da redundância intencional. Se o índice ficar desatualizado, ocorre uma falha de consistência ou uma referência órfã.

Perguntas de reflexão:

- Por que `favoriteIds` guarda chaves, e não cópias de `Contact`?
- Por que favoritar o mesmo contato duas vezes não deve criar duas entradas?
- O que precisa acontecer no índice quando um contato favorito é removido?
- Em que volume de contatos o custo de manter o índice poderia compensar sua complexidade?
- Que diferença existe entre uma consulta derivada em `agenda` e um índice persistente em `favoritos`?

## Shell

```bash
#TEST_CASE iniciando agenda
$add eva oi:8585 claro:9999
$add ana tim:3434
$add ana casa:4567 oi:8754
$add bia vivo:5454
$add rui casa:3233
$add zac fixo:3131
$show
- ana [0:tim:3434] [1:casa:4567] [2:oi:8754]
- bia [0:vivo:5454]
- eva [0:oi:8585] [1:claro:9999]
- rui [0:casa:3233]
- zac [0:fixo:3131]

#TEST_CASE favoritando
$star eva
$star ana
$star ana
$star zac
$starred
@ ana [0:tim:3434] [1:casa:4567] [2:oi:8754]
@ eva [0:oi:8585] [1:claro:9999]
@ zac [0:fixo:3131]

#TEST_CASE removendo contato favorito
$rm zac
$starred
@ ana [0:tim:3434] [1:casa:4567] [2:oi:8754]
@ eva [0:oi:8585] [1:claro:9999]

#TEST_CASE desfavoritando
$unstar ana
$starred
@ eva [0:oi:8585] [1:claro:9999]

#TEST_CASE operações inválidas
$star rita
fail: contact not found
$unstar rita
fail: contact not found
$rm rita
fail: contact not found
$end
```

```bash
#TEST_CASE regras herdadas e busca
$add ana home:-()
fail: invalid number
$add eva home:8585
$search 85
- eva [0:home:8585]
$show
- ana []
- eva [0:home:8585]
$end
```

```bash
#TEST_CASE init_resets_index
$add ana home:3434
$star ana
$init
$starred
$add ana home:5678
$show
- ana [0:home:5678]
$end
```

## Draft

<!-- links .cache/starter -->
<!-- links -->
<!-- KOTLIN -->
