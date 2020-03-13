## ©05_fighter Agencia Bancária 1
###

![](figura.jpg)


O objetivo dessa atividade é implementar uma classe responsável por gerenciar a conta bancária de um único cliente. Faremos operações de saque, depósito e extrato.

## Funcionalidades

- **[2.0 P] Iniciar**
    - Iniciar a conta passando número da conta.
    - Se a conta já existir, resete todos os valores para uma nova conta.
    - Verificar saldo.
- **[2.0 P] Saque, Depósito e Tarifas**
    - Verifique se o valor é válido.
    - No caso da tarifa, o valor final de saldo poderá ser negativo.
    - No caso do saque, verifique se há saldo suficiente efetuar a operação. 
- **[2.0 P] Retornar o extrato**.
    - Extrato completo
        - Retornar todas as movimentações da conta desde a abertura
        - A descrição pode ser "abertura", "saque", "deposito", "tarifa", "extorno".
        - Os saques devem ter valor negativo e os depósitos positivos.
    - Extrato parcial
      - Mostre as últimas N operações do extrato.
- **[2.0 P] Extornar tarifas**.
    - Deve ser possível extornar, pagando de volta, tarifas passando uma lista de índices.
    - Apenas efetue a operação de extorno dos índices válidos que forem tarifas.

***
## Exemplos

```bash
#__case iniciar
$init 100
$show 
conta:100 saldo:0

#__case 
$deposito 100
$deposito -10
fail: valor invalido
$show
conta:100 saldo:100

#__case debito
$saque 20
$tarifa 10
$show
conta:100 saldo:70
$saque 150
fail: saldo insuficiente
$saque 30
$tarifa 5
$deposito 5
$tarifa 1
$show
conta:100 saldo:39

#__case extrato
#extrato mostra todas as operações desde a abertura da conta
$extrato
 0: abertura:    0:    0
 1: deposito:  100:  100
 2:    saque:  -20:   80
 3:   tarifa:  -10:   70
 4:    saque:  -30:   40
 5:   tarifa:   -5:   35
 6: deposito:    5:   40
 7:   tarifa:   -1:   39

#__case extrato n
#extratoN mostra as ultimas N operacoes
$extratoN 2
 6: deposito:    5:   40
 7:   tarifa:   -1:   39

#__case extornar
$extornar 1 5 7 50
fail: indice 1 nao e tarifa
fail: indice 50 invalido

#__case novo extrato
$extrato
 0: abertura:    0:    0
 1: deposito:  100:  100
 2:    saque:  -20:   80
 3:   tarifa:  -10:   70
 4:    saque:  -30:   40
 5:   tarifa:   -5:   35
 6: deposito:    5:   40
 7:   tarifa:   -1:   39
 8:  extorno:    5:   44
 9:  extorno:    1:   45

#__case extrato tarifa
$tarifa 50
$extratoN 2
 9:  extorno:    1:   45
10:   tarifa:  -50:   -5

$end
```

***
## Raio X

````c
class Operacao
+ indice: int
+ descricao: string
+ valor: float
+ saldo: float
--
+ Operacao(indice, descricao, valor, saldo)

class Conta
- nextId: int //id da próxima operaçao
- saldo: float
- numero: int
- extrato: Operacao[]
--
+ salvarOperacao(label: string, value: float, saldo: float) // usado para alterar saldo e extrato
+ debitar(label: string, value: float): boolean //usado para saque e tarifa
+ creditar(label: string, value: float): boolean // usado para extorno e depósito
+ getExtratoN(N: int): Operacao[] //retorna as última n operacoes

````
