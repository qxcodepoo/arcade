# Crie as contas poupança e corrente

<!-- toch -->
[Vídeo](#vídeo) | [Intro](#intro) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | -- | --
<!-- toch -->

![cover](assets/cover.webp)

O objetivo dessa atividade é implementar uma agência bancária simplificada. Deve ser capaz de cadastrar cliente. Cada cliente inicia com uma conta poupança e uma conta corrente. Contas correntes tem taxa de administração e contas poupanças rendem juros.

## Vídeo

[![_](assets/video.webp)](https://youtu.be/AfJ--C8ZqPY)

## Intro

- Cadastrar um cliente com idCliente único
  - Quando o cliente é cadastrado no sistema, automaticamente é aberta uma conta corrente e uma conta poupança para ele.
- Mensalmente:
  - Contas corrente vão receber uma tarifa de **20 reais** podendo inclusive ficar negativas.
  - Contas poupança vão aumentar de 1 porcento.
- Sua agência deve ter um mapa de clientes e um mapa de contas.
- O cliente só tem duas contas, mas imagine que no futuro ele poderá ter várias.
- As contas devem ser tratadas utilizando polimorfismo.

## Draft

<!-- links .cache/drafts -->
- cpp
  - [shell.cpp](.cache/drafts/cpp/shell.cpp)
- java
  - [Shell.java](.cache/drafts/java/Shell.java)
- ts
  - [shell.ts](.cache/drafts/ts/shell.ts)
<!-- links -->

## Guide

![diagrama](assets/diagrama.webp)

[![youtube icon](../youguide.webp)](https://youtu.be/2Mk5c6p-d20?si=M2XqjolrOL7Hw-C3)


## Shell

```bash
#TEST_CASE first clients
# addCli _idCliente
# adiciona um cliente na lista de clientes.
# cria uma conta poupança e uma conta corrente para cada cliente usando numeração de forma sequencial.
$addCli Almir
$addCli Julia
$addCli Maria

# show mostra as contas do banco, com id:usuario:saldo:tipo
# em tipo use CC para conta corrente e CP para conta poupança.
$show
- Clients
Almir [0, 1]
Julia [2, 3]
Maria [4, 5]
- Accounts
0:Almir:0.00:CC
1:Almir:0.00:CP
2:Julia:0.00:CC
3:Julia:0.00:CP
4:Maria:0.00:CC
5:Maria:0.00:CP

######################################
#TEST_CASE operações básicas
#faça as operações básicas de saque, depósito e transferência entre contas
#verifique se as contas existem antes de efetuar as operações
# $saque _conta _value
# para sacar verifique o saldo
#
# $deposito _conta _value
#
# $transf _contaDe _contaPara _value

$deposito 0 100
$deposito 1 200
$deposito 2 50
$deposito 3 300
$saque 3 50
$saque 0 70
$saque 1 300
fail: saldo insuficiente

$show
- Clients
Almir [0, 1]
Julia [2, 3]
Maria [4, 5]
- Accounts
0:Almir:30.00:CC
1:Almir:200.00:CP
2:Julia:50.00:CC
3:Julia:250.00:CP
4:Maria:0.00:CC
5:Maria:0.00:CP

$transf 3 5 200
$transf 0 4 25
$transf 9 1 30
fail: conta nao encontrada
$transf 2 8 10
fail: conta nao encontrada

$show
- Clients
Almir [0, 1]
Julia [2, 3]
Maria [4, 5]
- Accounts
0:Almir:5.00:CC
1:Almir:200.00:CP
2:Julia:50.00:CC
3:Julia:50.00:CP
4:Maria:25.00:CC
5:Maria:200.00:CP

#TEST_CASE update mensal
# No comando update todas as contas serão atualizadas.
# Contas corrente vão receber uma tarifa de 20 reais podendo inclusive ficar negativas.
# Contas poupança vão aumentar de 1 porcento.
$update

$show
- Clients
Almir [0, 1]
Julia [2, 3]
Maria [4, 5]
- Accounts
0:Almir:-15.00:CC
1:Almir:202.00:CP
2:Julia:30.00:CC
3:Julia:50.50:CP
4:Maria:5.00:CC
5:Maria:202.00:CP

$end

```
