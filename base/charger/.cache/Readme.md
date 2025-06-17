# Notebook com TESTES

<!-- toch -->
[INTRO](#intro) | [GUIDE](#guide) | [SHELL](#shell)
-- | -- | --
<!-- toch -->

![imagem de notebook](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/charger/cover.jpg)

## INTRO

- Vamos modelar um notebook que pode ter ou não tanto carregador quanto bateria.
- Terá que reescrever os métodos `usar <tempo>`, `ligar`.
- Só poderá `ligar` se tiver carga na bateria ou carregador.
- Enquanto em uso
  - se tiver apenas na bateria, a carga da bateria deve diminuir.
  - se estiver na bateria e no carregador, a carga deve aumentar.
- O carregador possui uma potência que implica na quantidade de carga carregada por unidade de tempo.
- A bateria possui uma carga e uma capacidade que representam a carga atual e o máximo possível de carga.
- Para simplificar, vamos utilizar minutos como a unidade de tempo e de carga.
- Uma bateria `15/50` significa que possui ainda 15 minutos de carga e suporta no máximo 50.
- Um carregador com 3 de potência consegue em um minuto de uso, adicionar 3 minutos de carga na bateria.

## GUIDE

[![youtube icon](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/charger/../youguide.png)](https://youtu.be/2oyQq-h0kqY?si=8DQZV6mLYKNtd2jZ)


- Crie sempre atributos privados e os utilize através de métodos públicos.
- Vá implementando orientado aos testes, implementando apenas o necessário para passar em cada teste.
- Seu código será pontuado pela quantidade de testes que passarem, não pela quantidade de código escrito.

## SHELL

```bash
#TEST_CASE iniciar
$show
Notebook: desligado

#TEST_CASE não pode ligar

$turn_on
fail: não foi possível ligar

#TEST_CASE tentando usar desligado
$use 5
fail: desligado
$end
```

___

```bash
#TEST_CASE adicionando carregador
$set_charger 2
$show
Notebook: desligado, Carregador 2W

#TEST_CASE ligando no carregador
$turn_on
$show
Notebook: ligado por 0 min, Carregador 2W

#TEST_CASE usando
$use 5
$show
Notebook: ligado por 5 min, Carregador 2W

$use 7
$show
Notebook: ligado por 12 min, Carregador 2W


#TEST_CASE desligando
$turn_off
$show
Notebook: desligado, Carregador 2W
$end
```

___

```bash
#TEST_CASE adicionando carregador
$set_charger 3
$set_charger 4
fail: carregador já conectado
$turn_on
$use 4
$show
Notebook: ligado por 4 min, Carregador 3W

#TEST_CASE removendo carregador
$rm_charger
Removido 3W

$rm_charger
fail: Sem carregador

$show
Notebook: desligado
$end
```

___

```bash
#TEST_CASE adicionando bateria
$set_battery 50
$show
Notebook: desligado, Bateria 50/50

#TEST_CASE ligando na bateria
$turn_on
$show
Notebook: ligado por 0 min, Bateria 50/50

#TEST_CASE usando
$use 5
$show
Notebook: ligado por 5 min, Bateria 45/50

$use 10
$show
Notebook: ligado por 15 min, Bateria 35/50

#TEST_CASE desligando
$turn_off
$show
Notebook: desligado, Bateria 35/50
$end
```

___

```bash

#TEST_CASE retirando bateria
$set_battery 50
$turn_on
$use 5
$show
Notebook: ligado por 5 min, Bateria 45/50

$rm_battery
Removido 45/50

$rm_battery
fail: Sem bateria

$show
Notebook: desligado
$end
```

___

```bash
#TEST_CASE usando bateria até descarregar
$set_battery 50
$turn_on
$use 45
$show
Notebook: ligado por 45 min, Bateria 5/50

$use 10
fail: descarregou
$show
Notebook: desligado, Bateria 0/50

$end
```

___

```bash
#TEST_CASE usando bateria até descarregar
$set_battery 50
$turn_on
$use 40
$show
Notebook: ligado por 40 min, Bateria 10/50

$use 10
fail: descarregou
$show
Notebook: desligado, Bateria 0/50

$end
```

___

```bash
#TEST_CASE bateria e carregador
$set_battery 50
$show
Notebook: desligado, Bateria 50/50
$turn_on
$use 45
$show
Notebook: ligado por 45 min, Bateria 5/50

$set_charger 1
$show
Notebook: ligado por 45 min, Carregador 1W, Bateria 5/50

$use 20
$show
Notebook: ligado por 65 min, Carregador 1W, Bateria 25/50

$use 30
$show
Notebook: ligado por 95 min, Carregador 1W, Bateria 50/50

$end
```

___

```bash
#TEST_CASE bateria e carregador
$set_battery 50
$turn_on
$use 40
$show
Notebook: ligado por 40 min, Bateria 10/50

$set_charger 5
$show
Notebook: ligado por 40 min, Carregador 5W, Bateria 10/50

#TEST_CASE turbo carregador

$use 6
$show
Notebook: ligado por 46 min, Carregador 5W, Bateria 40/50

#TEST_CASE remover bateria com carregador

$rm_battery
Removido 40/50
$show
Notebook: ligado por 46 min, Carregador 5W

$end
```

<!-- links .cache/draft -->
- cpp
  - [shell.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/charger/.cache/draft/cpp/shell.cpp)
- java
  - [Shell.java](https://github.com/qxcodepoo/arcade/blob/master/base/charger/.cache/draft/java/Shell.java)
- ts
  - [shell.ts](https://github.com/qxcodepoo/arcade/blob/master/base/charger/.cache/draft/ts/shell.ts)
<!-- links -->
