## ©06_jedi Agiota Gente Fina #arrays #mapas #crud
### Ptolomeu é o agiota mais carismático de MoneyVille. Sem nenhuma razão foi denunciado e acabou indo pra cadeira. A lasqueira foi que ele afirma que quem implementou o software de controle dos empréstimos e quem apagou os registro dos defuntos foi você.
![](figura.jpg)

Seu Plutolomeu é um agiota que empresta dinheiro a juros 0. Ele é uma pessoa muito carismática e amiga de todos. De sorriso largo sempre aberto, Plutolomeu é amigo da vizinhança. Inclusive esse ano, ele ganhou uma festa de aniversário surpresa de todos os seus devedores. Só quem é gente muito fina ganha festa surpresa né?

**Um, pelo menos foi isso que ele disse pra polícia quando foi pego em flagrante com 50 mil reais escondidos debaixo do colchão!**

Vamos abstrair um pouco da história de Plutolomeu e analisar o sistema de emprestimos que ele tinha instalado em seu computador.

## Funcionalidades

- Iniciar Sistema.
    - Inicia o sistema com uma certa quantidade de dinheiro.
    - Apaga todos os registros de transações que existam.
    - Inicialize o sistema com valores válidos.

- Cadastrar Clientes
    - Cada cliente tem um apelido (clienteId) que é sua chave no sistema e um nome que pode ter várias palavras.

- Emprestar Dinheiro.
    - Uma transação tem um clienteId e um valor numérico.
    - Empréstimos são salvos com valor negativo de transação.
    - Cada transação deve receber do sistema um identificador numérico crescente.
    - A primeira transação tem id 0. A segunda tem id 1 e etc.
    - Ptolomeu não pode emprestar dinheiro se não tiver dinheiro suficiente.
- Mostrar o histórico de transações.
- Mostrar cliente. 
    - Mostra apenas as transações daquele cliente e o saldo.
- Mostrar todos os clientes com o saldo de cada um.

- Receber dinheiro.
    - Clientes pagam os empréstimos aos poucos.
    - O cliente não pode pagar mais do que está devendo.

- Matar um cliente.    
    - As vezes Ptolomeu dá um chá de sumiço em quem não paga suas dívidas. Pra não deixar pontas soltas ele precisa apagar as transações do histórico e remover o cliente da lista. 
    - Apagar as transações não altera o saldo de ptolomeu.


## Exemplos

```bash
#__case init
# addCli _id _full_name
# addTr _id _value
# showAll
# showTr
# showCli _id
# matar _id


$init 500

#__case cadastrar
$addCli maria maria silva
$addCli josue josue matos
$addCli maria ana maria silva
fail: cliente ja existe

#__case emprestar
$emprestar maria 300
$emprestar josue 50
$emprestar maria 100
$emprestar bruno 30
fail: cliente nao existe
$emprestar josue 400
fail: fundos insuficientes

#__case resumo
# Mostrar todos ordenados por idCli
$resumo
josue : josue matos : 50
maria : maria silva : 400
saldo : 50

#__case historico
#######################################
# Mostrar o histórico de transações
#######################################
$historico
id:0 [maria 300]
id:1 [josue 50]
id:2 [maria 100]

#__case filtrar
#######################################
# Mostrar cliente
#######################################
$filtrar maria
id:0 [maria 300]
id:2 [maria 100]
saldo: 400

#__case receber
#######################################
# Receber dinheiro
#######################################
$receber maria 1000
fail: valor maior que a divida
$receber maria 350
$historico
id:0 [maria 300]
id:1 [josue 50]
id:2 [maria 100]
id:3 [maria -350]
$receber josue 1
$receber maria 10

#__case mais operacoes
#######################################
# Mais operacoes
#######################################
$addCli hugo hugo calingo
$emprestar hugo 10
$emprestar hugo 20
$receber maria 5
$receber josue 3

$historico
id:0 [maria 300]
id:1 [josue 50]
id:2 [maria 100]
id:3 [maria -350]
id:4 [josue -1]
id:5 [maria -10]
id:6 [hugo 10]
id:7 [hugo 20]
id:8 [maria -5]
id:9 [josue -3]

#__case matar
#######################################
# Matando
#######################################
$filtrar josue
id:1 [josue 50]
id:4 [josue -1]
id:9 [josue -3]
saldo: 46

$matar josue

$historico
id:0 [maria 300]
id:2 [maria 100]
id:3 [maria -350]
id:5 [maria -10]
id:6 [hugo 10]
id:7 [hugo 20]
id:8 [maria -5]

$resumo
hugo : hugo calingo : 30
maria : maria silva : 35
saldo : 389

$end
```

***
## Diagrama
![](diagrama.png)

## Fim da história

- Então assim ficou Ptolomeu, depois de conseguir explicar pra polícia que tudo não passou me um mal entendido. 
    - *Essa explicação custou 20.000 reais*, mas isso é detalhe, ninguém comenta.

![](ptolomeu.jpg)
