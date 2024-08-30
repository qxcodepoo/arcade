# @especiais - Operações IV

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/especiais/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo especiais`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Shell](#shell)
-- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/especiais/cover.jpg)

***

## Intro

### pares

- **occurr**: Faça uma contagem de quantas vezes cada nível de stress aparece e retorne essa contagem ordenado pelo nível de stress.
- **times** Uma ou mais pessoas de mesmo stress seguidas formam um time. Gere um vetor compactado indicando o nível de stress e quantas pessoas tem em cada time?

### proximidade

- **mnext**: Apresente um mapa colocando 1 nas posições que existem homens ao lado de pelo menos uma mulher.
- **alone**: quais posições existem homens que não estão do lado de nenhuma mulher?

### duplo for

- **couple**: Casais são formados quando quando um homem e uma mulher com o mesmo nível de stress se encontram. Retorne a quantidade de casais que podem ser formados.
- **subseq**: Dada uma sequência de valores, procure essa sequência na fila e retorne a primeira posição onde ela começar.

### remoções

- **erase**: dado a lista com os índices de todas as pessoas que saíram da fila, qual a fila resultante?
- **clear**: dado um valor, remova todas as vezes que esse valor aparece na lista.

***

## Draft

- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/especiais/.cache/draft.cpp)
- [solver.java](https://github.com/qxcodepoo/arcade/blob/master/base/especiais/.cache/draft.java)
- [solver.ts](https://github.com/qxcodepoo/arcade/blob/master/base/especiais/.cache/draft.ts)

## Shell

```sh
#TEST_CASE occur
$occurr [1,3,-1]
[(1, 2), (3, 1)]
$occurr [-2,1,-2,4]
[(1, 1), (2, 2), (4, 1)]
$occurr [1,2,5,9,-1,-1,5,5]
[(1, 3), (2, 1), (5, 3), (9, 1)]
$end
```

```sh
#TEST_CASE teams
$teams []
[]
$teams [5]
[(5, 1)]
$teams [5,5]
[(5, 2)]
$teams [3,5,5,5]
[(3, 1), (5, 3)]
$teams [5,5,2,2,2,4,4]
[(5, 2), (2, 3), (4, 2)]
$teams [5,5,7,1,5]
[(5, 2), (7, 1), (1, 1), (5, 1)]
$end
```

```sh
#TEST_CASE mnext
$mnext [5]
[0]
$mnext [5,2]
[0, 0]
$mnext [-1,-3,5]
[0, 0, 1]
$mnext [1,2,5,9,-1,-1,5,5]
[0, 0, 0, 1, 0, 0, 1, 0]
$end
```

```sh
#TEST_CASE alone
$alone [5]
[1]
$alone [5,3]
[1, 1]
$alone [-1,-3,5]
[0, 0, 0]
$alone [1,-3,5]
[0, 0, 0]
$alone [-1,3,-5]
[0, 0, 0]
$alone [1,2,5,9,-1,-1,5,5]
[1, 1, 1, 0, 0, 0, 0, 1]
$end
```

```sh
#TEST_CASE couple
$couple [5]
0
$couple [5,3]
0
$couple [5,-5]
1
$couple [-5,-5]
0
$couple [-5,5]
1
$couple [-5,5,-5,-5]
1
$couple [2,-2,4,2,-4,-4]
2
$couple [2,-2,4,2,-4,-4,4]
3
$end
```

```sh
#TEST_CASE subseq
$subseq [1,2,4,3] [8]
-1
$subseq [1,2,4,3] [1,2]
0
$subseq [1,2,4,3] [2,4,3]
1
$subseq [3,5,5,5] [5,5]
1
$subseq [5,5,2,2,2,4,4] [2,2,4]
3
$subseq [5,5,2,2,2,4,4] [2,2,4,4,3]
-1
$subseq [5,5,2,2,2,4,4] [9]
-1
$subseq [5,5,2,2,2,4,4] [4,4,4]
-1
$end
```

```sh
#TEST_CASE erase
$erase [1,2,4,3] [0,1,2,3]
[]
$erase [1,2,4,3] [1,2]
[1, 3]
$erase [1,2,4,3] [2,1,3]
[1]
$erase [3,5,5,5] [3]
[3, 5, 5]
$end
```

```sh
#TEST_CASE clear
$clear [2,2,2,2,2] 2
[]
$clear [1,2,4,3] 1
[2, 4, 3]
$clear [1,2,2,3,2,2] 2
[1, 3]
$clear [5,5,3,5,5,5] 5
[3]
$end
```
