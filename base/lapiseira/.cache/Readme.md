# Gerenciando os múltiplos grafites de uma @lapiseira

Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/lapiseira/Readme.md)

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/lapiseira/cover.jpg)

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

- [Solver.java](https://github.com/qxcodepoo/arcade/blob/master/base/lapiseira/.cache/draft.java)
- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/lapiseira/.cache/draft.cpp)
- [solver.ts](https://github.com/qxcodepoo/arcade/blob/master/base/lapiseira/.cache/draft.ts)

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/lapiseira/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts
' Grafite
class Lead {
    
    ' calibre do grafite
    - thickness : float
    
    ' dureza do grafite HB, 2B, 4B, 6B
    - hardness  : string

    ' tamanho do grafite em milímetros
    - size      : int
    __
  
    ' inicializa os atributos do grafite
    + Lead(thickness : float, hardness : string, size : int)
    
    ' gastoPorFolha
    ' retorna o gasto em milímetros para uma página escrita
    ' 1mm para HB
    ' 2mm para 2B
    ' 4mm para 4B
    ' 6mm para 6B
    + usagePerSheet() : int
    __
    
    ' apenas os métodos get
    + getHardness()  : string
    + getSize()      : int
    + getThickness() : float

    __
    + setSize(size : int)
    __
    + toString()      : string
}

' Lapiseira
class Pencil {
    
    ' calibre da lapiseira
    - thickness : float

    ' guarda o grafite que está na ponta da lapiseira
    ' um valor nulo indica que a lapiseira está sem grafite
    - tip       : Lead | null

    ' tambor da lapiseira, guarda os grafites
    - barrel    : List<Lead>
    __

    ' inicializa os atributos da lapiseira
    ' tip para null
    ' barrel para uma lista vazia
    + Pencil(thickness : float)
    __

    ' insere um grafite no final do tambor
    ' verifica se o grafite tem calibre compatível
    + insert(lead : Lead) : boolean

    ' remove o grafite da ponta
    ' verifica se existe grafite na ponta
    ' retorna o grafite removido
    ' ou null se não tinha grafite
    ' remover significa colocar o atributo tip para null
    + remove()            : Lead | null

    ' remove primeiro grafite do tambor e insere na ponta
    ' precisa existir algum grafite no tambor
    ' precisa a ponta estar vazia
    + pull()              : boolean

    ' escreve na folha gastando o grafite
    ' verifica se existe grafite na ponta
    ' tenta diminuir o tamanho do grafite 
    '   utilizando os métodos getSize() e setSize()
    '   escrever uma folha gasta tip.usagePerSheet() mm
    ' verifica se existe tamanho para escrever a folha inteira
    + writePage()
    __
    + toString() : string
}
```

<!-- load -->

***

## Shell

```bash
#__case inserindo grafites
$init 0.5
$show
calibre: 0.5, bico: [], tambor: {}
#__case calibre errado
$insert 0.7 2B 50
fail: calibre incompatível
#__case calibre certo
$insert 0.5 2B 50
$show
calibre: 0.5, bico: [], tambor: {[0.5:2B:50]}
#__case mais de um grafite
$insert 0.5 2B 30
$show
calibre: 0.5, bico: [], tambor: {[0.5:2B:50][0.5:2B:30]}
#__case puxando grafite
$pull
$show
calibre: 0.5, bico: [0.5:2B:50], tambor: {[0.5:2B:30]}
#__case puxando ocupado
$pull
fail: ja existe grafite no bico
#__case removendo do bico
$remove
$show
calibre: 0.5, bico: [], tambor: {[0.5:2B:30]}
$end
```

***

```bash
#__case escrevendo 
$init 0.9
$insert 0.9 4B 14
$insert 0.9 4B 16
#__case sem grafite no bico
$write
fail: nao existe grafite no bico
#__case puxando grafite
$pull
$show
calibre: 0.9, bico: [0.9:4B:14], tambor: {[0.9:4B:16]}
#__case gastando grafite
$write
$show
calibre: 0.9, bico: [0.9:4B:10], tambor: {[0.9:4B:16]}
#__case puxando novo
$remove
$pull
$show
calibre: 0.9, bico: [0.9:4B:16], tambor: {}
$write
$show
calibre: 0.9, bico: [0.9:4B:12], tambor: {}
#__case folha incompleta
$write
fail: folha incompleta
$show
calibre: 0.9, bico: [0.9:4B:10], tambor: {}
#__case tamanho insuficiente
$write
fail: tamanho insuficiente
$end
```
