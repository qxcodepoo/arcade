# @produto - Padrão Composite e Decorator

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/produto/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo produto`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

Padrões de projeto são soluções para problemas comuns que encontramos ao projetar um sistema. Eles são como receitas de bolo que podemos aplicar em nossos projetos para resolver problemas recorrentes. Os padrões de projeto são divididos em três categorias: padrões de criação, padrões estruturais e padrões comportamentais.

Vamos trabalhar os conceitos de dois padrões de projeto: Composite e Decorator, e adicionar o conceito de uma classe de controle usando o padrão Adapter.

## Composite

O padrão Composite é um padrão estrutural que permite que objetos sejam agrupados de forma a tratá-los como se fossem um único objeto. Ele permite que clientes tratem objetos individuais e composições de objetos de maneira uniforme.

## Decorator

O padrão Decorator é um padrão estrutural que permite que responsabilidades sejam adicionadas a um objeto dinamicamente. Ele permite que um objeto seja envolvido por outros objetos que adicionam comportamento a ele. É frequentemente usado para adicionar responsabilidades a objetos sem que isso cause um efeito colateral para os outros objetos.

### Exemplo

Vamos modelar um sistema de vendas de produtos. O sistema deve permitir que sejam cadastrados produtos simples e pacotes. Pacotes são o agrupamento de produtos que devem ser vendidos juntos. Produtos simples são produtos que não contêm outros produtos. Pacotes e produtos simples devem ser tratados de forma uniforme. Além disso, deve ser possível criar produtos ou pacotes com desconto, em quaisquer tipo de montagem ou configuração.

### Descrição

#### Interface IProduct

Define os métodos que todas as classes de produto devem implementar.

- `getPrice()`: Retorna o preço do produto.
- `getLabel()`: Retorna o rótulo do produto.

#### Classe Product

Implementa a interface `IProduct` e representa um produto simples.

- **Atributos:**
  - `name`: Nome do produto.
  - `price`: Preço do produto.
- **Métodos:**
  - `constructor(name: string, price: number)`: Inicializa os atributos `name` e `price`.
  - `getPrice()`: Retorna o preço do produto.
  - `getLabel()`: Retorna o nome do produto.

#### Classe Bundle

Implementa a interface `IProduct` e representa um pacote de produtos (padrão composite).

- **Atributos:**
  - `products`: Lista de produtos que compõem o pacote.
- **Métodos:**
  - `constructor(products: IProduct[] = [])`: Inicializa a lista de produtos.
  - `addProduct(product: IProduct)`: Adiciona um produto ao pacote.
  - `getPrice()`: Retorna o preço total do pacote.
  - `getLabel()`: Retorna uma string com os nomes dos produtos no pacote. Exemplo: `[bermuda, camisa, bone]`.

#### Classe DiscountedProduct

Implementa a interface `IProduct` e representa um produto com desconto (padrão decorator).

- **Atributos:**
  - `product`: O produto original.
  - `discount`: O percentual de desconto.
- **Métodos:**
  - `constructor(product: IProduct, discount: number)`: Inicializa os atributos `product` e `discount`.
  - `getPrice()`: Retorna o preço do produto com desconto.
  - `getLabel()`: Retorna uma string com o nome do produto e o desconto aplicado. Exemplo: `camisa(10% OFF)`.

#### Classe Manager

Serve para gerenciar a criação e manipulação dos produtos.

- **Atributos:**
  - `products`: Array para armazenar os produtos.
- **Métodos:**
  - `constructor()`: Inicializa o array `products`.
  - `addProduct(name: string, price: number)`: Adiciona um novo produto ao array.
  - `addBundle(indexes: number[])`: Cria um novo pacote com base nos índices fornecidos e adiciona ao array.
  - `addDiscount(index: number, discount: number)`: Adiciona um desconto a um produto existente.
  - `toString()`: Retorna uma string com informações sobre todos os produtos no array.

#### Classe Adapter

Serve como uma classe de controle, gerenciando a criação e manipulação dos produtos.

- **Atributos:**
  - `manager`: Instância da classe `Manager`.
- **Métodos:**
  - `constructor()`: Inicializa a instância de `Manager`.
  - `addProduct(label: string, price: number)`: Adiciona um novo produto ao manager.
  - `addBundle(indexes: number[])`: Adiciona um novo pacote ao manager.
  - `addDiscount(index: number, discount: number)`: Adiciona um desconto a um produto no manager.
  - `toString()`: Retorna uma string com a representação de todos os produtos no manager.

## Guide

![Diagrama de Classes](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/produto/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts

' Interface que define a responsabilidade de um produto
interface IProduct {
  + getPrice(): double
  + getLabel(): String
}

' Produto simples
class Product {
  - name: String
  - price: double
  + Product(name: String, price: double)
  + getPrice(): double
  + getLabel(): String
}

' Conjunto de produtos que são vendidos juntos
class Bundle {
  - products: List<IProduct>
  + Bundle(products: List<IProduct>)
  + addProduct(product: IProduct): void
  
  ' A soma dos preços dos produtos individuais
  + getPrice(): double

  ' A concatenação dos nomes dos produtos individuais no formato [nome1, nome2, nome3]
  + getLabel(): String
}

' Produto com desconto
class DiscountedProduct {
  - product: IProduct

  ' Valor de 0 a 100
  - discount: double

  + DiscountedProduct(product: IProduct, discount: double)
  
  ' O valor do produto original - o desconto
  + getPrice(): double

  ' O label do produto original com o desconto no formato
  ' label_original (desconto %OFF)
  + getLabel(): String
}

' Gerenciador de produtos
class ProductManager {
  - products: List<IProduct>
  + ProductManager()

  ' Adiciona um produto simples
  + addProduct(label: String, price: double): void

  ' Cria um pacote a partir de todos os índices
  + addPackage(indexes: List<int>): void

  ' Adiciona um desconto a um produto dado o índice do produto
  + addDiscount(index: int, discount: double): void

  ' Mostra os índices dos produtos, seus rótulos e preços
  + toString(): String
}

```

<!-- load -->

## Shell

```bash
#TEST_CASE criando produto simples

$add camisa 40
$add bermuda 30
$add bone 20
$show
00:camisa:40.00
01:bermuda:30.00
02:bone:20.00

#TEST_CASE criando pacote
$addPacote 0 2
$addPacote 1 1
$addPacote 0 1 2
$show
00:camisa:40.00
01:bermuda:30.00
02:bone:20.00
03:[camisa, bone]:60.00
04:[bermuda, bermuda]:60.00
05:[camisa, bermuda, bone]:90.00

#TEST_CASE criando produto com desconto
$addDesconto 0 10
$addDesconto 3 20
$addDesconto 4 15

$show
00:camisa:40.00
01:bermuda:30.00
02:bone:20.00
03:[camisa, bone]:60.00
04:[bermuda, bermuda]:60.00
05:[camisa, bermuda, bone]:90.00
06:camisa(10% OFF):36.00
07:[camisa, bone](20% OFF):48.00
08:[bermuda, bermuda](15% OFF):51.00

#TEST_CASE finalizando

# [camisa, bone](https://github.com/qxcodepoo/arcade/blob/master/base/produto/20%) + [bermuda, bermuda](https://github.com/qxcodepoo/arcade/blob/master/base/produto/15%)
$addPacote 7 8
$addDesconto 9 10
$show
00:camisa:40.00
01:bermuda:30.00
02:bone:20.00
03:[camisa, bone]:60.00
04:[bermuda, bermuda]:60.00
05:[camisa, bermuda, bone]:90.00
06:camisa(10% OFF):36.00
07:[camisa, bone](20% OFF):48.00
08:[bermuda, bermuda](15% OFF):51.00
09:[[camisa, bone](20% OFF), [bermuda, bermuda](15% OFF)]:99.00
10:[[camisa, bone](20% OFF), [bermuda, bermuda](15% OFF)](10% OFF):89.10

$end
```
