```bash
#__case inicio
# O acumulador inicia em 0.
# O comando "$show" mostra o valor acumulado com duas casas decimais.
# O comando "$add V" adiciona o um valor float ao acumulador.
$show
0.00
$add 3
$add 5
$show
8.00
$end
```
```bash
#__case multiplicacao
# o comando "$mult V" multiplica o acumulado pelo valor V float.
$show
0.00
$add 4 
$mult 2.5
$mult 1.5
$show
15.00
$end
```
```bash
#__case div
# o comando "$div V" divide pelo valor. Se V for zero, informe o erro e mantenha o acumulador.
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
```
```bash
#__case addm
# o comando "$addm V [V ...]" adiciona vários valores em linha.
$show
0.00
$addm -3 -10 2 3 4 1 20 2 9
$show
$addm -1 -1 -3.2 4.3
$show
$end
```
```bash
#__case all_together_p1
$show
0.00
$add 4
$mult 1.5
$show
6.00

#__case all_together_p2
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
```
