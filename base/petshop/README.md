# @petshop

<!-- toch -->
[Intro](#intro) | [Draft](#draft)
-- | --
<!-- toch -->

![cover](cover.jpg)

Totó tá com a perna dodói. Faça o sistema da clínica veterinária para cadastrar clientes, animais, serviços e vendas.

Você deve desenvolver o sistema de uma clínica veterinária que deve ser capaz de:

***

## Intro

- Cadastrar clientes pelo idCliente
  - Id de cliente deve ser único entre os clientes
  - Cliente tem um id e um nome de múltiplas palavras
- Mostrar todos os clientes

```
#TEST_CASE client rep
# nwcli _idCli _nome_completo
$addcli luke luke skywallker
$addcli lea princesa lea
$addcli vader darth vader
$addcli lea fracileia moreira
fail: cliente lea ja cadastrado.
$getcli lea
lea:princesa lea
$show
luke:luke skywallker
lea:princesa lea
vader:darth vader
$delcli luke
$show
lea:princesa lea
vader:darth vader
$end
```

- Cadastrar animais.
  - Animal tem um id, um nome e uma especie e está vinculado a um único cliente.
  - Um cliente não pode ter dois animais com o mesmo nome.
- Mostrar todos os animais cadastrados.
- Mostre os clientes com seus animais.

```
#TEST_CASE animal rep
# addpet _idCli _idAni _especie
$addcli vader darth vader
$addpet vader rex gato
$addpet vader chaninha urubu
$addpet vader rex dino
fail: animal rex ja existe
$show
vader: darth vader [1:rex:gato][2:chaninha:urubu]
```

- Adicionar serviços na clínica.
  - Cada serviço tem um id único e um preço.
- Mostrar os serviços cadastrados

```
#TEST_CASE service rep
# addser _idSer _preco
$addser tosa 30.0
$addser banho 15.0
$addser tingimento 150.0
$listser
tosa:30.0
banho:15.0
tingimento:150.0
#end
```

- Vender serviços para um animal passando id do cliente e nome do animal e o id do serviço
- Dê para cada venda um id inteiro único crescente.
- Mostrar vendas.
- Mostrar dinheiro total recebido.
- Trate os possíveis erros.

```
#TEST_CASE venda rep
# sell _idCli _idPet _idSer
$addcli vader darth vader
$addpet vader rex gato
$addpet vader chaninha urubu
$addser tosa 30.0
$addser banho 15.0
$addser tingimento 150.0
$sell vader rex banho
$sell luke rosinha tingimento  
$sell r2d2 rex banho
fail: cliente r2d2 nao existe
sell luke xuxu banho
fail: animal xuxu nao existe
sell luke rosinha castracao
fail: servico castracao nao existe
$listsell
0:luke:rosinha:tosa
1:vader:rex:banho
2:luke:rosinha:tingimento
$balance
195.0
$end
```

***

## Draft

```java
class Pet {
+ idPet: String
+ especie: String
--
+ Pet(idPet: String, especie: String)
+ toString(): String
}

class Client {
+ idClient: String
+ pets: Map<String, Pet>
--
+ Client (idClient: String)
+ toString(): String
--
+ addPet(pet: Pet): void
+ getPet(idPet: String): Pet
+ delPet(idPet: String): void
+ listPets(): List<Pet>
}

class Service {
+ idService: String
+ price: float
--
+ Service(idService: String, price: float)
+ toString(): String
}

class Sale {
+ idSale: int
+ idClient: String
+ idPet: String
+ idService: String
--
+ Sale(idClient: String, idPet: String, idService: String)
+ toString(): String
}

class Clinic {
+ nextSaleId: int
+ repServices: Map<String, Service>
+ repClients: Map<String, Client>
+ repSales: Map<Integer, Sale>
--
+ addClient(cliente: Cliente): void
+ getClient(idClient: String): Client
+ delClient(idClient: String): void
+ listClients(): List<Client>
--
+ addService(nome: String, valor: String): void
+ getService(idService: String): Service
+ delService(idService: String): void
+ listServices(): List<Service>
--
+ sell(idCliente: String, nomeAnimal: String, IdServico: String): void
+ listSales(): List<Sale>
+ balance(): float
}
````
