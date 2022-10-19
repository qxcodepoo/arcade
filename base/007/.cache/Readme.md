## @007 Tarifas

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/007/cover.jpg)

[](toc)

- [Intro](#intro)
- [Guide](#guide)
- [Shell](#shell)
[](toc)

O objetivo dessa atividade é implementar uma classe responsável por gerenciar a account bancária de um único cliente. Faremos operações de withdraw, depósito e extrato.

## Intro

- **Iniciar**
  - Iniciar a account passando número da account.
  - Se a account já existir, resete todos os valores para uma nova account.
  - Inicia a account com a operação de "abertura".
  - Para facilitar a visualização dos dados, utilize inteiros para registrar as operações financeiras.
- **Saque, Depósito e Tarifas**
  - Verifique se o valor é válido.
  - No caso da tarifa, o valor final de saldo poderá ser negativo.
  - No caso do withdraw, verifique se há saldo suficiente efetuar a operação.
- **Retornar o extrato**.
  - Extrato completo
    - Retornar todas as movimentações da conta desde a abertura
    - A descrição pode ser "opening", "withdraw", "deposit", "fee", "reverse".
    - Os saques devem ter valor negativo e os depósitos positivos.
  - **Extrato parcial**
    - Mostre as últimas N operações do extrato.
- **Extornar tarifas**.
  - Deve ser possível extornar, pagando de volta, tarifas passando uma lista de índices.
  - Apenas efetue a operação de extorno dos índices válidos que forem tarifas.

***

## Guide

Os gets e sets estão marcados em separado para facilitar a visualização dos métodos importantes.

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/007/diagrama.png)

[](load)[](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/007/diagrama.puml)[](plantuml:fenced:filter)

```plantuml
class Account {
  - balanceManager : BalanceManager
  - id : int
  __
  + Account(id : int)

  ' adiciona valor à conta
  + deposit(label : Label, value : int) : boolean

  ' retira o dinheiro, mesmo que o balance fique negativo
  + fee(value : int) : boolean

  ' se o índice for válido e representar uma operação de fee
  ' adicione o mesmo valor tarifado, mas com label de reverse
  + reverse(index : int) : boolean

  ' só realiza a operação se houver dinheiro suficiente na conta
  + withdraw(value : int) : boolean
  + toString() : String
  __
  + getBalanceManager() : BalanceManager
}
'
' nessa classe são efetivadas e registradas as alterações no saldo
class BalanceManager {
  - balance : int
  - extract : List<Operation>
  - nextId : int
  __
  + BalanceManager()

  ' adiciona value ao balance
  ' crie operação e adiciona ao vetor de operações
  ' incrementa o nextId
  + addOperation(label : Label, value : int)
  + toString() : String
  __
  + getBalance() : int

  ' metodo sobrescrito para retornar apenas as últimas qtdOp operações
  + getExtract() : List<Operation>
  + getExtract(qtdOp : int) : List<Operation>
}
'
' essa enumeração guarda possíveis labels para as operações
enum Label {
  + deposit {static}
  + fee {static}
  + opening {static}
  + reverse {static}
  + withdraw {static}
  - name : String
  __
  + valueOf(name : String) : Label {static}
  + values() : Label[] {static}
  + toString() : String
  __
  + getName() : String
}
'
' operação guarda os dados de uma única operação
class Operation {
  - balance : int
  - index : int
  - label : Label

  ' valor em negativo se for débito
  - value : int
  __
  + Operation(index : int, label : Label, value : int, balance : int)

  ' faz o preenchimento da string com espaços em branco até completar o length
  + pad(string : String, length : int) : String {static}
  + toString() : String
  __
  + getBalance() : int
  + getIndex() : int
  + getLabel() : Label
  + getValue() : int
}

```

[](load)

***

## Shell

```bash
#__case iniciar
$init 100
$show 
account:100 balance:0

#__case depositar
$deposit 100
$deposit -10
fail: invalid value
$show
account:100 balance:100

#__case debito
$withdraw 20
$fee 10
$show
account:100 balance:70
$withdraw 150
fail: insuficient balance
$withdraw 30
$fee 5
$deposit 5
$fee 1
$show
account:100 balance:39

#__case extrato
#extrato mostra todas as operações desde a abertura da account
$extract
 0:  opening:    0:    0
 1:  deposit:  100:  100
 2: withdraw:  -20:   80
 3:      fee:  -10:   70
 4: withdraw:  -30:   40
 5:      fee:   -5:   35
 6:  deposit:    5:   40
 7:      fee:   -1:   39

#__case extrato n
#extratoN mostra as ultimas N operacoes
$extractN 2
 6:  deposit:    5:   40
 7:      fee:   -1:   39

#__case extornar
$reverse 1 5 7 50
fail: index 1 is not a fee
fail: index 50 invalid

#__case novo extrato
$extract
 0:  opening:    0:    0
 1:  deposit:  100:  100
 2: withdraw:  -20:   80
 3:      fee:  -10:   70
 4: withdraw:  -30:   40
 5:      fee:   -5:   35
 6:  deposit:    5:   40
 7:      fee:   -1:   39
 8:  reverse:    5:   44
 9:  reverse:    1:   45

#__case extrato tarifa
$fee 50
$extractN 2
 9:  reverse:    1:   45
10:      fee:  -50:   -5

$end
```
