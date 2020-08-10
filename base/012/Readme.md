# Topic de Luxo ⭐⭐⭐
![](figura.jpg)

<!--TOC_BEGIN-->
- [Requisitos](#requisitos)
- [Shell](#shell)
- [Raio X](#raio-x)

<!--TOC_END-->

O objetivo dessa atividade é exercitar o que vocês aprenderam no cinema com algumas variações. Aqui, vamos implementar um sistema de alocação de passageiros em uma topic. Nossa topic tem uma quantidade máxima de passageiros, mas também define alguns assentos preferenciais.

## Requisitos
Seu sistema deverá:

- **[3.0 P] Inicializar e Mostrar.** 
    - Iniciar a topic solicitando a lotação máxima e a quantidade de cadeiras preferenciais.
    - Mostrar o estado do trem
        - Coloque @ na frente das cadeiras preferenciais
        - Coloque = na frente das cadeiras normais.
- **[5.0 P] Inserir.** 
    - Inserir passageiros informando id e idade
        - Se o passageiro for idoso:
            - Se houver cadeiras preferenciais
                - O coloque na primeira cadeira preferencia.
            - Senão
                - O coloque na primeira cadeira normal.
        - Se o passageiro não for idoso.
            - Se houver cadeiras não preferenciais
                - O coloque na primeira não preferencial.
            - Se não
                - O coloque na primeira cadeira preferencial.
- **[2.0 P] Remover.** 
    - Remover passageiros por id

***
## Shell

```bash

#######################################
#__case Inicializar
#######################################
# init _lotacao _qtd_prioritarios
$show
[ ]
$init 5 2
$show
[ @ @ = = = ]

#######################################
#__case Embarque
#######################################

$in davi 17
$show
[ @ @ =davi:17 = = ]
$in joao 103
$show
[ @joao:103 @ =davi:17 = = ]
$in ana 35
$show
[ @joao:103 @ =davi:17 =ana:35 = ]
$in rex 20
$in bia 16
$show
[ @joao:103 @bia:16 =davi:17 =ana:35 =rex:20 ]

#######################################
#__case Desembarque
#######################################

$out davi
$show
[ @joao:103 @bia:16 = =ana:35 =rex:20 ]
$in aragao 96
$show
[ @joao:103 @bia:16 =aragao:96 =ana:35 =rex:20 ]

#######################################
#__case Erros
#######################################

$in lucas 23
fail: topic lotada
$out marcelo
fail: pass nao esta na topic
$out ana
$in bia
fail: pass ja esta na topic
$show
[ @joao:103 @bia:16 =aragao:96 = =rex:20 ]
$end

#__end__
```

***
## Raio X
```java
class Pass
+ id: string
+ idade: int

class Topic
+ cadeiras: Pass[]
--
+ 



```
