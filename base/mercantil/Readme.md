## 50 Mercantil #interfaces #composite #decorator
###
![](figura.jpg)


```bash
#__case cadastro de produtos
# O comando "$addPr id:desc:price [id:desc:price ...] " adiciona produtos informando o ID, a descrição e o PREÇO BASE.
# Se o produto com esse id já existir,informe o erro e interrompa o cadastro dos produtos.
# O comando "$showPr" mostra todos os produtos cadastrados ordenando pelo id
$addPr 1:veja:3.50 2:bombril:4.00 3:rodo:15.00 4:balde:2.00 5:limpol:5.00
$addPr 6:vassoura:7:50
$show
[1:veja:3.50]
[2:bombril:4.00]
[3:rodo:15.00]
[4:balde:2.00]
[5:limpol:5.00]
[6:vassoura:7.50]

$addPr 7:esponja:5.00 1:vega:4:20 9:pepaconha:4:40
fail: id 1 ja existe

$show
[1:veja:3.50]
[2:bombril:4.00]
[3:rodo:15.00]
[4:balde:2.00]
[5:limpol:5.00]
[6:vassoura:7.50]
[7:esponja:5.00]

#__case cadastro de pacotes
# Um pacote é um item que contém outros itens.
# Para cadastrar um pacote é necessário informar o ID do pacote e a lista dos itens que o compõe com as respectivas quantidades. Note que um pacote pode conter outros pacotes.
# A descrição de um pacote é formada pela descrição de seus itens com as respectivas quantidades
# O preço do pacote é a soma do preço dos itens.
# "addPac idPac idItem:qtd [idItem:qtd ...]
$addPac 8 3:1 4:1 6:1
$addPac 9 5:2 1:2 2:2
$addPac 10 7:3 8:1 9:1
$show
[1:veja:3.50]
[2:bombril:4.00]
[3:rodo:15.00]
[4:balde:2.00]
[5:limpol:5.00]
[6:vassoura:7.50]
[7:esponja:5.00]
[8:(rodo)x1(balde)x1(vassoura)x1:24.50]
[9:(limpol)x2(veja)x2(bombril)x4:33.00]
[10:(esponja)x3((rodo)x1(balde)x1(vassoura)x1)x1((limpol)x2(veja)x2(bombril)x4)x1:72.50]

#__case promocoes
# Uma promoção pode ser aplicada a qualquer item. Ela exige um novo id de item pois cria um novo item vendável.
# O comando "$addPro id idItem porcentagem" cria um novo item como promoção de um item que existe.
# A descrição é a descrição do item com a tag da porcentagem. O novo preço a atualização do preço do item.
addPro 11 2 30
addPro 12 8 20
$show
[1:veja:3.50]
[2:bombril:4.00]
[3:rodo:15.00]
[4:balde:2.00]
[5:limpol:5.00]
[6:vassoura:7.50]
[7:esponja:5.00]
[8:(rodo)x1(balde)x1(vassoura)x1:24.50]
[9:(limpol)x2(veja)x2(bombril)x4:33.00]
[10:(esponja)x3((rodo)x1(balde)x1(vassoura)x1)x1((limpol)x2(veja)x2(bombril)x4)x1:72.50]
[11:(bombril)-30%:2.80]
[12:((rodo)x1(balde)x1(vassoura)x1)-20%:26.40]

#__case combinado
$addPac 13 11:3
$show
[1:veja:3.50]
[2:bombril:4.00]
[3:rodo:15.00]
[4:balde:2.00]
[5:limpol:5.00]
[6:vassoura:7.50]
[7:esponja:5.00]
[8:(rodo)x1(balde)x1(vassoura)x1:24.50]
[9:(limpol)x2(veja)x2(bombril)x4:33.00]
[10:(esponja)x3((rodo)x1(balde)x1(vassoura)x1)x1((limpol)x2(veja)x2(bombril)x4)x1:72.50]
[11:(bombril)-30%:2.80]
[12:((rodo)x1(balde)x1(vassoura)x1)-20%:26.40]
[13:((bombril)-30%)x3:8.4]


#__case estoque
# O estoque da nossa loja online é abastecido com produtos. Para inserir elementos no estoque é necessário que os IDs sejam apenas de produtos simples, não de pacotes ou promoções.
# O comando "$addEst id:qtd [id:qtd ...] adiciona itens ao estoque.
# O comando "$showEst" mostra os itens do estoque com suas respectivas descrições e quantidades, ordenado por id.
# Mostre apenas os itens que contem pelo menos uma unidade.
$addEst 1:10 3:5 4:10 9:50 7:10
$showEst
[1:veja:10U]
[3:rodo:5U]
[4:balde:10U]
[7:esponja:10U]
[9:limpol:50U]


#__case info
# O comando "$info id" descreve o item apresentando os produtos que ele contem agrupados por id.
$addPac 14 4:2 12:10 8:1
$show
[1:veja:3.50]
[2:bombril:4.00]
[3:rodo:15.00]
[4:balde:2.00]
[5:limpol:5.00]
[6:vassoura:7.50]
[7:esponja:5.00]
[8:(rodo)x1(balde)x1(vassoura)x1:24.50]
[9:(limpol)x2(veja)x2(bombril)x4:33.00]
[10:(esponja)x3((rodo)x1(balde)x1(vassoura)x1)x1((limpol)x2(veja)x2(bombril)x4)x1:72.50]
[11:(bombril)-30%:2.80]
[12:((rodo)x1(balde)x1(vassoura)x1)-20%:26.40]
[13:((bombril)-30%)x3:8.4]
[14:(balde)x2((bombril)-30%)x10(((rodo)x1(balde)x1(vassoura)x1)-20%)x1:58.40]

$info 4
4:(balde)x1
$info 14
2:(bombril)x10
4:(balde)x3
3:(rodo)x1
6:(vassoura)x1

#__case vitrine
# A vitrine virtual é composta dos itens que o gerente escolhe colocar para vender no site.
# O comando "$addVit id [id ...]" adiciona itens à vitrine.
# O comando "$showVit" mostra os itens da vitrine.
$addVit 1 3 4 5 6 10 11 13 14
$showVit
[1:veja:3.50]
[3:rodo:15.00]
[4:balde:2.00]
[5:limpol:5.00]
[6:vassoura:7.50]
[10:(esponja)x3((rodo)x1(balde)x1(vassoura)x1)x1((limpol)x2(veja)x2(bombril)x4)x1:72.50]
[11:(bombril)-30%:2.80]
[13:((bombril)-30%)x3:8.4]
[14:(balde)x2((bombril)-30%)x10(((rodo)x1(balde)x1(vassoura)x1)-20%)x1:58.40]

#__case carrinho
# Sempre que um cliente acessa a loja é criado um carrinho virtual para ele. O cliente pode adicionar e remover itens da vitrine para o carrinho. 
# Para garantir a confiabilidade da loja, quando um cliente adiciona itens ao carrinho, o sistema deve assegurar que outra pessoa não possa comprar esses itens enquanto o primeiro cliente não devolver os itens, ou cancelar o carrinho.
# O comando "$carNew idCar" cria um novo carrinho com esse id de carrinho.
# O comando "$carAdd idCar idItem:qtd [idItem:qtd ...]" tenta transferir esses itens do estoque para o carrinho.
# O comando "$carDel" desiste da compra e devolve os produtos
# O comando "$carBuy" finaliza a compra e remove os produtos definitivamente do estoque
# Se não existirem itens suficientes informe.
$carNew car1
$carNew car2
$carAdd car1 1:7
$carAdd car2 1:7
fail: qtd indisponível

$showEst
[1:veja:10U]
[3:rodo:5U]
[4:balde:10U]
[7:esponja:10U]
[9:limpol:50U]

$carDel car1
$carAdd car2 1:7 3:5
$carAdd car2 14:1
fail: qtd indisponível
$carBuy car2
$showEst
[1:veja:3U]
[4:balde:10U]
[7:esponja:10U]
[9:limpol:50U]


```
