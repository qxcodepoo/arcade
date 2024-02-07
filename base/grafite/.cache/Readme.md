# Controle uma lapiseria de um @grafite

Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/grafite/Readme.md)

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/grafite/cover.jpg)

Faça o modelo de uma lapiseira que pode conter um único grafite.

[![explicação](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/grafite/../_images/explicacao.png)](https://youtu.be/LvZODN2rL6s)

***

## Intro

- Iniciar lapiseira.
  - Inicia uma lapiseira de determinado calibre sem grafite no bico.
- Inserir grafite.
  - Insere um grafite passando
    - o calibre: float.
    - a dureza: string.
    - o tamanho em mm: int.
  - Não deve aceitar um grafite de calibre não compatível.
- Remover grafite.
  - Retira o grafite se houver algum.
- Escrever folha.
  - Não é possível escrever se não há grafite ou o grafite tem tamanho menor ou igual a 10mm.
  - Quanto mais macio o grafite, mais rapidamente ele se acaba. Para simplificar, use a seguinte regra:
    - Grafite HB: 1mm por folha.
    - Grafite 2B: 2mm por folha.
    - Grafite 4B: 4mm por folha.
    - Grafite 6B: 6mm por folha.
    - O último centímetro de um grafite não pode ser aproveitado, quando o grafite estiver com 10mm, não é mais possível escrever.
    - Se não houver grafite suficiente para terminar a folha, avise que o texto ficou incompleto.

***

## Draft

- [Solver.java](https://github.com/qxcodepoo/arcade/blob/master/base/grafite/.cache/draft.java)
- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/grafite/.cache/draft.cpp)
- [solver.ts](https://github.com/qxcodepoo/arcade/blob/master/base/grafite/.cache/draft.ts)

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/grafite/diagrama.png)

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


class Pencil {
    
    ' calibre da lapiseira
    - thickness : float

    ' guarda o grafite que está na ponta da lapiseira
    ' um valor nulo indica que a lapiseira está sem grafite
    - tip       : Lead | null
    __

    ' inicializa os atributos da lapiseira
    ' tip para null
    + Pencil(thickness : float)
    
    ' retorna true se tem grafite na lapiseira
    + hasGrafite()        : boolean
    
    ' insere o grafite na lapiseira
    ' verifica se ja tem grafite
    ' verifica se o grafite tem calibre compatível
    + insert(lead : Lead) : boolean
    
    ' remove o grafite da ponta
    ' verifica se existe grafite na ponta
    ' retorna o grafite removido
    ' ou null se não tinha grafite
    ' remover significa colocar o atributo tip para null
    + remove()            : Lead | null

    ' escreve na folha gastando o grafite
    ' verifica se existe grafite na ponta
    ' tenta diminuir o tamanho do grafite 
    '   utilizando os métodos getSize() e setSize()
    '   escrever uma folha gasta tip.usagePerSheet() mm
    ' verifica se existe tamanho para escrever a folha inteira
    + writePage()         : void
    
    __
    + toString()          : string
}
```

<!-- load -->

***

## Shell

```bash
#__case inserindo grafites
$init 0.5
$show
calibre: 0.5, grafite: null

#__case incompativel
$insert 0.7 2B 50
fail: calibre incompativel
$insert 0.5 2B 50
$show
calibre: 0.5, grafite: [0.5:2B:50]
$end
```

***

```bash
#__case inserindo
$init 0.3
$insert 0.3 2B 50
$show
calibre: 0.3, grafite: [0.3:2B:50]

#__case ja existe
$insert 0.3 4B 70
fail: ja existe grafite
$show
calibre: 0.3, grafite: [0.3:2B:50]

#__case removendo
$remove
$show
calibre: 0.3, grafite: null

#__case reinserindo
$insert 0.3 4B 70
$show
calibre: 0.3, grafite: [0.3:4B:70]
$end
```

***

```bash
#__case sem grafite
$init 0.9
$write
fail: nao existe grafite

#__case escrevendo 1
$insert 0.9 4B 14
$write
$write
fail: tamanho insuficiente
$show
calibre: 0.9, grafite: [0.9:4B:10]
$end
```

***

```bash
#__case escrevendo 2
$init 0.9
$insert 0.9 4B 16
$write
$show
calibre: 0.9, grafite: [0.9:4B:12]
#__case escrevendo 3
$write
fail: folha incompleta
$show
calibre: 0.9, grafite: [0.9:4B:10]
$end
```
