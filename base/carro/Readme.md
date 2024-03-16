# Se não pode comprar um, construa seu primeiro @carro

- Veja a versão online: [aqui.](https://github.com/qxcodepoo/arcade/blob/master/base/carro/Readme.md)
- Para programar na sua máquina (local/virtual) use:
  - `tko down poo carro`
- Se não tem o `tko`, instale pelo [LINK](https://github.com/senapk/tko#tko).

---

<!-- toch -->
[Intro](#intro) | [Treino](#treino) | [Draft](#draft) | [Guide](#guide) | [Shell](#shell)
-- | -- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/carro/cover.jpg)

Nessa atividade vamos implementar um carro ecológico. Ele deve poder embarcar e desembarcar pessoas, colocar combustível e andar.

***

## Intro

Seu sistema deverá:

- Inicializar.
  - Iniciar de tanque vazio, sem ninguém dentro e com 0 de quilometragem.
  - Para simplificar, nosso carro esportivo suporta até 2 pessoas e seu tanque suporta até 100 litros de combustível.
- Entrando e Saindo.
  - Embarcar uma pessoa por vez.
  - Desembarcar uma pessoa por vez.
    - Não embarque além do limite ou desembarque se não houver ninguém no carro.
- Abastecer.
  - Abastecer o tanque passando a quantidade de litros de combustível.
  - Caso tente abastecer acima do limite, descarte o valor que passou.
- Dirigir.
  - Caso haja pelo menos uma pessoa no carro e **algum combustível**, ele deve gastar combustível andando e aumentar a quilometragem.
  - Nosso carro faz um quilômetro por litro de combustível.
  - Caso não exista combustível suficiente para completar a viagem inteira, dirija o que for possível e emita uma mensagem indicando quanto foi percorrido.

***

## Treino

- Parte 1: entrar;
  - Crie a classe `Car` com os atributos `pass`, `passMax`;
  - Crie o método construtor que inicializa os atributos com 0 e 2;
  - Crie o método `enter` que incrementa `pass`;
  - Crie um if para impedir que `pass` ultrapasse `passMax`;
  - Crie o método `toString` mostrar o estado do carro.
  - Teste seu código.
- Parte 2: sair.
  - Crie o método `leave` que decrementa `pass`;
  - Crie um if para impedir que `pass` seja menor que 0;
  - Teste seu código.
- Parte 3: abastecer.
  - Crie os atributos `gas` e `gasMax`;
  - Crie o método `fuel` que incrementa `gas` com o valor passado;
  - Crie um if para impedir que `gas` ultrapasse `gasMax`;
  - Teste seu código.
- Parte 4: dirigir.
  - Crie o atributo `km`;
  - Crie o método `drive` que incrementa `km` e decrementa `gas` com o valor passado;
  - Crie testes para impedir que o carro dirija em passageiros ou sem combustível;
  - Teste seu código.
- Parte 5: dirigir longe.
  - Crie testes para impedir que o carro dirija mais do que o combustível permite;
  - Teste seu código.

## Draft

- [Solver.java](https://github.com/qxcodepoo/arcade/blob/master/base/carro/.cache/draft.java)
- [solver.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/carro/.cache/draft.cpp)
- [solver.ts](https://github.com/qxcodepoo/arcade/blob/master/base/carro/.cache/draft.ts)

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/carro/diagrama.png)

<!-- load diagrama.puml fenced=ts:filter -->

```ts
class Car {
  ' quantidade de passageiros no carro
  + pass    : int

  ' máximo de passageiros que o carro suporta
  + passMax : int

  ' gasolina atual do carro
  + gas     : int

  ' máximo de gasolina que o carro suporta
  + gasMax  : int

  ' quilometragem atual do carro
  + km      : int

  __
  
  ' inicializar todos os atributos
  ' inicializar com tanque vazio
  ' 0 passageiros
  ' 0 de quilometragem
  ' máximo de 2 pessoas
  ' máximo de 100 litros de gasolina
  + Car()

  ' embarca uma pessoa no carro
  ' verifique se o carro não estiver lotado
  + enter()
  
  ' desembarca uma pessoa por vez
  ' verifique se tem alguém no carro
  + leave()
  
  ' percorre value quilometros com o carro
  ' gasta um litro de gas para cada km de distancia
  ' verifique se tem alguém no carro
  ' verifique se tem gasolina suficiente

  + drive(value : int): void
  
  ' incrementa gasolina no tanque de value
  ' caso tente abastecer acima do limite de gasMax
  '   o valor em excesso deve ser descartado
  
  + fuel(value : int)

  + toString() : string
}

class Legenda {
  + atributoPublic
  - atributoPrivate
  # atributoProtected
  __
  + métodoPublic()
  - métodoPrivate()
  # métodoProtected()
}

```

<!-- load -->

***

## Shell

```bash
#__case inicializar
# O comando "$enter" insere uma pessoa no carro.
# O comando "$leave" retira uma pessoa do carro".
# O comando "$show" mostra o estado do carro.
# Deve ser emitido um erro caso não seja possível inserir ou retirar uma pessoa.
$show
pass: 0, gas: 0, km: 0

#__case entrar
$enter
$enter
$show
pass: 2, gas: 0, km: 0

#__case limite
$enter
fail: limite de pessoas atingido
$show
pass: 2, gas: 0, km: 0

#__case sair
$leave
$show
pass: 1, gas: 0, km: 0

#__case limite saida
$leave
$leave
fail: nao ha ninguem no carro
$show
pass: 0, gas: 0, km: 0
$end
```

***

```bash
#__case abastecer
$fuel 60
$show
pass: 0, gas: 60, km: 0

#__case dirigir vazio
$drive 10
fail: nao ha ninguem no carro

#__case dirigir
$enter
$drive 10
$show
pass: 1, gas: 50, km: 10

#__case para longe
$drive 70
fail: tanque vazio apos andar 50 km
$drive 10
fail: tanque vazio
$show
pass: 1, gas: 0, km: 60

#__case enchendo o tanque
$fuel 200
$show
pass: 1, gas: 100, km: 60
$end
#__end__
```
