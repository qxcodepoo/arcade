# Uma calculadora com bateria

<!-- toc-table -->
<!-- toc-table -->

![cover](assets/cover.webp)

## Intro

O objetivo dessa atividade é implementar uma calculadora que utiliza bateria. Se há bateria, ela executa operações de soma e divisão. É possível também mostrar a quantidade de bateria e recarregar a calculadora. Ela avisa quando está sem bateria e se há tentativa de divisão por 0.

O foco é separar a regra da calculadora das mensagens do `Shell`: a calculadora altera `display` e `battery`, enquanto o `Shell` mostra as falhas.

## Regras

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
    - `display = {display:.2f}, battery = {battery}`
    - Exemplo: `display = 0.00, battery = 0`
- Recarregar
  - Requisição: `$charge increment`
  - Adiciona carga à bateria, mas não pode ultrapassar o limite.
- Somar
  - Requisição: `$sum a b`
  - Soma dois valores e guarda no display.
  - Se não houver bateria, emita a mensagem `fail: bateria insuficiente`.
- Divisão
  - Requisição: `$div num den`
  - Divide dois valores e guarda no display.
  - Se não houver bateria, emita a mensagem `fail: bateria insuficiente`.
  - Se houver divisão por zero, consome um ponto de bateria, mantém o display anterior e emite a mensagem `fail: divisao por zero`.
- Separe as responsabilidades:
  - A classe Calculadora não deve conter nenhuma operação de impressão.
  - A classe Shell não deve ter lógica de negócios.

## Diagrama

`Calculator` permanece como uma classe coesa nesta etapa: bateria, display e operações fazem parte da simulação de uma calculadora. Extrair `Battery` será uma evolução possível em outro bloco, quando o ciclo de vida do componente for um objetivo explícito.

![diagrama](assets/diagrama.png)

## Guide

[Vídeo de apoio](https://youtu.be/oZYwuP3CKJM?si=uVdiZn8tXbwUGH41)

- Comece pelo construtor, garantindo que `display` e `battery` iniciem em `0`.
- Implemente `chargeBattery` limitando a bateria a `batteryMax`.
- Implemente `sum` e `division` retornando um resultado de sucesso ou falha.
- No `Shell`, traduza cada falha para a mensagem literal definida nas regras.

Pergunta de reflexão: por que a divisão por zero mantém o `display`, mas ainda consome bateria?

- Como formatar com duas casas decimais em diferentes linguagens.

```java
// java
public String toString() {
    // Dependendo da configuração do sistema, o java usa vírgula nos decimais. 
    // Para contornar isso e gerar sempre com ponto, usamos a classe Decimal Format
    DecimalFormat df = new DecimalFormat("0.00");
    return String.format("display = %s, battery = %d", df.format(this.display).replace(',','.'), this.battery);
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

<!-- links .cache/starter -->
<!-- links -->

## Cheat

<!-- links .cache/cheat -->
<!-- links -->
