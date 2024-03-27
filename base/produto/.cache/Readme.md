# Padrão Composite e Decorator: @produto

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/produto/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo produto`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

Padrões de projeto são soluções para problemas comuns que encontramos ao projetar um sistema. Eles são como receitas de bolo que podemos aplicar em nossos projetos para resolver problemas comuns. Os padrões de projeto são divididos em três categorias: padrões de criação, padrões estruturais e padrões comportamentais.

Vamos trabalhar os conceitos de dois padrões de projeto: Composite e Decorator.

## Composite

O padrão Composite é um padrão estrutural que permite que objetos sejam agrupados de forma a tratá-los como se fossem um único objeto. O padrão Composite permite que clientes tratem objetos individuais e composições de objetos de maneira uniforme.

## Decorator

O padrão Decorator é um padrão estrutural que permite que responsabilidades sejam adicionadas a um objeto dinamicamente. O padrão Decorator permite que um objeto seja envolvido por outros objetos que adicionam comportamento a ele. O padrão Decorator é frequentemente usado para adicionar responsabilidades a objetos sem que isso cause um efeito colateral para os outros objetos.

## Exemplo

Vamos modelar um sistema de vendas de produtos. O sistema deve permitir que sejam cadastrados produtos simples e pacotes. Pacotes são o agrupamento de produtos que devem ser vendidos juntos. Produtos simples são produtos que não contém outros produtos. Pacotes e produtos simples devem ser tratados de forma uniforme. Além disso, deve ser possível criar produtos ou pacotes com disconto, em quaisquer tipo de montagem ou configuração.

## Resolução

- Vamos criar uma interface `IProduct` que define os métodos `getPrice()` e `getLabel()`. Ela representa nosso contrato de o que uma classe deve implementar para ser considerada um produto.
- Vamos criar uma classe `Product` que implementa a interface `IProduct`.
  - Ela representa um produto simples. A classe `Product` possui os atributos `name` e `price`.
  - O método `getPrice()` retorna o preço do produto.
  - O método `getLabel()` retorna o nome do produto.
- Vamos criar uma classe `Bundle` (Pacote) que implementa a interface `IProduct`.
  - Ela ao mesmo tempo é um produto e contém produtos.
  - A classe `Bundle` possui o atributo `products` que é uma lista de produtos que ela contém.
  - O método `addProduct()` adiciona um produto na lista de produtos.
  - O método `getPrice()` retorna o preço do pacote que é calculado a partir da soma dos preços de cada um produtos que o pacote contém.
  - O método `getLabel()` retorna uma String com os nomes dos produtos contidos no pacote.
- Vamos criar uma classe `DiscountedProduct` (Produto com desconto) que implementa a interface `IProduct`.
  - Ela ao mesmo tempo é um produto e contém um produto.
  - A classe `DiscountedProduct` possui os atributos `product` e `discount`.
  - O método `getPrice()` retorna o preço do produto com desconto que é calculado a partir do preço do produto que ele contém menos o desconto.
  - O método `getLabel()` retorna uma String com o nome do produto que ele contém e o desconto.

## Draft

[draft.ts](https://github.com/qxcodepoo/arcade/blob/master/base/produto/.cache/draft.ts)

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
#__case criando produto simples

$add camisa 40
$add bermuda 30
$add bone 20
$show
00:camisa:40.00
01:bermuda:30.00
02:bone:20.00

#__case criando pacote
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

#__case criando produto com desconto
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

#__case finalizando

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
