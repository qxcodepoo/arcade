# Uma calculadora com bateria

<!-- toch -->
[Intro](#intro) | [Guide](#guide) | [Shell](#shell) | [Draft](#draft) | [Cheat](#cheat)
-- | -- | -- | -- | --
<!-- toch -->

![cover](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/calculadora/cover.jpg)

## Intro

O objetivo dessa atividade é implementar uma calculadora que utiliza bateria. Se há bateria, ela executa operações de soma e divisão. É possível também mostrar a quantidade de bateria e recarregar a calculadora. Ela avisa quando está sem bateria e se há tentativa de divisão por 0.

- Descrição
  - A calculadora possui um display `display` e uma bateria `battery`. Ela guarda o valor atual da bateria e o valor máximo `batteryMax`.
  - O display é onde o resultado das operações é armazenado.
  - A bateria é a quantidade de energia que a calculadora possui.
  - Cada operação gasta um ponto de bateria.
  - A calculadora não pode realizar operações se não houver bateria.
  - A calculadora não pode realizar divisões por zero.
- Construtor
  - Requisição `$init batteryMax`
  - Receba o máximo de bateria como parâmetro no construtor da Calculadora.
- `toString`
  - Deve ser invocado na requisição `$show`.
  - Retorna a representação da calculadora no formato:
    - `display = {display:.2f}, battery = {battery}"`
    - Exemplo: `display = 0.00, battery = 0`
- Recarregar
  - Requisição: `$charge increment`
  - Adiciona carga à bateria, mas não pode ultrapassar o limite.
- Somar
  - Requisição: `$sum a b`
  - Soma dois valores e guarda no display.
  - Se não houver bateria, emita a mensagem `fail: bateria insuficiente`.
- Divisão
  - Requisição: `$div den num`
  - Divide dois valores e guarda no display.
  - Se não houver bateria, emita a mensagem `fail: bateria insuficiente`.
  - Se houver divisão por zero, emita a mensagem `fail: divisao por zero`.

## Guide

![diagrama](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/calculadora/diagrama.png)

[![youtube icon](https://raw.githubusercontent.com/qxcodepoo/arcade/master/base/calculadora/../youguide.png)](https://youtu.be/oZYwuP3CKJM?si=uVdiZn8tXbwUGH41)

- Como formatar com duas casas decimais em diferentes linguagens.

```java
// java
public String toString() {
    // Dependendo da configuração do sistema, o java usa vírgula nos decimais. 
    // Para contornar isso e gerar sempre com ponto, usamos a classe Decimal Format
    DecimalFormat df = new DecimalFormat("0.00");
    return String.format("display = %s, battery = %d", df.format(this.display).replace(',','.'), this.battery);
}

//ts
toString(): string {
    // o typescript usa o modelo crase ${} para string de substituição
    return `display = ${this.display.toFixed(2)}, battery = ${this.battery}`;
}

//cpp
std::string str() const {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << "display = " << this->display << ", battery = " << this->battery;
    return ss.str();
}

```

## Shell

### Primeira simulação

```bash
#TEST_CASE iniciar mostrar e recarregar

$init 5
$show
display = 0.00, battery = 0

```

```bash
#TEST_CASE charge

$charge 3
$show
display = 0.00, battery = 3
$charge 1
$show
display = 0.00, battery = 4
```

```bash
#TEST_CASE boundary

$charge 2
$show
display = 0.00, battery = 5
```

```bash
#TEST_CASE reset

$init 4
$charge 2
$show
display = 0.00, battery = 2
$charge 3
$show
display = 0.00, battery = 4

```

```bash
$end
```

### Segunda simulação

```bash
#TEST_CASE somando

$init 2
$charge 2
$sum 4 3
$show
display = 7.00, battery = 1
```

```bash
#TEST_CASE gastando bateria

$sum 2 3
$show
display = 5.00, battery = 0
```

```bash
#TEST_CASE sem bateria

$sum -4 -1
fail: bateria insuficiente
```

```bash
#TEST_CASE recarregando

$charge 1
$show
display = 5.00, battery = 1
$sum -4 -2
$show
display = -6.00, battery = 0
```

```bash
$end
```

### Terceira simulação

```bash
#TEST_CASE dividindo

$init 3
$charge 3
$div 6 3
$show
display = 2.00, battery = 2
```

```bash
#TEST_CASE dividindo por zero gastando bateria

$div 7 0
fail: divisao por zero
$show
display = 2.00, battery = 1
```

```bash
#TEST_CASE gastando bateria

$div 7 2
$div 10 2
fail: bateria insuficiente
$show
display = 3.50, battery = 0
```

```bash
$end
```

## Draft

<!-- links .cache/draft -->
- cpp
  - [shell.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/calculadora/.cache/draft/cpp/shell.cpp)
- java
  - [Shell.java](https://github.com/qxcodepoo/arcade/blob/master/base/calculadora/.cache/draft/java/Shell.java)
- ts
  - [shell.ts](https://github.com/qxcodepoo/arcade/blob/master/base/calculadora/.cache/draft/ts/shell.ts)
<!-- links -->

## Cheat

<!-- links .cache/cheat -->
- cpp
  - [shell.cpp](https://github.com/qxcodepoo/arcade/blob/master/base/calculadora/.cache/cheat/cpp/shell.cpp)
- java
  - [Shell.java](https://github.com/qxcodepoo/arcade/blob/master/base/calculadora/.cache/cheat/java/Shell.java)
- ts
  - [shell.ts](https://github.com/qxcodepoo/arcade/blob/master/base/calculadora/.cache/cheat/ts/shell.ts)
<!-- links -->
