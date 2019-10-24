## 40 Trem 2
### Trem com passageiros e carga.
![](figura.jpg)

Vamos ampliar a atividade do trem colocando vagões de carga para carregar bagagens.

## Funcionalidades

### Parte 1 - Trem e Vagões

- Um vagão de pessoas possui uma quantidade de cadeiras.
- Um vagão de carga tem um limite de peso.
- O trem possui um máximo de vagões que ele pode carregar.
- Ao mostrar um vagão de pessoas, coloque [], e para cada cadeira livre coloque um "-".
- Ao mostrar um vagão de carga, use um (), coloque os identificadores de carga e mostre quando de peso livre ainda existe. 

- Uma carga possui um peso e um identificador.
- Um passageiro possui um identificador.

```
  # init _maxVagoes  #inicia o trem
  # nwvp _capacidade #novo vagao de pessoa
  # nwvc _pesoMax    #novo vagao de carga
init 3
  done
nwvp 2
  done
la
  Trem [ - - ]
nwvc 350.0
  done
la
  Trem [ - - ]( _350.0 )
nwvp 2
  done
la
  Trem [ - - ]( _350.0 )[ - - ]
nwvc 1
  fail: limite de vagões atingido
```

### Parte 2 - Embarque e Desembarque

- Embarcar um novo item.
    - Ao tentar embarcar, o trem vai procurar o primeiro vagão livre para inserir o item.
    - Se não houver espaço livre em nenhum vagão então não haverá embarque.
    - Não deve ser possível embarcar duas vezes o mesmo passageiro ou a mesma carga no trem.
- Desembarcar um passageiro ou carga
    - Se o item estiver no trem, ele sai do trem liberando sua vaga.

```
# addp _idPass #tenta embarcar uma pessoa
# addc _idCarga _peso #tenta embarcar uma carga

addp goku
la
  Trem [ goku - ]( _350.0 )[ - - ]
addp kate
addp sara
addp goku
  fail: goku já está no trem
la
  Trem [ goku kate ]( _350.0 )[ sara - ]
addp tina
addp james
  fail: trem lotado
la
  Trem [ goku kate ]( _350.0 )[ sara james ]
addc xilitos 200.0
la
  Trem [ goku kate ]( xilitos:200.0 _150.0 )[ sara james ]
addc pipoca 100.0
la
  Trem [ goku kate ]( xilitos:200.0 pipoca:100.0 _50.0 )[ sara james ]
addc cebolitos 100.0
  fail: trem lotado
sair kate
sair sara
sair rufus
  fail: rufus nao esta no trem
sair xilitos
la
  Trem [ goku - ]( pipoca:100.0 _50.0 )[ james ]
```

### Parte 3 - Cadastro de Passeiros e Registro de Embarque

- Mostrar a lista de itens cadastrados.
    - Quando um item tenta embarcar, ele é cadastrado no sistema, independente de conseguir ou não embarcar, independente se é passageiro ou carga.
    - Mostre a lista ordenada pelo id do passageiro.
- Mostrar a sequência de embarque e desembarque.

```
cadastro
  alex
  cebolitos:100.0
  goku
  james
  kate
  pipoca:100.0
  sara
  tina
  xilitos:200.0

movimentacao
  goku in
  kate in
  sara in
  tina in
  james in
  xilitos:200.0 in
  pipoca:100.0 in
  kate out
  sara out
  xilitos:200.0 out
```

---
## Raio X

```java

interface Pass:
  getId(): string


class Pessoa implements Pass
- id: string

class Carga implements Pass
- id: string
- peso: float

interface class Vagao
- elementos: Passageiro[]
--
+ embarcar(pass: Pass)
+ desembarcar(idPass: String)
+ exists(idPass): boolean

class Trem
- maxVagoes: number
- vagoes: Vagao[]
--
+ addVagao(vagao: Vagao)
+ embarcar(pass: Passageiro)
+ desembarcar(idPass: string)
+ exists(idPass): bool
--
+ constructor(maxVagoes: number)

enum Direcao
IN
OUT

class Movimento
- pass: Passageiro
- dir: Direcao

class Registro
- repPassageiros: Passageiro[]
- movimentacao: Movimento[]
--
+ cadastrar(pass: Passageiro)
+ movimentar(mov: Movimento)
--
+ constructor(maxVagoes: number)
```
