# Toalha com testes

- Crie uma classe `Toalha` com os atributos `cor`, `tamanho` e `umidade`.
- Crie um construtor que inicialize todos os atributos `cor` e `tamanho` com valores recebidos como parâmetro e `umidade` com 0.
- Crie um método `enxugar` que recebe um valor inteiro `umidade` e aumenta o atributo `umidade` da toalha.
- Crie um método `torcer` que zera o atributo `umidade` da toalha.
- Crie um método `pegarMaximoUmidade` que retorna o valor máximo de umidade que essa toalha pode ter.
- O máximo de umidade que uma toalha pode ter é de acordo com o tamanho dela:
  - `P` -> 10
  - `M` -> 20
  - `G` -> 30
- Crie um método `estaSeca` que retorna `true` se a umidade da toalha for 0 e `false` caso contrário.
- Faça um código de teste para validar o comportamento da classe `Toalha`.

## Testes

```bash
#TEST_CASE criação
$criar azul P
$mostrar
Cor: azul, Tamanho: P, Umidade: 0

$seca
sim

$enxugar 5
$mostrar
Cor: azul, Tamanho: P, Umidade: 5

$seca
nao

$enxugar 5
toalha encharcada
$mostrar
Cor: azul, Tamanho: P, Umidade: 10

$enxugar 5
toalha encharcada

$mostrar
Cor: azul, Tamanho: P, Umidade: 10

$torcer
$mostrar
Cor: azul, Tamanho: P, Umidade: 0

$end

```

---

```bash

#TEST_CASE criação
$criar verde G

$mostrar
Cor: verde, Tamanho: G, Umidade: 0

$enxugar 30
toalha encharcada
$mostrar
Cor: verde, Tamanho: G, Umidade: 30

$enxugar 1
toalha encharcada
$mostrar
Cor: verde, Tamanho: G, Umidade: 30
$end
```
