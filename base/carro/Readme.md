## 11 Carro
### Hora de dar uma voltinha de carro. Quero buzinar meu kalhambek.
![](figura.jpg)

Essa atividade se propõe a implementar um carro que pode andar pela cidade. Ele deve poder embarcar e desembarcar pessoas, colocar gasolina e andar.


## Funcionalidades
Seu sistema deverá:

- Inicializar.
    - Iniciar de tanque vazio, sem ninguém dentro e com 0 de quilometragem.
    - Para simplificar, nosso carro esportivo suporta até 2 pessoas e seu tanque suporta até 10 litros.
- Entrando e Saindo.
    - Embarcar uma pessoa por vez.
    - Desembarcar uma pessoa por vez.
        - Não embarque além do limite ou desembarque se não houver ninguém no carro.
- Abastecer.
    - Abastecer o tanque passando a quantidade de litros de combustível.
        - Caso tente abastecer acima do limite, descarte o valor que passou.
- Andar.
    - Caso haja pelo menos uma pessoa no carro e combustível suficiente, ele deve gastar combustível e aumentar a quilometragem.
    - Nosso carro tem desempenho fixo de 10 km por litro.
    - Caso não exista combustível suficiente para completar a viagem inteira, o carro deve avisar e não iniciar a viagem.

---
## Shell

```bash
#__case inicializar
# O comando "$in" insere uma pessoa no carro.
# O comando "$out" retira uma pessoa do carro".
# O comando "$show" mostra o estado do carro.
# Deve ser emitido um erro caso não seja possível inserir ou retirar uma pessoa.
$show
pass: 0, gas: 0, km: 0
$in
$in
$show
pass: 2, gas: 0, km: 0
$in
fail: limite de pessoas atingido
$show
pass: 2, gas: 0, km: 0
$out
$out
$out
fail: nao ha ninguem no carro
$show
pass: 0, gas: 0, km: 0
$end
```

```bash
#__case abastecer
$fuel 25
$show
pass: 0, gas: 10, km: 0

#__case dirigir vazio
$drive 10
fail: nao ha ninguem no carro

#__case dirigir
$in
$drive 10
$show
pass: 1, gas: 9, km: 10
$drive 70
$show
pass: 1, gas: 2, km: 80

#__case para longe
$drive 50
fail: gasolina insuficiente
$end
#__end__
```

---
## Raio X

```java
class Car 
+ gas: float
+ gasMax: float
+ pass: int
+ passMax: int
+ km: float
--
+ in(): bool    //embarcar
+ out(): bool   //desembarcar
+ fuel(value: float): void //abastecer
+ drive(float: distance): boolean //dirigir
+ show(): string
```

---

## Resposta e testes
- Respostas
    - [C++](solver.cpp)
