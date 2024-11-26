# Lapiseira com múltiplos grafites

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![cover](cover.jpg)

Faça o modelo de uma lapiseira que pode conter vários.

## Intro

- Iniciar lapiseira
  - Inicia uma lapiseira de determinado calibre sem grafite.
  - Lapiseiras possuem um bico e um tambor.
  - O bico guarda o grafite que está em uso.
  - O tambor guarda os grafites reservas.
- Inserir grafite
  - Insere um grafite passando
    - o calibre: float.
    - a dureza: string.
    - o tamanho em mm: int.
  - Não deve aceitar um grafite de calibre não compatível.
  - O grafite é colocado como o ÚLTIMO grafite do tambor.
- Puxar grafite
  - Puxa o grafite do tambor para o bico.
  - Se já tiver um grafite no bico, esse precisa ser removido primeiro.
- Remover grafite
  - Retira o grafite do bico.
- Escrever folha
  - Não é possível escrever se não há grafite no bico.
  - Quanto mais macio o grafite, mais rapidamente ele se acaba. Para simplificar, use a seguinte regra:
    - Grafite HB: 1mm por folha.
    - Grafite 2B: 2mm por folha.
    - Grafite 4B: 4mm por folha.
    - Grafite 6B: 6mm por folha.
  - O último centímetro de um grafite não pode ser aproveitado, quando o grafite estiver com 10mm, não é mais possível escrever e o grafite deve ser retirado.
  - Se não houver grafite suficiente para terminar a folha, avise que o texto ficou incompleto.

***

## Draft

- [Solver.java](.cache/draft.java)
- [solver.cpp](.cache/draft.cpp)
- [solver.ts](.cache/draft.ts)

## Guide

![diagrama](diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts

@startuml
skinparam defaultFontName "Source Code Pro"
skinparam dpi 150
left to right direction

' Grafite
class Lead {
    - hardness  : string
    - thickness : number
    - size      : number
    __
    + Lead(thickness: number, hardness: string, size: number)
    __
    + usagePerSheet(): number
    + getSize()      : number
    + getThickness() : number
    + getHardness()  : string
    __
    + setSize(size : number)
    __
    + toString(): string
}

class Pencil {
    - thickness: number
    - tip      : Lead | null
    - barrel   : Array<Lead>
    __
    + Pencil(thickness : number)
    __
    + insert(lead: Lead) : boolean
    + remove()   : Lead | null
    + pull()     : boolean
    + writePage(): void
    __
    + toString() : string
}

Pencil "1" o--  "0..*" Lead : > Stores
@enduml
```

<!-- load -->

***

## Shell

```bash
#TEST_CASE inserindo grafites
$init 0.5
$show
calibre: 0.5, bico: [], tambor: <>
#TEST_CASE calibre errado
$insert 0.7 2B 50
fail: calibre incompatível
#TEST_CASE calibre certo
$insert 0.5 2B 50
$show
calibre: 0.5, bico: [], tambor: <[0.5:2B:50]>
#TEST_CASE mais de um grafite
$insert 0.5 2B 30
$show
calibre: 0.5, bico: [], tambor: <[0.5:2B:50][0.5:2B:30]>
#TEST_CASE puxando grafite
$pull
$show
calibre: 0.5, bico: [0.5:2B:50], tambor: <[0.5:2B:30]>
#TEST_CASE puxando ocupado
$pull
fail: ja existe grafite no bico
#TEST_CASE removendo do bico
$remove
$show
calibre: 0.5, bico: [], tambor: <[0.5:2B:30]>
$end
```

***

```bash
#TEST_CASE escrevendo 
$init 0.9
$insert 0.9 4B 14
$insert 0.9 4B 16
#TEST_CASE sem grafite no bico
$write
fail: nao existe grafite no bico
#TEST_CASE puxando grafite
$pull
$show
calibre: 0.9, bico: [0.9:4B:14], tambor: <[0.9:4B:16]>
#TEST_CASE gastando grafite
$write
$show
calibre: 0.9, bico: [0.9:4B:10], tambor: <[0.9:4B:16]>
#TEST_CASE puxando novo
$remove
$pull
$show
calibre: 0.9, bico: [0.9:4B:16], tambor: <>
$write
$show
calibre: 0.9, bico: [0.9:4B:12], tambor: <>
#TEST_CASE folha incompleta
$write
fail: folha incompleta
$show
calibre: 0.9, bico: [0.9:4B:10], tambor: <>
#TEST_CASE tamanho insuficiente
$write
fail: tamanho insuficiente
$end
```
