# @contagem - Operações II

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/contagem/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo contagem`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Shell](#shell) | [Alien](#alien)
-- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/contagem/cover.jpg)

***

## Intro

- **count**: quantas vezes o valor X apareceu na fila?
- **sum**: qual a soma de todos os valores de stress da fila?
- **average**: qual a média de stress?
- **half_compare**: qual metade da lista é mais estressada? A primeira metade ou a segunda metade? A quantidade de elementos na lista sempre será par. \[draw, first, second]
- **more_men_or_women**: existem mais homens ou mulheres? \[draw, men, women]
- **sex_battle**: quem é mais estressado em média? \[draw, men, women]

## Draft

- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/contagem/.cache/draft.cpp)
- [solver.ts](https://github.com/qxcodepoo/arcade/blob/master/base/contagem/.cache/draft.ts)

## Shell

```sh
#TEST_CASE count
$count [5,3,-1,-50,-1,-99] -1
2
$count [-1,-50,-1,-99,-444] 10
0
$end
```

```sh
#TEST_CASE sum
$sum [1,-1]
2
$sum [5,3,-1]
9
$sum [-1,-50]
51
$end
```

```sh
#TEST_CASE average
$average [5,3,-1,-50,-1,-99]
26.50
$average [-1,-50,-1,-99,-444]
119.00
$end
```

```sh
#TEST_CASE more_men
$more_men [5,3,1,-50,-1,-99]
draw
$more_men [5,-3,1,-50,-1,-99]
women
$more_men [5,3,1,-50,-1,99]
men
$end
```

```sh
#TEST_CASE half_compare
$half_compare [5,-5]
draw
$half_compare [5,-4]
first
$half_compare [5,-6]
second
$half_compare [5,3]
first
$half_compare [3,5]
second
$half_compare [5,3,-1,50,10,-999]
second
$half_compare [50,-98,2,-50,-1,-99]
draw
$half_compare [51,99,1,-50,-1,-99]
first
$end
```

```sh
#TEST_CASE sex_battle
$sex_battle [5,3,-1,-50,-10,-999]
women
$sex_battle [50,98,2,-50,-1,9991]
men
$sex_battle [-50,99,1,50,-1,-99]
draw
$end
```

## Alien

[![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/contagem/../../wiki/images/alien4.jpg)](https://www.youtube.com/watch?v=yEks2RnwgeA)
