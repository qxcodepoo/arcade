# Grafite 🎥

![cover](cover.jpg)

[](toc)

- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
[](toc)

Faça o modelo de uma lapiseira que pode conter um único grafite.

[![explicação](../_images/explicacao.png)](https://youtu.be/LvZODN2rL6s)

***

## Intro

- Iniciar lapiseira
  - Inicia uma lapiseira de determinado calibre sem grafite no bico.
- Inserir grafite
  - Insere um grafite passando
    - o calibre: float.
    - a dureza: string.
    - o tamanho em mm: int.
  - Não deve aceitar um grafite de calibre não compatível.
- Remover grafite
  - Retira o grafite se houver algum.
- Escrever folha
  - Não é possível escrever se não há grafite ou o grafite tem tamanho menor ou igual a 10mm.
  - Quanto mais macio o grafite, mais rapidamente ele se acaba. Para simplificar, use a seguinte regra:
    - Grafite HB: 1mm por folha.
    - Grafite 2B: 2mm por folha.
    - Grafite 4B: 4mm por folha.
    - Grafite 6B: 6mm por folha.
    - O último centímetro de um grafite não pode ser aproveitado, quando o grafite estiver com 10mm, não é mais possível escrever.
    - Se não houver grafite suficiente para terminar a folha, avise que o texto ficou incompleto.

***

## Guide

![diagrama](diagrama.png)

[](load)[](diagrama.puml)[](plantuml:fenced:filter)

```plantuml
class Lead {
  - thickness : float
  - hardness  : string
  - size      : int
  __
  '
  ' inicializa os atributos do grafite
  + Lead(thickness : float, hardness : string, size : int)
  '
  ' retorna o gasto em milímetros para uma página escrita
  ' 1mm para HB
  ' 2mm para 2B
  ' 4mm para 4B
  ' 6mm para 6B
  + usagePerSheet() : int
  __
  + setSize(size : int)
  __
  + getHardness()      : string
  + getSize()          : int
  + getThickness()     : float
}

class Pencil {
  - thickness : float
  - tip : Lead | null
  __
  '
  ' inicializa os atributos da lapiseira
  ' lembre de inicializar tip como null
  + Pencil(thickness : float)
  '
  ' retorna true se tem grafite na lapiseira
  + hasGrafite()        : boolean
  '
  ' verifica se ja tem grafite
  ' verifica se o grafite tem espessura compatível
  ' insere o grafite na lapiseira
  + insert(lead : Lead) : boolean
  '
  ' se houver grafite, remove e retorna o grafite
  ' se nao houver grafite, retorna null
  + remove()            : Lead | null
  '
  ' verifica se tem grafite
  ' verifica se tem mais de 10mm
  ' se tiver menos que o necessário para página, escreve parcialmente
  ' se tiver mais que o necessário para página, escreve totalmente
  + writePage()         : void
  '
  + toString()          : string
  __
  + getThickness()      : float
}
```

[](load)

- [Solver.java](.cache/draft.java)
- [solver.cpp_](.cache/draft.cpp)
- [solver.ts__](.cache/draft.ts)

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
