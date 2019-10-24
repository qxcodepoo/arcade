## 03 Vetores
### Treine estrutura de dados.
![](figura.jpg)

O objetivo da atividade é treinar estrutura de dados.

---
## Funcionalidades

Requisito:
- Utilize uma estrutura de armazenamento linear que permita elementos duplicados e mantenha a ordem de inserção.
- Sugestão:
    - C: array
    - C++: vector
    - Java: ArrayList


## SHELL

```bash
#__case inicio
# O comando "$show" mostra os valores do vetor.
# O comando "$add V [V ...]" adiciona os valores no final da estrutura.
$show
[ ]
$add 1 2 3 4
$show
[ 1 2 3 4 ]
$end
```

```bash
#__case rshow
# O comando "$rshow" mostra os valores da estrutura do último para o primeiro.
$rshow
[ ]
$add 1
$rshow
[ 1 ]
$add 2 3 5
$rshow
[ 5 3 2 1 ]
$end
```

```bash
#__case add_mais_elementos
$add 4 5 6 8 1 2 2 9
$add 2 2 2 8 9 0 1 4
$add 3 3 2 1
$show
[ 4 5 6 8 1 2 2 9 2 2 2 8 9 0 1 4 3 3 2 1 ]

#__case find_elemento
# o comando "$find V [V ...]" retorna o índice da primeira ocorrência dos valores procurado ou -1 se ele não existir.
$find 7
[ -1 ]
$find 6 8 9
[ 2 3 7 ]
$find 2 0 1 7 10
[ 5 13 4 -1 -1 ]
$end
```
```bash
#__case insert_indice
# O comando "$ins ind V" insere esse valor V na posição ind da estrutura.
# Se o ind for menor que 0, não faça a inserção.
# Se ind for maior que último índice válido, insira na última posição.
# Se ind for um índice válido, desloque todos os elementos a partir dessa posição, uma posição à frente.
$add 3 7
$show
[ 3 7 ]
$ins 0 2
$show
[ 2 3 7 ]
$ins 3 1
$show
[ 2 3 7 1 ]
$ins -2 5
$show
[ 2 3 7 1 ]
$ins 9 5
$show
[ 2 3 7 1 5 ]
$ins 2 6
$show
[ 2 3 6 7 1 5 ]
$end
```

```bash
#__case remover_por_indice
# o comando "$rmi ind" remove o elemento dado o índice. Se o índice não existir, informe a falha.
$add 4 5 6 8 1 2 2 9
$rmi 0
$show
[ 5 6 8 1 2 2 9 ]
$rmi 5
$show
[ 5 6 8 1 2 9 ]
$rmi 5
$show
[ 5 6 8 1 2 ]
$rmi 2
$show
[ 5 6 1 2 ]
$rmi -1
fail
$rmi 4
fail
$show
[ 5 6 1 2 ]
$end
```

```bash
#__case remove_all
# o comando "$rma V" remove todos os elemento que contém esse valor. Observe que você deve caminhar pela estrutura UMA ÚNICA VEZ removendo os elementos. NÃO utilize find + remover por índice.
$add 2 2 2 2
$rma 2
$show
[ ]
$add 4 4 4 4 2 2 2 4 4 4 1 2 3 4
$rma 7
$show
[ 4 4 4 4 2 2 2 4 4 4 1 2 3 4 ]
$rma 2
$show
[ 4 4 4 4 4 4 4 1 3 4 ]
$rma 4
$show
[ 1 3 ]
$end
```



---

## Código base, respostas e VPL

- Código de Partida
    - [C](https://qxcodepoo.github.io/assets/vetores/base_c.c)
    - [C++](https://qxcodepoo.github.io/assets/vetores/base_cpp.cpp)
    - [Java](https://qxcodepoo.github.io/assets/vetores/Controller.java)
- Respostas
    - [C](https://qxcodepoo.github.io/assets/vetores/solver_c.c)
    - [C++](https://qxcodepoo.github.io/assets/vetores/solver_cpp.cpp)
    - [Java](https://qxcodepoo.github.io/assets/vetores/Controller_solver.java)
- Testes
    - [MD](https://qxcodepoo.github.io/assets/vetores/t.md)
- Para rodar os teste offline
    - [TH](https://github.com/senapk/th)
