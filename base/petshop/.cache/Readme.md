# @petshop Pets

Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/petshop/Readme.md)

<!-- toch -->
[Intro](#intro) | [Draft](#draft)
-- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/petshop/cover.jpg)

Totó tá com a perna dodói. Faça o sistema da clínica veterinária para cadastrar clientes, animais, serviços e vendas.

Você deve desenvolver o sistema de uma clínica veterinária que deve ser capaz de:

***

## Intro

- Cadastrar clientes pelo idCliente
    - Id de cliente deve ser único entre os clientes
    - Cliente tem um id e um nome de múltiplas palavras
- Mostrar todos os clientes

```
# nwcli _idCli _nome_completo
nwcli luke luke skywallker
  done
nwcli lea princesa lea
  done
nwcli vader darth vader
  done
nwcli lea fracileia moreira
  fail: cliente lea ja cadastrado.
lacli
  cli luke: luke skywallker
  cli lea: princesa lea
  cli vader: darth vader

```

- Cadastrar animais.
    - Animal tem um id, um nome e uma especie e está vinculado a um único cliente.
    - Cada animal cadastrado deve receber um id único inteiro crescente do sistema.
    - Um cliente não pode ter dois animais com o mesmo nome.
- Mostrar todos os animais cadastrados.
- Mostre os clientes com seus animais.

```
# addAni _idCli _idAni _especie
nwani vader rex gato
  done
nwani vader chaninha urubu
  done
nwani vader rex dino
  fail: animal rex ja existe
lscli vader
  cli vader: darth vader [1:rex:gato][2:chaninha:urubu]
nwani luke rosinha chinchila
  done
laani
  [1:rex:gato]
  [2:chaninha:urubu]
  [3:rosinha:chinchila]
```

- Adicionar serviços na clínica.
    - Cada serviço tem um id único e um preço.
- Mostrar os serviços cadastrados

```
# addSer _idSer _preco
nwser tosa 30.0
  done
nwser banho 15.0
  done
nwser tingimento 150.0
  done
laser
  [tosa 30.0]
  [banho 15.0]
  [tingimento 150.0]
```

- Vender serviços para um animal passando id do cliente e nome do animal.
- Dê para cada venda um id inteiro único crescente.
- Mostrar vendas.
- Mostrar dinheiro total recebido.
- Trate os possíveis erros.

```
nwven luke rosinha tosa
  done
nwven vader rex banho
  done
nwven luke rosinha tingimento  
  done
nwven r2d2 rex banho
  fail: cliente r2d2 nao existe
nwven luke xuxu banho
  fail: animal xuxu nao existe
nwven luke rosinha castracao
  fail: servico castracao nao existe
laven
  [0 luke rosinha tosa]
  [1 vader rex banho]
  [2 luke rosinha tingimento]
saldo
  Saldo 195 reais
```

***

## Draft

````java
class Animal
+ idAnimal: int
+ nome: String
+ especie: String
+ dono: Cliente
--
+ constructor(idAnimal, nome, especie, dono)
+ toString()

class Cliente
+ id: String
+ nome: String
- animais: Map<String, Animal>
--
+ addAnimal(animal: Animal): void
--
+ constructor (id, nome)
+ toString()
+ getIdCliente()
+ getNome()
+ getAnimais()

class Servico
+ idServico: int
+ nome: String
+ valor: float
--
+ constructor(idServico, nome, especie)
+ toString()

class Venda
+ idAnimal: String
+ idCliente: String
+ idServico: String
--
+ constructor(idCliente, idAnimal, idServico)

class ServicoClinica
- nextSerId: int
- nextAniId: int
- nextVenId: int
- rSer: Repository<Servico>
- rAni: Repository<Animal>
- rPes: Repository<Pessoa>
- rVen: Repository<Venda>
--
+ addCliente(cliente: Cliente): void
+ addServico(nome: String, valor: String): void
+ addAnimal(idCliente: String, nomeAnimal: String, especie: String): void
+ vender(idCliente: String, nomeAnimal: String, IdServico: String): void
+ saldo(): float
+ getAllCliente(): List<Cliente>
+ getAllServico(): List<Servico>
+ getAllAnimal(): List<Animal>
+ getCliente(idCliente)
+ getServico(idServico)
+ getAnimal(idAnimal)

````
