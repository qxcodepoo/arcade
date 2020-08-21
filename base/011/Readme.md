# JunkFood Machine
![](figura.jpg)

<!--TOC_BEGIN-->
- [Requisitos](#requisitos)
- [Shell](#shell)
- [Raio X](#raio-x)
- [Ajuda](#ajuda)

<!--TOC_END-->

Máquinas de junk food só servem pra 2 coisas, 1 vender comidas que fazem mal pra saúde, 2 rejeitar as notas velhas que você tem.

O objetivo dessa atividade é implementar uma classe responsável por uma máquina de vender JunkFood. Na máquina existem várias espirais. Uma espiral contém uma certa quantidade de produtos do mesmo tipo e mesmo preço. O usuário coloca o dinheiro, compra o produto e recebe o troco.

## Requisitos

Seu sistema deverá ser capaz de:

- **[3.0 P] Iniciando a máquina** 
    - Iniciar a máquina definindo o número de espirais e a quantidade máxima de produtos em uma espiral.
        - Se já houver uma máquina, então apague tudo e inicie uma nova máquina.
    - Mostrar o conteúdo de cada espiral
        - indice, nome do produto, quantidade de produtos e preço.
        - Coloque um "-" no nome do produto para informar que não há produto definido.

- **[2.0 P] Algo pra comer** 
    - Definir quais produtos há em cada espiral passando as informações do produto.
- **[2.0 P] Resetar uma espiral** 
    - Limpar todas as informações da espiral voltando ao seu estado original. 
    - Tratar os erros de indice inválido e máximo de produtos estourado.

- **[1.0 P] Dinheiro vai** 
    - Inserir dinheiro na espiral.
        - Abstraia como o dinheiro vai. Crédito, débito, bitcoin, cédula nova ou velha, ficha de fliperama. Não importa.
        - Receber o dinheiro do usuário e vá adicionando ao saldo.
        - Alterar o mostrar máquina para mostrar o saldo também.

- **[2.0 P] Comida vem, Dinheiro vem, Erros também** 
    - Permitir que o cliente possa comprar um produto de uma espiral.
        - Verificar se existe o produto e se o valor do pagamento é suficiente.
        - Tratar todos esses erros.
        - Mostrar o nome do produto que ele pediu.
    - Quando o cliente pedir o troco, mostre o quanto ele tinha de saldo e zere o saldo.

***
## Shell

```bash
#__case init

# init _espirais _max_produtos
$init 3 5
$show
saldo: 0.00
0 [   empty : 0 U : 0.00 RS]
1 [   empty : 0 U : 0.00 RS]
2 [   empty : 0 U : 0.00 RS]

#__case inserindo comida
# set _ind _nome _qtd _valor 
$set 2 todinho 3 2.50
$show
saldo: 0.00
0 [   empty : 0 U : 0.00 RS]
1 [   empty : 0 U : 0.00 RS]
2 [ todinho : 3 U : 2.50 RS]

$set 0 tampico 1 1.50
$set 1 xaverde 3 5.00
$show   
saldo: 0.00
0 [ tampico : 1 U : 1.50 RS]
1 [ xaverde : 3 U : 5.00 RS]
2 [ todinho : 3 U : 2.50 RS]

#__case limpando
# limpar _ind
$limpar 2
$show
saldo: 0.00
0 [ tampico : 1 U : 1.50 RS]
1 [ xaverde : 3 U : 5.00 RS]
2 [   empty : 0 U : 0.00 RS]
$set 4 ovo 2 4.30
fail: indice nao existe
$set 0 farofa 50 3.00
fail: limite excedido

#__case dinheiro
# dinheiro _valor
$dinheiro 5
$dinheiro 4
$show   
saldo: 9.00
0 [ tampico : 1 U : 1.50 RS]
1 [ xaverde : 3 U : 5.00 RS]
2 [   empty : 0 U : 0.00 RS]

#__case troco
$troco
voce recebeu 9.00 RS
$show
saldo: 0.00
0 [ tampico : 1 U : 1.50 RS]
1 [ xaverde : 3 U : 5.00 RS]
2 [   empty : 0 U : 0.00 RS]
$dinheiro 8

#__case comprar
# comprar _ind
$comprar 1
voce comprou um xaverde
$comprar 1
fail: saldo insuficiente
$comprar 0
voce comprou um tampico
$show
saldo: 1.50
0 [ tampico : 0 U : 1.50 RS]
1 [ xaverde : 2 U : 5.00 RS]
2 [   empty : 0 U : 0.00 RS]
$comprar 0
fail: espiral sem produtos
$comprar 4
fail: indice nao existe
$troco
voce recebeu 1.50 RS
$end
#__end__
```

***
## Raio X

````java
class Espiral
+ nome: String
+ qtd: int
+ preco: float
--
+ toString(): String

class Maquina
- espirais: List<Espiral>
- saldoCliente: float
- lucro: float
--
+ inserirDinheiro(value: number): boolean
+ pedirTroco(): float
+ vender(indice: int): boolean
+ alterarEspiral(indice: int, nome: String, qtd : int, preco :float) : boolean
+ getSaldo(): float
+ toString() String
````


***
## Ajuda

- Faça primeiro a classe Espiral. Garanta que existe um construtor default seja sem parâmetros ou com todos os parametros com valores default.
- No contrutor da class Maquina receba a quantidade de espirais. Para iniciar o vetor de espirais você pode fazer um laço inserindo qtd Espirais no vetor.

- Exemplo Typescript

```typescript
class Espiral{
    constructor(
        public nome : string = "", 
        public qtd : number = 0, 
        public preco : number = 0.0
    ){}
}

class Machine{
    saldo : number;
    lucro : number;
    maxProdutos : number;
    espirais : Espiral[];

    constructor(nespirais : number, maxProdutos : number){
        this.saldo = 0.0;
        this.lucro = 0.0;
        this.maxProdutos = maxProdutos;
        this.espirais = [];

        for(let i = 0; i < nespirais; i++){
            this.espirais.push(new Espiral());
        }
    }
}
```

- Exemplo c++

```c++
//c++
class Espiral{
    //atributos
    Espiral(){
        //inicializacao
    }
}

class Maquina{
    std::vector<Espiral> espirais;
    //outros atributos
public:
    Maquina(int nespirais){
        for(int i = 0; i < nespirais; i++)
            espirais.push_back(Espiral());
    }
}
```

