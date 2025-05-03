# Estressados Operações III

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell)
-- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/manipulacao/cover.jpg)

***

## Intro

### filter

- **get_men**: retorne uma lista com os homens.
- **get_calm_women**: retorne uma lista com as mulheres stress menor que 10.

### sort

- **sort**: ordene a lista pelo valor real
- **sort_stress**: ordene a lista por nível de stress

### reverse

- **reverse**: faça uma função que não altere a lista original, mas retorne uma nova lista invertida

### set e map

- **unicos**: retorne uma nova lista sem repetição de valores
- **repetidos**: retorne uma nova lista apenas com os valores repetidos

***

## Guide

- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/manipulacao/.cache/draft.cpp)
- [solver.ts](https://github.com/qxcodepoo/arcade/blob/master/base/manipulacao/.cache/draft.ts)
- [solver.java](https://github.com/qxcodepoo/arcade/blob/master/base/manipulacao/.cache/draft.java)

## Shell

```sh
#TEST_CASE get_men
$get_men [1,2,-3,4]
[1, 2, 4]
$get_men [1,-2,3,5]
[1, 3, 5]
$get_men [-1,-2,-5,-9]
[]
$end
```

```sh
#TEST_CASE get_calm_women
$get_calm_women [-10,-5,6,-90]
[-5]
$get_calm_women [-1,5,-11,-99,-8]
[-1, -8]
$end
```

```sh
#TEST_CASE sort
$sort [5,3,-1,-50,-1,-99]
[-99, -50, -1, -1, 3, 5]
$sort [-1,-50,12,8,-1,-99,-444]
[-444, -99, -50, -1, -1, 8, 12]
$end
```

```sh
#TEST_CASE sort_stress
$sort_stress [5,3,-1,-50,-1,-99]
[-1, -1, 3, 5, -50, -99]
$sort_stress [-1,-50,12,8,-1,-99,-444]
[-1, -1, 8, 12, -50, -99, -444]
$end
```

```sh
#TEST_CASE reverse
$reverse [5,3,-1,-50,-1,-99]
[-99, -1, -50, -1, 3, 5]
$reverse []
[]
$end
```

```sh
#TEST_CASE unique
$unique [1,1,1]
[1]
$unique [5,3,1,1,3,2]
[5, 3, 1, 2]
$unique [5,4,3,2,1]
[5, 4, 3, 2, 1]
$end
```

```sh
#TEST_CASE repeated
$repeated [1,1,1]
[1, 1]
$repeated [5,3,1,1,3,2]
[1, 3]
$repeated [5,4,3,2,1]
[]
$end
```
