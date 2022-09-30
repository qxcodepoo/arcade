## @028 Bilheteria

![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/028/cover.jpg)

[](toc)

- [Requisitos](#requisitos)
- [Diagrama](#diagrama)
- [Main não interativa](#main-não-interativa)
[](toc)

Fazer vendas usando papel e caneta é coisa do passado. Você foi contratado para modernizar a bilheteria do seu bairro e trazer ela pro século XXI

Você deve desenvolver um sistema para gerenciar as vendas de uma bilheteria de shows.

## Requisitos

- Cadastrar uma pessoa pelo nome.
    - nome da pessoa é único
    - a pessoa pode ou não pagar meia
- Mostrar todos os clientes

```sh
#__case cadastro pessoas
# addPessoa _nome _meia
$addPessoa steve inteira
$addPessoa tony meia
$addPessoa steve meia
fail: pessoa steve ja existe
$pessoas
[steve, inteira]
[tony, meia]

#- Cadastrar evento pelo nome.
#    - Assim como pessoa, nome do evento é único
#    - Um evento pode ter vários setores
#- Cadastrar setor pelo nome.
#    - Setor tem nome e preço
#    - Setores do MESMO EVENTO não podem ter o mesmo nome
#- Mostrar evento e setores de um evento cadastrados

#__case cadastro eventos e setores

# addEvento _nome
$addEvento orappa
# addSetor _nome-evento _nome _preco _capacidade
$addSetor orappa front 70 5
$addSetor orappa pista 35 3
$eventos
orappa
- [front:70.0:0/5]
- [pista:35.0:0/3]

# addEvento _nome
$addEvento discoteca
# addSetor _nome-evento _nome _preco
$addSetor discoteca camarote 100 5
$addSetor discoteca arquibancade 50 2
$eventos
discoteca
- [arquibancade:50.0:0/2]
- [camarote:100.0:0/5]
orappa
- [front:70.0:0/5]
- [pista:35.0:0/3]

#- Realizar venda
#    - Uma venda deve ter pessoa, evento, setor
#    - O identificador único da venda é o nome do cliente(Pessoa)
#    - O valor da venda deve ser contabilizado em um caixa
#- Mostrar vendas realizadas e o valor atual em caixa

#__case vender ingressos

# vender _Pessoa _Evento _Setor
$vender tony orappa front
$vendas
[tony, orappa, front]
R$ 35.0

$vender steve orappa camarote
fail: setor camarote nao existe

$vender steve orappa front
$vendas
[tony, orappa, front]
[steve, orappa, front]
R$ 105.0

$eventos
discoteca
- [arquibancade:50.0:0/2]
- [camarote:100.0:0/5]
orappa
- [front:70.0:2/5]
- [pista:35.0:0/3]

$end
```
***
## Diagrama

![](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/028/diagrama.png)
 
---

## Main não interativa

```java
Bilheteria bilheteria = new Bilheteria();
bilheteria.addPessoa(new Pessoa("steve", 32, false));
bilheteria.addPessoa(new Pessoa("steve", 32, false));
bilheteria.addPessoa(new Pessoa("tony", 43, true));
bilheteria.addPessoa(new Pessoa("steve", 24, true));
//fail: pessoa steve ja existe
bilheteria.showPessoas();
//[tony, 43, sim],
//[steve, 32, nao]

bilheteria.addEvento(new Evento("orappa"));
bilheteria.addSetor("orappa", new Setor("front", 70f));
bilheteria.addSetor("orappa", new Setor("pista", 35));
bilheteria.showEvento();
//[orappa]
bilheteria.showSetor("orappa");
//[front],
//[pista]

bilheteria.vender("tony", "orappa", "front");
bilheteria.vender("steve", "orappa", "camarote");
//fail: setor camarote nao existe

bilheteria.showVenda();
//[tony, orappa, front, 35,00]

bilheteria.showCaixa();
//R$ 35,00
```