## 01 Shell, entendendo comandos.
### Aprenda o modelo de comandos
![](figura.jpg)

O objetivo da atividade é treinar é aprender o modelo de comandos. Para isso você vai implementar uma calculadora simples que contém um único registrador. 

---
## Funcionalidades
O modelo de comandos é um modelo de vários comandos dentro de um contexto persistente.
- Você pode imaginar o terminal ou o prompt de comando.
- A primeira palavra é o comando e as outras são os parâmetros do comando.
- Um comando pode gerar ou não uma saída.

---
## Programa
- Você implementará uma calculadora persistente com uma série de comandos.
- Na tabela abaixo você pode ver a entrada do sistema e a saída esperada.
- Observe que a linha do comando de entrada é repetida na saída.
    - O objetivo é facilitar o debug de testes com uma grande quantidade de comandos.

___
## SHELL

- O acumulador inicia em 0.
- O comando "show" mostra o valor acumulado com duas casas decimais.
- O comando "add V" adiciona o um valor `V` float ao acumulador.
- O comando "end" finaliza a execução. 

```sh
>>>>>>>> soma
show
add 3
add 5
show
end
========
$show
0.00
$add 3
$add 5
$show
8.00
$end
<<<<<<<<<
```

- O comando "`mult V`" multiplica o acumulado pelo valor V float.

```bash
>>>>>>>> multi
show
add 4 
mult 2.5
mult 1.5
show
end
========
$show
0.00
$add 4 
$mult 2.5
$mult 1.5
$show
15.00
$end
<<<<<<<<
```

- o comando "`div V`" divide o acumulado pelo valor. Se V for zero, informe o erro e mantenha o acumulador.

```bash
>>>>>>>> div
show
add 4 
mult 2.2
div 2
show
div 0
show
end
========
$show
0.00
$add 4 
$mult 2.2
$div 2
$show
4.40
$div 0
fail: division by zero
$show
4.40
$end
<<<<<<<<
```


- o comando "`addm V [V ...]`" adiciona vários valores em linha.

```ruby
>>>>>>>> addm
show
addm -3 -10 2 3 4 1 20 2 9
show
addm -1 -1 -3.2 4.3
show
end
========
$show
0.00
$addm -3 -10 2 3 4 1 20 2 9
$show
28.00
$addm -1 -1 -3.2 4.3
$show
27.10
$end
<<<<<<<<
```

```ruby
>>>>>>>> 01 all_together_p1
show
add 4
mult 1.5
show
end
========
$show
0.00
$add 4
$mult 1.5
$show
6.00
$end
<<<<<<<<
```

```ruby
>>>>>>>> 05 all_together_p2 !%
show
add 4
mult 1.5
show
div 4
show
addm 1 3 -1
show
addm -3 -10 2 3 4 1 20 2 9
show
div 0
show
end
========
$show
0.00
$add 4
$mult 1.5
$show
6.00
$div 4
$show
1.50
$addm 1 3 -1
$show
4.50
$addm -3 -10 2 3 4 1 20 2 9
$show
32.50
$div 0
fail: division by zero
$show
32.50
$end
<<<<<<<<
```

---
## Testando seu código
- Você pode utilizar o Moodle ou testar diretamente no seu computador.
- O script `th` permite você testar seu código utilizando os testes. Você pode instalá-lo através do link [https://github.com/senapk/th](https://github.com/senapk/th).

Se você está programando em Java, não utilize nenhum pacote. Se o arquivo que contém a main for o Controller.java você poderia rodar os testes com:

```
th run "java Controller.class" t.md -v
```

A saída esperada quando todos os testes dão certo é algo como:

```
th run "java Controller.class" t.md  -v
###############################################################################################################
                                                     Run:
! GR: --- SUCCEED [01] t.md (inicio)
! GR: --- SUCCEED [02] t.md (multiplicacao)
! GR: --- SUCCEED [03] t.md (div)
! GR: --- SUCCEED [04] t.md (all_together_p1)
! GR: --- SUCCEED [05] t.md (all_together_p2)
                                             You have no failures!
###############################################################################################################
                                                Final Grade:100
                                              Time: 0.02 segundos
```


---

## Código base, respostas e VPL

- Respostas
    - [C](https://qxcodepoo.github.io/assets/shell/code.c)
    - [C++](https://qxcodepoo.github.io/assets/shell/solver.cpp)
    - [Java](https://qxcodepoo.github.io/assets/shell/Solver.java)
- Testes
    - [MD](https://qxcodepoo.github.io/assets/shell/t.md)
- Para rodar os teste offline
    - [TH](https://github.com/senapk/th)
