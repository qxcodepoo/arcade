# @busca - Operações I

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/busca/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo busca`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

<!-- toch -->
[Intro](#intro) | [Draft](#draft) | [Shell](#shell) | [Alien](#alien)
-- | -- | -- | --
<!-- toch -->

![cover](https://gist.github.com/assets/4747652/c22c464a-b797-4bd7-b963-4e4f1ee7f96b)

***

## Intro

- Na entrada de um evento de um experimento social, os participantes ganhavam uma pulseira especial que precisavam ficar utilizando.
- A pulseira informava, num pequeno visor, um número inteiro que representava o nível de stress daquele participante.
- O número 1 significava totalmente tranquilo e vai aumentando conforme o stress do participante aumentava até o valor máximo de infinito.
- Para fazer uma representação lógica de homens e mulheres em um vetor de inteiros, os números positivos representam os homens e os números negativos representam mulheres.
- Precisamos escrever os algoritmos que identifiquem informações importantes sobre os participantes da fila.

**Exemplos:**

- `{}` equivale a uma fila vazia.
- `{-1, -50, -99}` equivale a uma mulher totalmente tranquila, uma mulher médio estressada e uma mulher extremamente estressada.
- `{80, 70, 90, -4}` equivale a três homens estressados e uma mulher tranquila.

**Funções**:

- **in**: existe determinado valor na fila?
- **index_of**: qual posição aparece X na fila pela primeira vez?
- **find_if**: qual a posição do primeiro valor positivo da fila?
- **min_element**: qual a posição do menor valor da lista?
- **find_min_if**: qual a posição do menor valor positivo?

***

## Draft

- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/busca/.cache/draft.cpp)
- [solver.ts](https://github.com/qxcodepoo/arcade/blob/master/base/busca/.cache/draft.ts)
- [Solver.java](https://github.com/qxcodepoo/arcade/blob/master/base/busca/.cache/draft.java)

## Shell

```sh
#TEST_CASE in
$in [1,2,3,4] 4
true
$in [1,2,3,5] 1
true
$in [1,2,5,9] 7
false
$end
```

```sh
#TEST_CASE index_of
$index_of [-1,-50,-1,-99] -50
1
$index_of [-1,-50,-1,-99] -99
3
$index_of [-1,-50,-1,-99] 10
-1
$end
```

```sh
#TEST_CASE find_if
$find_if [5,3,-1,-50,-1,-99]
0
$find_if [-1,-50,-1,-99,-444]
-1
$end
```

```sh
#TEST_CASE min_element
$min_element [5,3,-1,-50,-1,-99]
5
$min_element [-1,-50,-1,-99,-444]
4
$min_element [-2,5,3,-1,50,-1]
0
$min_element []
-1
$end
```

```sh
#TEST_CASE find_min_if
$find_min_if [5,3,-1,-50,-1,-99]
1
$find_min_if [-1,-50,-1,-99,-444]
-1
$end
```

## Alien

[![_](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/busca/../../wiki/images/alien3.jpg)](https://www.youtube.com/watch?v=2b3WvsJHa0Y)
